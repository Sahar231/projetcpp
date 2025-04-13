/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QSpinBox *spinBox;
    QDateEdit *dd;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QPushButton *autoFillButton;
    QTableView *tableView;
    QComboBox *trier;
    QLineEdit *recherche;
    QLineEdit *supprimer;
    QLabel *label_10;
    QPushButton *btnemploye;
    QPushButton *btnpatient;
    QPushButton *btnvaccins;
    QPushButton *btnequipement;
    QPushButton *btnformation;
    QPushButton *btnrecherche;
    QPushButton *logout;
    QPushButton *logo;
    QPushButton *pdf;
    QPushButton *pdf_2;
    QPushButton *pushButton_2;
    QPushButton *recherche_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1404, 770);
        MainWindow->setMinimumSize(QSize(1404, 0));
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(180, 30, 261, 701));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 80, 181, 26));
        lineEdit->setMinimumSize(QSize(113, 0));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 1.5px solid black; /* Black border */\n"
"    border-radius: 10px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 181, 41));
        label->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 140, 181, 31));
        lineEdit_2->setMinimumSize(QSize(113, 0));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 10px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
""));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 440, 63, 20));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(30, 220, 181, 31));
        lineEdit_4->setMinimumSize(QSize(113, 0));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 10px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
""));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 480, 171, 31));
        comboBox->setMinimumSize(QSize(111, 0));
        comboBox->setStyleSheet(QString::fromUtf8(""));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 650, 93, 35));
        pushButton_4->setMinimumSize(QSize(93, 0));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D3D3D3;  /* Gris moyen \303\251l\303\251gant */\n"
"    color: black;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #616161;  /* Gris fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #424242;  /* Gris encore plus fonc\303\251 quand press\303\251 */\n"
"    transform: scale(0.98);  /* Effet d\342\200\231appui visuel */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #bdbdbd;  /* Gris clair pour d\303\251sactiv\303\251 */\n"
"    color: #eeeeee;\n"
"}\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 420, 171, 26));
        spinBox->setMinimumSize(QSize(111, 0));
        dd = new QDateEdit(groupBox);
        dd->setObjectName("dd");
        dd->setGeometry(QRect(30, 560, 191, 26));
        dd->setMinimumSize(QSize(110, 0));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 180, 81, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 260, 151, 41));
        label_12->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 380, 121, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 450, 81, 31));
        label_14->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 520, 161, 31));
        label_15->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 650, 101, 35));
        pushButton_3->setMinimumSize(QSize(93, 0));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D3D3D3;  /* Gris moyen \303\251l\303\251gant */\n"
"    color: black;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 8px 16px;\n"
"   \n"
"  font-size: 14px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #616161;  /* Gris fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #424242;  /* Gris encore plus fonc\303\251 quand press\303\251 */\n"
"    transform: scale(0.98);  /* Effet d\342\200\231appui visuel */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #bdbdbd;  /* Gris clair pour d\303\251sactiv\303\251 */\n"
"    color: #eeeeee;\n"
"}\n"
""));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(150, 20, 111, 31));
        pushButton_5->setMinimumSize(QSize(93, 0));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #235284;  /* Gris moyen \303\251l\303\251gant */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #616161;  /* Gris fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #424242;  /* Gris encore plus fonc\303\251 quand press\303\251 */\n"
"    transform: scale(0.98);  /* Effet d\342\200\231appui visuel */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #bdbdbd;  /* Gris clair pour d\303\251sactiv\303\251 */\n"
"    color: #eeeeee;\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(30, 300, 191, 71));
        autoFillButton = new QPushButton(groupBox);
        autoFillButton->setObjectName("autoFillButton");
        autoFillButton->setGeometry(QRect(60, 610, 93, 29));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(490, 290, 851, 431));
        tableView->setMinimumSize(QSize(851, 411));
        tableView->setMaximumSize(QSize(851, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"        border: none;\n"
"        gridline-color: black;\n"
"\n"
"      \n"
"    }\n"
"    QTableView::item { \n"
"        padding: 15px; \n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: white;\n"
"        padding: 10px;\n"
"        font-size: 11px;\n"
"        border: none;\n"
"       gridline-color: black;\n"
"    }\n"
"QTableView::item:hover {\n"
"      background-color: #d3e0ea;\n"
"     color: black;\"\n"
"    }\n"
"\n"
"    "));
        tableView->setGridStyle(Qt::PenStyle::SolidLine);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        trier = new QComboBox(centralwidget);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(710, 250, 131, 31));
        recherche = new QLineEdit(centralwidget);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(640, 190, 281, 31));
        recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"           border: 0.5px solid black;\n"
