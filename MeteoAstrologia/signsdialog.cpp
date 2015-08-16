#include "signsdialog.h"
#include "ui_signsdialog.h"

signsDialog::signsDialog(metAstro::signsParameter *param, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signsDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));

    ui->columnaComboBox->addItem("Cardinal", "ca");
    ui->columnaComboBox->addItem("Fixed", "fi");
    ui->columnaComboBox->addItem("Mutable", "mu");

    ui->elementoComboBox->addItem("Agua", "ag");
    ui->elementoComboBox->addItem("Fuego", "fu");
    ui->elementoComboBox->addItem("Tierra", "ti");
    ui->elementoComboBox->addItem("Aire", "ai");

    ui->planetComboBox->addItem("sol", 1);
    ui->planetComboBox->addItem("luna", 2);
    ui->planetComboBox->addItem("mercurio", 3);
    ui->planetComboBox->addItem("venus", 4);
    ui->planetComboBox->addItem("marte", 5);
    ui->planetComboBox->addItem("jupiter", 6);
    ui->planetComboBox->addItem("saturno", 7);
    ui->planetComboBox->addItem("urano", 8);
    ui->planetComboBox->addItem("neptuno", 9);
    ui->planetComboBox->addItem("pluton", 10);
    ui->planetComboBox->addItem("ascendiente", 11);
    ui->planetComboBox->addItem("MC", 12);
    ui->planetComboBox->addItem("Nodo", 13);
    ui->planetComboBox->addItem("Lilith", 14);
    ui->planetComboBox->addItem("Fortuna", 15);

    if(param == 0){
        isMod = false;
        this->meinSign = new metAstro::signsParameter;
        meinSign->column = "ca";
        meinSign->sign = "fu";
        meinSign->planet = 1;
    }else{
        isMod = true;
        this->meinSign = param;
    }

    loadData();
}

signsDialog::~signsDialog()
{
    delete ui;
}

void signsDialog::accepted(){
    meinSign->column = ui->columnaComboBox->itemData(ui->columnaComboBox->currentIndex()).toString();
    meinSign->planet = ui->planetComboBox->itemData(ui->planetComboBox->currentIndex()).toInt();
    meinSign->sign = ui->elementoComboBox->itemData(ui->elementoComboBox->currentIndex()).toString();

    if(isMod){
        emit signsModded(meinSign);
    }else{
        emit signsAdded(meinSign);
    }
    QDialog::accept();
}

void signsDialog::closed(){
    if(!isMod) delete meinSign;
    QDialog::close();
}

void signsDialog::loadData(){
    ui->columnaComboBox->setCurrentIndex(ui->columnaComboBox->findData(meinSign->column));
    ui->elementoComboBox->setCurrentIndex(ui->elementoComboBox->findData(meinSign->sign));
    ui->planetComboBox->setCurrentIndex(ui->planetComboBox->findData(meinSign->planet));
}
