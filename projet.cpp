#include "projet.h"
#include "ui_projet.h"
#include "login.h"
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
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>
#include <QTextDocument>
#include "stati.h"
#include <QSortFilterProxyModel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QDebug>
#include <QInputDialog>
#include <QSettings>
#include <functional>
#include "ard.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include "equip.h"
#include "form.h"
#include "patie.h"
#include "user.h"

#include "mainwindow.h"



projet::projet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::projet),
    manager(new QNetworkAccessManager(this)),
    model(new QStringListModel(this))
{
    ui->setupUi(this);
    // Initialize Arduino connection using the Arduino class
    if (A.connect_arduino() == 0) {
        qDebug() << "Arduino connection opened successfully on port:" << A.getarduino_port_name();
    } else {
        qDebug() << "Failed to open Arduino port";
        QMessageBox::warning(this, "Serial Port Error",
                             "Failed to open serial port. Please check your Arduino connection.");
    }

    // Connect the readyRead signal to update_label slot
    QObject::connect(A.getserial(), &QSerialPort::readyRead, this, &projet::update_label);

    setWindowTitle("Recherche");
    ui->Rc_TableView_Res->setModel(R.afficher());
    ui->RC_combo_ID->setModel(R.afficher_id());
    populateComboBoxes();

    // Set initial language to French
    currentLanguage = "fr";

    // Display text: user-friendly, underlying data: real column name
    ui->Rc_comboBox->clear();
    ui->Rc_comboBox->addItem("NOM", "NOM_RECH");
    ui->Rc_comboBox->addItem("TYPE", "TYPE_RECH");
    ui->Rc_comboBox->addItem("STATUT", "STATUT");
    ui->tableView_Recherche->setModel(model);


    connect(ui->push_recherche, &QPushButton::clicked, this, &projet::onSearchClicked);
    connect(manager, &QNetworkAccessManager::finished, this, &projet::onApiResult, Qt::UniqueConnection);
    connect(ui->Rc_Line_Recherche, &QLineEdit::textChanged, this, &projet::on_Rc_Line_Recherche_textChanged);
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,QCoreApplication::organizationName(), QCoreApplication::applicationName());
    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.bing.com/maps?FORM=Z9LH2&cp=36.9003%7E10.187824&lvl=16.0");
    connect(ui->tableView_Recherche, &QTableView::doubleClicked, this, &projet::on_tableView_Recherche_doubleClicked);
    QString path = QCoreApplication::applicationDirPath() + "/translations.json";
    loadTranslations(path);
    QPalette palette;
    QPixmap pixmap("c:/Users/Sahar/Bureau/project/integration/back55.jpg");
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





    ui->logo->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/logo9.png"));

    ui->logo->setIconSize(QSize(150, 150));
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



}


void  projet::populateComboBoxes()
{
    // Populate Rc_employe_combox with IDs from EMPLOYES table
    QSqlQuery queryEmploye;
    queryEmploye.prepare("SELECT ID_EMPLOYE FROM EMPLOYE"); // Fixed table & column name
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
    ui->Rc_statut_combo->addItem("En Cours");
    ui->Rc_statut_combo->addItem("Termine");
    ui->Rc_statut_combo->addItem("Annule");
}

void projet::clearFields()
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

void projet::on_Rc_push_Supprimer_clicked()
{
    bool ok;
    int ID = ui->RC_combo_ID->currentText().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un ID valide.");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              "Êtes-vous sûr de vouloir supprimer cette recherche?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        bool test = R.supprimer(ID);
        if (test) {
            ui->Rc_TableView_Res->setModel(R.afficher());
            ui->RC_combo_ID->setModel(R.afficher_id());
            QMessageBox::information(this, "Succès", "Recherche supprimée avec succès!");
            clearFields();

            // Apply translations after deletion
            applyTableTranslations();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de la recherche.");
        }
    }
}