"         border-radius: 15px;\n"
"        padding: px;\n"
"\n"
"         color: black;\n"
"        }\n"
" QLineEdit:focus {\n"
"           border: 1px solid #4A90E2;\"  \n"
"         }\n"
"   "));
        supprimer = new QLineEdit(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(900, 250, 141, 31));
        supprimer->setMinimumSize(QSize(141, 0));
        supprimer->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #4A90E2; /* Change border color when focused */\n"
"    background-color: #f0f8ff; /* Optional: lighter background on focus */\n"
"}\n"
""));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(610, -10, 451, 111));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 italic 18pt \"Comic Sans MS\";"));
        btnemploye = new QPushButton(centralwidget);
        btnemploye->setObjectName("btnemploye");
        btnemploye->setGeometry(QRect(0, 100, 161, 81));
        btnemploye->setMinimumSize(QSize(161, 0));
        btnemploye->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        btnpatient = new QPushButton(centralwidget);
        btnpatient->setObjectName("btnpatient");
        btnpatient->setGeometry(QRect(0, 190, 161, 81));
        btnpatient->setMinimumSize(QSize(161, 0));
        btnpatient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        btnvaccins = new QPushButton(centralwidget);
        btnvaccins->setObjectName("btnvaccins");
        btnvaccins->setGeometry(QRect(0, 280, 161, 81));
        btnvaccins->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        btnequipement = new QPushButton(centralwidget);
        btnequipement->setObjectName("btnequipement");
        btnequipement->setGeometry(QRect(0, 370, 161, 81));
        btnequipement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        btnformation = new QPushButton(centralwidget);
        btnformation->setObjectName("btnformation");
        btnformation->setGeometry(QRect(0, 460, 161, 81));
        btnformation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        btnrecherche = new QPushButton(centralwidget);
        btnrecherche->setObjectName("btnrecherche");
        btnrecherche->setGeometry(QRect(0, 550, 161, 81));
        btnrecherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        logout = new QPushButton(centralwidget);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(0, 640, 161, 61));
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
"\n"
""));
        logo = new QPushButton(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 161, 91));
        logo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 0.5px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed {\n"
"    background-color: #D3D3D3;\n"
"    border: 0.5px solid black;\n"
"}\n"
""));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(790, 110, 131, 51));
        pdf->setStyleSheet(QString::fromUtf8(""));
        pdf_2 = new QPushButton(centralwidget);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(650, 110, 111, 51));
        pdf_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1070, 250, 141, 29));
        pushButton_2->setMinimumSize(QSize(0, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#D3D3D3; /* Gris moyen \303\251l\303\251gant */\n"
"    color: black;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    transition: background-color 0.3s, transform 0.1s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #616161;  /* Gris fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #424242;  /* Gris encore plus fonc\303\251 quand press\303\251 */\n"
"    transform: scale(0.98);  /* Effet d\342\200\231appui visuel */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #bdbdbd;  /* Gris clair pour d\303\251sactiv\303\251 */\n"
"    color: #eeeeee;\n"
"}\n"
""));
        recherche_2 = new QPushButton(centralwidget);
        recherche_2->setObjectName("recherche_2");
        recherche_2->setGeometry(QRect(940, 190, 111, 29));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(990, 120, 93, 29));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(1170, 130, 93, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 250, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1404, 26));
        menubar->setTabletTracking(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter /Modifier ", nullptr));
        lineEdit->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Id   equipement</span></p></body></html>", nullptr));
        lineEdit_2->setText(QString());
        label_7->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">nom</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Type</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">description</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">quantite</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Etat</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Date   achat</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "effacer", nullptr));
        autoFillButton->setText(QCoreApplication::translate("MainWindow", "ai auto fill", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt; color:#ffffff;\">Equipement</span></p></body></html>", nullptr));
#if QT_CONFIG(whatsthis)
        btnemploye->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">employe</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnemploye->setText(QCoreApplication::translate("MainWindow", "Employe", nullptr));
        btnpatient->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        btnvaccins->setText(QCoreApplication::translate("MainWindow", "Vaccins", nullptr));
        btnequipement->setText(QCoreApplication::translate("MainWindow", "Equipement", nullptr));
        btnformation->setText(QCoreApplication::translate("MainWindow", "Formation", nullptr));
        btnrecherche->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        logout->setText(QString());
        logo->setText(QString());
        pdf->setText(QString());
        pdf_2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        recherche_2->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "execl", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "historique", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
