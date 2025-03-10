#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel> // Cette ligne est essentielle
#include <QComboBox>
#include <QTableView>  // Assurez-vous d'inclure QTableView

// If you are using a PDF generation library, add the necessary include
// Example (for QtPdf):
// #include <QtPdf/QPdfWriter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // Déclaration de la fonction getVaccinsData
    QList<QPair<QString, QString>> getVaccinsData();

private slots:
    void on_pushButton_4_clicked();  // Le slot pour ajouter un vaccin
    void afficherVaccins();          // Slot pour afficher les vaccins
    void on_btnSupprimer_clicked();  // Déclaration de la méthode de suppression
    void on_btnModifier_clicked();   // Ajoutez cette ligne
    void initializeTable();          // Déclaration de la méthode
    void on_btnRecherche_clicked();  // Déclaration du slot
    void trierVaccins(int index);    // Déclarez la méthode trierVaccins ici
    void genererPDFDocument();       // Add this declaration for your PDF function





private:
    Ui::MainWindow *ui;
    QSqlDatabase db;  // Pour la base de données
    QSqlTableModel *modelVaccins;
    QTableView *tableViewVaccins;
    // Déclaration de la fonction nettoyerTexte
    QString nettoyerTexte(const QString &texte);

};


#endif // MAINWINDOW_H
