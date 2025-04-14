#include <QMainWindow>
#include "employe.h"

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
    void on_pushButton_4_clicked();         // Create
    void on_pushButton_3_clicked();         // Read
    void on_modifier_clicked();         // Update
    void on_pushButton_2_clicked();         // Delete



private slots:





    void on_recherche_textChanged(const QString &arg1);


    void on_Pdf_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();



    void on_trier_currentTextChanged(const QString &arg1);

    void on_combo_stat_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    employe temploye;                     // Employee instance
};
