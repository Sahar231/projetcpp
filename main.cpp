#include "Mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"
#include "connection.cpp"
#include <QString>
#include <QChar>
int main(int arg, char *ar[])
{
    QApplication a(arg, ar);
    MainWindow w;

    connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
