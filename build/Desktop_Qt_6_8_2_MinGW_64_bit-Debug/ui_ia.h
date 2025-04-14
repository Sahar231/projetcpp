/********************************************************************************
** Form generated from reading UI file 'ia.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IA_H
#define UI_IA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ia
{
public:
    QLabel *labelImage;
    QPushButton *btnAjouterImage;
    QPushButton *btnAjouterImage_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *ia)
    {
        if (ia->objectName().isEmpty())
            ia->setObjectName("ia");
        ia->resize(1601, 734);
        labelImage = new QLabel(ia);
        labelImage->setObjectName("labelImage");
        labelImage->setEnabled(true);
        labelImage->setGeometry(QRect(280, 20, 921, 271));
        btnAjouterImage = new QPushButton(ia);
        btnAjouterImage->setObjectName("btnAjouterImage");
        btnAjouterImage->setGeometry(QRect(30, 250, 151, 51));
        btnAjouterImage_2 = new QPushButton(ia);
        btnAjouterImage_2->setObjectName("btnAjouterImage_2");
        btnAjouterImage_2->setGeometry(QRect(1360, 240, 151, 51));
        textEdit = new QTextEdit(ia);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(280, 340, 911, 381));

        retranslateUi(ia);

        QMetaObject::connectSlotsByName(ia);
    } // setupUi

    void retranslateUi(QWidget *ia)
    {
        ia->setWindowTitle(QCoreApplication::translate("ia", "Form", nullptr));
        labelImage->setText(QString());
        btnAjouterImage->setText(QCoreApplication::translate("ia", "Ajouter image ", nullptr));
        btnAjouterImage_2->setText(QCoreApplication::translate("ia", "g\303\251n\303\251rer text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ia: public Ui_ia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IA_H
