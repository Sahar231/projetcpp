#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlError>
#include <QDebug>
#include <QObject>
#include <QJsonObject>

class Recherche : public QObject
{
    Q_OBJECT  // Nécessaire pour les signaux/slots

private:
    int idRech;
    QString nomRech;
    QString typeRech;
    QDate dateRech;
    QString statut;
    int idEmploye;
    int etat;

public:
    // Constructeur par défaut
    explicit Recherche(QObject* parent = nullptr);

    // Constructeur avec paramètres
    Recherche(int idRech, QString nomRech, QString typeRech, QDate dateRech,
              QString statut, int idEmploye, int etat);

    // Destructeur
    ~Recherche() {}

    // Getters
    int getIdRech() const { return idRech; }
    QString getNomRech() const { return nomRech; }
    QString getTypeRech() const { return typeRech; }
    QDate getDateRech() const { return dateRech; }
    QString getStatut() const { return statut; }
    int getIdEmploye() const { return idEmploye; }
    int getEtat() const { return etat; }

    // Setters
    void setIdRech(int id) { idRech = id; }
    void setNomRech(QString nom) { nomRech = nom; }
    void setTypeRech(QString type) { typeRech = type; }
    void setDateRech(QDate date) { dateRech = date; }
    void setStatut(QString s) { statut = s; }
    void setIdEmploye(int id) { idEmploye = id; }
    void setEtat(int e) { etat = e; }

    // Méthodes CRUD
    bool ajouter();
    bool modifier();
    bool supprimer(int idRech);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_id();
    QSqlQueryModel* Afficher_Tri_NOM();
    QSqlQueryModel* Afficher_Tri_TYPE();
    QSqlQueryModel* Afficher_Tri_STATUT();

    // Méthodes utilitaires
    void Rechercher(QTableView* table, QString valeur, QString critere);
    void clearTable(QTableView* table);
    void retranslateHeaders(QSqlQueryModel* model, const QJsonObject& translations);
};

#endif // RECHERCHE_H
