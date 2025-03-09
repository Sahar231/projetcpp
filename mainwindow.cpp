#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configuration de l'interface
    QPalette palette;
    QPixmap pixmap("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/back55.jpg");
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
    ui->logo->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/logo9.png"));
    ui->logo->setIconSize(QSize(161, 91));
    ui->logo->setStyleSheet(commonButtonStyle);

    ui->btnemploye->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);

    ui->btnpatient->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);

    ui->btnvaccins->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);

    ui->btnequipement->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);

    ui->btnformation->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);

    ui->btnrecherche->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);
    ui->logout->setStyleSheet(commonButtonStyle);

    ui->rech->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/reche.png"));
    ui->rech->setIconSize(QSize(91, 31));
    ui->rech->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->pdf->setIcon(QIcon("C:/Users/21692/Downloads/Qt/Qt/interfce/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->pdf_2->setIcon(QIcon("C:/Users/yousfi islem/Desktop/Qt/Qt/interfce/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

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

    // Connexion des boutons
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifier_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Fonction pour ajouter un employé
void MainWindow::on_pushButton_4_clicked()
{
    QString id_employe = ui->lineEdit->text().trimmed();
    QString nom = ui->lineEdit_2->text().trimmed();
    QString prenom = ui->lineEdit_3->text().trimmed();
    QString telStr = ui->lineEdit_4->text().trimmed();
    QString genre = ui->comboBox_2->currentText().trimmed();
    QString adresse = ui->lineEdit_5->text().trimmed();
    QString specialite = ui->lineEdit_6->text().trimmed();
    QString salaireStr = ui->lineEdit_7->text().trimmed(); // Nouveau champ pour le salaire

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
    employe temploye(id_employe, nom, prenom, tel, genre, adresse, specialite, salaire);

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
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }
}

// Fonction pour afficher les employés
void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setModel(temploye.afficher()); // Rafraîchir la table
}

// Fonction pour supprimer un employé
void MainWindow::on_pushButton_2_clicked()
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
void MainWindow::on_modifier_clicked()
{
    QString id_employe = ui->lineEdit->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    int tel = ui->lineEdit_4->text().toInt();
    QString genre = ui->comboBox_2->currentText();
    QString adresse = ui->lineEdit_5->text();
    QString specialite = ui->lineEdit_6->text();
    int salaire = ui->lineEdit_7->text().toInt(); // Récupération du salaire

    // Vérification de l'ID
    if (id_employe.isEmpty()) {
        QMessageBox::information(nullptr, QObject::tr("Aucun ID saisi"),
                                 QObject::tr("Veuillez saisir un ID pour modifier."), QMessageBox::Ok);
        return;
    }

    bool test = temploye.modifier(id_employe, nom, prenom, tel, genre, adresse, specialite, salaire);

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

        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                                 QObject::tr("Modification réussie."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                              QObject::tr("Erreur lors de la modification.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
