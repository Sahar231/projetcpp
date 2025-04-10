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
#include <QtWidgets/QGridLayout>
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
    QLabel *label_10;
    QPushButton *btnemploye;
    QPushButton *btnpatient;
    QPushButton *btnvaccins;
    QPushButton *btnequipement;
    QPushButton *btnformation;
    QPushButton *btnrecherche;
    QPushButton *logout;
    QPushButton *logo;
    QGroupBox *Recherche_Infos;
    QWidget *layoutWidget_2;
    QGridLayout *Labels_Lines_2;
    QLabel *Event_label_Type;
    QComboBox *Rc_statut_combo;
    QLineEdit *Rc_type_field;
    QLabel *Event_label_Date_2;
    QComboBox *Rc_employe_combox;
    QLabel *Event_label_Date;
    QLabel *Event_label_Lieu_3;
    QLineEdit *Rc_id_field;
    QLabel *Event_label_ID;
    QDateEdit *Rc_date_field;
    QLabel *Event_label_Nom;
    QLineEdit *Rc_nom_field;
    QPushButton *Rc_push_Ajouter;
    QPushButton *Rc_push_Modifier;
    QPushButton *Rc_push_Supprimer;
    QComboBox *RC_combo_ID;
    QTableView *Rc_TableView_Res;
    QLabel *Rc_Label_InfoAffichage;
    QPushButton *Rc_Button_ExportPDF;
    QLineEdit *Rc_Line_Recherche;
    QPushButton *Rc_Button_Tri_Numtel;
    QLabel *Rc_Label_TriPar;
    QPushButton *Rc_Button_Tri_Nom;
    QPushButton *Rc_Button_Tri_Email;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1404, 770);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(580, 10, 421, 71));
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
        Recherche_Infos = new QGroupBox(centralwidget);
        Recherche_Infos->setObjectName("Recherche_Infos");
        Recherche_Infos->setGeometry(QRect(190, 150, 361, 521));
        Recherche_Infos->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background: transparent; /* Fully transparent background */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-top-right-radius: 7px;\n"
"    border-bottom-right-radius: 7px;\n"
"    border-bottom-left-radius: 7px;\n"
"    margin-top: 22px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    background-color: transparent; /* Transparent title background */\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QGroupBox:hover {\n"
"    background: transparent; /* No background change on hover */\n"
"    border-color: black; /* Keep border black */\n"
"}\n"
""));
        layoutWidget_2 = new QWidget(Recherche_Infos);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 50, 321, 351));
        Labels_Lines_2 = new QGridLayout(layoutWidget_2);
        Labels_Lines_2->setObjectName("Labels_Lines_2");
        Labels_Lines_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        Labels_Lines_2->setVerticalSpacing(24);
        Labels_Lines_2->setContentsMargins(0, 0, 0, 0);
        Event_label_Type = new QLabel(layoutWidget_2);
        Event_label_Type->setObjectName("Event_label_Type");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        Event_label_Type->setFont(font);
        Event_label_Type->setStyleSheet(QString::fromUtf8(""));
        Event_label_Type->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Event_label_Type, 4, 0, 2, 1);

        Rc_statut_combo = new QComboBox(layoutWidget_2);
        Rc_statut_combo->addItem(QString());
        Rc_statut_combo->addItem(QString());
        Rc_statut_combo->addItem(QString());
        Rc_statut_combo->setObjectName("Rc_statut_combo");
        Rc_statut_combo->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    selection-background-color: rgba(255, 255, 255, 150); /* Semi-transparent white for selection */\n"
"    selection-color: black;\n"
"    color: black; /* Default text color */\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white background */\n"
"    border-style: solid;\n"
"    border: 1px solid black; /* Black border */\n"
"    border-radius: 5px; /* Keeping rounded corners */\n"
"    padding: 1px 0px 1px 20px;\n"
"}\n"
"\n"
"QComboBox:hover\n"
"{\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 1px solid black; /* Keep border black */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgba(255, 255, 255, 200); /* Semi-transparent white dropdown */\n"
"    border: 1px solid black;\n"
"    selection-background-color: rgba(200, 200, 200, 150); /* Slightly darker for selected item */\n"
"    selection-color: b"
                        "lack;\n"
