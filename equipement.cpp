#include "equipement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include<QDebug>
/*equipement::equipement() {
    id_equipement=0;
    nom_eq="";
    image="";
    type_eq="";
    description="";
    etat="";

    quantite=0;
}*/
equipement::equipement(int ID_EQUIPEMENT,QString NOM_EQ,QString IMAGE,QString TYPE_eq,QString DESCRIPTION,int QUANTITE,QString ETAT)
{
    this->ID_EQUIPEMENT=ID_EQUIPEMENT;
    this->NOM_EQ=NOM_EQ;
    this->IMAGE=IMAGE;
    this->TYPE_eq=TYPE_eq;
    this->DESCRIPTION=DESCRIPTION;
    this->ETAT=ETAT;

    this->QUANTITE=QUANTITE;

}


bool equipement::ajouterEQ()
{
    QSqlQuery query;
    QString res = QString::number(ID_EQUIPEMENT);

    query.prepare("INSERT INTO EQUIPEMENT (ID_EQUIPEMENT, NOM_EQ, IMAGE, TYPE_EQ, DESCRIPTION, QUANTITE, ETAT) "
                  "VALUES (:ID_EQUIPEMENT, :NOM_EQ, :IMAGE, :TYPE_EQ, :DESCRIPTION, :QUANTITE, :ETAT)");

    query.bindValue(":ID_EQUIPEMENT", res);
    query.bindValue(":NOM_EQ", NOM_EQ);
    query.bindValue(":IMAGE", IMAGE);
    query.bindValue(":TYPE_EQ", TYPE_eq);
    query.bindValue(":DESCRIPTION", DESCRIPTION);

    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT);


    return query.exec();

}



/*QSqlQueryModel * equipement::affichierEQ()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM equipement");
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EQ"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("IMAGE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_EQ"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
    return model;





    }
*/
QSqlQueryModel * equipement::affichierEQ()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    // Check if the database is open
    if (!QSqlDatabase::database().isOpen()) {
        qWarning() << "Database connection is not open!";
        return nullptr;
    }

    query.prepare("SELECT * FROM equipement");

    // Execute the query
    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError();
        return nullptr;
    }
    /*if (query.exec() && query.next()) {
        QByteArray imageData = query.value(0).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        ui-->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
    }*/

    // Set the query result to the model
    model->setQuery(query);

    // Set headers for the columns
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EQ"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IMAGE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_EQ"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));


    return model;
}

/*QSqlQueryModel * equipement::affichierEQ()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM equipement"); // Vérifier que le nom de la table est correct

    if (!query.exec()) {
        qDebug() << "Erreur SQL: " << query.lastError().text();
        return nullptr;  // Retourner un pointeur nul en cas d'erreur
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EQ"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IMAGE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_EQ"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}*/

bool equipement::supprimerEQ( int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Delete from EQUIPEMENT where ID_EQUIPEMENT=  :id");
    query.bindValue(":id",res);
    return query.exec();


    ;}
equipement::~equipement(){};
