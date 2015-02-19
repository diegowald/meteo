/********************************************************************************
** Form generated from reading UI file 'dignitydialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGNITYDIALOG_H
#define UI_DIGNITYDIALOG_H

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

class Ui_dignityDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *planetaLabel;
    QComboBox *planetaComboBox;
    QLabel *dignidadLabel;
    QComboBox *dignidadComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dignityDialog)
    {
        if (dignityDialog->objectName().isEmpty())
            dignityDialog->setObjectName(QString::fromUtf8("dignityDialog"));
        dignityDialog->setWindowModality(Qt::ApplicationModal);
        dignityDialog->resize(410, 144);
        verticalLayout = new QVBoxLayout(dignityDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        planetaLabel = new QLabel(dignityDialog);
        planetaLabel->setObjectName(QString::fromUtf8("planetaLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, planetaLabel);

        planetaComboBox = new QComboBox(dignityDialog);
        planetaComboBox->setObjectName(QString::fromUtf8("planetaComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, planetaComboBox);

        dignidadLabel = new QLabel(dignityDialog);
        dignidadLabel->setObjectName(QString::fromUtf8("dignidadLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, dignidadLabel);

        dignidadComboBox = new QComboBox(dignityDialog);
        dignidadComboBox->setObjectName(QString::fromUtf8("dignidadComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dignidadComboBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dignityDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dignityDialog);

        QMetaObject::connectSlotsByName(dignityDialog);
    } // setupUi

    void retranslateUi(QDialog *dignityDialog)
    {
        dignityDialog->setWindowTitle(QApplication::translate("dignityDialog", "Agregar/Modificar Dignidades", 0, QApplication::UnicodeUTF8));
        planetaLabel->setText(QApplication::translate("dignityDialog", "Planeta:", 0, QApplication::UnicodeUTF8));
        dignidadLabel->setText(QApplication::translate("dignityDialog", "Dignidad:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dignityDialog: public Ui_dignityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGNITYDIALOG_H
