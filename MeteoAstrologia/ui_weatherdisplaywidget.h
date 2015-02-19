/********************************************************************************
** Form generated from reading UI file 'weatherdisplaywidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERDISPLAYWIDGET_H
#define UI_WEATHERDISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_weatherDisplayWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *typeComboBox;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *daysSpinBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *sizigiasCheckBox;
    FreezeTableWidget *tableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *weatherDisplayWidget)
    {
        if (weatherDisplayWidget->objectName().isEmpty())
            weatherDisplayWidget->setObjectName(QString::fromUtf8("weatherDisplayWidget"));
        weatherDisplayWidget->resize(780, 490);
        verticalLayout = new QVBoxLayout(weatherDisplayWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(weatherDisplayWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        typeComboBox = new QComboBox(weatherDisplayWidget);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));

        horizontalLayout->addWidget(typeComboBox);

        label = new QLabel(weatherDisplayWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(weatherDisplayWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(weatherDisplayWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        daysSpinBox = new QSpinBox(weatherDisplayWidget);
        daysSpinBox->setObjectName(QString::fromUtf8("daysSpinBox"));
        daysSpinBox->setMinimum(1);
        daysSpinBox->setMaximum(365);
        daysSpinBox->setValue(15);

        horizontalLayout->addWidget(daysSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sizigiasCheckBox = new QCheckBox(weatherDisplayWidget);
        sizigiasCheckBox->setObjectName(QString::fromUtf8("sizigiasCheckBox"));
        sizigiasCheckBox->setChecked(true);

        horizontalLayout->addWidget(sizigiasCheckBox);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new FreezeTableWidget(weatherDisplayWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(false);

        verticalLayout->addWidget(tableView);

        buttonBox = new QDialogButtonBox(weatherDisplayWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(weatherDisplayWidget);

        QMetaObject::connectSlotsByName(weatherDisplayWidget);
    } // setupUi

    void retranslateUi(QWidget *weatherDisplayWidget)
    {
        weatherDisplayWidget->setWindowTitle(QApplication::translate("weatherDisplayWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("weatherDisplayWidget", "Tiipo: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("weatherDisplayWidget", "Fecha Actual:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("weatherDisplayWidget", "\302\261 dias: ", 0, QApplication::UnicodeUTF8));
        sizigiasCheckBox->setText(QApplication::translate("weatherDisplayWidget", "Mostrar Sizigias", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class weatherDisplayWidget: public Ui_weatherDisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERDISPLAYWIDGET_H
