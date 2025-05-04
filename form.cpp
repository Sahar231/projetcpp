#include "form.h"
#include "ui_form.h"
#include <QString>
#include "formation.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPageSize>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSystemTrayIcon>
#include "connection.h"

#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QtCharts>
#include <QHorizontalBarSeries>
#include <QSqlQuery>
#include <QDate>
#include "arduino.h"
#include "equip.h"

#include "patie.h"
#include "user.h"
#include "projet.h"
#include "mainwindow.h"
#include "login.h"


#include <QUrl>
#include <QMessageBox>



#include <QDebug>
forma::forma(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::forma)
{
    ui->setupUi(this);




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



    ui->groupBox->setStyleSheet(
        "QGroupBox {"
        "background-color: Light Cyan;"
        "border: 0.5px solid black;"
        "border-radius: 5px;"
        "padding: 10px;"
        "}"
        "QLineEdit { border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "QspinBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"
        "QComboBox{ border: 0.5px solid black; border-radius: 5px; padding: 2px; }"

        "}");


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



    ui->recherche->setPlaceholderText("rechercher un formation par ... ");

    ui->supprimer->setPlaceholderText("ID");
    ui->trier->addItem("trier par");
    ui->trier->addItem("id");
    ui->comboBox->addItem("oui ");
    ui->comboBox->addItem("non ");




    ///CONNECTION DATABASE + REMPLIR LE TABLEVIEW///

    formation f;

        QSqlQueryModel *model = f.afficherFormation();
        ui->tableView->setModel(model);

        // Make sure the model stays alive as long as the table view needs it
        ui->tableView->setProperty("model", QVariant::fromValue(model));

        // Optional: Adjust column widths to fit content
        ui->tableView->resizeColumnsToContents();



    ///NOTIFICATION///
    // Initialize system tray icon
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("c:/Users/Sahar/Bureau/project/integration/icon.png")); // Set your app icon here
    trayIcon->show();

    notificationTimer = new QTimer(this);
    connect(notificationTimer, &QTimer::timeout, this, &forma::checkUpcomingFormations);
    notificationTimer->start(7000); // Check every minute (60,000 ms)

    // Initial check
    checkUpcomingFormations();
    //showNotification("ahla","mar7be");
    int ret = arduino.connect_arduino();
    switch (ret) {
    case 0:
        qDebug() << "arduino is available and connected to: " << arduino.getarduino_port_name();
        QMessageBox::information(this, "Connexion Arduino", "Arduino est disponible et connecté sur le port: " + arduino.getarduino_port_name());
        break;

    case 1:
        qDebug() << "arduino is available but not connected to ";
        QMessageBox::warning(this, "Connexion Arduino", "Arduino est disponible mais n'est pas connecté.");
        break;

    case -1:
        qDebug() << "arduino is not available ";
        QMessageBox::critical(this, "Connexion Arduino", "Arduino n'est pas disponible !");
        break;
    }

    QObject::connect(arduino.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));


    loadFormationData();

    ///NAVIGATION///
    connect(ui->calendarBUtoon, &QPushButton::clicked, this, [this]() { navigateToPage(1); }); //go to calendar page
    connect(ui->STATISTICSBUTTON, &QPushButton::clicked, this, [this]() { navigateToPage(2); }); //go to statistics page
    connect(ui->backtoHomeButtonC, &QPushButton::clicked, this, [this]() { navigateToPage(0); }); //go back to home
    connect(ui->backtoHomeButtonS, &QPushButton::clicked, this, [this]() { navigateToPage(0); });//go back to home

    connect(ui->pushButton_3, &QPushButton::clicked, this, [this]() { navigateToPage(3); }); //go to calendar page


    ///CALENDRIER///
    // Connect calendar signals
    connect(ui->calendarWidget, &QCalendarWidget::currentPageChanged,
            this, &forma::onCalendarPageChanged);
    connect(ui->calendarWidget, &QCalendarWidget::clicked,
            this, &forma::onCalendarClicked);

    // Initial highlight
    highlightFormationDates();

    ///statistique///
    setupParticipantStatsChart();


    ///pdf///
    connect(ui->pdf_3, &QPushButton::clicked, this, &forma::on_pdf_clicked);





}




///statistique///
/*void MainWindow::setupPriceStatsChart()
{
    // Clear previous content
    QLayoutItem* item;
    while ((item = ui->prixstatsContainerLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Query to get formation names and prices
    QSqlQuery query("SELECT LIEU, PRIX FROM FORMATION ORDER BY PRIX DESC");

    // Create chart objects
    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();

    // Create axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    QValueAxis *axisY = new QValueAxis();

    // Prepare data
    QBarSet *set = new QBarSet("Prix (TND)");
    QStringList categories;
    double maxPrice = 0;

    while (query.next()) {
        QString lieu = query.value(0).toString();
        double prix = query.value(1).toDouble();

        *set << prix;
        categories << lieu;

        if (prix > maxPrice) {
            maxPrice = prix;
        }
    }

    series->append(set);
    chart->addSeries(series);

    // Configure chart appearance
    chart->setTitle("Formation Price Statistics");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Configure axes
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY->setRange(0, maxPrice * 1.1); // 10% padding
    axisY->setTitleText("Prix (TND)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Custom styling
    set->setColor(QColor(231, 76, 60)); // Nice red color
    chart->setBackgroundBrush(QBrush(Qt::white));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // For showing values on bars - alternative to setLabelFormat
    series->setLabelsVisible(true);
    series->setLabelsFormat("@value$");
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    // Display chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->prixstatsContainerLayout->addWidget(chartView);
}*/

void forma::setupParticipantStatsChart()
{
    // Create a query to get formation names and participant counts
    QSqlQuery query("SELECT LIEU, PARTICIPANT FROM FORMATION ORDER BY PARTICIPANT DESC");

    // Create chart objects
    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();

    // Create axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    QValueAxis *axisY = new QValueAxis();

    // Prepare data
    QMap<QString, int> formationParticipants;
    int maxParticipants = 0;

    while (query.next()) {
        QString lieu = query.value(0).toString();
        int participants = query.value(1).toInt();

        formationParticipants.insert(lieu, participants);
        if (participants > maxParticipants) {
            maxParticipants = participants;
        }
    }

    // Create bars for each formation
    QBarSet *set = new QBarSet("Participants");
    for (const auto &lieu : formationParticipants.keys()) {
        *set << formationParticipants.value(lieu);
        axisX->append(lieu);
    }

    series->append(set);
    chart->addSeries(series);

    // Configure chart appearance
    chart->setTitle("Formation Participants Statistics");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Configure axes
    chart->createDefaultAxes();
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);

    // Set axis ranges
    axisY->setRange(0, maxParticipants * 1.1); // 10% padding
    axisY->setTitleText("Number of Participants");
    axisX->setTitleText("Formation Location");

    // Display chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add to your UI - you might want to use a QWidget container
    ui->statsContainerLayout->addWidget(chartView); // Assuming you have a QVBoxLayout named statsContainerLayout
}
///statistique///


///CALENDRIER///
void forma::highlightFormationDates()
{
    // Clear previous highlights
    formationDetailsMap.clear();

    // Get all formations from database
    QSqlQuery query("SELECT * FROM FORMATION");

    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(Qt::yellow);
    highlightFormat.setToolTip("Formation scheduled");

    while (query.next()) {
        QDate startDate = query.value(1).toDate();
        QDate endDate = query.value(2).toDate();

        // Store formation details
        QString details = QString(
                              "ID: %1\n"
                              "Date: %2 - %3\n"
                              "Hours: %4\n"
                              "Location: %5\n"
                              "Participants: %6\n"

                              "Certificate: %8"

                              )
                              .arg(query.value(0).toString())
                              .arg(startDate.toString("dd/MM/yyyy"))
                              .arg(endDate.toString("dd/MM/yyyy"))
                              .arg(query.value(3).toString())
                              .arg(query.value(4).toString())
                              .arg(query.value(5).toString())

                              .arg(query.value(7).toString());

        // Highlight each day of the formation period
        for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
            ui->calendarWidget->setDateTextFormat(date, highlightFormat);

            // Add to our details map
            if (!formationDetailsMap.contains(date)) {
                formationDetailsMap.insert(date, QList<QString>());
            }
            formationDetailsMap[date].append(details);
        }
    }
}

