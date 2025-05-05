#include "equip.h"
#include "ui_equip.h"
#include <QString>
#include "equipements.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "login.h"
#include <QFileDialog>
#include "EtatDelegate.h"
#include "historique.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include "statistique.h"
#include "patie.h"
#include "form.h"
#include "user.h"
#include <QNetworkRequest>
#include <QMessageBox>
#include <QBuffer>
#include <QPainter>
#include <QTextDocument>
#include <QProcess>
#include <QMessageBox>

#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QUrl>
#include "projet.h"
#include "mainwindow.h"


equip::equip(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::equip)
{
    ui->setupUi(this);

    QPalette palette;
    QPixmap pixmap("c:/Users/Sahar/Bureau/project/integration/back55.jpg");
    palette.setBrush(QPalette::Window,  pixmap);
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);

    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));


    ui->pushButton_3->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/edit.png"));
        ui->pushButton_3->setIconSize(QSize(100, 38));
    ui->pushButton_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/delete.png"));
        ui->pushButton_2->setIconSize(QSize(138, 29));
    ui->comboBox->addItem("en panne");
    ui->comboBox->setItemData(1, QColor(Qt::red), Qt::ForegroundRole);

    ui->comboBox->addItem("en service");
    ui->comboBox->setItemData(2, QColor(Qt::blue), Qt::ForegroundRole);

    ui->comboBox->addItem("disponible");
    ui->comboBox->setItemData(0, QColor(Qt::green), Qt::ForegroundRole);

    ui->btnemploye->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));

    ui->btnpatient->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));

    ui->btnvaccins->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));

    ui->btnequipement->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));

    ui->btnformation->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));

    ui->btnrecherche->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));



    ui->pdf->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/stat.png"));
    ui->pdf_2->setIconSize(QSize(120, 90));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    // Actualiser
    ui->actuliser->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/actualiser.png"));
    ui->actuliser->setIconSize(QSize(80, 40));
    ui->actuliser->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    // Rechercher
    ui->rechercher->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/rechecher.png"));
    ui->rechercher->setIconSize(QSize(80, 40));
    ui->rechercher->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    // Historique
    ui->historique->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/historique.png"));
    ui->historique->setIconSize(QSize(80, 40));
    ui->historique->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    // Autofill
    ui->autoFillButton->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/autofill.png"));
    ui->autoFillButton->setIconSize(QSize(91, 51));
    ui->autoFillButton->setStyleSheet("QPushButton { border: 0px; background: transparent; }");


    ui->recherche->setPlaceholderText("rechercher un equipement  ");


    ui->supprimer->setPlaceholderText("donner id a supprime");



    ui->trier->addItem("nom");
    ui->trier->addItem("type");
    ui->trier->addItem("quantite");
    ui->trier->addItem("etat");
    ui->trier->addItem("date");
    ui->tableView->setModel(equ.affichierEQ());
    ui->tableView->show();
    ui->tableView->setWordWrap(true);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->resizeRowsToContents(); // Ajuster la hauteur des lignes automatiquement

    ui->tableView->setItemDelegateForColumn(5, new EtatDelegate(ui->tableView));







}
void equip::on_pushButton_clicked()
{

    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();
    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->textEdit->toPlainText();
    QDate DATE_ACHAT=ui->dd->date();
    int QUANTITE = ui->spinBox->value();
    QString ETAT= ui->comboBox->currentText();

   if (ID_EQUIPEMENT <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'équipement doit être un nombre positif et unique !");
        return;
    }
    if(equ.idExiste(ID_EQUIPEMENT ))
    {         QMessageBox::warning(this, "Erreur", "Cet ID existe  !");

        return;
    }


    if (NOM_EQ.isEmpty() || TYPE_eq.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le type de l'équipement ne doivent pas être vides !");
        return;
    }
    // Vérification de la description (minimum 10 caractères)
    if (DESCRIPTION.isEmpty() ) {
        QMessageBox::warning(this, "Erreur", "La description ne doivent pas être vides !");
        return;
    }

    // Vérification de la quantité
    if (QUANTITE < 1) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre positif !");
        return;
    }
    if (DATE_ACHAT > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date d'achat ne peut pas être dans le futur !");
        return;
    }
    if (DATE_ACHAT > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date d'achat ne peut pas être dans le futur !");
        return;
    }



    equipement eq ( ID_EQUIPEMENT, NOM_EQ, TYPE_eq, DESCRIPTION, QUANTITE, ETAT ,DATE_ACHAT);
    bool test=eq.ajouterEQ();
    if(test){
       ui->tableView->setModel(equ.affichierEQ());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("ajout non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit->clear();   // Réinitialise le champ pour l'ID_EQUIPEMENT
    ui->lineEdit_2->clear();  // Réinitialise le champ pour le NOM_EQ
    ui->lineEdit_4->clear();  // Réinitialise le champ pour le TYPE_eq
    ui->textEdit->clear();  // Réinitialise le champ pour la DESCRIPTION
    ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
    ui->spinBox->setValue(1);  // Réinitialise la valeur de QUANTITE à 0
    ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)

}


