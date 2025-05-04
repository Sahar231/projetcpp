#ifndef STATI_H
#define STATI_H

#include <QMainWindow>

namespace Ui {
class stati;
}

class stati : public QMainWindow
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
    ~stati();

private slots:
    void tech_choix_pie();
    void on_Rc_push_Stat_clicked();
private:
    Ui::stati *ui;
};

#endif // STATI_H
