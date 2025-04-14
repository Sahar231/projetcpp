#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

connection::connection() {
    // Constructeur
}

bool connection::createconnection() {
    // Créer la connexion à la base de données Oracle
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");  // "QOCI" est le pilote pour Oracle


    db.setDatabaseName("labsync");  // Nom de la source de données
    db.setUserName("C##LABSYNC_NEW");  // Nom d'utilisateur
    db.setPassword("labsync");  // Mot de passe

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError().text();
        return false;
    }

    return true;
}
