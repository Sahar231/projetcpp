#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include <QString>
#include "equipement.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileDialog>
#include "EtatDelegate.h"
#include "historique.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include "statistique.h"


#include <QMessageBox>
#include <QBuffer>
#include <QPainter>
#include <QTextDocument>
#include <QProcess>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette palette;
    QPixmap pixmap("c:/Users/Sahar/Bureau/project/interfce/back55.jpg");
    palette.setBrush(QPalette::Window,  pixmap);
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);

    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));

    ui->pushButton_4->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/add.png"));
        ui->pushButton_4->setIconSize(QSize(108, 38));
    ui->pushButton_3->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/edit.png"));
        ui->pushButton_3->setIconSize(QSize(100, 38));
    ui->pushButton_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/delete.png"));
        ui->pushButton_2->setIconSize(QSize(138, 29));
    ui->comboBox->addItem("en panne");
    ui->comboBox->setItemData(0, QColor(Qt::red), Qt::ForegroundRole);

    ui->comboBox->addItem("en service");
    ui->comboBox->setItemData(1, QColor(Qt::blue), Qt::ForegroundRole);

    ui->comboBox->addItem("disponible");
    ui->comboBox->setItemData(2, QColor(Qt::green), Qt::ForegroundRole);

    ui->btnemploye->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));

    ui->btnpatient->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));

    ui->btnvaccins->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));

    ui->btnequipement->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));

    ui->btnformation->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));

    ui->btnrecherche->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));



    ui->pdf->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interface/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interface/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->recherche->setPlaceholderText("rechercher un equipement par ... ");


    ui->supprimer->setPlaceholderText("donner id a supprime");
    ui->trier->addItem("trier par");


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
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);




}

void MainWindow::on_pushButton_4_clicked()  //ajouter
{

    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();
    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->lineEdit_3->text();
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
    ui->lineEdit_3->clear();  // Réinitialise le champ pour la DESCRIPTION
    ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
    ui->spinBox->setValue(0);  // Réinitialise la valeur de QUANTITE à 0
    ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)

}


void MainWindow::on_autoFillButton_clicked()
{



        //C:/Users/Sahar/Bureau/project/interfce/ai auto fill/generation.py"
}









void MainWindow::on_pushButton_3_clicked()  //edit
{
    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();

    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->lineEdit_3->text();
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
    ui->lineEdit_3->clear();  // Réinitialise le champ pour la DESCRIPTION
    ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
    ui->spinBox->setValue(0);  // Réinitialise la valeur de QUANTITE à 0
    ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)





}



void MainWindow::on_pushButton_2_clicked() //delete
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







MainWindow::~MainWindow()
{
    delete ui;
}








void MainWindow::on_tableView_clicked(const QModelIndex &index)
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
        ui->lineEdit_3->setText(description);
        ui->spinBox->setValue(quantite);
        ui->comboBox->setCurrentText(etat);
        ui->dd->setDate(date_achat);


}





void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->clear();   // Réinitialise le champ pour l'ID_EQUIPEMENT
    ui->lineEdit_2->clear();  // Réinitialise le champ pour le NOM_EQ
    ui->lineEdit_4->clear();  // Réinitialise le champ pour le TYPE_eq
    ui->lineEdit_3->clear();  // Réinitialise le champ pour la DESCRIPTION
    ui->dd->setDate(QDate::currentDate()); // Réinitialise la date à la date actuelle (ou vous pouvez utiliser QDate())
    ui->spinBox->setValue(0);  // Réinitialise la valeur de QUANTITE à 0
    ui->comboBox->setCurrentIndex(0);  // Réinitialise l'index de la comboBox (premier élément sélectionné)


}





void MainWindow::on_recherche_2_clicked()
{
    if (ui->recherche->text().isEmpty()) {
        QMessageBox::warning(this, "erreur", "Aucun résultat trouvé pour votre recherche.");
        ui->tableView->setModel(equ.affichierEQ());
    } else {
        // Si le champ de recherche contient du texte, rechercher avec ce texte
        QSqlQueryModel *model = equ.Rechercher(ui->recherche->text());

        // Vérifier si le modèle est vide (c'est-à-dire aucune correspondance)
        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucun résultat", "Aucun résultat trouvé pour votre recherche.");
        }


        ui->tableView->setModel(model);
    }

}


void MainWindow::on_trier_activated(int index)
{
    QString critere = ui->trier->currentText();  // comboBoxTri est ton QComboBox
    ui->tableView->setModel(equ.trier(critere));

}

