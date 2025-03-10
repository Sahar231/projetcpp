#include "vaccin.h"

Vaccin::Vaccin() {}

Vaccin::Vaccin(int id, QString nom, QString effets, QString compo, int quant, QDate dateC, QDate dateP, QString type, int idR)
    : idVaccin(id), nomVaccin(nom), effetsSecondaires(effets), composition(compo), quantite(quant),
    dateCreation(dateC), datePeremption(dateP), typeVaccin(type), idRech(idR) {}

bool Vaccin::ajouterVaccin()
{
    QSqlQuery query;
    query.prepare("INSERT INTO \"C##LABSYNC_NEW\".\"VACCINS\" "
                  "(\"ID_VACCIN\", \"NOM_VACCIN\", \"EFFET_SECONDAIRE\", \"COMPOSITION\", \"QUANTITÉ\", \"DATE_CRÉATION\", \"DATE_PEREMPTION\", \"TYPE\", \"ID_RECH_PK1\") "
                  "VALUES (:id, :nom, :effets, :compo, :quantite, TO_DATE(:dateC, 'YYYY-MM-DD'), TO_DATE(:dateP, 'YYYY-MM-DD'), :type, :idRech)");

    query.bindValue(":id", idVaccin);
    query.bindValue(":nom", nomVaccin);
    query.bindValue(":effets", effetsSecondaires);
    query.bindValue(":compo", composition);
    query.bindValue(":quantite", quantite);
    query.bindValue(":dateC", dateCreation.toString("yyyy-MM-dd"));
    query.bindValue(":dateP", datePeremption.toString("yyyy-MM-dd"));
    query.bindValue(":type", typeVaccin);
    query.bindValue(":idRech", idRech);

    return query.exec();
}

bool Vaccin::supprimerVaccin(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"ID_VACCIN\" = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Vaccin::modifierVaccin()
{
    QSqlQuery query;
    query.prepare("UPDATE \"C##LABSYNC_NEW\".\"VACCINS\" SET "
                  "\"NOM_VACCIN\" = :nom, "
                  "\"EFFET_SECONDAIRE\" = :effets, "
                  "\"COMPOSITION\" = :compo, "
                  "\"QUANTITÉ\" = :quantite, "
                  "\"DATE_CRÉATION\" = TO_DATE(:dateC, 'YYYY-MM-DD'), "
                  "\"DATE_PEREMPTION\" = TO_DATE(:dateP, 'YYYY-MM-DD'), "
                  "\"TYPE\" = :type, "
                  "\"ID_RECH_PK1\" = :idRech "
                  "WHERE \"ID_VACCIN\" = :id");

    query.bindValue(":id", idVaccin); // ID du vaccin à modifier
    query.bindValue(":nom", nomVaccin);
    query.bindValue(":effets", effetsSecondaires);
    query.bindValue(":compo", composition);
    query.bindValue(":quantite", quantite);
    query.bindValue(":dateC", dateCreation.toString("yyyy-MM-dd"));
    query.bindValue(":dateP", datePeremption.toString("yyyy-MM-dd"));
    query.bindValue(":type", typeVaccin);
    query.bindValue(":idRech", idRech);

    return query.exec();
}

QSqlQueryModel* Vaccin::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\"");
    return model;
}
