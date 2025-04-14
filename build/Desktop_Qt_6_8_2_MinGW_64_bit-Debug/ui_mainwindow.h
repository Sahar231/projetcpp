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
    QGroupBox *groupBox_2;
    QPushButton *pushButton_5;
    QPushButton *btnModifier;
    QLineEdit *edit;
    QLabel *label_10;
    QPushButton *btnemploye;
    QPushButton *btnpatient;
    QPushButton *btnvaccins;
    QPushButton *btnequipement;
    QPushButton *btnformation;
    QPushButton *btnrecherche;
    QPushButton *logout;
    QPushButton *logo;
    QTableView *tableViewVaccin;
    QPushButton *btnSave;
    QGroupBox *groupBox;
    QLineEdit *recherche;
    QComboBox *comboBox_typeVaccin_3;
    QPushButton *btnRecherche;
    QComboBox *trier;
    QLineEdit *supprimer;
    QPushButton *btnSupprimer;
    QGroupBox *groupBox_3;
    QPushButton *pdf_4;
    QPushButton *on_excel_clicked;
    QPushButton *statistiqueButton;
    QPushButton *pdf_2;
    QPushButton *pdf;
    QPushButton *pdf_3;
    QPushButton *qr;
    QPushButton *openia;
    QLabel *label_6;
    QLabel *label_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1732, 1122);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBox_typeVaccin_2 = new QGroupBox(centralwidget);
        comboBox_typeVaccin_2->setObjectName("comboBox_typeVaccin_2");
        comboBox_typeVaccin_2->setGeometry(QRect(170, 10, 261, 641));
        lineEdit_idVaccin = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_idVaccin->setObjectName("lineEdit_idVaccin");
        lineEdit_idVaccin->setGeometry(QRect(30, 50, 171, 31));
        label = new QLabel(comboBox_typeVaccin_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 121, 20));
        label_2 = new QLabel(comboBox_typeVaccin_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 121, 20));
        lineEdit_nomVaccin = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_nomVaccin->setObjectName("lineEdit_nomVaccin");
        lineEdit_nomVaccin->setGeometry(QRect(30, 110, 171, 26));
        label_3 = new QLabel(comboBox_typeVaccin_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 121, 20));
        lineEdit_effetsSecondaires = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_effetsSecondaires->setObjectName("lineEdit_effetsSecondaires");
        lineEdit_effetsSecondaires->setGeometry(QRect(30, 170, 171, 26));
        label_4 = new QLabel(comboBox_typeVaccin_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 200, 121, 20));
        label_7 = new QLabel(comboBox_typeVaccin_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 440, 63, 20));
        lineEdit_composition = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_composition->setObjectName("lineEdit_composition");
        lineEdit_composition->setGeometry(QRect(30, 230, 171, 26));
        label_5 = new QLabel(comboBox_typeVaccin_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 260, 63, 20));
        comboBox_typeVaccin = new QComboBox(comboBox_typeVaccin_2);
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->addItem(QString());
        comboBox_typeVaccin->setObjectName("comboBox_typeVaccin");
        comboBox_typeVaccin->setGeometry(QRect(30, 500, 141, 31));
        label_8 = new QLabel(comboBox_typeVaccin_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 470, 63, 20));
        pushButton_4 = new QPushButton(comboBox_typeVaccin_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 590, 201, 41));
        label_9 = new QLabel(comboBox_typeVaccin_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 470, 81, 20));
        dateEdit_dateCreation = new QDateEdit(comboBox_typeVaccin_2);
        dateEdit_dateCreation->setObjectName("dateEdit_dateCreation");
        dateEdit_dateCreation->setGeometry(QRect(30, 360, 141, 31));
        label_11 = new QLabel(comboBox_typeVaccin_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 330, 101, 20));
        lineEdit_quantite = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_quantite->setObjectName("lineEdit_quantite");
        lineEdit_quantite->setGeometry(QRect(30, 290, 171, 26));
        dateEdit_datePeremption = new QDateEdit(comboBox_typeVaccin_2);
        dateEdit_datePeremption->setObjectName("dateEdit_datePeremption");
        dateEdit_datePeremption->setGeometry(QRect(30, 440, 141, 31));
        label_12 = new QLabel(comboBox_typeVaccin_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 400, 151, 31));
        lineEdit_idRech = new QLineEdit(comboBox_typeVaccin_2);
        lineEdit_idRech->setObjectName("lineEdit_idRech");
        lineEdit_idRech->setGeometry(QRect(30, 550, 171, 26));
        label_13 = new QLabel(comboBox_typeVaccin_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 530, 91, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(170, 660, 281, 61));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 10, 93, 41));
        btnModifier = new QPushButton(groupBox_2);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(110, 10, 93, 41));
        edit = new QLineEdit(groupBox_2);
        edit->setObjectName("edit");
        edit->setGeometry(QRect(210, 10, 51, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(560, 10, 261, 101));
        label_10->setFocusPolicy(Qt::FocusPolicy::TabFocus);
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
        tableViewVaccin = new QTableView(centralwidget);
        tableViewVaccin->setObjectName("tableViewVaccin");
        tableViewVaccin->setGeometry(QRect(450, 330, 1051, 441));
        QFont font;
        font.setPointSize(9);
        tableViewVaccin->setFont(font);
        tableViewVaccin->setMouseTracking(false);
        tableViewVaccin->setLineWidth(-3);
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(220, 730, 181, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(480, 140, 731, 121));
        recherche = new QLineEdit(groupBox);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(20, 20, 291, 31));
        comboBox_typeVaccin_3 = new QComboBox(groupBox);
        comboBox_typeVaccin_3->setObjectName("comboBox_typeVaccin_3");
        comboBox_typeVaccin_3->setGeometry(QRect(320, 20, 171, 31));
        btnRecherche = new QPushButton(groupBox);
        btnRecherche->setObjectName("btnRecherche");
        btnRecherche->setGeometry(QRect(510, 10, 201, 41));
        trier = new QComboBox(groupBox);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(30, 70, 281, 31));
        supprimer = new QLineEdit(groupBox);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(330, 70, 161, 31));
        btnSupprimer = new QPushButton(groupBox);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(520, 70, 191, 41));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(860, 10, 561, 111));
        pdf_4 = new QPushButton(groupBox_3);
        pdf_4->setObjectName("pdf_4");
        pdf_4->setGeometry(QRect(20, 20, 131, 61));
        on_excel_clicked = new QPushButton(groupBox_3);
        on_excel_clicked->setObjectName("on_excel_clicked");
        on_excel_clicked->setGeometry(QRect(20, 20, 131, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/excel-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        on_excel_clicked->setIcon(icon);
        statistiqueButton = new QPushButton(groupBox_3);
        statistiqueButton->setObjectName("statistiqueButton");
        statistiqueButton->setGeometry(QRect(160, 20, 111, 61));
        pdf_2 = new QPushButton(groupBox_3);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(160, 20, 111, 61));
        pdf = new QPushButton(groupBox_3);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(310, 20, 61, 61));
        pdf_3 = new QPushButton(groupBox_3);
        pdf_3->setObjectName("pdf_3");
        pdf_3->setGeometry(QRect(280, 20, 121, 61));
        qr = new QPushButton(groupBox_3);
        qr->setObjectName("qr");
        qr->setGeometry(QRect(420, 20, 111, 61));
        pdf_3->raise();
        pdf_4->raise();
        on_excel_clicked->raise();
        statistiqueButton->raise();
        pdf_2->raise();
        pdf->raise();
        qr->raise();
        openia = new QPushButton(centralwidget);
        openia->setObjectName("openia");
        openia->setGeometry(QRect(450, 20, 111, 91));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(730, 270, 211, 51));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1240, 169, 271, 111));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1732, 26));
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
        comboBox_typeVaccin_2->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Id vaccin</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">nom vaccin</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">effet secondaires</span></p></body></html>", nullptr));
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
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">date cr\303\251ation</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">date peremption</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">id recherche</span></p><p><br/></p><p><br/></p></body></html>", nullptr));
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
        btnSave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        groupBox->setTitle(QString());
        btnRecherche->setText(QCoreApplication::translate("MainWindow", "chercher", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        groupBox_3->setTitle(QString());
        pdf_4->setText(QString());
        on_excel_clicked->setText(QString());
        statistiqueButton->setText(QString());
        pdf_2->setText(QString());
        pdf->setText(QString());
        pdf_3->setText(QString());
        qr->setText(QString());
        openia->setText(QString());
        label_6->setText(QString());
        label_14->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
