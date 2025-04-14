#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Establish database connection
    connection c;
    bool test = c.createconnection();
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Database connection failed"),
                              QObject::tr("Connection to database failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return -1; // Exit if the connection fails
    }
    login loginDialog;
    loginDialog.resize(450, 400);
    while(loginDialog.exec() != QDialog::Accepted) {
        loginDialog.show();



    }

        MainWindow mainWindow;
        mainWindow.resize(1600, 900);
        mainWindow.show();
        return a.exec(); // Start the event loop


}
