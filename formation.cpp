#include "formation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

formation::formation(int ID, QDate DATEDEBUT, QDate DATEFIN,int HEURE , QString LIEU,   int PARTICIPANT , QString CERTIFICAT,int NOMBREMAX)
{
    this->ID = ID;
    this->DATEDEBUT = DATEDEBUT;
    this->DATEFIN = DATEFIN;
    this->HEURE = HEURE;
    this->LIEU = LIEU;
    this->PARTICIPANT=PARTICIPANT;

    this->CERTIFICAT = CERTIFICAT;
    this->NOMBREMAX=NOMBREMAX;



}

bool formation::ajouterFormation()
{
    QSqlQuery query;
    QString res = QString::number(ID);

    query.prepare("INSERT INTO FORMATION (ID, DATEDEBUT, DATEFIN, HEURE, LIEU, PARTICIPANT, CERTIFICAT,NOMBREMAX) "
                  "VALUES (:ID, :DATEDEBUT, :DATEFIN, :HEURE, :LIEU, :PARTICIPANT,  :CERTIFICAT,:NOMBREMAX)");

    query.bindValue(":ID", res);
    query.bindValue(":DATEDEBUT", DATEDEBUT);
    query.bindValue(":DATEFIN", DATEFIN);
    query.bindValue(":HEURE", HEURE);
    query.bindValue(":LIEU", LIEU);
    query.bindValue(":PARTICIPANT", PARTICIPANT);

    query.bindValue(":CERTIFICAT", CERTIFICAT);
    query.bindValue(":NOMBREMAX", NOMBREMAX);

    return query.exec();

}

QSqlQueryModel* formation::afficherFormation()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FORMATION");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEFIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PARTICIPANT"));

    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CERTIFICAT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOMBREMAX"));



    return model;
}

bool formation::supprimerFormation(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("DELETE FROM FORMATION WHERE ID = :id");
    query.bindValue(":id", res);

    return query.exec();
}

bool formation::modifierFormation()
{
    QSqlQuery query;
    query.prepare("UPDATE FORMATION SET DATEDEBUT = :datedebut, DATEFIN = :datefin, HEURE = :heure, "
                  "LIEU = :lieu, PARTICIPANT = :participant,  CERTIFICAT = :certificat,NOMBREMAX=:nombremax "
                  "WHERE ID = :id");

    query.bindValue(":id", ID);
    query.bindValue(":datedebut", DATEDEBUT);
    query.bindValue(":datefin", DATEFIN);
    query.bindValue(":heure", HEURE);
    query.bindValue(":lieu", LIEU);
    query.bindValue(":participant", PARTICIPANT);

    query.bindValue(":certificat", CERTIFICAT);
    query.bindValue(":nombremax",NOMBREMAX);


    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour :" << query.lastError().text();
        return false;
    }
    return true;

}
QSqlQueryModel* formation::Rechercher(QString valeur)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;


    query.prepare("SELECT * FROM FORMATION WHERE ID || DATEDEBUT|| DATEFIN || LIEU  || CERTIFICAT || HEURE || PARTICIPANT || NOMBREMAX LIKE :valeur");


    query.bindValue(":valeur", "%" + valeur + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }

    return model;
}
QSqlQueryModel* formation::trier(QString critere)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Protection contre les critères invalides
    QString tri = critere.toLower();

    if(tri == "id")
        model->setQuery("SELECT * FROM FORMATION ORDER BY ID ASC");

    else
        model->setQuery("SELECT * FROM FORMATION "); // par défaut

    return model;
}
formation::~formation() {}

