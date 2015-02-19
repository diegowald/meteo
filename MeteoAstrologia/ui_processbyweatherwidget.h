/********************************************************************************
** Form generated from reading UI file 'processbyweatherwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSBYWEATHERWIDGET_H
#define UI_PROCESSBYWEATHERWIDGET_H

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
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processByWeatherWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFormLayout *formLayout_6;
    QLabel *desdeLaTablaLabel;
    QComboBox *desdeLaTablaComboBox;
    QTableWidget *weatherTable;
    QHBoxLayout *horizontalLayout;
    QToolButton *addButton;
    QToolButton *delButton;
    QPushButton *buscarButton;
    QLabel *fechasLabel;
    QListWidget *datesList;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *porcentajeLabel;
    QSpinBox *aspectariumPorcentajeSpinBox;
    QTableWidget *aspectariumTableWidget;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *porcentajeLabel_2;
    QSpinBox *signPorcentajeSpinBox;
    QTableWidget *signsTableWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_3;
    QLabel *porcentajeLabel_3;
    QSpinBox *positionsPorcentajeSpinBox;
    QTableWidget *positionsTableWidget;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_4;
    QLabel *procentajeLabel;
    QSpinBox *quadrantsProcentajeSpinBox;
    QTableWidget *quadrantesTableWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_5;
    QLabel *porcentajeLabel_4;
    QSpinBox *housesPorcentajeSpinBox;
    QTableWidget *housesTableWidget;

    void setupUi(QWidget *processByWeatherWidget)
    {
        if (processByWeatherWidget->objectName().isEmpty())
            processByWeatherWidget->setObjectName(QString::fromUtf8("processByWeatherWidget"));
        processByWeatherWidget->resize(799, 423);
        horizontalLayout_2 = new QHBoxLayout(processByWeatherWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(processByWeatherWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        desdeLaTablaLabel = new QLabel(processByWeatherWidget);
        desdeLaTablaLabel->setObjectName(QString::fromUtf8("desdeLaTablaLabel"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, desdeLaTablaLabel);

        desdeLaTablaComboBox = new QComboBox(processByWeatherWidget);
        desdeLaTablaComboBox->setObjectName(QString::fromUtf8("desdeLaTablaComboBox"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, desdeLaTablaComboBox);


        verticalLayout->addLayout(formLayout_6);

        weatherTable = new QTableWidget(processByWeatherWidget);
        weatherTable->setObjectName(QString::fromUtf8("weatherTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(weatherTable->sizePolicy().hasHeightForWidth());
        weatherTable->setSizePolicy(sizePolicy);
        weatherTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        weatherTable->setSelectionMode(QAbstractItemView::SingleSelection);
        weatherTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(weatherTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QToolButton(processByWeatherWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/edit-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);

        horizontalLayout->addWidget(addButton);

        delButton = new QToolButton(processByWeatherWidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/edit-remove-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        delButton->setIcon(icon1);

        horizontalLayout->addWidget(delButton);

        buscarButton = new QPushButton(processByWeatherWidget);
        buscarButton->setObjectName(QString::fromUtf8("buscarButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        buscarButton->setIcon(icon2);

        horizontalLayout->addWidget(buscarButton);


        verticalLayout->addLayout(horizontalLayout);

        fechasLabel = new QLabel(processByWeatherWidget);
        fechasLabel->setObjectName(QString::fromUtf8("fechasLabel"));

        verticalLayout->addWidget(fechasLabel);

        datesList = new QListWidget(processByWeatherWidget);
        datesList->setObjectName(QString::fromUtf8("datesList"));

        verticalLayout->addWidget(datesList);


        horizontalLayout_2->addLayout(verticalLayout);

        groupBox_5 = new QGroupBox(processByWeatherWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        porcentajeLabel = new QLabel(groupBox_5);
        porcentajeLabel->setObjectName(QString::fromUtf8("porcentajeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, porcentajeLabel);

        aspectariumPorcentajeSpinBox = new QSpinBox(groupBox_5);
        aspectariumPorcentajeSpinBox->setObjectName(QString::fromUtf8("aspectariumPorcentajeSpinBox"));
        aspectariumPorcentajeSpinBox->setMaximum(100);
        aspectariumPorcentajeSpinBox->setValue(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, aspectariumPorcentajeSpinBox);


        verticalLayout_2->addLayout(formLayout);

        aspectariumTableWidget = new QTableWidget(groupBox_5);
        aspectariumTableWidget->setObjectName(QString::fromUtf8("aspectariumTableWidget"));
        aspectariumTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        aspectariumTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        aspectariumTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(aspectariumTableWidget);


        horizontalLayout_2->addWidget(groupBox_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, 10, -1);
        groupBox_3 = new QGroupBox(processByWeatherWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        porcentajeLabel_2 = new QLabel(groupBox_3);
        porcentajeLabel_2->setObjectName(QString::fromUtf8("porcentajeLabel_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, porcentajeLabel_2);

        signPorcentajeSpinBox = new QSpinBox(groupBox_3);
        signPorcentajeSpinBox->setObjectName(QString::fromUtf8("signPorcentajeSpinBox"));
        signPorcentajeSpinBox->setMaximum(100);
        signPorcentajeSpinBox->setValue(20);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, signPorcentajeSpinBox);


        verticalLayout_3->addLayout(formLayout_2);

        signsTableWidget = new QTableWidget(groupBox_3);
        signsTableWidget->setObjectName(QString::fromUtf8("signsTableWidget"));
        signsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        signsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        signsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(signsTableWidget);


        verticalLayout_7->addWidget(groupBox_3);

        groupBox = new QGroupBox(processByWeatherWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        porcentajeLabel_3 = new QLabel(groupBox);
        porcentajeLabel_3->setObjectName(QString::fromUtf8("porcentajeLabel_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, porcentajeLabel_3);

        positionsPorcentajeSpinBox = new QSpinBox(groupBox);
        positionsPorcentajeSpinBox->setObjectName(QString::fromUtf8("positionsPorcentajeSpinBox"));
        positionsPorcentajeSpinBox->setMaximum(100);
        positionsPorcentajeSpinBox->setValue(20);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, positionsPorcentajeSpinBox);


        verticalLayout_4->addLayout(formLayout_3);

        positionsTableWidget = new QTableWidget(groupBox);
        positionsTableWidget->setObjectName(QString::fromUtf8("positionsTableWidget"));
        positionsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        positionsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        positionsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_4->addWidget(positionsTableWidget);


        verticalLayout_7->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, -1, 10, -1);
        groupBox_4 = new QGroupBox(processByWeatherWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        procentajeLabel = new QLabel(groupBox_4);
        procentajeLabel->setObjectName(QString::fromUtf8("procentajeLabel"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, procentajeLabel);

        quadrantsProcentajeSpinBox = new QSpinBox(groupBox_4);
        quadrantsProcentajeSpinBox->setObjectName(QString::fromUtf8("quadrantsProcentajeSpinBox"));
        quadrantsProcentajeSpinBox->setMaximum(100);
        quadrantsProcentajeSpinBox->setValue(20);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, quadrantsProcentajeSpinBox);


        verticalLayout_5->addLayout(formLayout_4);

        quadrantesTableWidget = new QTableWidget(groupBox_4);
        quadrantesTableWidget->setObjectName(QString::fromUtf8("quadrantesTableWidget"));
        quadrantesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        quadrantesTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        quadrantesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_5->addWidget(quadrantesTableWidget);


        verticalLayout_8->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(processByWeatherWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        porcentajeLabel_4 = new QLabel(groupBox_2);
        porcentajeLabel_4->setObjectName(QString::fromUtf8("porcentajeLabel_4"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, porcentajeLabel_4);

        housesPorcentajeSpinBox = new QSpinBox(groupBox_2);
        housesPorcentajeSpinBox->setObjectName(QString::fromUtf8("housesPorcentajeSpinBox"));
        housesPorcentajeSpinBox->setMaximum(100);
        housesPorcentajeSpinBox->setValue(20);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, housesPorcentajeSpinBox);


        verticalLayout_6->addLayout(formLayout_5);

        housesTableWidget = new QTableWidget(groupBox_2);
        housesTableWidget->setObjectName(QString::fromUtf8("housesTableWidget"));
        housesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        housesTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        housesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_6->addWidget(housesTableWidget);


        verticalLayout_8->addWidget(groupBox_2);


        horizontalLayout_2->addLayout(verticalLayout_8);


        retranslateUi(processByWeatherWidget);

        QMetaObject::connectSlotsByName(processByWeatherWidget);
    } // setupUi

    void retranslateUi(QWidget *processByWeatherWidget)
    {
        processByWeatherWidget->setWindowTitle(QApplication::translate("processByWeatherWidget", "Por Estados de Tiempo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("processByWeatherWidget", "Estados del Tiempo:", 0, QApplication::UnicodeUTF8));
        desdeLaTablaLabel->setText(QApplication::translate("processByWeatherWidget", "Desde la Tabla:", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("processByWeatherWidget", "...", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("processByWeatherWidget", "...", 0, QApplication::UnicodeUTF8));
        buscarButton->setText(QApplication::translate("processByWeatherWidget", "Filtrar", 0, QApplication::UnicodeUTF8));
        fechasLabel->setText(QApplication::translate("processByWeatherWidget", "Fechas:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("processByWeatherWidget", "Aspectos", 0, QApplication::UnicodeUTF8));
        porcentajeLabel->setText(QApplication::translate("processByWeatherWidget", "Porcentaje:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("processByWeatherWidget", "Signos", 0, QApplication::UnicodeUTF8));
        porcentajeLabel_2->setText(QApplication::translate("processByWeatherWidget", "Porcentaje", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("processByWeatherWidget", "Posicion", 0, QApplication::UnicodeUTF8));
        porcentajeLabel_3->setText(QApplication::translate("processByWeatherWidget", "Porcentaje", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("processByWeatherWidget", "Cuadrante", 0, QApplication::UnicodeUTF8));
        procentajeLabel->setText(QApplication::translate("processByWeatherWidget", "Procentaje", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("processByWeatherWidget", "Casas", 0, QApplication::UnicodeUTF8));
        porcentajeLabel_4->setText(QApplication::translate("processByWeatherWidget", "Porcentaje", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class processByWeatherWidget: public Ui_processByWeatherWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSBYWEATHERWIDGET_H
