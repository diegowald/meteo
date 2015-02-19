/********************************************************************************
** Form generated from reading UI file 'grabdatawidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRABDATAWIDGET_H
#define UI_GRABDATAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grabDataWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *SizigiagroupBox;
    QHBoxLayout *sizigiaLayout;
    QLabel *label_2;
    QComboBox *sizigiaComboBox;
    QGroupBox *lunaGroupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *fullMoonRadioButton;
    QRadioButton *newMoonRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *fechaGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
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
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *observacionesTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *astroInfoButton;
    QPushButton *satelmecPushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *saveButton;
    QPushButton *closeButton;

    void setupUi(QWidget *grabDataWidget)
    {
        if (grabDataWidget->objectName().isEmpty())
            grabDataWidget->setObjectName(QString::fromUtf8("grabDataWidget"));
        grabDataWidget->resize(620, 429);
        verticalLayout_2 = new QVBoxLayout(grabDataWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        SizigiagroupBox = new QGroupBox(grabDataWidget);
        SizigiagroupBox->setObjectName(QString::fromUtf8("SizigiagroupBox"));
        SizigiagroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        sizigiaLayout = new QHBoxLayout(SizigiagroupBox);
        sizigiaLayout->setObjectName(QString::fromUtf8("sizigiaLayout"));
        sizigiaLayout->setContentsMargins(-1, 1, -1, -1);
        label_2 = new QLabel(SizigiagroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        sizigiaLayout->addWidget(label_2);

        sizigiaComboBox = new QComboBox(SizigiagroupBox);
        sizigiaComboBox->setObjectName(QString::fromUtf8("sizigiaComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sizigiaComboBox->sizePolicy().hasHeightForWidth());
        sizigiaComboBox->setSizePolicy(sizePolicy);

        sizigiaLayout->addWidget(sizigiaComboBox);

        lunaGroupBox = new QGroupBox(SizigiagroupBox);
        lunaGroupBox->setObjectName(QString::fromUtf8("lunaGroupBox"));
        lunaGroupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(lunaGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        fullMoonRadioButton = new QRadioButton(lunaGroupBox);
        fullMoonRadioButton->setObjectName(QString::fromUtf8("fullMoonRadioButton"));

        verticalLayout_3->addWidget(fullMoonRadioButton);

        newMoonRadioButton = new QRadioButton(lunaGroupBox);
        newMoonRadioButton->setObjectName(QString::fromUtf8("newMoonRadioButton"));

        verticalLayout_3->addWidget(newMoonRadioButton);


        sizigiaLayout->addWidget(lunaGroupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sizigiaLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(SizigiagroupBox);

        fechaGroupBox = new QGroupBox(grabDataWidget);
        fechaGroupBox->setObjectName(QString::fromUtf8("fechaGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(fechaGroupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(fechaGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(fechaGroupBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateTimeEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(fechaGroupBox);

        groupBox = new QGroupBox(grabDataWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tempMaxLabel = new QLabel(groupBox);
        tempMaxLabel->setObjectName(QString::fromUtf8("tempMaxLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, tempMaxLabel);

        tempMaxDoubleSpinBox = new QDoubleSpinBox(groupBox);
        tempMaxDoubleSpinBox->setObjectName(QString::fromUtf8("tempMaxDoubleSpinBox"));
        tempMaxDoubleSpinBox->setMinimum(-9.999e+07);

        formLayout->setWidget(0, QFormLayout::FieldRole, tempMaxDoubleSpinBox);

        tempMinLabel = new QLabel(groupBox);
        tempMinLabel->setObjectName(QString::fromUtf8("tempMinLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, tempMinLabel);

        tempMinDoubleSpinBox = new QDoubleSpinBox(groupBox);
        tempMinDoubleSpinBox->setObjectName(QString::fromUtf8("tempMinDoubleSpinBox"));
        tempMinDoubleSpinBox->setMinimum(-990000);

        formLayout->setWidget(1, QFormLayout::FieldRole, tempMinDoubleSpinBox);

        presionLabel = new QLabel(groupBox);
        presionLabel->setObjectName(QString::fromUtf8("presionLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, presionLabel);

        precipitacionSpinBox = new QDoubleSpinBox(groupBox);
        precipitacionSpinBox->setObjectName(QString::fromUtf8("precipitacionSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, precipitacionSpinBox);


        horizontalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        velVientoLabel = new QLabel(groupBox);
        velVientoLabel->setObjectName(QString::fromUtf8("velVientoLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, velVientoLabel);

        dirVientoLabel = new QLabel(groupBox);
        dirVientoLabel->setObjectName(QString::fromUtf8("dirVientoLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, dirVientoLabel);

        dirVientoSpinBox = new QSpinBox(groupBox);
        dirVientoSpinBox->setObjectName(QString::fromUtf8("dirVientoSpinBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, dirVientoSpinBox);

        data1000500Label = new QLabel(groupBox);
        data1000500Label->setObjectName(QString::fromUtf8("data1000500Label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, data1000500Label);

        velVientoDoubleSpinBox = new QDoubleSpinBox(groupBox);
        velVientoDoubleSpinBox->setObjectName(QString::fromUtf8("velVientoDoubleSpinBox"));
        velVientoDoubleSpinBox->setMaximum(999.99);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, velVientoDoubleSpinBox);

        data1000500SpinBox = new QSpinBox(groupBox);
        data1000500SpinBox->setObjectName(QString::fromUtf8("data1000500SpinBox"));
        data1000500SpinBox->setMaximum(9999);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, data1000500SpinBox);


        horizontalLayout->addLayout(formLayout_2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(grabDataWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        observacionesTextEdit = new QPlainTextEdit(groupBox_2);
        observacionesTextEdit->setObjectName(QString::fromUtf8("observacionesTextEdit"));

        verticalLayout->addWidget(observacionesTextEdit);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        astroInfoButton = new QPushButton(grabDataWidget);
        astroInfoButton->setObjectName(QString::fromUtf8("astroInfoButton"));

        horizontalLayout_3->addWidget(astroInfoButton);

        satelmecPushButton = new QPushButton(grabDataWidget);
        satelmecPushButton->setObjectName(QString::fromUtf8("satelmecPushButton"));

        horizontalLayout_3->addWidget(satelmecPushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        saveButton = new QPushButton(grabDataWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_3->addWidget(saveButton);

        closeButton = new QPushButton(grabDataWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_3->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(grabDataWidget);
        QObject::connect(closeButton, SIGNAL(clicked()), grabDataWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(grabDataWidget);
    } // setupUi

    void retranslateUi(QWidget *grabDataWidget)
    {
        grabDataWidget->setWindowTitle(QApplication::translate("grabDataWidget", "Carga de Datos", 0, QApplication::UnicodeUTF8));
        SizigiagroupBox->setTitle(QApplication::translate("grabDataWidget", "Sizigia: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("grabDataWidget", "Sizigia: ", 0, QApplication::UnicodeUTF8));
        sizigiaComboBox->clear();
        sizigiaComboBox->insertItems(0, QStringList()
         << QApplication::translate("grabDataWidget", "Enero", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Febrero", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Marzo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Abril", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Mayo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Junio", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Julio", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Agosto", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Septiembre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Octubre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Noviembre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Diciembre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Solsticio de Verano", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Solsticio de Invierno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Equinoccio de Primavera", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("grabDataWidget", "Equinoccio de Oto\303\261o", 0, QApplication::UnicodeUTF8)
        );
        lunaGroupBox->setTitle(QApplication::translate("grabDataWidget", "Luna", 0, QApplication::UnicodeUTF8));
        fullMoonRadioButton->setText(QApplication::translate("grabDataWidget", "Llena", 0, QApplication::UnicodeUTF8));
        newMoonRadioButton->setText(QApplication::translate("grabDataWidget", "Nueva", 0, QApplication::UnicodeUTF8));
        fechaGroupBox->setTitle(QApplication::translate("grabDataWidget", "Fecha:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("grabDataWidget", "Fecha / Hora:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("grabDataWidget", "Datos:", 0, QApplication::UnicodeUTF8));
        tempMaxLabel->setText(QApplication::translate("grabDataWidget", "Temp Max:", 0, QApplication::UnicodeUTF8));
        tempMinLabel->setText(QApplication::translate("grabDataWidget", "Temp Min:", 0, QApplication::UnicodeUTF8));
        presionLabel->setText(QApplication::translate("grabDataWidget", "Precipitacion:", 0, QApplication::UnicodeUTF8));
        velVientoLabel->setText(QApplication::translate("grabDataWidget", "Vel. Viento:", 0, QApplication::UnicodeUTF8));
        dirVientoLabel->setText(QApplication::translate("grabDataWidget", "Dir. Viento:", 0, QApplication::UnicodeUTF8));
        data1000500Label->setText(QApplication::translate("grabDataWidget", "1000/500", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("grabDataWidget", "Observaciones:", 0, QApplication::UnicodeUTF8));
        astroInfoButton->setText(QApplication::translate("grabDataWidget", "Generar Datos Astrologicos", 0, QApplication::UnicodeUTF8));
        satelmecPushButton->setText(QApplication::translate("grabDataWidget", "Cargar Data Archivo", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("grabDataWidget", "Guardar", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("grabDataWidget", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class grabDataWidget: public Ui_grabDataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRABDATAWIDGET_H
