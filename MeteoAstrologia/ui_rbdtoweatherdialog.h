/********************************************************************************
** Form generated from reading UI file 'rbdtoweatherdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RBDTOWEATHERDIALOG_H
#define UI_RBDTOWEATHERDIALOG_H

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

class Ui_RBDtoWeatherDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *desdeLabel;
    QDateEdit *desdeDateEdit;
    QLabel *hastaLabel;
    QDateEdit *hastaDateEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RBDtoWeatherDialog)
    {
        if (RBDtoWeatherDialog->objectName().isEmpty())
            RBDtoWeatherDialog->setObjectName(QString::fromUtf8("RBDtoWeatherDialog"));
        RBDtoWeatherDialog->resize(275, 104);
        verticalLayout = new QVBoxLayout(RBDtoWeatherDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        desdeLabel = new QLabel(RBDtoWeatherDialog);
        desdeLabel->setObjectName(QString::fromUtf8("desdeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, desdeLabel);

        desdeDateEdit = new QDateEdit(RBDtoWeatherDialog);
        desdeDateEdit->setObjectName(QString::fromUtf8("desdeDateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(desdeDateEdit->sizePolicy().hasHeightForWidth());
        desdeDateEdit->setSizePolicy(sizePolicy);
        desdeDateEdit->setDate(QDate(1900, 1, 1));

        formLayout->setWidget(0, QFormLayout::FieldRole, desdeDateEdit);

        hastaLabel = new QLabel(RBDtoWeatherDialog);
        hastaLabel->setObjectName(QString::fromUtf8("hastaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, hastaLabel);

        hastaDateEdit = new QDateEdit(RBDtoWeatherDialog);
        hastaDateEdit->setObjectName(QString::fromUtf8("hastaDateEdit"));
        sizePolicy.setHeightForWidth(hastaDateEdit->sizePolicy().hasHeightForWidth());
        hastaDateEdit->setSizePolicy(sizePolicy);
        hastaDateEdit->setDate(QDate(2020, 1, 1));

        formLayout->setWidget(1, QFormLayout::FieldRole, hastaDateEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(RBDtoWeatherDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RBDtoWeatherDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RBDtoWeatherDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RBDtoWeatherDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RBDtoWeatherDialog);
    } // setupUi

    void retranslateUi(QDialog *RBDtoWeatherDialog)
    {
        RBDtoWeatherDialog->setWindowTitle(QApplication::translate("RBDtoWeatherDialog", "Tiempo RBD a Dias", 0, QApplication::UnicodeUTF8));
        desdeLabel->setText(QApplication::translate("RBDtoWeatherDialog", "Desde:", 0, QApplication::UnicodeUTF8));
        hastaLabel->setText(QApplication::translate("RBDtoWeatherDialog", "Hasta:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RBDtoWeatherDialog: public Ui_RBDtoWeatherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RBDTOWEATHERDIALOG_H
