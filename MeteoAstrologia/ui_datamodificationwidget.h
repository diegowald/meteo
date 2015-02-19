/********************************************************************************
** Form generated from reading UI file 'datamodificationwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMODIFICATIONWIDGET_H
#define UI_DATAMODIFICATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataModificationWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *filterGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *typeComboBox;
    QLabel *label;
    QComboBox *dateComboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *loadButton;
    QGroupBox *dataGroupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QComboBox *kindComboBox;
    QHBoxLayout *horizontalLayout_8;
    QFormLayout *formLayout;
    QLabel *tempMaxLabel;
    QDoubleSpinBox *tempMaxDoubleSpinBox;
    QLabel *tempMinLabel;
    QDoubleSpinBox *tempMinDoubleSpinBox;
    QLabel *presionLabel;
    QDoubleSpinBox *precipitacionSpinBox;
    QFormLayout *formLayout_2;
    QLabel *velVientoLabel;
    QLabel *dirVientoLabel;
    QSpinBox *dirVientoSpinBox;
    QLabel *data1000500Label;
    QDoubleSpinBox *velVientoDoubleSpinBox;
    QSpinBox *data1000500SpinBox;
    QPlainTextEdit *observacionTextEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *delButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *dataModificationWidget)
    {
        if (dataModificationWidget->objectName().isEmpty())
            dataModificationWidget->setObjectName(QString::fromUtf8("dataModificationWidget"));
        dataModificationWidget->resize(640, 480);
        verticalLayout = new QVBoxLayout(dataModificationWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        filterGroupBox = new QGroupBox(dataModificationWidget);
        filterGroupBox->setObjectName(QString::fromUtf8("filterGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterGroupBox->sizePolicy().hasHeightForWidth());
        filterGroupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(filterGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(filterGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        typeComboBox = new QComboBox(filterGroupBox);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));

        horizontalLayout->addWidget(typeComboBox);

        label = new QLabel(filterGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateComboBox = new QComboBox(filterGroupBox);
        dateComboBox->setObjectName(QString::fromUtf8("dateComboBox"));

        horizontalLayout->addWidget(dateComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loadButton = new QPushButton(filterGroupBox);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        horizontalLayout->addWidget(loadButton);


        verticalLayout->addWidget(filterGroupBox);

        dataGroupBox = new QGroupBox(dataModificationWidget);
        dataGroupBox->setObjectName(QString::fromUtf8("dataGroupBox"));
        dataGroupBox->setEnabled(false);
        dataGroupBox->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(dataGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(dataGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        kindComboBox = new QComboBox(dataGroupBox);
        kindComboBox->setObjectName(QString::fromUtf8("kindComboBox"));

        horizontalLayout_2->addWidget(kindComboBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, 0, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tempMaxLabel = new QLabel(dataGroupBox);
        tempMaxLabel->setObjectName(QString::fromUtf8("tempMaxLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tempMaxLabel);

        tempMaxDoubleSpinBox = new QDoubleSpinBox(dataGroupBox);
        tempMaxDoubleSpinBox->setObjectName(QString::fromUtf8("tempMaxDoubleSpinBox"));
        tempMaxDoubleSpinBox->setMinimum(-9.999e+07);

        formLayout->setWidget(0, QFormLayout::FieldRole, tempMaxDoubleSpinBox);

        tempMinLabel = new QLabel(dataGroupBox);
        tempMinLabel->setObjectName(QString::fromUtf8("tempMinLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, tempMinLabel);

        tempMinDoubleSpinBox = new QDoubleSpinBox(dataGroupBox);
        tempMinDoubleSpinBox->setObjectName(QString::fromUtf8("tempMinDoubleSpinBox"));
        tempMinDoubleSpinBox->setMinimum(-990000);

        formLayout->setWidget(1, QFormLayout::FieldRole, tempMinDoubleSpinBox);

        presionLabel = new QLabel(dataGroupBox);
        presionLabel->setObjectName(QString::fromUtf8("presionLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, presionLabel);

        precipitacionSpinBox = new QDoubleSpinBox(dataGroupBox);
        precipitacionSpinBox->setObjectName(QString::fromUtf8("precipitacionSpinBox"));
        precipitacionSpinBox->setMinimum(-99);

        formLayout->setWidget(2, QFormLayout::FieldRole, precipitacionSpinBox);


        horizontalLayout_8->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        velVientoLabel = new QLabel(dataGroupBox);
        velVientoLabel->setObjectName(QString::fromUtf8("velVientoLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, velVientoLabel);

        dirVientoLabel = new QLabel(dataGroupBox);
        dirVientoLabel->setObjectName(QString::fromUtf8("dirVientoLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, dirVientoLabel);

        dirVientoSpinBox = new QSpinBox(dataGroupBox);
        dirVientoSpinBox->setObjectName(QString::fromUtf8("dirVientoSpinBox"));
        dirVientoSpinBox->setMinimum(-99);
        dirVientoSpinBox->setMaximum(32);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, dirVientoSpinBox);

        data1000500Label = new QLabel(dataGroupBox);
        data1000500Label->setObjectName(QString::fromUtf8("data1000500Label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, data1000500Label);

        velVientoDoubleSpinBox = new QDoubleSpinBox(dataGroupBox);
        velVientoDoubleSpinBox->setObjectName(QString::fromUtf8("velVientoDoubleSpinBox"));
        velVientoDoubleSpinBox->setMinimum(-99);
        velVientoDoubleSpinBox->setMaximum(999.99);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, velVientoDoubleSpinBox);

        data1000500SpinBox = new QSpinBox(dataGroupBox);
        data1000500SpinBox->setObjectName(QString::fromUtf8("data1000500SpinBox"));
        data1000500SpinBox->setMinimum(-99);
        data1000500SpinBox->setMaximum(9999);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, data1000500SpinBox);


        horizontalLayout_8->addLayout(formLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        observacionTextEdit = new QPlainTextEdit(dataGroupBox);
        observacionTextEdit->setObjectName(QString::fromUtf8("observacionTextEdit"));

        verticalLayout_2->addWidget(observacionTextEdit);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        delButton = new QPushButton(dataGroupBox);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        horizontalLayout_9->addWidget(delButton);

        buttonBox = new QDialogButtonBox(dataGroupBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        horizontalLayout_9->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout->addWidget(dataGroupBox);


        retranslateUi(dataModificationWidget);

        QMetaObject::connectSlotsByName(dataModificationWidget);
    } // setupUi

    void retranslateUi(QWidget *dataModificationWidget)
    {
        dataModificationWidget->setWindowTitle(QApplication::translate("dataModificationWidget", "Modificar Datos", 0, QApplication::UnicodeUTF8));
        filterGroupBox->setTitle(QApplication::translate("dataModificationWidget", "Filtro:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dataModificationWidget", "Tipo:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dataModificationWidget", "Fecha:", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("dataModificationWidget", "Cargar", 0, QApplication::UnicodeUTF8));
        dataGroupBox->setTitle(QApplication::translate("dataModificationWidget", "Datos:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dataModificationWidget", "Tipo:", 0, QApplication::UnicodeUTF8));
        kindComboBox->clear();
        kindComboBox->insertItems(0, QStringList()
         << QApplication::translate("dataModificationWidget", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dataModificationWidget", "Mensual", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dataModificationWidget", "Solsticio Verano", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dataModificationWidget", "Solsticio Invierno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dataModificationWidget", "Equinoccio Primavera", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dataModificationWidget", "Equinoccio Oto\303\261o", 0, QApplication::UnicodeUTF8)
        );
        tempMaxLabel->setText(QApplication::translate("dataModificationWidget", "Temp Max:", 0, QApplication::UnicodeUTF8));
        tempMinLabel->setText(QApplication::translate("dataModificationWidget", "Temp Min:", 0, QApplication::UnicodeUTF8));
        presionLabel->setText(QApplication::translate("dataModificationWidget", "Precipitacion:", 0, QApplication::UnicodeUTF8));
        velVientoLabel->setText(QApplication::translate("dataModificationWidget", "Vel. Viento:", 0, QApplication::UnicodeUTF8));
        dirVientoLabel->setText(QApplication::translate("dataModificationWidget", "Dir. Viento:", 0, QApplication::UnicodeUTF8));
        data1000500Label->setText(QApplication::translate("dataModificationWidget", "1000/500", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("dataModificationWidget", "Borrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dataModificationWidget: public Ui_dataModificationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMODIFICATIONWIDGET_H
