#include "historique.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

historique::historique(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Historique des Actions");
    resize(700, 600);

    // Zone d'affichage en lecture seule
    textDisplay = new QTextEdit();
    textDisplay->setReadOnly(true);
    textDisplay->setFont(QFont("Arial", 10));

    // Champ de recherche
    searchLineEdit = new QLineEdit();
    searchLineEdit->setPlaceholderText("Rechercher...");
    connect(searchLineEdit, &QLineEdit::textChanged, this, &historique::filtrerHistorique);

    // ComboBox pour le tri des actions
    filterComboBox = new QComboBox();
    filterComboBox->addItem("Toutes les actions");
    filterComboBox->addItem("Ajouter");
    filterComboBox->addItem("Modifier");
    filterComboBox->addItem("Supprimer");
    connect(filterComboBox, &QComboBox::currentTextChanged, this, &historique::filtrerHistorique);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(searchLineEdit);
    layout->addWidget(filterComboBox);
    layout->addWidget(textDisplay);

    chargerHistorique();
}


void historique::chargerHistorique()
{
    QSqlQuery query;
    query.prepare("SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE ORDER BY DATE_HIS DESC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger l'historique.\nDétails: " );
        return;
    }

    QString historiqueText;
    QDate lastDate;

    while (query.next()) {
        QString action = query.value("ACTION").toString().toUpper();
        QString details = query.value("DETAILS").toString();
        QDateTime dateTime = query.value("DATE_HIS").toDateTime();
        QDate currentDate = dateTime.date();
        QString heure = dateTime.toString("HH:mm");

        // Affichage de la date en grand et en gras une seule fois par jour
        if (currentDate != lastDate) {
            historiqueText += QString("<br><span style='font-size:16px; font-weight: bold;'>%1</span><br>")
            .arg(currentDate.toString("dd/MM/yyyy"));
            lastDate = currentDate;
        }

        // Déterminer la couleur selon l'action
        QString color;
        if (action == "AJOUT") color = "green";
        else if (action == "MODIFICATION") color = "blue";
        else if (action == "SUPPRESSION") color = "red";
        else color = "black";

        // Ajouter l'entrée formatée avec couleur
        historiqueText += QString("&nbsp;&nbsp;[<b>%1</b>] <span style='color:%2;'>%3</span> : %4<br>")
                              .arg(heure)
                              .arg(color)
                              .arg(action == "AJOUT" ? "Ajout d'un équipement au nom" :
                                       action == "MODIFICATION" ? "Modification d'un équipement au nom":
                                       action == "SUPPRESSION" ? "Suppression d'un équipement au nom " :
                                       "Action inconnue")
                              .arg(details);
    }

    if (historiqueText.isEmpty()) {
        historiqueText = "<i>Aucune action enregistrée.</i>";
    }

    textDisplay->setHtml(historiqueText);  // Utilisation de HTML pour le formatage
}

    void historique::filtrerHistorique()
    {
        QString searchText = searchLineEdit->text().toLower();  // Texte de recherche
        QString filterAction = filterComboBox->currentText();    // Action sélectionnée

        // Construction de la requête SQL selon l'action choisie dans le combo box
        QString queryStr;
        if (filterAction == "Ajouter") {
            // Requête spécifique pour les ajouts
            queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE ACTION = 'AJOUT' AND LOWER(DETAILS) LIKE :searchText ORDER BY DATE_HIS DESC";
        } else if (filterAction == "Modifier") {
            // Requête spécifique pour les modifications
            queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE ACTION = 'MODIFICATION' AND LOWER(DETAILS) LIKE :searchText ORDER BY DATE_HIS DESC";
        } else if (filterAction == "Supprimer") {
            // Requête spécifique pour les suppressions
            queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE ACTION = 'SUPPRESSION' AND LOWER(DETAILS) LIKE :searchText ORDER BY DATE_HIS DESC";
        } else {
            // Si "Toutes les actions" est sélectionnée, on affiche tout
            queryStr = "SELECT ACTION, DETAILS, DATE_HIS FROM HISTORIQUE WHERE LOWER(DETAILS) LIKE :searchText ORDER BY DATE_HIS DESC";
        }

        // Préparation de la requête SQL
        QSqlQuery query;
        query.prepare(queryStr);
        query.bindValue(":searchText", "%" + searchText + "%");  // Binding de la recherche

        // Exécution de la requête
        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur", "Impossible de charger l'historique.\nDétails: " + query.lastError().text());
            return;
        }

        QString historiqueText;
        QDate lastDate;
        QString lastActionType = ""; // Variable pour garder la trace du type d'action

        // Boucle pour afficher l'historique filtré
        while (query.next()) {
            QString action = query.value("ACTION").toString().toUpper();
            QString details = query.value("DETAILS").toString();
            QDateTime dateTime = query.value("DATE_HIS").toDateTime();
            QDate currentDate = dateTime.date();
            QString heure = dateTime.toString("HH:mm");

            // Affichage de l'historique par type d'action (ajouter, modifier, supprimer)
            if (action != lastActionType) {
                // Si le type d'action change, afficher le titre du type d'action
                lastActionType = action;
                historiqueText += QString("<h3>Historique d'%1</h3>").arg(action.toLower());
            }

            // Affichage de la date en grand et en gras une seule fois par jour
            if (currentDate != lastDate) {
                historiqueText += QString("<br><span style='font-size:16px; font-weight: bold;'>%1</span><br>")
                .arg(currentDate.toString("dd/MM/yyyy"));
                lastDate = currentDate;
            }

            // Déterminer la couleur selon l'action
            QString color;
            if (action == "AJOUT") color = "green";
            else if (action == "MODIFICATION") color = "blue";
            else if (action == "SUPPRESSION") color = "red";
            else color = "black";

            // Ajouter l'entrée formatée avec couleur et détails
            historiqueText += QString("&nbsp;&nbsp;[<b>%1</b>] <span style='color:%2;'>%3</span> : %4<br>")
                                  .arg(heure)
                                  .arg(color)
                                  .arg(action == "AJOUT" ? "Nouvel équipement ajouté" :
                                           action == "MODIFICATION" ? "Équipement modifié" :
                                           action == "SUPPRESSION" ? "Équipement supprimé" :
                                           "Action inconnue")
                                  .arg(details);
        }

        // Si aucun historique n'est trouvé
        if (historiqueText.isEmpty()) {
            historiqueText = "<i>Aucune action enregistrée.</i>";
        }

        textDisplay->setHtml(historiqueText);  // Utilisation de HTML pour le formatage
    }


