#include "equipement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileDialog>
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
equipement::equipement(int ID_EQUIPEMENT,QString NOM_EQ,QString IMAGE,QString TYPE_eq,QString DESCRIPTION,int QUANTITE,QString ETAT,QDate DATE_ACHAT)
{
    this->ID_EQUIPEMENT=ID_EQUIPEMENT;
    this->NOM_EQ=NOM_EQ;
    this->IMAGE=IMAGE;
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

    query.prepare("INSERT INTO EQUIPEMENT (ID_EQUIPEMENT, NOM_EQ, IMAGE, TYPE_EQ, DESCRIPTION, QUANTITE, ETAT,DATE_ACHAT) "
                  "VALUES (:ID_EQUIPEMENT, :NOM_EQ, :IMAGE, :TYPE_EQ, :DESCRIPTION, :QUANTITE, :ETAT, :DATE_ACHAT)");

    query.bindValue(":ID_EQUIPEMENT", res);
    query.bindValue(":NOM_EQ", NOM_EQ);
    query.bindValue(":IMAGE", IMAGE);
    query.bindValue(":TYPE_EQ", TYPE_eq);
    query.bindValue(":DESCRIPTION", DESCRIPTION);

    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT);
    query.bindValue(":DATE_ACHAT", DATE_ACHAT);
    /*QFile file(IMAGE);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Erreur ouverture fichier image";
        return false;
    }
    QByteArray imageData = file.readAll();
    query.bindValue(":image", imageData);*/


    return query.exec();

}




QSqlQueryModel * equipement::affichierEQ()
{
    QSqlQueryModel * model = new QSqlQueryModel();



    model->setQuery("SELECT * FROM EQUIPEMENT");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EQ"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("IMAGE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_EQ"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE_ACHAT"));




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
    query.prepare("UPDATE EQUIPEMENT SET NOM_EQ = :nom, IMAGE = :image, TYPE_eq = :type, DESCRIPTION = :description, "
                  "ETAT = :etat, QUANTITE = :quantite, DATE_ACHAT = :date_achat WHERE ID_EQUIPEMENT = :id");

    query.bindValue(":id", ID_EQUIPEMENT);
    query.bindValue(":nom", NOM_EQ);
    query.bindValue(":image", IMAGE);
    query.bindValue(":type", TYPE_eq);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":etat", ETAT);
    query.bindValue(":quantite", QUANTITE);
    query.bindValue(":date_achat", DATE_ACHAT);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification :" << query.lastError().text();
        return false;
    }
    return true;
}
/*QByteArray equipement::loadImageFromFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) return QByteArray();
    return file.readAll();
}*/


equipement::~equipement(){};
