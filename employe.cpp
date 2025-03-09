#include "employe.h"
#include <QSqlError>

employe::employe()
{
    id_employe =" ";
    nom =" ";
    prenom =" ";
    tel = 0;
    genre =" ";
    adresse =" ";
    specialite = " ";
    salaire = 0;
}

employe::employe(QString id_employe,QString nom,QString prenom,int tel,QString genre,QString adresse,QString specialite, int salaire)
{
    this->id_employe =id_employe;
    this->nom =nom;
    this->prenom =prenom;
    this->tel =tel;
    this->genre =genre;
    this->adresse =adresse;
    this->specialite =specialite;
    this->salaire = salaire;
}

bool employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employe (id_employe, nom, prenom, tel, genre, adresse, specialite, salaire) "
                  "VALUES (:id_employe, :nom, :prenom, :tel, :genre, :adresse, :specialite, :salaire)");

    query.bindValue(":id_employe", id_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":genre", genre);
    query.bindValue(":adresse", adresse);
    query.bindValue(":specialite", specialite);
    query.bindValue(":salaire", salaire);

    return query.exec();
}

QSqlQueryModel *employe::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from employe");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("SALAIRE"));

    return model;
}

bool employe::supprimer(QString cc)
{
    QSqlQuery query;
    query.prepare("Delete from employe where id_employe = :id_employe ");
    query.bindValue(":id_employe",cc);
    return query.exec();
}

bool employe::modifier(QString id_employe,QString nom,QString prenom,int tel,QString genre,QString adresse,QString specialite, int salaire)
{
    QSqlQuery qry;
    qry.prepare("UPDATE employe SET nom = :nom, prenom = :prenom, tel = :tel, genre = :genre, "
                "adresse = :adresse, specialite = :specialite, salaire = :salaire WHERE id_employe = :id_employe");

    qry.bindValue(":id_employe", id_employe);
    qry.bindValue(":nom", nom);
    qry.bindValue(":prenom", prenom);
    qry.bindValue(":tel", tel);
    qry.bindValue(":genre", genre);
    qry.bindValue(":adresse", adresse);
    qry.bindValue(":specialite", specialite);
    qry.bindValue(":salaire", salaire);

    return qry.exec();
}
