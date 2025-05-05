#include "employe.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QPrinter>

Employe::Employe()
{
    id_employe =" ";
    nom =" ";
    prenom =" ";
    tel = 0;
    genre =" ";
    adresse =" ";
    specialite = " ";
    salaire = 0;
    email="";
}

Employe::Employe(QString id_employe,QString nom,QString prenom,int tel,QString genre,QString adresse,QString specialite, int salaire,QString email)
{
    this->id_employe =id_employe;
    this->nom =nom;
    this->prenom =prenom;
    this->tel =tel;
    this->genre =genre;
    this->adresse =adresse;
    this->specialite =specialite;
    this->salaire = salaire;
    this->email = email;

}

bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employe (id_employe, nom, prenom, tel, genre, adresse, specialite, salaire, email) "
                  "VALUES (:id_employe, :nom, :prenom, :tel, :genre, :adresse, :specialite, :salaire, :email)");

    query.bindValue(":id_employe", id_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":genre", genre);
    query.bindValue(":adresse", adresse);
    query.bindValue(":specialite", specialite);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email", email);

    return query.exec();
}

QSqlQueryModel *Employe::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from employe");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("EMAIL"));

    return model;
}

bool Employe::supprimer(QString cc)
{
    QSqlQuery query;
    query.prepare("Delete from employe where id_employe = :id_employe ");
    query.bindValue(":id_employe",cc);
    return query.exec();
}

bool Employe::modifier(QString id_employe,QString nom,QString prenom,int tel,QString genre,QString adresse,QString specialite, int salaire,QString email)
{
    QSqlQuery qry;
    qry.prepare("UPDATE employe SET nom = :nom, prenom = :prenom, tel = :tel, genre = :genre, "
                "adresse = :adresse, specialite = :specialite, salaire = :salaire, email = :email WHERE id_employe = :id_employe");

    qry.bindValue(":id_employe", id_employe);
    qry.bindValue(":nom", nom);
    qry.bindValue(":prenom", prenom);
    qry.bindValue(":tel", tel);
    qry.bindValue(":genre", genre);
    qry.bindValue(":adresse", adresse);
    qry.bindValue(":specialite", specialite);
    qry.bindValue(":salaire", salaire);
    qry.bindValue(":email", email);

    return qry.exec();
}
QSqlQueryModel* Employe::trier_par(const QString &colonne)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT * FROM employe ORDER BY " + colonne;

    model->setQuery(query);
    return model;
}

//rech
QSqlQueryModel* Employe::rechercher(const QString &colonne, const QString &valeur)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT * FROM employe WHERE " + colonne + " LIKE '%" + valeur + "%'";
    model->setQuery(query);
    return model;
}


bool Employe::exporterPDF(const QString& fileName, QSqlQueryModel* model)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Landscape);  // Orientation paysage
    printer.setOutputFileName(fileName);

    // Réduire les marges pour maximiser l'espace disponible
    QMarginsF margins(10, 10, 10, 10);  // Marges de 10mm
    printer.setPageMargins(margins, QPageLayout::Millimeter);

    QPainter painter(&printer);
    if (!painter.isActive()) {
        QMessageBox::warning(nullptr, "Erreur", "Impossible de dessiner sur l'imprimante.");
        return false;
    }

    // Définir la police et les couleurs
    painter.setFont(QFont("Arial", 10));
    QColor headerColor(49, 164, 180);  // Couleur d'arrière-plan des en-têtes
    QColor cellColor(230, 244, 241);   // Couleur d'arrière-plan des cellules

    // Positionnement de la table (marges internes)
    int x = 40;
    int y = 40;
    int rowHeight = 20;
    int colWidth = 120;  // Largeur des colonnes

    // Dessiner le titre du document
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.setPen(QPen(headerColor));
    painter.drawText(x, y, "Liste des Employés");
    y += 30;  // Décalage après le titre

    // Dessiner les en-têtes de table
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(QBrush(headerColor));
    painter.setPen(QPen(Qt::black));

    // Draw header cells for Employee data (ID, Nom, Prénom, Genre, Salaire)
    QStringList headers = {"ID Employé", "Nom", "Prénom", "Genre", "Salaire"};
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
        painter.drawText(x + col * colWidth + 5, y + 15, headers[col]);
    }

    y += rowHeight;  // Décalage après les en-têtes

    // Dessiner les lignes de données
    painter.setFont(QFont("Arial", 10));
    painter.setBrush(QBrush(cellColor));

    for (int row = 0; row < model->rowCount(); ++row) {
        // Check for page overflow and add a new page if necessary
        if (y + rowHeight > printer.pageRect(QPrinter::DevicePixel).bottom()) {
            painter.end();
            printer.newPage();
            painter.begin(&printer);
            y = 40;  // Reset Y position for new page

            // Re-draw headers on new page
            for (int col = 0; col < headers.size(); ++col) {
                painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
                painter.drawText(x + col * colWidth + 5, y + 15, headers[col]);
            }
            y += rowHeight;  // Adjust Y position after headers
        }

        // Draw each row's cells (corresponding to employee data)
        for (int col = 0; col < headers.size(); ++col) {
            painter.setPen(QPen(Qt::black));
            painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
            QString data = model->data(model->index(row, col)).toString();
            painter.drawText(x + col * colWidth + 5, y + 15, data);
        }
        y += rowHeight;  // Pass to the next row
    }

    // Finaliser l'impression
    painter.end();

    return true;
}
