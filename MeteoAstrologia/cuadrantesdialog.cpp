#include "cuadrantesdialog.h"
#include "ui_cuadrantesdialog.h"

cuadrantesDialog::cuadrantesDialog(metAstro::cuadrantesParameter *cuadrante, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cuadrantesDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));

    ui->eastwestComboBox->addItem("Este", "es");
    ui->eastwestComboBox->addItem("Oeste", "we");

    ui->codeComboBox->addItem("Above", "ab");
    ui->codeComboBox->addItem("Beneath", "be");

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

    if(cuadrante == 0){
        isMod = false;
        this->meinCuadrante = new metAstro::cuadrantesParameter;
        this->meinCuadrante->code = "ab";
        this->meinCuadrante->eastwest = "es";
        this->meinCuadrante->planet = 1;
    }else{
        isMod = true;
        this->meinCuadrante = cuadrante;
    };

    loadData();
}

cuadrantesDialog::~cuadrantesDialog()
{
    delete ui;
}

void cuadrantesDialog::accepted(){
    meinCuadrante->code = ui->codeComboBox->itemData(ui->codeComboBox->currentIndex()).toString();
    meinCuadrante->eastwest = ui->eastwestComboBox->itemData(ui->eastwestComboBox->currentIndex()).toString();
    meinCuadrante->planet = ui->planetComboBox->itemData(ui->planetComboBox->currentIndex()).toInt();

    if(isMod){
        emit cuadranteModded(this->meinCuadrante);
    }else{
        emit cuadranteAdded(this->meinCuadrante);
    };
    QDialog::accept();
}

void cuadrantesDialog::closed(){
    if(!isMod) delete meinCuadrante;
    QDialog::close();
}

void cuadrantesDialog::loadData(){
    ui->codeComboBox->setCurrentIndex(ui->codeComboBox->findData(meinCuadrante->code));
    ui->eastwestComboBox->setCurrentIndex(ui->eastwestComboBox->findData(meinCuadrante->eastwest));
    ui->planetComboBox->setCurrentIndex(ui->planetComboBox->findData(meinCuadrante->planet));
}
