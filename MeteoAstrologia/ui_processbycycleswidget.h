/********************************************************************************
** Form generated from reading UI file 'processbycycleswidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSBYCYCLESWIDGET_H
#define UI_PROCESSBYCYCLESWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_processByCyclesWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *tipoFechaLabel;
    QComboBox *tipoFechaComboBox;
    QLabel *diaLabel;
    QComboBox *diaComboBox;
    QPushButton *filterButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListView *phase96ListView;
    QListView *phase37ListView;
    QListView *phase19ListView;
    QListView *nMonthListView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *nMonthSpinBox;
    QLabel *label_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    FreezeTableWidget *monthTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    FreezeTableWidget *daysTableView;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    FreezeTableWidget *astrologycalDaysTableView;

    void setupUi(QWidget *processByCyclesWidget)
    {
        if (processByCyclesWidget->objectName().isEmpty())
            processByCyclesWidget->setObjectName(QString::fromUtf8("processByCyclesWidget"));
        processByCyclesWidget->resize(719, 554);
        verticalLayout_3 = new QVBoxLayout(processByCyclesWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, -1, -1);
        groupBox = new QGroupBox(processByCyclesWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tipoFechaLabel = new QLabel(groupBox);
        tipoFechaLabel->setObjectName(QString::fromUtf8("tipoFechaLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tipoFechaLabel);

        tipoFechaComboBox = new QComboBox(groupBox);
        tipoFechaComboBox->setObjectName(QString::fromUtf8("tipoFechaComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tipoFechaComboBox);

        diaLabel = new QLabel(groupBox);
        diaLabel->setObjectName(QString::fromUtf8("diaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, diaLabel);

        diaComboBox = new QComboBox(groupBox);
        diaComboBox->setObjectName(QString::fromUtf8("diaComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, diaComboBox);


        verticalLayout->addLayout(formLayout);

        filterButton = new QPushButton(groupBox);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon);

        verticalLayout->addWidget(filterButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(processByCyclesWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        phase96ListView = new QListView(groupBox_2);
        phase96ListView->setObjectName(QString::fromUtf8("phase96ListView"));

        gridLayout->addWidget(phase96ListView, 1, 0, 1, 1);

        phase37ListView = new QListView(groupBox_2);
        phase37ListView->setObjectName(QString::fromUtf8("phase37ListView"));

        gridLayout->addWidget(phase37ListView, 1, 1, 1, 1);

        phase19ListView = new QListView(groupBox_2);
        phase19ListView->setObjectName(QString::fromUtf8("phase19ListView"));

        gridLayout->addWidget(phase19ListView, 1, 2, 1, 1);

        nMonthListView = new QListView(groupBox_2);
        nMonthListView->setObjectName(QString::fromUtf8("nMonthListView"));

        gridLayout->addWidget(nMonthListView, 1, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_4);

        nMonthSpinBox = new QSpinBox(groupBox_2);
        nMonthSpinBox->setObjectName(QString::fromUtf8("nMonthSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nMonthSpinBox->sizePolicy().hasHeightForWidth());
        nMonthSpinBox->setSizePolicy(sizePolicy1);
        nMonthSpinBox->setMinimum(1);
        nMonthSpinBox->setMaximum(200);

        horizontalLayout_2->addWidget(nMonthSpinBox);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);


        gridLayout->addLayout(horizontalLayout_2, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(processByCyclesWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        monthTableView = new FreezeTableWidget(tab);
        monthTableView->setObjectName(QString::fromUtf8("monthTableView"));
        monthTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        monthTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        monthTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        monthTableView->setSortingEnabled(true);

        verticalLayout_4->addWidget(monthTableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        daysTableView = new FreezeTableWidget(tab_2);
        daysTableView->setObjectName(QString::fromUtf8("daysTableView"));
        daysTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        daysTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        daysTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        daysTableView->setSortingEnabled(true);

        verticalLayout_5->addWidget(daysTableView);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        astrologycalDaysTableView = new FreezeTableWidget(tab_3);
        astrologycalDaysTableView->setObjectName(QString::fromUtf8("astrologycalDaysTableView"));
        astrologycalDaysTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        astrologycalDaysTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        astrologycalDaysTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        astrologycalDaysTableView->setSortingEnabled(true);

        verticalLayout_6->addWidget(astrologycalDaysTableView);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(processByCyclesWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(processByCyclesWidget);
    } // setupUi

    void retranslateUi(QWidget *processByCyclesWidget)
    {
        processByCyclesWidget->setWindowTitle(QApplication::translate("processByCyclesWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("processByCyclesWidget", "Datos:", 0, QApplication::UnicodeUTF8));
        tipoFechaLabel->setText(QApplication::translate("processByCyclesWidget", "Tipo Fecha", 0, QApplication::UnicodeUTF8));
        diaLabel->setText(QApplication::translate("processByCyclesWidget", "Dia:", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("processByCyclesWidget", "Filtrar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("processByCyclesWidget", "Resultados:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("processByCyclesWidget", "Fase R 96 meses", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("processByCyclesWidget", "+ 37 a\303\261os", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("processByCyclesWidget", "Fase lunar 18.6 a\303\261os", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("processByCyclesWidget", "Fase ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("processByCyclesWidget", "meses", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("processByCyclesWidget", "Meses", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("processByCyclesWidget", "Dias", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("processByCyclesWidget", "Dias Astrologicos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processByCyclesWidget: public Ui_processByCyclesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSBYCYCLESWIDGET_H
