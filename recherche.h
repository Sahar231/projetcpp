#ifndef RECHERCHE_H
#define RECHERCHE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Recherche
{
    int idRech;
    QString nomRech;
    QString typeRech;
    QDate dateRech;
    QString statut;
    int idEmploye;

public:
    Recherche();
    Recherche(int, QString, QString, QDate, QString, int);

    int getIdRech() { return idRech; }
    QString getNomRech() { return nomRech; }
    QString getTypeRech() { return typeRech; }
    QDate getDateRech() { return dateRech; }
    QString getStatut() { return statut; }
    int getIdEmploye() { return idEmploye; }

    void setIdRech(int idRech) { this->idRech = idRech; }
    void setNomRech(QString nomRech) { this->nomRech = nomRech; }
    void setTypeRech(QString typeRech) { this->typeRech = typeRech; }
    void setDateRech(QDate dateRech) { this->dateRech = dateRech; }
    void setStatut(QString statut) { this->statut = statut; }
    void setIdEmploye(int idEmploye) { this->idEmploye = idEmploye; }

    void clearTable(QTableView *table);
    void Rechercher(QTableView *table, QString x, QString critere);

    bool ajouter();
    bool supprimer(int idRech);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_id();
    QSqlQueryModel* Afficher_Tri_STATUT();
    QSqlQueryModel* Afficher_Tri_TYPE();
    QSqlQueryModel* Afficher_Tri_NOM();
};

#endif
