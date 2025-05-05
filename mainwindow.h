#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel> // Cette ligne est essentielle
#include <QComboBox>
#include <QTableView>  // Assurez-vous d'inclure QTableView
#include <QVBoxLayout>  // Inclure pour QVBoxLayout (si ce n'est pas déjà inclus)
#include <QLabel>  // Si vous affichez des QR Codes avec des QLabel

namespace Ui {
class MainWindow;
}

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
    void on_pdf_2_clicked();
    void on_excel_clicked();
    void resetTableView();  // Déclaration de la fonction de réinitialisation du tableau
    void askForReset();
    void openIA();  // Déclaration de la méthode openIA
    void genererQRCode(); // Votre fonction pour générer un QR Code

    void on_btnemploye_clicked();

    void on_btnpatient_clicked();

    void on_btnequipement_clicked();

    void on_btnformation_clicked();

    void on_btnrecherche_clicked();

    void on_logout_clicked();

private:
    Ui::MainWindow *ui;
    void setupTableView();
    QSqlDatabase db;  // Pour la base de données
    QSqlTableModel *modelVaccins;
    QTableView *tableViewVaccins;
    QVBoxLayout *qrLayout; // Ajouter cette ligne pour votre layout QR

    // Déclaration de la fonction nettoyerTexte
    QString nettoyerTexte(const QString &texte);
    QList<QString> getListeVaccins();
};

#endif // MAINWINDOW_H
