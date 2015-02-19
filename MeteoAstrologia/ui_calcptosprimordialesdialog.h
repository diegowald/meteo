/********************************************************************************
** Form generated from reading UI file 'calcptosprimordialesdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCPTOSPRIMORDIALESDIALOG_H
#define UI_CALCPTOSPRIMORDIALESDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_calcPtosPrimordialesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *desdeLabel;
    QDateEdit *desdeDateEdit;
    QLabel *hastaLabel;
    QDateEdit *hastaDateEdit;
    QLabel *planetaLabel;
    QComboBox *planetaComboBox;
    QLabel *signoLabel;
    QComboBox *signoComboBox;
    QLabel *gradosDeSignoLabel;
    QDoubleSpinBox *gradosDeSignoDoubleSpinBox;
    QLabel *toleranciaLabel;
    QDoubleSpinBox *toleranciaDoubleSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *calcPtosPrimordialesDialog)
    {
        if (calcPtosPrimordialesDialog->objectName().isEmpty())
            calcPtosPrimordialesDialog->setObjectName(QString::fromUtf8("calcPtosPrimordialesDialog"));
        calcPtosPrimordialesDialog->resize(320, 240);
        verticalLayout = new QVBoxLayout(calcPtosPrimordialesDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        desdeLabel = new QLabel(calcPtosPrimordialesDialog);
        desdeLabel->setObjectName(QString::fromUtf8("desdeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, desdeLabel);

        desdeDateEdit = new QDateEdit(calcPtosPrimordialesDialog);
        desdeDateEdit->setObjectName(QString::fromUtf8("desdeDateEdit"));
        desdeDateEdit->setDate(QDate(1900, 1, 1));
        desdeDateEdit->setCalendarPopup(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, desdeDateEdit);

        hastaLabel = new QLabel(calcPtosPrimordialesDialog);
        hastaLabel->setObjectName(QString::fromUtf8("hastaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, hastaLabel);

        hastaDateEdit = new QDateEdit(calcPtosPrimordialesDialog);
        hastaDateEdit->setObjectName(QString::fromUtf8("hastaDateEdit"));
        hastaDateEdit->setDate(QDate(2020, 1, 1));
        hastaDateEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, hastaDateEdit);

        planetaLabel = new QLabel(calcPtosPrimordialesDialog);
        planetaLabel->setObjectName(QString::fromUtf8("planetaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, planetaLabel);

        planetaComboBox = new QComboBox(calcPtosPrimordialesDialog);
        planetaComboBox->setObjectName(QString::fromUtf8("planetaComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, planetaComboBox);

        signoLabel = new QLabel(calcPtosPrimordialesDialog);
        signoLabel->setObjectName(QString::fromUtf8("signoLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, signoLabel);

        signoComboBox = new QComboBox(calcPtosPrimordialesDialog);
        signoComboBox->setObjectName(QString::fromUtf8("signoComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, signoComboBox);

        gradosDeSignoLabel = new QLabel(calcPtosPrimordialesDialog);
        gradosDeSignoLabel->setObjectName(QString::fromUtf8("gradosDeSignoLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, gradosDeSignoLabel);

        gradosDeSignoDoubleSpinBox = new QDoubleSpinBox(calcPtosPrimordialesDialog);
        gradosDeSignoDoubleSpinBox->setObjectName(QString::fromUtf8("gradosDeSignoDoubleSpinBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, gradosDeSignoDoubleSpinBox);

        toleranciaLabel = new QLabel(calcPtosPrimordialesDialog);
        toleranciaLabel->setObjectName(QString::fromUtf8("toleranciaLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, toleranciaLabel);

        toleranciaDoubleSpinBox = new QDoubleSpinBox(calcPtosPrimordialesDialog);
        toleranciaDoubleSpinBox->setObjectName(QString::fromUtf8("toleranciaDoubleSpinBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, toleranciaDoubleSpinBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(calcPtosPrimordialesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(calcPtosPrimordialesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), calcPtosPrimordialesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), calcPtosPrimordialesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(calcPtosPrimordialesDialog);
    } // setupUi

    void retranslateUi(QDialog *calcPtosPrimordialesDialog)
    {
        calcPtosPrimordialesDialog->setWindowTitle(QApplication::translate("calcPtosPrimordialesDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        desdeLabel->setText(QApplication::translate("calcPtosPrimordialesDialog", "Desde: ", 0, QApplication::UnicodeUTF8));
        hastaLabel->setText(QApplication::translate("calcPtosPrimordialesDialog", "Hasta: ", 0, QApplication::UnicodeUTF8));
        planetaLabel->setText(QApplication::translate("calcPtosPrimordialesDialog", "Planeta:", 0, QApplication::UnicodeUTF8));
        signoLabel->setText(QApplication::translate("calcPtosPrimordialesDialog", "Signo: ", 0, QApplication::UnicodeUTF8));
        gradosDeSignoLabel->setText(QApplication::translate("calcPtosPrimordialesDialog", "Grados de Signo:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel->setText(QApplication::translate("calcPtosPrimordialesDialog", "Tolerancia: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calcPtosPrimordialesDialog: public Ui_calcPtosPrimordialesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCPTOSPRIMORDIALESDIALOG_H
