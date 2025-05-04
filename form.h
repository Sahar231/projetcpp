#ifndef FORM_H
#define FORM_H
#include "formation.h"
#include <QMainWindow>
#include <QTimer>
#include <QDate>
#include <QSystemTrayIcon>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QHorizontalBarSeries>
#include "arduino.h"

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


private slots:



     void update_label();
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void loadFormationData();



    void checkUpcomingFormations();  // Checks for formations starting soon
    void showNotification(const QString &title, const QString &message);  // Shows system notifi
    void navigateToPage(int pageIndex);

    void onCalendarPageChanged();
    void onCalendarClicked(const QDate &date);

    void setupParticipantStatsChart();


    void on_pdf_clicked();


    void on_pushButton_5_clicked();

    void on_trier_activated(int index);

    void on_tableView_clicked(const QModelIndex &index);





    void on_pushButton_6_clicked();




 void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();





private:
    Ui::MainWindow *ui;
    formation form;
    Arduino arduino ;

    QTimer *notificationTimer;  // Timer for periodic checks
    QList<int> notifiedFormations;  // Tracks already notified formations
    QSystemTrayIcon *trayIcon;  // Add this line

    void highlightFormationDates();
    QMap<QDate, QList<QString>> formationDetailsMap; // Stores date -> list of formations
};
#endif // FORM_H
