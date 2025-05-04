#include "equipements.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
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
equipement::equipement(int ID_EQUIPEMENT,QString NOM_EQ,QString TYPE_eq,QString DESCRIPTION,int QUANTITE,QString ETAT,QDate DATE_ACHAT)
{
    this->ID_EQUIPEMENT=ID_EQUIPEMENT;
    this->NOM_EQ=NOM_EQ;

    this->TYPE_eq=TYPE_eq;
    this->DESCRIPTION=DESCRIPTION;
    this->ETAT=ETAT;

    this->QUANTITE=QUANTITE;
    this->DATE_ACHAT=DATE_ACHAT;


}


bool equipement::ajouterEQ()
{
    QSqlQuery query;
    QString res = QString::number(ID_EQUIPEMENT);



    query.prepare("INSERT INTO EQUIPEMENT (ID_EQUIPEMENT, NOM_EQ, TYPE_EQ, DESCRIPTION, QUANTITE, ETAT, DATE_ACHAT) "
                  "VALUES (:ID_EQUIPEMENT, :NOM_EQ, :TYPE_EQ, :DESCRIPTION, :QUANTITE, :ETAT, :DATE_ACHAT)");


    query.bindValue(":ID_EQUIPEMENT", res);
    query.bindValue(":NOM_EQ", NOM_EQ);

    query.bindValue(":TYPE_EQ", TYPE_eq);
    query.bindValue(":DESCRIPTION", DESCRIPTION);

    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT);
    query.bindValue(":DATE_ACHAT", DATE_ACHAT);






   return query.exec();
}




QSqlQueryModel * equipement::affichierEQ()
{
    QSqlQueryModel * model = new QSqlQueryModel();



    model->setQuery("SELECT ID_EQUIPEMENT, NOM_EQ, TYPE_EQ, DESCRIPTION, QUANTITE, ETAT, TO_CHAR(DATE_ACHAT, 'DD-MM-YYYY') as DATE_ACHAT FROM EQUIPEMENT");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date achat"));



    return model;
}



bool equipement::supprimerEQ( int id)
{


    QSqlQuery query;
    QString res=QString::number(id);


    query.prepare("Delete from EQUIPEMENT where ID_EQUIPEMENT=  :id");
    query.bindValue(":id",res);
    return query.exec();
}



bool equipement::modifierEQ()
{
    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENT SET NOM_EQ = :nom, TYPE_eq = :type, DESCRIPTION = :description, "
                  "ETAT = :etat, QUANTITE = :quantite, DATE_ACHAT = :date_achat WHERE ID_EQUIPEMENT = :id");

    query.bindValue(":id", ID_EQUIPEMENT);
    query.bindValue(":nom", NOM_EQ);
    query.bindValue(":type", TYPE_eq);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":etat", ETAT);
    query.bindValue(":quantite", QUANTITE);
    query.bindValue(":date_achat", DATE_ACHAT);


    return query.exec();
}

bool equipement::idExiste(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("SELECT COUNT(*) FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", res);

    if(query.exec())
    {
        if(query.next())
        {
            int count = query.value(0).toInt();
            return (count > 0);
        }
    }
    return false;
}
QSqlQueryModel* equipement::Rechercher(QString valeur)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;


    query.prepare("SELECT * FROM EQUIPEMENT WHERE ID_EQUIPEMENT || NOM_EQ || TYPE_EQ || DESCRIPTION || QUANTITE || ETAT || DATE_ACHAT LIKE :valeur");


    query.bindValue(":valeur", "%" + valeur + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }

    return model;
}
QSqlQueryModel* equipement::trier(QString critere)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Protection contre les critères invalides
    QString tri = critere.toLower();

    if(tri == "nom")
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY NOM_EQ ASC");
    else if(tri == "type")
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY TYPE_EQ ASC");
    else if(tri == "quantite")
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY QUANTITE DESC");
    else if(tri == "etat")
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY ETAT ASC");
    else if(tri == "date")
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY DATE_ACHAT DESC");
    else
        model->setQuery("SELECT * FROM EQUIPEMENT"); // par défaut

    return model;
}

equipement::~equipement(){};
