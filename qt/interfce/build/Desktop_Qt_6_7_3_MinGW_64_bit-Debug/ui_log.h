/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_log
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *log)
    {
        if (log->objectName().isEmpty())
            log->setObjectName("log");
        log->resize(800, 600);
        centralwidget = new QWidget(log);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 70, 451, 381));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 63, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 150, 63, 20));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 100, 281, 26));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(70, 190, 281, 26));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 250, 171, 29));
        log->setCentralWidget(centralwidget);
        menubar = new QMenuBar(log);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        log->setMenuBar(menubar);
        statusbar = new QStatusBar(log);
        statusbar->setObjectName("statusbar");
        log->setStatusBar(statusbar);

        retranslateUi(log);

        QMetaObject::connectSlotsByName(log);
    } // setupUi

    void retranslateUi(QMainWindow *log)
    {
        log->setWindowTitle(QCoreApplication::translate("log", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("log", "username", nullptr));
        label_2->setText(QCoreApplication::translate("log", "password", nullptr));
        pushButton->setText(QCoreApplication::translate("log", "log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class log: public Ui_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
