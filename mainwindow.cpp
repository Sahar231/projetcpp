#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
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




    // Ajouter l'icône au bouton excel
    QIcon excelIcon("C:/Users/hp/Desktop/2A17/qt/interfce/excel.png"); // Correct


    if (!excelIcon.isNull()) {
        ui->on_excel_clicked->setIcon(excelIcon);
        ui->on_excel_clicked->setIconSize(QSize(71, 51)); // Même taille que le bouton
        ui->on_excel_clicked->setFlat(true);              // Supprime l'effet 3D du bouton
        ui->on_excel_clicked->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    } else {
        qDebug() << "Erreur: Impossible de charger l'icône Excel.";
    }


    ui->trier->setCurrentIndex(0);  // Sélectionner l'option de tri par défaut, ici "id"


QString style = R"(
    QTableView {
        background: rgba(236, 240, 241, 200); /* Set a semi-transparent background */
        border: 2px solid rgba(41, 128, 185, 255); /* Border color remains solid */
        border-radius: 12px;
        gridline-color: #BDC3C7;
        selection-background-color: rgba(41, 128, 185, 255); /* Solid selection color */
        selection-color: white;
        alternate-background-color: rgba(214, 234, 248, 200); /* Semi-transparent alternate background */
        font-size: 9pt;
        padding: 5px;
    }

    QHeaderView::section {
        background-color: rgba(41, 128, 185, 255); /* Solid color for header */
        color: white;
        padding: 6px;
        border: none;
        font-size: 9.5pt;
        font-weight: bold;
        text-transform: uppercase;
        border-radius: 6px;
    }

    QTableView::item {
        padding: 4px;
        border-radius: 6px;
    }

    QTableView::item:hover {
        background-color: rgba(133, 193, 233, 255); /* Hover color remains solid */
        color: #2C3E50;
        transition: background-color 0.3s ease-in-out;
    }

    QTableView::item:selected {
        background-color: #1F618D; /* Solid color for selected item */
        color: white;
    }


)";


    ui->tableViewVaccin->setStyleSheet(style);

    // Activer les couleurs alternées
    ui->tableViewVaccin->setAlternatingRowColors(true);

    // Ajuster la taille des colonnes automatiquement
    ui->tableViewVaccin->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Activer le tri des colonnes
    ui->tableViewVaccin->setSortingEnabled(true);

    // Sélectionner des lignes entières au lieu des cellules
    ui->tableViewVaccin->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Créer un modèle pour le tableau
    QStandardItemModel *model = new QStandardItemModel(0, 3, this); // 0 lignes, 3 colonnes
    model->setHorizontalHeaderLabels({"ID", "Nom Vaccin", "Détails"});

    // Ajouter un exemple de données avec une icône
    QIcon icon(":/icons/vaccine.png"); // Assurez-vous que l'icône est dans les ressources Qt
    QStandardItem *item = new QStandardItem(icon, "Pfizer");
    model->setItem(0, 1, item);


    // Lier le modèle au `tableViewVaccin`
    ui->tableViewVaccin->setModel(model);
    initializeTable(); // Appeler la méthode d'initialisation
    //connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);

    // Initialiser le modèle des vaccins
    modelVaccins = new QSqlTableModel(this);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::afficherVaccins);
    //connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->btnRecherche, &QPushButton::clicked, this, &MainWindow::on_btnRecherche_clicked);
    connect(ui->trier, SIGNAL(currentIndexChanged(int)), this, SLOT(trierVaccins(int)));
    connect(ui->pdf_3, &QPushButton::clicked, this, &MainWindow::genererPDFDocument); // Ou genererPDF si vous utilisez ce nom
    connect(ui->on_excel_clicked, &QPushButton::clicked, this, &MainWindow::on_excel_clicked);





    // Configuration du QTableView
    ui->tableViewVaccin->setModel(modelVaccins);
    ui->tableViewVaccin->setSelectionBehavior(QAbstractItemView::SelectRows);  // Sélection par ligne
    ui->tableViewVaccin->setEditTriggers(QAbstractItemView::NoEditTriggers);  // Désactiver l'édition directe

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
    ui->comboBox_typeVaccin_2->setStyleSheet(
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
        //{ui->rech, "C:/Users/hp/Desktop/2A17/qt/interfce/reche.png", QSize(91, 31)},
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
    ui->recherche->setPlaceholderText("Rechercher un vaccin par...");
    ui->comboBox_typeVaccin_3->addItems({"nom", "type", });
    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItems({ "id", "quantité"});
}

