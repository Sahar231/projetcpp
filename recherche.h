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
    int idVaccin;
    int idEmploye;
    int idEquipement;

public:
    Recherche();
    Recherche(int, QString, QString, QDate, QString, int, int, int);

    int getIdRech() { return idRech; }
    QString getNomRech() { return nomRech; }
    QString getTypeRech() { return typeRech; }
    QDate getDateRech() { return dateRech; }
    QString getStatut() { return statut; }
    int getIdVaccin() { return idVaccin; }
    int getIdEmploye() { return idEmploye; }
    int getIdEquipement() { return idEquipement; }

    void setIdRech(int idRech) { this->idRech = idRech; }
    void setNomRech(QString nomRech) { this->nomRech = nomRech; }
    void setTypeRech(QString typeRech) { this->typeRech = typeRech; }
    void setDateRech(QDate dateRech) { this->dateRech = dateRech; }
    void setStatut(QString statut) { this->statut = statut; }
    void setIdVaccin(int idVaccin) { this->idVaccin = idVaccin; }
    void setIdEmploye(int idEmploye) { this->idEmploye = idEmploye; }
    void setIdEquipement(int idEquipement) { this->idEquipement = idEquipement; }

    bool ajouter();
    bool supprimer(int idRech);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_id();
};

#endif
