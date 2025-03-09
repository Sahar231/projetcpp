#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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




private:
    Ui::MainWindow *ui;
    employe temploye;                     // Employee instance
};
#endif // MAINWINDOW_H