void forma::onCalendarPageChanged()
{
    // Re-highlight when month/year changes
    highlightFormationDates();
}

void forma::onCalendarClicked(const QDate &date)
{
    if (formationDetailsMap.contains(date)) {
        QString allFormations;
        foreach (const QString &details, formationDetailsMap.value(date)) {
            allFormations += details + "\n\n";
        }
        ui->formationdate->setText(allFormations);
    } else {
        ui->formationdate->setText("No formations on " + date.toString("dd/MM/yyyy"));
    }
}
///CALENDRIER///



///NAVIGATION///
void forma::navigateToPage(int pageIndex)
{
    ui->stackedWidget->setCurrentIndex(pageIndex);
}
///NAVIGATION///


///NOTIFICATION///
void forma::checkUpcomingFormations()
{
    QDate today = QDate::currentDate();
    QDate tomorrow = today.addDays(1);

    QSqlQuery query;
    query.prepare("SELECT * FROM FORMATION "
                  "WHERE DATEDEBUT BETWEEN ? AND ?");
    query.addBindValue(today);
    query.addBindValue(tomorrow);

    if (!query.exec()) {
        qWarning() << "Formation query error:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();

        // Skip if we've already notified about this formation
        if (notifiedFormations.contains(id)) {
            continue;
        }

        QDate startDate = query.value(1).toDate();
        QString location = query.value(2).toString();
        int participants = query.value(3).toInt();

        QString title = tr("Upcoming Formation");
        QString message = tr("Formation starts soon:\n"
                             "Date: %1\n"
                             "Location: %2\n"
                             "Participants: %3")
                              .arg(startDate.toString("dd/MM/yyyy"))
                              .arg(location)
                              .arg(participants);

        showNotification(title, message);
        notifiedFormations.append(id);  // Remember we notified this one
    }
}

void forma::showNotification(const QString &title, const QString &message)
{
    // Use system tray notifications if available
    if (trayIcon && trayIcon->isSystemTrayAvailable()) {
        trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 5000);
    }
    // Fallback to console output if notifications aren't available
    else {
        qInfo() << "Notification:" << title << "-" << message;
    }
}



///NOTIFICATION///




