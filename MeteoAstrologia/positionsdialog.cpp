#include "positionsdialog.h"
#include "ui_positionsdialog.h"

positionsDialog::positionsDialog(metAstro::positionParameter *param, bool modif, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::positionsDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));

    /*ui->casaComboBox->addItem("1 5 9", 1);
    ui->casaComboBox->addItem("10 2 6", 10);
    ui->casaComboBox->addItem("7 11 3", 7);
    ui->casaComboBox->addItem("4 8 12", 4);*/
    ui->casaComboBox->addItem("1", 1);
    ui->casaComboBox->addItem("2", 2);
    ui->casaComboBox->addItem("3", 3);
    ui->casaComboBox->addItem("4", 4);
    ui->casaComboBox->addItem("5", 5);
    ui->casaComboBox->addItem("6", 6);
    ui->casaComboBox->addItem("7", 7);
    ui->casaComboBox->addItem("8", 8);
    ui->casaComboBox->addItem("9", 9);
    ui->casaComboBox->addItem("10", 10);
    ui->casaComboBox->addItem("11", 11);
    ui->casaComboBox->addItem("12", 12);

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

    ui->signComboBox->addItem("Aries", 1);
    ui->signComboBox->addItem("Taurus", 2);
    ui->signComboBox->addItem("Gemini", 3);
    ui->signComboBox->addItem("Cancer", 4);
    ui->signComboBox->addItem("Leo", 5);
    ui->signComboBox->addItem("Virgo", 6);
    ui->signComboBox->addItem("Libra", 7);
    ui->signComboBox->addItem("Scorpio", 8);
    ui->signComboBox->addItem("Sagittarius", 9);
    ui->signComboBox->addItem("Capricorn", 10);
    ui->signComboBox->addItem("Aquarius", 11);
    ui->signComboBox->addItem("Pisces", 12);


    if(param == 0){
        isMod = false;
        this->meinPosition = new metAstro::positionParameter;
        meinPosition->sign = 1;
        meinPosition->planet = 1;
        meinPosition->computeDistance = false;
        meinPosition->distance = 0;
        meinPosition->distanceTolerance = 0;
        meinPosition->computeHouse = false;
        meinPosition->house = 1;
        meinPosition->gradesLat.compute = false;
        meinPosition->gradesLat.tolerance= 0;
        meinPosition->gradesLat.value = 0;
        meinPosition->gradesLon.compute = false;
        meinPosition->gradesLon.tolerance= 0;
        meinPosition->gradesLon.value = 0;
        meinPosition->gradesVel.compute = false;
        meinPosition->gradesVel.tolerance= 0;
        meinPosition->gradesVel.value = 0;

        meinPosition->minutesLat.compute = false;
        meinPosition->minutesLat.tolerance= 0;
        meinPosition->minutesLat.value = 0;
        meinPosition->minutesLon.compute = false;
        meinPosition->minutesLon.tolerance= 0;
        meinPosition->minutesLon.value = 0;
        meinPosition->minutesVel.compute = false;
        meinPosition->minutesVel.tolerance= 0;
        meinPosition->minutesVel.value = 0;

        meinPosition->secondsLat.compute = false;
        meinPosition->secondsLat.tolerance= 0;
        meinPosition->secondsLat.value = 0;
        meinPosition->secondsLon.compute = false;
        meinPosition->secondsLon.tolerance= 0;
        meinPosition->secondsLon.value = 0;
        meinPosition->secondsVel.compute = false;
        meinPosition->secondsVel.tolerance= 0;
        meinPosition->secondsVel.value = 0;
    }else{
        isMod = true;
        this->meinPosition = param;

    };

    if(modif){
    };

    loadData();
}

positionsDialog::~positionsDialog()
{
    delete ui;
}

