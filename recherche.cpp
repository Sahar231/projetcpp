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
    idEmploye = 0;
}

Recherche::Recherche(int idRech, QString nomRech, QString typeRech, QDate dateRech, QString statut, int idEmploye)
{
    this->idRech = idRech;
    this->nomRech = nomRech;
    this->typeRech = typeRech;
    this->dateRech = dateRech;
    this->statut = statut;
    this->idEmploye = idEmploye;
}

bool Recherche::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RECHERCHES (ID_RECH, NOM_RECH, TYPE_RECH, DATE_RECH, STATUT,ID_EMPLOYE) "
                  "VALUES (:ID_RECH, :NOM_RECH, :TYPE_RECH, :DATE_RECH, :STATUT,:ID_EMPLOYE)");
    query.bindValue(":ID_RECH", idRech);
    query.bindValue(":NOM_RECH", nomRech);
    query.bindValue(":TYPE_RECH", typeRech);
    query.bindValue(":DATE_RECH", dateRech);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_EMPLOYE", idEmploye);
    return query.exec();
}

bool Recherche::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE RECHERCHES SET NOM_RECH=:NOM_RECH, TYPE_RECH=:TYPE_RECH, DATE_RECH=:DATE_RECH, STATUT=:STATUT, "
                  "ID_EMPLOYE=:ID_EMPLOYE "
                  "WHERE ID_RECH=:ID_RECH");
    query.bindValue(":ID_RECH", idRech);
    query.bindValue(":NOM_RECH", nomRech);
    query.bindValue(":TYPE_RECH", typeRech);
    query.bindValue(":DATE_RECH", dateRech);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_EMPLOYE", idEmploye);
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
                    "STATUT, TO_CHAR(ID_EMPLOYE) AS ID_EMPLOYE "
                    " FROM RECHERCHES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Recherche"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Recherche"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Recherche"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}

QSqlQueryModel* Recherche::afficher_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECH FROM RECHERCHES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    return model;
}
QSqlQueryModel* Recherche::Afficher_Tri_NOM() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT TO_CHAR(ID_RECH) AS ID_RECH, NOM_RECH, TYPE_RECH, TO_CHAR(DATE_RECH, 'YYYY-MM-DD') AS DATE_RECH, STATUT, TO_CHAR(ID_EMPLOYE) AS ID_EMPLOYE FROM RECHERCHES ORDER BY NOM_RECH");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Recherche"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Recherche"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Recherche"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}

QSqlQueryModel* Recherche::Afficher_Tri_TYPE() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT TO_CHAR(ID_RECH) AS ID_RECH, NOM_RECH, TYPE_RECH, TO_CHAR(DATE_RECH, 'YYYY-MM-DD') AS DATE_RECH, STATUT, TO_CHAR(ID_EMPLOYE) AS ID_EMPLOYE FROM RECHERCHES ORDER BY TYPE_RECH");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Recherche"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Recherche"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Recherche"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}

QSqlQueryModel* Recherche::Afficher_Tri_STATUT() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT TO_CHAR(ID_RECH) AS ID_RECH, NOM_RECH, TYPE_RECH, TO_CHAR(DATE_RECH, 'YYYY-MM-DD') AS DATE_RECH, STATUT, TO_CHAR(ID_EMPLOYE) AS ID_EMPLOYE FROM RECHERCHES ORDER BY STATUT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Recherche"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Recherche"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Recherche"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Recherche"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}
void Recherche::clearTable(QTableView *table) {
    QSqlQueryModel* modelFeragh = new QSqlQueryModel();
    modelFeragh->clear();
    table->setModel(modelFeragh);
}

void Recherche::Rechercher(QTableView *table, QString x, QString critere) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery;

    QString baseQuery = "SELECT TO_CHAR(ID_RECH) AS ID_RECH, NOM_RECH, TYPE_RECH, TO_CHAR(DATE_RECH, 'YYYY-MM-DD') AS DATE_RECH, STATUT, TO_CHAR(ID_EMPLOYE) AS ID_EMPLOYE "
                        "FROM RECHERCHES";

    if (!x.isEmpty()) {
        baseQuery += " WHERE regexp_like(" + critere + ", :X, 'i')";
        query->prepare(baseQuery);
        query->bindValue(":X", x);
    } else {
        query->prepare(baseQuery);
    }

    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

