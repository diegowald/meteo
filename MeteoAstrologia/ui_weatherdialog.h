/********************************************************************************
** Form generated from reading UI file 'weatherdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERDIALOG_H
#define UI_WEATHERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_weatherDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *tipoLabel;
    QComboBox *tipoComboBox;
    QLabel *valorLabel;
    QDoubleSpinBox *valorDoubleSpinBox;
    QLabel *toleranciaLabel;
    QDoubleSpinBox *toleranciaDoubleSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *weatherDialog)
    {
        if (weatherDialog->objectName().isEmpty())
            weatherDialog->setObjectName(QString::fromUtf8("weatherDialog"));
        weatherDialog->resize(343, 171);
        verticalLayout = new QVBoxLayout(weatherDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tipoLabel = new QLabel(weatherDialog);
        tipoLabel->setObjectName(QString::fromUtf8("tipoLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tipoLabel);

        tipoComboBox = new QComboBox(weatherDialog);
        tipoComboBox->setObjectName(QString::fromUtf8("tipoComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tipoComboBox);

        valorLabel = new QLabel(weatherDialog);
        valorLabel->setObjectName(QString::fromUtf8("valorLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, valorLabel);

        valorDoubleSpinBox = new QDoubleSpinBox(weatherDialog);
        valorDoubleSpinBox->setObjectName(QString::fromUtf8("valorDoubleSpinBox"));
        valorDoubleSpinBox->setMinimum(-99);
        valorDoubleSpinBox->setMaximum(9999.99);

        formLayout->setWidget(1, QFormLayout::FieldRole, valorDoubleSpinBox);

        toleranciaLabel = new QLabel(weatherDialog);
        toleranciaLabel->setObjectName(QString::fromUtf8("toleranciaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, toleranciaLabel);

        toleranciaDoubleSpinBox = new QDoubleSpinBox(weatherDialog);
        toleranciaDoubleSpinBox->setObjectName(QString::fromUtf8("toleranciaDoubleSpinBox"));
        toleranciaDoubleSpinBox->setMaximum(9999.99);

        formLayout->setWidget(2, QFormLayout::FieldRole, toleranciaDoubleSpinBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(weatherDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(weatherDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), weatherDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), weatherDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(weatherDialog);
    } // setupUi

    void retranslateUi(QDialog *weatherDialog)
    {
        weatherDialog->setWindowTitle(QApplication::translate("weatherDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        tipoLabel->setText(QApplication::translate("weatherDialog", "Tipo: ", 0, QApplication::UnicodeUTF8));
        valorLabel->setText(QApplication::translate("weatherDialog", "Valor:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel->setText(QApplication::translate("weatherDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class weatherDialog: public Ui_weatherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERDIALOG_H
