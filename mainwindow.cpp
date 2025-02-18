#include "mainwindow.h"
#include "ui_mainwindow.h"

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



    ui->groupBox->setStyleSheet(
        "QGroupBox {"
        "background-color: Light Cyan;"
        "border: 0.5px solid black;"
        "border-radius: 5px;"
        "padding: 10px;"
        "}"
        "QLineEdit { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "QspinBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "QComboBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"

        "}");


    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);


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


MainWindow::~MainWindow()
{
    delete ui;
}







