#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "serialcommunication.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

SerialCommunication::SerialCommunication(QObject *parent)
    : QObject(parent)
{
    serialPort = new QSerialPort(this);

    // 🔍 Recherche automatique du port Arduino
    bool portFound = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "🔌 Port trouvé:" << info.portName()
            << "Description:" << info.description()
            << "Fabricant:" << info.manufacturer();

        // Si description ou fabricant contient "Arduino" ou "USB"
        if (info.description().contains("Arduino", Qt::CaseInsensitive) ||
            info.manufacturer().contains("Arduino", Qt::CaseInsensitive) ||
            info.description().contains("USB", Qt::CaseInsensitive)) {

            serialPort->setPort(info);
            portFound = true;
            break;
        }
    }

    if (!portFound) {
        qDebug() << "❌ Aucun port Arduino détecté. Vérifie la connexion USB.";
        return;
    }

    // Configuration du port série
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "❌ Erreur : Impossible d'ouvrir le port série.";
        qDebug() << "👉 Message d'erreur :" << serialPort->errorString();
    } else {
        qDebug() << "✅ Port série ouvert avec succès :" << serialPort->portName();
    }
}

SerialCommunication::~SerialCommunication() {
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}

void SerialCommunication::start() {
    connect(serialPort, &QSerialPort::readyRead, this, &SerialCommunication::readSerial);
}

void SerialCommunication::readSerial() {
    if (serialPort->canReadLine()) {
        QByteArray data = serialPort->readLine().trimmed();
        QString uid = QString::fromUtf8(data);
        qDebug() << "📥 UID reçu :" << uid;

        if (expectingUid) {
            // Only process the UID if we are expecting it
            if (uid.startsWith("UID reçu : ")) {
                uid = uid.mid(11);  // Clean up the "UID reçu : " prefix
                qDebug() << "Cleaned UID: " << uid;

                // Query the database to check if the UID exists
                QSqlQuery query;
                query.prepare("SELECT ID_EMPLOYE, NOM FROM EMPLOYE WHERE RFID_UID = :uid");
                query.bindValue(":uid", uid);
                if (query.exec() && query.next()) {
                    // UID found in the database
                    QString idEmploye = query.value("ID_EMPLOYE").toString();
                    QString nomEmploye = query.value("NOM").toString();

                    qDebug() << "UID authorized: " << uid;

                    // Send employee ID and name to Arduino for display on the LCD
                    sendMessage("Nom: " + nomEmploye);
                    sendMessage("ID: " + idEmploye);

                    // Call MainWindow method to handle UID and show the alert box
                    emit uidAuthorized(uid);  // You will need to create a signal to connect to MainWindow
                    expectingUid = false;  // Stop expecting further UIDs until the next cycle
                } else {
                    // UID not found in the database
                    qDebug() << "Invalid UID received: " << uid;
                    sendMessage("Refuse");
                    expectingUid = true; // Reset to expect a new UID
                }
            }
        } else {
            // If we are not expecting a UID, it must be a response
            if (uid.startsWith("Réponse reçue : ")) {
                qDebug() << "Réponse reçue (ignoring): " << uid;
                expectingUid = true; // Once we receive the response, expect a new UID
            }
        }
    }
}

void SerialCommunication::sendMessage(const QString &message) {
    if (serialPort && serialPort->isOpen()) {
        QString msg = message + "\n";
        serialPort->write(msg.toUtf8());
        serialPort->flush();
        qDebug() << "📤 Message envoyé à l'Arduino :" << msg;
    } else {
        qDebug() << "⚠️ Port série non ouvert, impossible d'envoyer le message.";
    }
}
