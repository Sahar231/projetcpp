#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "equipement.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileDialog>

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
    QString commonButtonStyle =
        "QPushButton {"
        "   border: 0.5px solid black;"
        "   border-radius: 5px;"
        "   padding: 10px;"
        "   font-weight: bold;"             // Texte en gras
        "   font-size: 14px;"

        "}"
        "QPushButton:hover, QPushButton:pressed {"
        "   background-color: #D3D3D3;"
        "   border: 0.5px solid black;"
        "}";
   /* ui->groupBox->setStyleSheet(
    "QGroupBox {"

    "border: 0.5px solid black;"
    "border-radius: 5px;"
    "padding: 10px;"
    "}"
    "QLineEdit { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
    "QspinBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
    "QComboBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"

        "}");*/




    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);
    ui->comboBox->addItem("en panne ");
    ui->comboBox->addItem("en service");
    ui->comboBox->addItem("disponble");


    ui->btnemploye->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);
    ui->btnpatient->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);
    ui->btnvaccins->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);
    ui->btnequipement->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);
    ui->btnformation->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);
    ui->btnrecherche->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);
    ui->logout->setStyleSheet(commonButtonStyle);
    ui->rech->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/reche.png"));
    ui->rech->setIconSize(QSize(91, 31));
    ui->rech->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->recherche->setPlaceholderText("rechercher un equipement par ... ");
    ui->comboBox_3->addItem("nom");
    ui->comboBox_3->addItem("type");
    ui->comboBox_3->addItem("etat");
    ui->comboBox_3->addItem("localisation");
    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItem("trier par");
    ui->trier->addItem("nom");
    ui->trier->addItem("type");
    ui->trier->addItem("etat");
    ui->trier->addItem("quantité");



}
void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(equ.affichierEQ());
}
void MainWindow::on_pushButton_4_clicked()
{
    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();
    QString IMAGE=ui->lineEdit_3->text();
    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->lineEdit_5->text();

    int QUANTITE = ui->spinBox->value();
    QString ETAT= ui->comboBox->currentText();

    if (ID_EQUIPEMENT <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'équipement doit être un nombre positif !");
        return;
    }


    if (NOM_EQ.isEmpty() || TYPE_eq.isEmpty() || DESCRIPTION.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
        return;
    }


    if (QUANTITE < 1) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être positive !");
        return;
    }

    equipement eq ( ID_EQUIPEMENT, NOM_EQ, IMAGE, TYPE_eq, DESCRIPTION, QUANTITE, ETAT);
    bool test=eq.ajouterEQ();
    if(test){
       ui->tableView->setModel(equ.affichierEQ());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("ajout non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_2_clicked()
{
    int id =ui->supprimer->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
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

    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("suppression non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


}




MainWindow::~MainWindow()
{
    delete ui;
}















void MainWindow::on_radioButton_clicked()
{
    ui->groupBox->setTitle("Ajouter un equipement");
    ui->pushButton_4->setText("Ajouter");

}


void MainWindow::on_radioButton_2_clicked()
{
    ui->groupBox->setTitle("Modifier un equipement");
    ui->pushButton_4->setText("Modifier");
}


void MainWindow::on_pushButton_3_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner une image", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (!filePath.isEmpty()) {
        ui->lineEdit_3->setText(filePath);
}
}