void equip::on_autoFillButton_clicked()
{





        QString apiKey = "AIzaSyCDpmQmNjDY9ME5fIGPgaNL9-c9n5fnGJc";

    QString equipmentName = ui->lineEdit_2->text().trimmed();
    if (equipmentName.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer le nom de l'équipement.");
        return;
    }

        QString prompt = QString(
                             "Donne-moi le type simple et description plus plus plus plus plus  simple et plus plus courte    de l'équipement de laboratoire appelé '%1'. "
                             "Réponds au format :\nType: ...\nDescription: ..."
                             ).arg(equipmentName);

    QString url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=" + apiKey;







       QNetworkRequest request = QNetworkRequest(QUrl(url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QJsonObject textPart;
        textPart["text"] = prompt;

        QJsonObject message;
        QJsonArray parts;
        parts.append(textPart);
        message["contents"] = QJsonArray{ QJsonObject{ { "parts", parts } } };

        QJsonDocument doc(message);

        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
                QJsonObject rootObj = responseDoc.object();

                QJsonArray candidates = rootObj["candidates"].toArray();
                if (!candidates.isEmpty()) {
                    QString content = candidates[0].toObject()["content"].toObject()["parts"].toArray()[0].toObject()["text"].toString();

                    QString type, description;
                    QStringList lines = content.split('\n');
                    for (const QString& line : lines) {
                        if (line.toLower().startsWith("type:"))
                            type = line.section(':', 1).trimmed();
                        else if (line.toLower().startsWith("description:"))
                            description = line.section(':', 1).trimmed();
                    }

                    ui->lineEdit_4->setText(type);
                    ui->textEdit->setText(description);

                    if (type.isEmpty() || description.isEmpty()) {
                        QMessageBox::warning(this, "Erreur", "La réponse de l'IA est incomplète.");
                    } else {
                        QMessageBox::information(this, "Succès", "Les informations ont été récupérées avec succès.");
                    }
                } else {
                    QMessageBox::warning(this, "Erreur", "Aucune réponse de l'IA.");
                }
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la requête : " + reply->errorString());
            }

            reply->deleteLater();
            manager->deleteLater();
        });

        manager->post(request, doc.toJson());
        ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
        ui->spinBox->setValue(1);  // Réinitialise la valeur de QUANTITE à 0
        ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)

}