void forma::on_pushButton_4_clicked()
{
    int ID = ui->lineEdit->text().toInt();
    QDate DATEDEBUT = ui->date_edit2->date();
    QDate DATEFIN = ui->date_edit3->date();
    int  PARTICIPANT = ui->spinBox->value();
    int NOMBREMAX = ui->lineEdit_2->text().toInt();
    QString CERTIFICAT = ui->comboBox->currentText();
    int HEURE = ui->lineEdit_4->text().toInt();
    QString LIEU =ui->lineEdit_5->text();

    if (ID <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID de la formation doit être un nombre positif !");
        return;
    }

    if (LIEU.isEmpty() || CERTIFICAT.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
        return;
    }





    if (DATEDEBUT > DATEFIN) {
        QMessageBox::warning(this, "Erreur", "La date de début ne peut pas être après la date de fin !");
        return;
    }

    formation form(ID,DATEDEBUT,DATEFIN, HEURE, LIEU, PARTICIPANT,  CERTIFICAT,NOMBREMAX);
    bool test = form.ajouterFormation();

    if (test) {
        ui->tableView->setModel(form.afficherFormation());
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("ajout effectuée avec succès.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"),
                              QObject::tr("ajout  n'a pas été effectuée.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }


}


void forma::on_pushButton_3_clicked()
{
    ui->tableView->setModel(form.afficherFormation());

}


void forma::on_pushButton_2_clicked()
{
    int id = ui->supprimer->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer cette formation ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return; // Annuler la suppression si l'utilisateur a choisi "Non"
    }

    bool test = form.supprimerFormation(id);

    if (test) {
        ui->tableView->setModel(form.afficherFormation());
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Suppression effectuée avec succès.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"),
                              QObject::tr("La suppression n'a pas été effectuée.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }


}


void forma::on_pushButton_clicked()
{
    int ID = ui->lineEdit->text().toInt();
    QDate DATEDEBUT = ui->date_edit2->date();
    QDate DATEFIN= ui->date_edit3->date();
    int  PARTICIPANT = ui->spinBox->value();
    int NOMBREMAX= ui->lineEdit_2->text().toInt();
    QString CERTIFICAT = ui->comboBox->currentText();
    int HEURE = ui->lineEdit_4->text().toInt();
    QString LIEU =ui->lineEdit_5->text();


    formation form(ID,DATEDEBUT,DATEFIN, HEURE, LIEU, PARTICIPANT,  CERTIFICAT,NOMBREMAX);
    bool test = form.modifierFormation();

    if (test) {
        ui->tableView->setModel(form.afficherFormation());
        loadFormationData();
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Modification effectuée avec succès.\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec"),
                              QObject::tr("La modification n'a pas été effectuée.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }

}




void forma::on_pdf_clicked()
{
    // Get save file name from user
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Export PDF"),
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        tr("PDF Files (*.pdf)")
        );

    if (fileName.isEmpty()) {
        return;
    }

    // Setup printer
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(fileName);

    // Create document
    QTextDocument document;
    QTextCursor cursor(&document);

    // Add title
    QTextCharFormat titleFormat;
    titleFormat.setFont(QFont("Arial", 18, QFont::Bold));
    cursor.insertText(tr("Formation Report\n"), titleFormat);

    // Add date
    QTextCharFormat dateFormat;
    dateFormat.setFont(QFont("Arial", 10));
    cursor.insertText(QDate::currentDate().toString("dd/MM/yyyy") + "\n\n", dateFormat);

    // Get model from table view
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::warning(this, tr("Error"), tr("No data to export"));
        return;
    }

    // Create table format
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setCellPadding(5);
    tableFormat.setCellSpacing(0);
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setHeaderRowCount(1);

    // Create table
    QTextTable *table = cursor.insertTable(model->rowCount() + 1, model->columnCount(), tableFormat);

    // Set header format
    QTextCharFormat headerFormat;
    headerFormat.setFont(QFont("Arial", 10, QFont::Bold));
    headerFormat.setBackground(QColor(220, 220, 220));

    // Add headers
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        table->cellAt(0, col).firstCursorPosition().insertText(header, headerFormat);
    }

    // Add data rows
    QTextCharFormat cellFormat;
    cellFormat.setFont(QFont("Arial", 9));

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString text = model->data(index).toString();
            table->cellAt(row + 1, col).firstCursorPosition().insertText(text, cellFormat);
        }
    }

    // Add summary
    cursor.movePosition(QTextCursor::End);
    cursor.insertText("\n\n");

    QTextCharFormat summaryFormat;
    summaryFormat.setFont(QFont("Arial", 10, QFont::Bold));
    cursor.insertText(tr("Summary:\n"), summaryFormat);
    cursor.insertText(QString(tr("Total Formations: %1\n")).arg(model->rowCount()));

    // Print document
    document.print(&printer);

    // Show success message
    QMessageBox::information(
        this,
        tr("Success"),
        tr("PDF exported successfully to:\n%1").arg(fileName)
        );
}

