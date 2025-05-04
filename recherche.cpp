#include "recherche.h"
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QUrlQuery>
#include <QSerialPort>
#include <QSerialPortInfo>

// Constructeur par défaut
Recherche::Recherche(QObject* parent) : QObject(parent)
{
    idRech = 0;
    nomRech = "";
    typeRech = "";
    dateRech = QDate::currentDate(); // Par défaut, aujourd’hui
    statut = "";
    idEmploye = 0;
    etat = 1;
}

// Constructeur avec paramètres
Recherche::Recherche(int idRech, QString nomRech, QString typeRech, QDate dateRech, QString statut, int idEmploye, int etat)

{
    this->idRech = idRech;
    this->nomRech = nomRech;
    this->typeRech = typeRech;
    this->dateRech = dateRech;
    this->statut = statut;
    this->idEmploye = idEmploye;
    this->etat = etat;
}

bool Recherche::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RECHERCHES (ID_RECH, NOM_RECH, TYPE_RECH, DATE_RECH, STATUT, ID_EMPLOYE) "
                  "VALUES (:ID_RECH, :NOM_RECH, :TYPE_RECH, :DATE_RECH, :STATUT, :ID_EMPLOYE)");

    query.bindValue(":ID_RECH", idRech);
    query.bindValue(":NOM_RECH", nomRech);
    query.bindValue(":TYPE_RECH", typeRech);
    query.bindValue(":DATE_RECH", dateRech);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_EMPLOYE", idEmploye);

    return query.exec();
}

bool Recherche::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE RECHERCHES SET NOM_RECH=:NOM_RECH, TYPE_RECH=:TYPE_RECH, "
                  "DATE_RECH=:DATE_RECH, STATUT=:STATUT, ID_EMPLOYE=:ID_EMPLOYE WHERE ID_RECH=:ID_RECH");

    query.bindValue(":ID_RECH", idRech);
    query.bindValue(":NOM_RECH", nomRech);
    query.bindValue(":TYPE_RECH", typeRech);
    query.bindValue(":DATE_RECH", dateRech);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_EMPLOYE", idEmploye);

    return query.exec();
}

bool Recherche::supprimer(int idRech)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RECHERCHES WHERE ID_RECH = :ID_RECH");
    query.bindValue(":ID_RECH", idRech);

    return query.exec();
}

QSqlQueryModel* Recherche::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT R.ID_RECH, R.NOM_RECH, R.TYPE_RECH, "
                    "TO_CHAR(R.DATE_RECH, 'YYYY-MM-DD') as DATE_RECH, "
                    "R.STATUT, R.ID_EMPLOYE,R.ETAT "
                    "FROM RECHERCHES R "
                    "ORDER BY R.ID_RECH");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel* Recherche::afficher_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECH FROM RECHERCHES ORDER BY ID_RECH");
    return model;
}

QSqlQueryModel* Recherche::Afficher_Tri_NOM()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECH, NOM_RECH, TYPE_RECH, "
                    "TO_CHAR(DATE_RECH, 'YYYY-MM-DD') as DATE_RECH, "
                    "STATUT, ID_EMPLOYE "
                    "FROM RECHERCHES "
                    "ORDER BY NOM_RECH");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}

QSqlQueryModel* Recherche::Afficher_Tri_TYPE()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECH, NOM_RECH, TYPE_RECH, "
                    "TO_CHAR(DATE_RECH, 'YYYY-MM-DD') as DATE_RECH, "
                    "STATUT, ID_EMPLOYE "
                    "FROM RECHERCHES "
                    "ORDER BY TYPE_RECH");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}

QSqlQueryModel* Recherche::Afficher_Tri_STATUT()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECH, NOM_RECH, TYPE_RECH, "
                    "TO_CHAR(DATE_RECH, 'YYYY-MM-DD') as DATE_RECH, "
                    "STATUT, ID_EMPLOYE "
                    "FROM RECHERCHES "
                    "ORDER BY STATUT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    return model;
}

void Recherche::Rechercher(QTableView* table, QString valeur, QString critere)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = QString("SELECT ID_RECH, NOM_RECH, TYPE_RECH, "
                          "TO_CHAR(DATE_RECH, 'YYYY-MM-DD') as DATE_RECH, "
                          "STATUT, ID_EMPLOYE "
                          "FROM RECHERCHES WHERE %1 LIKE '%%2%' "
                          "ORDER BY ID_RECH").arg(critere, valeur);

    model->setQuery(sql);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Employé"));

    table->setModel(model);
}

void Recherche::clearTable(QTableView* table)
{
    table->setModel(nullptr);
}
void Recherche::retranslateHeaders(QSqlQueryModel* model, const QJsonObject& translations)
{
    if (!model) return;

    // Define standard column headers and their possible variations
    QMap<int, QStringList> headerVariations;

    // Create QStringList for each column and add to the map
    QStringList col0; col0 << "ID Recherche" << "IDRecherche" << "ID" << "ИД" << "المعرف";
    QStringList col1; col1 << "Nom Recherche" << "NomRecherche" << "Nom" << "Name" << "Имя" << "الاسم" << "Nome" << "Nombre";
    QStringList col2; col2 << "Type Recherche" << "TypeRecherche" << "Type" << "Тип" << "النوع" << "Tipo" << "Typ";
    QStringList col3; col3 << "Date Recherche" << "DateRecherche" << "Date" << "Дата" << "التاريخ" << "Data" << "Datum" << "Fecha";
    QStringList col4; col4 << "Statut" << "Status" << "Статус" << "الحالة" << "Stato" << "Estado";
    QStringList col5; col5 << "ID Employé" << "ID_Employe" << "ID Employe" << "ID сотрудника" << "معرف الموظف" << "ID Impiegato" << "ID Empleado";

    headerVariations[0] = col0;
    headerVariations[1] = col1;
    headerVariations[2] = col2;
    headerVariations[3] = col3;
    headerVariations[4] = col4;
    headerVariations[5] = col5;

    // Apply translations to each column header
    for (int col = 0; col < qMin(headerVariations.size(), model->columnCount()); ++col) {
        // Get all possible variations for this column
        const QStringList& variations = headerVariations[col];

        // Try each variation to find a translation
        QString translated;
        for (const QString& headerVariation : variations) {
            if (translations.contains(headerVariation)) {
                translated = translations[headerVariation].toString();
                if (!translated.isEmpty()) {
                    break;
                }
            }
        }

        // Apply the translation if found
        if (!translated.isEmpty()) {
            model->setHeaderData(col, Qt::Horizontal, translated);
        }
    }
}

