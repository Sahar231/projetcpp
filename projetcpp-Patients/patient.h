#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Patient
{
public:
    Patient();
    bool addPatient(QString id_patient, QString nom, QString prenom, QString adresse, QString email, QString numT, QDate dateN, QString genre, QString description);
    bool deletePatient(QString id_patient);
    bool updatePatient(QString id_patient, QString nom, QString prenom, QString adresse, QString email, QString numT, QDate dateN, QString genre, QString description);





};

#endif // PATIENT_H
