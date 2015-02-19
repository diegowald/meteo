/********************************************************************************
** Form generated from reading UI file 'processdatawidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSDATAWIDGET_H
#define UI_PROCESSDATAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processDataWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QDateEdit *initDateEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QDateEdit *finishDateEdit;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *aspectTableWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addAspectButton;
    QPushButton *modAspectButton;
    QPushButton *delAspectButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *weatherTableWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addWeatherButton;
    QPushButton *modWeatherButton;
    QPushButton *delWeatherButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *processWeatherButton;
    QPushButton *processAspectButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView;

    void setupUi(QWidget *processDataWidget)
    {
        if (processDataWidget->objectName().isEmpty())
            processDataWidget->setObjectName(QString::fromUtf8("processDataWidget"));
        processDataWidget->resize(732, 544);
        verticalLayout = new QVBoxLayout(processDataWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(processDataWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        initDateEdit = new QDateEdit(processDataWidget);
        initDateEdit->setObjectName(QString::fromUtf8("initDateEdit"));
        initDateEdit->setCalendarPopup(true);

        horizontalLayout_5->addWidget(initDateEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_2 = new QLabel(processDataWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        finishDateEdit = new QDateEdit(processDataWidget);
        finishDateEdit->setObjectName(QString::fromUtf8("finishDateEdit"));
        finishDateEdit->setCalendarPopup(true);

        horizontalLayout_5->addWidget(finishDateEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        groupBox = new QGroupBox(processDataWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        aspectTableWidget = new QTableWidget(groupBox);
        aspectTableWidget->setObjectName(QString::fromUtf8("aspectTableWidget"));
        aspectTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        aspectTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_3->addWidget(aspectTableWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        addAspectButton = new QPushButton(groupBox);
        addAspectButton->setObjectName(QString::fromUtf8("addAspectButton"));

        verticalLayout_2->addWidget(addAspectButton);

        modAspectButton = new QPushButton(groupBox);
        modAspectButton->setObjectName(QString::fromUtf8("modAspectButton"));

        verticalLayout_2->addWidget(modAspectButton);

        delAspectButton = new QPushButton(groupBox);
        delAspectButton->setObjectName(QString::fromUtf8("delAspectButton"));

        verticalLayout_2->addWidget(delAspectButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(processDataWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        weatherTableWidget = new QTableWidget(groupBox_2);
        weatherTableWidget->setObjectName(QString::fromUtf8("weatherTableWidget"));
        weatherTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        weatherTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_4->addWidget(weatherTableWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 0, -1);
        addWeatherButton = new QPushButton(groupBox_2);
        addWeatherButton->setObjectName(QString::fromUtf8("addWeatherButton"));

        verticalLayout_3->addWidget(addWeatherButton);

        modWeatherButton = new QPushButton(groupBox_2);
        modWeatherButton->setObjectName(QString::fromUtf8("modWeatherButton"));

        verticalLayout_3->addWidget(modWeatherButton);

        delWeatherButton = new QPushButton(groupBox_2);
        delWeatherButton->setObjectName(QString::fromUtf8("delWeatherButton"));

        verticalLayout_3->addWidget(delWeatherButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        processWeatherButton = new QPushButton(processDataWidget);
        processWeatherButton->setObjectName(QString::fromUtf8("processWeatherButton"));

        horizontalLayout_2->addWidget(processWeatherButton);

        processAspectButton = new QPushButton(processDataWidget);
        processAspectButton->setObjectName(QString::fromUtf8("processAspectButton"));

        horizontalLayout_2->addWidget(processAspectButton);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(processDataWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout_4->addWidget(tableView);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(processDataWidget);

        QMetaObject::connectSlotsByName(processDataWidget);
    } // setupUi

    void retranslateUi(QWidget *processDataWidget)
    {
        processDataWidget->setWindowTitle(QApplication::translate("processDataWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("processDataWidget", "Fecha Inicio: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("processDataWidget", "Fecha Final:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("processDataWidget", "Aspectos", 0, QApplication::UnicodeUTF8));
        addAspectButton->setText(QApplication::translate("processDataWidget", "Agregar", 0, QApplication::UnicodeUTF8));
        modAspectButton->setText(QApplication::translate("processDataWidget", "Modificar", 0, QApplication::UnicodeUTF8));
        delAspectButton->setText(QApplication::translate("processDataWidget", "Borrar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("processDataWidget", "Estados", 0, QApplication::UnicodeUTF8));
        addWeatherButton->setText(QApplication::translate("processDataWidget", "Agregar", 0, QApplication::UnicodeUTF8));
        modWeatherButton->setText(QApplication::translate("processDataWidget", "Modificar", 0, QApplication::UnicodeUTF8));
        delWeatherButton->setText(QApplication::translate("processDataWidget", "Borrar", 0, QApplication::UnicodeUTF8));
        processWeatherButton->setText(QApplication::translate("processDataWidget", "Procesar Estados", 0, QApplication::UnicodeUTF8));
        processAspectButton->setText(QApplication::translate("processDataWidget", "Procesar Aspectos", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("processDataWidget", "Prosesado:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processDataWidget: public Ui_processDataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSDATAWIDGET_H
