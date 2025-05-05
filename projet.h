#ifndef PROJET_H
#define PROJET_H

#include <QMainWindow>
#include "recherche.h"
#include "connection.h"
#include <QList>
#include <QString>
#include <QSqlQuery>
#include <QStringListModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QSortFilterProxyModel>
#include "ard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class projet; }
QT_END_NAMESPACE

class projet: public QMainWindow
{
    Q_OBJECT

public:
    projet(QWidget *parent = nullptr);
    ~projet();
    bool loadTranslations(const QString &filePath);
private slots:

    void on_Rc_push_Supprimer_clicked();

    void on_Rc_push_Modifier_clicked();

    void on_Rc_push_Ajouter_clicked();

    void on_RC_combo_ID_currentIndexChanged(int index);

    void on_Rc_Button_Tri_Nom_clicked();

    void on_Rc_Button_Tri_Type_clicked();

    void on_Rc_Button_Tri_Statut_clicked();

    void on_Rc_Line_Recherche_textChanged(const QString &arg1);

    void on_Rc_Button_ExportPDF_clicked();

    void onSearchClicked();

    void on_Rc_Button_Stat_clicked();
    void on_line_Recherche_textChanged(const QString &text);

    void onApiResult(QNetworkReply *reply);
    void on_tableView_Recherche_doubleClicked(const QModelIndex &index);
    void on_push_Translation_clicked();

    void on_push_recherche_clicked();
    void readSerial();
    bool connectArduino();
    void update_label(); // Added to match the slot connection
    void on_pushButton_envoyer_clicked();
    void on_pushButton1_envoyer_clicked();

    void on_btnemploye_clicked();

    void on_btnpatient_clicked();

    void on_btnvaccins_clicked();

    void on_btnequipement_clicked();

    void on_btnformation_clicked();

    void on_logout_clicked();

private:
    Ui::projet*ui;
    QSortFilterProxyModel *proxyModelRecherche;

    QNetworkAccessManager *manager;
    QString m_searchTerm;
    QStringListModel *model;

    QJsonObject translations;
    Recherche R;
    void clearFields();
    void populateComboBoxes();

    // Helper method to apply translations to the table headers
    void applyTableTranslations();

    // Current language
    QString currentLanguage;

    QSerialPort *arduino;


    QByteArray data;
    Ard A; // Changed to lowercase to match class name
};


#endif // PROJET_H

