#include "historique.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QSqlError>
#include <QSet>

historique::historique(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Historique des Actions");
    resize(800, 700);

    // Zone d'affichage en lecture seule
    textDisplay = new QTextEdit();
    textDisplay->setReadOnly(true);
    textDisplay->setFont(QFont("Arial", 10));

    // Champ de recherche
    searchLineEdit = new QLineEdit();
    searchLineEdit->setPlaceholderText("Rechercher...");

    QPushButton* rechercherButton = new QPushButton(this);
    rechercherButton->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/rechecher.png"));
    rechercherButton->setIconSize(QSize(91, 51));
    rechercherButton->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    connect(rechercherButton, &QPushButton::clicked, this, &historique::rechercherHistorique);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(rechercherButton);

    // ComboBox pour le tri des actions
    filterComboBox = new QComboBox();
    filterComboBox->addItem("Toutes les actions");
    filterComboBox->addItem("Ajouter");
    filterComboBox->addItem("Modifier");
    filterComboBox->addItem("Supprimer");
    connect(filterComboBox, &QComboBox::currentTextChanged, this, &historique::filtrerHistorique);

    // Bouton d'actualisation
    QPushButton* actualiserButton = new QPushButton(this);
    actualiserButton->setIcon(QIcon("c:/Users/Sahar/Bureau/project/interfce/actualiser.png"));
    actualiserButton->setIconSize(QSize(51, 21));
    actualiserButton->setStyleSheet("QPushButton { border: 0px; background: transparent; }");
    connect(actualiserButton, &QPushButton::clicked, this, &historique::chargerHistorique);

    // Layout principal
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(searchLayout);      // Zone de recherche
    layout->addWidget(filterComboBox);    // Zone de filtrage
    layout->addWidget(textDisplay);       // Affichage de l'historique
    layout->addWidget(actualiserButton);  // Bouton Actualiser

    chargerHistorique(); // Chargement initial

}

void historique::chargerHistorique()
{
    QSqlQuery query;
    query.prepare("SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE ORDER BY DATE_HIS DESC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger l'historique.\nDétails: " + query.lastError().text());
        return;
    }

    QString historiqueText;
    QDate lastDate;
    QDate today = QDate::currentDate();
    QDate yesterday = today.addDays(-1);

    while (query.next()) {
        QString action = query.value("ACTION").toString().toUpper();
        QString details = query.value("DETAILS").toString();
        QDateTime dateTime = query.value("DATE_HIS").toDateTime();
        QDate currentDate = dateTime.date();
        QString heure = dateTime.toString("HH:mm");

        if (currentDate != lastDate) {
            QString dateLabel = (currentDate == today) ? "Aujourd'hui" :
                                    (currentDate == yesterday) ? "Hier" :
                                    currentDate.toString("dd/MM/yyyy");

            historiqueText += QString("<br><span style='font-size:16px; font-weight: bold;'>%1</span><br>").arg(dateLabel);
            lastDate = currentDate;
        }

        QString color;
        if (action == "AJOUT") color = "green";
        else if (action == "MODIFICATION") color = "blue";
        else if (action == "SUPPRESSION") color = "red";
        else color = "black";

        historiqueText += QString("&nbsp;&nbsp;[<b>%1</b>] <span style='color:%2;'>%3</span> : %4<br>")
                              .arg(heure)
                              .arg(color)
                              .arg(action == "AJOUT" ? "Ajout d'un équipement" :
                                       action == "MODIFICATION" ? "Modification d'un équipement" :
                                       action == "SUPPRESSION" ? "Suppression d'un équipement" :
                                       "Action inconnue")
                              .arg(details);
    }

    if (historiqueText.isEmpty())
        historiqueText = "<i>Aucune action enregistrée.</i>";

    textDisplay->setHtml(historiqueText);
}

