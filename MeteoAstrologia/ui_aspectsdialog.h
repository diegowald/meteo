/********************************************************************************
** Form generated from reading UI file 'aspectsdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASPECTSDIALOG_H
#define UI_ASPECTSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aspectsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *aspectoLabel;
    QComboBox *aspectoComboBox;
    QLabel *planeta1Label;
    QComboBox *planeta1ComboBox;
    QLabel *planeta2Label;
    QComboBox *planeta2ComboBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *gradeGroupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *gradosLabel;
    QSpinBox *gradosSpinBox;
    QLabel *toleranciaLabel;
    QSpinBox *toleranciaGradosSpinBox;
    QGroupBox *minutesGroupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *valorLabel;
    QSpinBox *minutosSpinBox;
    QLabel *toleranciaLabel_2;
    QSpinBox *toleranciaMinutosSpinBox;
    QGroupBox *secondsGroupBox;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *valorLabel_2;
    QSpinBox *segundosSpinBox;
    QLabel *toleranciaLabel_3;
    QSpinBox *toleranciaSegundosSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *aspectsDialog)
    {
        if (aspectsDialog->objectName().isEmpty())
            aspectsDialog->setObjectName(QString::fromUtf8("aspectsDialog"));
        aspectsDialog->resize(525, 311);
        verticalLayout = new QVBoxLayout(aspectsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        aspectoLabel = new QLabel(aspectsDialog);
        aspectoLabel->setObjectName(QString::fromUtf8("aspectoLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, aspectoLabel);

        aspectoComboBox = new QComboBox(aspectsDialog);
        aspectoComboBox->setObjectName(QString::fromUtf8("aspectoComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, aspectoComboBox);

        planeta1Label = new QLabel(aspectsDialog);
        planeta1Label->setObjectName(QString::fromUtf8("planeta1Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, planeta1Label);

        planeta1ComboBox = new QComboBox(aspectsDialog);
        planeta1ComboBox->setObjectName(QString::fromUtf8("planeta1ComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, planeta1ComboBox);

        planeta2Label = new QLabel(aspectsDialog);
        planeta2Label->setObjectName(QString::fromUtf8("planeta2Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, planeta2Label);

        planeta2ComboBox = new QComboBox(aspectsDialog);
        planeta2ComboBox->setObjectName(QString::fromUtf8("planeta2ComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, planeta2ComboBox);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, -1);
        gradeGroupBox = new QGroupBox(aspectsDialog);
        gradeGroupBox->setObjectName(QString::fromUtf8("gradeGroupBox"));
        gradeGroupBox->setCheckable(true);
        verticalLayout_2 = new QVBoxLayout(gradeGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        gradosLabel = new QLabel(gradeGroupBox);
        gradosLabel->setObjectName(QString::fromUtf8("gradosLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, gradosLabel);

        gradosSpinBox = new QSpinBox(gradeGroupBox);
        gradosSpinBox->setObjectName(QString::fromUtf8("gradosSpinBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, gradosSpinBox);

        toleranciaLabel = new QLabel(gradeGroupBox);
        toleranciaLabel->setObjectName(QString::fromUtf8("toleranciaLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, toleranciaLabel);

        toleranciaGradosSpinBox = new QSpinBox(gradeGroupBox);
        toleranciaGradosSpinBox->setObjectName(QString::fromUtf8("toleranciaGradosSpinBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, toleranciaGradosSpinBox);


        verticalLayout_2->addLayout(formLayout_2);


        horizontalLayout->addWidget(gradeGroupBox);

        minutesGroupBox = new QGroupBox(aspectsDialog);
        minutesGroupBox->setObjectName(QString::fromUtf8("minutesGroupBox"));
        minutesGroupBox->setCheckable(true);
        verticalLayout_3 = new QVBoxLayout(minutesGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        valorLabel = new QLabel(minutesGroupBox);
        valorLabel->setObjectName(QString::fromUtf8("valorLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, valorLabel);

        minutosSpinBox = new QSpinBox(minutesGroupBox);
        minutosSpinBox->setObjectName(QString::fromUtf8("minutosSpinBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, minutosSpinBox);

        toleranciaLabel_2 = new QLabel(minutesGroupBox);
        toleranciaLabel_2->setObjectName(QString::fromUtf8("toleranciaLabel_2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_2);

        toleranciaMinutosSpinBox = new QSpinBox(minutesGroupBox);
        toleranciaMinutosSpinBox->setObjectName(QString::fromUtf8("toleranciaMinutosSpinBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, toleranciaMinutosSpinBox);


        verticalLayout_3->addLayout(formLayout_3);


        horizontalLayout->addWidget(minutesGroupBox);

        secondsGroupBox = new QGroupBox(aspectsDialog);
        secondsGroupBox->setObjectName(QString::fromUtf8("secondsGroupBox"));
        secondsGroupBox->setCheckable(true);
        verticalLayout_4 = new QVBoxLayout(secondsGroupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        valorLabel_2 = new QLabel(secondsGroupBox);
        valorLabel_2->setObjectName(QString::fromUtf8("valorLabel_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, valorLabel_2);

        segundosSpinBox = new QSpinBox(secondsGroupBox);
        segundosSpinBox->setObjectName(QString::fromUtf8("segundosSpinBox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, segundosSpinBox);

        toleranciaLabel_3 = new QLabel(secondsGroupBox);
        toleranciaLabel_3->setObjectName(QString::fromUtf8("toleranciaLabel_3"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_3);

        toleranciaSegundosSpinBox = new QSpinBox(secondsGroupBox);
        toleranciaSegundosSpinBox->setObjectName(QString::fromUtf8("toleranciaSegundosSpinBox"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, toleranciaSegundosSpinBox);


        verticalLayout_4->addLayout(formLayout_4);


        horizontalLayout->addWidget(secondsGroupBox);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(aspectsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(aspectsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), aspectsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), aspectsDialog, SLOT(reject()));
        QObject::connect(gradeGroupBox, SIGNAL(toggled(bool)), gradosSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(gradeGroupBox, SIGNAL(toggled(bool)), toleranciaGradosSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(minutesGroupBox, SIGNAL(toggled(bool)), minutosSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(minutesGroupBox, SIGNAL(toggled(bool)), toleranciaMinutosSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(secondsGroupBox, SIGNAL(toggled(bool)), segundosSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(secondsGroupBox, SIGNAL(toggled(bool)), toleranciaSegundosSpinBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(aspectsDialog);
    } // setupUi

    void retranslateUi(QDialog *aspectsDialog)
    {
        aspectsDialog->setWindowTitle(QApplication::translate("aspectsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        aspectoLabel->setText(QApplication::translate("aspectsDialog", "Aspecto:", 0, QApplication::UnicodeUTF8));
        planeta1Label->setText(QApplication::translate("aspectsDialog", "Planeta 1:", 0, QApplication::UnicodeUTF8));
        planeta2Label->setText(QApplication::translate("aspectsDialog", "Planeta 2:", 0, QApplication::UnicodeUTF8));
        gradeGroupBox->setTitle(QApplication::translate("aspectsDialog", "Grados:", 0, QApplication::UnicodeUTF8));
        gradosLabel->setText(QApplication::translate("aspectsDialog", "Valor:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel->setText(QApplication::translate("aspectsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        minutesGroupBox->setTitle(QApplication::translate("aspectsDialog", "Minutos:", 0, QApplication::UnicodeUTF8));
        valorLabel->setText(QApplication::translate("aspectsDialog", "Valor:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_2->setText(QApplication::translate("aspectsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        secondsGroupBox->setTitle(QApplication::translate("aspectsDialog", "Segundos:", 0, QApplication::UnicodeUTF8));
        valorLabel_2->setText(QApplication::translate("aspectsDialog", "Valor:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_3->setText(QApplication::translate("aspectsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class aspectsDialog: public Ui_aspectsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASPECTSDIALOG_H
