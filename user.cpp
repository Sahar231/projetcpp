    #include "user.h"
#include "ui_user.h"
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QRegularExpression>
#include "chat.h"
#include "serialcommunication.h"
#include "equip.h"
#include "form.h"
#include "patie.h"
#include "projet.h"
#include "mainwindow.h"
#include "login.h"



user::user(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::user )
{
    ui->setupUi(this);
    ui->combo_stat->setVisible(false); // Cacher le QComboBox au démarrage
    setupSerial();
    loadEmployees();

    // Configuration de l'interface
    QPalette palette;
    QPixmap pixmap("c:/Users/Sahar/Bureau/project/integration/back55.jpg");
    palette.setBrush(QPalette::Window, pixmap);
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);

    // Style des boutons
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

    // Style du groupe
    ui->groupBox->setStyleSheet(
        "QGroupBox {"
        "background-color: Light Cyan;"
        "border: 0.5px solid black;"
        "border-radius: 5px;"
        "padding: 10px;"
        "}"
        "QLineEdit { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "QSpinBox { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "QComboBox { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "}");

    // Configuration des icônes et des boutons
    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/logo9.png"));
    ui->logo->setIconSize(QSize(161, 91));
    ui->logo->setStyleSheet(commonButtonStyle);

    ui->btnemploye->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);

    ui->btnpatient->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);

    ui->btnvaccins->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);

    ui->btnequipement->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);

    ui->btnformation->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);

    ui->btnrecherche->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);
    ui->logout->setStyleSheet(commonButtonStyle);





    // Configuration des champs de saisie
    ui->recherche->setPlaceholderText("Rechercher un employé par ... ");
    ui->comboBox_3->addItem("nom");
    ui->comboBox_3->addItem("prenom");
    ui->comboBox_3->addItem("id");

    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItem("trier par");
    ui->trier->addItem("salaire");
    ui->trier->addItem("genre");
    ui->trier->addItem("spécialite");

    ui->combo_stat->addItem("stat selon");
    ui->combo_stat->addItem("Genre");
    ui->combo_stat->addItem("Spécialité");
    ui->combo_stat->addItem("Salaire");

    // Connexion des boutons
    connect(ui->pushButton_4, &QPushButton::clicked, this, &user::on_pushButton_4_clicked);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &user::on_pushButton_2_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &user::on_modifier_clicked);
    connect(serialCom, &SerialCommunication::uidReceived, this, &user::checkUidInDatabase);
    connect(serialCom, &SerialCommunication::uidAuthorized, this, &user::handleUidFromArduino);
    connect(ui->addUidToEmployee, &QPushButton::clicked, this, &user::addUidToEmployee);


}

user ::~user ()
{
    delete ui;
}

// Fonction pour ajouter un employé
void user::on_pushButton_4_clicked()
{
    QString id_employe = ui->lineEdit->text().trimmed();
    QString nom = ui->lineEdit_2->text().trimmed();
    QString prenom = ui->lineEdit_3->text().trimmed();
    QString telStr = ui->lineEdit_4->text().trimmed();
    QString genre = ui->comboBox_2->currentText().trimmed();
    QString adresse = ui->lineEdit_5->text().trimmed();
    QString specialite = ui->lineEdit_6->text().trimmed();
    QString salaireStr = ui->lineEdit_7->text().trimmed(); // Nouveau champ pour le salaire
    QString email = ui->email->text().trimmed();

    // Expressions régulières pour valider les entrées
    QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÖØ-öø-ÿ]+$"); // Lettres et accents
    QRegularExpression regexTel("^[0-9]{8}$"); // Numéro de téléphone de 8 chiffres
    QRegularExpression regexSalaire("^[0-9]+$"); // Salaire doit être un nombre

    // Vérifications des champs
    if (id_employe.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'employé est obligatoire.");
        return;
    }
    if (!regexNomPrenom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres.");
        return;
    }
    if (!regexNomPrenom.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le prénom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTel.match(telStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }
    if (genre.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un genre.");
        return;
    }
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'adresse ne peut pas être vide.");
        return;
    }
    if (!regexNomPrenom.match(specialite).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La spécialité ne doit contenir que des lettres.");
        return;
    }
    if (!regexSalaire.match(salaireStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le salaire doit être un nombre.");
        return;
    }

    // Conversion du téléphone et du salaire en entier après validation
    int tel = telStr.toInt();
    int salaire = salaireStr.toInt();

    // Création de l'employé après validation
    Employe temploye(id_employe, nom, prenom, tel, genre, adresse, specialite, salaire,email);

    // Ajout dans la base de données
    bool test = temploye.ajouter();
    if (test)
    {
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
        ui->tableView->setModel(temploye.afficher());

        // Réinitialisation des champs
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear(); // Réinitialisation du champ salaire
        ui->comboBox_2->setCurrentIndex(-1);
        ui->email->clear();
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }
}

