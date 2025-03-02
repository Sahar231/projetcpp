#include "recherche.h"
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QUrlQuery>

Recherche::Recherche()
{
    idRech = 0;
    nomRech = "";
    typeRech = "";
    dateRech = QDate::currentDate(); // Default to current date
    statut = "";
    idVaccin = 0;
    idEmploye = 0;
    idEquipement = 0;
}

Recherche::Recherche(int idRech, QString nomRech, QString typeRech, QDate dateRech, QString statut, int idVaccin, int idEmploye, int idEquipement)
{
    this->idRech = idRech;
    this->nomRech = nomRech;
    this->typeRech = typeRech;
    this->dateRech = dateRech;
    this->statut = statut;
    this->idVaccin = idVaccin;
    this->idEmploye = idEmploye;
    this->idEquipement = idEquipement;
}

bool Recherche::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RECHERCHES (ID_RECH, NOM_RECH, TYPE_RECH, DATE_RECH, STATUT, ID_VACCIN, ID_EMPLOYE, ID_EQUIPEMENT) "
                  "VALUES (:ID_RECH, :NOM_RECH, :TYPE_RECH, :DATE_RECH, :STATUT, :ID_VACCIN, :ID_EMPLOYE, :ID_EQUIPEMENT)");
    query.bindValue(":ID_RECH", idRech);
    query.bindValue(":NOM_RECH", nomRech);
    query.bindValue(":TYPE_RECH", typeRech);
    query.bindValue(":DATE_RECH", dateRech);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_VACCIN", idVaccin);
    query.bindValue(":ID_EMPLOYE", idEmploye);
    query.bindValue(":ID_EQUIPEMENT", idEquipement);
    return query.exec();
}

bool Recherche::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE RECHERCHES SET NOM_RECH=:NOM_RECH, TYPE_RECH=:TYPE_RECH, DATE_RECH=:DATE_RECH, STATUT=:STATUT, "
                  "ID_VACCIN=:ID_VACCIN, ID_EMPLOYE=:ID_EMPLOYE, ID_EQUIPEMENT=:ID_EQUIPEMENT "
                  "WHERE ID_RECH=:ID_RECH");
    query.bindValue(":ID_RECH", idRech);
    query.bindValue(":NOM_RECH", nomRech);
    query.bindValue(":TYPE_RECH", typeRech);
    query.bindValue(":DATE_RECH", dateRech);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_VACCIN", idVaccin);
    query.bindValue(":ID_EMPLOYE", idEmploye);
    query.bindValue(":ID_EQUIPEMENT", idEquipement);
    return query.exec();
}

bool Recherche::supprimer(int idRech)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RECHERCHES WHERE ID_RECH = :ID_RECH");
    query.bindValue(":ID_RECH", idRech);
    return query.exec();
}

QSqlQueryModel* Recherche::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT TO_CHAR(ID_RECH) AS ID_RECH, NOM_RECH, TYPE_RECH, TO_CHAR(DATE_RECH, 'YYYY-MM-DD') AS DATE_RECH, "
                    "STATUT, TO_CHAR(ID_VACCIN) AS ID_VACCIN, TO_CHAR(ID_EMPLOYE) AS ID_EMPLOYE, "
                    "TO_CHAR(ID_EQUIPEMENT) AS ID_EQUIPEMENT FROM RECHERCHES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Recherche"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Recherche"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Recherche"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Vaccin"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID Employé"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID Équipement"));
    return model;
}

QSqlQueryModel* Recherche::afficher_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECH FROM RECHERCHES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    return model;
}
