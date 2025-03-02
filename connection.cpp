#include "connection.h"
#include<QDebug>
connection::connection()
{


}
bool connection::createconnect()
{bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetCPP");
    db.setUserName("Slim");
    db.setPassword("Slim");

    if (db.open())
        test=true;


return  test;
}