"}\n"
""));

        Labels_Lines_2->addWidget(Rc_statut_combo, 7, 1, 1, 1);

        Rc_type_field = new QLineEdit(layoutWidget_2);
        Rc_type_field->setObjectName("Rc_type_field");
        Rc_type_field->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
""));

        Labels_Lines_2->addWidget(Rc_type_field, 4, 1, 2, 2);

        Event_label_Date_2 = new QLabel(layoutWidget_2);
        Event_label_Date_2->setObjectName("Event_label_Date_2");
        Event_label_Date_2->setFont(font);
        Event_label_Date_2->setStyleSheet(QString::fromUtf8(""));
        Event_label_Date_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Event_label_Date_2, 7, 0, 1, 1);

        Rc_employe_combox = new QComboBox(layoutWidget_2);
        Rc_employe_combox->setObjectName("Rc_employe_combox");
        Rc_employe_combox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    selection-background-color: rgba(255, 255, 255, 150); /* Semi-transparent white for selection */\n"
"    selection-color: black;\n"
"    color: black; /* Default text color */\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white background */\n"
"    border-style: solid;\n"
"    border: 1px solid black; /* Black border */\n"
"    border-radius: 5px; /* Keeping rounded corners */\n"
"    padding: 1px 0px 1px 20px;\n"
"}\n"
"\n"
"QComboBox:hover\n"
"{\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 1px solid black; /* Keep border black */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgba(255, 255, 255, 200); /* Semi-transparent white dropdown */\n"
"    border: 1px solid black;\n"
"    selection-background-color: rgba(200, 200, 200, 150); /* Slightly darker for selected item */\n"
"    selection-color: b"
                        "lack;\n"
"}\n"
""));

        Labels_Lines_2->addWidget(Rc_employe_combox, 8, 1, 1, 1);

        Event_label_Date = new QLabel(layoutWidget_2);
        Event_label_Date->setObjectName("Event_label_Date");
        Event_label_Date->setFont(font);
        Event_label_Date->setStyleSheet(QString::fromUtf8(""));
        Event_label_Date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Event_label_Date, 6, 0, 1, 1);

        Event_label_Lieu_3 = new QLabel(layoutWidget_2);
        Event_label_Lieu_3->setObjectName("Event_label_Lieu_3");
        Event_label_Lieu_3->setFont(font);
        Event_label_Lieu_3->setStyleSheet(QString::fromUtf8(""));
        Event_label_Lieu_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Event_label_Lieu_3, 8, 0, 1, 1);

        Rc_id_field = new QLineEdit(layoutWidget_2);
        Rc_id_field->setObjectName("Rc_id_field");
        Rc_id_field->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        Labels_Lines_2->addWidget(Rc_id_field, 0, 1, 2, 2);

        Event_label_ID = new QLabel(layoutWidget_2);
        Event_label_ID->setObjectName("Event_label_ID");
        Event_label_ID->setFont(font);
        Event_label_ID->setStyleSheet(QString::fromUtf8(""));
        Event_label_ID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Event_label_ID, 0, 0, 2, 1);

        Rc_date_field = new QDateEdit(layoutWidget_2);
        Rc_date_field->setObjectName("Rc_date_field");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat Medium")});
        font1.setPointSize(10);
        Rc_date_field->setFont(font1);
        Rc_date_field->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    selection-background-color: rgba(255, 255, 255, 150); /* Semi-transparent white selection */\n"
