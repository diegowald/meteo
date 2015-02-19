/********************************************************************************
** Form generated from reading UI file 'browsewidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEWIDGET_H
#define UI_BROWSEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_browseWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *horaComboBox;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *delButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *closeButton;

    void setupUi(QWidget *browseWidget)
    {
        if (browseWidget->objectName().isEmpty())
            browseWidget->setObjectName(QString::fromUtf8("browseWidget"));
        browseWidget->resize(686, 345);
        verticalLayout = new QVBoxLayout(browseWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(browseWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateEdit = new QDateEdit(browseWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(browseWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horaComboBox = new QComboBox(browseWidget);
        horaComboBox->setObjectName(QString::fromUtf8("horaComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horaComboBox->sizePolicy().hasHeightForWidth());
        horaComboBox->setSizePolicy(sizePolicy);
        horaComboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(horaComboBox);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(browseWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        delButton = new QPushButton(browseWidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        horizontalLayout_2->addWidget(delButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        closeButton = new QPushButton(browseWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(browseWidget);
        QObject::connect(closeButton, SIGNAL(clicked()), browseWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(browseWidget);
    } // setupUi

    void retranslateUi(QWidget *browseWidget)
    {
        browseWidget->setWindowTitle(QApplication::translate("browseWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("browseWidget", "Fecha:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("browseWidget", "Hora:", 0, QApplication::UnicodeUTF8));
        delButton->setText(QApplication::translate("browseWidget", "Borrar Datos en Lista", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("browseWidget", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class browseWidget: public Ui_browseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEWIDGET_H
