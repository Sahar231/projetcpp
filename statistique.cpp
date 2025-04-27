#include "statistique.h"
#include "ui_statistique.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QBarSet>
#include <QBarSeries>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>
#include <QChart>
#include <QLabel>
#include <QMessageBox>
#include <QTabWidget>
#include <QMap>
#include <QSet>



statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    setWindowTitle("Statistiques des Équipements");
    resize(800, 700);

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Ajout du résumé total
    layout->addWidget(createTotalEquipementWidget());

    QTabWidget *tabWidget = new QTabWidget(this);

    // Ajout des graphiques
    tabWidget->addTab(createPieChart("ETAT", "Répartition par État"), "Par État");

    tabWidget->addTab(createPieChart("TYPE_EQ", "Répartition par Type"), "Par Type");
    tabWidget->addTab(createQuantityChart(), "Quantité Totale");
    tabWidget->addTab(createEtatParTypeChart(), "État par Type");


    layout->addWidget(tabWidget);
    setLayout(layout);
}

QWidget* statistique::createTotalEquipementWidget()
{
    int total = 0;


    QSqlQuery query("SELECT count(*) FROM EQUIPEMENT");
    if (query.next()) {
        total = query.value(0).toInt();
    }


    QLabel *label = new QLabel(QString("Nombre total d'équipements : %1").arg(total));
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 18px; font-weight: bold; padding: 10px;");
    return label;
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


    QWidget* statistique::createQuantityChart()
    {
        QBarSeries *series = new QBarSeries();
        QBarSet *set = new QBarSet("Quantité d'équipements");

        QSqlQuery query("SELECT TYPE_EQ, SUM(QUANTITE) FROM EQUIPEMENT GROUP BY TYPE_EQ ORDER BY TYPE_EQ");

        QStringList categories;
        int totalQuantity = 0; // To keep track of the total quantity

        while (query.next()) {
            QString type = query.value(0).toString();
            int total = query.value(1).toInt();

            *set << total;
            categories << type;

            totalQuantity += total; // Accumulate total quantity
        }


        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Quantité totale par type d'équipement");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Quantité");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        // Add total quantity label above the chart
        QLabel *totalLabel = new QLabel(QString("Quantité totale d'équipements : %1").arg(totalQuantity));
        totalLabel->setAlignment(Qt::AlignCenter);
        totalLabel->setStyleSheet("font-size: 18px; font-weight: bold; padding: 10px;");

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(totalLabel); // Add total label above chart
        layout->addWidget(new QChartView(chart)); // Add the chart to the layout

        QWidget *widget = new QWidget();
        widget->setLayout(layout);

        return widget;
    }




    QWidget* statistique::createEtatParTypeChart()
    {
        QSqlQuery query("SELECT TYPE_EQ, ETAT, COUNT(*) FROM EQUIPEMENT GROUP BY TYPE_EQ, ETAT");

        QMap<QString, QMap<QString, int>> data;
        QSet<QString> allEtats;
        QSet<QString> allTypes;

        while (query.next()) {
            QString type = query.value(0).toString();
            QString etat = query.value(1).toString();
            int count = query.value(2).toInt();
            data[type][etat] = count;
            allEtats.insert(etat);
            allTypes.insert(type);
        }



        QMap<QString, QBarSet*> barSets;
        for (const QString &etat : allEtats) {
            barSets[etat] = new QBarSet(etat);
        }

        QStringList categories;
        for (const QString &type : allTypes) {
            categories << type;
            for (const QString &etat : allEtats) {
                int val = data[type].value(etat, 0);
                *(barSets[etat]) << val;
            }
        }

        // ✅ Changement ici : utiliser QBarSeries au lieu de QStackedBarSeries
        QBarSeries *series = new QBarSeries();
        for (QBarSet *set : barSets.values()) {
            series->append(set);
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Répartition des états par type (groupé)");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Nombre");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        return chartView;
    }





statistique::~statistique()
{
    delete ui;
}
