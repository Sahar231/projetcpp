#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QSqlQuery>
#include <QDateTime>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlError>
#include <QDate>

class historique : public QDialog
{
    Q_OBJECT

public:
    explicit historique(QWidget *parent = nullptr);
    ~historique() {}

private:
    QTextEdit *textDisplay;         // Zone d'affichage de l'historique
    QLineEdit *searchLineEdit;      // Champ de recherche
    QComboBox *filterComboBox;      // ComboBox pour le tri des actions

    void chargerHistorique();       // Charger l'historique depuis la base de données
    void filtrerHistorique();       // Filtrer l'historique selon la recherche et le tri

};

#endif // HISTORIQUE_H
