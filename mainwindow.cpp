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
#include <QPrinter>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Recherche");

    ui->Rc_TableView_Res->setModel(R.afficher());
    ui->RC_combo_ID->setModel(R.afficher_id());
    populateComboBoxes();
    // Display text: user-friendly, underlying data: real column name
    ui->Rc_comboBox->clear();
    ui->Rc_comboBox->addItem("NOM", "NOM_RECH");
    ui->Rc_comboBox->addItem("TYPE", "TYPE_RECH");
    ui->Rc_comboBox->addItem("STATUT", "STATUT");






    QPalette palette;
    QPixmap pixmap("C:/Users/slimc/Desktop/projetcpp/back55.jpg");
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




    ui->logo->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);


    ui->btnemploye->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);
    ui->btnpatient->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);
    ui->btnvaccins->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);
    ui->btnequipement->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);
    ui->btnformation->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);
    ui->btnrecherche->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->logout->setIcon(QIcon("C:/Users/slimc/Desktop/projetcpp/logout1.png"));
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
    int idRech = ui->RC_combo_ID->currentText().toInt();

    // 🔍 Vérification si la recherche est liée à un vaccin
    QSqlQuery check;
    check.prepare("SELECT COUNT(*) FROM VACCINS WHERE ID_RECH = :id");
    check.bindValue(":id", idRech);

    if (check.exec() && check.next()) {
        int count = check.value(0).toInt();
        if (count > 0) {
            ui->Rc_Label_InfoAffichage->setText("❌ Impossible de supprimer : cette recherche est liée à un vaccin.");
            return;
        }
    } else {
        ui->Rc_Label_InfoAffichage->setText("❌ Erreur lors de la vérification dans la table VACCINS.");
        return;
    }

    // ✅ Suppression autorisée
    Recherche R;
    R.setIdRech(idRech);
    bool test = R.supprimer(R.getIdRech());
    if (test) {
        ui->Rc_Label_InfoAffichage->setText("✅ Suppression effectuée.");
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        clearFields();
        populateComboBoxes(); // Mise à jour des listes déroulantes
    } else {
        ui->Rc_Label_InfoAffichage->setText("❌ Suppression non effectuée.");
    }
}

void MainWindow::on_Rc_push_Modifier_clicked()
{
    QString idRechString = ui->Rc_id_field->text().trimmed();
    QString nomRech = ui->Rc_nom_field->text().trimmed();
    QString typeRech = ui->Rc_type_field->text().trimmed();
    QDate dateRech = ui->Rc_date_field->date();
    QString statut = ui->Rc_statut_combo->currentText().trimmed();
    QString idEmployeString = ui->Rc_employe_combox->currentText().trimmed();

    // Vérification des champs
    if (idRechString.isEmpty() || nomRech.isEmpty() || typeRech.isEmpty() || statut.isEmpty() || idEmployeString.isEmpty()) {
        ui->Rc_Label_InfoAffichage->setText("⚠️ Tous les champs doivent être remplis.");
        return;
    }

    bool ok;
    int idRech = idRechString.toInt(&ok);
    if (!ok || idRech <= 0) {
        ui->Rc_Label_InfoAffichage->setText("❌ L'ID doit être un entier valide.");
        return;
    }

    int idEmploye = idEmployeString.toInt(&ok);
    if (!ok || idEmploye <= 0) {
        ui->Rc_Label_InfoAffichage->setText("❌ L'ID employé n'est pas valide.");
        return;
    }

    Recherche R(idRech, nomRech, typeRech, dateRech, statut, idEmploye);
    bool test = R.modifier();

    if (test) {
        ui->Rc_Label_InfoAffichage->setText("✅ Modification réussie (ID: " + QString::number(idRech) + ")");
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        clearFields();
        populateComboBoxes();
    } else {
        ui->Rc_Label_InfoAffichage->setText("❌ Modification non effectuée. L'ID existe-t-il ?");
    }
}