void forma::on_pushButton_5_clicked()
{

    if (ui->recherche->text().isEmpty()) {
        QMessageBox::warning(this, "erreur", "rechercher d un equipement ne doivent pas être vides .");
        ui->tableView->setModel(form.afficherFormation());
    } else {
        // Si le champ de recherche contient du texte, rechercher avec ce texte
        QSqlQueryModel *model = form.Rechercher(ui->recherche->text());

        // Vérifier si le modèle est vide (c'est-à-dire aucune correspondance)
        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucun résultat", "Aucun résultat trouvé pour votre recherche.");
            ui->tableView->setModel(form.afficherFormation());
        }


        ui->tableView->setModel(model);
    }
}



void forma::on_trier_activated(int index)
{
    QString critere = ui->trier->currentText();  // comboBoxTri est ton QComboBox
    ui->tableView->setModel(form.trier(critere));
}


void forma::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row(); // Récupérer la ligne sélectionnée


    // Récupérer les données de la ligne sélectionnée
    int ID  = ui->tableView->model()->index(row, 0).data().toInt();
    QDate DATEDEBUT  = ui->tableView->model()->index(row, 1).data().toDate();
    QDate DATEFIN = ui->tableView->model()->index(row, 2).data().toDate();
    int HEURE =ui->tableView->model()->index(row, 3).data().toInt();
    QString LIEU =ui->tableView->model()->index(row, 4).data().toString();


    int  PARTICIPANT= ui->tableView->model()->index(row, 5).data().toInt();


    QString CERTIFICAT  = ui->tableView->model()->index(row, 7).data().toString();
    int NOMBREMAX =ui->tableView->model()->index(row, 6).data().toInt();

    ui->lineEdit->setText(QString::number(ID));
    ui->date_edit2->setDate(DATEDEBUT);
    ui->date_edit3->setDate(DATEFIN );
    ui->spinBox->setValue(PARTICIPANT);
    ui->lineEdit_2->setText(QString::number(NOMBREMAX));
    ui->comboBox->setCurrentText(CERTIFICAT);
    ui->lineEdit_4->setText(QString::number(HEURE));
    ui->lineEdit_5->setText(LIEU);

}


/*void MainWindow::loadFormationData()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FORMATION WHERE DATEDEBUT LIKE :date || '%'");

    // If you need to match the exact datetime format including time
    QDateTime todayStart = QDateTime::currentDateTime();
    todayStart.setTime(QTime(0,0,0)); // Set to midnight
    QString dateString = todayStart.toString("dd/MM/yyyy hh:mm:ss AP");
    query.bindValue(":date", dateString);

    if (query.exec()) {
        if (query.next()) {  // Don't forget to move to the first result
            int current = query.value(5).toInt();
            int max = query.value(7).toInt();
            int id = query.value(0).toInt();

            ui->label_24->setText(QString::number(current));
            ui->label_25->setText(QString::number(max));
            ui->label_23->setText(QString::number(id));
        } else {
            ui->label_24->setText("N/A");
            ui->label_25->setText("N/A");
            ui->label_23->setText("N/A");

            QMessageBox::information(this, "Information", "Aucune formation trouvée pour la date");
        }
    } else {
        QMessageBox::critical(this, "Error", "Erreur de requête: " + query.lastError().text());
    }
}*/
void forma::on_pushButton_6_clicked()
{
    navigateToPage(0);
}
void forma::loadFormationData()
{
    QSqlQuery query;
    query.prepare(
        "SELECT ID, PARTICIPANT, NOMBREMAX FROM FORMATION "
        "WHERE TO_CHAR(DATEDEBUT, 'DD/MM/YYYY') = :date"
        );

    QDate today = QDate::currentDate();
    QString dateString = today.toString("dd/MM/yyyy"); // Oracle expects 'DD/MM/YYYY'
    query.bindValue(":date", dateString);

    if (query.exec()) {
        if (query.next()) {
            // Access columns by name (safer than hardcoded indices)
            int id = query.value("ID").toInt();
            int current = query.value("PARTICIPANT").toInt();
            int max = query.value("NOMBREMAX").toInt();

            ui->label_23->setText(QString::number(id));
            ui->label_24->setText(QString::number(current));
            ui->label_25->setText(QString::number(max));
        } else {
            ui->label_23->setText("N/A");
            ui->label_24->setText("N/A");
            ui->label_25->setText("N/A");

            QMessageBox::information(
                this,
                "Information",
                "Aucune formation trouvée pour la date " + dateString
                );
        }
    } else {
        QMessageBox::critical(
            this,
            "Error",
            "Erreur de requête: " + query.lastError().text()
            );
    }
}