"    selection-color: black;\n"
"    color: black; /* Default text color */\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white background */\n"
"    border-style: solid;\n"
"    border: 1px solid black; /* Black border */\n"
"    border-radius: 5px; /* Keeping rounded corners */\n"
"    padding: 1px 0px 1px 20px;\n"
"}\n"
"\n"
"QDateEdit:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 1px solid black; /* Keep border black */\n"
"}\n"
"\n"
"QDateEdit QAbstractItemView {\n"
"    background-color: rgba(255, 255, 255, 200); /* Semi-transparent white dropdown */\n"
"    border: 1px solid black;\n"
"    selection-background-color: rgba(200, 200, 200, 150); /* Slightly darker for selected item */\n"
"    selection-color: black;\n"
"}\n"
""));
        Rc_date_field->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Rc_date_field, 6, 1, 1, 1);

        Event_label_Nom = new QLabel(layoutWidget_2);
        Event_label_Nom->setObjectName("Event_label_Nom");
        Event_label_Nom->setFont(font);
        Event_label_Nom->setStyleSheet(QString::fromUtf8(""));
        Event_label_Nom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Labels_Lines_2->addWidget(Event_label_Nom, 2, 0, 2, 1);

        Rc_nom_field = new QLineEdit(layoutWidget_2);
        Rc_nom_field->setObjectName("Rc_nom_field");
        Rc_nom_field->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        Labels_Lines_2->addWidget(Rc_nom_field, 2, 1, 2, 2);

        Rc_push_Ajouter = new QPushButton(Recherche_Infos);
        Rc_push_Ajouter->setObjectName("Rc_push_Ajouter");
        Rc_push_Ajouter->setGeometry(QRect(30, 430, 141, 31));
        Rc_push_Ajouter->setFont(font1);
        Rc_push_Ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        Rc_push_Modifier = new QPushButton(Recherche_Infos);
        Rc_push_Modifier->setObjectName("Rc_push_Modifier");
        Rc_push_Modifier->setGeometry(QRect(190, 430, 141, 31));
        Rc_push_Modifier->setFont(font1);
        Rc_push_Modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        Rc_push_Supprimer = new QPushButton(Recherche_Infos);
        Rc_push_Supprimer->setObjectName("Rc_push_Supprimer");
        Rc_push_Supprimer->setGeometry(QRect(110, 470, 141, 31));
        Rc_push_Supprimer->setFont(font1);
        Rc_push_Supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        RC_combo_ID = new QComboBox(centralwidget);
        RC_combo_ID->setObjectName("RC_combo_ID");
        RC_combo_ID->setGeometry(QRect(280, 100, 181, 22));
        RC_combo_ID->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    selection-background-color: rgba(255, 255, 255, 150); /* Semi-transparent white for selection */\n"
"    selection-color: black;\n"
"    color: black; /* Default text color */\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white background */\n"
"    border-style: solid;\n"
"    border: 1px solid black; /* Black border */\n"
"    border-radius: 5px; /* Keeping rounded corners */\n"
"    padding: 1px 0px 1px 20px;\n"
"}\n"
"\n"
"QComboBox:hover\n"
"{\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 1px solid black; /* Keep border black */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgba(255, 255, 255, 200); /* Semi-transparent white dropdown */\n"
"    border: 1px solid black;\n"
"    selection-background-color: rgba(200, 200, 200, 150); /* Slightly darker for selected item */\n"
"    selection-color: b"
                        "lack;\n"
"}\n"
""));
        Rc_TableView_Res = new QTableView(centralwidget);
        Rc_TableView_Res->setObjectName("Rc_TableView_Res");
        Rc_TableView_Res->setGeometry(QRect(590, 260, 801, 411));
        Rc_TableView_Res->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    gridline-color: black; /* Ensuring grid lines are visible */\n"
"    color: black; /* Default text color */\n"
"    selection-background-color: rgba(0, 0, 0, 50); /* Slightly visible selection */\n"
"    selection-color: white; /* White text for selection */\n"
"}\n"
"\n"
"QTableView::viewport {\n"
"    background-color: rgba(255, 255, 255, 150); /* Ensuring viewport is also semi-transparent white */\n"
"}\n"
"\n"
"QWidget {\n"
"    background: transparent; /* Ensure parent widget does not override */\n"
"}\n"
""));
        Rc_Label_InfoAffichage = new QLabel(centralwidget);
        Rc_Label_InfoAffichage->setObjectName("Rc_Label_InfoAffichage");
        Rc_Label_InfoAffichage->setGeometry(QRect(720, 100, 511, 41));
        Rc_Label_InfoAffichage->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Fully transparent background */\n"
"    border: 1px solid #230a98; /* Purple border */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    color: black; /* Default text color */\n"
"}\n"
""));
        Rc_Button_ExportPDF = new QPushButton(centralwidget);
        Rc_Button_ExportPDF->setObjectName("Rc_Button_ExportPDF");
        Rc_Button_ExportPDF->setGeometry(QRect(1260, 170, 81, 31));
        Rc_Button_ExportPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        Rc_Line_Recherche = new QLineEdit(centralwidget);
        Rc_Line_Recherche->setObjectName("Rc_Line_Recherche");
        Rc_Line_Recherche->setGeometry(QRect(590, 169, 181, 31));
        Rc_Line_Recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"		border: 1px solid #230a98;\n"
"		border-radius: 5px;\n"
"}\n"
"QLineEdit:hover {\n"
"		border: 1px solid #7359f0;\n"
"}"));
        Rc_Button_Tri_Numtel = new QPushButton(centralwidget);
        Rc_Button_Tri_Numtel->setObjectName("Rc_Button_Tri_Numtel");
        Rc_Button_Tri_Numtel->setGeometry(QRect(850, 217, 81, 31));
        Rc_Button_Tri_Numtel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        Rc_Label_TriPar = new QLabel(centralwidget);
        Rc_Label_TriPar->setObjectName("Rc_Label_TriPar");
        Rc_Label_TriPar->setGeometry(QRect(590, 215, 71, 31));
        QFont font2;
        font2.setBold(true);
        Rc_Label_TriPar->setFont(font2);
        Rc_Button_Tri_Nom = new QPushButton(centralwidget);
        Rc_Button_Tri_Nom->setObjectName("Rc_Button_Tri_Nom");
        Rc_Button_Tri_Nom->setGeometry(QRect(670, 217, 81, 31));
        Rc_Button_Tri_Nom->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        Rc_Button_Tri_Email = new QPushButton(centralwidget);
        Rc_Button_Tri_Email->setObjectName("Rc_Button_Tri_Email");
        Rc_Button_Tri_Email->setGeometry(QRect(760, 217, 81, 31));
        Rc_Button_Tri_Email->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white */\n"
"    border: 2px solid black; /* Black border */\n"
"    border-radius: 8px;\n"
"    color: black; /* Default text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 2px solid black; /* Keep border black */\n"
"}\n"
""));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(800, 174, 171, 22));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    selection-background-color: rgba(255, 255, 255, 150); /* Semi-transparent white for selection */\n"
"    selection-color: black;\n"
"    color: black; /* Default text color */\n"
"    background-color: rgba(255, 255, 255, 150); /* Semi-transparent white background */\n"
"    border-style: solid;\n"
"    border: 1px solid black; /* Black border */\n"
"    border-radius: 5px; /* Keeping rounded corners */\n"
"    padding: 1px 0px 1px 20px;\n"
"}\n"
"\n"
"QComboBox:hover\n"
"{\n"
"    background-color: rgba(255, 255, 255, 180); /* Slightly less transparent on hover */\n"
"    border: 1px solid black; /* Keep border black */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgba(255, 255, 255, 200); /* Semi-transparent white dropdown */\n"
"    border: 1px solid black;\n"
"    selection-background-color: rgba(200, 200, 200, 150); /* Slightly darker for selected item */\n"
"    selection-color: b"
                        "lack;\n"
"}\n"
""));
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
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:696; font-style:italic; color:#ffffff;\">RECHERCHE</span></p></body></html>", nullptr));
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
        Recherche_Infos->setTitle(QCoreApplication::translate("MainWindow", "Recherche Informations", nullptr));
        Event_label_Type->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        Rc_statut_combo->setItemText(0, QCoreApplication::translate("MainWindow", "En Cours", nullptr));
        Rc_statut_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Termine", nullptr));
        Rc_statut_combo->setItemText(2, QCoreApplication::translate("MainWindow", "Annule", nullptr));

        Event_label_Date_2->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        Event_label_Date->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        Event_label_Lieu_3->setText(QCoreApplication::translate("MainWindow", "ID_Employe", nullptr));
        Rc_id_field->setText(QString());
        Event_label_ID->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        Rc_date_field->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd-MM-yyyy", nullptr));
        Event_label_Nom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        Rc_push_Ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        Rc_push_Modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        Rc_push_Supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        Rc_Label_InfoAffichage->setText(QString());
        Rc_Button_ExportPDF->setText(QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        Rc_Line_Recherche->setInputMask(QString());
        Rc_Line_Recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche Par...", nullptr));
        Rc_Button_Tri_Numtel->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        Rc_Label_TriPar->setText(QCoreApplication::translate("MainWindow", "Tri par :", nullptr));
        Rc_Button_Tri_Nom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        Rc_Button_Tri_Email->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "nom", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "type", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "statut", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
