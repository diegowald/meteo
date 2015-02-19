#include "aspectsdialog.h"
#include "ui_aspectsdialog.h"

aspectsDialog::aspectsDialog(metAstro::aspectParameter *aspect, bool modif, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aspectsDialog)
{
    ui->setupUi(this);
    ui->planeta1ComboBox->addItem("sol", 0);
    ui->planeta1ComboBox->addItem("luna", 1);
    ui->planeta1ComboBox->addItem("mercurio", 2);
    ui->planeta1ComboBox->addItem("venus", 3);
    ui->planeta1ComboBox->addItem("marte", 4);
    ui->planeta1ComboBox->addItem("jupiter", 5);
    ui->planeta1ComboBox->addItem("saturno", 6);
    ui->planeta1ComboBox->addItem("urano", 7);
    ui->planeta1ComboBox->addItem("neptuno", 8);
    ui->planeta1ComboBox->addItem("pluton", 9);
    ui->planeta1ComboBox->addItem("ascendente", 15);
    ui->planeta1ComboBox->addItem("MC", 13);
    ui->planeta1ComboBox->addItem("Nodo", 10);
    ui->planeta1ComboBox->addItem("Lilith", 12);
    ui->planeta1ComboBox->addItem("Fortuna", 11);

    ui->planeta2ComboBox->addItem("sol", 0);
    ui->planeta2ComboBox->addItem("luna", 1);
    ui->planeta2ComboBox->addItem("mercurio", 2);
    ui->planeta2ComboBox->addItem("venus", 3);
    ui->planeta2ComboBox->addItem("marte", 4);
    ui->planeta2ComboBox->addItem("jupiter", 5);
    ui->planeta2ComboBox->addItem("saturno", 6);
    ui->planeta2ComboBox->addItem("urano", 7);
    ui->planeta2ComboBox->addItem("neptuno", 8);
    ui->planeta2ComboBox->addItem("pluton", 9);
    ui->planeta2ComboBox->addItem("ascendiente", 12);
    ui->planeta2ComboBox->addItem("MC", 13);
    ui->planeta2ComboBox->addItem("Nodo", 10);
    ui->planeta2ComboBox->addItem("Lilith", 12);
    ui->planeta2ComboBox->addItem("Fortuna", 11);

    ui->aspectoComboBox->addItem("Conjunction", 1);
    ui->aspectoComboBox->addItem("Opposition", 2);
    ui->aspectoComboBox->addItem("Trine", 3);
    ui->aspectoComboBox->addItem("Square", 4);
    ui->aspectoComboBox->addItem("Quintile", 5);
    ui->aspectoComboBox->addItem("Biquintile", 6);
    ui->aspectoComboBox->addItem("Sextile", 7);
    ui->aspectoComboBox->addItem("Septile", 8);
    ui->aspectoComboBox->addItem("Biseptile", 9);
    ui->aspectoComboBox->addItem("Triseptile", 10);
    ui->aspectoComboBox->addItem("Octile", 11);
    ui->aspectoComboBox->addItem("Trioctile", 12);
    ui->aspectoComboBox->addItem("Novile", 13);
    ui->aspectoComboBox->addItem("Decile", 14);
    ui->aspectoComboBox->addItem("Tridecile", 15);
    ui->aspectoComboBox->addItem("Semisextile", 16);
    ui->aspectoComboBox->addItem("Quincunx", 17);
    ui->aspectoComboBox->addItem("Undecile", 18);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));

    if(aspect != 0){
        meinAspect = aspect;
        isMod = true;
    }else{
        meinAspect = new metAstro::aspectParameter;
        this->meinAspect->aspect = 1;
        this->meinAspect->planet1 = 0;
        this->meinAspect->planet2 = 0;
        this->meinAspect->computeGrade = false;
        this->meinAspect->computeMinutes = false;
        this->meinAspect->computeSeconds = false;
        this->meinAspect->grade = 0; this->meinAspect->gradeTolerance = 0;
        this->meinAspect->minutes = 0; this->meinAspect->minutesTolerance = 0;
        this->meinAspect->seconds = 0; this->meinAspect->secondsTolerance = 0;
        isMod = false;
    };

    if(modif){
        ui->toleranciaGradosSpinBox->setEnabled(false);
        ui->toleranciaMinutosSpinBox->setEnabled(false);
        ui->toleranciaSegundosSpinBox->setEnabled(false);
    };

    loadAspect();
}

aspectsDialog::~aspectsDialog()
{
    delete ui;
}

void aspectsDialog::accepted(){
    meinAspect->aspect = ui->aspectoComboBox->itemData(ui->aspectoComboBox->currentIndex()).toInt();
    meinAspect->planet1 = ui->planeta1ComboBox->itemData(ui->planeta1ComboBox->currentIndex()).toInt();
    meinAspect->planet2 = ui->planeta2ComboBox->itemData(ui->planeta2ComboBox->currentIndex()).toInt();
    meinAspect->computeGrade = ui->gradeGroupBox->isChecked();
    meinAspect->grade = ui->gradosSpinBox->value();
    meinAspect->gradeTolerance = ui->toleranciaGradosSpinBox->value();
    meinAspect->computeMinutes = ui->minutesGroupBox->isChecked();
    meinAspect->minutes = ui->minutosSpinBox->value();
    meinAspect->minutesTolerance = ui->toleranciaSegundosSpinBox->value();
    meinAspect->computeSeconds = ui->secondsGroupBox->isChecked();
    meinAspect->seconds  =ui->segundosSpinBox->value();
    meinAspect->secondsTolerance = ui->toleranciaSegundosSpinBox->value();
    if(isMod){
        emit aspectsMod(meinAspect);
    }else{
        emit aspectsAdd(meinAspect);
    };
    QDialog::accept();
}

void aspectsDialog::closed(){
    if(!isMod){
        delete meinAspect;
    };
    QDialog::close();
}

void aspectsDialog::loadAspect(){
    ui->aspectoComboBox->setCurrentIndex(ui->aspectoComboBox->findData(meinAspect->aspect));
    ui->planeta1ComboBox->setCurrentIndex(ui->planeta1ComboBox->findData(meinAspect->planet1));
    ui->planeta2ComboBox->setCurrentIndex(ui->planeta2ComboBox->findData(meinAspect->planet2));

    ui->gradeGroupBox->setChecked(meinAspect->computeGrade);
    ui->gradosSpinBox->setValue(meinAspect->grade);
    ui->toleranciaGradosSpinBox->setValue(meinAspect->gradeTolerance);
    ui->minutesGroupBox->setChecked(meinAspect->computeMinutes);
    ui->minutosSpinBox->setValue(meinAspect->minutes);
    ui->toleranciaMinutosSpinBox->setValue(meinAspect->minutesTolerance);
    ui->secondsGroupBox->setChecked(meinAspect->computeSeconds);
    ui->segundosSpinBox->setValue(meinAspect->seconds);
    ui->toleranciaSegundosSpinBox->setValue(meinAspect->secondsTolerance);
}
