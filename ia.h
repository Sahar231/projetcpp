#ifndef IA_H
#define IA_H

#include <QWidget>


#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
namespace Ui {
class ia;
}

class ia : public QWidget
{
    Q_OBJECT

public:
    explicit ia(QWidget *parent = nullptr);
    void sendImagePathToAPI(const QString &imagePath);
    ~ia();

private slots:
    void on_btnAjouterImage_2_clicked();
    void handleAPIResponse(QNetworkReply *reply);

private:
    Ui::ia *ui;
    QString imagePath;
    //void sendImagePathToAPI(const QString &imagePath);
};

//private slots:

#endif // IA_H
