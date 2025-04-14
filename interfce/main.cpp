#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"  // Ensure the path is correct

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;  // Create an object of the connection class
    bool test = c.createconnection();  // Call the createconnection() method

    MainWindow w;
    w.resize(1600, 900);

    if (test) {
        // Show the main window
        w.show();

        // Display a success message
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\nClick OK to continue."),
                                 QMessageBox::Ok);
    } else {
        // Display an error message if connection fails
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\nClick OK to exit."),
                              QMessageBox::Ok);
        return -1;  // Exit if connection fails
    }

    return a.exec();  // Start the event loop
}