void equip::on_pushButton_3_clicked()  //edit
{
    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();

    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->textEdit->toPlainText();
    QDate DATE_ACHAT=ui->dd->date();
    int QUANTITE = ui->spinBox->value();
    QString ETAT= ui->comboBox->currentText();




    if (ID_EQUIPEMENT <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'équipement doit être un nombre positif !");
        return;
    }

    if (NOM_EQ.isEmpty() || TYPE_eq.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le type de l'équipement ne doivent pas être vides !");
        return;
    }
    // Vérification de la description (minimum 10 caractères)
    if (DESCRIPTION.isEmpty() ) {
        QMessageBox::warning(this, "Erreur", "La description ne doivent pas être vides !");
        return;
    }

    // Vérification de la quantité
    if (QUANTITE < 1) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre positif !");
        return;
    }

    // Vérification de la date d'achat (ne peut pas être dans le futur)
    if (DATE_ACHAT > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date d'achat ne peut pas être dans le futur !");
        return;
    }

    // Vérification de l'état (doit être sélectionné)
    if (ETAT.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un état pour l'équipement !");
        return;
    }




    equipement eq ( ID_EQUIPEMENT, NOM_EQ, TYPE_eq, DESCRIPTION, QUANTITE, ETAT ,DATE_ACHAT);
    bool test=eq.modifierEQ();
    if(test){
        ui->tableView->setModel(equ.affichierEQ());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifie effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr(" modifie non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    ui->lineEdit->clear();   // Réinitialise le champ pour l'ID_EQUIPEMENT
    ui->lineEdit_2->clear();  // Réinitialise le champ pour le NOM_EQ
    ui->lineEdit_4->clear();  // Réinitialise le champ pour le TYPE_eq
    ui->textEdit->clear();  // Réinitialise le champ pour la DESCRIPTION
    ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
    ui->spinBox->setValue(0);  // Réinitialise la valeur de QUANTITE à 0
    ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)





}



void equip::on_pushButton_2_clicked() //delete
{
    int id =ui->supprimer->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return;
    }
    if (!equ.idExiste(id)) {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas !");
        ui->supprimer->clear();
        return;

    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer cet équipement ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return; // Annuler la suppression si l'utilisateur a choisi "Non"
    }
    bool  test =equ.supprimerEQ(id);
    if(test)
    {

      ui->tableView->setModel(equ.affichierEQ());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else

    {QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("suppression non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

   ui->supprimer->clear();


}






equip::~equip()
{
    delete ui;
}








void equip::on_tableView_clicked(const QModelIndex &index)
{
      int row = index.row(); // Récupérer la ligne sélectionnée

        // Récupérer les données de la ligne sélectionnée
        int id = ui->tableView->model()->index(row, 0).data().toInt();
        QString nom = ui->tableView->model()->index(row, 1).data().toString();

        QString type = ui->tableView->model()->index(row, 2).data().toString();
        QString description = ui->tableView->model()->index(row, 3).data().toString();
        int quantite = ui->tableView->model()->index(row, 4).data().toInt();
        QString etat = ui->tableView->model()->index(row, 5).data().toString();
        QDate date_achat = ui->tableView->model()->index(row, 6).data().toDate();

        // Remplir les champs avec les données sélectionnées
        ui->lineEdit->setText(QString::number(id));
        ui->lineEdit_2->setText(nom);

        ui->lineEdit_4->setText(type);
        ui->textEdit->setText(description);
        ui->spinBox->setValue(quantite);
        ui->comboBox->setCurrentText(etat);
        ui->dd->setDate(date_achat);



}





void equip::on_pushButton_5_clicked()
{
    ui->lineEdit->clear();   // Réinitialise le champ pour l'ID_EQUIPEMENT
    ui->lineEdit_2->clear();  // Réinitialise le champ pour le NOM_EQ
    ui->lineEdit_4->clear();  // Réinitialise le champ pour le TYPE_eq
    ui->textEdit->clear();  // Réinitialise le champ pour la DESCRIPTION
    ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
    ui->spinBox->setValue(0);  // Réinitialise la valeur de QUANTITE à 0
    ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)


}



void equip::on_trier_activated(int index)
{
    QString critere = ui->trier->currentText();  // comboBoxTri est ton QComboBox
    ui->tableView->setModel(equ.trier(critere));

}

void equip::on_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");

    if (fileName.isEmpty())
        return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    printer.setPageSize(QPageSize(QSizeF(280, 396), QPageSize::Millimeter));




    QString html;



    html += "<div style='display: flex; justify-content: space-between; align-items: center; width: 100%; font-family: Arial;'>";

    // Gauche
    html += "<div style='text-align: left; font-size: 10pt;'>";
    html += "Labsync<br>";
    html += "Centre de Vaccination <br>";
    html += "et de Recherche Biologique<br>";
    html += "</div>";

    // Centre - Logo
    html += "<div style='text-align: center;'>";
    html += "<img src='c:/Users/Sahar/Bureau/project/interfce/logo9.png' width='80'/>";
    html += "</div>";

    // Droite - Date et Heure
    html += "<div style='text-align: right; font-size: 10pt;'>";
    html += "Date : " + QDate::currentDate().toString("dd/MM/yyyy") + "<br>";
    html += "Heure : " + QTime::currentTime().toString("hh:mm:ss");
    html += "</div>";

    html += "</div>";  // Fin de la ligne

    html += "<div style='text-align:center; margin-top:15px;'>";
    html += "<h2 style='font-size:14pt; color:#1E90FF;'>Liste des équipements</h2>";
    html += "</div>";


    // Tableau
    html += "<table border='1' cellspacing='0' cellpadding='4' width='100%'>";
    html += "<thead><tr style='background-color:#d0d0d0;'>";

    for (int col = 0; col < ui->tableView->model()->columnCount(); ++col)
        html += "<th style='font-size:11pt; color:#333;'>" + ui->tableView->model()->headerData(col, Qt::Horizontal).toString() + "</th>";

    html += "</tr></thead><tbody>";

    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        html += (row % 2 == 0) ? "<tr style='background-color:#f9f9f9;'>" : "<tr>";
        for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
            QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, col)).toString();
            html += "<td style='font-size:10pt; color:#333;'>" + data + "</td>";
        }
        html += "</tr>";
    }

    html += "</tbody></table>";

    int totalEquipements = ui->tableView->model()->rowCount();
    html += "<p align='right' style='font-size:12pt; font-weight: bold; color:#333;'>Nombre total d'équipements : " + QString::number(totalEquipements) + "</p>";

    // Signature
    html += "<div style='margin-top: 40px; text-align: right; font-size:11pt; color:#555;'>";
    html += "Signature du Responsable des Equipements";
    html += "</div>";

    // Footer
    html += "<div style='width:100%; text-align:center; font-size:9pt; color:#777; margin-top:80px;'>";
    html += "2025 © Tous droits sont réservés.";
    html += "</div>";


    html += "</div>";

    QTextDocument *docText = new QTextDocument();
    docText->setHtml(html);
    docText->setPageSize(printer.pageRect(QPrinter::Point).size());
    docText->print(&printer);

    QMessageBox::information(this, "PDF Exporté", "Liste exportée avec succès sous forme de PDF !");
}





