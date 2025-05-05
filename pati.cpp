#include "pat.h"
#include "ui_pat.h"
#include "patient.h"  // Include Patient class
#include <QString>
#include <QMessageBox>
#include <QDebug>      // For debugging
#include <QFileDialog>
#include <QPdfWriter>
#include <QPageSize>
#include <QPageLayout>
#include <QPainter>
#include <QMessageBox>
#include <QAbstractItemModel>
#include <QFont>
#include <QFontMetrics>
#include <QColor>
#include <QRect>
#include <QModelIndex>
#include <QSslSocket>



pati::pati(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pati)
{
    ui->setupUi(this);
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_rowSelected(QModelIndex)));
    connect(ui->pushButton_6, &QPushButton::clicked, this, &pati::genererPDFPatients);



    QPalette palette;
    QPixmap pixmap("d:/patient/projetcpp-Patients/back55.jpg");
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

    ui->logo->setIcon(QIcon("d:/patient/projetcpp-Patients/logo9.png"));
    ui->logo->setIconSize(QSize(150, 150));
    ui->logo->setStyleSheet(commonButtonStyle);

    ui->comboBox_2->addItem("Homme ");
    ui->comboBox_2->addItem("Femme");

    ui->btnemploye->setIcon(QIcon("d:/patient/projetcpp-Patients/employe.png"));
    ui->btnemploye->setIconSize(QSize(50, 50));
    ui->btnemploye->setStyleSheet(commonButtonStyle);

    ui->btnpatient->setIcon(QIcon("d:/patient/projetcpp-Patients/patient.png"));
    ui->btnpatient->setIconSize(QSize(50, 50));
    ui->btnpatient->setStyleSheet(commonButtonStyle);

    ui->btnvaccins->setIcon(QIcon("d:/patient/projetcpp-Patients/vaccins.png"));
    ui->btnvaccins->setIconSize(QSize(50, 50));
    ui->btnvaccins->setStyleSheet(commonButtonStyle);

    ui->btnequipement->setIcon(QIcon("d:/patient/projetcpp-Patients/equipement.png"));
    ui->btnequipement->setIconSize(QSize(50, 50));
    ui->btnequipement->setStyleSheet(commonButtonStyle);

    ui->btnformation->setIcon(QIcon("d:/patient/projetcpp-Patients/formation.png"));
    ui->btnformation->setIconSize(QSize(50, 50));
    ui->btnformation->setStyleSheet(commonButtonStyle);

    ui->btnrecherche->setIcon(QIcon("d:/patient/projetcpp-Patients/recherche.png"));
    ui->btnrecherche->setIconSize(QSize(50, 50));
    ui->btnrecherche->setStyleSheet(commonButtonStyle);

    ui->logout->setIcon(QIcon("d:/patient/projetcpp-Patients/logout1.png"));
    ui->logout->setIconSize(QSize(50, 50));
    ui->logout->setStyleSheet(commonButtonStyle);

    ui->rech->setIcon(QIcon("d:/patient/projetcpp-Patients/reche.png"));
    ui->rech->setIconSize(QSize(91, 31));
    ui->rech->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->pdf->setIcon(QIcon("d:/patient/projetcpp-Patients/pdf2.png"));
    ui->pdf->setIconSize(QSize(91, 51));
    ui->pdf->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->pdf_2->setIcon(QIcon("d:/patient/projetcpp-Patients/sta.png"));
    ui->pdf_2->setIconSize(QSize(91, 51));
    ui->pdf_2->setStyleSheet("QPushButton { border: 0px; background: transparent; }");

    ui->recherche->setPlaceholderText("Rechercher un Patient par ... ");





    ui->trier->addItem("Trier par");
    ui->trier->addItem("DateN (Plus agé)");
    ui->trier->addItem("DateN (Moin agé)");

    ui->comboBox_3->addItem("Nom");
    ui->comboBox_3->addItem("Prénom");
    ui->comboBox_3->addItem("IDP");
    ui->comboBox_3->addItem("NumT");

    // ✅ Display patients when the app starts
    displayPatients();
}

