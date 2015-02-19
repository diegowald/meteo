/********************************************************************************
** Form generated from reading UI file 'batchastrologicgrabdata.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHASTROLOGICGRABDATA_H
#define UI_BATCHASTROLOGICGRABDATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_batchAstrologicGrabData
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *aspectariumTextEdit;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *basicinfoTextEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *logTableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *batchAstrologicGrabData)
    {
        if (batchAstrologicGrabData->objectName().isEmpty())
            batchAstrologicGrabData->setObjectName(QString::fromUtf8("batchAstrologicGrabData"));
        batchAstrologicGrabData->resize(797, 488);
        verticalLayout = new QVBoxLayout(batchAstrologicGrabData);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit = new QDateEdit(batchAstrologicGrabData);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        pushButton = new QPushButton(batchAstrologicGrabData);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        groupBox_2 = new QGroupBox(batchAstrologicGrabData);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        aspectariumTextEdit = new QTextEdit(groupBox_2);
        aspectariumTextEdit->setObjectName(QString::fromUtf8("aspectariumTextEdit"));

        verticalLayout_3->addWidget(aspectariumTextEdit);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(batchAstrologicGrabData);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        basicinfoTextEdit = new QTextEdit(groupBox_3);
        basicinfoTextEdit->setObjectName(QString::fromUtf8("basicinfoTextEdit"));

        verticalLayout_2->addWidget(basicinfoTextEdit);


        horizontalLayout_3->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(batchAstrologicGrabData);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        logTableWidget = new QTableWidget(groupBox);
        logTableWidget->setObjectName(QString::fromUtf8("logTableWidget"));

        verticalLayout_4->addWidget(logTableWidget);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nextButton = new QPushButton(batchAstrologicGrabData);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setEnabled(false);

        horizontalLayout_2->addWidget(nextButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(batchAstrologicGrabData);

        QMetaObject::connectSlotsByName(batchAstrologicGrabData);
    } // setupUi

    void retranslateUi(QWidget *batchAstrologicGrabData)
    {
        batchAstrologicGrabData->setWindowTitle(QApplication::translate("batchAstrologicGrabData", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("batchAstrologicGrabData", "Cargar Vacios", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("batchAstrologicGrabData", "Aspectarium", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("batchAstrologicGrabData", "Inf. Basica", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("batchAstrologicGrabData", "Log: ", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("batchAstrologicGrabData", "Siguiente", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class batchAstrologicGrabData: public Ui_batchAstrologicGrabData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHASTROLOGICGRABDATA_H
