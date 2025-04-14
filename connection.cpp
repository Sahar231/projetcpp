#include "connection.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

connection::connection()
{
    // Constructor body is empty
}

bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("labsync");
    db.setUserName("labsync");
    db.setPassword("labsync");
    if (db.open())
    {
        qDebug() << "Connection to the database successful";
        return true;
    }
    else
    {
        QSqlError lastError = db.lastError();
        qDebug() << "Failed to connect to the database. Error: " << lastError.text();
        return false;
    }
}


void connection::closeconnection()
{
    db.close();
}
