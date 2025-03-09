#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileDialog>
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QUrlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Recherche");

    ui->Rc_TableView_Res->setModel(R.afficher());
    ui->RC_combo_ID->setModel(R.afficher_id());
    populateComboBoxes();





    QPalette palette;
    QPixmap pixmap("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/back55.jpg");
    palette.setBrush(QPalette::Window,  pixmap);
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);
    QString commonButtonStyle =
        "QPushButton {"
        "   border: 0.5px solid black;"
        "   border-radius: 5px;"
        "   padding: 10px;"
        "   font-weight: bold;"             // Texte en gras
        "   font-size: 14px;"

        "}"
        "QPushButton:hover, QPushButton:pressed {"
        "   background-color: #D3D3D3;"
        "   border: 0.5px solid black;"
        "}";
   /* ui->groupBox->setStyleSheet(
    "QGroupBox {"

    "border: 0.5px solid black;"
    "border-radius: 5px;"
    "padding: 10px;"
    "}"
    "QLineEdit { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
    "QspinBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
    "QComboBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"

        "}");*/




    ui->logo->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);


    ui->btnemploye->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);
    ui->btnpatient->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);
    ui->btnvaccins->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);
    ui->btnequipement->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);
    ui->btnformation->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);
    ui->btnrecherche->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("C:/Users/slimc/OneDrive/Documents/GitHub/projetcpp/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);
    ui->logout->setStyleSheet(commonButtonStyle);


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateComboBoxes()
{
    // Populate Rc_employe_combox with IDs from EMPLOYES table
    QSqlQuery queryEmploye;
    queryEmploye.prepare("SELECT ID_EMP FROM EMPLOYES"); // Fixed table & column name
    if (queryEmploye.exec()) {
        ui->Rc_employe_combox->clear();
        while (queryEmploye.next()) {
            ui->Rc_employe_combox->addItem(queryEmploye.value(0).toString());
        }
    } else {
        qDebug() << "Failed to populate Rc_employe_combox:" << queryEmploye.lastError().text();
    }

    // Populate Rc_statut_combox with predefined values
    ui->Rc_statut_combo->clear();
    ui->Rc_statut_combo->addItem("En cours");
    ui->Rc_statut_combo->addItem("Terminé");
    ui->Rc_statut_combo->addItem("Annulé");
}




void MainWindow::clearFields()
{
    // Clear all QLineEdit fields
    ui->Rc_id_field->clear();
    ui->Rc_nom_field->clear();
    ui->Rc_type_field->clear();

    // Reset QDateEdit field to a default date (e.g., current date)
    ui->Rc_date_field->setDate(QDate::currentDate());

    // Reset combo boxes to default (e.g., first item or clear)
    if (ui->Rc_statut_combo->count() > 0) ui->Rc_statut_combo->setCurrentIndex(0);
    if (ui->Rc_employe_combox->count() > 0) ui->Rc_employe_combox->setCurrentIndex(0);
}

void MainWindow::on_Rc_push_Supprimer_clicked()
{
    Recherche R;
    R.setIdRech(ui->RC_combo_ID->currentText().toInt());
    bool test = R.supprimer(R.getIdRech());
    if (test) {
        ui->Rc_Label_InfoAffichage->setText("Suppression Effectuée");
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        clearFields();
        populateComboBoxes(); // Refresh combo boxes after deletion
    } else {
        ui->Rc_Label_InfoAffichage->setText("Suppression non effectuée");
    }

}

void MainWindow::on_Rc_push_Modifier_clicked()
{
    int idRech = ui->Rc_id_field->text().toInt();
    QString nomRech = ui->Rc_nom_field->text();
    QString typeRech = ui->Rc_type_field->text();
    QDate dateRech = ui->Rc_date_field->date();
    QString statut = ui->Rc_statut_combo->currentText(); // Changed to use Rc_statut_combox
    int idEmploye = ui->Rc_employe_combox->currentText().toInt(); // Corrected to Rc_employe_combox
    QString idRechString = ui->Rc_id_field->text();

    if (idRechString.isEmpty() || idRech == 0 || nomRech.isEmpty() || typeRech.isEmpty() || statut.isEmpty()) {
        ui->Rc_Label_InfoAffichage->setText("Erreur de contrôle de saisie");
        return;
    }

    Recherche R(idRech, nomRech, typeRech, dateRech, statut, idEmploye);
    bool test = R.modifier();
    if (test) {
        ui->Rc_Label_InfoAffichage->setText("Modification Effectuée ID: " + QString::number(idRech));
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        clearFields();
        populateComboBoxes(); // Refresh combo boxes after modification
    } else {
        ui->Rc_Label_InfoAffichage->setText("Modification non effectuée");
    }
}

void MainWindow::on_Rc_push_Ajouter_clicked()
{
    int idRech = ui->Rc_id_field->text().toInt();
    QString nomRech = ui->Rc_nom_field->text();
    QString typeRech = ui->Rc_type_field->text();
    QDate dateRech = ui->Rc_date_field->date();
    QString statut = ui->Rc_statut_combo->currentText(); // Changed to use Rc_statut_combox
    int idEmploye = ui->Rc_employe_combox->currentText().toInt(); // Corrected to Rc_employe_combox
    QString idRechString = ui->Rc_id_field->text();

    if (idRechString.isEmpty() || idRech == 0 || nomRech.isEmpty() || typeRech.isEmpty() || statut.isEmpty()) {
        ui->Rc_Label_InfoAffichage->setText("Erreur de contrôle de saisie");
        return;
    }

    Recherche R(idRech, nomRech, typeRech, dateRech, statut, idEmploye);
    ui->Rc_Label_InfoAffichage->setText("Ajout Effectué ID: " + QString::number(idRech));
    bool test = R.ajouter();
    if (test) {
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        clearFields();
        populateComboBoxes(); // Refresh combo boxes after addition
    } else {
        ui->Rc_Label_InfoAffichage->setText("Ajout non effectué");
    }

}

void MainWindow::on_RC_combo_ID_currentIndexChanged(int index)
{
    int idRech = ui->RC_combo_ID->currentText().toInt();
    QString idRechString = QString::number(idRech);
    QSqlQuery query;
    query.prepare("SELECT * FROM RECHERCHES WHERE ID_RECH = :ID_RECH");
    query.bindValue(":ID_RECH", idRech);
    if (query.exec()) {
        while (query.next()) {
            ui->Rc_id_field->setText(query.value(0).toString());
            ui->Rc_nom_field->setText(query.value(1).toString());
            ui->Rc_type_field->setText(query.value(2).toString());
            ui->Rc_date_field->setDate(query.value(3).toDate());
            ui->Rc_statut_combo->setCurrentText(query.value(4).toString()); // Set statut combo box
            ui->Rc_employe_combox->setCurrentText(query.value(5).toString()); // Set employe combo box
        }
    } else {
        ui->Rc_Label_InfoAffichage->setText("Échec de chargement");
    }

}
