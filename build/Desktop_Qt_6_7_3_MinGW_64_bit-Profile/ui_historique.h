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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_historique
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QLineEdit *searchLineEdit;
    QComboBox *filterComboBox;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *historique)
    {
        if (historique->objectName().isEmpty())
            historique->setObjectName("historique");
        historique->resize(955, 706);
        textEdit = new QTextEdit(historique);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 110, 931, 591));
        label = new QLabel(historique);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 10, 571, 31));
        searchLineEdit = new QLineEdit(historique);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(20, 60, 341, 31));
        filterComboBox = new QComboBox(historique);
        filterComboBox->setObjectName("filterComboBox");
        filterComboBox->setGeometry(QRect(550, 70, 271, 26));
        label_2 = new QLabel(historique);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 60, 121, 31));
        pushButton = new QPushButton(historique);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(370, 60, 93, 29));
        pushButton_2 = new QPushButton(historique);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(840, 70, 93, 29));

        retranslateUi(historique);

        QMetaObject::connectSlotsByName(historique);
    } // setupUi

    void retranslateUi(QDialog *historique)
    {
        historique->setWindowTitle(QCoreApplication::translate("historique", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("historique", "HISTORIQUE", nullptr));
        label_2->setText(QCoreApplication::translate("historique", "tri par", nullptr));
        pushButton->setText(QCoreApplication::translate("historique", "rechercher ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("historique", "actuliser", nullptr));
    } // retranslateUi

};

namespace Ui {
    class historique: public Ui_historique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUE_H
