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
#include "imagedelegate.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

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
    ui->recherche->setStyleSheet(
        "QLineEdit {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"

        "   color: black;"
        "}"
        "QLineEdit:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
           /* Lighter background on focus */
        "}"
        );
    ui->supprimer->setStyleSheet(
        "QLineEdit {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"

        "   color: black;"
        "}"
        "QLineEdit:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
        /* Lighter background on focus */
        "}"
        );

    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"
         "   background-color: #17A2B8;"
        "   color: black;"
        "}"
        "QPushButton:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
           "   background-color: #17A2B8;"/* Lighter background on focus */
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"
        "   background-color: #D3D3D3;"
        "   color: black;"
        "}"
        "QPushButton:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
           "   background-color: #D3D3D3;"/* Lighter background on focus */
        "}"
        );
    ui->pushButton_4->setStyleSheet(
        "QPushButton {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"
     "   background-color:#D3D3D3 ;"
        "   color: black;"
        "}"
        "QPushButton:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
          "   background-color:#D3D3D3 ;" /* Lighter background on focus */
        "}"
        );
    ui->comboBox_3->setStyleSheet(
        "QComboBox {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"

        "   color: black;"
        "}"
        "QComboBox:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
          /* Lighter background on focus */
        "}"
        );
    ui->trier->setStyleSheet(
        "QComboBox {"
        "   border: 0.5px solid black;"
        "   border-radius: 15px;"
        "   padding: px;"

        "   color: black;"
        "}"
        "QComboBox:focus {"
        "   border: 1px solid #4A90E2;"  /* Change border color when focused */
          /* Lighter background on focus */
        "}"
        );


    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);




    // Connexions pour gérer les clics des boutons
    ui->pushButton_4->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/add.png"));
        ui->pushButton_4->setIconSize(QSize(108, 38));
    ui->pushButton_3->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/edit.png"));
        ui->pushButton_3->setIconSize(QSize(100, 38));
    ui->pushButton_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/delete.png"));
        ui->pushButton_2->setIconSize(QSize(108, 28));
    ui->comboBox->addItem("en panne");
    ui->comboBox->setItemData(0, QColor(Qt::red), Qt::ForegroundRole);

    ui->comboBox->addItem("en service");
    ui->comboBox->setItemData(1, QColor(Qt::blue), Qt::ForegroundRole);

    ui->comboBox->addItem("disponible");
    ui->comboBox->setItemData(2, QColor(Qt::green), Qt::ForegroundRole);

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

    ui->pdf->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interface/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf_2->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interface/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->recherche->setPlaceholderText("rechercher un equipement par ... ");
    ui->comboBox_3->addItem("nom");
    ui->comboBox_3->addItem("type");
    ui->comboBox_3->addItem("etat");

    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItem("trier par");
    ui->trier->addItem("nom");
    ui->trier->addItem("type");
    ui->trier->addItem("etat");
    ui->trier->addItem("quantité");



}

void MainWindow::on_pushButton_4_clicked()  //ajouter
{
    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();
    QString IMAGE=ui->lineEdit_3->text();
    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->lineEdit_5->text();
    QDate DATE_ACHAT=ui->dateEdit->date();
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

    equipement eq ( ID_EQUIPEMENT, NOM_EQ, IMAGE, TYPE_eq, DESCRIPTION, QUANTITE, ETAT ,DATE_ACHAT);
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

}





/*QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner une image", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (!filePath.isEmpty()) {
        ui->lineEdit_3->setText(filePath);
    }*/

void MainWindow::on_pushButton_3_clicked()  //edit
{
    int ID_EQUIPEMENT = ui->lineEdit->text().toInt();
    QString NOM_EQ=ui->lineEdit_2->text();
    QString IMAGE=ui->lineEdit_3->text();
    QString TYPE_eq = ui->lineEdit_4->text();
    QString DESCRIPTION=ui->lineEdit_5->text();
    QDate DATE_ACHAT=ui->dateEdit->date();
    int QUANTITE = ui->spinBox->value();
    QString ETAT= ui->comboBox->currentText();

    equipement eq ( ID_EQUIPEMENT, NOM_EQ, IMAGE, TYPE_eq, DESCRIPTION, QUANTITE, ETAT ,DATE_ACHAT);
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




}
void MainWindow::on_pushButton_clicked()  //read
{

    ui->tableView->setModel(equ.affichierEQ());

}


void MainWindow::on_pushButton_2_clicked() //delete
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

    {QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("suppression non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }




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
        QString image = ui->tableView->model()->index(row, 2).data().toString();
        QString type = ui->tableView->model()->index(row, 3).data().toString();
        QString description = ui->tableView->model()->index(row, 4).data().toString();
        int quantite = ui->tableView->model()->index(row, 5).data().toInt();
        QString etat = ui->tableView->model()->index(row, 6).data().toString();
        QDate date_achat = ui->tableView->model()->index(row, 7).data().toDate();

        // Remplir les champs avec les données sélectionnées
        ui->lineEdit->setText(QString::number(id));
        ui->lineEdit_2->setText(nom);
        ui->lineEdit_3->setText(image);
        ui->lineEdit_4->setText(type);
        ui->lineEdit_5->setText(description);
        ui->spinBox->setValue(quantite);
        ui->comboBox->setCurrentText(etat);
        ui->dateEdit->setDate(date_achat);


}


void MainWindow::on_pushButton_5_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!filePath.isEmpty()) {
        ui->lineEdit_3->setText(filePath);
    }

}

