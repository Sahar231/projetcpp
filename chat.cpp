#include "chat.h"
#include "ui_chat.h"
#include <QSqlDatabase>
#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <random>
#include <cstdlib>
#include <ctime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>

chat::chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat),
    networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(ui->SendButton, &QPushButton::clicked, this, &chat::on_SendButton_clicked);
    setWindowTitle("Chatbot");
}

chat::~chat()
{
    delete ui;
}

QString chat::getRandomJoke()
{
    QStringList jokes;
    jokes << "Why don't scientists trust atoms? Because they make up everything!"
          << "Why did the bicycle fall over? Because it was two-tired!"
          << "What do you call fake spaghetti? An impasta!"
          << "Why don't eggs tell jokes? Because they might crack up!"
          << "What do you call a train carrying bubble-gum? A chew-chew train!";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, jokes.size() - 1);
    return jokes[dist(gen)];
}

QString chat::generatechatReply(const QString& message)
{
    QString reply;
    QString lowercaseMessage = message.toLower();

    if (lowercaseMessage.contains("hello") || lowercaseMessage.contains("hi"))
        reply = "Hello!";
    else if (lowercaseMessage.contains("comment allez vous"))
        reply = "I'm doing well, thank you! How about you?";
    else if (lowercaseMessage.contains("fine") || lowercaseMessage.contains("good"))
        reply = "That's great to hear!";
    else if (lowercaseMessage.contains("bad"))
        reply = "I'm sorry to hear that.";
    else if (lowercaseMessage.contains("my name"))
        reply = "I am sorry but I don't know your name";
    else if (lowercaseMessage.contains("nouveau vaccin"))
        reply = "nos nouveau vaccin sont Axpkds25";
    else if (lowercaseMessage.contains("vaccin covid "))
        reply = "le vaccin covid est dispo chez nous ";
    else if (lowercaseMessage.contains("my name"))
        reply = "I am sorry but I don't know your name";
    else if (lowercaseMessage.contains("joke"))
    {
        QString joke = getRandomJoke();
        m_lastJoke = joke;
        reply = joke;
    }
    else if (lowercaseMessage.contains("another") && lowercaseMessage.contains("joke"))
    {
        if (!m_lastJoke.isEmpty())
        {
            reply = getRandomJoke();
            m_lastJoke = reply;
        }
        else
            reply = "Sorry, I don't have another joke at the moment.";
    }
    else if (lowercaseMessage.contains("play game") || lowercaseMessage.contains("play a game"))
        reply = "Sure! Let's play Rock, Paper, Scissors. Choose one: rock, paper, or scissors.";
    else if (lowercaseMessage.contains("rock") || lowercaseMessage.contains("paper") || lowercaseMessage.contains("scissors"))
    {
        QStringList choices = {"rock", "paper", "scissors"};
        QString computerChoice = choices[QRandomGenerator::global()->bounded(3)];

        reply = "You chose " + message + ". I chose " + computerChoice + ". ";

        if ((message == "rock" && computerChoice == "scissors") ||
            (message == "paper" && computerChoice == "rock") ||
            (message == "scissors" && computerChoice == "paper"))
        {
            reply += "You win!";
        }
        else if (message == computerChoice)
            reply += "It's a tie!";
        else
            reply += "I win!";
    }
    else if (lowercaseMessage.contains("quiz") || lowercaseMessage.contains("question") || lowercaseMessage.contains("next"))
    {
        QString apiUrl = "https://opentdb.com/api.php?amount=20&category=17&difficulty=medium&type=multiple";
        fetchTriviaQuestion(apiUrl);
        return ""; // Trivia question will be fetched asynchronously
    }
    else
        reply = "I'm sorry, I didn't quite understand. Can you please rephrase your message?";

    return reply;
}

void chat::on_SendButton_clicked()
{
    sendMessage();
}

void chat::sendMessage()
{
    QString message = ui->messageTextEdit->toPlainText().trimmed();
    if (message.isEmpty()) return;

    ui->chatDisplayTextEdit->appendPlainText("User: " + message);
    ui->messageTextEdit->clear();

    if (m_currentQuestion.isValid && !m_currentQuestion.options.isEmpty())
    {
        bool isValidAnswer = false;
        int selectedOption = message.toInt(&isValidAnswer);

        if (isValidAnswer && selectedOption >= 1 && selectedOption <= m_currentQuestion.options.size())
        {
            QString userAnswer = m_currentQuestion.options[selectedOption - 1];
            if (userAnswer == m_currentQuestion.correctAnswer)
                ui->chatDisplayTextEdit->appendPlainText("chat: Correct answer!");
            else
                ui->chatDisplayTextEdit->appendPlainText("chat: Incorrect answer. The correct answer is: " + m_currentQuestion.correctAnswer);
        }
        else
            ui->chatDisplayTextEdit->appendPlainText("chat: Invalid answer. Please provide a valid option number.");

        m_currentQuestion.clear();
    }
    else
    {
        QString reply = generatechatReply(message);
        if (!reply.isEmpty())
            ui->chatDisplayTextEdit->appendPlainText("chat: " + reply);
    }
}

void chat::fetchTriviaQuestion(const QString &apiUrl)
{
    QUrl url(apiUrl);
       QNetworkRequest request(url);

     QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
            QJsonArray results = jsonDoc.object()["results"].toArray();

            if (!results.isEmpty())
            {
                QJsonObject trivia = results[0].toObject();
                m_currentQuestion.question = decodeHtmlEntities(trivia["question"].toString());
                m_currentQuestion.correctAnswer = decodeHtmlEntities(trivia["correct_answer"].toString());
                for (const auto &value : trivia["incorrect_answers"].toArray())
                    m_currentQuestion.options.append(decodeHtmlEntities(value.toString()));

                m_currentQuestion.options.append(m_currentQuestion.correctAnswer);
                std::shuffle(m_currentQuestion.options.begin(), m_currentQuestion.options.end(), std::mt19937(std::random_device()()));
                m_currentQuestion.isValid = true;

                ui->chatDisplayTextEdit->appendPlainText("chat: " + m_currentQuestion.question);
                for (int i = 0; i < m_currentQuestion.options.size(); ++i)
                    ui->chatDisplayTextEdit->appendPlainText(QString::number(i + 1) + ". " + m_currentQuestion.options[i]);
            }
        }
        reply->deleteLater();
    });
}

QString chat::decodeHtmlEntities(const QString &text)
{
    return text;
}
