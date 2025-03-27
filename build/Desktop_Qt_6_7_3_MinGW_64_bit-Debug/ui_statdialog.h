/********************************************************************************
** Form generated from reading UI file 'statdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATDIALOG_H
#define UI_STATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_statdialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *statdialog)
    {
        if (statdialog->objectName().isEmpty())
            statdialog->setObjectName("statdialog");
        statdialog->resize(1090, 635);
        buttonBox = new QDialogButtonBox(statdialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(830, 70, 81, 241));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(statdialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, statdialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, statdialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(statdialog);
    } // setupUi

    void retranslateUi(QDialog *statdialog)
    {
        statdialog->setWindowTitle(QCoreApplication::translate("statdialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statdialog: public Ui_statdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATDIALOG_H
