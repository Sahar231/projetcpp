#include "connection.h"
#include<QDebug>
connection::connection()
{}
bool connection::createconnect()
{bool test=false;;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Source_Projet2A17v");//inserer le nom de la source de données
    db.setUserName("labsync");//inserer nom de l'utilisateur
    db.setPassword("labsync");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;



    return  test;
}

