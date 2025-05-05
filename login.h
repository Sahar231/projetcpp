#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSslSocket>
#include <QSqlQuery>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_buttonBox_accepted();  // Slot for the login button click
    void on_pushButton_clicked();  // Slot for sending an email

private:
    Ui::login *ui;

    bool loginEmploye(QString email, QString mdp);  // Function to verify employee login
    QString getEmployeId(QString email);  // Function to get employee ID from email
    void sendEmail(QString employeId);  // Function to send the email
};

#endif // LOGIN_H
