#include "statistique_eq.h"
#include "ui_statistique_eq.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QSqlQuery>
#include <QMessageBox>

statistique_eq::statistique_eq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique_eq)
{
    ui->setupUi(this);
}

statistique_eq::~statistique_eq()
{
    delete ui;
}

QVector<QPair<QString, int>> statistique_eq::getEquipementStats()
{
    QVector<QPair<QString, int>> stats;
    QSqlQuery query;
    query.prepare("SELECT ETAT, COUNT(*) FROM EQUIPEMENT GROUP BY ETAT");

    if (query.exec()) {
        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            stats.append(qMakePair(etat, count));
        }
    } else {
        QMessageBox::critical(this, "Erreur de requête", "Impossible de récupérer les données.");
    }
    return stats;
}

void statistique_eq::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Récupérer les statistiques
    QVector<QPair<QString, int>> stats = getEquipementStats();
    int total = 0;
    for (const auto& stat : stats) {
        total += stat.second;
    }

    // Définir les couleurs pour chaque section
    QVector<QColor> colors = {Qt::blue, Qt::green, Qt::red, Qt::yellow};
    int startAngle = 0;
    int radius = 100;

    // Dessiner les secteurs du graphique circulaire
    for (int i = 0; i < stats.size(); ++i) {
        int spanAngle = (stats[i].second * 360) / total;
        painter.setBrush(QBrush(colors[i % colors.size()]));
        painter.drawPie(50, 50, radius * 2, radius * 2, startAngle * 16, spanAngle * 16);
        startAngle += spanAngle;
    }

    // Afficher les labels
    startAngle = 0;
    for (int i = 0; i < stats.size(); ++i) {
        int spanAngle = (stats[i].second * 360) / total;
        int angle = startAngle + spanAngle / 2;
        painter.drawText(QRect(50, 50, radius * 2, radius * 2), Qt::AlignCenter, QString("%1: %2").arg(stats[i].first).arg(stats[i].second));
        startAngle += spanAngle;
    }
}
