/********************************************************************************
** Form generated from reading UI file 'monthcalcdialog.ui'
**
** Created: Sun 19. May 01:43:10 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHCALCDIALOG_H
#define UI_MONTHCALCDIALOG_H

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

class Ui_monthCalcDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *desdeLabel;
    QDateEdit *desdeDateEdit;
    QLabel *hastaLabel;
    QDateEdit *hastaDateEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *monthCalcDialog)
    {
        if (monthCalcDialog->objectName().isEmpty())
            monthCalcDialog->setObjectName(QString::fromUtf8("monthCalcDialog"));
        monthCalcDialog->resize(320, 240);
        verticalLayout = new QVBoxLayout(monthCalcDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        desdeLabel = new QLabel(monthCalcDialog);
        desdeLabel->setObjectName(QString::fromUtf8("desdeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, desdeLabel);

        desdeDateEdit = new QDateEdit(monthCalcDialog);
        desdeDateEdit->setObjectName(QString::fromUtf8("desdeDateEdit"));
        desdeDateEdit->setDate(QDate(1900, 1, 1));

        formLayout->setWidget(0, QFormLayout::FieldRole, desdeDateEdit);

        hastaLabel = new QLabel(monthCalcDialog);
        hastaLabel->setObjectName(QString::fromUtf8("hastaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, hastaLabel);

        hastaDateEdit = new QDateEdit(monthCalcDialog);
        hastaDateEdit->setObjectName(QString::fromUtf8("hastaDateEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, hastaDateEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(monthCalcDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(monthCalcDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), monthCalcDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), monthCalcDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(monthCalcDialog);
    } // setupUi

    void retranslateUi(QDialog *monthCalcDialog)
    {
        monthCalcDialog->setWindowTitle(QApplication::translate("monthCalcDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        desdeLabel->setText(QApplication::translate("monthCalcDialog", "Desde:", 0, QApplication::UnicodeUTF8));
        hastaLabel->setText(QApplication::translate("monthCalcDialog", "Hasta:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class monthCalcDialog: public Ui_monthCalcDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHCALCDIALOG_H