void MainWindow::on_pdf_clicked()
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
    printer.setPageSize(QPageSize(QSizeF(300, 400), QPageSize::Millimeter)); // الحجم الجديد

    QString dateTime = QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString time = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

    QString html;
    html += "<div style='width:100%; font-family:Arial;'>";

    // Logo, titre, date et heure
    html += "<div style='text-align:center;'>";
    html += "<img src='c:/Users/Sahar/Bureau/project/interfce/logo9.png' width='120'/><br>";
    html += "<span style='font-size:11pt; color:#333;'>Labsync - Centre de Vaccination et de Recherche Biologique</span><br>";
    html += "<span style='font-size:10pt; color:#777;'>Date : " + dateTime + " | Heure : " + time + "</span>";
    html += "</div>";

    html += "<hr style='height:2px;border:none;color:#333;background-color:#333;'/>";

    html += "<h2 align='center' style='font-size:16pt; font-weight: bold; color:#1E90FF;'>Liste des équipements</h2>";
    html += "<hr style='height:1px;border:none;color:#333;background-color:#ccc;'/>";

    // Tableau
    html += "<table border='1' cellspacing='0' cellpadding='4' width='100%'>";
    html += "<thead><tr style='background-color:#d0d0d0;'>";

    for (int col = 0; col < ui->tableView->model()->columnCount(); ++col)
        html += "<th style='font-size:11pt; color:#333;'>" + ui->tableView->model()->headerData(col, Qt::Horizontal).toString() + "</th>";

    html += "</tr></thead><tbody>";

    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
            QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, col)).toString();
            html += "<td style='font-size:10pt; color:#333;'>" + data + "</td>";
        }
        html += "</tr>";
    }

    html += "</tbody></table>";

    int totalEquipements = ui->tableView->model()->rowCount();
    html += "<p align='right' style='font-size:12pt; font-weight: bold; color:#333;'>Nombre total d'équipements : " + QString::number(totalEquipements) + "</p>";

    html += "<br><br><hr style='height:1px;border:none;color:#ccc;background-color:#ccc;'/>";
    html += "<div style='display: flex; justify-content: space-between;'>";
    html += "<p style='font-size:11pt; color:#555;'>Chef de Lab</p>";
    html += "<p style='font-size:11pt; color:#555;'>Signature du Responsable des Equipements – Page <span class='pageNumber'></span></p>";
    html += "</div>";

    // Footer simple
    html += "<br><hr style='height:2px;border:none;color:#333;background-color:#333;'/>";
    html += "<div style='text-align: center; font-size:10pt; color:#777;'>";
    html += "2025 © Tous les droits sont réservés.";
    html += "</div>";

    html += "</div>";

    QTextDocument *docText = new QTextDocument();
    docText->setHtml(html);
    docText->setPageSize(printer.pageRect(QPrinter::Point).size());
    docText->print(&printer);

    QMessageBox::information(this, "PDF Exporté", "Liste exportée avec succès sous forme de PDF !");
}


void MainWindow::on_pushButton_6_clicked()
{

        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en Excel", "", "*.csv");

        if (fileName.isEmpty())
            return;

        if (!fileName.endsWith(".csv"))
            fileName += ".csv";

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            // En-têtes
            QAbstractItemModel *model = ui->tableView->model();
            for (int col = 0; col < model->columnCount(); ++col) {
                stream << model->headerData(col, Qt::Horizontal).toString();
                if (col != model->columnCount() - 1)
                    stream << ";";
            }
            stream << "\n";

            // Lignes
            for (int row = 0; row < model->rowCount(); ++row) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    QString data = model->data(model->index(row, col)).toString();
                    stream << data;
                    if (col != model->columnCount() - 1)
                        stream << ";";
                }
                stream << "\n";
            }

            file.close();
            QMessageBox::information(this, "Export réussi", "La liste a été exportée vers Excel avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible d’ouvrir le fichier pour l’écriture.");
        }


}





void MainWindow::on_pushButton_7_clicked()
{
    historique histDialog(this);

    histDialog.exec();
}


void MainWindow::on_pdf_2_clicked()
{
    statistique statsDialog;
    statsDialog.exec();

}


void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(equ.affichierEQ());
    ui->tableView->setWordWrap(true);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
   ui->tableView->resizeRowsToContents();

    ui->tableView->setItemDelegateForColumn(5, new EtatDelegate(ui->tableView));



   ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    ui->tableView->setColumnWidth(0, 35);   // Colonne 1: ID
    ui->tableView->setColumnWidth(3, 30);
   ui->tableView->setColumnWidth(4, 80);    // Colonne 4: Quantité
    ui->tableView->setColumnWidth(5, 40);  // Colonne 6: Date achat



   ui->tableView->resizeRowsToContents();


      // Ajuste la largeur de la colonne image (ajuste selon tes besoins)


}


