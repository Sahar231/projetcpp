#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class historique : public QDialog
{
    Q_OBJECT

public:
    explicit historique(QWidget *parent = nullptr);

private slots:
    void chargerHistorique();         // Charger tous les historiques
    void filtrerHistorique();         // Filtrer selon action (ajout, suppression, etc.)
    void rechercherHistorique();      // Recherche par mot-clé

private:
    QTextEdit* textDisplay;           // Zone d'affichage HTML
    QLineEdit* searchLineEdit;        // Champ de recherche
    QComboBox* filterComboBox;        // Menu déroulant pour filtre
};

#endif // HISTORIQUE_H
