/********************************************************************************
** Form generated from reading UI file 'housesdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOUSESDIALOG_H
#define UI_HOUSESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_housesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *codigoCasaLabel;
    QComboBox *codigoCasaComboBox;
    QLabel *tipoLabel;
    QComboBox *tipoComboBox;
    QLabel *planetaLabel;
    QComboBox *planetComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *housesDialog)
    {
        if (housesDialog->objectName().isEmpty())
            housesDialog->setObjectName(QString::fromUtf8("housesDialog"));
        housesDialog->resize(499, 239);
        verticalLayout = new QVBoxLayout(housesDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        codigoCasaLabel = new QLabel(housesDialog);
        codigoCasaLabel->setObjectName(QString::fromUtf8("codigoCasaLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, codigoCasaLabel);

        codigoCasaComboBox = new QComboBox(housesDialog);
        codigoCasaComboBox->setObjectName(QString::fromUtf8("codigoCasaComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, codigoCasaComboBox);

        tipoLabel = new QLabel(housesDialog);
        tipoLabel->setObjectName(QString::fromUtf8("tipoLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, tipoLabel);

        tipoComboBox = new QComboBox(housesDialog);
        tipoComboBox->setObjectName(QString::fromUtf8("tipoComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, tipoComboBox);

        planetaLabel = new QLabel(housesDialog);
        planetaLabel->setObjectName(QString::fromUtf8("planetaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, planetaLabel);

        planetComboBox = new QComboBox(housesDialog);
        planetComboBox->setObjectName(QString::fromUtf8("planetComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, planetComboBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(housesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(housesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), housesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), housesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(housesDialog);
    } // setupUi

    void retranslateUi(QDialog *housesDialog)
    {
        housesDialog->setWindowTitle(QApplication::translate("housesDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        codigoCasaLabel->setText(QApplication::translate("housesDialog", "Codigo Casa:", 0, QApplication::UnicodeUTF8));
        tipoLabel->setText(QApplication::translate("housesDialog", "Tipo:", 0, QApplication::UnicodeUTF8));
        planetaLabel->setText(QApplication::translate("housesDialog", "Planeta:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class housesDialog: public Ui_housesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOUSESDIALOG_H
