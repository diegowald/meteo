/********************************************************************************
** Form generated from reading UI file 'processbyaspectwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSBYASPECTWIDGET_H
#define UI_PROCESSBYASPECTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processByAspectWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *aspectTableWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *addlButton;
    QToolButton *dellButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *filterButton;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTableView *occurenciasTableView;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableView *astroTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *dairyTableView;

    void setupUi(QWidget *processByAspectWidget)
    {
        if (processByAspectWidget->objectName().isEmpty())
            processByAspectWidget->setObjectName(QString::fromUtf8("processByAspectWidget"));
        processByAspectWidget->resize(712, 478);
        horizontalLayout_2 = new QHBoxLayout(processByAspectWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(-1, -1, -1, 10);
        label = new QLabel(processByAspectWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        aspectTableWidget = new QTableWidget(processByAspectWidget);
        aspectTableWidget->setObjectName(QString::fromUtf8("aspectTableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aspectTableWidget->sizePolicy().hasHeightForWidth());
        aspectTableWidget->setSizePolicy(sizePolicy);
        aspectTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        aspectTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        aspectTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(aspectTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addlButton = new QToolButton(processByAspectWidget);
        addlButton->setObjectName(QString::fromUtf8("addlButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/edit-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addlButton->setIcon(icon);

        horizontalLayout->addWidget(addlButton);

        dellButton = new QToolButton(processByAspectWidget);
        dellButton->setObjectName(QString::fromUtf8("dellButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/edit-remove-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        dellButton->setIcon(icon1);

        horizontalLayout->addWidget(dellButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        filterButton = new QPushButton(processByAspectWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon2);

        horizontalLayout->addWidget(filterButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget = new QTabWidget(processByAspectWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        occurenciasTableView = new QTableView(tab_3);
        occurenciasTableView->setObjectName(QString::fromUtf8("occurenciasTableView"));
        sizePolicy.setHeightForWidth(occurenciasTableView->sizePolicy().hasHeightForWidth());
        occurenciasTableView->setSizePolicy(sizePolicy);
        occurenciasTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        occurenciasTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        occurenciasTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        occurenciasTableView->setSortingEnabled(true);

        verticalLayout_4->addWidget(occurenciasTableView);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        astroTableView = new QTableView(tab);
        astroTableView->setObjectName(QString::fromUtf8("astroTableView"));
        astroTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        astroTableView->setAlternatingRowColors(true);
        astroTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(astroTableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dairyTableView = new QTableView(tab_2);
        dairyTableView->setObjectName(QString::fromUtf8("dairyTableView"));
        dairyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        dairyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(dairyTableView);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);


        retranslateUi(processByAspectWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(processByAspectWidget);
    } // setupUi

    void retranslateUi(QWidget *processByAspectWidget)
    {
        processByAspectWidget->setWindowTitle(QApplication::translate("processByAspectWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("processByAspectWidget", "Aspectos:", 0, QApplication::UnicodeUTF8));
        addlButton->setText(QApplication::translate("processByAspectWidget", "...", 0, QApplication::UnicodeUTF8));
        dellButton->setText(QApplication::translate("processByAspectWidget", "...", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("processByAspectWidget", "Filtrar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("processByAspectWidget", "Ocurrencias por Signo:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("processByAspectWidget", "Tiempos Astrologicos", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("processByAspectWidget", "Tiempos Diarios", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processByAspectWidget: public Ui_processByAspectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSBYASPECTWIDGET_H
