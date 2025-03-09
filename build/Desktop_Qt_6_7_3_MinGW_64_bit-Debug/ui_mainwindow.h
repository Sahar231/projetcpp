/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
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
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_3;
    QDateEdit *dateEdit;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton_5;
    QTableView *tableView;
    QComboBox *trier;
    QLineEdit *recherche;
    QLineEdit *supprimer;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QComboBox *comboBox_3;
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
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1404, 770);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(190, 10, 231, 681));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 60, 113, 26));
        lineEdit->setMinimumSize(QSize(113, 0));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 20, 141, 41));
        label->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 120, 113, 26));
        lineEdit_2->setMinimumSize(QSize(113, 0));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 440, 63, 20));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(30, 290, 113, 26));
        lineEdit_4->setMinimumSize(QSize(113, 0));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(30, 360, 113, 26));
        lineEdit_5->setMinimumSize(QSize(113, 0));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 500, 111, 31));
        comboBox->setMinimumSize(QSize(111, 0));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(2, 628, 111, 41));
        pushButton_4->setMinimumSize(QSize(93, 0));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 90, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 430, 111, 26));
        spinBox->setMinimumSize(QSize(111, 0));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 190, 141, 61));
        lineEdit_3->setMinimumSize(QSize(141, 0));
        lineEdit_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/imageeq.jpg);"));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(20, 570, 110, 26));
        dateEdit->setMinimumSize(QSize(110, 0));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(122, 628, 101, 41));
        pushButton_3->setMinimumSize(QSize(93, 0));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 160, 161, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 270, 81, 20));
        label_11->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 320, 151, 41));
        label_12->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(0, 400, 81, 20));
        label_13->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 470, 81, 20));
        label_14->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 540, 101, 20));
        label_15->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Comic Sans MS\";"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(90, 260, 93, 29));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(500, 300, 851, 411));
        tableView->setMinimumSize(QSize(851, 411));
        tableView->setMaximumSize(QSize(851, 16777215));
        tableView->setGridStyle(Qt::PenStyle::SolidLine);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        trier = new QComboBox(centralwidget);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(760, 260, 131, 31));
        recherche = new QLineEdit(centralwidget);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(650, 210, 281, 31));
        supprimer = new QLineEdit(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(960, 260, 141, 31));
        supprimer->setMinimumSize(QSize(141, 0));
        supprimer->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/imageeq.jpg);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1110, 260, 101, 31));
        pushButton_2->setMinimumSize(QSize(101, 0));
        pushButton_2->setMaximumSize(QSize(101, 16777215));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(610, -10, 451, 111));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 italic 18pt \"Comic Sans MS\";"));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(950, 210, 111, 31));
        btnemploye = new QPushButton(centralwidget);
        btnemploye->setObjectName("btnemploye");
        btnemploye->setGeometry(QRect(0, 100, 161, 81));
        btnemploye->setMinimumSize(QSize(161, 0));
        btnpatient = new QPushButton(centralwidget);
        btnpatient->setObjectName("btnpatient");
        btnpatient->setGeometry(QRect(0, 190, 161, 81));
        btnpatient->setMinimumSize(QSize(161, 0));
        btnvaccins = new QPushButton(centralwidget);
        btnvaccins->setObjectName("btnvaccins");
        btnvaccins->setGeometry(QRect(0, 280, 161, 81));
        btnequipement = new QPushButton(centralwidget);
        btnequipement->setObjectName("btnequipement");
        btnequipement->setGeometry(QRect(0, 370, 161, 81));
        btnformation = new QPushButton(centralwidget);
        btnformation->setObjectName("btnformation");
        btnformation->setGeometry(QRect(0, 460, 161, 81));
        btnrecherche = new QPushButton(centralwidget);
        btnrecherche->setObjectName("btnrecherche");
        btnrecherche->setGeometry(QRect(0, 550, 161, 81));
        logout = new QPushButton(centralwidget);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(0, 640, 161, 61));
        logo = new QPushButton(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 161, 91));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(790, 110, 131, 51));
        pdf->setStyleSheet(QString::fromUtf8(""));
        pdf_2 = new QPushButton(centralwidget);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(650, 110, 111, 51));
        pdf_2->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 260, 211, 31));
        pushButton->setMaximumSize(QSize(211, 31));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        tableView->raise();
        trier->raise();
        recherche->raise();
        supprimer->raise();
        label_10->raise();
        pushButton_2->raise();
        comboBox_3->raise();
        btnemploye->raise();
        btnpatient->raise();
        btnvaccins->raise();
        btnequipement->raise();
        btnformation->raise();
        btnrecherche->raise();
        logout->raise();
        logo->raise();
        pdf->raise();
        pdf_2->raise();
        pushButton->raise();
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Id_equipement</span></p></body></html>", nullptr));
        label_7->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">nom</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">upload image</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Type</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">description</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">quantite</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Etat</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Date_achat</span></p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Liste d'equipement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