MainWindow::~MainWindow()
{
    delete ui;
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
    query.prepare("INSERT INTO \"C##LABSYNC_NEW\".\"VACCINS\" "
                  "(\"NOM_VACCIN\", \"EFFET_SECONDAIRE\", \"COMPOSITION\", \"QUANTITÉ\", \"DATE_CRÉATION\", \"DATE_PEREMPTION\", \"TYPE\", \"ID_RECH_PK1\") "
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
    query.exec("SELECT MAX(ID_VACCIN) FROM \"C##LABSYNC_NEW\".\"VACCINS\"");

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
    modelVaccins->setTable("C##LABSYNC_NEW.VACCINS");
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
    checkQuery.prepare("SELECT COUNT(*) FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"ID_VACCIN\" = :id_vaccin");
    checkQuery.bindValue(":id_vaccin", idVaccin);

    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun vaccin trouvé avec cet ID.");
        return; // Ne pas continuer si l'ID n'existe pas
    }

    // Préparer la requête SQL pour supprimer le vaccin
    QSqlQuery query;
    query.prepare("DELETE FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"ID_VACCIN\" = :id_vaccin");
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
    checkQuery.prepare("SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"ID_VACCIN\" = :id_vaccin");
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
    ui->lineEdit_quantite->setText(checkQuery.value("QUANTITÉ").toString());
    ui->dateEdit_dateCreation->setDate(checkQuery.value("DATE_CRÉATION").toDate());
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
        updateQuery.prepare("UPDATE \"C##LABSYNC_NEW\".\"VACCINS\" SET "
                            "\"NOM_VACCIN\" = :nom_vaccin, "
                            "\"EFFET_SECONDAIRE\" = :effets_secondaires, "
                            "\"COMPOSITION\" = :composition, "
                            "\"QUANTITÉ\" = :quantite, "
                            "\"DATE_CRÉATION\" = TO_DATE(:date_creation, 'YYYY-MM-DD'), "
                            "\"DATE_PEREMPTION\" = TO_DATE(:date_peremption, 'YYYY-MM-DD'), "
                            "\"TYPE\" = :type, "
                            "\"ID_RECH_PK1\" = :id_rech "
                            "WHERE \"ID_VACCIN\" = :id_vaccin");

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

void MainWindow::on_btnRecherche_clicked() {
    // Vérifier si la base de données est connectée
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée.");
        return;
    }

    // Récupérer le texte de recherche et le critère de recherche choisi
    QString rechercheTexte = ui->recherche->text().trimmed();
    QString critereRecherche = ui->comboBox_typeVaccin_3->currentText();

    // Vérifier que le texte de recherche n'est pas vide
    if (rechercheTexte.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez entrer un texte de recherche.");
        return;
    }

    // Construire la requête de recherche selon le critère sélectionné
    QSqlQuery query;
    QString requeteSql;

    if (critereRecherche == "nom") {
        requeteSql = "SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"NOM_VACCIN\" LIKE :rechercheTexte";
    } else if (critereRecherche == "type") {
        requeteSql = "SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"TYPE\" LIKE :rechercheTexte";
    } else if (critereRecherche == "état") {
        requeteSql = "SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"EFFET_SECONDAIRE\" LIKE :rechercheTexte";
    } else if (critereRecherche == "date_création") {
        requeteSql = "SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"DATE_CRÉATION\" LIKE :rechercheTexte";
    } else if (critereRecherche == "date_peremption") {
        requeteSql = "SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" WHERE \"DATE_PEREMPTION\" LIKE :rechercheTexte";
    }

    // Préparer la requête SQL
    query.prepare(requeteSql);
    query.bindValue(":rechercheTexte", "%" + rechercheTexte + "%");  // Utiliser des wildcards pour une recherche partielle

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche des vaccins.");
        qDebug() << "Erreur lors de la recherche:" << query.lastError().text();
        return;
    }

    // Mettre à jour le QTableView avec les résultats de la recherche
    modelVaccins->setQuery(std::move(query));  // Déplacer le query pour éviter la copie (déprécié)

    // Vérifier si des résultats ont été retournés
    if (modelVaccins->rowCount() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucun vaccin ne correspond à votre recherche.");
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
        critere = "QUANTITÉ";   // Tri par quantité (ordre décroissant)
        ordre = "DESC";
        break;
    default:
        return;  // Pas de tri si l'index n'est pas valide
    }

    // Créer la requête SQL pour trier les données
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM \"C##LABSYNC_NEW\".\"VACCINS\" ORDER BY \"%1\" %2")
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
    // Ouvrir une boîte de dialogue pour enregistrer le fichier PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF",
                                                    QApplication::applicationDirPath() + "/vaccins.pdf",
                                                    "Fichiers PDF (*.pdf)");

    // Vérifier si l'utilisateur a sélectionné un fichier
    if (filePath.isEmpty()) {
        return;
    }

    // Créer un objet QPdfWriter pour écrire dans le fichier
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);

    QPainter painter(&writer);

    // Vérifier si le QPainter a bien été initialisé
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'initialiser le QPainter pour le PDF.");
        return;
    }

    // Définir les marges et dimensions
    int marginLeft = 50;   // Marge de gauche
    int marginTop = 50;    // Marge en haut
    int rowHeight = 40;    // Hauteur des lignes
    int availableWidth = writer.width() - 2 * marginLeft; // Largeur disponible pour les vaccins

    // Liste des vaccins
    QList<QString> vaccinsList = {"Grippe", "Tétanos", "COVID-19", "Rougeole"};

    // Calculer l'espacement horizontal nécessaire
    int totalTextWidth = 0;
    for (const QString &vaccin : vaccinsList) {
        totalTextWidth += painter.fontMetrics().horizontalAdvance(vaccin);  // Largeur totale des textes
    }

    // Calculer l'espacement horizontal disponible
    int horizontalSpacing = (availableWidth - totalTextWidth) / (vaccinsList.size() + 1); // Ajouter un espacement entre chaque vaccin

    // Définir la police et la taille de l'en-tête
    QFont titleFont("Arial", 18, QFont::Bold);
    painter.setFont(titleFont);

    // Dessiner l'en-tête du PDF centré
    QString title = "Liste des Vaccins";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    painter.drawText((writer.width() - titleWidth) / 2, marginTop, title);

    // Ajouter un espace vertical plus grand avant la liste des vaccins
    int titleSpacing = 200; // Augmenter encore l'espacement entre le titre et la liste des vaccins
    int startY = marginTop + titleSpacing;  // Nouveau point de départ pour la liste des vaccins

    // Modifier la police pour la liste des vaccins
    QFont vaccinFont("Arial", 14);
    painter.setFont(vaccinFont);

    // Espacement vertical avant la liste des vaccins
    startY += rowHeight;  // Commencer un peu plus bas après le titre et l'espacement

    int startX = marginLeft;

    // Afficher les vaccins sur la même ligne avec l'espacement calculé
    for (const QString &vaccin : vaccinsList) {
        painter.drawText(startX, startY, vaccin);  // Dessiner chaque vaccin à la position (startX, startY)

        // Mettre à jour la position horizontale pour le vaccin suivant
        startX += painter.fontMetrics().horizontalAdvance(vaccin) + horizontalSpacing;  // Calculer la prochaine position horizontale
    }

    // Terminer l'écriture du PDF
    painter.end();

    // Afficher un message de succès
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès à l'emplacement : " + filePath);
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
    QSqlQuery query("SELECT \"NOM_VACCIN\", \"QUANTITÉ\" FROM \"C##LABSYNC_NEW\".\"VACCINS\"");

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
