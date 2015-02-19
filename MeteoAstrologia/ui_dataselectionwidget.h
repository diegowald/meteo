/********************************************************************************
** Form generated from reading UI file 'dataselectionwidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASELECTIONWIDGET_H
#define UI_DATASELECTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataSelectionWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *dataSelectionWidget)
    {
        if (dataSelectionWidget->objectName().isEmpty())
            dataSelectionWidget->setObjectName(QString::fromUtf8("dataSelectionWidget"));
        dataSelectionWidget->setWindowModality(Qt::ApplicationModal);
        dataSelectionWidget->resize(511, 231);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataSelectionWidget->sizePolicy().hasHeightForWidth());
        dataSelectionWidget->setSizePolicy(sizePolicy);
        dataSelectionWidget->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_2 = new QVBoxLayout(dataSelectionWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(dataSelectionWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(dataSelectionWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(dataSelectionWidget);

        QMetaObject::connectSlotsByName(dataSelectionWidget);
    } // setupUi

    void retranslateUi(QWidget *dataSelectionWidget)
    {
        dataSelectionWidget->setWindowTitle(QApplication::translate("dataSelectionWidget", "Seleccionar Datos", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("dataSelectionWidget", "Datos: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dataSelectionWidget: public Ui_dataSelectionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASELECTIONWIDGET_H