void projet::on_Rc_push_Modifier_clicked()
{
    bool ok;
    int ID = ui->RC_combo_ID->currentText().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un ID valide.");
        return;
    }

    QString Nom = ui->Rc_nom_field->text();
    QString Type = ui->Rc_type_field->text();
    QDate Date = ui->Rc_date_field->date();
    QString Statut = ui->Rc_statut_combo->currentText();
    int ID_emp = ui->Rc_employe_combox->currentText().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID Employé doit être un nombre entier valide.");
        return;
    }

    Recherche r(ID, Nom, Type, Date, Statut, ID_emp,-1);

    bool test = r.modifier();
    if (test) {
        ui->Rc_TableView_Res->setModel(R.afficher());
        QMessageBox::information(this, "Succès", "Recherche modifiée avec succès!");
        clearFields();

        // Apply translations after modification
        applyTableTranslations();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification de la recherche.");
    }
}

void projet::on_Rc_push_Ajouter_clicked()
{
    bool ok;
    int ID = ui->Rc_id_field->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID doit être un nombre entier valide.");
        return;
    }

    QString Nom = ui->Rc_nom_field->text();
    QString Type = ui->Rc_type_field->text();
    QDate Date = ui->Rc_date_field->date();
    QString Statut = ui->Rc_statut_combo->currentText();
    int ID_emp = ui->Rc_employe_combox->currentText().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID Employé doit être un nombre entier valide.");
        return;
    }

    Recherche r(ID, Nom, Type, Date, Statut, ID_emp,-1);

    bool test = r.ajouter();
    if (test) {
        ui->Rc_TableView_Res->setModel(R.afficher());
        ui->RC_combo_ID->setModel(R.afficher_id());
        QMessageBox::information(this, "Succès", "Recherche ajoutée avec succès!");
        clearFields();

        // Apply translations after adding
        applyTableTranslations();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de la recherche.");
    }
}

void projet::on_RC_combo_ID_currentIndexChanged(int index)
{
    if (index == -1) return;

    QString id = ui->RC_combo_ID->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM RECHERCHES WHERE ID_RECH = :id");
    query.bindValue(":id", id);

    if(query.exec() && query.next()) {
        ui->Rc_id_field->setText(id);
        ui->Rc_nom_field->setText(query.value(1).toString());
        ui->Rc_type_field->setText(query.value(2).toString());
        ui->Rc_date_field->setDate(query.value(3).toDate());

        // Set Statut combobox
        QString statut = query.value(4).toString();
        int statutIndex = ui->Rc_statut_combo->findText(statut);
        if (statutIndex != -1) {
            ui->Rc_statut_combo->setCurrentIndex(statutIndex);
        }

        // Set ID_Employe combobox
        QString idEmploye = query.value(5).toString();
        int empIndex = ui->Rc_employe_combox->findText(idEmploye);
        if (empIndex != -1) {
            ui->Rc_employe_combox->setCurrentIndex(empIndex);
        }
    }
}

// Helper method to apply translations to the table headers
void projet::applyTableTranslations()
{
    // If interface is already translated, apply translations to the headers
    if (!currentLanguage.isEmpty() && currentLanguage != "fr") {
        QJsonObject langTranslations = translations[currentLanguage].toObject();
        if (!langTranslations.isEmpty()) {
            QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->Rc_TableView_Res->model());
            if (model) {
                R.retranslateHeaders(model, langTranslations);
            }
        }
    }
}

void projet::on_Rc_Button_Tri_Nom_clicked()
{
    ui->Rc_TableView_Res->setModel(R.Afficher_Tri_NOM());
    applyTableTranslations();
}

void projet::on_Rc_Button_Tri_Type_clicked()
{
    ui->Rc_TableView_Res->setModel(R.Afficher_Tri_TYPE());
    applyTableTranslations();
}

void projet::on_Rc_Button_Tri_Statut_clicked()
{
    ui->Rc_TableView_Res->setModel(R.Afficher_Tri_STATUT());
    applyTableTranslations();
}

void projet::on_Rc_Line_Recherche_textChanged(const QString &arg1)
{
    if (ui->Rc_comboBox->currentText()=="")
    {
        ui->Rc_TableView_Res->setModel(R.afficher());
    }
    else
    {
        QString critere = ui->Rc_comboBox->currentData().toString();  // Get the real column name from the combobox
        R.Rechercher(ui->Rc_TableView_Res, arg1, critere);
    }

    // Apply translations to search results if needed
    applyTableTranslations();
}