void historique::filtrerHistorique()
{
    QString filterAction = filterComboBox->currentText();

    QString queryStr;
    if (filterAction == "Ajouter")
        queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE ACTION = 'ajout' ORDER BY DATE_HIS DESC";
    else if (filterAction == "Modifier")
        queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE ACTION = 'modification' ORDER BY DATE_HIS DESC";
    else if (filterAction == "Supprimer")
        queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE ACTION = 'suppression' ORDER BY DATE_HIS DESC";
    else {
        chargerHistorique(); // Toutes les actions
        return;
    }

    QSqlQuery query;
    if (!query.exec(queryStr)) {
        QMessageBox::critical(this, "Erreur", "Impossible de filtrer l'historique.\nDétails: " + query.lastError().text());
        return;
    }

    QString historiqueText;
    QSet<QString> addedDates;
    bool actionTitleAdded = false;
    QDate aujourdHui = QDate::currentDate();
    QDate hier = aujourdHui.addDays(-1);

    while (query.next()) {
        QString action = query.value("ACTION").toString().toUpper();
        QString details = query.value("DETAILS").toString();
        QDateTime dateTime = query.value("DATE_HIS").toDateTime();
        QDate currentDate = dateTime.date();
        QString heure = dateTime.toString("HH:mm");

        if (!actionTitleAdded) {
            historiqueText += QString("<h3>Historique de %1</h3>").arg(action.toLower());
            actionTitleAdded = true;
        }

        QString dateKey = currentDate.toString("yyyyMMdd");
        if (!addedDates.contains(dateKey)) {
            QString dateLabel = (currentDate == aujourdHui) ? "Aujourd’hui" :
                                    (currentDate == hier) ? "Hier" :
                                    currentDate.toString("dd/MM/yyyy");

            historiqueText += QString("<br><span style='font-size:16px; font-weight: bold;'>%1</span><br>").arg(dateLabel);
            addedDates.insert(dateKey);
        }

        QString color = (action == "AJOUT") ? "green" :
                            (action == "MODIFICATION") ? "blue" :
                            (action == "SUPPRESSION") ? "red" : "black";

        historiqueText += QString("&nbsp;&nbsp;[<b>%1</b>] <span style='color:%2;'>%3</span> : %4<br>")
                              .arg(heure)
                              .arg(color)
                              .arg(action == "AJOUT" ? "Nouvel équipement ajouté" :
                                       action == "MODIFICATION" ? "Équipement modifié" :
                                       action == "SUPPRESSION" ? "Équipement supprimé" :
                                       "Action inconnue")
                              .arg(details);
    }

    if (historiqueText.isEmpty())
        historiqueText = "<i>Aucune action trouvée pour ce filtre.</i>";

    textDisplay->setHtml(historiqueText);
}

void historique::rechercherHistorique()
{
    QString searchText = searchLineEdit->text().toLower().trimmed();
    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ de recherche ne doit pas être vide.");
        return;
    }

    QString queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE "
                       "WHERE LOWER(DETAILS) LIKE :searchText ORDER BY DATE_HIS DESC";

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche.\nDétails : " + query.lastError().text());
        return;
    }

    QString historiqueText;
    QSet<QString> addedDates;
    QDate aujourdHui = QDate::currentDate();
    QDate hier = aujourdHui.addDays(-1);

    bool hasResults = false;  // Flag to check if there are any results

    while (query.next()) {
        QString action = query.value("ACTION").toString();
        QString details = query.value("DETAILS").toString();
        QDateTime dateTime = query.value("DATE_HIS").toDateTime();
        QDate currentDate = dateTime.date();
        QString heure = dateTime.toString("HH:mm");

        QString dateKey = currentDate.toString("yyyyMMdd");
        if (!addedDates.contains(dateKey)) {
            QString dateLabel = (currentDate == aujourdHui) ? "Aujourd’hui" :
                                    (currentDate == hier) ? "Hier" :
                                    currentDate.toString("dd/MM/yyyy");

            historiqueText += QString("<br><span style='font-size:16px; font-weight: bold;'>%1</span><br>").arg(dateLabel);
            addedDates.insert(dateKey);
        }

        QString color = (action == "ajout") ? "green" :
                            (action == "modification") ? "blue" :
                            (action == "suppression") ? "red" : "black";

        historiqueText += QString("&nbsp;&nbsp;[<b>%1</b>] <span style='color:%2;'>%3</span> : %4<br>")
                              .arg(heure)
                              .arg(color)
                              .arg(action == "ajout" ? "Nouvel équipement ajouté" :
                                       action == "modification" ? "Équipement modifié" :
                                       action == "suppression" ? "Équipement supprimé" :
                                       "Action inconnue")
                              .arg(details);

        hasResults = true;  // Mark that we have results
    }

    if (!hasResults) {
        QMessageBox::warning(this, "Aucun résultat", "Le champ de recherche ne doit pas être vide.");
        textDisplay->clear();  // Optionally clear the display if no results are found
    } else {
        textDisplay->setHtml(historiqueText);  // Update the display only when there are results
    }
}
