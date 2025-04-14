#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class connection {
public:
    connection();  // Constructeur de la classe
    bool createconnection();  // Méthode pour établir la connexion à la base de données
};

#endif // CONNECTION_H
