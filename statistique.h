// statistique.h
#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QtCharts>



    namespace Ui {
    class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private:
    Ui::statistique *ui;

    QWidget* createPieChart(const QString &field, const QString &title);
    QWidget* createMonthlyChart();
    QWidget* createQuantityChart();
    QWidget* createErrorWidget(const QString &message);
};

#endif // STATISTIQUE_H
