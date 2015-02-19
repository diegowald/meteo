/********************************************************************************
** Form generated from reading UI file 'fileloadwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILELOADWIDGET_H
#define UI_FILELOADWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileLoadWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *sunspotDiaryRadioButton;
    QRadioButton *sunspotMonthlyRadioButton;
    QRadioButton *weatherDiaryRadioButton;
    QRadioButton *ninoMonthlyRadioButton;
    QVBoxLayout *verticalLayout_3;
    QPushButton *calcButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *delButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *fileLoadWidget)
    {
        if (fileLoadWidget->objectName().isEmpty())
            fileLoadWidget->setObjectName(QString::fromUtf8("fileLoadWidget"));
        fileLoadWidget->resize(640, 480);
        verticalLayout_4 = new QVBoxLayout(fileLoadWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sunspotDiaryRadioButton = new QRadioButton(fileLoadWidget);
        sunspotDiaryRadioButton->setObjectName(QString::fromUtf8("sunspotDiaryRadioButton"));
        sunspotDiaryRadioButton->setChecked(true);

        verticalLayout_2->addWidget(sunspotDiaryRadioButton);

        sunspotMonthlyRadioButton = new QRadioButton(fileLoadWidget);
        sunspotMonthlyRadioButton->setObjectName(QString::fromUtf8("sunspotMonthlyRadioButton"));

        verticalLayout_2->addWidget(sunspotMonthlyRadioButton);

        weatherDiaryRadioButton = new QRadioButton(fileLoadWidget);
        weatherDiaryRadioButton->setObjectName(QString::fromUtf8("weatherDiaryRadioButton"));

        verticalLayout_2->addWidget(weatherDiaryRadioButton);

        ninoMonthlyRadioButton = new QRadioButton(fileLoadWidget);
        ninoMonthlyRadioButton->setObjectName(QString::fromUtf8("ninoMonthlyRadioButton"));

        verticalLayout_2->addWidget(ninoMonthlyRadioButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        calcButton = new QPushButton(fileLoadWidget);
        calcButton->setObjectName(QString::fromUtf8("calcButton"));

        verticalLayout_3->addWidget(calcButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableWidget = new QTableWidget(fileLoadWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addButton = new QPushButton(fileLoadWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        delButton = new QPushButton(fileLoadWidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        verticalLayout->addWidget(delButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(fileLoadWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(fileLoadWidget);

        QMetaObject::connectSlotsByName(fileLoadWidget);
    } // setupUi

    void retranslateUi(QWidget *fileLoadWidget)
    {
        fileLoadWidget->setWindowTitle(QApplication::translate("fileLoadWidget", "Form", 0, QApplication::UnicodeUTF8));
        sunspotDiaryRadioButton->setText(QApplication::translate("fileLoadWidget", "sunspot diarios", 0, QApplication::UnicodeUTF8));
        sunspotMonthlyRadioButton->setText(QApplication::translate("fileLoadWidget", "sunspot mensuales", 0, QApplication::UnicodeUTF8));
        weatherDiaryRadioButton->setText(QApplication::translate("fileLoadWidget", "Estados de tiempo diarios", 0, QApplication::UnicodeUTF8));
        ninoMonthlyRadioButton->setText(QApplication::translate("fileLoadWidget", "Corriente del Ni\303\261o", 0, QApplication::UnicodeUTF8));
        calcButton->setText(QApplication::translate("fileLoadWidget", "Calcular", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("fileLoadWidget", "Agregar", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("fileLoadWidget", "Quitar", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("fileLoadWidget", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fileLoadWidget: public Ui_fileLoadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILELOADWIDGET_H
