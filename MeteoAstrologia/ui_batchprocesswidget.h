/********************************************************************************
** Form generated from reading UI file 'batchprocesswidget.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHPROCESSWIDGET_H
#define UI_BATCHPROCESSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatchProcessWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *initDateEdit;
    QLabel *label_2;
    QDateEdit *endDateEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *doButton;
    QPushButton *closeButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *astroCheckBox;
    QCheckBox *weatherCheckBox;
    QCheckBox *overwriteCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QProgressBar *progressBar;

    void setupUi(QWidget *BatchProcessWidget)
    {
        if (BatchProcessWidget->objectName().isEmpty())
            BatchProcessWidget->setObjectName(QString::fromUtf8("BatchProcessWidget"));
        BatchProcessWidget->resize(640, 480);
        verticalLayout_2 = new QVBoxLayout(BatchProcessWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BatchProcessWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        initDateEdit = new QDateEdit(BatchProcessWidget);
        initDateEdit->setObjectName(QString::fromUtf8("initDateEdit"));
        initDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(initDateEdit);

        label_2 = new QLabel(BatchProcessWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        endDateEdit = new QDateEdit(BatchProcessWidget);
        endDateEdit->setObjectName(QString::fromUtf8("endDateEdit"));
        endDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(endDateEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        doButton = new QPushButton(BatchProcessWidget);
        doButton->setObjectName(QString::fromUtf8("doButton"));

        horizontalLayout->addWidget(doButton);

        closeButton = new QPushButton(BatchProcessWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(BatchProcessWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        astroCheckBox = new QCheckBox(groupBox);
        astroCheckBox->setObjectName(QString::fromUtf8("astroCheckBox"));

        horizontalLayout_2->addWidget(astroCheckBox);

        weatherCheckBox = new QCheckBox(groupBox);
        weatherCheckBox->setObjectName(QString::fromUtf8("weatherCheckBox"));

        horizontalLayout_2->addWidget(weatherCheckBox);

        overwriteCheckBox = new QCheckBox(groupBox);
        overwriteCheckBox->setObjectName(QString::fromUtf8("overwriteCheckBox"));

        horizontalLayout_2->addWidget(overwriteCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BatchProcessWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setMinimum(0);
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addWidget(groupBox_2);


        retranslateUi(BatchProcessWidget);

        QMetaObject::connectSlotsByName(BatchProcessWidget);
    } // setupUi

    void retranslateUi(QWidget *BatchProcessWidget)
    {
        BatchProcessWidget->setWindowTitle(QApplication::translate("BatchProcessWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BatchProcessWidget", "Fecha Inicio:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BatchProcessWidget", "Fecha Fin:", 0, QApplication::UnicodeUTF8));
        doButton->setText(QApplication::translate("BatchProcessWidget", "Calcular", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("BatchProcessWidget", "Cerrar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BatchProcessWidget", "Datos a Calcular", 0, QApplication::UnicodeUTF8));
        astroCheckBox->setText(QApplication::translate("BatchProcessWidget", "Astrologicos", 0, QApplication::UnicodeUTF8));
        weatherCheckBox->setText(QApplication::translate("BatchProcessWidget", "Estados de Tiempo", 0, QApplication::UnicodeUTF8));
        overwriteCheckBox->setText(QApplication::translate("BatchProcessWidget", "Sobreescribir", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BatchProcessWidget", "Estado:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BatchProcessWidget: public Ui_BatchProcessWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHPROCESSWIDGET_H
