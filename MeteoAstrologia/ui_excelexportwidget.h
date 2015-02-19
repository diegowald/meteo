/********************************************************************************
** Form generated from reading UI file 'excelexportwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCELEXPORTWIDGET_H
#define UI_EXCELEXPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_excelExportWidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *addButton;
    QToolButton *delButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *allRadio;
    QRadioButton *selectedRadio;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *astralRadio;
    QRadioButton *noaaRadio;
    QRadioButton *rbdButton;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *monthRadio;
    QComboBox *typeComboBox;
    QRadioButton *annoButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *onlyRadio;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *filterButton;
    QPushButton *exportButton;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QWidget *excelExportWidget)
    {
        if (excelExportWidget->objectName().isEmpty())
            excelExportWidget->setObjectName(QString::fromUtf8("excelExportWidget"));
        excelExportWidget->resize(794, 488);
        horizontalLayout_4 = new QHBoxLayout(excelExportWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        listWidget = new QListWidget(excelExportWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QToolButton(excelExportWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/edit-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);

        horizontalLayout->addWidget(addButton);

        delButton = new QToolButton(excelExportWidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/edit-remove-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        delButton->setIcon(icon1);

        horizontalLayout->addWidget(delButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        groupBox = new QGroupBox(excelExportWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        allRadio = new QRadioButton(groupBox);
        allRadio->setObjectName(QString::fromUtf8("allRadio"));
        allRadio->setChecked(true);

        verticalLayout_3->addWidget(allRadio);

        selectedRadio = new QRadioButton(groupBox);
        selectedRadio->setObjectName(QString::fromUtf8("selectedRadio"));
        selectedRadio->setChecked(false);

        verticalLayout_3->addWidget(selectedRadio);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(excelExportWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        astralRadio = new QRadioButton(groupBox_2);
        astralRadio->setObjectName(QString::fromUtf8("astralRadio"));
        astralRadio->setChecked(true);

        verticalLayout_4->addWidget(astralRadio);

        noaaRadio = new QRadioButton(groupBox_2);
        noaaRadio->setObjectName(QString::fromUtf8("noaaRadio"));

        verticalLayout_4->addWidget(noaaRadio);

        rbdButton = new QRadioButton(groupBox_2);
        rbdButton->setObjectName(QString::fromUtf8("rbdButton"));

        verticalLayout_4->addWidget(rbdButton);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        monthRadio = new QRadioButton(groupBox_2);
        monthRadio->setObjectName(QString::fromUtf8("monthRadio"));

        horizontalLayout_5->addWidget(monthRadio);

        typeComboBox = new QComboBox(groupBox_2);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));
        typeComboBox->setEnabled(false);

        horizontalLayout_5->addWidget(typeComboBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        annoButton = new QRadioButton(groupBox_2);
        annoButton->setObjectName(QString::fromUtf8("annoButton"));

        verticalLayout_4->addWidget(annoButton);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(excelExportWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        onlyRadio = new QRadioButton(groupBox_3);
        onlyRadio->setObjectName(QString::fromUtf8("onlyRadio"));
        onlyRadio->setChecked(true);

        verticalLayout_5->addWidget(onlyRadio);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);

        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy2);
        spinBox->setMaximum(9999);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(groupBox_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        filterButton = new QPushButton(excelExportWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        sizePolicy2.setHeightForWidth(filterButton->sizePolicy().hasHeightForWidth());
        filterButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon2);

        verticalLayout_2->addWidget(filterButton);

        exportButton = new QPushButton(excelExportWidget);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        sizePolicy2.setHeightForWidth(exportButton->sizePolicy().hasHeightForWidth());
        exportButton->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(exportButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(excelExportWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_6->addWidget(tableWidget);


        horizontalLayout_4->addLayout(verticalLayout_6);


        retranslateUi(excelExportWidget);
        QObject::connect(radioButton_2, SIGNAL(toggled(bool)), spinBox, SLOT(setEnabled(bool)));
        QObject::connect(monthRadio, SIGNAL(toggled(bool)), typeComboBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(excelExportWidget);
    } // setupUi

    void retranslateUi(QWidget *excelExportWidget)
    {
        excelExportWidget->setWindowTitle(QApplication::translate("excelExportWidget", "Form", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("excelExportWidget", "...", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("excelExportWidget", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("excelExportWidget", "Cuales:", 0, QApplication::UnicodeUTF8));
        allRadio->setText(QApplication::translate("excelExportWidget", "Todas", 0, QApplication::UnicodeUTF8));
        selectedRadio->setText(QApplication::translate("excelExportWidget", "Fechas Seleccionadas", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("excelExportWidget", "Tipo de Exportacion:", 0, QApplication::UnicodeUTF8));
        astralRadio->setText(QApplication::translate("excelExportWidget", "Dias Astrologicos", 0, QApplication::UnicodeUTF8));
        noaaRadio->setText(QApplication::translate("excelExportWidget", "Dias NOAA", 0, QApplication::UnicodeUTF8));
        rbdButton->setText(QApplication::translate("excelExportWidget", "Dias RBD", 0, QApplication::UnicodeUTF8));
        monthRadio->setText(QApplication::translate("excelExportWidget", "Meses", 0, QApplication::UnicodeUTF8));
        annoButton->setText(QApplication::translate("excelExportWidget", "A\303\261os", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("excelExportWidget", "Rangos", 0, QApplication::UnicodeUTF8));
        onlyRadio->setText(QApplication::translate("excelExportWidget", "Solo lo seleccionado", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("excelExportWidget", "Agregar elementos ", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("excelExportWidget", "Filtrar", 0, QApplication::UnicodeUTF8));
        exportButton->setText(QApplication::translate("excelExportWidget", "Exportar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class excelExportWidget: public Ui_excelExportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCELEXPORTWIDGET_H
