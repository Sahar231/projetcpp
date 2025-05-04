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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Home_Page;
    QPushButton *pdf_2;
    QPushButton *btnequipement;
    QLabel *label_10;
    QPushButton *btnemploye;
    QLineEdit *recherche;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLabel *label_11;
    QPushButton *pushButton;
    QDateEdit *date_edit2;
    QDateEdit *date_edit3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QComboBox *trier;
    QPushButton *logo;
    QPushButton *btnpatient;
    QTableView *tableView;
    QPushButton *btnrecherche;
    QPushButton *pdf;
    QLineEdit *supprimer;
    QPushButton *btnvaccins;
    QPushButton *logout;
    QPushButton *btnformation;
    QPushButton *pushButton_2;
    QPushButton *calendarBUtoon;
    QPushButton *STATISTICSBUTTON;
    QPushButton *pdf_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QWidget *Page_Calendrier;
    QCalendarWidget *calendarWidget;
    QLabel *formationdate;
    QPushButton *backtoHomeButtonC;
    QWidget *page_statistique;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *statsContainerLayout;
    QPushButton *backtoHomeButtonS;
    QWidget *pagecapteur;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_12;
    QGroupBox *groupBox_3;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_16;
    QPushButton *pushButton_6;
    QListView *listView;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QGroupBox *groupBox_4;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1418, 735);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-20, 0, 1405, 748));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/back55.jpg);"));
        Home_Page = new QWidget();
        Home_Page->setObjectName("Home_Page");
        pdf_2 = new QPushButton(Home_Page);
        pdf_2->setObjectName("pdf_2");
        pdf_2->setGeometry(QRect(680, 150, 91, 51));
        btnequipement = new QPushButton(Home_Page);
        btnequipement->setObjectName("btnequipement");
        btnequipement->setGeometry(QRect(0, 380, 161, 81));
        label_10 = new QLabel(Home_Page);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(590, 30, 421, 71));
        btnemploye = new QPushButton(Home_Page);
        btnemploye->setObjectName("btnemploye");
        btnemploye->setGeometry(QRect(0, 110, 161, 81));
        recherche = new QLineEdit(Home_Page);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(550, 220, 271, 26));
        groupBox = new QGroupBox(Home_Page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(180, 50, 221, 651));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 50, 113, 26));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 121, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 91, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 63, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 200, 81, 20));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 360, 111, 26));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 260, 81, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 440, 63, 20));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(30, 230, 113, 26));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setEnabled(true);
        lineEdit_5->setGeometry(QRect(30, 290, 113, 26));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 490, 111, 31));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 460, 63, 20));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 610, 93, 29));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 390, 101, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 610, 93, 29));
        date_edit2 = new QDateEdit(groupBox);
        date_edit2->setObjectName("date_edit2");
        date_edit2->setGeometry(QRect(30, 110, 110, 26));
        date_edit3 = new QDateEdit(groupBox);
        date_edit3->setObjectName("date_edit3");
        date_edit3->setGeometry(QRect(40, 170, 110, 26));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 420, 113, 26));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 330, 111, 20));
        trier = new QComboBox(Home_Page);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(780, 260, 171, 31));
        logo = new QPushButton(Home_Page);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 10, 161, 91));
        btnpatient = new QPushButton(Home_Page);
        btnpatient->setObjectName("btnpatient");
        btnpatient->setGeometry(QRect(0, 200, 161, 81));
        tableView = new QTableView(Home_Page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(490, 300, 851, 411));
        btnrecherche = new QPushButton(Home_Page);
        btnrecherche->setObjectName("btnrecherche");
        btnrecherche->setGeometry(QRect(0, 560, 161, 81));
        pdf = new QPushButton(Home_Page);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(820, 150, 91, 51));
        supprimer = new QLineEdit(Home_Page);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(990, 260, 113, 26));
        btnvaccins = new QPushButton(Home_Page);
        btnvaccins->setObjectName("btnvaccins");
        btnvaccins->setGeometry(QRect(0, 290, 161, 81));
        logout = new QPushButton(Home_Page);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(0, 650, 161, 61));
        btnformation = new QPushButton(Home_Page);
        btnformation->setObjectName("btnformation");
        btnformation->setGeometry(QRect(0, 470, 161, 81));
        pushButton_2 = new QPushButton(Home_Page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1120, 260, 93, 29));
        calendarBUtoon = new QPushButton(Home_Page);
        calendarBUtoon->setObjectName("calendarBUtoon");
        calendarBUtoon->setGeometry(QRect(1170, 130, 171, 26));
        STATISTICSBUTTON = new QPushButton(Home_Page);
        STATISTICSBUTTON->setObjectName("STATISTICSBUTTON");
        STATISTICSBUTTON->setGeometry(QRect(1170, 180, 171, 26));
        pdf_3 = new QPushButton(Home_Page);
        pdf_3->setObjectName("pdf_3");
        pdf_3->setGeometry(QRect(990, 220, 111, 29));
        pushButton_5 = new QPushButton(Home_Page);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(840, 220, 93, 28));
        pushButton_3 = new QPushButton(Home_Page);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(540, 260, 201, 29));
        stackedWidget->addWidget(Home_Page);
        Page_Calendrier = new QWidget();
        Page_Calendrier->setObjectName("Page_Calendrier");
        calendarWidget = new QCalendarWidget(Page_Calendrier);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(550, 110, 841, 561));
        formationdate = new QLabel(Page_Calendrier);
        formationdate->setObjectName("formationdate");
        formationdate->setGeometry(QRect(30, 70, 471, 631));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        formationdate->setFont(font);
        backtoHomeButtonC = new QPushButton(Page_Calendrier);
        backtoHomeButtonC->setObjectName("backtoHomeButtonC");
        backtoHomeButtonC->setGeometry(QRect(20, 10, 121, 41));
        stackedWidget->addWidget(Page_Calendrier);
        page_statistique = new QWidget();
        page_statistique->setObjectName("page_statistique");
        verticalLayoutWidget = new QWidget(page_statistique);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(330, 160, 581, 381));
        statsContainerLayout = new QVBoxLayout(verticalLayoutWidget);
        statsContainerLayout->setObjectName("statsContainerLayout");
        statsContainerLayout->setContentsMargins(0, 0, 0, 0);
        backtoHomeButtonS = new QPushButton(page_statistique);
        backtoHomeButtonS->setObjectName("backtoHomeButtonS");
        backtoHomeButtonS->setGeometry(QRect(110, 40, 121, 51));
        stackedWidget->addWidget(page_statistique);
        pagecapteur = new QWidget();
        pagecapteur->setObjectName("pagecapteur");
        groupBox_2 = new QGroupBox(pagecapteur);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(80, 40, 381, 211));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 30, 331, 31));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 70, 93, 29));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(170, 70, 93, 29));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 120, 161, 20));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(80, 140, 231, 51));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(120, 150, 161, 41));
        groupBox_3 = new QGroupBox(pagecapteur);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(520, 50, 451, 211));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(90, 50, 161, 20));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(80, 110, 231, 51));
        label_16 = new QLabel(pagecapteur);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(1150, 80, 201, 81));
        pushButton_6 = new QPushButton(pagecapteur);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(30, 690, 141, 41));
        listView = new QListView(pagecapteur);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(260, 310, 861, 351));
        label_19 = new QLabel(pagecapteur);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(312, 370, 221, 41));
        label_20 = new QLabel(pagecapteur);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(350, 450, 63, 41));
        label_21 = new QLabel(pagecapteur);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(410, 520, 161, 51));
        label_22 = new QLabel(pagecapteur);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(710, 530, 231, 31));
        label_23 = new QLabel(pagecapteur);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(610, 370, 63, 20));
        label_24 = new QLabel(pagecapteur);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(410, 580, 141, 41));
        label_25 = new QLabel(pagecapteur);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(700, 570, 181, 51));
        label_26 = new QLabel(pagecapteur);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(530, 450, 191, 20));
        label_27 = new QLabel(pagecapteur);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(540, 460, 241, 31));
        groupBox_4 = new QGroupBox(pagecapteur);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(1030, 50, 371, 211));
        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(20, 20, 331, 31));
        label_29 = new QLabel(groupBox_4);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 60, 291, 71));
        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(30, 139, 281, 61));
        stackedWidget->addWidget(pagecapteur);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1418, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pdf_2->setText(QString());
        btnequipement->setText(QCoreApplication::translate("MainWindow", "equipement", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700; font-style:italic; color:#ffffff;\">FORMATION</span></p><p align=\"center\"><br/></p></body></html>", nullptr));
#if QT_CONFIG(whatsthis)
        btnemploye->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">employe</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnemploye->setText(QCoreApplication::translate("MainWindow", "employe", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Id</span></p><p><br/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">DateDebut</span></p><p><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">DateFin</span></p><p><br/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Heure</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Lieu</span></p></body></html>", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Certificat</span></p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>nombre max</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "modifier ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Participant</span></p></body></html>", nullptr));
        logo->setText(QString());
        btnpatient->setText(QCoreApplication::translate("MainWindow", "patient", nullptr));
        btnrecherche->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        pdf->setText(QString());
        btnvaccins->setText(QCoreApplication::translate("MainWindow", "vaccins", nullptr));
        logout->setText(QString());
        btnformation->setText(QCoreApplication::translate("MainWindow", "formation", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        calendarBUtoon->setText(QCoreApplication::translate("MainWindow", "GO TO CALENDAR", nullptr));
        STATISTICSBUTTON->setText(QCoreApplication::translate("MainWindow", "GO TO STATISTICS", nullptr));
        pdf_3->setText(QCoreApplication::translate("MainWindow", "Export pdf", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "capteur de mouvement", nullptr));
        formationdate->setText(QString());
        backtoHomeButtonC->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        backtoHomeButtonS->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "capteur de mouvement", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Modifier l'\303\251tat du capteur </span></p></body></html>", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "on", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Etat du capteur", nullptr));
        label_17->setText(QString());
        label_12->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Etat du porte", nullptr));
        label_18->setText(QString());
        label_16->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">id du formation</span></p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">date</span></p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">PARTICIPANT </span></p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">NOMBRE MAX</span></p></body></html>", nullptr));
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QString());
        label_26->setText(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "28/04/2025", nullptr));
        groupBox_4->setTitle(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">etat du salle</span></p></body></html>", nullptr));
        label_29->setText(QString());
        label_30->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