void projet::on_Rc_Button_ExportPDF_clicked()
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
           "<center><h1>Liste des Recherches</h1><br><br>\n"
           "<table border=1 cellspacing=0 cellpadding=2>\n";

    // Table headers
    out << "<thead><tr bgcolor=#f0f0f0><th>Numéro</th>";
    for (int column = 0; column < columnCount; ++column) {
        if (!ui->Rc_TableView_Res->isColumnHidden(column)) {
            out << QString("<th>%1</th>").arg(
                ui->Rc_TableView_Res->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // Table data
    for (int row = 0; row < rowCount; ++row) {
        out << "<tr><td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; ++column) {
            if (!ui->Rc_TableView_Res->isColumnHidden(column)) {
                QString data = ui->Rc_TableView_Res->model()
                ->data(ui->Rc_TableView_Res->model()->index(row, column))
                    .toString()
                    .simplified();
                out << QString("<td>%1</td>").arg(data.isEmpty() ? "&nbsp;" : data);
            }
        }
        out << "</tr>\n";
    }

    out << "</table></center>\n</body>\n</html>\n";

    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder en PDF", "", "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}

void projet::on_Rc_Button_Stat_clicked()
{
    stati *st = new stati(this);


    QSize statSize = st->size();
    QPoint mainWindowPos = this->pos();
    QSize mainWindowSize = this->size();


    int x = mainWindowPos.x() + (mainWindowSize.width() - statSize.width()) / 2;
    int y = mainWindowPos.y() + (mainWindowSize.height() - statSize.height()) / 2;

    st->move(x, y);

    // Show the window
    st->show();
}

void projet::onSearchClicked() {
    QString searchTerm = ui->line_recherche->text().trimmed();
    if (searchTerm.isEmpty()) {
        ui->Rc_Label_InfoAffichage->setText("⚠️ Please enter a search term.");
        return;
    }

    // Lien vers l'API
    QString urlString = "https://data.cdc.gov/resource/kh8y-3es6.json";
    QNetworkRequest request;
    request.setUrl(QUrl(urlString));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 🔥 Envoie réellement la requête ici :
    manager->get(request);

    qDebug() << "Sent request to:" << urlString;
    ui->Rc_Label_InfoAffichage->setText("Fetching CDC vaccine data...");
}


void projet::onApiResult(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Network error:" << reply->errorString();
        ui->Rc_Label_InfoAffichage->setText("❌ Network error: " + reply->errorString());
        QMessageBox::warning(this, "API Error", "Failed to fetch data.\nPlease try again later.");
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    qDebug() << "Raw JSON:" << responseData;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        qDebug() << "Invalid JSON or not an array";
        ui->Rc_Label_InfoAffichage->setText("❌ Invalid data format.");
        reply->deleteLater();
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();

    QStandardItemModel *tableModel = new QStandardItemModel(this);
    tableModel->setColumnCount(7);
    tableModel->setHorizontalHeaderLabels({"Provider name", "Type", "Date", "Status", "Payment","City","State"});

    int rowCount = 0;
    for (const QJsonValue &value : jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            QString providerName = obj["provider_name"].toString();
            QString state = obj["state"].toString();
            QString city = obj["city"].toString();
            QString payment = obj["payment"].toString();
            QString nomRech = providerName; // Use provider name as research name
            QString typeRech = ui->line_recherche->text();       // Use state as type
            QString dateRech = "01-JAN-23"; // Placeholder; adjust if API provides dates
            QString statut = payment.contains("$") ? "Funded" : "Unknown"; // Simple mapping

            QList<QStandardItem *> rowItems;
            rowItems << new QStandardItem(nomRech)
                     << new QStandardItem(typeRech)
                     << new QStandardItem(dateRech)
                     << new QStandardItem(statut)
                     << new QStandardItem(payment)
                     << new QStandardItem(city)
                     << new QStandardItem(state);
            tableModel->appendRow(rowItems);
            rowCount++;
        }
    }

    qDebug() << "Rows added to model:" << rowCount;
    if (rowCount == 0) {
        ui->Rc_Label_InfoAffichage->setText("⚠️ No data parsed from API.");
    } else {
        ui->Rc_Label_InfoAffichage->setText("✅ Loaded " + QString::number(rowCount) + " records.");
    }

    // Set up proxy model for filtering
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(tableModel);
    proxyModel->setFilterKeyColumn(-1); // Search all columns
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // Apply the proxy model to the TableView
    ui->tableView_Recherche->setModel(tableModel);
    ui->tableView_Recherche->resizeColumnsToContents();
    ui->tableView_Recherche->setMinimumSize(800, 600);
    ui->tableView_Recherche->setVisible(true);
    ui->tableView_Recherche->update();

    qDebug() << "TableView model:" << ui->tableView_Recherche->model();
    qDebug() << "TableView visible:" << ui->tableView_Recherche->isVisible();
    qDebug() << "TableView size:" << ui->tableView_Recherche->size();

    reply->deleteLater();
}

