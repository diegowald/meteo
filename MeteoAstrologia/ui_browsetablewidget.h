/********************************************************************************
** Form generated from reading UI file 'browsetablewidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSETABLEWIDGET_H
#define UI_BROWSETABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_browseTableWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QComboBox *typeComboBox;
    QLabel *label_2;
    QComboBox *datesComboBox;
    QLabel *label;
    QComboBox *tableComboBox;
    QTableView *tableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *browseTableWidget)
    {
        if (browseTableWidget->objectName().isEmpty())
            browseTableWidget->setObjectName(QString::fromUtf8("browseTableWidget"));
        browseTableWidget->resize(790, 437);
        verticalLayout = new QVBoxLayout(browseTableWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(browseTableWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        typeComboBox = new QComboBox(browseTableWidget);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));

        horizontalLayout->addWidget(typeComboBox);

        label_2 = new QLabel(browseTableWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        datesComboBox = new QComboBox(browseTableWidget);
        datesComboBox->setObjectName(QString::fromUtf8("datesComboBox"));

        horizontalLayout->addWidget(datesComboBox);

        label = new QLabel(browseTableWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        tableComboBox = new QComboBox(browseTableWidget);
        tableComboBox->setObjectName(QString::fromUtf8("tableComboBox"));

        horizontalLayout->addWidget(tableComboBox);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(browseTableWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        buttonBox = new QDialogButtonBox(browseTableWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(browseTableWidget);

        QMetaObject::connectSlotsByName(browseTableWidget);
    } // setupUi

    void retranslateUi(QWidget *browseTableWidget)
    {
        browseTableWidget->setWindowTitle(QApplication::translate("browseTableWidget", "Visualizar Tablas de Datos", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("browseTableWidget", "Tipo:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("browseTableWidget", "Fecha:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("browseTableWidget", "Tabla: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class browseTableWidget: public Ui_browseTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSETABLEWIDGET_H
