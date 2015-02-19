/********************************************************************************
** Form generated from reading UI file 'sizigiaexcelreportwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZIGIAEXCELREPORTWIDGET_H
#define UI_SIZIGIAEXCELREPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sizigiaExcelReportWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *tipoDeDatoLabel;
    QComboBox *tipoDeDatoComboBox;
    QLabel *fechaLabel;
    QComboBox *fechaComboBox;
    QLabel *aExportarLabel;
    QComboBox *aExportarComboBox;
    QCheckBox *allInCheckBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filterButton;
    QPushButton *exportButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *sizigiaExcelReportWidget)
    {
        if (sizigiaExcelReportWidget->objectName().isEmpty())
            sizigiaExcelReportWidget->setObjectName(QString::fromUtf8("sizigiaExcelReportWidget"));
        sizigiaExcelReportWidget->resize(640, 480);
        verticalLayout = new QVBoxLayout(sizigiaExcelReportWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(sizigiaExcelReportWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        tipoDeDatoLabel = new QLabel(groupBox);
        tipoDeDatoLabel->setObjectName(QString::fromUtf8("tipoDeDatoLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tipoDeDatoLabel);

        tipoDeDatoComboBox = new QComboBox(groupBox);
        tipoDeDatoComboBox->setObjectName(QString::fromUtf8("tipoDeDatoComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tipoDeDatoComboBox);

        fechaLabel = new QLabel(groupBox);
        fechaLabel->setObjectName(QString::fromUtf8("fechaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, fechaLabel);

        fechaComboBox = new QComboBox(groupBox);
        fechaComboBox->setObjectName(QString::fromUtf8("fechaComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fechaComboBox);

        aExportarLabel = new QLabel(groupBox);
        aExportarLabel->setObjectName(QString::fromUtf8("aExportarLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, aExportarLabel);

        aExportarComboBox = new QComboBox(groupBox);
        aExportarComboBox->setObjectName(QString::fromUtf8("aExportarComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, aExportarComboBox);

        allInCheckBox = new QCheckBox(groupBox);
        allInCheckBox->setObjectName(QString::fromUtf8("allInCheckBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, allInCheckBox);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        filterButton = new QPushButton(groupBox);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon);

        horizontalLayout_2->addWidget(filterButton);

        exportButton = new QPushButton(groupBox);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));

        horizontalLayout_2->addWidget(exportButton);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);

        tableWidget = new QTableWidget(sizigiaExcelReportWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(sizigiaExcelReportWidget);

        QMetaObject::connectSlotsByName(sizigiaExcelReportWidget);
    } // setupUi

    void retranslateUi(QWidget *sizigiaExcelReportWidget)
    {
        sizigiaExcelReportWidget->setWindowTitle(QApplication::translate("sizigiaExcelReportWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("sizigiaExcelReportWidget", "Datos:", 0, QApplication::UnicodeUTF8));
        tipoDeDatoLabel->setText(QApplication::translate("sizigiaExcelReportWidget", "Tipo de Dato:", 0, QApplication::UnicodeUTF8));
        fechaLabel->setText(QApplication::translate("sizigiaExcelReportWidget", "Fecha:", 0, QApplication::UnicodeUTF8));
        aExportarLabel->setText(QApplication::translate("sizigiaExcelReportWidget", "A Exportar:", 0, QApplication::UnicodeUTF8));
        allInCheckBox->setText(QApplication::translate("sizigiaExcelReportWidget", "Incluir a todos", 0, QApplication::UnicodeUTF8));
        filterButton->setText(QApplication::translate("sizigiaExcelReportWidget", "Filtrar", 0, QApplication::UnicodeUTF8));
        exportButton->setText(QApplication::translate("sizigiaExcelReportWidget", "Exportar a Excel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sizigiaExcelReportWidget: public Ui_sizigiaExcelReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZIGIAEXCELREPORTWIDGET_H
