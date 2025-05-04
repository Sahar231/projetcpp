#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "login.h"
#include <QPalette>
#include <QtSql>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPageSize>
#include <QPainter>
#include <QList>
#include <QPair>
#include <QString>
#include <QRegularExpression>  // Inclure QRegularExpression pour les versions modernes de Qt
#include <QFont>
#include <QColor>
#include <QBrush>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFontMetrics>
#include <QSqlError>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMap>
#include <QDate>
#include <QStandardItemModel>
#include <QTableView>
#include "ia.h"  // Assurez-vous que ce fichier est inclus pour reconnaître la classe IA
#include <QPushButton>
#include <QIcon>
#include "QZXing.h"
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QVBoxLayout>  // Assurez-vous que cette ligne est présente
#include <QPixmap>
#include <QImage>
#include <QZXing.h> // Assure-toi d'avoir bien ajouté QZXing à ton projet
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QZXing>
#include "equip.h"
#include "form.h"
#include "patie.h"
#include "user.h"
#include "projet.h"



QString MainWindow::nettoyerTexte(const QString &text) {
    // Convertir en UTF-8
    QByteArray byteArray = text.toUtf8();
    QString cleanedText = QString::fromUtf8(byteArray);

    // Remplacer les caractères spéciaux par des caractères ASCII normaux
    cleanedText.replace(QRegularExpression("[éèêë]"), "e");
    cleanedText.replace(QRegularExpression("[àâä]"), "a");
    cleanedText.replace(QRegularExpression("[ôö]"), "o");
    cleanedText.replace(QRegularExpression("[ùûü]"), "u");
    cleanedText.replace(QRegularExpression("[îï]"), "i");
    cleanedText.replace(QRegularExpression("[ç]"), "c");

    // Supprimer tous les autres caractères non ASCII (imprimables)
    cleanedText.replace(QRegularExpression("[^\\x20-\\x7E]"), "");

    return cleanedText;
}


QList<QPair<QString, QString>> MainWindow::getVaccinsData() {
    QList<QPair<QString, QString>> vaccinsList;

    int rowCount = modelVaccins->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        QString nomVaccin = modelVaccins->data(modelVaccins->index(row, 1)).toString();  // Nom du vaccin
        QString description = modelVaccins->data(modelVaccins->index(row, 3)).toString(); // Description
        QString composition = modelVaccins->data(modelVaccins->index(row, 4)).toString();  // Composition

        // Ajoutez tous les champs dans une structure appropriée
        vaccinsList.append(qMakePair(nomVaccin + " - " + description, composition));
    }

    return vaccinsList;
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //imagepourlaboutton ia
    // Définir le chemin de l'image
    QString imagePath = "c:/Users/Sahar/Bureau/project/integration/chat.png";

    // Assurez-vous que le widget openia est accessible
    QPushButton* openiaButton = ui->openia;

    // Définir l'icône pour le bouton
    openiaButton->setIcon(QIcon(imagePath));

    // Ajuster la taille de l'icône, si nécessaire
    openiaButton->setIconSize(QSize(100, 100));  // Choisissez la taille qui vous convient
    //ia
    // Connecter le bouton openia à la méthode qui ouvre la fenêtre IA
    connect(ui->openia, &QPushButton::clicked, this, &MainWindow::openIA);

    // Appliquer un style moderne au QLabel (label_10) après l'initialisation de l'UI
    // Appliquer un style moderne avec une autre police (par exemple Montserrat)
    ui->label_10->setText("Vaccins");
    ui->label_10->setStyleSheet("QLabel {"
                                "font-family: 'Montserrat', 'Segoe UI', sans-serif;"  // Police moderne Montserrat
                                "font-size: 48pt;"                                    // Taille du texte plus grande
                                "font-weight: 800;"                                   // Texte en gras
                                "color: #1F618D;"                                     // Couleur bleue
                                "text-align: center;"                                 // Centrer le texte
                                "}");


    // Configuration de l'icône pour le bouton Excel
    QIcon excelIcon("c:/Users/Sahar/Bureau/project/integration/excel.png");
    if (!excelIcon.isNull()) {
        ui->on_excel_clicked->setIcon(excelIcon);
        ui->on_excel_clicked->setIconSize(QSize(71, 51));  // Taille de l'icône
        ui->on_excel_clicked->setFlat(true);
        ui->on_excel_clicked->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    } else {
        qDebug() << "Erreur: Impossible de charger l'icône Excel.";
    }

    ui->trier->setCurrentIndex(0); // Sélectionner l'option de tri par défaut

    // Style moderne pour QTableView
    QString modernTableStyle = R"(
        QTableView {
            background: rgba(236, 240, 241, 200);
            border: 2px solid rgba(41, 128, 185, 255);
            border-radius: 12px;
            gridline-color: #BDC3C7;
            selection-background-color: rgba(41, 128, 185, 255);
            selection-color: white;
            alternate-background-color: rgba(214, 234, 248, 200);
            font-size: 10pt;
            padding: 5px;
        }

        QHeaderView::section {
            background-color: rgba(41, 128, 185, 255);
            color: white;
            padding: 6px;
            border: none;
            font-size: 10pt;
            font-weight: bold;
            text-transform: uppercase;
            border-radius: 6px;
        }

        QTableView::item {
            padding: 4px;
            border-radius: 6px;
        }

        QTableView::item:hover {
            background-color: rgba(133, 193, 233, 255);
            color: #2C3E50;
            transition: background-color 0.3s ease-in-out;
        }

        QTableView::item:selected {
            background-color: #1F618D;
            color: white;
        }
    )";
    ui->tableViewVaccin->setStyleSheet(modernTableStyle);

    // Alternance des couleurs de ligne dans le QTableView
    ui->tableViewVaccin->setAlternatingRowColors(true);

    // Ajustement automatique des colonnes
    ui->tableViewVaccin->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Activation du tri dans le QTableView
    ui->tableViewVaccin->setSortingEnabled(true);

    // Sélection de lignes entières
    ui->tableViewVaccin->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Modèle de données pour les vaccins
    QStandardItemModel *model = new QStandardItemModel(0, 3, this);
    model->setHorizontalHeaderLabels({"ID", "Nom Vaccin", "Détails"});

    // Ajouter un exemple de données avec une icône
    QIcon icon(":/icons/vaccine.png");
    QStandardItem *item = new QStandardItem(icon, "Pfizer");
    model->setItem(0, 1, item);

    // Lier le modèle au tableView
    ui->tableViewVaccin->setModel(model);
    initializeTable(); // Appeler la méthode d'initialisation

    // Initialiser le modèle des vaccins
    modelVaccins = new QSqlTableModel(this);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::afficherVaccins);
    //connect(ui->btnRecherche, &QPushButton::clicked, this, &MainWindow::on_btnRecherche_clicked);
    connect(ui->trier, SIGNAL(currentIndexChanged(int)), this, SLOT(trierVaccins(int)));
    connect(ui->pdf_3, &QPushButton::clicked, this, &MainWindow::genererPDFDocument);
    connect(ui->on_excel_clicked, &QPushButton::clicked, this, &MainWindow::on_excel_clicked);
    connect(ui->qr, &QPushButton::clicked, this, &MainWindow::genererQRCode);


    // Configuration du QTableView
    ui->tableViewVaccin->setModel(modelVaccins);
    ui->tableViewVaccin->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewVaccin->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Style global de l'interface : changement des couleurs de fond, boutons et écritures
    QString modernStyle = R"(
        * {
            font-family: 'Segoe UI', sans-serif;
            font-size: 12pt;
            color: #2C3E50;
        }

        QMainWindow {
            background-color: #EAF2F8;
        }

        QPushButton {
            background-color: #3498db;
            border: 1px solid #2980b9;
            border-radius: 8px;
            padding: 10px;
            font-weight: bold;
            font-size: 14px;
            color: white;
            transition: background-color 0.3s, transform 0.2s;
        }

        QPushButton:hover {
            background-color: #2980b9;
            transform: scale(1.05);
        }

        QPushButton:pressed {
            background-color: #1f6f8b;
            transform: scale(0.98);
        }

        QGroupBox {
            background-color: #D5E8FB;
            border: 1px solid #3498db;
            border-radius: 6px;
            padding: 10px;
            font-weight: bold;
            font-size: 14px;
        }

        QComboBox {
            background-color: #FFFFFF;
            border: 1px solid #3498db;
            border-radius: 6px;
            padding: 5px;
            font-size: 12pt;
        }

        QLineEdit {
            background-color: #FFFFFF;
            border: 1px solid #3498db;
            border-radius: 6px;
            padding: 6px;
            font-size: 12pt;
        }

        QLabel {
            color: #2C3E50;
            font-weight: bold;
        }

        QTabWidget::pane {
            border: 1px solid #2980b9;
            border-radius: 6px;
        }

        QTabBar::tab {
            background-color: #2980b9;
            color: white;
            padding: 6px 12px;
            border-radius: 6px;
        }

        QTabBar::tab:hover {
            background-color: #3498db;
        }

        QTabBar::tab:selected {
            background-color: #1f618d;
            font-weight: bold;
        }
    )";
    this->setStyleSheet(modernStyle);

    // Appliquer une palette de couleurs modernes à l'interface
    if (ui->centralwidget) {
        QPalette palette;
        QPixmap pixmap("c:/Users/Sahar/Bureau/project/integration/back55.jpg");
        if (!pixmap.isNull()) {
            palette.setBrush(QPalette::Window, pixmap);
            ui->centralwidget->setPalette(palette);
            ui->centralwidget->setAutoFillBackground(true);
        } else {
            qDebug() << "Erreur: Impossible de charger l'image de fond.";
        }
    }

    // Style commun pour tous les boutons avec icônes
    struct ButtonConfig {
        QPushButton *button;
        QString iconPath;
        QSize iconSize;
    };

    ButtonConfig buttons[] = {
        {ui->logo, "c:/Users/Sahar/Bureau/project/integration/logo9.png", QSize(150, 150)},
        {ui->btnemploye, "c:/Users/Sahar/Bureau/project/integration/employe.png", QSize(50, 50)},
        {ui->btnpatient, "c:/Users/Sahar/Bureau/project/integration/patient.png", QSize(50, 50)},
        {ui->btnvaccins, "c:/Users/Sahar/Bureau/project/integration/vaccins.png", QSize(50, 50)},
        {ui->btnequipement, "c:/Users/Sahar/Bureau/project/integration/equipement.png", QSize(50, 50)},
        {ui->btnformation, "c:/Users/Sahar/Bureau/project/integration/formation.png", QSize(50, 50)},
        {ui->btnrecherche, "c:/Users/Sahar/Bureau/project/integration/recherche.png", QSize(50, 50)},
        {ui->logout, "c:/Users/Sahar/Bureau/project/integration/logout1.png", QSize(50, 50)}
    };

    for (const auto &btnConfig : buttons) {
        if (btnConfig.button) {
            QIcon icon(btnConfig.iconPath);
            if (!icon.isNull()) {
                btnConfig.button->setIcon(icon);
                btnConfig.button->setIconSize(btnConfig.iconSize);

                // Appliquer une police moderne et un style pour les boutons
                btnConfig.button->setStyleSheet(R"(
QPushButton {
    border: 0.5px solid black;
    border-radius: 5px;
    padding: 10px;
    font-weight: bold; /* Texte en gras */
    font-size: 14px;
}

QPushButton:hover,
QPushButton:pressed {
    background-color: #D3D3D3;
    border: 0.5px solid black;
}


            )");
            } else {
                qDebug() << "Erreur: Impossible de charger l'icône:" << btnConfig.iconPath;
            }
        }
    }



    for (const auto &btnConfig : buttons) {
        if (btnConfig.button) {
            QIcon icon(btnConfig.iconPath);
            if (!icon.isNull()) {
                btnConfig.button->setIcon(icon);
                btnConfig.button->setIconSize(btnConfig.iconSize);
                btnConfig.button->setStyleSheet(modernStyle);
            } else {
                qDebug() << "Erreur: Impossible de charger l'icône:" << btnConfig.iconPath;
            }
        }
    }

    // Configuration des boutons transparents (PDF, statistiques)
    struct TransparentButtonConfig {
        QPushButton *button;
        QString iconPath;
        QSize iconSize;
    };

    TransparentButtonConfig transparentButtons[] = {
        {ui->pdf, "c:/Users/Sahar/Bureau/project/integration/pdf2.png", QSize(91, 51)}
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

    // Configuration des placeholders pour une saisie élégante
    ui->recherche->setPlaceholderText("Rechercher un vaccin...");
    ui->comboBox_typeVaccin_3->addItems({"Nom", "Type"});
    ui->supprimer->setPlaceholderText("ID à supprimer");
    ui->trier->addItems({"ID", "Quantité"});
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openIA()
{
    // Dans ta méthode openIA (ou la méthode où tu souhaites créer l'objet)
    ia *iaWindow = new ia();  // Utiliser 'ia' avec une minuscule

    // Afficher la fenêtre IA
    iaWindow->show();
}
void MainWindow::on_pushButton_4_clicked()
{
    // Vérifier si la base est bien connectée
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur : Connexion à la base de données non ouverte";
        return;
    }

    // Récupérer les valeurs des champs de saisie
    QString nomVaccin = ui->lineEdit_nomVaccin->text().trimmed();
    QString effetsSecondaires = ui->lineEdit_effetsSecondaires->text().trimmed();
    QString composition = ui->lineEdit_composition->text().trimmed();
    QString quantiteStr = ui->lineEdit_quantite->text().trimmed();
    QDate dateCreation = ui->dateEdit_dateCreation->date();
    QDate datePeremption = ui->dateEdit_datePeremption->date();
    QString typeVaccin = ui->comboBox_typeVaccin->currentText();
    int idRech = ui->lineEdit_idRech->text().toInt();

    // Vérification des champs vides
    if (nomVaccin.isEmpty() || effetsSecondaires.isEmpty() || composition.isEmpty() ||
        quantiteStr.isEmpty() || typeVaccin.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérification si la quantité est un nombre valide
    bool ok;
    int quantite = quantiteStr.toInt(&ok);
    if (!ok || quantite <= 0) {
        QMessageBox::warning(this, "Avertissement", "La quantité doit être un nombre supérieur à 0!");
        return;
    }

    // Vérification de la validité des dates
    if (dateCreation > datePeremption) {
        QMessageBox::warning(this, "Avertissement", "La date de péremption doit être postérieure à la date de création.");
        return;
    }

    // Vérification que la date de création est aujourd'hui
    if (dateCreation != QDate::currentDate()) {
        QMessageBox::warning(this, "Avertissement", "La date de création doit être la date d'aujourd'hui.");
        return;
    }

    // Vérification de l'ID_RECH
    if (idRech <= 0) {
        QMessageBox::warning(this, "Avertissement", "L'ID_RECH doit être un nombre positif.");
        return;
    }

    // Vérification que le nom du vaccin commence par une majuscule
    if (nomVaccin.isEmpty() || !nomVaccin[0].isUpper()) {
        QMessageBox::warning(this, "Avertissement", "Le nom du vaccin doit commencer par une majuscule.");
        return;
    }

    // Vérification que les effets secondaires et la composition contiennent au moins trois mots
    if (effetsSecondaires.split(" ").size() < 3) {
        QMessageBox::warning(this, "Avertissement", "Les effets secondaires doivent contenir au moins trois mots.");
        return;
    }

    if (composition.split(" ").size() < 3) {
        QMessageBox::warning(this, "Avertissement", "La composition doit contenir au moins trois mots.");
        return;
    }

    // Afficher les valeurs pour le débogage
    qDebug() << "Valeurs récupérées:";
    qDebug() << "Nom:" << nomVaccin << ", Effets:" << effetsSecondaires;
    qDebug() << "Composition:" << composition << ", Quantité:" << quantiteStr;
    qDebug() << "Date création:" << dateCreation.toString("yyyy-MM-dd") << ", Date péremption:" << datePeremption.toString("yyyy-MM-dd");
    qDebug() << "ID_RECH:" << idRech << ", Type:" << typeVaccin;

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO VACCINS "
                  "(NOM_VACCIN, EFFET_SECONDAIRE, COMPOSITION, QUANTITE, DATE_CREATION,DATE_PEREMPTION, TYPE, ID_RECH_PK1) "
                  "VALUES (:nom_vaccin, :effets_secondaires, :composition, :quantite, TO_DATE(:date_creation, 'YYYY-MM-DD'), TO_DATE(:date_peremption, 'YYYY-MM-DD'), :type, :id_rech)");

    // Lier les valeurs aux paramètres SQL
    query.bindValue(":nom_vaccin", nomVaccin);
    query.bindValue(":effets_secondaires", effetsSecondaires);
    query.bindValue(":composition", composition);
    query.bindValue(":quantite", quantite);
    query.bindValue(":date_creation", dateCreation.toString("yyyy-MM-dd"));
    query.bindValue(":date_peremption", datePeremption.toString("yyyy-MM-dd"));
    query.bindValue(":type", typeVaccin);
    query.bindValue(":id_rech", idRech);

    // Exécuter la requête et vérifier le succès
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de l'insertion dans la base de données.");
        qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
    } else {
        QMessageBox::information(this, "Succès", "Insertion réussie.");

        // Vider les champs après une insertion réussie
        ui->lineEdit_nomVaccin->clear();
        ui->lineEdit_effetsSecondaires->clear();
        ui->lineEdit_composition->clear();
        ui->lineEdit_quantite->clear();
        ui->lineEdit_idRech->clear();
        ui->comboBox_typeVaccin->setCurrentIndex(0);
        ui->dateEdit_dateCreation->setDate(QDate::currentDate());
        ui->dateEdit_datePeremption->setDate(QDate::currentDate());
    }
}


// mainwindow.cpp
void MainWindow::initializeTable() {
    QSqlQuery query;
    query.exec("SELECT MAX(ID_VACCIN) FROM VACCINS");

    if (query.next()) {
        int lastId = query.value(0).toInt();
        // Si la table est vide, initialiser l'ID à 1
        if (lastId == 0) {
            ui->lineEdit_idVaccin->setText("1");
        } else {
            ui->lineEdit_idVaccin->setText(QString::number(lastId + 1));
        }
    } else {
        // Gérer l'erreur si la requête échoue
        qDebug() << "Erreur lors de la récupération de l'ID auto-incrémenté:" << query.lastError().text();
        ui->lineEdit_idVaccin->setText("1"); // Initialiser à 1 par défaut
    }
}



void MainWindow::afficherVaccins()
{
    // Afficher le QTableView uniquement si le bouton "Afficher" est cliqué
    modelVaccins->setTable("VACCINS");
    modelVaccins->select();
    ui->tableViewVaccin->setVisible(true);  // Rendre le tableau visible
    qDebug() << "Affichage des vaccins dans le tableau.";
}
void MainWindow::on_btnSupprimer_clicked()
{
    // Vérifier si la base est bien connectée
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur : Connexion à la base de données non ouverte";
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée.");
        return;
    }

    qDebug() << "on_btnSupprimer_clicked called"; // Pour déboguer

    // Récupérer l'ID du vaccin à supprimer depuis le champ 'supprimer'
    bool ok; // Pour vérifier la conversion
    int idVaccin = ui->supprimer->text().toInt(&ok);

    // Vérifier que l'ID est valide
    if (!ok || idVaccin <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM VACCINS WHERE ID_VACCIN = :id_vaccin");
    checkQuery.bindValue(":id_vaccin", idVaccin);

    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun vaccin trouvé avec cet ID.");
        return; // Ne pas continuer si l'ID n'existe pas
    }

    // Préparer la requête SQL pour supprimer le vaccin
    QSqlQuery query;
    query.prepare("DELETE FROM VACCINS WHERE ID_VACCIN = :id_vaccin");
    query.bindValue(":id_vaccin", idVaccin);

    // Exécuter la requête et vérifier les erreurs
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression : " << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du vaccin. Assurez-vous que l'ID existe.");
    } else {
        // Vaccin supprimé avec succès
        QMessageBox::information(this, "Succès", "Vaccin supprimé avec succès.");
        ui->supprimer->clear();  // Vider le champ de saisie
        afficherVaccins();  // Mettre à jour l'affichage des vaccins
    }
}
void MainWindow::on_btnModifier_clicked()
{
    // Vérifier si la base de données est connectée
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée.");
        return;
    }

    // Récupérer l'ID du vaccin à modifier depuis le champ de saisie
    bool ok;
    int idVaccin = ui->edit->text().toInt(&ok);  // Supposons que 'edit' est le QLineEdit pour l'ID

    // Vérifier que l'ID est valide
    if (!ok || idVaccin <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM VACCINS WHERE ID_VACCIN = :id_vaccin");
    checkQuery.bindValue(":id_vaccin", idVaccin);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Aucun vaccin trouvé avec cet ID.");
        return; // Ne pas continuer si l'ID n'existe pas
    }

    // Remplir le formulaire avec les données existantes
    ui->lineEdit_idVaccin->setText(checkQuery.value("ID_VACCIN").toString());
    ui->lineEdit_idVaccin->setReadOnly(true);  // Empêcher la modification de l'ID dans l'interface

    ui->lineEdit_nomVaccin->setText(checkQuery.value("NOM_VACCIN").toString());
    ui->lineEdit_effetsSecondaires->setText(checkQuery.value("EFFET_SECONDAIRE").toString());
    ui->lineEdit_composition->setText(checkQuery.value("COMPOSITION").toString());
    ui->lineEdit_quantite->setText(checkQuery.value("QUANTITE").toString());
    ui->dateEdit_dateCreation->setDate(checkQuery.value("DATE_CREATION").toDate());
    ui->dateEdit_datePeremption->setDate(checkQuery.value("DATE_PEREMPTION").toDate());
    ui->comboBox_typeVaccin->setCurrentText(checkQuery.value("TYPE").toString());
    ui->lineEdit_idRech->setText(checkQuery.value("ID_RECH_PK1").toString());

    // Sélectionner la ligne correspondante dans le QTableView
    int rowCount = modelVaccins->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        if (modelVaccins->data(modelVaccins->index(row, 0)).toInt() == idVaccin) { // Assurez-vous que la colonne 0 contient l'ID
            ui->tableViewVaccin->selectRow(row);
            break;
        }
    }

    // Connecter le bouton de sauvegarde après avoir vérifié l'ID
    connect(ui->btnSave, &QPushButton::clicked, this, [this, idVaccin]() {
        // Vérification des champs de saisie
        QString nomVaccin = ui->lineEdit_nomVaccin->text().trimmed();
        QString effetsSecondaires = ui->lineEdit_effetsSecondaires->text().trimmed();
        QString composition = ui->lineEdit_composition->text().trimmed();
        QString quantiteStr = ui->lineEdit_quantite->text().trimmed();
        QDate dateCreation = ui->dateEdit_dateCreation->date();
        QDate datePeremption = ui->dateEdit_datePeremption->date();
        QString typeVaccin = ui->comboBox_typeVaccin->currentText();
        int idRech = ui->lineEdit_idRech->text().toInt();

        // Vérifier que l'ID n'a pas été modifié
        int idVaccinForm = ui->lineEdit_idVaccin->text().toInt();
        if (idVaccinForm != idVaccin) {
            QMessageBox::warning(this, "Erreur", "Vous ne pouvez pas modifier l'identifiant du vaccin.");
            return;
        }

        // Vérification des champs vides
        if (nomVaccin.isEmpty() || effetsSecondaires.isEmpty() || composition.isEmpty() ||
            quantiteStr.isEmpty() || typeVaccin.isEmpty()) {
            QMessageBox::warning(this, "Avertissement", "Tous les champs doivent être remplis.");
            return;
        }

        // Vérification si la quantité est un nombre valide
        bool ok;
        int quantite = quantiteStr.toInt(&ok);
        if (!ok || quantite <= 0) {
            QMessageBox::warning(this, "Avertissement", "La quantité doit être un nombre supérieur à 0!");
            return;
        }

        // Vérification de la validité des dates
        if (dateCreation > datePeremption) {
            QMessageBox::warning(this, "Avertissement", "La date de péremption doit être postérieure à la date de création.");
            return;
        }

        // Vérification que la date de création est aujourd'hui
        if (dateCreation != QDate::currentDate()) {
            QMessageBox::warning(this, "Avertissement", "La date de création doit être la date d'aujourd'hui.");
            return;
        }

        // Vérification de l'ID_RECH
        if (idRech <= 0) {
            QMessageBox::warning(this, "Avertissement", "L'ID_RECH doit être un nombre positif.");
            return;
        }

        // Vérification que le nom du vaccin commence par une majuscule
        if (nomVaccin.isEmpty() || !nomVaccin[0].isUpper()) {
            QMessageBox::warning(this, "Avertissement", "Le nom du vaccin doit commencer par une majuscule.");
            return;
        }

        // Vérification que les effets secondaires et la composition contiennent au moins trois mots
        if (effetsSecondaires.split(" ").size() < 3) {
            QMessageBox::warning(this, "Avertissement", "Les effets secondaires doivent contenir au moins trois mots.");
            return;
        }

        if (composition.split(" ").size() < 3) {
            QMessageBox::warning(this, "Avertissement", "La composition doit contenir au moins trois mots.");
            return;
        }

        // Créer une requête de mise à jour
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE VACCINS SET "
                            "NOM_VACCIN = :nom_vaccin, "
                            "EFFET_SECONDAIRE= :effets_secondaires, "
                            "COMPOSITION = :composition, "
                            "QUANTITE = :quantite, "
                            "DATE_CREATION = TO_DATE(:date_creation, 'YYYY-MM-DD'), "
                            "DATE_PEREMPTION = TO_DATE(:date_peremption, 'YYYY-MM-DD'), "
                            "TYPE = :type, "
                            "ID_RECH_PK1 = :id_rech "
                            "WHERE ID_VACCIN = :id_vaccin");

        // Lier les valeurs aux paramètres SQL
        updateQuery.bindValue(":id_vaccin", idVaccin);
        updateQuery.bindValue(":nom_vaccin", nomVaccin);
        updateQuery.bindValue(":effets_secondaires", effetsSecondaires);
        updateQuery.bindValue(":composition", composition);
        updateQuery.bindValue(":quantite", quantite);
        updateQuery.bindValue(":date_creation", dateCreation.toString("yyyy-MM-dd"));
        updateQuery.bindValue(":date_peremption", datePeremption.toString("yyyy-MM-dd"));
        updateQuery.bindValue(":type", typeVaccin);
        updateQuery.bindValue(":id_rech", idRech);

        // Exécuter la requête et vérifier le succès
        if (!updateQuery.exec()) {
            QMessageBox::critical(this, "Erreur", "Échec de la mise à jour du vaccin.");
            qDebug() << "Erreur lors de la mise à jour:" << updateQuery.lastError().text();
        } else {
            QMessageBox::information(this, "Succès", "Vaccin mis à jour avec succès.");
            afficherVaccins();  // Mettre à jour l'affichage des vaccins
            disconnect(ui->btnSave, nullptr, nullptr, nullptr); // Déconnecter le signal pour éviter des appels multiples
        }
    });
}
//rech
// Recherche
void MainWindow::on_btnRecherche_clicked() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée.");
        return;
    }

    QString rechercheTexte = ui->recherche->text().trimmed();
    QString critereRecherche = ui->comboBox_typeVaccin_3->currentText();

    if (rechercheTexte.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez entrer un texte de recherche. 😊");
        return;
    }

    QString champSQL;
    if (critereRecherche == "Nom") {
        champSQL = "NOM_VACCIN";
    } else if (critereRecherche == "Type") {
        champSQL = "TYPE";
    } else if (critereRecherche == "Tous") {
        champSQL = "NOM_VACCIN";  // ou "*" selon ce que tu veux afficher
    } else {
        QMessageBox::warning(this, "Avertissement", "Critère de recherche non valide.");
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;

    query.prepare(QString("SELECT * FROM VACCINS WHERE %1 LIKE :recherche").arg(champSQL));
    query.bindValue(":recherche", "%" + rechercheTexte + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Échec lors de l'exécution de la recherche : " + query.lastError().text());
        return;
    }

    model->setQuery(std::move(query));

    // 🔁 Forcer le chargement des lignes pour éviter l'affichage multiple des messages
    while (model->canFetchMore()) {
        model->fetchMore();
    }

    int nbResultats = model->rowCount();

    if (nbResultats == 0) {
        QMessageBox::information(this, "Recherche", "Aucun vaccin trouvé pour la recherche.");
    } else {
        QMessageBox::information(this, "Succès", "Recherche effectuée avec succès !");
        ui->tableViewVaccin->setModel(model);
        ui->tableViewVaccin->resizeColumnsToContents();

        // ⏱️ Timer pour proposer la réinitialisation
        QTimer::singleShot(2000, this, &MainWindow::askForReset);
    }
}

// Demander à l'utilisateur s'il souhaite réinitialiser le tableau
void MainWindow::askForReset() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Réinitialiser le tableau",
                                  "Souhaitez-vous réinitialiser le tableau ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        resetTableView();
    }
}

// Fonction pour réinitialiser le tableau
void MainWindow::resetTableView() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;

    query.prepare("SELECT * FROM VACCINS");

    if (query.exec()) {
        model->setQuery(std::move(query));

        // 🔁 Forcer le chargement ici aussi (bonne pratique)
        while (model->canFetchMore()) {
            model->fetchMore();
        }

        ui->tableViewVaccin->setModel(model);
        ui->tableViewVaccin->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec lors de la réinitialisation de la table.");
    }
}


void MainWindow::trierVaccins(int index)
{
    QString critere;
    QString ordre = "ASC"; // par défaut ordre croissant

    // Déterminer le critère de tri et l'ordre en fonction de la sélection
    switch(index) {
    case 0:
        critere = "ID_VACCIN";  // Tri par ID (ordre croissant)
        break;
    case 1:
        critere = "QUANTITE";   // Tri par quantité (ordre décroissant)
        ordre = "DESC";
        break;
    default:
        return;  // Pas de tri si l'index n'est pas valide
    }

    // Créer la requête SQL pour trier les données
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM VACCINS ORDER BY \"%1\" %2")
                      .arg(critere, ordre));

    // Exécuter la requête
    if (query.exec()) {
        // Rafraîchir le modèle et mettre à jour l'affichage
        modelVaccins->setQuery(std::move(query));
        ui->tableViewVaccin->setModel(modelVaccins);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec du tri des vaccins.");
        qDebug() << "Erreur lors du tri:" << query.lastError().text();
    }
}


//pdf
void MainWindow::genererPDFDocument() {
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF",
                                                    QApplication::applicationDirPath() + "/vaccins.pdf",
                                                    "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter writer(filePath);

    // Définir la page au format A4 paysage (format rectangle)
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Landscape); // Orientation paysage

    writer.setResolution(300);
    QPainter painter(&writer);

    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'initialiser le QPainter pour le PDF.");
        return;
    }

    QAbstractItemModel* model = ui->tableViewVaccin->model();
    if (!model) return;

    int pageWidth = writer.width();
    int pageHeight = writer.height();

    // Marges réduites pour maximiser l'espace
    int marginLeft = 40;
    int marginTop = 80;   // Ajustement pour l'orientation paysage
    int marginRight = 40;
    int marginBottom = 40;

    int usableWidth = pageWidth - marginLeft - marginRight;
    int usableHeight = pageHeight - marginTop - marginBottom;

    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    // --- Calcul dynamique pour remplir toute la page
    // Réduire la taille du tableau en fonction de l'espace disponible
    int cellWidth = usableWidth / columnCount;
    int cellHeight = (rowCount > 0) ? usableHeight / (rowCount + 1) : 40;

    // Ajuster la hauteur des cellules si nécessaire pour mieux afficher tout le texte
    cellHeight = std::max(cellHeight, 20); // Assurez-vous que les cellules ne sont pas trop petites

    // --- Titre
    QFont titleFont("Arial", 20, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(QColor("#0D47A1"));
    QString title = "Liste Complète des Vaccins";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    painter.drawText((pageWidth - titleWidth) / 2, 60, title);

    // --- Police pour tableau
    QFont tableFont("Helvetica", 10);  // Réduire légèrement la taille de la police
    painter.setFont(tableFont);
    painter.setPen(Qt::black);

    // --- En-têtes de colonnes
    for (int c = 0; c < columnCount; ++c) {
        QRect rect(marginLeft + c * cellWidth, marginTop, cellWidth, cellHeight);
        painter.fillRect(rect, QColor("#BBDEFB")); // bleu clair
        painter.setPen(QColor("#0D47A1"));
        painter.drawRect(rect);
        QString headerText = model->headerData(c, Qt::Horizontal).toString();
        painter.drawText(rect.adjusted(5, 0, -5, 0), Qt::AlignCenter, headerText);
    }

    // --- Lignes de données (remplies verticalement)
    for (int r = 0; r < rowCount; ++r) {
        for (int c = 0; c < columnCount; ++c) {
            QRect rect(marginLeft + c * cellWidth, marginTop + (r + 1) * cellHeight, cellWidth, cellHeight);
            QColor bg = (r % 2 == 0) ? QColor("#E3F2FD") : QColor("#FFFFFF");
            painter.fillRect(rect, bg);
            painter.setPen(Qt::black);
            painter.drawRect(rect);

            QString text = model->data(model->index(r, c)).toString();
            QString finalText = painter.fontMetrics().elidedText(text, Qt::ElideRight, cellWidth - 10);
            painter.drawText(rect.adjusted(5, 0, -5, 0), Qt::AlignVCenter | Qt::AlignLeft, finalText);
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès à l'emplacement :\n" + filePath);
}


//stat

void MainWindow::on_pdf_2_clicked()
{
    // Vérifie que la base est connectée
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Base de données non connectée !");
        return;
    }

    // Préparer la requête pour additionner les quantités par nom de vaccin
    QMap<QString, int> quantiteParVaccin;
    QSqlQuery query("SELECT NOM_VACCIN, QUANTITE FROM VACCINS");

    while (query.next()) {
        QString nomVaccin = query.value(0).toString();
        int quantite = query.value(1).toInt();
        quantiteParVaccin[nomVaccin] += quantite;
    }

    if (quantiteParVaccin.isEmpty()) {
        QMessageBox::information(this, "Information", "Aucune donnée disponible pour générer les statistiques.");
        return;
    }

    // Création de la série du diagramme
    QPieSeries *series = new QPieSeries();

    for (auto it = quantiteParVaccin.begin(); it != quantiteParVaccin.end(); ++it) {
        series->append(it.key(), it.value());
    }

    // Personnalisation du design
    int colorIndex = 0;
    QStringList colors = { "#3498db", "#2ecc71", "#e74c3c", "#9b59b6", "#f39c12", "#1abc9c", "#e67e22", "#7f8c8d" };

    for (auto slice : series->slices()) {
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg(slice->value()));
        slice->setLabelVisible(true);
        slice->setExploded(true); // Fait ressortir chaque tranche
        slice->setLabelColor(Qt::black);
        slice->setPen(QPen(Qt::darkGray, 1));
        QColor color = QColor(colors[colorIndex % colors.size()]);
        slice->setBrush(color);
        colorIndex++;
    }

    // Créer et configurer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Quantité totale des vaccins par nom");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(640, 480);
    chartView->setWindowTitle("Statistiques des Vaccins (par Quantité)");
    chartView->show(); // Affiche la fenêtre du graphique
}
void MainWindow::on_excel_clicked()
{
    qDebug() << "Bouton Excel cliqué !";

    // Demander à l'utilisateur de choisir l'emplacement de sauvegarde
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en Excel", "", "Fichiers CSV (*.csv)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier pour écriture.");
        return;
    }

    QTextStream out(&file);

    // Exporter les en-têtes de colonnes
    QAbstractItemModel *model = ui->tableViewVaccin->model();
    QStringList headers;
    for (int col = 0; col < model->columnCount(); ++col) {
        headers << model->headerData(col, Qt::Horizontal).toString();
    }
    out << headers.join(";") << "\n";

    // Exporter les données de chaque ligne
    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList rowValues;
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            rowValues << data;
        }
        out << rowValues.join(";") << "\n";
    }

    file.close();
    QMessageBox::information(this, "Succès", "Exportation vers Excel réussie !");
}
//qrcode
void MainWindow::genererQRCode()
{
    QSqlQuery query;
    query.prepare("SELECT ID_VACCIN, NOM_VACCIN, TYPE, QUANTITE, DATE_CREATION, DATE_PEREMPTION FROM VACCINS");

    if (!query.exec()) {
        qDebug() << "Erreur d'exécution de la requête : " << query.lastError().text();
        return;
    }

    QString data;

    while (query.next()) {
        int idVaccin = query.value("ID_VACCIN").toInt();
        QString nomVaccin = query.value("NOM_VACCIN").toString();
        QString typeVaccin = query.value("NOM_VACCIN").toString();
        int quantite = query.value("QUANTITE").toInt();
        QDate dateCreation = query.value("DATE_CREATION").toDate();
        QDate datePeremption = query.value("DATE_PEREMPTION").toDate();

        // Construire la chaîne de texte qui sera contenue dans le QR code
        data += QString("ID=%1; Nom=%2; Type=%3; Quantité=%4; Créé=%5; Expire=%6\n")
                    .arg(idVaccin)
                    .arg(nomVaccin)
                    .arg(typeVaccin)
                    .arg(quantite)
                    .arg(dateCreation.toString("yyyy-MM-dd"))
                    .arg(datePeremption.toString("yyyy-MM-dd"));
    }

    if (!data.isEmpty()) {
        // Retirer le dernier saut de ligne
        data.chop(1);

        // Créer un QR code à partir des données
        QZXingEncoderConfig config;
        config.format = QZXing::EncoderFormat_QR_CODE;

        // Encoder les données dans le QR code
        QImage qrImage = QZXing::encodeData(data, config);

        if (!qrImage.isNull()) {
            ui->labelQRCode->setPixmap(QPixmap::fromImage(qrImage).scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Échec de génération du QR Code.";
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun vaccin trouvé dans la base de données.");
    }
}

void MainWindow::on_btnemploye_clicked()
{
    user *u=new user();
    u->show();
    this->hide();

}


void MainWindow::on_btnpatient_clicked()
{
    patie * pa=new patie();
    pa->show();
    this->hide();

}


void MainWindow::on_btnequipement_clicked()
{
    equip *e = new equip();
    e->show();
    this->hide();
}


void MainWindow::on_btnformation_clicked()
{
    forma *fo= new forma();
    fo->show();
    this->hide();

}


void MainWindow::on_btnrecherche_clicked()
{
    projet *r=new projet();
    r->show();
    this->hide();

}


void MainWindow::on_logout_clicked()
{
    login *l=new login();
    l->show();
    this->hide();
}