void projet::on_line_Recherche_textChanged(const QString &searchText) {
    QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *>(ui->Rc_TableView_Res->model());
    if (proxyModel) {
        proxyModel->setFilterFixedString(searchText);
        ui->Rc_Label_InfoAffichage->setText("🔍 Searching for: " + searchText);
        qDebug() << "Filter applied for:" << searchText;
    } else {
        ui->Rc_Label_InfoAffichage->setText("⚠️ Proxy model not found.");
        qDebug() << "Proxy model not set on TableView";
    }
}

void projet::on_tableView_Recherche_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QString city = ui->tableView_Recherche->model()->index(row, 0).data().toString();
    QString state = ui->tableView_Recherche->model()->index(row, 1).data().toString();
    QString location = QString("%1, %2").arg(city, state);
    QString url = "https://www.bing.com/maps?FORM=Z9LH2&q=" + QUrl::toPercentEncoding(location);
    ui->WebBrowser->dynamicCall("Navigate(const QString&)", url);
    ui->WebBrowser->dynamicCall("Silent", true);
    ui->tabWidget->setCurrentIndex(2);
    qDebug() << "Navigating to map location:" << url;
}

/*bool projet::loadTranslations(const QString &filePath)
{
    QFile file(filePath);
    qDebug() << "Attempting to open translation file:" << filePath;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open translations file:" << file.errorString();
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) {
        qDebug() << "Failed to parse JSON or it is not an object.";
        return false;
    }

    translations = doc.object(); // Store the top-level object directly
    return true;
}

void projet::on_push_Translation_clicked()
{
    QStringList languages = translations.keys(); // Extract from loaded JSON
    QString targetLang = QInputDialog::getItem(this, "Language", "Translate to:", languages, languages.indexOf(currentLanguage), false);
    if (targetLang.isEmpty()) return;

    // If same language selected, don't do anything
    if (targetLang == currentLanguage) return;

    // Always reset to French first (the base language) to avoid translation chaining issues
    QJsonObject frenchTranslations = translations["fr"].toObject();
    if (!frenchTranslations.isEmpty()) {
        // Reset all labels to French first
        auto resetToFrench = [&](QWidget* widget, const QString& original) {
            QString frenchText = frenchTranslations.value(original).toString();
            if (!frenchText.isEmpty()) {
                if (auto label = qobject_cast<QLabel*>(widget)) label->setText(frenchText);
                else if (auto button = qobject_cast<QPushButton*>(widget)) button->setText(frenchText);
                else if (auto combo = qobject_cast<QComboBox*>(widget)) combo->setCurrentText(frenchText);
            }
        };

        // Reset UI elements to French
        resetToFrench(ui->Rc_Label_InfoAffichage, "Recherche Informations");
        resetToFrench(ui->Rc_push_Ajouter, "Ajouter");
        resetToFrench(ui->Rc_push_Modifier, "Modifier");
        resetToFrench(ui->Rc_push_Supprimer, "Supprimer");
        resetToFrench(ui->Rc_Button_ExportPDF, "Export PDF");
        resetToFrench(ui->Rc_Button_Stat, "Statistique");
        resetToFrench(ui->push_Translation, "Traduction");
        resetToFrench(ui->Event_label_ID, "ID");
        resetToFrench(ui->Event_label_Nom, "Nom");
        resetToFrench(ui->Event_label_Type, "Type");
        resetToFrench(ui->Event_label_Date, "Date");
        resetToFrench(ui->Event_label_Date_2, "Statut");
        resetToFrench(ui->Event_label_ID_employe, "ID_Employe");

        // Reset the tri par buttons
        resetToFrench(ui->Rc_Button_Tri_Nom, "Nom");
        resetToFrench(ui->Rc_Button_Tri_Type, "Type");
        resetToFrench(ui->Rc_Button_Tri_Statut, "Statut");

        // Reset label for tri par
        if (ui->label_tri) {
            resetToFrench(ui->label_tri, "Tri par :");
        }

        // Reset placeholders
        ui->Rc_nom_field->setPlaceholderText(frenchTranslations.value("Nom Recherche").toString());
        ui->Rc_type_field->setPlaceholderText(frenchTranslations.value("Type Recherche").toString());

        // Reset table headers to French
        QSqlQueryModel* sqlModel = qobject_cast<QSqlQueryModel*>(ui->Rc_TableView_Res->model());
        if (sqlModel) {
            R.retranslateHeaders(sqlModel, frenchTranslations);
        }
    }

    // Now apply the target language translations
    QJsonObject langTranslations = translations[targetLang].toObject();
    if (langTranslations.isEmpty()) {
        qDebug() << "No translations found for language:" << targetLang;
        return;
    }

    auto tryTranslate = [&](QWidget* widget, const QString& original) {
        QString translated = langTranslations.value(original).toString();
        if (!translated.isEmpty()) {
            if (auto label = qobject_cast<QLabel*>(widget)) label->setText(translated);
            else if (auto button = qobject_cast<QPushButton*>(widget)) button->setText(translated);
            else if (auto combo = qobject_cast<QComboBox*>(widget)) combo->setItemText(combo->currentIndex(), translated); // if applicable
        }
    };

    // Translate UI elements
    tryTranslate(ui->Rc_Label_InfoAffichage, "Recherche Informations");
    tryTranslate(ui->Rc_push_Ajouter, "Ajouter");
    tryTranslate(ui->Rc_push_Modifier, "Modifier");
    tryTranslate(ui->Rc_push_Supprimer, "Supprimer");
    tryTranslate(ui->Rc_Button_ExportPDF, "Export PDF");
    tryTranslate(ui->Rc_Button_Stat, "Statistique");
    tryTranslate(ui->push_Translation, "Traduction");

    // Translate static labels for form fields
    tryTranslate(ui->Event_label_ID, "ID");
    tryTranslate(ui->Event_label_Nom, "Nom");
    tryTranslate(ui->Event_label_Type, "Type");
    tryTranslate(ui->Event_label_Date, "Date");
    tryTranslate(ui->Event_label_Date_2, "Statut");
    tryTranslate(ui->Event_label_ID_employe, "ID_Employe");

    // Translate the tri par buttons
    tryTranslate(ui->Rc_Button_Tri_Nom, "Nom");
    tryTranslate(ui->Rc_Button_Tri_Type, "Type");
    tryTranslate(ui->Rc_Button_Tri_Statut, "Statut");

    // Translate label for tri par
    if (ui->label_tri) {
        tryTranslate(ui->label_tri, "Tri par :");
    }

    // Field placeholders or line edits if needed
    ui->Rc_nom_field->setPlaceholderText(langTranslations.value("Nom Recherche").toString());
    ui->Rc_type_field->setPlaceholderText(langTranslations.value("Type Recherche").toString());

    // ComboBox item example
    int index = ui->Rc_comboBox->findText("NOM");
    if (index != -1) ui->Rc_comboBox->setItemText(index, langTranslations.value("Nom").toString());

    // Table headers translation for main QSqlQueryModel based table
    QSqlQueryModel* sqlModel = qobject_cast<QSqlQueryModel*>(ui->Rc_TableView_Res->model());
    if (sqlModel) {
        // Use the specialized method to translate the headers
        R.retranslateHeaders(sqlModel, langTranslations);
    } else {
        // Fallback for any other model type
        QAbstractItemModel* tableModel = ui->Rc_TableView_Res->model();
        if (tableModel) {
            for (int col = 0; col < tableModel->columnCount(); ++col) {
                QString originalHeader = tableModel->headerData(col, Qt::Horizontal).toString();
                // Try different key formats for the header
                QString translated = langTranslations.value(originalHeader).toString();
                if (translated.isEmpty()) {
                    // Try alternative key formats
                    QStringList possibleKeys;
                    possibleKeys << originalHeader // Original as is
                                 << originalHeader.replace(" ", "") // Without spaces
                                 << originalHeader.replace("Recherche", "") // Without "Recherche"
                                 << "ID" << "Nom" << "Type" << "Date" << "Statut" << "ID_Employe"; // Direct keys

                    for (const QString& key : possibleKeys) {
                        translated = langTranslations.value(key).toString();
                        if (!translated.isEmpty()) break;
                    }
                }

                if (!translated.isEmpty()) {
                    tableModel->setHeaderData(col, Qt::Horizontal, translated);
                }
            }
        }
    }

    // Standard model translation for tableView_Recherche
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_Recherche->model());
    if (model) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString originalHeader = model->headerData(col, Qt::Horizontal).toString();
            QString translated = langTranslations.value(originalHeader).toString();
            if (!translated.isEmpty()) {
                model->setHeaderData(col, Qt::Horizontal, translated);
            }
        }

        // Optional: Translate cell values if needed
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QStandardItem* item = model->item(row, col);
                if (!item) continue;
                if (item->text() == "Funded") {
                    QString wordTranslated = langTranslations.value("Funded").toString();
                    item->setText(wordTranslated.isEmpty() ? item->text() : wordTranslated);
                }
            }
        }
    }

    // Update current language
    currentLanguage = targetLang;

    // Show confirmation
    ui->Rc_Label_InfoAffichage->setText("✅ Interface translated to " + targetLang);
}*/
bool projet::loadTranslations(const QString &filePath)
{
    QFile file(filePath);
    qDebug() << "Attempting to open translation file:" << filePath;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open translations file:" << file.errorString();
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) {
        qDebug() << "Failed to parse JSON or it is not an object.";
        return false;
    }

    translations = doc.object(); // Store the top-level object directly
    return true;
}

