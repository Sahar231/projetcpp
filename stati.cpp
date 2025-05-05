#include "stati.h"
#include "ui_stati.h"
#include "projet.h"
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtGlobal>
#include <QPainter>
#include <QSqlQuery>

stati::stati(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
    tech_choix_pie();
    show();

}

stati::~stati()
{
    delete ui;
}


void stati::tech_choix_pie() {
    QChartView *chartView;
    QSqlQuery query;
    qreal tot = 0, InfoCount = 0, GCcount = 0, EMCount = 0;
    query.prepare("SELECT COUNT(*) FROM RECHERCHES");
    if (query.exec() && query.next()) {
        tot = query.value(0).toDouble();
    }
    query.prepare("SELECT STATUT, COUNT(*) FROM RECHERCHES WHERE STATUT IN ('En Cours', 'Termine', 'Annule') GROUP BY STATUT");
    if (query.exec()) {
        while (query.next()) {
            QString status = query.value(0).toString();
            int count = query.value(1).toInt();
            if (status == "En Cours") {
                InfoCount = count;
            } else if (status == "Termine") {
                GCcount = count;
            } else if (status == "Annule") {
                EMCount = count;
            }
        }
    }
    qreal c1 = (tot > 0) ? (InfoCount / tot) : 0;
    qreal c2 = (tot > 0) ? (GCcount / tot) : 0;
    qreal c3 = (tot > 0) ? (EMCount / tot) : 0;
    QPieSeries *series = new QPieSeries();
    series->append("En Cours", c1);
    series->append("Termine", c2);
    series->append("Annule", c3);
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible();
        slice->setLabel(QString("%1: %2%").arg(slice->label()).arg(slice->percentage() * 100, 0, 'f', 1));
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setTheme(QChart::ChartThemeQt);
    chartView = new QChartView(chart, ui->Res_Label_Stats);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(570, 570);
    chartView->show();
}


void stati::on_Rc_push_Stat_clicked()
{
    tech_choix_pie();
    show();
}
