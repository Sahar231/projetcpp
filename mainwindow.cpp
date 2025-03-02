#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include <QMessageBox>







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    QPalette palette;
    QPixmap pixmap("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/back55.jpg");
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




    ui->logo->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);



    ui->btnemploye->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);
    ui->btnpatient->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);
    ui->btnvaccins->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);
    ui->btnequipement->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);
    ui->btnformation->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);
    ui->btnrecherche->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);
    ui->logout->setStyleSheet(commonButtonStyle);
    ui->rech->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/reche.png"));
    ui->rech->setIconSize(QSize(91, 31));
    ui->rech->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->pdf_2->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/IINTERFACE/interface/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    ui->recherche->setPlaceholderText("Rechercher un Patient par ... ");
    ui->comboBox->addItem("Homme");
    ui->comboBox->addItem("Femme");
    ui->comboBox_2->addItem("A+");
    ui->comboBox_2->addItem("A-");
    ui->comboBox_2->addItem("B+");
    ui->comboBox_2->addItem("B-");
    ui->comboBox_2->addItem("O+");
    ui->comboBox_2->addItem("O-");
    ui->comboBox_2->addItem("AB+");
    ui->comboBox_2->addItem("AB-");
    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItem("trier par");
    ui->trier->addItem("nom");
    ui->trier->addItem("type");
    ui->trier->addItem("etat");
    ui->trier->addItem("quantité");



}



MainWindow::~MainWindow()
{
    delete ui;
}