// Fonction pour afficher les employés
void user::on_pushButton_3_clicked()
{
    ui->tableView->setModel(temploye.afficher()); // Rafraîchir la table
}

// Fonction pour supprimer un employé
void user::on_pushButton_2_clicked()
{
    QString id_employe = ui->supprimer->text();
    QMessageBox msgbox;
    msgbox.setWindowTitle("Supprimer");
    msgbox.setText("Voulez-vous supprimer cet employé ?");
    msgbox.setStandardButtons(QMessageBox::Yes);
    msgbox.addButton(QMessageBox::No);

    if (msgbox.exec() == QMessageBox::Yes)
    {
        bool test = temploye.supprimer(id_employe);

        if (test)
        {
            ui->tableView->setModel(temploye.afficher());
            ui->supprimer->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                                  QObject::tr("Erreur.\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }
    else
    {
        ui->tableView->setModel(temploye.afficher());
    }
}

// Fonction pour modifier un employé
void user::on_modifier_clicked()
{
    QString id_employe = ui->lineEdit->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    int tel = ui->lineEdit_4->text().toInt();
    QString genre = ui->comboBox_2->currentText();
    QString adresse = ui->lineEdit_5->text();
    QString specialite = ui->lineEdit_6->text();
    int salaire = ui->lineEdit_7->text().toInt(); // Récupération du salaire
    QString email = ui->email->text();

    // Vérification de l'ID
    if (id_employe.isEmpty()) {
        QMessageBox::information(nullptr, QObject::tr("Aucun ID saisi"),
                                 QObject::tr("Veuillez saisir un ID pour modifier."), QMessageBox::Ok);
        return;
    }

    bool test = temploye.modifier(id_employe, nom, prenom, tel, genre, adresse, specialite, salaire,email);

    if (test) {
        ui->tableView->setModel(temploye.afficher()); // Rafraîchir la vue
        // Réinitialisation des champs
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear(); // Réinitialisation du champ salaire
        ui->comboBox_2->setCurrentIndex(-1);
        ui->email->clear();

        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                                 QObject::tr("Modification réussie."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                              QObject::tr("Erreur lors de la modification.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}



void user::on_recherche_textChanged(const QString &arg1)
{
    QString critere = ui->comboBox_3->currentText();
    QString colonne;

    if (critere == "nom") {
        colonne = "nom";
    } else if (critere == "prenom") {
        colonne = "prenom";
    } else if (critere == "id") {
        colonne = "id_employe"; // Mets ici le vrai nom de ta colonne ID dans la base
    } else {
        // Si rien sélectionné, on affiche tout
        ui->tableView->setModel(temploye.afficher());
        return;
    }

    ui->tableView->setModel(temploye.rechercher(colonne, arg1));
}



void user::on_pushButton_clicked()
{

    ui->combo_stat->setVisible(true); // Cacher le QComboBox au démarrage

}


void user::on_Pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty())
    {
        return; // Si l'utilisateur annule, on ne fait rien
    }
    Employe e; // Créez un objet employé
    QSqlQueryModel *model = e.afficher(); // Récupérer les données des employés (afficher)
    if (e.exporterPDF(filePath, model))
    {
        QMessageBox::information(this, "PDF généré", "Le fichier PDF a été créé avec succès !");
    }
    else {
        QMessageBox::critical(this, "Erreur", "Échec de la création du fichier PDF.");
    }
}



void user::on_pushButton_5_clicked()
{
    chat chatDialog;
    chatDialog.setModal(true);
    chatDialog.exec();

}






void user::on_trier_currentTextChanged(const QString &critere)
{
    QString colonne;

    if (critere == "salaire") {
        colonne = "salaire";
    } else if (critere == "genre") {
        colonne = "genre";
    } else if (critere == "spécialité") {
        colonne = "specialite";
    } else {
        // Aucun tri ou texte non reconnu → affichage normal
        ui->tableView->setModel(temploye.afficher());
        return;
    }

    // Appliquer le tri selon la colonne sélectionnée
    ui->tableView->setModel(temploye.trier_par(colonne));
}

void user::on_combo_stat_currentTextChanged(const QString &critere)
{

    if (critere == "stat selon") {
        return; // Ne rien faire pour l'option par défaut
    }

    QPieSeries *series = new QPieSeries();
    QSqlQuery query;

    // Variables pour compter les tranches de salaire
    int count1 = 0; // pour < 1000
    int count2 = 0; // pour 1000-2000
    int count3 = 0; // pour > 2000

    // Préparer la requête selon le critère
    if (critere == "Genre") {
        query.exec("SELECT genre, COUNT(*) FROM employe GROUP BY genre");
        // Remplir la série pour le genre
        while (query.next()) {
            QString label = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(label, count);
        }
    }
    else if (critere == "Spécialité") {
        query.exec("SELECT specialite, COUNT(*) FROM employe GROUP BY specialite");
        // Remplir la série pour la spécialité
        while (query.next()) {
            QString label = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(label, count);
        }
    }
    else if (critere == "Salaire") {
        query.exec("SELECT salaire FROM employe");

        // Calcul des tranches de salaire dans le code
        while (query.next()) {
            int salaire = query.value(0).toInt();

            if (salaire < 1000) {
                count1++;
            } else if (salaire >= 1000 && salaire <= 2000) {
                count2++;
            } else if (salaire > 2000) {
                count3++;
            }
        }

        // Ajouter les tranches de salaire au graphique
        series->append("< 1000", count1);
        series->append("1000-2000", count2);
        series->append("> 2000", count3);
    }

    // Afficher les labels sur le graphique
    series->setLabelsVisible(true);

    // Ajouter des couleurs personnalisées (optionnel)
    QList<QColor> couleurs = {Qt::cyan, Qt::magenta, Qt::yellow, Qt::green, Qt::red, Qt::blue};
    int i = 0;
    for (auto slice : series->slices()) {
        slice->setBrush(couleurs[i % couleurs.size()]);
        ++i;
    }

    // Créer et configurer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des employés par " + critere);
    chart->setTitleFont(QFont("Arial", 12, QFont::Bold));
    chart->setTitleBrush(QBrush(Qt::darkBlue));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::SeriesAnimations); // Animation douce

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // S'assurer que le layout existe
    if (!ui->stat->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat);
        ui->stat->setLayout(layout);
    }

    // Nettoyer l'ancien graphique s’il existe
    QLayoutItem *child;
    while ((child = ui->stat->layout()->takeAt(0)) != nullptr) {
        if (child->widget())
            delete child->widget();
        delete child;
    }

    // Ajouter le nouveau graphique à l'interface
    ui->stat->layout()->addWidget(chartView);
}
void user::setupSerial()
{
    serialCom = new SerialCommunication(this);
    connect(serialCom, &SerialCommunication::uidReceived, this, &user::checkUidInDatabase);
    serialCom->start();
}
void user::checkUidInDatabase(const QString &uid)
{
    qDebug() << "UID received: " << uid;

    // Clean up the UID by removing the prefix (if present)
    QString cleanedUid = uid.trimmed();
    if (cleanedUid.startsWith("UID reçu : ")) {
        cleanedUid = cleanedUid.mid(11);  // Remove the prefix "UID reçu : "
    }

    qDebug() << "Cleaned UID: " << cleanedUid;

    // Ensure the UID is valid (8 characters long)
    if (cleanedUid.isEmpty() || cleanedUid.length() != 8) {
        qDebug() << "Invalid UID received: " << cleanedUid;
        serialCom->sendMessage("Refuse");  // Send "Refuse" for invalid UID
        return;  // Don't process further
    }

    // Prepare the SQL query to check if the UID exists in the database
    QSqlQuery query;
    query.prepare("SELECT RFID_UID FROM EMPLOYE WHERE UPPER(RFID_UID) = :uid");
    query.bindValue(":uid", cleanedUid);  // Use the cleaned UID directly

    if (query.exec()) {
        if (query.next()) {
            // If a matching UID is found
            qDebug() << "UID authorized: " << cleanedUid;
            serialCom->sendMessage("Autorise");  // Send "Autorise" message to Arduino
        } else {
            // If no matching UID is found
            qDebug() << "UID not authorized: " << cleanedUid;
            serialCom->sendMessage("Refuse");   // Send "Refuse" message to Arduino
        }
    } else {
        qDebug() << "Query execution error: " << query.lastError().text();
        serialCom->sendMessage("Refuse");  // Send "Refuse" on query error
    }
}
void user::handleUidFromArduino(const QString &uid) {
    // Exemple : boîte de dialogue d'acceptation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Accès RFID", "UID détecté : " + uid + "\nAutoriser l'accès ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        serialCom->sendMessage("Autorise");
    } else {
        serialCom->sendMessage("Refuse");
    }
}


void user::handleUidAuthorized(const QString &uid) {
    // Implémentation de ta fonction pour gérer l'UID autorisé
    qDebug() << "UID autorisé : " << uid;
    // Ajoute ici le code nécessaire pour manipuler l'UID autorisé
}
void user::loadEmployees()
{
    // Exécuter la requête SQL pour récupérer les employés
    QSqlQuery query("SELECT ID_EMPLOYE, NOM FROM EMPLOYE");

    // Ajouter chaque employé dans le ComboBox
    while (query.next()) {
        QString employeeId = query.value("ID_EMPLOYE").toString();
        QString employeeName = query.value("NOM").toString();

        // Ajouter l'employé au ComboBox (afficher le nom mais utiliser l'ID comme donnée)
        ui->employeeComboBox->addItem(employeeName, employeeId);
    }
}
void user::addUidToEmployee()
{
    // Récupérer l'UID entré et l'ID de l'employé sélectionné
    QString uid = ui->uidLineEdit->text().trimmed();
    QString employeeId = ui->employeeComboBox->currentData().toString();

    // Vérifier si l'UID n'est pas vide
    if (uid.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un UID valide.");
        return;
    }

    // Préparer la requête SQL pour mettre à jour l'UID de l'employé
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET RFID_UID = :uid WHERE ID_EMPLOYE = :employeeId");
    query.bindValue(":uid", uid);
    query.bindValue(":employeeId", employeeId);

    // Exécuter la requête et vérifier le succès
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "L'UID a été assigné à l'employé.");
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'assigner l'UID à l'employé.");
    }
}





void user::on_btnpatient_clicked()
{
    patie *p=new patie();
    p->show();
    this->hide();

}


void user::on_btnequipement_clicked()
{
    equip *e = new equip();
    e->show();
    this->hide();
}


void user::on_btnformation_clicked()
{
    forma *f= new forma();
    f->show();
    this->hide();

}


void user::on_btnrecherche_clicked()
{
    projet *r=new projet();
    r->show();
    this->hide();

}


void user::on_btnvaccins_clicked()
{
    MainWindow *v=new MainWindow();
    v->show();
    this->hide();

}


void user::on_logout_clicked()
{
    login *l=new login();
    l->show();
    this->hide();
}