void forma::update_label()
{
    QByteArray data = arduino.read_from_arduino();

    if (data.contains("M")) {
        qDebug() << "Mouvement détecté";

        QSqlQuery query;
        QDate today = QDate::currentDate();
        QString dateString = today.toString("dd/MM/yyyy");

        query.prepare("SELECT ID, PARTICIPANT, NOMBREMAX FROM FORMATION "
                      "WHERE TO_CHAR(DATEDEBUT, 'DD/MM/YYYY') = :date");
        query.bindValue(":date", dateString);

        if (query.exec() && query.next()) {
            int current = query.value("PARTICIPANT").toInt();
            int max = query.value("NOMBREMAX").toInt();

            if (current < max) {
                arduino.write_to_arduino("O"); // ouvrir la porte
                ui->label_10->setText("Porte ouverte pour 3 sec ");
                int par = current;
                int nbr = max;




                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE FORMATION SET PARTICIPANT = PARTICIPANT + 1 "
                                    "WHERE TO_CHAR(DATEDEBUT, 'DD/MM/YYYY') = :date");
                updateQuery.bindValue(":date", dateString);
                if (!updateQuery.exec()) {
                    qDebug() << "Erreur mise à jour base:" << updateQuery.lastError();
                    QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour de la base.");
                }
                QMessageBox::information(this, "acces", "bienvenue.");
                ui->label_24->setText(QString::number(current + 1));
                ui->tableView->setModel(form.afficherFormation());
                ui->label_29->setText("il reste");
                ui->label_30->setText(QString::number(nbr - par -1));
            } else {
                arduino.write_to_arduino("X"); // fermer la porte
                ui->label_10->setText("Porte fermée - nombre max atteint");
                QMessageBox::critical(this, "nombre max atteint", "desole -salle pleine !");
                ui->label_29->setText("salle pleine");
            }







        } else {
            qDebug() << "Erreur lecture base:" << query.lastError();
            ui->label_10->setText("Erreur lecture base");

            QMessageBox::critical(this, "Erreur", "Erreur de lecture de la base de données.");
        }
    }

}
void forma::on_pushButton_7_clicked()
{
    if (arduino.getserial()->isOpen()) {
        arduino.write_to_arduino("A");
        loadFormationData();
        ui->label_12->setText("Capteur activé");

    }
}

void forma::on_pushButton_8_clicked()
{
    if (arduino.getserial()->isOpen()) {
        arduino.write_to_arduino("D");
        ui->label_12->setText("Capteur désactivé");
        QMessageBox::information(this, "Capteur désactivé", "Le capteur a été désactivé.");
    } else {
        qDebug() << "Arduino non connecté!";
        QMessageBox::critical(this, "Erreur", "Arduino non connecté !");
    }
}

forma::~forma()
{
    delete ui;
}

void forma::on_btnemploye_clicked()
{
    user *u=new user();
    u->show();
    this->hide();
}


void forma::on_btnpatient_clicked()
{
    patie *p=new patie();
    p->show();
    this->hide();

}


void forma::on_btnvaccins_clicked()
{
    MainWindow *v=new MainWindow();
    v->show();
    this->hide();

}


void forma::on_btnequipement_clicked()
{
    equip *e = new equip();
    e->show();
    this->hide();
}


void forma::on_btnrecherche_clicked()
{
    projet *r=new projet();
    r->show();
    this->hide();


}


void forma::on_logout_clicked()
{
    login *l=new login();
    l->show();
    this->hide();
}

