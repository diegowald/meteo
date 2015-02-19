/********************************************************************************
** Form generated from reading UI file 'monthParameterDialog.ui'
**
** Created: Thu 12. Apr 12:15:01 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHPARAMETERDIALOG_H
#define UI_MONTHPARAMETERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_monthParameterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *mesLabel;
    QSpinBox *mesSpinBox;
    QLabel *lluviaLabel;
    QDoubleSpinBox *lluviaDoubleSpinBox;
    QLabel *toleranciaLabel;
    QDoubleSpinBox *toleranciaDoubleSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *monthParameterDialog)
    {
        if (monthParameterDialog->objectName().isEmpty())
            monthParameterDialog->setObjectName(QString::fromUtf8("monthParameterDialog"));
        monthParameterDialog->resize(332, 134);
        verticalLayout = new QVBoxLayout(monthParameterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        mesLabel = new QLabel(monthParameterDialog);
        mesLabel->setObjectName(QString::fromUtf8("mesLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, mesLabel);

        mesSpinBox = new QSpinBox(monthParameterDialog);
        mesSpinBox->setObjectName(QString::fromUtf8("mesSpinBox"));
        mesSpinBox->setMinimum(1);
        mesSpinBox->setMaximum(12);

        formLayout->setWidget(0, QFormLayout::FieldRole, mesSpinBox);

        lluviaLabel = new QLabel(monthParameterDialog);
        lluviaLabel->setObjectName(QString::fromUtf8("lluviaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lluviaLabel);

        lluviaDoubleSpinBox = new QDoubleSpinBox(monthParameterDialog);
        lluviaDoubleSpinBox->setObjectName(QString::fromUtf8("lluviaDoubleSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lluviaDoubleSpinBox);

        toleranciaLabel = new QLabel(monthParameterDialog);
        toleranciaLabel->setObjectName(QString::fromUtf8("toleranciaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, toleranciaLabel);

        toleranciaDoubleSpinBox = new QDoubleSpinBox(monthParameterDialog);
        toleranciaDoubleSpinBox->setObjectName(QString::fromUtf8("toleranciaDoubleSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, toleranciaDoubleSpinBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(monthParameterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(monthParameterDialog);

        QMetaObject::connectSlotsByName(monthParameterDialog);
    } // setupUi

    void retranslateUi(QDialog *monthParameterDialog)
    {
        monthParameterDialog->setWindowTitle(QApplication::translate("monthParameterDialog", "Agregar Parametro de Mes", 0, QApplication::UnicodeUTF8));
        mesLabel->setText(QApplication::translate("monthParameterDialog", "Mes:", 0, QApplication::UnicodeUTF8));
        lluviaLabel->setText(QApplication::translate("monthParameterDialog", "lluvia:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel->setText(QApplication::translate("monthParameterDialog", "tolerancia:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class monthParameterDialog: public Ui_monthParameterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHPARAMETERDIALOG_H