void projet::on_push_Translation_clicked()
{
    QStringList languages = translations.keys(); // Extract from loaded JSON
    QString targetLang = QInputDialog::getItem(this, "Language", "Translate to:", languages, languages.indexOf(currentLanguage), false);
    if (targetLang.isEmpty()) return;

    // If same language selected, don't do anything
    if (targetLang == currentLanguage) return;

    // Always reset to French first (the base language) to avoid translation chaining issues
    QJsonObject frenchTranslations = translations["fr"].toObject();
    if (!frenchTranslations.isEmpty()) {
        // Reset all labels to French first
        auto resetToFrench = [&](QWidget* widget, const QString& original) {
            QString frenchText = frenchTranslations.value(original).toString();
            if (!frenchText.isEmpty()) {
                if (auto label = qobject_cast<QLabel*>(widget)) label->setText(frenchText);
                else if (auto button = qobject_cast<QPushButton*>(widget)) button->setText(frenchText);
                else if (auto combo = qobject_cast<QComboBox*>(widget)) combo->setCurrentText(frenchText);
            }
        };

        // Reset UI elements to French
        resetToFrench(ui->Rc_Label_InfoAffichage, "Recherche Informations");
        resetToFrench(ui->Rc_push_Ajouter, "Ajouter");
        resetToFrench(ui->Rc_push_Modifier, "Modifier");
        resetToFrench(ui->Rc_push_Supprimer, "Supprimer");
        resetToFrench(ui->Rc_Button_ExportPDF, "Export PDF");
        resetToFrench(ui->Rc_Button_Stat, "Statistique");
        resetToFrench(ui->push_Translation, "Traduction");
        resetToFrench(ui->Event_label_ID, "ID");
        resetToFrench(ui->Event_label_Nom, "Nom");
        resetToFrench(ui->Event_label_Type, "Type");
        resetToFrench(ui->Event_label_Date, "Date");
        resetToFrench(ui->Event_label_Date_2, "Statut");
        resetToFrench(ui->Event_label_ID_employe, "ID_Employe");

        // Reset the tri par buttons
        resetToFrench(ui->Rc_Button_Tri_Nom, "Nom");
        resetToFrench(ui->Rc_Button_Tri_Type, "Type");
        resetToFrench(ui->Rc_Button_Tri_Statut, "Statut");

        // Reset label for tri par
        if (ui->label_tri) {
            resetToFrench(ui->label_tri, "Tri par :");
        }

        // Reset placeholders
        ui->Rc_nom_field->setPlaceholderText(frenchTranslations.value("Nom Recherche").toString());
        ui->Rc_type_field->setPlaceholderText(frenchTranslations.value("Type Recherche").toString());

        // Reset table headers to French
        QSqlQueryModel* sqlModel = qobject_cast<QSqlQueryModel*>(ui->Rc_TableView_Res->model());
        if (sqlModel) {
            R.retranslateHeaders(sqlModel, frenchTranslations);
        }
    }

    // Now apply the target language translations
    QJsonObject langTranslations = translations[targetLang].toObject();
    if (langTranslations.isEmpty()) {
        qDebug() << "No translations found for language:" << targetLang;
        return;
    }

    auto tryTranslate = [&](QWidget* widget, const QString& original) {
        QString translated = langTranslations.value(original).toString();
        if (!translated.isEmpty()) {
            if (auto label = qobject_cast<QLabel*>(widget)) label->setText(translated);
            else if (auto button = qobject_cast<QPushButton*>(widget)) button->setText(translated);
            else if (auto combo = qobject_cast<QComboBox*>(widget)) combo->setItemText(combo->currentIndex(), translated); // if applicable
        }
    };

    // Translate UI elements
    tryTranslate(ui->Rc_Label_InfoAffichage, "Recherche Informations");
    tryTranslate(ui->Rc_push_Ajouter, "Ajouter");
    tryTranslate(ui->Rc_push_Modifier, "Modifier");
    tryTranslate(ui->Rc_push_Supprimer, "Supprimer");
    tryTranslate(ui->Rc_Button_ExportPDF, "Export PDF");
    tryTranslate(ui->Rc_Button_Stat, "Statistique");
    tryTranslate(ui->push_Translation, "Traduction");

    // Translate static labels for form fields
    tryTranslate(ui->Event_label_ID, "ID");
    tryTranslate(ui->Event_label_Nom, "Nom");
    tryTranslate(ui->Event_label_Type, "Type");
    tryTranslate(ui->Event_label_Date, "Date");
    tryTranslate(ui->Event_label_Date_2, "Statut");
    tryTranslate(ui->Event_label_ID_employe, "ID_Employe");

    // Translate the tri par buttons
    tryTranslate(ui->Rc_Button_Tri_Nom, "Nom");
    tryTranslate(ui->Rc_Button_Tri_Type, "Type");
    tryTranslate(ui->Rc_Button_Tri_Statut, "Statut");

    // Translate label for tri par
    if (ui->label_tri) {
        tryTranslate(ui->label_tri, "Tri par :");
    }

    // Field placeholders or line edits if needed
    ui->Rc_nom_field->setPlaceholderText(langTranslations.value("Nom Recherche").toString());
    ui->Rc_type_field->setPlaceholderText(langTranslations.value("Type Recherche").toString());

    // ComboBox item example
    int index = ui->Rc_comboBox->findText("NOM");
    if (index != -1) ui->Rc_comboBox->setItemText(index, langTranslations.value("Nom").toString());

    // Table headers translation for main QSqlQueryModel based table
    QSqlQueryModel* sqlModel = qobject_cast<QSqlQueryModel*>(ui->Rc_TableView_Res->model());
    if (sqlModel) {
        // Use the specialized method to translate the headers
        R.retranslateHeaders(sqlModel, langTranslations);
    } else {
        // Fallback for any other model type
        QAbstractItemModel* tableModel = ui->Rc_TableView_Res->model();
        if (tableModel) {
            for (int col = 0; col < tableModel->columnCount(); ++col) {
                QString originalHeader = tableModel->headerData(col, Qt::Horizontal).toString();
                // Try different key formats for the header
                QString translated = langTranslations.value(originalHeader).toString();
                if (translated.isEmpty()) {
                    // Try alternative key formats
                    QStringList possibleKeys;
                    possibleKeys << originalHeader // Original as is
                                 << originalHeader.replace(" ", "") // Without spaces
                                 << originalHeader.replace("Recherche", "") // Without "Recherche"
                                 << "ID" << "Nom" << "Type" << "Date" << "Statut" << "ID_Employe"; // Direct keys

                    for (const QString& key : possibleKeys) {
                        translated = langTranslations.value(key).toString();
                        if (!translated.isEmpty()) break;
                    }
                }

                if (!translated.isEmpty()) {
                    tableModel->setHeaderData(col, Qt::Horizontal, translated);
                }
            }
        }
    }

    // Standard model translation for tableView_Recherche
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_Recherche->model());
    if (model) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString originalHeader = model->headerData(col, Qt::Horizontal).toString();
            QString translated = langTranslations.value(originalHeader).toString();
            if (!translated.isEmpty()) {
                model->setHeaderData(col, Qt::Horizontal, translated);
            }
        }

        // Optional: Translate cell values if needed
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QStandardItem* item = model->item(row, col);
                if (!item) continue;
                if (item->text() == "Funded") {
                    QString wordTranslated = langTranslations.value("Funded").toString();
                    item->setText(wordTranslated.isEmpty() ? item->text() : wordTranslated);
                }
            }
        }
    }

    // Update current language
    currentLanguage = targetLang;

    // Show confirmation
    ui->Rc_Label_InfoAffichage->setText("✅ Interface translated to " + targetLang);
}



