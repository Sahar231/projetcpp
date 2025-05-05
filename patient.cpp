#include "patient.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QDate>

// Constructor definition for Patient class
Patient::Patient() {
    // Constructor code (if any initialization is needed)
}

// Function to add a patient
bool Patient::addPatient(QString id_patient, QString nom, QString prenom, QString adresse, QString email, QString numT, QDate dateN, QString genre, QString description)
{
    // Validate inputs
    if (id_patient.isEmpty() || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || email.isEmpty() ||
        numT.isEmpty() || genre.isEmpty() || description.isEmpty())
    {
        QMessageBox::warning(nullptr, "Erreur", "Tous les champs doivent être remplis !");
        return false;
    }

    // Validate numT (must be exactly 8 digits)
    QRegularExpression regex("[0-9]{8}");
    QRegularExpressionMatch match = regex.match(numT); // Use match() instead of exactMatch()
    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return false;
    }

    // Validate email (must contain @)
    if (!email.contains("@")) {
        QMessageBox::warning(nullptr, "Erreur", "L'email doit contenir '@' !");
        return false;
    }

    // Check if id_patient is unique
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Patients WHERE id_patient = :id_patient");
    checkQuery.bindValue(":id_patient", id_patient);

    if (!checkQuery.exec()) {
        QMessageBox::critical(nullptr, "Erreur Base de Données", "Échec de la vérification de l'identifiant !");
        return false;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du patient existe déjà !");
        return false;
    }

    // Insert patient into database
    QSqlQuery query;
    query.prepare("INSERT INTO Patients (id_patient, nom, prenom, adresse, email, numT, dateN, genre, description) "
                  "VALUES (:id_patient, :nom, :prenom, :adresse, :email, :numT, :dateN, :genre, :description)");

    query.bindValue(":id_patient", id_patient);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":numT", numT);
    query.bindValue(":dateN", dateN);
    query.bindValue(":genre", genre);
    query.bindValue(":description", description);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur Base de Données", "L'ajout du patient a échoué !");
        return false;
    }

    QMessageBox::information(nullptr, "Succès", "Patient ajouté avec succès !");
    return true;
}
bool Patient::deletePatient(QString id_patient)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Patients WHERE id_patient = :id_patient");
    query.bindValue(":id_patient", id_patient);

    return query.exec();  // Returns true if deletion is successful, false otherwise
}
bool Patient::updatePatient(QString id_patient, QString nom, QString prenom, QString adresse, QString email, QString numT, QDate dateN, QString genre, QString description)
{
    // Validate inputs
    if (id_patient.isEmpty() || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || email.isEmpty() ||
        numT.isEmpty() || genre.isEmpty() || description.isEmpty())
    {
        QMessageBox::warning(nullptr, "Erreur", "Tous les champs doivent être remplis !");
        return false;
    }

    // Validate numT (must be exactly 8 digits)
    QRegularExpression regex("[0-9]{8}");
    if (!regex.match(numT).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return false;
    }

    // Validate email
    if (!email.contains("@")) {
        QMessageBox::warning(nullptr, "Erreur", "L'email doit contenir '@' !");
        return false;
    }

    // Update query
    QSqlQuery query;
    query.prepare("UPDATE Patients SET nom=:nom, prenom=:prenom, adresse=:adresse, email=:email, numT=:numT, dateN=:dateN, genre=:genre, description=:description "
                  "WHERE id_patient=:id_patient");

    query.bindValue(":id_patient", id_patient);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":numT", numT);
    query.bindValue(":dateN", dateN);
    query.bindValue(":genre", genre);
    query.bindValue(":description", description);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur Base de Données", "La modification du patient a échoué !");
        return false;
    }

    QMessageBox::information(nullptr, "Succès", "Patient mis à jour avec succès !");
    return true;
}

