/********************************************************************************
** Form generated from reading UI file 'cuadrantesdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUADRANTESDIALOG_H
#define UI_CUADRANTESDIALOG_H

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

class Ui_cuadrantesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *tipoLabel;
    QComboBox *codeComboBox;
    QLabel *posicionLabel;
    QComboBox *eastwestComboBox;
    QLabel *planetaLabel;
    QComboBox *planetComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *cuadrantesDialog)
    {
        if (cuadrantesDialog->objectName().isEmpty())
            cuadrantesDialog->setObjectName(QString::fromUtf8("cuadrantesDialog"));
        cuadrantesDialog->resize(384, 212);
        verticalLayout = new QVBoxLayout(cuadrantesDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tipoLabel = new QLabel(cuadrantesDialog);
        tipoLabel->setObjectName(QString::fromUtf8("tipoLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tipoLabel);

        codeComboBox = new QComboBox(cuadrantesDialog);
        codeComboBox->setObjectName(QString::fromUtf8("codeComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, codeComboBox);

        posicionLabel = new QLabel(cuadrantesDialog);
        posicionLabel->setObjectName(QString::fromUtf8("posicionLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, posicionLabel);

        eastwestComboBox = new QComboBox(cuadrantesDialog);
        eastwestComboBox->setObjectName(QString::fromUtf8("eastwestComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, eastwestComboBox);

        planetaLabel = new QLabel(cuadrantesDialog);
        planetaLabel->setObjectName(QString::fromUtf8("planetaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, planetaLabel);

        planetComboBox = new QComboBox(cuadrantesDialog);
        planetComboBox->setObjectName(QString::fromUtf8("planetComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, planetComboBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(cuadrantesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(cuadrantesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), cuadrantesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), cuadrantesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(cuadrantesDialog);
    } // setupUi

    void retranslateUi(QDialog *cuadrantesDialog)
    {
        cuadrantesDialog->setWindowTitle(QApplication::translate("cuadrantesDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        tipoLabel->setText(QApplication::translate("cuadrantesDialog", "Tipo", 0, QApplication::UnicodeUTF8));
        posicionLabel->setText(QApplication::translate("cuadrantesDialog", "Posicion", 0, QApplication::UnicodeUTF8));
        planetaLabel->setText(QApplication::translate("cuadrantesDialog", "Planeta:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cuadrantesDialog: public Ui_cuadrantesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUADRANTESDIALOG_H
