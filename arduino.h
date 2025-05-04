#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QString>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlDatabase>

class Arduino {
public:
    Arduino();
    ~Arduino();
    int connect_arduino();
    int close_arduino();
    QString getarduino_port_name();
    QSerialPort* getserial();
    QByteArray read_from_arduino();
    int read_integer_from_arduino();
    void write_to_arduino(const QByteArray &data);

    QString verifyPatientID(const QString &patientID, QSqlDatabase &db);
    void check_and_update_research_state();

private:
    QSerialPort* serial;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
    static const quint16 arduino_uno_vendor_id = 0x2341;  // Arduino Uno
    static const quint16 arduino_uno_product_id = 0x0043; // Arduino Uno
};

#endif // ARDUINO_H
