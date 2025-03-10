#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Initialisation de l'UI

    // Vérification que le widget central existe avant d'appliquer une palette
    if (ui->centralwidget) {
        QPalette palette;
        QPixmap pixmap("C:/Users/hp/Desktop/2A17/qt/interfce/back55.jpg");
        if (!pixmap.isNull()) {
            palette.setBrush(QPalette::Window, pixmap);
            ui->centralwidget->setPalette(palette);
            ui->centralwidget->setAutoFillBackground(true);
        } else {
            qDebug() << "Erreur: Impossible de charger l'image de fond.";
        }
    }

    // Style commun pour les boutons
    QString commonButtonStyle =
        "QPushButton {"
        "   border: 0.5px solid black;"
        "   border-radius: 5px;"
        "   padding: 10px;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover, QPushButton:pressed {"
        "   background-color: #D3D3D3;"
        "   border: 0.5px solid black;"
        "}";

    // Application des styles à un QGroupBox
    ui->groupBox->setStyleSheet(
        "QGroupBox {"
        "background-color: Light Cyan;"
        "border: 0.5px solid black;"
        "border-radius: 5px;"
        "padding: 10px;"
        "}");

    // Configuration des boutons avec icônes
    struct ButtonConfig {
        QPushButton *button;
        QString iconPath;
        QSize iconSize;
    };

    ButtonConfig buttons[] = {
        {ui->logo, "C:/Users/hp/Desktop/2A17/qt/interfce/logo9.png", QSize(150, 150)},
        {ui->btnemploye, "C:/Users/hp/Desktop/2A17/qt/interfce/employe.png", QSize(50, 50)},
        {ui->btnpatient, "C:/Users/hp/Desktop/2A17/qt/interfce/patient.png", QSize(50, 50)},
        {ui->btnvaccins, "C:/Users/hp/Desktop/2A17/qt/interfce/vaccins.png", QSize(50, 50)},
        {ui->btnequipement, "C:/Users/hp/Desktop/2A17/qt/interfce/equipement.png", QSize(50, 50)},
        {ui->btnformation, "C:/Users/hp/Desktop/2A17/qt/interfce/formation.png", QSize(50, 50)},
        {ui->btnrecherche, "C:/Users/hp/Desktop/2A17/qt/interfce/recherche.png", QSize(50, 50)},
        {ui->logout, "C:/Users/hp/Desktop/2A17/qt/interfce/logout1.png", QSize(50, 50)}
    };

    for (const auto &btnConfig : buttons) {
        if (btnConfig.button) {
            QIcon icon(btnConfig.iconPath);
            if (!icon.isNull()) {
                btnConfig.button->setIcon(icon);
                btnConfig.button->setIconSize(btnConfig.iconSize);
                btnConfig.button->setStyleSheet(commonButtonStyle);
            } else {
                qDebug() << "Erreur: Impossible de charger l'icône:" << btnConfig.iconPath;
            }
        }
    }

    // Configuration des boutons transparents
    struct TransparentButtonConfig {
        QPushButton *button;
        QString iconPath;
        QSize iconSize;
    };

    TransparentButtonConfig transparentButtons[] = {
        {ui->rech, "C:/Users/hp/Desktop/2A17/qt/interfce/reche.png", QSize(91, 31)},
        {ui->pdf, "C:/Users/hp/Desktop/2A17/qt/interfce/pdf2.png", QSize(91, 51)},
        {ui->pdf_2, "C:/Users/hp/Desktop/2A17/qt/interfce/sta.png", QSize(91, 51)}
    };

    for (const auto &btnConfig : transparentButtons) {
        if (btnConfig.button) {
            QIcon icon(btnConfig.iconPath);
            if (!icon.isNull()) {
                btnConfig.button->setIcon(icon);
                btnConfig.button->setIconSize(btnConfig.iconSize);
                btnConfig.button->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
            } else {
                qDebug() << "Erreur: Impossible de charger l'icône:" << btnConfig.iconPath;
            }
        }
    }

    // Configuration des placeholders
    ui->recherche->setPlaceholderText("Rechercher un équipement par...");
    ui->comboBox_3->addItems({"nom", "type", "état", "localisation"});
    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItems({"Trier par", "nom", "type", "état", "quantité"});
}

MainWindow::~MainWindow()
{
    delete ui;
}
