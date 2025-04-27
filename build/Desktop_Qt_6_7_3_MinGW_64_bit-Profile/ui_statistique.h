/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_statistique
{
public:

    void setupUi(QDialog *statistique)
    {
        if (statistique->objectName().isEmpty())
            statistique->setObjectName("statistique");
        statistique->resize(1084, 643);

        retranslateUi(statistique);

        QMetaObject::connectSlotsByName(statistique);
    } // setupUi

    void retranslateUi(QDialog *statistique)
    {
        statistique->setWindowTitle(QCoreApplication::translate("statistique", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statistique: public Ui_statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
