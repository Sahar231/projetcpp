#ifndef FORMATION_H
#define FORMATION_H
#include <QMainWindow>
#include <QObject>

#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class formation {
public:
    formation() {}
    formation(int, QDate, QDate, int, QString ,  int,QString,int);

    int get_id() const { return ID; }
    QDate get_datedebut() const { return DATEDEBUT; }
    QDate get_datefin() const { return DATEFIN; }
    QString get_lieu() const { return LIEU; }

    QString get_certificat() const { return CERTIFICAT; }
    int get_heure() const { return HEURE; }
    int get_par(){ return PARTICIPANT;}
    void set_id(int id) { ID = id; }
    void set_datedebut(QDate date) { DATEDEBUT = date; }
    void set_datefin(QDate date) { DATEFIN = date; }
    void set_lieu(const QString& lieu) { LIEU = lieu; }

    void set_certificat(const QString& certif) { CERTIFICAT = certif; }
    void set_heure(int heure) { HEURE = heure; }
    void set_par(int par) { PARTICIPANT=par;}
    bool ajouterFormation();
    QSqlQueryModel* afficherFormation();
    bool supprimerFormation(int);
    bool modifierFormation();
    QSqlQueryModel* trier(QString critere);
    QSqlQueryModel* Rechercher(QString valeur);

    ~formation();

private:
    int ID;
    QDate DATEDEBUT, DATEFIN;
    QString LIEU, CERTIFICAT;

    int HEURE;
    int PARTICIPANT;
    int NOMBREMAX;
};








#endif // FORMATION_H
