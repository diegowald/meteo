/********************************************************************************
** Form generated from reading UI file 'processbymonths.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSBYMONTHS_H
#define UI_PROCESSBYMONTHS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processByMonths
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *mesLabel;
    QSpinBox *mesSpinBox;
    QLabel *lluviasLabel;
    QDoubleSpinBox *lluviasDoubleSpinBox;
    QLabel *toleranciaLabel;
    QDoubleSpinBox *toleranciaDoubleSpinBox;
    QPushButton *filterButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableView *monthResultTableView;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QTableView *dayResultTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_8;
    QTableView *noaaResultTableView;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QTableView *AspectsTableView;
    QLabel *label_3;
    QTableView *positionTableView;
    QLabel *label_4;
    QTableView *housesTableView;
    QLabel *label_6;
    QTableView *signsTableView;
    QLabel *label_7;
    QTableView *quadrantsTableView;

    void setupUi(QWidget *processByMonths)
    {
        if (processByMonths->objectName().isEmpty())
            processByMonths->setObjectName(QString::fromUtf8("processByMonths"));
        processByMonths->resize(743, 620);
        verticalLayout_5 = new QVBoxLayout(processByMonths);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(15, -1, 0, -1);
        groupBox = new QGroupBox(processByMonths);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        mesLabel = new QLabel(groupBox);
        mesLabel->setObjectName(QString::fromUtf8("mesLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, mesLabel);

        mesSpinBox = new QSpinBox(groupBox);
        mesSpinBox->setObjectName(QString::fromUtf8("mesSpinBox"));
        mesSpinBox->setMinimum(1);
        mesSpinBox->setMaximum(12);

        formLayout->setWidget(0, QFormLayout::FieldRole, mesSpinBox);

        lluviasLabel = new QLabel(groupBox);
        lluviasLabel->setObjectName(QString::fromUtf8("lluviasLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lluviasLabel);

        lluviasDoubleSpinBox = new QDoubleSpinBox(groupBox);
        lluviasDoubleSpinBox->setObjectName(QString::fromUtf8("lluviasDoubleSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lluviasDoubleSpinBox);

        toleranciaLabel = new QLabel(groupBox);
        toleranciaLabel->setObjectName(QString::fromUtf8("toleranciaLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, toleranciaLabel);

        toleranciaDoubleSpinBox = new QDoubleSpinBox(groupBox);
        toleranciaDoubleSpinBox->setObjectName(QString::fromUtf8("toleranciaDoubleSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, toleranciaDoubleSpinBox);


        verticalLayout->addLayout(formLayout);

        filterButton = new QPushButton(groupBox);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon);

        verticalLayout->addWidget(filterButton);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(processByMonths);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        monthResultTableView = new QTableView(groupBox_2);
        monthResultTableView->setObjectName(QString::fromUtf8("monthResultTableView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monthResultTableView->sizePolicy().hasHeightForWidth());
        monthResultTableView->setSizePolicy(sizePolicy);
        monthResultTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        monthResultTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        monthResultTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        monthResultTableView->setSortingEnabled(true);

        verticalLayout_2->addWidget(monthResultTableView);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        dayResultTableView = new QTableView(tab);
        dayResultTableView->setObjectName(QString::fromUtf8("dayResultTableView"));
        dayResultTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        dayResultTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        dayResultTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        dayResultTableView->setSortingEnabled(true);

        verticalLayout_7->addWidget(dayResultTableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_8 = new QVBoxLayout(tab_2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        noaaResultTableView = new QTableView(tab_2);
        noaaResultTableView->setObjectName(QString::fromUtf8("noaaResultTableView"));
        noaaResultTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_8->addWidget(noaaResultTableView);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);


        horizontalLayout_3->addLayout(verticalLayout_3);


        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(processByMonths);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea = new QScrollArea(groupBox_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 686, 1097));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        AspectsTableView = new QTableView(scrollAreaWidgetContents);
        AspectsTableView->setObjectName(QString::fromUtf8("AspectsTableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AspectsTableView->sizePolicy().hasHeightForWidth());
        AspectsTableView->setSizePolicy(sizePolicy1);
        AspectsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        AspectsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        AspectsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        AspectsTableView->setSortingEnabled(true);

        verticalLayout_6->addWidget(AspectsTableView);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_6->addWidget(label_3);

        positionTableView = new QTableView(scrollAreaWidgetContents);
        positionTableView->setObjectName(QString::fromUtf8("positionTableView"));
        sizePolicy1.setHeightForWidth(positionTableView->sizePolicy().hasHeightForWidth());
        positionTableView->setSizePolicy(sizePolicy1);
        positionTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        positionTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        positionTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        positionTableView->setSortingEnabled(true);

        verticalLayout_6->addWidget(positionTableView);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_6->addWidget(label_4);

        housesTableView = new QTableView(scrollAreaWidgetContents);
        housesTableView->setObjectName(QString::fromUtf8("housesTableView"));
        sizePolicy1.setHeightForWidth(housesTableView->sizePolicy().hasHeightForWidth());
        housesTableView->setSizePolicy(sizePolicy1);
        housesTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        housesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        housesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        housesTableView->setSortingEnabled(false);

        verticalLayout_6->addWidget(housesTableView);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        signsTableView = new QTableView(scrollAreaWidgetContents);
        signsTableView->setObjectName(QString::fromUtf8("signsTableView"));
        sizePolicy1.setHeightForWidth(signsTableView->sizePolicy().hasHeightForWidth());
        signsTableView->setSizePolicy(sizePolicy1);
        signsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        signsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        signsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        signsTableView->setSortingEnabled(true);

        verticalLayout_6->addWidget(signsTableView);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        quadrantsTableView = new QTableView(scrollAreaWidgetContents);
        quadrantsTableView->setObjectName(QString::fromUtf8("quadrantsTableView"));
        sizePolicy1.setHeightForWidth(quadrantsTableView->sizePolicy().hasHeightForWidth());
        quadrantsTableView->setSizePolicy(sizePolicy1);
        quadrantsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        quadrantsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        quadrantsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        quadrantsTableView->setSortingEnabled(true);

        verticalLayout_6->addWidget(quadrantsTableView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        verticalLayout_5->addWidget(groupBox_3);


        retranslateUi(processByMonths);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(processByMonths);
    } // setupUi

    void retranslateUi(QWidget *processByMonths)
    {
        processByMonths->setWindowTitle(QApplication::translate("processByMonths", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("processByMonths", "Datos:", 0, QApplication::UnicodeUTF8));
        mesLabel->setText(QApplication::translate("processByMonths", "Mes:", 0, QApplication::UnicodeUTF8));
        lluviasLabel->setText(QApplication::translate("processByMonths", "Lluvias:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel->setText(QApplication::translate("processByMonths", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("processByMonths", "Filtrar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("processByMonths", "Resultados:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("processByMonths", "Meses-A\303\261o", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("processByMonths", "Dias del periodo Seleccionado", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("processByMonths", "Base RDB (Astrales)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("processByMonths", "Base NOAA", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("processByMonths", "Estados Astrlogicos", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("processByMonths", "Aspectos:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("processByMonths", "Posiciones:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("processByMonths", "Casas:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("processByMonths", "Signos:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("processByMonths", "Cuadrantes:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processByMonths: public Ui_processByMonths {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSBYMONTHS_H
