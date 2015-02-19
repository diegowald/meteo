/********************************************************************************
** Form generated from reading UI file 'workingdatedialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKINGDATEDIALOG_H
#define UI_WORKINGDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_workingDateDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *fechaLabel;
    QDateTimeEdit *fechaDateTimeEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *workingDateDialog)
    {
        if (workingDateDialog->objectName().isEmpty())
            workingDateDialog->setObjectName(QString::fromUtf8("workingDateDialog"));
        workingDateDialog->resize(351, 88);
        verticalLayout = new QVBoxLayout(workingDateDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        fechaLabel = new QLabel(workingDateDialog);
        fechaLabel->setObjectName(QString::fromUtf8("fechaLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fechaLabel);

        fechaDateTimeEdit = new QDateTimeEdit(workingDateDialog);
        fechaDateTimeEdit->setObjectName(QString::fromUtf8("fechaDateTimeEdit"));
        fechaDateTimeEdit->setWrapping(false);
        fechaDateTimeEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fechaDateTimeEdit->setMinimumTime(QTime(2, 0, 0));
        fechaDateTimeEdit->setCalendarPopup(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, fechaDateTimeEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(workingDateDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(workingDateDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(workingDateDialog);

        QMetaObject::connectSlotsByName(workingDateDialog);
    } // setupUi

    void retranslateUi(QDialog *workingDateDialog)
    {
        workingDateDialog->setWindowTitle(QApplication::translate("workingDateDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        fechaLabel->setText(QApplication::translate("workingDateDialog", "Fecha:", 0, QApplication::UnicodeUTF8));
        fechaDateTimeEdit->setDisplayFormat(QApplication::translate("workingDateDialog", "dd/MM/yyyy hh:mm:ss", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("workingDateDialog", "Ok", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("workingDateDialog", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class workingDateDialog: public Ui_workingDateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKINGDATEDIALOG_H
