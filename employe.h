#include <QDialog>
#include<QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

class Employe
{
    QString nom,prenom,specialite,genre,adresse,id_employe,email;
    int tel;
    int salaire;
public:
    Employe();
    Employe(QString,QString,QString,int,QString,QString,QString, int,QString);

    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getspecialite() const { return specialite; }
    QString getGenre() const { return genre; }
    QString getAdresse() const { return adresse; }
    QString getEmail() const { return email; }

    int getTel() const { return tel; }
    QString getid() const { return id_employe; }
    int getSalaire() const { return salaire; }

    void setNom(const QString &n) { nom = n; }
    void setPrenom(const QString &pn) { prenom = pn; }
    void setspecialite(const QString &s) { specialite = s; }
    void setTel(int t) { tel = t; }
    void setGenre(const QString &g) { genre = g; }
    void setAdresseemploye(const QString &ad) { adresse = ad; }
    void setId(const QString &i) { id_employe = i; }
    void setSalaire(int s) { salaire = s; }
    void setEmail(const QString &g) { email = g; }

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(QString);
    bool modifier(QString,QString,QString,int,QString,QString,QString, int,QString);
    //trie
    QSqlQueryModel* trier_par(const QString &colonne);
    QSqlQueryModel* rechercher(const QString &colonne, const QString &valeur);
    bool exporterPDF(const QString& fileName, QSqlQueryModel* model);

};
