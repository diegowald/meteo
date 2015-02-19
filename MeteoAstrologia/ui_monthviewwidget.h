/********************************************************************************
** Form generated from reading UI file 'monthviewwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHVIEWWIDGET_H
#define UI_MONTHVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_monthViewWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    FreezeTableWidget *monthTableView;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    FreezeTableWidget *dailyTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    FreezeTableWidget *astroDailyTableView;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *astralComboBox;
    FreezeTableWidget *astralTableView;

    void setupUi(QWidget *monthViewWidget)
    {
        if (monthViewWidget->objectName().isEmpty())
            monthViewWidget->setObjectName(QString::fromUtf8("monthViewWidget"));
        monthViewWidget->resize(683, 458);
        verticalLayout_2 = new QVBoxLayout(monthViewWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(monthViewWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        monthTableView = new FreezeTableWidget(tab);
        monthTableView->setObjectName(QString::fromUtf8("monthTableView"));
        monthTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        monthTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        monthTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        monthTableView->setSortingEnabled(false);

        verticalLayout->addWidget(monthTableView);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        dailyTableView = new FreezeTableWidget(tab_4);
        dailyTableView->setObjectName(QString::fromUtf8("dailyTableView"));
        dailyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        dailyTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        dailyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        dailyTableView->setSortingEnabled(false);

        verticalLayout_4->addWidget(dailyTableView);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        astroDailyTableView = new FreezeTableWidget(tab_2);
        astroDailyTableView->setObjectName(QString::fromUtf8("astroDailyTableView"));
        astroDailyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        astroDailyTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        astroDailyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        astroDailyTableView->setSortingEnabled(false);

        verticalLayout_3->addWidget(astroDailyTableView);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        astralComboBox = new QComboBox(tab_3);
        astralComboBox->setObjectName(QString::fromUtf8("astralComboBox"));

        horizontalLayout->addWidget(astralComboBox);


        verticalLayout_5->addLayout(horizontalLayout);

        astralTableView = new FreezeTableWidget(tab_3);
        astralTableView->setObjectName(QString::fromUtf8("astralTableView"));
        astralTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        astralTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        astralTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        astralTableView->setSortingEnabled(false);

        verticalLayout_5->addWidget(astralTableView);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(monthViewWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(monthViewWidget);
    } // setupUi

    void retranslateUi(QWidget *monthViewWidget)
    {
        monthViewWidget->setWindowTitle(QApplication::translate("monthViewWidget", "Form", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("monthViewWidget", "Datos Mensuales", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("monthViewWidget", "Datos Diarios Registro", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("monthViewWidget", "Datos Diarios Astrologicos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("monthViewWidget", "Tabla:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("monthViewWidget", "Datos Astrales", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class monthViewWidget: public Ui_monthViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHVIEWWIDGET_H
