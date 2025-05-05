#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H

#include <QMainWindow>
#include <QObject>
#include <QDate>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class equipement
{
public:
    equipement(){}
    equipement(int,QString,QString,QString,int,QString,QDate);
    int get_id(){ return ID_EQUIPEMENT;}
    QString get_nom(){ return NOM_EQ; }

    QString get_type(){ return TYPE_eq ; }
    QString get_description(){ return DESCRIPTION ;}
    QString get_etat(){ return ETAT; }
    QDate get_date() { return DATE_ACHAT; }
    int get_quantite(){ return QUANTITE ;}
    void set_id(int id){ ID_EQUIPEMENT=id ;}
    void set_nom(QString nom){ NOM_EQ=nom ;}

    void set_description(QString des){ DESCRIPTION=des ;}
    void set_etat(QString et){ETAT=et ;}
    void set_type(QString type_e){ TYPE_eq=type_e ;}
    void set_date(QDate date) { DATE_ACHAT = date; }
    void set_quantite(int qu){ QUANTITE =qu ;}
    bool ajouterEQ();
    QSqlQueryModel * affichierEQ();
    bool supprimerEQ(int);
    bool modifierEQ();
    QSqlQueryModel * Rechercher(QString valeur);
    QSqlQueryModel * trier(QString critere);
    bool idExiste(int);
    ~equipement();

private:
    int ID_EQUIPEMENT;

    QString NOM_EQ,TYPE_eq, DESCRIPTION,ETAT;
    int QUANTITE;
    QDate DATE_ACHAT;


};

#endif // EQUIPEMENTS_H
