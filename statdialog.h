#ifndef STATDIALOG_H
#define STATDIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class statDialog;
}

class statDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statDialog(QWidget *parent = nullptr);
    ~statDialog();

private:
    Ui::statDialog *ui;
    void afficherStatistiques();
};

#endif // STATDIALOG_H
