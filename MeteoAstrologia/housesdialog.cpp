#include "housesdialog.h"
#include "ui_housesdialog.h"

housesDialog::housesDialog(metAstro::housesParameter *house, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::housesDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));

    ui->codigoCasaComboBox->addItem("1 5 9", 1);
    ui->codigoCasaComboBox->addItem("10 2 6", 10);
    ui->codigoCasaComboBox->addItem("7 11 3", 7);
    ui->codigoCasaComboBox->addItem("4 8 12", 4);

    ui->tipoComboBox->addItem("Angular", "an");
    ui->tipoComboBox->addItem("Succedent", "su");
    ui->tipoComboBox->addItem("Cadent", "ca");

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

    if(house == 0){
        isMod = false;
        meinHouse = new metAstro::housesParameter;
        meinHouse->house = 1;
        meinHouse->houseType = "an";
        meinHouse->planet = 1;
        //meinHouse->house =
    }else{
        meinHouse = house;
        isMod = true;
    }

    loadData();
}

housesDialog::~housesDialog()
{
    delete ui;
}

void housesDialog::accepted(){
    meinHouse->house = ui->codigoCasaComboBox->itemData(ui->codigoCasaComboBox->currentIndex()).toInt();
    meinHouse->houseType = ui->tipoComboBox->itemData(ui->tipoComboBox->currentIndex()).toString();
    meinHouse->planet = ui->planetComboBox->itemData(ui->planetComboBox->currentIndex()).toInt();
    if(isMod){
        emit housesModded(meinHouse);
    }else{
        emit housesAdded(meinHouse);
    }
    QDialog::accept();
}

void housesDialog::closed(){
    if(!isMod) delete meinHouse;
    QDialog::close();
}

void housesDialog::loadData(){
    ui->codigoCasaComboBox->setCurrentIndex(ui->codigoCasaComboBox->findData(meinHouse->house));
    ui->tipoComboBox->setCurrentIndex(ui->tipoComboBox->findData(meinHouse->houseType));
    ui->planetComboBox->setCurrentIndex(ui->planetComboBox->findData(meinHouse->planet));
}
