#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"  // Include Patient class
#include <QString>
#include <QMessageBox>
#include <QDebug>      // For debugging

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_rowSelected(QModelIndex)));


    QPalette palette;
    QPixmap pixmap("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/back55.jpg");
    palette.setBrush(QPalette::Window, pixmap);
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);

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

    ui->logo->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);

    ui->comboBox->addItem("Homme ");
    ui->comboBox->addItem("Femme");

    ui->btnemploye->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);

    ui->btnpatient->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);

    ui->btnvaccins->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);

    ui->btnequipement->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);

    ui->btnformation->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);

    ui->btnrecherche->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);

    ui->logout->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->logout->setStyleSheet(commonButtonStyle);

    ui->rech->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/reche.png"));
    ui->rech->setIconSize(QSize(91, 31));
    ui->rech->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->pdf->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->pdf_2->setIcon(QIcon("c:/Users/Amari Aziz/Desktop/InterfaceQT/interface/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->recherche->setPlaceholderText("Rechercher un Patient par ... ");



    ui->supprimer->setPlaceholderText("ID");

    ui->trier->addItem("Trier par");
    ui->trier->addItem("DateN");

    ui->comboBox_3->addItem("Nom");
    ui->comboBox_3->addItem("Prénom");
    ui->comboBox_3->addItem("IDP");
    ui->comboBox_3->addItem("NumT");

    // ✅ Display patients when the app starts
    displayPatients();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ================== 🚀 ADD PATIENT FUNCTION 🚀 ==================
void MainWindow::on_pushButton_4_clicked()
{
    // Retrieve input values from UI
    QString id_patient = ui->lineEdit->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString adresse = ui->lineEdit_4->text();
    QString email = ui->lineEdit_5->text();
    QString numT = ui->lineEdit_6->text();
    QDate dateN = ui->dateEdit->date();
    QString genre = ui->comboBox->currentText();
    QString description = ui->textEdit->toPlainText();

    // ===== VALIDATIONS =====
    if (id_patient.isEmpty() || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || email.isEmpty() || numT.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    if (numT.length() != 8 || !numT.toLongLong()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return;
    }

    if (!email.contains('@')) {
        QMessageBox::warning(this, "Erreur", "L'adresse email doit contenir '@' !");
        return;
    }

    // ===== INSERT INTO DATABASE =====
    Patient p;
    bool success = p.addPatient(id_patient, nom, prenom, adresse, email, numT, dateN, genre, description);

    if (success) {
        QMessageBox::information(this, "Succès", "Patient ajouté avec succès !");
        displayPatients(); // ✅ Refresh table after adding a patient
    } else {
        QMessageBox::warning(this, "Erreur", "L'ajout du patient a échoué.");
    }
}


// ================== ✅ DISPLAY PATIENTS FUNCTION ✅ ==================
void MainWindow::displayPatients()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id_patient, nom, prenom, adresse, email, numT, dateN, genre, description FROM Patients");
    ui->tableView->setModel(model);
}
// ✅ Selects a row when clicking on tableView
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        selectedPatientId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    }
}

// ✅ Deletes the selected patient
void MainWindow::on_pushButton_2_clicked()
{
    if (selectedPatientId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un patient à supprimer !");
        return;
    }

    Patient p;
    bool success = p.deletePatient(selectedPatientId);

    if (success) {
        QMessageBox::information(this, "Succès", "Patient supprimé avec succès !");
        displayPatients(); // Refresh table after deletion
        selectedPatientId.clear(); // Reset selected ID
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression du patient.");
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if (selectedPatientId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un patient à modifier !");
        return;
    }

    // Retrieve new input values
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString adresse = ui->lineEdit_4->text();
    QString email = ui->lineEdit_5->text();
    QString numT = ui->lineEdit_6->text();
    QDate dateN = ui->dateEdit->date();
    QString genre = ui->comboBox->currentText();
    QString description = ui->textEdit->toPlainText();

    // Call update function
    Patient p;
    bool success = p.updatePatient(selectedPatientId, nom, prenom, adresse, email, numT, dateN, genre, description);

    if (success) {
        QMessageBox::information(this, "Succès", "Patient modifié avec succès !");
        displayPatients(); // Refresh table
        selectedPatientId.clear(); // Reset selected ID
    } else {
        QMessageBox::warning(this, "Erreur", "La modification du patient a échoué !");
    }
}
void MainWindow::on_tableView_rowSelected(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();

    selectedPatientId = model->data(model->index(row, 0)).toString();
    ui->lineEdit->setText(selectedPatientId);
    ui->lineEdit_2->setText(model->data(model->index(row, 1)).toString());
    ui->lineEdit_3->setText(model->data(model->index(row, 2)).toString());
    ui->lineEdit_4->setText(model->data(model->index(row, 3)).toString());
    ui->lineEdit_5->setText(model->data(model->index(row, 4)).toString());
    ui->lineEdit_6->setText(model->data(model->index(row, 5)).toString());
    ui->dateEdit->setDate(model->data(model->index(row, 6)).toDate());
    ui->comboBox->setCurrentText(model->data(model->index(row, 7)).toString());
    ui->textEdit->setPlainText(model->data(model->index(row, 8)).toString());
}


