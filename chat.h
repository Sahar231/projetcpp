#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class chat;
}

struct TriviaQuestion {
    QString question;
    QString correctAnswer;
    QStringList options;
    bool isValid = false;

    void clear() {
        question.clear();
        correctAnswer.clear();
        options.clear();
        isValid = false;
    }
};

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();

private slots:
    void on_SendButton_clicked();
    void fetchTriviaQuestion(const QString &apiUrl);
    void sendMessage();

private:
    Ui::chat *ui;
    QString getRandomJoke();
    QString generatechatReply(const QString& message);
    QString decodeHtmlEntities(const QString &text);

    QNetworkAccessManager *networkManager;
    TriviaQuestion m_currentQuestion;
    QString m_lastJoke;
};

#endif // CHAT_H
