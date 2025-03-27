/********************************************************************************
** Form generated from reading UI file 'historique.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIQUE_H
#define UI_HISTORIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_historique
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *historique)
    {
        if (historique->objectName().isEmpty())
            historique->setObjectName("historique");
        historique->resize(776, 706);
        scrollArea = new QScrollArea(historique);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(29, 29, 651, 601));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 649, 599));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(historique);

        QMetaObject::connectSlotsByName(historique);
    } // setupUi

    void retranslateUi(QDialog *historique)
    {
        historique->setWindowTitle(QCoreApplication::translate("historique", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class historique: public Ui_historique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUE_H
