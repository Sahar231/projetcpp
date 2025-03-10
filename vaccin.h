#ifndef VACCIN_H
#define VACCIN_H

#include <QString>
#include <QDate>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel> // Ajouté pour éviter l'erreur

class Vaccin
{
private:
    int idVaccin;
    QString nomVaccin;
    QString effetsSecondaires;
    QString composition;
    int quantite;
    QDate dateCreation;
    QDate datePeremption;
    QString typeVaccin;
    int idRech;

public:
    Vaccin();
    Vaccin(int id, QString nom, QString effets, QString compo, int quant, QDate dateC, QDate dateP, QString type, int idR);

    bool ajouterVaccin();            // Vérifié ✅
    bool supprimerVaccin(int id);    // Vérifié ✅
    bool modifierVaccin();           // Nouvelle méthode pour modifier un vaccin
    static QSqlQueryModel* afficher(); // Vérifié ✅
};

#endif // VACCIN_H