pati::~pati()
{
    delete ui;
}

// ================== 🚀 ADD PATIENT FUNCTION 🚀 ==================
void pati::on_pushButton_4_clicked() // ajout
{
    // Retrieve input values from UI
    QString id_patient = ui->lineEdit_7->text();
    QString nom = ui->lineEdit_7->text();
    QString prenom = ui->lineEdit_8->text();
    QString adresse = ui->lineEdit_9->text();
    QString email = ui->lineEdit_10->text();
    QString numT = ui->lineEdit_11->text();
    QDate dateN = ui->dateEdit_2->date();
    QString genre = ui->comboBox_2->currentText();
    QString description = ui->textEdit_2->toPlainText();

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
void pati::displayPatients() // affichage
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id_patient, nom, prenom, adresse, email, numT, dateN, genre, description FROM Patients");
    ui->tableView->setModel(model);
}
// ✅ Selects a row when clicking on tableView
void pati::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        selectedPatientId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    }
}

// ✅ Deletes the selected patient
void pati::on_pushButton_2_clicked() // suppression
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
void pati::on_pushButton_3_clicked() // modifier
{
    if (selectedPatientId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un patient à modifier !");
        return;
    }

    // Retrieve new input values
    QString nom = ui->lineEdit_7->text();
    QString prenom = ui->lineEdit_8->text();
    QString adresse = ui->lineEdit_9->text();
    QString email = ui->lineEdit_10->text();
    QString numT = ui->lineEdit_11->text();
    QDate dateN = ui->dateEdit_2->date();
    QString genre = ui->comboBox_2->currentText();
    QString description = ui->textEdit_2->toPlainText();

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
void pati::on_tableView_rowSelected(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();

    selectedPatientId = model->data(model->index(row, 0)).toString();
    ui->lineEdit_7->setText(selectedPatientId);
    ui->lineEdit_8->setText(model->data(model->index(row, 1)).toString());
    ui->lineEdit_9->setText(model->data(model->index(row, 2)).toString());
    ui->lineEdit_10->setText(model->data(model->index(row, 3)).toString());
    ui->lineEdit_11->setText(model->data(model->index(row, 4)).toString());
    ui->lineEdit_12->setText(model->data(model->index(row, 5)).toString());
    ui->dateEdit_2->setDate(model->data(model->index(row, 6)).toDate());
    ui->comboBox_2->setCurrentText(model->data(model->index(row, 7)).toString());
    ui->textEdit_2->setPlainText(model->data(model->index(row, 8)).toString());
}
void pati::on_pushButton_7_clicked() // TRI ET RECHERCHE
{
    QString searchText = ui->recherche->text().trimmed();
    QString sortOption = ui->trier->currentText();

    QString query = "SELECT id_patient, nom, prenom, adresse, email, numT, dateN, genre, description FROM Patients";
    QStringList conditions;

    // 🔍 Recherche logic
    if (!searchText.isEmpty()) {
        // Partial match for nom and prenom, exact match for id_patient and numT
        conditions << QString("id_patient = '%1'").arg(searchText);
        conditions << QString("numT = '%1'").arg(searchText);
        conditions << QString("nom LIKE '%%1%'").arg(searchText);
        conditions << QString("prenom LIKE '%%1%'").arg(searchText);
        query += " WHERE (" + conditions.join(" OR ") + ")";
    }

    // ⬇️ Tri logic
    if (sortOption == "DateN (Plus agé)") {
        query += " ORDER BY dateN ASC";
    } else if (sortOption == "DateN (Moin agé)") {
        query += " ORDER BY dateN DESC";
    }

    // Execute query
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tableView->setModel(model);

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Résultat", "Aucun patient trouvé !");
    }
}
void pati::genererPDFPatients() // PDF
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF",
                                                    QApplication::applicationDirPath() + "/patients.pdf",
                                                    "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Landscape);
    writer.setResolution(300);
    QPainter painter(&writer);

    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'initialiser le QPainter pour le PDF.");
        return;
    }

    QAbstractItemModel* model = ui->tableView->model();
    if (!model) return;

    int pageWidth = writer.width();
    int pageHeight = writer.height();

    int marginLeft = 40;
    int marginTop = 80;
    int marginRight = 40;
    int marginBottom = 40;

    int usableWidth = pageWidth - marginLeft - marginRight;
    int usableHeight = pageHeight - marginTop - marginBottom;

    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    int cellWidth = usableWidth / columnCount;
    int cellHeight = (rowCount > 0) ? usableHeight / (rowCount + 1) : 40;
    cellHeight = std::max(cellHeight, 20);

    QFont titleFont("Arial", 20, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(QColor("#0D47A1"));
    QString title = "Liste Complète des Patients";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    painter.drawText((pageWidth - titleWidth) / 2, 60, title);

    QFont tableFont("Helvetica", 10);
    painter.setFont(tableFont);
    painter.setPen(Qt::black);

    for (int c = 0; c < columnCount; ++c) {
        QRect rect(marginLeft + c * cellWidth, marginTop, cellWidth, cellHeight);
        painter.fillRect(rect, QColor("#BBDEFB"));
        painter.setPen(QColor("#0D47A1"));
        painter.drawRect(rect);
        QString headerText = model->headerData(c, Qt::Horizontal).toString();
        painter.drawText(rect.adjusted(5, 0, -5, 0), Qt::AlignCenter, headerText);
    }

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
void pati::on_pushButton_8_clicked() // stats
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Base de données non connectée !");
        return;
    }

    QMap<QString, int> ageGroupCounts;
    QSqlQuery query("SELECT dateN FROM Patients");

    QDate currentDate = QDate::currentDate();
    while (query.next()) {
        QDate dateN = query.value(0).toDate();
        int age = dateN.daysTo(currentDate) / 365;

        QString group;
        if (age < 20) group = "Moins de 20 ans";
        else if (age < 40) group = "20-39 ans";
        else if (age < 60) group = "40-59 ans";
        else group = "60 ans et plus";

        ageGroupCounts[group]++;
    }

    if (ageGroupCounts.isEmpty()) {
        QMessageBox::information(this, "Information", "Aucune donnée disponible pour générer les statistiques.");
        return;
    }

    QPieSeries *series = new QPieSeries();
    for (auto it = ageGroupCounts.begin(); it != ageGroupCounts.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QStringList colors = { "#6C5CE7", "#00B894", "#FAB1A0", "#E17055" };
    int colorIndex = 0;

    for (auto slice : series->slices()) {
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg(slice->value()));
        slice->setExploded(true);
        slice->setLabelVisible(true);
        slice->setBrush(QColor(colors[colorIndex % colors.size()]));
        slice->setLabelColor(Qt::black);
        colorIndex++;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des patients selon l'âge");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(640, 480);
    chartView->setWindowTitle("Statistiques des Patients (par âge)");
    chartView->show();
}