void equip::on_pdf_2_clicked()
{
    statistique statsDialog;
    statsDialog.exec();

}






void equip::on_historique_clicked()
{
    historique histDialog(this);

    histDialog.exec();
}



void equip::on_rechercher_clicked()
{
    if (ui->recherche->text().isEmpty()) {
        QMessageBox::warning(this, "erreur", "rechercher d un equipement ne doivent pas être vides .");
        ui->tableView->setModel(equ.affichierEQ());
    } else {
        // Si le champ de recherche contient du texte, rechercher avec ce texte
        QSqlQueryModel *model = equ.Rechercher(ui->recherche->text());

        // Vérifier si le modèle est vide (c'est-à-dire aucune correspondance)
        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucun résultat", "Aucun résultat trouvé pour votre recherche.");
            ui->tableView->setModel(equ.affichierEQ());
        }


        ui->tableView->setModel(model);
    }
}


void equip::on_actuliser_clicked()
{
    ui->tableView->setModel(equ.affichierEQ());
    ui->tableView->setWordWrap(true);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->resizeRowsToContents();
    ui->tableView->setItemDelegateForColumn(5, new EtatDelegate(ui->tableView));
    ui->tableView->resizeRowsToContents();
}








void equip::on_btnpatient_clicked()
{
    patie *p=new patie();
    p->show();
    this->hide();
}





void equip::on_btnformation_clicked()
{

    forma *f= new forma();
    f->show();
    this->hide();


}


void equip::on_btnemploye_clicked()
{
    user *u=new user();
    u->show();
    this->hide();
}


void equip::on_btnvaccins_clicked()
{
    MainWindow *v=new MainWindow();
    v->show();
    this->hide();



}


void equip::on_btnrecherche_clicked()
{
    projet *r=new projet();
    r->show();
    this->hide();
}


void equip::on_logout_clicked()
{
    login *l=new login();
    l->show();
    this->hide();
}


