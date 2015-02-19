/********************************************************************************
** Form generated from reading UI file 'optionswidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWIDGET_H
#define UI_OPTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optionsWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *starFisherExeLabel;
    QLabel *archivoSFDLabel;
    QLabel *archivoRBDLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *starFisherExeLineEdit;
    QToolButton *starFisherButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *archivoSFDLineEdit;
    QToolButton *sfdButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *archivoRBDLineEdit;
    QToolButton *rbdButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *optionsWidget)
    {
        if (optionsWidget->objectName().isEmpty())
            optionsWidget->setObjectName(QString::fromUtf8("optionsWidget"));
        optionsWidget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(optionsWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(optionsWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        starFisherExeLabel = new QLabel(groupBox);
        starFisherExeLabel->setObjectName(QString::fromUtf8("starFisherExeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, starFisherExeLabel);

        archivoSFDLabel = new QLabel(groupBox);
        archivoSFDLabel->setObjectName(QString::fromUtf8("archivoSFDLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, archivoSFDLabel);

        archivoRBDLabel = new QLabel(groupBox);
        archivoRBDLabel->setObjectName(QString::fromUtf8("archivoRBDLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, archivoRBDLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        starFisherExeLineEdit = new QLineEdit(groupBox);
        starFisherExeLineEdit->setObjectName(QString::fromUtf8("starFisherExeLineEdit"));

        horizontalLayout->addWidget(starFisherExeLineEdit);

        starFisherButton = new QToolButton(groupBox);
        starFisherButton->setObjectName(QString::fromUtf8("starFisherButton"));

        horizontalLayout->addWidget(starFisherButton);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        archivoSFDLineEdit = new QLineEdit(groupBox);
        archivoSFDLineEdit->setObjectName(QString::fromUtf8("archivoSFDLineEdit"));

        horizontalLayout_2->addWidget(archivoSFDLineEdit);

        sfdButton = new QToolButton(groupBox);
        sfdButton->setObjectName(QString::fromUtf8("sfdButton"));

        horizontalLayout_2->addWidget(sfdButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        archivoRBDLineEdit = new QLineEdit(groupBox);
        archivoRBDLineEdit->setObjectName(QString::fromUtf8("archivoRBDLineEdit"));

        horizontalLayout_3->addWidget(archivoRBDLineEdit);

        rbdButton = new QToolButton(groupBox);
        rbdButton->setObjectName(QString::fromUtf8("rbdButton"));

        horizontalLayout_3->addWidget(rbdButton);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(optionsWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(optionsWidget);

        QMetaObject::connectSlotsByName(optionsWidget);
    } // setupUi

    void retranslateUi(QWidget *optionsWidget)
    {
        optionsWidget->setWindowTitle(QApplication::translate("optionsWidget", "Opciones", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("optionsWidget", "Archivos:", 0, QApplication::UnicodeUTF8));
        starFisherExeLabel->setText(QApplication::translate("optionsWidget", "StarFisher (.exe)", 0, QApplication::UnicodeUTF8));
        archivoSFDLabel->setText(QApplication::translate("optionsWidget", "Archivo .SFD", 0, QApplication::UnicodeUTF8));
        archivoRBDLabel->setText(QApplication::translate("optionsWidget", "Archivo .RBD", 0, QApplication::UnicodeUTF8));
        starFisherButton->setText(QApplication::translate("optionsWidget", "...", 0, QApplication::UnicodeUTF8));
        sfdButton->setText(QApplication::translate("optionsWidget", "...", 0, QApplication::UnicodeUTF8));
        rbdButton->setText(QApplication::translate("optionsWidget", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class optionsWidget: public Ui_optionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWIDGET_H
