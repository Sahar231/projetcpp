#ifndef employe_H
#define employe_H

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

class employe
{
    QString nom,prenom,specialite,genre,adresse,id_employe;
    int tel;
    int salaire;
public:
    employe();
    employe(QString,QString,QString,int,QString,QString,QString, int);

    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getspecialite() const { return specialite; }
    QString getGenre() const { return genre; }
    QString getAdresse() const { return adresse; }
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

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(QString);
    bool modifier(QString,QString,QString,int,QString,QString,QString, int);
};

#endif // employe_H
