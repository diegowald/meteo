/********************************************************************************
** Form generated from reading UI file 'graphicswidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSWIDGET_H
#define UI_GRAPHICSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphicsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *graphicsWidget)
    {
        if (graphicsWidget->objectName().isEmpty())
            graphicsWidget->setObjectName(QString::fromUtf8("graphicsWidget"));
        graphicsWidget->resize(675, 346);
        verticalLayout = new QVBoxLayout(graphicsWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(graphicsWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(graphicsWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(graphicsWidget);

        QMetaObject::connectSlotsByName(graphicsWidget);
    } // setupUi

    void retranslateUi(QWidget *graphicsWidget)
    {
        graphicsWidget->setWindowTitle(QApplication::translate("graphicsWidget", "Form", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("graphicsWidget", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class graphicsWidget: public Ui_graphicsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSWIDGET_H
