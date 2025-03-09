#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel> // ✅ Added for database display

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QString selectedPatientId;

private slots:
    void on_pushButton_4_clicked(); // ✅ Add Patient function
    void displayPatients(); // ✅ Function to display patients in tableView
    void on_tableView_clicked(const QModelIndex &index);  // Selects row when clicking on table
    void on_pushButton_2_clicked();  // Deletes selected patient
    void on_pushButton_3_clicked();  // Handles patient modification
    void on_tableView_rowSelected(const QModelIndex &index);




private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
