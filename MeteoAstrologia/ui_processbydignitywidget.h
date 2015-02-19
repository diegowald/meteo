/********************************************************************************
** Form generated from reading UI file 'processbydignitywidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSBYDIGNITYWIDGET_H
#define UI_PROCESSBYDIGNITYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_processByDignityWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *tipoLabel;
    QComboBox *tipoComboBox;
    QLabel *fechaLabel;
    QComboBox *fechaComboBox;
    QPushButton *dignityFilterButton;
    QTableWidget *dignityTableWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *addButton;
    QToolButton *delButton;
    QPushButton *filterButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    FreezeTableWidget *tableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    FreezeTableWidget *noaaTableView;

    void setupUi(QWidget *processByDignityWidget)
    {
        if (processByDignityWidget->objectName().isEmpty())
            processByDignityWidget->setObjectName(QString::fromUtf8("processByDignityWidget"));
        processByDignityWidget->resize(640, 480);
        horizontalLayout_2 = new QHBoxLayout(processByDignityWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        groupBox = new QGroupBox(processByDignityWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tipoLabel = new QLabel(groupBox);
        tipoLabel->setObjectName(QString::fromUtf8("tipoLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tipoLabel);

        tipoComboBox = new QComboBox(groupBox);
        tipoComboBox->setObjectName(QString::fromUtf8("tipoComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tipoComboBox);

        fechaLabel = new QLabel(groupBox);
        fechaLabel->setObjectName(QString::fromUtf8("fechaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, fechaLabel);

        fechaComboBox = new QComboBox(groupBox);
        fechaComboBox->setObjectName(QString::fromUtf8("fechaComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fechaComboBox);


        verticalLayout->addLayout(formLayout);

        dignityFilterButton = new QPushButton(groupBox);
        dignityFilterButton->setObjectName(QString::fromUtf8("dignityFilterButton"));

        verticalLayout->addWidget(dignityFilterButton);


        verticalLayout_2->addWidget(groupBox);

        dignityTableWidget = new QTableWidget(processByDignityWidget);
        dignityTableWidget->setObjectName(QString::fromUtf8("dignityTableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dignityTableWidget->sizePolicy().hasHeightForWidth());
        dignityTableWidget->setSizePolicy(sizePolicy);
        dignityTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        dignityTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        dignityTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(dignityTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QToolButton(processByDignityWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/edit-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);

        horizontalLayout->addWidget(addButton);

        delButton = new QToolButton(processByDignityWidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/edit-remove-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        delButton->setIcon(icon1);

        horizontalLayout->addWidget(delButton);

        filterButton = new QPushButton(processByDignityWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon2);

        horizontalLayout->addWidget(filterButton);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(processByDignityWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        tabWidget = new QTabWidget(processByDignityWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableView = new FreezeTableWidget(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout_4->addWidget(tableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        noaaTableView = new FreezeTableWidget(tab_2);
        noaaTableView->setObjectName(QString::fromUtf8("noaaTableView"));
        noaaTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        noaaTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        noaaTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_5->addWidget(noaaTableView);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(processByDignityWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(processByDignityWidget);
    } // setupUi

    void retranslateUi(QWidget *processByDignityWidget)
    {
        processByDignityWidget->setWindowTitle(QApplication::translate("processByDignityWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("processByDignityWidget", "Seleccionar Fecha: ", 0, QApplication::UnicodeUTF8));
        tipoLabel->setText(QApplication::translate("processByDignityWidget", "Tipo:", 0, QApplication::UnicodeUTF8));
        fechaLabel->setText(QApplication::translate("processByDignityWidget", "Fecha:", 0, QApplication::UnicodeUTF8));
        dignityFilterButton->setText(QApplication::translate("processByDignityWidget", "Calcular Dignidades", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("processByDignityWidget", "...", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("processByDignityWidget", "...", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("processByDignityWidget", "Filtrar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("processByDignityWidget", "Fecha Resultado:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("processByDignityWidget", "Astrales", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("processByDignityWidget", "NOAA", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processByDignityWidget: public Ui_processByDignityWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSBYDIGNITYWIDGET_H
