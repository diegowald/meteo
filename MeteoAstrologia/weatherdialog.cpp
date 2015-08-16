#include "weatherdialog.h"
#include "ui_weatherdialog.h"

weatherDialog::weatherDialog(metAstro::weatherParameter *weather, bool isNOAA, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weatherDialog)
{
    ui->setupUi(this);
    this->isNOAA = isNOAA;
    QStringList list;
    list << "Temp. Maxima"
         << "Temp. Minima"
         << "Precipitaciones"
         << "1000/500"
         << "Dir. Viento"
         << "Vel. Viento";
    if(isNOAA){
        ui->tipoComboBox->addItem("Temp. Maxima", "temp_max");
        ui->tipoComboBox->addItem("Temp. Media", "temp_media");
        ui->tipoComboBox->addItem("Temp. Minima", "temp_min");
        ui->tipoComboBox->addItem("Presion", "presion");
        ui->tipoComboBox->addItem("Visibilidad", "visibilidad");
        ui->tipoComboBox->addItem("Vel. Viento", "viento_vel");
        ui->tipoComboBox->addItem("Vel. Rafaga", "viento_rafaga");
        ui->tipoComboBox->addItem("Punto de Rocio", "punto_rocio");
        ui->tipoComboBox->addItem("Precipitaciones", "precipitaciones");
        ui->tipoComboBox->addItem("Nieve", "nieve");
        ui->tipoComboBox->addItem("Sunspots", "sunspots");

    }else{
        ui->tipoComboBox->addItem("Temp. Maxima", "maxima");
        ui->tipoComboBox->addItem("Temp. Minima", "minima");
        ui->tipoComboBox->addItem("Precipitaciones", "precipitacion");
        ui->tipoComboBox->addItem("1000/500", "mil500");
        ui->tipoComboBox->addItem("Dir. Viento", "direccionviento");
        ui->tipoComboBox->addItem("Vel. Viento", "vientovel");
    }
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));
    connect(ui->tipoComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(typeChanged(QString)));

    if(weather != 0){
        isMod = true;
        this->meinWeather = weather;
        loadWeather();
    }else{
        isMod = false;
        this->meinWeather = new metAstro::weatherParameter;
        this->meinWeather->parameter = "null";
        this->meinWeather->value = 0;
        this->meinWeather->tolerance = 0;
    }
}

weatherDialog::~weatherDialog()
{
    delete ui;
}

void weatherDialog::closed(){
    if(!isMod) delete meinWeather;
    QDialog::close();
}

void weatherDialog::accepted(){
    qDebug() << ui->tipoComboBox->currentText();

    this->meinWeather->parameter = ui->tipoComboBox->itemData(ui->tipoComboBox->currentIndex()).toString();
    this->meinWeather->value = ui->valorDoubleSpinBox->value();
    this->meinWeather->tolerance = ui->toleranciaDoubleSpinBox->value();

    if(isMod){
        emit weatherMod(this->meinWeather);
    }else{
        emit weatherAdd(this->meinWeather);
    }
    QDialog::accept();
}

void weatherDialog::loadWeather(){
    ui->tipoComboBox->setCurrentIndex(ui->tipoComboBox->findText(this->meinWeather->parameter));
    ui->valorDoubleSpinBox->setValue(this->meinWeather->value);
    ui->toleranciaDoubleSpinBox->setValue(this->meinWeather->tolerance);
}

void weatherDialog::typeChanged(QString val){

}
