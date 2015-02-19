/********************************************************************************
** Form generated from reading UI file 'signsdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNSDIALOG_H
#define UI_SIGNSDIALOG_H

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

class Ui_signsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *columnaLabel;
    QComboBox *columnaComboBox;
    QLabel *elementoLabel;
    QComboBox *elementoComboBox;
    QLabel *planetaLabel;
    QComboBox *planetComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *signsDialog)
    {
        if (signsDialog->objectName().isEmpty())
            signsDialog->setObjectName(QString::fromUtf8("signsDialog"));
        signsDialog->resize(397, 217);
        verticalLayout = new QVBoxLayout(signsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        columnaLabel = new QLabel(signsDialog);
        columnaLabel->setObjectName(QString::fromUtf8("columnaLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, columnaLabel);

        columnaComboBox = new QComboBox(signsDialog);
        columnaComboBox->setObjectName(QString::fromUtf8("columnaComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, columnaComboBox);

        elementoLabel = new QLabel(signsDialog);
        elementoLabel->setObjectName(QString::fromUtf8("elementoLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, elementoLabel);

        elementoComboBox = new QComboBox(signsDialog);
        elementoComboBox->setObjectName(QString::fromUtf8("elementoComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, elementoComboBox);

        planetaLabel = new QLabel(signsDialog);
        planetaLabel->setObjectName(QString::fromUtf8("planetaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, planetaLabel);

        planetComboBox = new QComboBox(signsDialog);
        planetComboBox->setObjectName(QString::fromUtf8("planetComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, planetComboBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(signsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(signsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), signsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), signsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(signsDialog);
    } // setupUi

    void retranslateUi(QDialog *signsDialog)
    {
        signsDialog->setWindowTitle(QApplication::translate("signsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        columnaLabel->setText(QApplication::translate("signsDialog", "Columna:", 0, QApplication::UnicodeUTF8));
        elementoLabel->setText(QApplication::translate("signsDialog", "Elemento", 0, QApplication::UnicodeUTF8));
        planetaLabel->setText(QApplication::translate("signsDialog", "Planeta:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class signsDialog: public Ui_signsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNSDIALOG_H
