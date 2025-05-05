#ifndef EQUIP_H
#define EQUIP_H

#include <QMainWindow>
#include "equipements.h"
#include "historique.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class equip;
}
QT_END_NAMESPACE

class equip : public QMainWindow
{
    Q_OBJECT

public:
    equip(QWidget *parent = nullptr);
    void readdonnes();

    ~equip();


private slots:








    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_5_clicked();

    void on_trier_activated(int index);
    void on_pdf_clicked();


    void on_pdf_2_clicked();




    void on_autoFillButton_clicked();



    void on_historique_clicked();

    void on_rechercher_clicked();

    void on_actuliser_clicked();



    void on_pushButton_clicked();

    void on_btnpatient_clicked();

    void on_btnformation_clicked();

    void on_btnemploye_clicked();



    void on_btnvaccins_clicked();

    void on_btnrecherche_clicked();

    void on_logout_clicked();

private:
    Ui::equip *ui;
    equipement equ;
    historique *historiqueDialog;
};
#endif // EQUIP_H
