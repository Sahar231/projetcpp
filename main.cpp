#include "equip.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"
#include "connection.cpp"
#include <QString>
#include <QChar>
#include "menu.h"
#include "login.h"
int main(int arg, char *ar[])
{
    QApplication a(arg, ar);
     menu w;
    login loginDialog;


    connection c;
    bool test=c.createconnect();
    if(test)
    {    loginDialog.resize(1400, 770);
        while(loginDialog.exec() != QDialog::Accepted) {
            loginDialog.show();
        }

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    w.show();

    return a.exec();
}


