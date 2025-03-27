#include "statdialog.h"
#include "ui_statdialog.h"

using namespace QtCharts;

statDialog::statDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statDialog)
{
    ui->setupUi(this);
    afficherStatistiques();  // Appel de la fonction pour afficher les stats
}

statDialog::~statDialog()
{
    delete ui;
}

void StatDialog::afficherStatistiques()
{
    QPieSeries *series = new QPieSeries();

    QSqlQuery query;
    query.prepare("SELECT ETAT, COUNT(*) FROM EQUIPEMENT GROUP BY ETAT");

    if (query.exec()) {
        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(etat, count);
        }
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des équipements");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->statLayout->addWidget(chartView);
}