void MainWindow::on_Rc_push_Ajouter_clicked()
{
    QString idRechString = ui->Rc_id_field->text().trimmed();
    QString nomRech = ui->Rc_nom_field->text().trimmed();
    QString typeRech = ui->Rc_type_field->text().trimmed();
    QDate dateRech = ui->Rc_date_field->date();
    QString statut = ui->Rc_statut_combo->currentText().trimmed();
    QString idEmployeString = ui->Rc_employe_combox->currentText().trimmed();

    // Vérification de tous les champs obligatoires
    if (idRechString.isEmpty() || nomRech.isEmpty() || typeRech.isEmpty() || statut.isEmpty() || idEmployeString.isEmpty()) {
        ui->Rc_Label_InfoAffichage->setText("⚠️ Tous les champs doivent être remplis.");
        return;
    }

    bool ok;
    int idRech = idRechString.toInt(&ok);
    if (!ok || idRech <= 0) {
        ui->Rc_Label_InfoAffichage->setText("❌ L'ID doit être un entier valide supérieur à 0.");
        return;
    }

    int idEmploye = idEmployeString.toInt(&ok);
    if (!ok || idEmploye <= 0) {
        ui->Rc_Label_InfoAffichage->setText("❌ L'ID employé doit être un entier valide.");
        return;
    }

    // Création et insertion
    Recherche R(idRech, nomRech, typeRech, dateRech, statut, idEmploye);
    bool test = R.ajouter();

    if (test) {
        ui->Rc_Label_InfoAffichage->setText("✅ Ajout effectué avec succès (ID: " + QString::number(idRech) + ")");
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        clearFields();
        populateComboBoxes();
    } else {
        ui->Rc_Label_InfoAffichage->setText("❌ Échec de l'ajout. L'ID existe peut-être déjà.");
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

void MainWindow::on_Rc_Button_Tri_Nom_clicked()
{
     ui->Rc_Label_InfoAffichage->setText("Tri par NOM effectué");
     ui->Rc_TableView_Res->setModel(R.Afficher_Tri_NOM());
}


void MainWindow::on_Rc_Button_Tri_Type_clicked()
{
    ui->Rc_Label_InfoAffichage->setText("Tri par TYPE effectué");
    ui->Rc_TableView_Res->setModel(R.Afficher_Tri_TYPE());
}

void MainWindow::on_Rc_Button_Tri_Statut_clicked()
{
    ui->Rc_Label_InfoAffichage->setText("Tri par STATUT effectué");
    ui->Rc_TableView_Res->setModel(R.Afficher_Tri_STATUT());
}

void MainWindow::on_Rc_Line_Recherche_textChanged(const QString &arg1)
{
     QString critere = ui->Rc_comboBox->currentData().toString(); // should contain column names like "NOM_RECH", "TYPE_RECH", "STATUT"
        R.clearTable(ui->Rc_TableView_Res);
        R.Rechercher(ui->Rc_TableView_Res, arg1, critere);
}

void MainWindow::on_Rc_Button_ExportPDF_clicked()
{

        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->Rc_TableView_Res->model()->rowCount();
        const int columnCount = ui->Rc_TableView_Res->model()->columnCount();

        out << "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << QString("<title>%1</title>\n").arg("Export PDF")
            << "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
               "<center><H1>Liste des Recherches</H1><br><br>\n"
               "<table border=1 cellspacing=0 cellpadding=2>\n";

        // Table headers
        out << "<thead><tr bgcolor=#f0f0f0><th>Numero</th>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->Rc_TableView_Res->isColumnHidden(column)) {
                out << QString("<th>%1</th>").arg(ui->Rc_TableView_Res->model()->headerData(column, Qt::Horizontal).toString());
            }
        }
        out << "</tr></thead>\n";

        // Table rows
        for (int row = 0; row < rowCount; row++) {
            out << "<tr><td>" << row + 1 << "</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->Rc_TableView_Res->isColumnHidden(column)) {
                    QString data = ui->Rc_TableView_Res->model()->data(ui->Rc_TableView_Res->model()->index(row, column)).toString().simplified();
                    out << QString("<td>%1</td>").arg(data.isEmpty() ? "&nbsp;" : data);
                }
            }
            out << "</tr>\n";
        }

        out << "</table></center>\n</body>\n</html>\n";

        QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".pdf");

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size());
        doc.print(&printer);


}
