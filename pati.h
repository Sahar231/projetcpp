#ifndef PAT_H
#define PAT_H

#include <QMainWindow>
#include <QSqlQueryModel> // ✅ Added for database display

#include <QMap>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QSslSocket>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>



QT_BEGIN_NAMESPACE
namespace Ui {
class pati;
}
QT_END_NAMESPACE

class pati: public QMainWindow
{
    Q_OBJECT

public:
    pati(QWidget *parent = nullptr);
    ~pati();
private:
    QString selectedPatientId;

private slots:
    void on_pushButton_4_clicked(); // ✅ Add Patient function
    void displayPatients(); // ✅ Function to display patients in tableView
    void on_tableView_clicked(const QModelIndex &index);  // Selects row when clicking on table
    void on_pushButton_2_clicked();  // Deletes selected patient
    void on_pushButton_3_clicked();  // Handles patient modification
    void on_tableView_rowSelected(const QModelIndex &index);

    void on_pushButton_7_clicked();  // This is the final unified function
    void genererPDFPatients();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_5_clicked();




private:
    void sendEmail(QString recipient, QString subject, QString body);






private:
    Ui::pati *ui;


};


#endif // PAT_H
