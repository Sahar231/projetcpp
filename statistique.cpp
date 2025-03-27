// statistique.cpp
#include "statistique.h"
#include "ui_statistique.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QMessageBox>

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    setWindowTitle("Statistiques des Équipements");
    resize(1200, 800);

    QTabWidget *tabWidget = new QTabWidget(this);

    // Add all chart tabs
    tabWidget->addTab(createPieChart("ETAT", "Répartition par État"), "Par État");
    tabWidget->addTab(createPieChart("TYPE_EQ", "Répartition par Type"), "Par Type");
    tabWidget->addTab(createMonthlyChart(), "Par Mois");
    tabWidget->addTab(createQuantityChart(), "Quantité");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);
    setLayout(layout);
}

QWidget* statistique::createPieChart(const QString &field, const QString &title)
{
    QPieSeries *series = new QPieSeries();
    QSqlQuery query(QString("SELECT %1, COUNT(*) FROM EQUIPEMENT GROUP BY %1").arg(field));



    while (query.next()) {
        QString category = query.value(0).toString();
        int count = query.value(1).toInt();
        if (count > 0) {
            QPieSlice *slice = series->append(category, count);
            slice->setLabelVisible();
            slice->setLabel(QString("%1 (%2)").arg(category).arg(count));
        }
    }

    if (series->slices().isEmpty()) {
        return createErrorWidget("Aucune donnée disponible");
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

QWidget* statistique::createMonthlyChart()
{
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Achats par mois");

    QSqlQuery query("SELECT strftime('%Y-%m', DATE_ACHAT) as month, "
                    "COUNT(*) FROM EQUIPEMENT "
                    "GROUP BY month ORDER BY month");



    QStringList categories;
    QStringList monthNames = {"Jan", "Fév", "Mar", "Avr", "Mai", "Juin",
                              "Juil", "Août", "Sep", "Oct", "Nov", "Déc"};

    while (query.next()) {
        QString monthStr = query.value(0).toString();
        int count = query.value(1).toInt();

        QDate monthDate = QDate::fromString(monthStr, "yyyy-MM");
        QString label = QString("%1 %2")
                            .arg(monthNames.at(monthDate.month()-1))
                            .arg(monthDate.year());

        *set << count;
        categories << label;
    }

    if (set->count() == 0) {
        return createErrorWidget("Aucune donnée disponible");
    }

    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Achats d'équipements par mois");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre d'équipements");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

QWidget* statistique::createQuantityChart()
{
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Quantité d'équipements");

    QSqlQuery query("SELECT QUANTITE, COUNT(*) FROM EQUIPEMENT GROUP BY QUANTITE ORDER BY QUANTITE");



    QStringList categories;
    while (query.next()) {
        int quantity = query.value(0).toInt();
        int count = query.value(1).toInt();
        *set << count;
        categories << QString::number(quantity);
    }

    if (set->count() == 0) {
        return createErrorWidget("Aucune quantité valide trouvée");
    }

    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Distribution par quantité");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre d'occurrences");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

QWidget* statistique::createErrorWidget(const QString &message)
{
    QLabel *label = new QLabel(message);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("color: red; font-weight: bold;");
    return label;
}

statistique::~statistique()
{
    delete ui;
}
