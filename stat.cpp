#include "stat.h"
#include "ui_stat.h"
#include <QtCharts>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVBoxLayout>

QT_CHARTS_USE_NAMESPACE

stat::stat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stat)
{
    ui->setupUi(this);

    // Layout principal pour y héberger les graphiques
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 1. Pie Chart - Répartition par ÉTAT
    QPieSeries *pieSeries = new QPieSeries();
    QSqlQuery q1("SELECT ETAT, COUNT(*) FROM EQUIPEMENT GROUP BY ETAT");
    while (q1.next()) {
        pieSeries->append(q1.value(0).toString(), q1.value(1).toInt());
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des équipements par ÉTAT");
    pieChart->legend()->setAlignment(Qt::AlignRight);
    mainLayout->addWidget(new QChartView(pieChart));

    // 2. Bar Chart - Quantité par TYPE
    QBarSet *setTypes = new QBarSet("Quantité");
    QStringList categories;
    QSqlQuery q2("SELECT TYPE_EQ, COUNT(*) FROM EQUIPEMENT GROUP BY TYPE_EQ");
    while (q2.next()) {
        *setTypes << q2.value(1).toInt();
        categories << q2.value(0).toString();
    }

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(setTypes);

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Quantité par TYPE");
    barChart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Quantité");
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    mainLayout->addWidget(new QChartView(barChart));

    // 3. Bar Chart (Colonne) - Achats par ANNÉE (DATE_ACHAT)
    QBarSet *setYears = new QBarSet("Achats");
    QStringList years;

    // Pour Oracle
    QSqlQuery q3("SELECT TO_CHAR(DATE_ACHAT, 'YYYY') AS ANNEE, COUNT(*) FROM EQUIPEMENT GROUP BY TO_CHAR(DATE_ACHAT, 'YYYY')");

    // Si tu es en SQLite, utilise à la place :
    // QSqlQuery q3("SELECT strftime('%Y', DATE_ACHAT) AS ANNEE, COUNT(*) FROM EQUIPEMENT GROUP BY strftime('%Y', DATE_ACHAT)");

    while (q3.next()) {
        *setYears << q3.value(1).toInt();
        years << q3.value(0).toString();
    }

    QBarSeries *yearSeries = new QBarSeries();
    yearSeries->append(setYears);

    QChart *yearChart = new QChart();
    yearChart->addSeries(yearSeries);
    yearChart->setTitle("Équipements achetés par ANNÉE");

    QBarCategoryAxis *axisXYear = new QBarCategoryAxis();
    axisXYear->append(years);
    yearChart->addAxis(axisXYear, Qt::AlignBottom);
    yearSeries->attachAxis(axisXYear);

    QValueAxis *axisYYear = new QValueAxis();
    axisYYear->setTitleText("Nombre");
    yearChart->addAxis(axisYYear, Qt::AlignLeft);
    yearSeries->attachAxis(axisYYear);

    mainLayout->addWidget(new QChartView(yearChart));

    // Appliquer le layout à la fenêtre
    this->setLayout(mainLayout);
}

stat::~stat()
{
    delete ui;
}

