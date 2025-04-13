#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipement.h"
#include "historique.h"


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
    void readdonnes();

    ~MainWindow();


private slots:







    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_5_clicked();
    void on_recherche_2_clicked();
    void on_trier_activated(int index);
    void on_pdf_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pdf_2_clicked();
    void on_pushButton_clicked();



    void on_autoFillButton_clicked();

private:
    Ui::MainWindow *ui;
    equipement equ;
    historique *historiqueDialog;
};
#endif // MAINWINDOW_H
