#include "form.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
