#ifndef STATISTIQUE_EQ_H
#define STATISTIQUE_EQ_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QSqlQuery>

namespace Ui {
class statistique_eq;
}

class statistique_eq : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_eq(QWidget *parent = nullptr);
    ~statistique_eq();

protected:
    void paintEvent(QPaintEvent *event) override;  // Pour dessiner le graphique

private:
    Ui::statistique_eq *ui;

    // Méthode pour récupérer les statistiques
    QVector<QPair<QString, int>> getEquipementStats();
};

#endif // STATISTIQUE_EQ_H
