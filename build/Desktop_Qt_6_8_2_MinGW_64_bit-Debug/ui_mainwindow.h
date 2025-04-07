/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *comboBox_typeVaccin_2;
    QLineEdit *lineEdit_idVaccin;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_nomVaccin;
    QLabel *label_3;
    QLineEdit *lineEdit_effetsSecondaires;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *lineEdit_composition;
    QLabel *label_5;
    QComboBox *comboBox_typeVaccin;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLabel *label_9;
    QDateEdit *dateEdit_dateCreation;
    QLabel *label_11;
    QLineEdit *lineEdit_quantite;
    QDateEdit *dateEdit_datePeremption;
    QLabel *label_12;
    QLineEdit *lineEdit_idRech;
    QLabel *label_13;
    QTableView *tableView;
    QComboBox *trier;
    QLineEdit *recherche;
    QLineEdit *supprimer;
    QPushButton *btnSupprimer;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_5;
    QPushButton *btnModifier;
    QLineEdit *edit;
    QLabel *label_10;
    QComboBox *comboBox_typeVaccin_3;
    QPushButton *btnemploye;
    QPushButton *btnpatient;
    QPushButton *btnvaccins;
    QPushButton *btnequipement;
    QPushButton *btnformation;
    QPushButton *btnrecherche;
    QPushButton *logout;
    QPushButton *logo;
    QPushButton *btnRecherche;
    QPushButton *pdf;
    QPushButton *pdf_2;
    QTableView *tableViewVaccin;
    QPushButton *btnSave;
    QPushButton *statistiqueButton;
    QPushButton *pdf_3;
    QPushButton *on_excel_clicked;
    QPushButton *pdf_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1616, 850);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBox_typeVaccin_2 = new QGroupBox(centralwidget);
        comboBox_typeVaccin_2->setObjectName("comboBox_typeVaccin_2");
        comboBox_typeVaccin_2->setGeometry(QRect(170, 30, 261, 631));
        lineEdit_idVaccin = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_idVaccin->setObjectName("lineEdit_idVaccin");
        lineEdit_idVaccin->setGeometry(QRect(30, 60, 113, 26));
        label = new QLabel(comboBox_typeVaccin_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 121, 20));
        label_2 = new QLabel(comboBox_typeVaccin_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 121, 20));
        lineEdit_nomVaccin = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_nomVaccin->setObjectName("lineEdit_nomVaccin");
        lineEdit_nomVaccin->setGeometry(QRect(30, 110, 113, 26));
        label_3 = new QLabel(comboBox_typeVaccin_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 121, 20));
        lineEdit_effetsSecondaires = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_effetsSecondaires->setObjectName("lineEdit_effetsSecondaires");
        lineEdit_effetsSecondaires->setGeometry(QRect(30, 170, 113, 26));
        label_4 = new QLabel(comboBox_typeVaccin_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 200, 121, 20));
        label_7 = new QLabel(comboBox_typeVaccin_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 440, 63, 20));
        lineEdit_composition = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_composition->setObjectName("lineEdit_composition");
        lineEdit_composition->setGeometry(QRect(30, 230, 113, 26));
        label_5 = new QLabel(comboBox_typeVaccin_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 260, 63, 20));
        comboBox_typeVaccin = new QComboBox(comboBox_typeVaccin_2);
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->setObjectName("comboBox_typeVaccin");
        comboBox_typeVaccin->setGeometry(QRect(30, 500, 111, 31));
        label_8 = new QLabel(comboBox_typeVaccin_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 470, 63, 20));
        pushButton_4 = new QPushButton(comboBox_typeVaccin_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 590, 93, 29));
        label_9 = new QLabel(comboBox_typeVaccin_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 470, 81, 20));
        dateEdit_dateCreation = new QDateEdit(comboBox_typeVaccin_2);
        dateEdit_dateCreation->setObjectName("dateEdit_dateCreation");
        dateEdit_dateCreation->setGeometry(QRect(30, 360, 110, 26));
        label_11 = new QLabel(comboBox_typeVaccin_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 330, 101, 20));
        lineEdit_quantite = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_quantite->setObjectName("lineEdit_quantite");
        lineEdit_quantite->setGeometry(QRect(30, 290, 113, 26));
        dateEdit_datePeremption = new QDateEdit(comboBox_typeVaccin_2);
        dateEdit_datePeremption->setObjectName("dateEdit_datePeremption");
        dateEdit_datePeremption->setGeometry(QRect(30, 430, 110, 26));
        label_12 = new QLabel(comboBox_typeVaccin_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 400, 121, 20));
        lineEdit_idRech = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_idRech->setObjectName("lineEdit_idRech");
        lineEdit_idRech->setGeometry(QRect(30, 560, 113, 26));
        label_13 = new QLabel(comboBox_typeVaccin_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 530, 63, 20));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(450, 360, 1021, 421));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(9);
        font.setUnderline(true);
        tableView->setFont(font);
        trier = new QComboBox(centralwidget);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(760, 190, 171, 31));
        recherche = new QLineEdit(centralwidget);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(690, 150, 271, 26));
        supprimer = new QLineEdit(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(950, 190, 113, 26));
        btnSupprimer = new QPushButton(centralwidget);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(1080, 190, 93, 29));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(170, 660, 261, 51));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 10, 93, 29));
        btnModifier = new QPushButton(groupBox_2);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(110, 10, 93, 29));
        edit = new QLineEdit(groupBox_2);
        edit->setObjectName("edit");
        edit->setGeometry(QRect(210, 10, 41, 26));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(700, 20, 441, 111));
        comboBox_typeVaccin_3 = new QComboBox(centralwidget);
        comboBox_typeVaccin_3->setObjectName("comboBox_typeVaccin_3");
        comboBox_typeVaccin_3->setGeometry(QRect(970, 150, 111, 31));
        btnemploye = new QPushButton(centralwidget);
        btnemploye->setObjectName("btnemploye");
        btnemploye->setGeometry(QRect(0, 100, 161, 81));
        btnpatient = new QPushButton(centralwidget);
        btnpatient->setObjectName("btnpatient");
        btnpatient->setGeometry(QRect(0, 190, 161, 81));
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
        btnRecherche = new QPushButton(centralwidget);
        btnRecherche->setObjectName("btnRecherche");
        btnRecherche->setGeometry(QRect(1090, 150, 91, 31));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(1250, 10, 71, 51));
        pdf_2 = new QPushButton(centralwidget);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(1370, 10, 71, 51));
        tableViewVaccin = new QTableView(centralwidget);
        tableViewVaccin->setObjectName("tableViewVaccin");
        tableViewVaccin->setGeometry(QRect(450, 360, 1021, 421));
        QFont font1;
        font1.setPointSize(9);
        tableViewVaccin->setFont(font1);
        tableViewVaccin->setMouseTracking(false);
        tableViewVaccin->setLineWidth(-3);
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(270, 720, 93, 29));
        statistiqueButton = new QPushButton(centralwidget);
        statistiqueButton->setObjectName("statistiqueButton");
        statistiqueButton->setGeometry(QRect(1360, 60, 91, 31));
        pdf_3 = new QPushButton(centralwidget);
        pdf_3->setObjectName("pdf_3");
        pdf_3->setGeometry(QRect(1240, 60, 91, 31));
        on_excel_clicked = new QPushButton(centralwidget);
        on_excel_clicked->setObjectName("on_excel_clicked");
        on_excel_clicked->setGeometry(QRect(1140, 0, 81, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/excel-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        on_excel_clicked->setIcon(icon);
        pdf_4 = new QPushButton(centralwidget);
        pdf_4->setObjectName("pdf_4");
        pdf_4->setGeometry(QRect(1140, 60, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        comboBox_typeVaccin_2->raise();
        tableView->raise();
        trier->raise();
        recherche->raise();
        supprimer->raise();
        groupBox_2->raise();
        label_10->raise();
        btnSupprimer->raise();
        comboBox_typeVaccin_3->raise();
        btnemploye->raise();
        btnpatient->raise();
        btnvaccins->raise();
        btnequipement->raise();
        btnformation->raise();
        btnrecherche->raise();
        logout->raise();
        logo->raise();
        btnRecherche->raise();
        pdf->raise();
        pdf_2->raise();
        tableViewVaccin->raise();
        btnSave->raise();
        statistiqueButton->raise();
        pdf_3->raise();
        on_excel_clicked->raise();
        pdf_4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1616, 26));
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
        comboBox_typeVaccin_2->setTitle(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Id_vaccin</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">nom_vaccin</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">effet_secondaires</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">composition</span></p><p><br/></p></body></html>", nullptr));
        label_7->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">quantit\303\251</span></p></body></html>", nullptr));
        comboBox_typeVaccin->setItemText(0, QCoreApplication::translate("MainWindow", " inactiv\303\251s", nullptr));
        comboBox_typeVaccin->setItemText(1, QCoreApplication::translate("MainWindow", "Vivants Att\303\251nu\303\251s\n"
"", nullptr));
        comboBox_typeVaccin->setItemText(2, QCoreApplication::translate("MainWindow", "Recombinant\n"
"", nullptr));
        comboBox_typeVaccin->setItemText(3, QCoreApplication::translate("MainWindow", "Virus Modifi\303\251", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">type</span></p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">date_cr\303\251ation</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">date_peremption</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">id_rech</span></p><p><br/></p></body></html>", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700; color:#ffffff;\">vaccins</span></p></body></html>", nullptr));
#if QT_CONFIG(whatsthis)
        btnemploye->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">employe</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnemploye->setText(QCoreApplication::translate("MainWindow", "employe", nullptr));
        btnpatient->setText(QCoreApplication::translate("MainWindow", "patient", nullptr));
        btnvaccins->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        btnequipement->setText(QCoreApplication::translate("MainWindow", "equipement", nullptr));
        btnformation->setText(QCoreApplication::translate("MainWindow", "formation", nullptr));
        btnrecherche->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        logout->setText(QString());
        logo->setText(QString());
        btnRecherche->setText(QCoreApplication::translate("MainWindow", "chercher", nullptr));
        pdf->setText(QString());
        pdf_2->setText(QString());
        btnSave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        statistiqueButton->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        pdf_3->setText(QCoreApplication::translate("MainWindow", "pdf", nullptr));
        on_excel_clicked->setText(QString());
        pdf_4->setText(QCoreApplication::translate("MainWindow", "excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