void pati::sendEmail(QString recipient, QString subject, QString body)
{
    QSslSocket* socket = new QSslSocket(this);
    socket->connectToHostEncrypted("smtp.gmail.com", 465); // Secure Gmail SMTP

    if (!socket->waitForEncrypted(3000)) {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion au serveur SMTP.");
        return;
    }

    // Step-by-step SMTP handshake
    auto sendCmd = [&](QString cmd) {
        socket->write(cmd.toUtf8() + "\r\n");
        socket->flush();
        socket->waitForReadyRead(3000);
        qDebug() << socket->readAll();
    };

    sendCmd("EHLO labsync.com");
    sendCmd("AUTH LOGIN");
    sendCmd(QByteArray("medazizamari520@gmail.com").toBase64());
    sendCmd(QByteArray("urwqlrohjvazomva").toBase64()); // your app password

    sendCmd("MAIL FROM:<medazizamari520@gmail.com>");
    sendCmd("RCPT TO:<" + recipient + ">");
    sendCmd("DATA");

    QString message = "To: " + recipient + "\r\n"
                                           "From: medazizamari520@gmail.com\r\n"
                                           "Subject: " + subject + "\r\n"
                                  "\r\n" +
                      body + "\r\n.";

    sendCmd(message);
    sendCmd("QUIT");

    socket->disconnectFromHost();
    QMessageBox::information(this, "Succès", "E-mail envoyé avec succès !");
}
void pati::on_pushButton_9_clicked() // EMAIL
{
    // Get selected row from QTableView
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Sélection manquante", "Veuillez sélectionner un patient dans le tableau.");
        return;
    }

    int row = index.row();
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString prenom = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();
    QString age = ui->tableView->model()->data(ui->tableView->model()->index(row, 6)).toString(); // Adjust index if needed

    QString message =
        "Cher responsable,\n\n"
        "Nous vous confirmons que le patient suivant a complété son processus de vaccination :\n"
        + QString("Nom : %1 %2 | ID : %3 | né(e) le : %4 .\n\n")
              .arg(prenom, nom)
              .arg(id)
              .arg(age)
        + "Cordialement,\n"
        + "L'équipe LabSync.";

    QString from = "medazizamari520@gmail.com";
    QString to = "medazizamari520@gmail.com";
    QString subject = "Confirmation de Vaccination";
    QString password = "urwqlrohjvazomva";
    QString mailServer = "smtp.gmail.com";
    quint16 port = 465;

    QSslSocket *socket = new QSslSocket(this);
    socket->connectToHostEncrypted(mailServer, port);

    if (!socket->waitForEncrypted(5000)) {
        QMessageBox::critical(this, "Erreur", "Connexion sécurisée échouée: " + socket->errorString());
        return;
    }

    auto sendCommand = [&](const QString &cmd) {
        socket->write(cmd.toUtf8());
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(1000);
    };

    sendCommand("EHLO localhost\r\n");
    sendCommand("AUTH LOGIN\r\n");
    sendCommand(QByteArray(from.toUtf8().toBase64()) + "\r\n");
    sendCommand(QByteArray(password.toUtf8().toBase64()) + "\r\n");
    sendCommand("MAIL FROM:<" + from + ">\r\n");
    sendCommand("RCPT TO:<" + to + ">\r\n");
    sendCommand("DATA\r\n");

    socket->write(QString("From: LabSync <%1>\r\n").arg(from).toUtf8());
    socket->write(QString("To: <%1>\r\n").arg(to).toUtf8());
    socket->write(QString("Subject: %1\r\n").arg(subject).toUtf8());
    socket->write("\r\n");
    socket->write(message.toUtf8());
    socket->write("\r\n.\r\n");
    socket->waitForBytesWritten(1000);
    socket->waitForReadyRead(1000);

    sendCommand("QUIT\r\n");

    socket->disconnectFromHost();
    socket->deleteLater();

    QMessageBox::information(this, "Succès", "Email envoyé avec succès à : " + to);
}
void pati::on_pushButton_5_clicked() // SMS
{
    QModelIndex index = ui->tableView->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un patient dans la liste.");
        return;
    }

    int row = index.row();
    QString id = ui->tableView->model()->index(row, 0).data().toString();
    QString nom = ui->tableView->model()->index(row, 1).data().toString();
    QString prenom = ui->tableView->model()->index(row, 2).data().toString();

    // Date two days from now
    QString dateRappel = QDate::currentDate().addDays(2).toString("dd/MM/yyyy");

    // Compose the SMS content
    QString message = QString("Bonjour %1 %2 (ID: %3),\n"
                              "Ceci est un rappel que vous devez vous présenter au centre de vaccination le %4.")
                          .arg(nom, prenom, id, dateRappel);

    // Simulated sending the SMS
    qDebug() << "SMS envoyé à " << nom << " " << prenom << ":";
    qDebug() << message;

    // For real SMS, call API here instead
    QMessageBox::information(this, "SMS envoyé", "Message de rappel envoyé avec succès.");
}





