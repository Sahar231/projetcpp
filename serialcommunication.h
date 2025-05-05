// serialcommunication.h

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QObject>
#include <QSerialPort>

class SerialCommunication : public QObject
{
    Q_OBJECT

public:
    explicit SerialCommunication(QObject *parent = nullptr);
    ~SerialCommunication();

    void start();                     // Lance l'écoute du port
    void stop();                      // Ferme proprement le port
    void sendMessage(const QString &message);  // Envoie un message à l'Arduino

signals:
    void uidReceived(const QString &uid);// Signal émis quand un UID est reçu
    void uidAuthorized(const QString &uid);

private slots:
    void readSerial();               // Fonction pour lire les données entrantes

private:
    QSerialPort *serialPort;
    bool expectingUid = true;
};

#endif // SERIALCOMMUNICATION_H
