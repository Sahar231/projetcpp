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

    ~ia();

private slots:



    void envoyerImageHuggingFace(const QString &filePath);



private:
    Ui::ia *ui;
    QString imagePath;
    void envoyerPromptGemini(const QString &prompt);
    //void sendImagePathToAPI(const QString &imagePath);
};

//private slots:

#endif // IA_H
