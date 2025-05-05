#include "ard.h"
#include <QDebug>
#include <QSerialPortInfo>
#include <QSqlError>
#include "recher.h"


Ard::Ard()
{
    data = "";
    arduino_port_name = "COM5";
    arduino_is_available = false;
    serial = new QSerialPort;
}

Ard::~Ard()
{
    delete serial;
}

QString Ard::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Ard::getserial()
{
    return serial;
}

int Ard::connect_arduino()
{
    // Search for Arduino on available ports
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            // Check for common Arduino vendor and product IDs
            if ((serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                 serial_port_info.productIdentifier() == arduino_uno_product_id) ||
                serial_port_info.description().contains("Arduino", Qt::CaseInsensitive) ||
                serial_port_info.manufacturer().contains("Arduino", Qt::CaseInsensitive)) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                break;
            }
        }
    }

    qDebug() << "Detected Arduino port name:" << arduino_port_name;

    if (!arduino_is_available) {
        // Fallback to COM5 if no Arduino is detected
        arduino_port_name = "COM5";
        qDebug() << "No Arduino detected, attempting to use COM5";
    }

    // Configure serial port
    serial->setPortName(arduino_port_name);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Attempt to open the port
    if (serial->open(QSerialPort::ReadWrite)) {
        qDebug() << "Successfully opened port:" << arduino_port_name;
        return 0; // Success
    } else {
        qDebug() << "Failed to open port:" << serial->errorString();
        return 1; // Failed to open port
    }
}

int Ard::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "Serial port closed";
        return 0;
    }
    return 1;
}

int Ard::read_integer_from_arduino() {
    if (serial->canReadLine()) {
        QByteArray data = serial->readLine();
        bool ok;
        int value = data.trimmed().toInt(&ok);
        if (ok) {
            qDebug() << "Integer received from Arduino:" << value;
            return value;
        } else {
            qDebug() << "Failed to convert received data to integer.";
        }
    } else {
        qDebug() << "Erreur de lecture depuis Arduino.";
    }
    return -1; // ou une valeur par défaut
}



void Ard::write_to_arduino(const QByteArray &data)
{
    if (serial->isWritable()) {
        serial->write(data);
        serial->flush();
    } else {
        qDebug() << "Port série non prêt pour écriture.";
    }
}


QString Ard::verifyPatientID(const QString &patientID, QSqlDatabase &db)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM PATIENTS WHERE ID_PATIENT = :id");
    query.bindValue(":id", patientID);
    if (query.exec() && query.next()) {
        return "Patient ID verified";
    }
    return "Patient ID not found";
}
void Ard::check_and_update_research_state()
{
    int value = read_integer_from_arduino(); // utiliser l'objet courant
    qDebug() << "Value received from Arduino:" << value;

    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }

    if (value == 0 || value == 1) {
        QSqlQuery query;
        query.prepare("UPDATE RECHERCHES SET ETAT = :etat WHERE ID_RECH = 1");
        query.bindValue(":etat", value);

        if (query.exec()) {
            int rows = query.numRowsAffected();
            qDebug() << "RECHERCHES updated:" << rows << "row(s) affected. ETAT set to" << value << "for ID_RECH = 1.";
        } else {
            qDebug() << "Failed to update RECHERCHES table:" << query.lastError().text();
        }
    } else {
        qDebug() << "Invalid value received from Arduino (" << value << "). Expected 0 or 1.";
    }

}