void positionsDialog::accepted(){
    meinPosition->sign = ui->signComboBox->itemData(ui->signComboBox->currentIndex()).toInt();
    meinPosition->planet = ui->planetComboBox->itemData(ui->planetComboBox->currentIndex()).toInt();
    meinPosition->computeDistance = ui->distanceGroupBox->isChecked();
    meinPosition->distance = ui->distanciaDoubleSpinBox->value();
    meinPosition->distanceTolerance = ui->toleranciaDistanceDoubleSpinBox->value();
    meinPosition->computeHouse = ui->housesGroupBox->isChecked();
    meinPosition->house = ui->casaComboBox->itemData(ui->casaComboBox->currentIndex()).toInt();

    meinPosition->gradesLat.compute = ui->gradesLatGroupBox->isChecked();
    meinPosition->gradesLat.tolerance = ui->toleranciaGradesLatValueSpinBox->value();
    meinPosition->gradesLat.value = ui->gradesLatValueSpinBox->value();;
    meinPosition->gradesLon.compute = ui->gradesLonGroupBox->isChecked();
    meinPosition->gradesLon.tolerance= ui->toleranciaGradesLonValueSpinBox->value();
    meinPosition->gradesLon.value = ui->gradesLonValueSpinBox->value();
    meinPosition->gradesVel.compute = ui->gradesVelGroupBox->isChecked();
    meinPosition->gradesVel.tolerance= ui->toleranciaGradesVelValueSpinBox->value();
    meinPosition->gradesVel.value = ui->gradesVelValueSpinBox->value();

    meinPosition->minutesLat.compute = ui->minutesLatGroupBox->isChecked();
    meinPosition->minutesLat.tolerance = ui->toleranciaMinutesLatValueSpinBox->value();
    meinPosition->minutesLat.value = ui->minutesLatValueSpinBox->value();;
    meinPosition->minutesLon.compute = ui->minutesLonGroupBox->isChecked();
    meinPosition->minutesLon.tolerance= ui->toleranciaMinutesLonValueSpinBox->value();
    meinPosition->minutesLon.value = ui->minutesLonValueSpinBox->value();
    meinPosition->minutesVel.compute = ui->minutesVelGroupBox->isChecked();
    meinPosition->minutesVel.tolerance= ui->toleranciaMinutesVelValueSpinBox->value();
    meinPosition->minutesVel.value = ui->minutesVelValueSpinBox->value();

    meinPosition->secondsLat.compute = ui->secondsLatGroupBox->isChecked();
    meinPosition->secondsLat.tolerance = ui->toleranceSecondsLatValueSpinBox->value();
    meinPosition->secondsLat.value = ui->secondsLatValueSpinBox->value();;
    meinPosition->secondsLon.compute = ui->secondsLonGroupBox->isChecked();
    meinPosition->secondsLon.tolerance= ui->toleranceSecondsLonValueSpinBox->value();
    meinPosition->secondsLon.value = ui->secondsLonValueSpinBox->value();
    meinPosition->secondsVel.compute = ui->secondsVelGroupBox->isChecked();
    meinPosition->secondsVel.tolerance= ui->toleranceSecondsVelValueSpinBox->value();
    meinPosition->secondsVel.value = ui->secondsVelValueSpinBox->value();

    if(isMod){
        emit positionModded(this->meinPosition);
    }else{
        emit positionAdded(this->meinPosition);
    };
    QDialog::accept();
}

void positionsDialog::closed(){
    if(!isMod) delete this->meinPosition;
    QDialog::close();
}

void positionsDialog::loadData(){
    ui->signComboBox->setCurrentIndex(ui->signComboBox->findData(meinPosition->sign));
    ui->planetComboBox->setCurrentIndex(ui->planetComboBox->findData(meinPosition->planet));
    ui->casaComboBox->setCurrentIndex(ui->casaComboBox->findData(meinPosition->house));
    ui->housesGroupBox->setChecked(meinPosition->computeHouse);
    ui->distanceGroupBox->setChecked(meinPosition->computeDistance);
    ui->distanciaDoubleSpinBox->setValue(meinPosition->distance);
    ui->toleranciaDistanceDoubleSpinBox->setValue(meinPosition->distanceTolerance);

    ui->gradesLatGroupBox->setChecked(meinPosition->gradesLat.compute);
    ui->gradesLatValueSpinBox->setValue(meinPosition->gradesLat.value);
    ui->toleranciaGradesLatValueSpinBox->setValue(meinPosition->gradesLat.tolerance);

    ui->minutesLatGroupBox->setChecked(meinPosition->minutesLat.compute);
    ui->minutesLatValueSpinBox->setValue(meinPosition->minutesLat.value);
    ui->toleranciaMinutesLatValueSpinBox->setValue(meinPosition->minutesLat.tolerance);

    ui->secondsLatGroupBox->setChecked(meinPosition->secondsLat.compute);
    ui->secondsLatValueSpinBox->setValue(meinPosition->secondsLat.value);
    ui->toleranceSecondsLatValueSpinBox->setValue(meinPosition->secondsLat.tolerance);

    ui->gradesLonGroupBox->setChecked(meinPosition->gradesLon.compute);
    ui->gradesLonValueSpinBox->setValue(meinPosition->gradesLon.value);
    ui->toleranciaGradesLonValueSpinBox->setValue(meinPosition->gradesLon.tolerance);

    ui->minutesLonGroupBox->setChecked(meinPosition->minutesLon.compute);
    ui->minutesLonValueSpinBox->setValue(meinPosition->minutesLon.value);
    ui->toleranciaMinutesLonValueSpinBox->setValue(meinPosition->minutesLon.tolerance);

    ui->secondsLonGroupBox->setChecked(meinPosition->secondsLon.compute);
    ui->secondsLonValueSpinBox->setValue(meinPosition->secondsLon.value);
    ui->toleranceSecondsLonValueSpinBox->setValue(meinPosition->secondsLon.tolerance);

    ui->gradesVelGroupBox->setChecked(meinPosition->gradesVel.compute);
    ui->gradesVelValueSpinBox->setValue(meinPosition->gradesVel.value);
    ui->toleranciaGradesVelValueSpinBox->setValue(meinPosition->gradesVel.tolerance);

    ui->minutesVelGroupBox->setChecked(meinPosition->minutesVel.compute);
    ui->minutesVelValueSpinBox->setValue(meinPosition->minutesVel.value);
    ui->toleranciaMinutesVelValueSpinBox->setValue(meinPosition->minutesVel.tolerance);

    ui->secondsVelGroupBox->setChecked(meinPosition->secondsVel.compute);
    ui->secondsVelValueSpinBox->setValue(meinPosition->secondsVel.value);
    ui->toleranceSecondsVelValueSpinBox->setValue(meinPosition->secondsVel.tolerance);

}
