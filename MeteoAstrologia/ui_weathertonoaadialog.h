/********************************************************************************
** Form generated from reading UI file 'weathertonoaadialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERTONOAADIALOG_H
#define UI_WEATHERTONOAADIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_weatherToNoaaDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *desdeLabel;
    QDateEdit *desdeDateEdit;
    QLabel *hastaLabel;
    QDateEdit *hastaDateEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *weatherToNoaaDialog)
    {
        if (weatherToNoaaDialog->objectName().isEmpty())
            weatherToNoaaDialog->setObjectName(QString::fromUtf8("weatherToNoaaDialog"));
        weatherToNoaaDialog->resize(346, 111);
        verticalLayout = new QVBoxLayout(weatherToNoaaDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        desdeLabel = new QLabel(weatherToNoaaDialog);
        desdeLabel->setObjectName(QString::fromUtf8("desdeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, desdeLabel);

        desdeDateEdit = new QDateEdit(weatherToNoaaDialog);
        desdeDateEdit->setObjectName(QString::fromUtf8("desdeDateEdit"));
        desdeDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        desdeDateEdit->setCalendarPopup(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, desdeDateEdit);

        hastaLabel = new QLabel(weatherToNoaaDialog);
        hastaLabel->setObjectName(QString::fromUtf8("hastaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, hastaLabel);

        hastaDateEdit = new QDateEdit(weatherToNoaaDialog);
        hastaDateEdit->setObjectName(QString::fromUtf8("hastaDateEdit"));
        hastaDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        hastaDateEdit->setDate(QDate(2024, 1, 1));
        hastaDateEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, hastaDateEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(weatherToNoaaDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(weatherToNoaaDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), weatherToNoaaDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), weatherToNoaaDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(weatherToNoaaDialog);
    } // setupUi

    void retranslateUi(QDialog *weatherToNoaaDialog)
    {
        weatherToNoaaDialog->setWindowTitle(QApplication::translate("weatherToNoaaDialog", "Tiempos RBD a NOAA", 0, QApplication::UnicodeUTF8));
        desdeLabel->setText(QApplication::translate("weatherToNoaaDialog", "Desde: ", 0, QApplication::UnicodeUTF8));
        hastaLabel->setText(QApplication::translate("weatherToNoaaDialog", "Hasta: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class weatherToNoaaDialog: public Ui_weatherToNoaaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERTONOAADIALOG_H
