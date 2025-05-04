#include <QMainWindow>
#include "employe.h"
#include "serialcommunication.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class user;
}
QT_END_NAMESPACE

class user : public QMainWindow
{
    Q_OBJECT

public:
    user (QWidget *parent = nullptr);
    ~user ();
    void on_pushButton_4_clicked();         // Create
    void on_pushButton_3_clicked();         // Read
    void on_modifier_clicked();         // Update
    void on_pushButton_2_clicked();         // Delete
    void setupSerial();

private slots:



    void checkUidInDatabase(const QString &uid);
    void on_recherche_textChanged(const QString &arg1);


    void on_Pdf_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();



    void on_trier_currentTextChanged(const QString &arg1);

    void on_combo_stat_currentTextChanged(const QString &arg1);
    void handleUidFromArduino(const QString &uid);
    void handleUidAuthorized(const QString &uid);
    void addUidToEmployee();  // Slot pour ajouter un UID à un employé
    void loadEmployees();  // Charger les employés dans le ComboBox

    void on_btnpatient_clicked();

    void on_btnequipement_clicked();

    void on_btnformation_clicked();

    void on_btnrecherche_clicked();

    void on_btnvaccins_clicked();

    void on_logout_clicked();

private:
    Ui::user  *ui;
    Employe temploye;
    SerialCommunication *serialCom;        // Employee instance
    bool messageEnvoye = false;
    QString lastUid;
    bool isReadyForUid = true;
    bool connectToDatabase();


};
