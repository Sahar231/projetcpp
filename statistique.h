#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QMainWindow>

namespace Ui {
class Statistique;
}

class Statistique : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *parent = nullptr);
    ~Statistique();

private slots:
    void tech_choix_pie();
    void on_Rc_push_Stat_clicked();
private:
    Ui::Statistique *ui;
};

#endif // STATISTIQUE_H
