/********************************************************************************
** Form generated from reading UI file 'positionsdialog.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONSDIALOG_H
#define UI_POSITIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_positionsDialog
{
public:
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *planetComboBox;
    QLabel *label;
    QComboBox *signComboBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *gradesLonGroupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *valorLabel;
    QSpinBox *gradesLonValueSpinBox;
    QLabel *toleranciaLabel;
    QSpinBox *toleranciaGradesLonValueSpinBox;
    QGroupBox *minutesLonGroupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *valorLabel_2;
    QSpinBox *minutesLonValueSpinBox;
    QLabel *toleranciaLabel_2;
    QSpinBox *toleranciaMinutesLonValueSpinBox;
    QGroupBox *secondsLonGroupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *valorLabel_3;
    QSpinBox *secondsLonValueSpinBox;
    QLabel *toleranceLabel;
    QSpinBox *toleranceSecondsLonValueSpinBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *gradesLatGroupBox;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *valorLabel_4;
    QSpinBox *gradesLatValueSpinBox;
    QLabel *toleranciaLabel_3;
    QSpinBox *toleranciaGradesLatValueSpinBox;
    QGroupBox *minutesLatGroupBox;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_5;
    QLabel *valorLabel_5;
    QSpinBox *minutesLatValueSpinBox;
    QLabel *toleranciaLabel_4;
    QSpinBox *toleranciaMinutesLatValueSpinBox;
    QGroupBox *secondsLatGroupBox;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_6;
    QLabel *valorLabel_6;
    QSpinBox *secondsLatValueSpinBox;
    QLabel *toleranceLabel_2;
    QSpinBox *toleranceSecondsLatValueSpinBox;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *gradesVelGroupBox;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout_7;
    QLabel *valorLabel_7;
    QSpinBox *gradesVelValueSpinBox;
    QLabel *toleranciaLabel_5;
    QSpinBox *toleranciaGradesVelValueSpinBox;
    QGroupBox *minutesVelGroupBox;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout_8;
    QLabel *valorLabel_8;
    QSpinBox *minutesVelValueSpinBox;
    QLabel *toleranciaLabel_6;
    QSpinBox *toleranciaMinutesVelValueSpinBox;
    QGroupBox *secondsVelGroupBox;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout_9;
    QLabel *valorLabel_9;
    QSpinBox *secondsVelValueSpinBox;
    QLabel *toleranceLabel_3;
    QSpinBox *toleranceSecondsVelValueSpinBox;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *distanceGroupBox;
    QVBoxLayout *verticalLayout_10;
    QFormLayout *formLayout_11;
    QLabel *distanciaLabel;
    QDoubleSpinBox *distanciaDoubleSpinBox;
    QLabel *toleranciaLabel_7;
    QDoubleSpinBox *toleranciaDistanceDoubleSpinBox;
    QGroupBox *housesGroupBox;
    QVBoxLayout *verticalLayout_11;
    QFormLayout *formLayout_12;
    QLabel *casaLabel;
    QComboBox *casaComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *positionsDialog)
    {
        if (positionsDialog->objectName().isEmpty())
            positionsDialog->setObjectName(QString::fromUtf8("positionsDialog"));
        positionsDialog->resize(647, 498);
        verticalLayout_12 = new QVBoxLayout(positionsDialog);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(positionsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        planetComboBox = new QComboBox(positionsDialog);
        planetComboBox->setObjectName(QString::fromUtf8("planetComboBox"));

        horizontalLayout->addWidget(planetComboBox);

        label = new QLabel(positionsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        signComboBox = new QComboBox(positionsDialog);
        signComboBox->setObjectName(QString::fromUtf8("signComboBox"));

        horizontalLayout->addWidget(signComboBox);


        verticalLayout_12->addLayout(horizontalLayout);

        groupBox = new QGroupBox(positionsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gradesLonGroupBox = new QGroupBox(groupBox);
        gradesLonGroupBox->setObjectName(QString::fromUtf8("gradesLonGroupBox"));
        gradesLonGroupBox->setCheckable(true);
        verticalLayout = new QVBoxLayout(gradesLonGroupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        valorLabel = new QLabel(gradesLonGroupBox);
        valorLabel->setObjectName(QString::fromUtf8("valorLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, valorLabel);

        gradesLonValueSpinBox = new QSpinBox(gradesLonGroupBox);
        gradesLonValueSpinBox->setObjectName(QString::fromUtf8("gradesLonValueSpinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, gradesLonValueSpinBox);

        toleranciaLabel = new QLabel(gradesLonGroupBox);
        toleranciaLabel->setObjectName(QString::fromUtf8("toleranciaLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, toleranciaLabel);

        toleranciaGradesLonValueSpinBox = new QSpinBox(gradesLonGroupBox);
        toleranciaGradesLonValueSpinBox->setObjectName(QString::fromUtf8("toleranciaGradesLonValueSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, toleranciaGradesLonValueSpinBox);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_2->addWidget(gradesLonGroupBox);

        minutesLonGroupBox = new QGroupBox(groupBox);
        minutesLonGroupBox->setObjectName(QString::fromUtf8("minutesLonGroupBox"));
        minutesLonGroupBox->setCheckable(true);
        verticalLayout_2 = new QVBoxLayout(minutesLonGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        valorLabel_2 = new QLabel(minutesLonGroupBox);
        valorLabel_2->setObjectName(QString::fromUtf8("valorLabel_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, valorLabel_2);

        minutesLonValueSpinBox = new QSpinBox(minutesLonGroupBox);
        minutesLonValueSpinBox->setObjectName(QString::fromUtf8("minutesLonValueSpinBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, minutesLonValueSpinBox);

        toleranciaLabel_2 = new QLabel(minutesLonGroupBox);
        toleranciaLabel_2->setObjectName(QString::fromUtf8("toleranciaLabel_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_2);

        toleranciaMinutesLonValueSpinBox = new QSpinBox(minutesLonGroupBox);
        toleranciaMinutesLonValueSpinBox->setObjectName(QString::fromUtf8("toleranciaMinutesLonValueSpinBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, toleranciaMinutesLonValueSpinBox);


        verticalLayout_2->addLayout(formLayout_2);


        horizontalLayout_2->addWidget(minutesLonGroupBox);

        secondsLonGroupBox = new QGroupBox(groupBox);
        secondsLonGroupBox->setObjectName(QString::fromUtf8("secondsLonGroupBox"));
        secondsLonGroupBox->setCheckable(true);
        verticalLayout_3 = new QVBoxLayout(secondsLonGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        valorLabel_3 = new QLabel(secondsLonGroupBox);
        valorLabel_3->setObjectName(QString::fromUtf8("valorLabel_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, valorLabel_3);

        secondsLonValueSpinBox = new QSpinBox(secondsLonGroupBox);
        secondsLonValueSpinBox->setObjectName(QString::fromUtf8("secondsLonValueSpinBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, secondsLonValueSpinBox);

        toleranceLabel = new QLabel(secondsLonGroupBox);
        toleranceLabel->setObjectName(QString::fromUtf8("toleranceLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, toleranceLabel);

        toleranceSecondsLonValueSpinBox = new QSpinBox(secondsLonGroupBox);
        toleranceSecondsLonValueSpinBox->setObjectName(QString::fromUtf8("toleranceSecondsLonValueSpinBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, toleranceSecondsLonValueSpinBox);


        verticalLayout_3->addLayout(formLayout_3);


        horizontalLayout_2->addWidget(secondsLonGroupBox);


        verticalLayout_12->addWidget(groupBox);

        groupBox_2 = new QGroupBox(positionsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gradesLatGroupBox = new QGroupBox(groupBox_2);
        gradesLatGroupBox->setObjectName(QString::fromUtf8("gradesLatGroupBox"));
        gradesLatGroupBox->setCheckable(true);
        verticalLayout_4 = new QVBoxLayout(gradesLatGroupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        valorLabel_4 = new QLabel(gradesLatGroupBox);
        valorLabel_4->setObjectName(QString::fromUtf8("valorLabel_4"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, valorLabel_4);

        gradesLatValueSpinBox = new QSpinBox(gradesLatGroupBox);
        gradesLatValueSpinBox->setObjectName(QString::fromUtf8("gradesLatValueSpinBox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, gradesLatValueSpinBox);

        toleranciaLabel_3 = new QLabel(gradesLatGroupBox);
        toleranciaLabel_3->setObjectName(QString::fromUtf8("toleranciaLabel_3"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_3);

        toleranciaGradesLatValueSpinBox = new QSpinBox(gradesLatGroupBox);
        toleranciaGradesLatValueSpinBox->setObjectName(QString::fromUtf8("toleranciaGradesLatValueSpinBox"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, toleranciaGradesLatValueSpinBox);


        verticalLayout_4->addLayout(formLayout_4);


        horizontalLayout_3->addWidget(gradesLatGroupBox);

        minutesLatGroupBox = new QGroupBox(groupBox_2);
        minutesLatGroupBox->setObjectName(QString::fromUtf8("minutesLatGroupBox"));
        minutesLatGroupBox->setCheckable(true);
        verticalLayout_5 = new QVBoxLayout(minutesLatGroupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        valorLabel_5 = new QLabel(minutesLatGroupBox);
        valorLabel_5->setObjectName(QString::fromUtf8("valorLabel_5"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, valorLabel_5);

        minutesLatValueSpinBox = new QSpinBox(minutesLatGroupBox);
        minutesLatValueSpinBox->setObjectName(QString::fromUtf8("minutesLatValueSpinBox"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, minutesLatValueSpinBox);

        toleranciaLabel_4 = new QLabel(minutesLatGroupBox);
        toleranciaLabel_4->setObjectName(QString::fromUtf8("toleranciaLabel_4"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_4);

        toleranciaMinutesLatValueSpinBox = new QSpinBox(minutesLatGroupBox);
        toleranciaMinutesLatValueSpinBox->setObjectName(QString::fromUtf8("toleranciaMinutesLatValueSpinBox"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, toleranciaMinutesLatValueSpinBox);


        verticalLayout_5->addLayout(formLayout_5);


        horizontalLayout_3->addWidget(minutesLatGroupBox);

        secondsLatGroupBox = new QGroupBox(groupBox_2);
        secondsLatGroupBox->setObjectName(QString::fromUtf8("secondsLatGroupBox"));
        secondsLatGroupBox->setCheckable(true);
        verticalLayout_6 = new QVBoxLayout(secondsLatGroupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        valorLabel_6 = new QLabel(secondsLatGroupBox);
        valorLabel_6->setObjectName(QString::fromUtf8("valorLabel_6"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, valorLabel_6);

        secondsLatValueSpinBox = new QSpinBox(secondsLatGroupBox);
        secondsLatValueSpinBox->setObjectName(QString::fromUtf8("secondsLatValueSpinBox"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, secondsLatValueSpinBox);

        toleranceLabel_2 = new QLabel(secondsLatGroupBox);
        toleranceLabel_2->setObjectName(QString::fromUtf8("toleranceLabel_2"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, toleranceLabel_2);

        toleranceSecondsLatValueSpinBox = new QSpinBox(secondsLatGroupBox);
        toleranceSecondsLatValueSpinBox->setObjectName(QString::fromUtf8("toleranceSecondsLatValueSpinBox"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, toleranceSecondsLatValueSpinBox);


        verticalLayout_6->addLayout(formLayout_6);


        horizontalLayout_3->addWidget(secondsLatGroupBox);


        verticalLayout_12->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(positionsDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(true);
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gradesVelGroupBox = new QGroupBox(groupBox_3);
        gradesVelGroupBox->setObjectName(QString::fromUtf8("gradesVelGroupBox"));
        gradesVelGroupBox->setCheckable(true);
        verticalLayout_7 = new QVBoxLayout(gradesVelGroupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        valorLabel_7 = new QLabel(gradesVelGroupBox);
        valorLabel_7->setObjectName(QString::fromUtf8("valorLabel_7"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, valorLabel_7);

        gradesVelValueSpinBox = new QSpinBox(gradesVelGroupBox);
        gradesVelValueSpinBox->setObjectName(QString::fromUtf8("gradesVelValueSpinBox"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, gradesVelValueSpinBox);

        toleranciaLabel_5 = new QLabel(gradesVelGroupBox);
        toleranciaLabel_5->setObjectName(QString::fromUtf8("toleranciaLabel_5"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_5);

        toleranciaGradesVelValueSpinBox = new QSpinBox(gradesVelGroupBox);
        toleranciaGradesVelValueSpinBox->setObjectName(QString::fromUtf8("toleranciaGradesVelValueSpinBox"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, toleranciaGradesVelValueSpinBox);


        verticalLayout_7->addLayout(formLayout_7);


        horizontalLayout_4->addWidget(gradesVelGroupBox);

        minutesVelGroupBox = new QGroupBox(groupBox_3);
        minutesVelGroupBox->setObjectName(QString::fromUtf8("minutesVelGroupBox"));
        minutesVelGroupBox->setCheckable(true);
        verticalLayout_8 = new QVBoxLayout(minutesVelGroupBox);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        valorLabel_8 = new QLabel(minutesVelGroupBox);
        valorLabel_8->setObjectName(QString::fromUtf8("valorLabel_8"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, valorLabel_8);

        minutesVelValueSpinBox = new QSpinBox(minutesVelGroupBox);
        minutesVelValueSpinBox->setObjectName(QString::fromUtf8("minutesVelValueSpinBox"));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, minutesVelValueSpinBox);

        toleranciaLabel_6 = new QLabel(minutesVelGroupBox);
        toleranciaLabel_6->setObjectName(QString::fromUtf8("toleranciaLabel_6"));

        formLayout_8->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_6);

        toleranciaMinutesVelValueSpinBox = new QSpinBox(minutesVelGroupBox);
        toleranciaMinutesVelValueSpinBox->setObjectName(QString::fromUtf8("toleranciaMinutesVelValueSpinBox"));

        formLayout_8->setWidget(1, QFormLayout::FieldRole, toleranciaMinutesVelValueSpinBox);


        verticalLayout_8->addLayout(formLayout_8);


        horizontalLayout_4->addWidget(minutesVelGroupBox);

        secondsVelGroupBox = new QGroupBox(groupBox_3);
        secondsVelGroupBox->setObjectName(QString::fromUtf8("secondsVelGroupBox"));
        secondsVelGroupBox->setCheckable(true);
        verticalLayout_9 = new QVBoxLayout(secondsVelGroupBox);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        formLayout_9->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        valorLabel_9 = new QLabel(secondsVelGroupBox);
        valorLabel_9->setObjectName(QString::fromUtf8("valorLabel_9"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, valorLabel_9);

        secondsVelValueSpinBox = new QSpinBox(secondsVelGroupBox);
        secondsVelValueSpinBox->setObjectName(QString::fromUtf8("secondsVelValueSpinBox"));

        formLayout_9->setWidget(0, QFormLayout::FieldRole, secondsVelValueSpinBox);

        toleranceLabel_3 = new QLabel(secondsVelGroupBox);
        toleranceLabel_3->setObjectName(QString::fromUtf8("toleranceLabel_3"));

        formLayout_9->setWidget(1, QFormLayout::LabelRole, toleranceLabel_3);

        toleranceSecondsVelValueSpinBox = new QSpinBox(secondsVelGroupBox);
        toleranceSecondsVelValueSpinBox->setObjectName(QString::fromUtf8("toleranceSecondsVelValueSpinBox"));

        formLayout_9->setWidget(1, QFormLayout::FieldRole, toleranceSecondsVelValueSpinBox);


        verticalLayout_9->addLayout(formLayout_9);


        horizontalLayout_4->addWidget(secondsVelGroupBox);


        verticalLayout_12->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(positionsDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFlat(true);
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        distanceGroupBox = new QGroupBox(groupBox_4);
        distanceGroupBox->setObjectName(QString::fromUtf8("distanceGroupBox"));
        distanceGroupBox->setCheckable(true);
        verticalLayout_10 = new QVBoxLayout(distanceGroupBox);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        distanciaLabel = new QLabel(distanceGroupBox);
        distanciaLabel->setObjectName(QString::fromUtf8("distanciaLabel"));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, distanciaLabel);

        distanciaDoubleSpinBox = new QDoubleSpinBox(distanceGroupBox);
        distanciaDoubleSpinBox->setObjectName(QString::fromUtf8("distanciaDoubleSpinBox"));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, distanciaDoubleSpinBox);

        toleranciaLabel_7 = new QLabel(distanceGroupBox);
        toleranciaLabel_7->setObjectName(QString::fromUtf8("toleranciaLabel_7"));

        formLayout_11->setWidget(1, QFormLayout::LabelRole, toleranciaLabel_7);

        toleranciaDistanceDoubleSpinBox = new QDoubleSpinBox(distanceGroupBox);
        toleranciaDistanceDoubleSpinBox->setObjectName(QString::fromUtf8("toleranciaDistanceDoubleSpinBox"));

        formLayout_11->setWidget(1, QFormLayout::FieldRole, toleranciaDistanceDoubleSpinBox);


        verticalLayout_10->addLayout(formLayout_11);


        horizontalLayout_5->addWidget(distanceGroupBox);

        housesGroupBox = new QGroupBox(groupBox_4);
        housesGroupBox->setObjectName(QString::fromUtf8("housesGroupBox"));
        housesGroupBox->setCheckable(true);
        verticalLayout_11 = new QVBoxLayout(housesGroupBox);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        casaLabel = new QLabel(housesGroupBox);
        casaLabel->setObjectName(QString::fromUtf8("casaLabel"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, casaLabel);

        casaComboBox = new QComboBox(housesGroupBox);
        casaComboBox->setObjectName(QString::fromUtf8("casaComboBox"));

        formLayout_12->setWidget(0, QFormLayout::FieldRole, casaComboBox);


        verticalLayout_11->addLayout(formLayout_12);


        horizontalLayout_5->addWidget(housesGroupBox);


        verticalLayout_12->addWidget(groupBox_4);

        buttonBox = new QDialogButtonBox(positionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_12->addWidget(buttonBox);

        buttonBox->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();

        retranslateUi(positionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), positionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), positionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(positionsDialog);
    } // setupUi

    void retranslateUi(QDialog *positionsDialog)
    {
        positionsDialog->setWindowTitle(QApplication::translate("positionsDialog", "A\303\261adir o Modificar Posicion", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("positionsDialog", "Planeta:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("positionsDialog", "Signo:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("positionsDialog", "Longitud:", 0, QApplication::UnicodeUTF8));
        gradesLonGroupBox->setTitle(QApplication::translate("positionsDialog", "Grados:", 0, QApplication::UnicodeUTF8));
        valorLabel->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranciaLabel->setText(QApplication::translate("positionsDialog", "Tolerancia", 0, QApplication::UnicodeUTF8));
        minutesLonGroupBox->setTitle(QApplication::translate("positionsDialog", "Minutos:", 0, QApplication::UnicodeUTF8));
        valorLabel_2->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_2->setText(QApplication::translate("positionsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        secondsLonGroupBox->setTitle(QApplication::translate("positionsDialog", "Segundos:", 0, QApplication::UnicodeUTF8));
        valorLabel_3->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranceLabel->setText(QApplication::translate("positionsDialog", "Tolerance", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("positionsDialog", "Latitud:", 0, QApplication::UnicodeUTF8));
        gradesLatGroupBox->setTitle(QApplication::translate("positionsDialog", "Grados:", 0, QApplication::UnicodeUTF8));
        valorLabel_4->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_3->setText(QApplication::translate("positionsDialog", "Tolerancia", 0, QApplication::UnicodeUTF8));
        minutesLatGroupBox->setTitle(QApplication::translate("positionsDialog", "Minutos:", 0, QApplication::UnicodeUTF8));
        valorLabel_5->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_4->setText(QApplication::translate("positionsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        secondsLatGroupBox->setTitle(QApplication::translate("positionsDialog", "Segundos:", 0, QApplication::UnicodeUTF8));
        valorLabel_6->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranceLabel_2->setText(QApplication::translate("positionsDialog", "Tolerance", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("positionsDialog", "Velocidad:", 0, QApplication::UnicodeUTF8));
        gradesVelGroupBox->setTitle(QApplication::translate("positionsDialog", "Grados:", 0, QApplication::UnicodeUTF8));
        valorLabel_7->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_5->setText(QApplication::translate("positionsDialog", "Tolerancia", 0, QApplication::UnicodeUTF8));
        minutesVelGroupBox->setTitle(QApplication::translate("positionsDialog", "Minutos:", 0, QApplication::UnicodeUTF8));
        valorLabel_8->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_6->setText(QApplication::translate("positionsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        secondsVelGroupBox->setTitle(QApplication::translate("positionsDialog", "Segundos:", 0, QApplication::UnicodeUTF8));
        valorLabel_9->setText(QApplication::translate("positionsDialog", "Valor", 0, QApplication::UnicodeUTF8));
        toleranceLabel_3->setText(QApplication::translate("positionsDialog", "Tolerance", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("positionsDialog", "Otros:", 0, QApplication::UnicodeUTF8));
        distanceGroupBox->setTitle(QApplication::translate("positionsDialog", "Distancia:", 0, QApplication::UnicodeUTF8));
        distanciaLabel->setText(QApplication::translate("positionsDialog", "Distancia:", 0, QApplication::UnicodeUTF8));
        toleranciaLabel_7->setText(QApplication::translate("positionsDialog", "Tolerancia:", 0, QApplication::UnicodeUTF8));
        housesGroupBox->setTitle(QApplication::translate("positionsDialog", "Casa:", 0, QApplication::UnicodeUTF8));
        casaLabel->setText(QApplication::translate("positionsDialog", "Casa:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class positionsDialog: public Ui_positionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONSDIALOG_H
