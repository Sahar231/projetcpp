#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recherche.h"
#include "connection.h"
#include <QList>
#include <QString>
#include <QSqlQuery>
#include <QSerialPort>
#include "arduino.h"
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Rc_push_Supprimer_clicked();
    void on_Rc_push_Modifier_clicked();
    void on_Rc_push_Ajouter_clicked();
    void on_RC_combo_ID_currentIndexChanged(int index);
    void on_Rc_Button_Tri_Nom_clicked();
    void on_Rc_Button_Tri_Type_clicked();
    void on_Rc_Button_Tri_Statut_clicked();
    void on_Rc_Line_Recherche_textChanged(const QString &arg1);
    void on_Rc_Button_ExportPDF_clicked();
    void on_Rc_Button_Stat_clicked();
    void readSerial();
    bool connectArduino();
    void update_label(); // Added to match the slot connection
    void on_pushButton_envoyer_clicked();
private:
    Ui::MainWindow *ui;
    Recherche R; // Recherche instance
    QSerialPort *arduino;
    void clearFields();
    void populateComboBoxes();
    QByteArray data;
    Arduino A; // Changed to lowercase to match class name
};

#endif // MAINWINDOW_H