void projet::on_push_recherche_clicked()
{

}
bool projet::connectArduino()
{
    arduino = new QSerialPort(this);

    // Automatically find the Arduino
    QString portName = "";
    const auto serialPortInfos = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        // Look for Arduino - might be "Arduino", "USB Serial", etc.
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if ((serialPortInfo.vendorIdentifier() == 0x2341 && // Arduino vendor ID
                 serialPortInfo.productIdentifier() == 0x0043) ||
                serialPortInfo.description().contains("Arduino", Qt::CaseInsensitive)) {
                portName = serialPortInfo.portName();
                break;
            }
        }
    }

    if (portName.isEmpty()) {
        qDebug() << "Arduino not found!";
        return false;
    }

    arduino->setPortName(portName);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if (arduino->open(QIODevice::ReadWrite)) {
        connect(arduino, &QSerialPort::readyRead, this, &projet::readSerial);
        return true;
    } else {
        return false;
    }
}
void projet::readSerial()
{
    if (arduino->isReadable()) {
        QByteArray data = arduino->readAll();
        QString message = QString::fromUtf8(data);

        // Process data from Arduino
        // Parse temperature readings and fan start count
        if (message.contains("Temperature:")) {
            // Extract temperature value
            // Update UI
        } else if (message.contains("FAN_START_COUNT:")) {
            // Extract fan start count
            // Update statistics
        }
    }
}
void projet::on_pushButton_envoyer_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT ETAT FROM RECHERCHES WHERE ID_RECH = 1");

    if (query.exec() && query.next()) {
        int etat = query.value(0).toInt();
        qDebug() << "Valeur ETAT lue depuis la base : " << etat;

        if (etat == 1) {
            A.write_to_arduino("1"); // active le ventilateur
            qDebug() << "Commande envoyée à Arduino : 1";
        } else {
            qDebug() << "ETAT != 1 → aucune commande envoyée.";
        }
    } else {
        qDebug() << "Erreur lors de la lecture de ETAT : " << query.lastError().text();
    }
    Recherche r;
    QSqlQueryModel* model = r.afficher();
    ui->Rc_TableView_Res->setModel(model);
}
void projet::on_pushButton1_envoyer_clicked()
{

    A.write_to_arduino("0"); // active le ventilateur
    qDebug() << "Commande envoyée à Arduino : 1";


}

void projet::update_label()
{
    A.check_and_update_research_state();
}



projet::~projet()
{
    A.close_arduino();
    delete ui;
}

void projet::on_btnemploye_clicked()
{
    user *u=new user();
    u->show();
    this->hide();

}


void projet::on_btnpatient_clicked()
{
    patie *p=new patie();
    p->show();
    this->hide();
}




void projet::on_btnvaccins_clicked()
{
    MainWindow *v=new MainWindow();
    v->show();
    this->hide();


}


void projet::on_btnequipement_clicked()
{
    equip *e = new equip();
    e->show();
    this->hide();
}


void projet::on_btnformation_clicked()
{
    forma *f= new forma();
    f->show();
    this->hide();

}


void projet::on_logout_clicked()
{
    login *l=new login();
    l->show();
    this->hide();
}

