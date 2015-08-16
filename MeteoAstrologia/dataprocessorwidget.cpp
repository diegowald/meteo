#include "dataprocessorwidget.h"
#include "ui_dataprocessorwidget.h"

dataProcessorWidget::dataProcessorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataProcessorWidget)
{
    ui->setupUi(this);

    ui->finishDateTimeEdit->setDateTime(QDateTime::currentDateTime());

    connect(ui->addStrongAspectsPushButton, SIGNAL(clicked()), this, SLOT(addStrongAspect()));
    connect(ui->modStrongAspectsPushButton, SIGNAL(clicked()), this, SLOT(modStrongAspect()));
    connect(ui->delStrongAspectsPushButton, SIGNAL(clicked()), this, SLOT(delStrongAspect()));
    connect(ui->addWeakAspectsPushButton, SIGNAL(clicked()), this, SLOT(addWeakAspect()));
    connect(ui->modWeakAspectsPushButton, SIGNAL(clicked()), this, SLOT(modWeakAspect()));
    connect(ui->delWeakAspectsPushButton, SIGNAL(clicked()), this, SLOT(delWeakAspect()));

    connect(ui->addStrongHousesPushButton, SIGNAL(clicked()), this, SLOT(addStrongHouse()));
    connect(ui->modStrongHousesPushButton, SIGNAL(clicked()), this, SLOT(modStrongHouse()));
    connect(ui->delStrongHousesPushButton, SIGNAL(clicked()), this, SLOT(delStrongHouse()));
    connect(ui->addWeakHousesPushButton, SIGNAL(clicked()), this, SLOT(addWeakHouse()));
    connect(ui->modWeakHousesPushButton, SIGNAL(clicked()), this, SLOT(modWeakHouse()));
    connect(ui->delWeakHousesPushButton, SIGNAL(clicked()), this, SLOT(delWeakHouse()));

    connect(ui->addStrongCuadrantesPushButton, SIGNAL(clicked()), this, SLOT(addStrongCuadrante()));
    connect(ui->modStrongCuadrantesPushButton, SIGNAL(clicked()), this, SLOT(modStrongCuadrante()));
    connect(ui->delStrongCuadrantesPushButton, SIGNAL(clicked()), this, SLOT(delStrongCuadrante()));
    connect(ui->addWeakCuadrantesPushButton, SIGNAL(clicked()), this, SLOT(addWeakCuadrante()));
    connect(ui->modWeakCuadrantesPushButton, SIGNAL(clicked()), this, SLOT(modWeakCuadrante()));
    connect(ui->delWeakCuadrantesPushButton, SIGNAL(clicked()), this, SLOT(delWeakCuadrante()));

    connect(ui->addStrongWeatheresPushButton, SIGNAL(clicked()), this, SLOT(addStrongWeather()));
    connect(ui->modStrongWeatheresPushButton, SIGNAL(clicked()), this, SLOT(modStrongWeather()));
    connect(ui->delStrongWeatheresPushButton, SIGNAL(clicked()), this, SLOT(delStrongWeather()));
    connect(ui->addWeakWeatheresPushButton, SIGNAL(clicked()), this, SLOT(addWeakWeather()));
    connect(ui->modWeakWeatheresPushButton, SIGNAL(clicked()), this, SLOT(modWeakWeather()));
    connect(ui->delWeakWeatheresPushButton, SIGNAL(clicked()), this, SLOT(delWeakWeather()));

    connect(ui->addStrongSignsPushButton, SIGNAL(clicked()), this, SLOT(addStrongSign()));
    connect(ui->modStrongSignsPushButton, SIGNAL(clicked()), this, SLOT(modStrongSign()));
    connect(ui->delStrongSignsPushButton, SIGNAL(clicked()), this, SLOT(delStrongSign()));
    connect(ui->addWeakSignsPushButton, SIGNAL(clicked()), this, SLOT(addWeakSign()));
    connect(ui->modWeakSignsPushButton, SIGNAL(clicked()), this, SLOT(modWeakSign()));
    connect(ui->delWeakSignsPushButton, SIGNAL(clicked()), this, SLOT(delWeakSign()));

    connect(ui->addStrongPositionsPushButton, SIGNAL(clicked()), this, SLOT(addStrongPosition()));
    connect(ui->modStrongPositionsPushButton, SIGNAL(clicked()), this, SLOT(modStrongPosition()));
    connect(ui->delStrongPositionsPushButton, SIGNAL(clicked()), this, SLOT(delStrongPosition()));
    connect(ui->addWeakPositionsPushButton, SIGNAL(clicked()), this, SLOT(addWeakPosition()));
    connect(ui->modWeakPositionsPushButton, SIGNAL(clicked()), this, SLOT(modWeakPosition()));
    connect(ui->delWeakPositionsPushButton, SIGNAL(clicked()), this, SLOT(delWeakPosition()));

    connect(ui->processButton, SIGNAL(clicked()), this, SLOT(processData()));
}

dataProcessorWidget::~dataProcessorWidget()
{
    delete ui;
}

void dataProcessorWidget::addStrongAspect(){
    aspectsDialog *form = new aspectsDialog(0, false);
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsAdd(aspectParameter*)), this, SLOT(aspectStrongAdded(aspectParameter*)));
    form->show();
}
void dataProcessorWidget::modStrongAspect(){
    QModelIndexList indexes = ui->strongAspectTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    aspectsDialog *form = new aspectsDialog(strongAspects.at(indexes.at(0).row()), false);
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsMod(aspectParameter*)), this, SLOT(aspectStrongModed(aspectParameter*)));
    form->show();
}
void dataProcessorWidget::delStrongAspect(){
    QModelIndexList indexes = ui->strongAspectTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    strongAspects.removeAt(indexes.at(0).row());
    refreshStrongAspect();
}

void dataProcessorWidget::addWeakAspect(){
    aspectsDialog *form = new aspectsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsAdd(aspectParameter*)), this, SLOT(aspectWeakAdded(aspectParameter*)));
    form->show();
}
void dataProcessorWidget::modWeakAspect(){
    QModelIndexList indexes = ui->weakAspectTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    aspectsDialog *form = new aspectsDialog(weakAspects.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsMod(aspectParameter*)), this, SLOT(aspectWeakModed(aspectParameter*)));
    form->show();
}
void dataProcessorWidget::delWeakAspect(){
    QModelIndexList indexes = ui->weakAspectTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weakAspects.removeAt(indexes.at(0).row());
    refreshWeakAspect();
}

void dataProcessorWidget::addStrongHouse(){
    housesDialog *form = new housesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(housesAdded(housesParameter*)), this, SLOT(houseStrongAdded(housesParameter*)));
    form->show();
}
void dataProcessorWidget::modStrongHouse(){
    QModelIndexList indexes = ui->strongHousesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    housesDialog *form = new housesDialog(strongHouses.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(housesModded(housesParameter*)), this, SLOT(houseStrongModed(housesParameter*)));
    form->show();
}
void dataProcessorWidget::delStrongHouse(){
    QModelIndexList indexes = ui->strongHousesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    strongHouses.removeAt(indexes.at(0).row());
    refreshStrongHouse();
}
void dataProcessorWidget::addWeakHouse(){
    housesDialog *form = new housesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(housesAdded(housesParameter*)), this, SLOT(houseWeakAdded(housesParameter*)));
    form->show();
}
void dataProcessorWidget::modWeakHouse(){
    QModelIndexList indexes = ui->strongHousesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    housesDialog *form = new housesDialog(weakHouses.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(housesModded(housesParameter*)), this, SLOT(houseWeakModed(housesParameter*)));
    form->show();
}
void dataProcessorWidget::delWeakHouse(){
    QModelIndexList indexes = ui->weakHousesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weakHouses.removeAt(indexes.at(0).row());
    refreshWeakHouse();
}

void dataProcessorWidget::addStrongSign(){
    signsDialog *form = new signsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(signsAdded(signsParameter*)), this, SLOT(signStrongAdded(signsParameter*)));
    form->show();
}
void dataProcessorWidget::modStrongSign(){
    QModelIndexList indexes = ui->strongSignsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    signsDialog *form = new signsDialog(strongSigns.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(signsModded(signsParameter*)), this, SLOT(signStrongModed(signsParameter*)));
    form->show();
}
void dataProcessorWidget::delStrongSign(){
    QModelIndexList indexes = ui->strongSignsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    strongSigns.removeAt(indexes.at(0).row());
    refreshStrongSign();
}
void dataProcessorWidget::addWeakSign(){
    signsDialog *form = new signsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(signsAdded(signsParameter*)), this, SLOT(signWeakAdded(signsParameter*)));
    form->show();
}

void dataProcessorWidget::modWeakSign(){
    QModelIndexList indexes = ui->weakSignsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    signsDialog *form = new signsDialog(this->weakSigns.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(signsModded(signsParameter*)), this, SLOT(signWeakModed(signsParameter*)));
    form->show();
}
void dataProcessorWidget::delWeakSign(){
    QModelIndexList indexes = ui->weakSignsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weakSigns.removeAt(indexes.at(0).row());
    refreshWeakSign();
}

void dataProcessorWidget::addStrongWeather(){
    weatherDialog *form = new weatherDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(weatherAdd(weatherParameter*)), this, SLOT(weatherStrongAdded(weatherParameter*)));
    form->show();
}
void dataProcessorWidget::modStrongWeather(){
    QModelIndexList indexes = ui->strongWeatheresTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weatherDialog *form = new weatherDialog(this->strongWeather.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(weatherMod(weatherParameter*)), this, SLOT(weatherStrongModed(weatherParameter*)));
    form->show();
}
void dataProcessorWidget::delStrongWeather(){
    QModelIndexList indexes = ui->strongWeatheresTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    strongWeather.removeAt(indexes.at(0).row());
    refreshStrongWeather();
}

void dataProcessorWidget::addWeakWeather(){
    weatherDialog *form = new weatherDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(weatherAdd(weatherParameter*)), this, SLOT(weatherWeakAdded(weatherParameter*)));
    form->show();
}

void dataProcessorWidget::modWeakWeather(){
    QModelIndexList indexes = ui->weakWeatheresTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weatherDialog *form = new weatherDialog(this->weakWeather.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(weatherMod(weatherParameter*)), this, SLOT(weatherWeakModed(weatherParameter*)));
    form->show();
}

void dataProcessorWidget::delWeakWeather(){
    QModelIndexList indexes = ui->weakWeatheresTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weakWeather.removeAt(indexes.at(0).row());
    refreshWeakWeather();
}

void dataProcessorWidget::addStrongCuadrante(){
    cuadrantesDialog *form = new cuadrantesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(cuadranteAdded(cuadrantesParameter*)), this, SLOT(cuadranteStrongAdded(cuadrantesParameter*)));
    form->show();
}

void dataProcessorWidget::modStrongCuadrante(){
    QModelIndexList indexes = ui->strongCuadrantesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    cuadrantesDialog *form = new cuadrantesDialog(this->strongCuadrantes.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(cuadranteModded(cuadrantesParameter*)), this, SLOT(cuadranteStrongModed(cuadrantesParameter*)));
    form->show();
}

void dataProcessorWidget::delStrongCuadrante(){
    QModelIndexList indexes = ui->strongCuadrantesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    this->strongCuadrantes.removeAt(indexes.at(0).row());
    refreshStrongCuadrante();
}

void dataProcessorWidget::addWeakCuadrante(){
    cuadrantesDialog *form = new cuadrantesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(cuadranteAdded(cuadrantesParameter*)), this, SLOT(cuadranteWeakAdded(cuadrantesParameter*)));
    form->show();
}

void dataProcessorWidget::modWeakCuadrante(){
    QModelIndexList indexes = ui->weakCuadrantesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    cuadrantesDialog *form = new cuadrantesDialog(this->weakCuadrantes.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(cuadranteModded(cuadrantesParameter*)), this, SLOT(cuadranteWeakModed(cuadrantesParameter*)));
    form->show();
}

void dataProcessorWidget::delWeakCuadrante(){
    QModelIndexList indexes = ui->weakCuadrantesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weakCuadrantes.removeAt(indexes.at(0).row());
    refreshWeakCuadrante();
}

void dataProcessorWidget::addStrongPosition(){
    positionsDialog *form = new positionsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(positionAdded(positionParameter*)), this, SLOT(positionStrongAdded(positionParameter*)));
    form->show();
}

void dataProcessorWidget::modStrongPosition(){
    QModelIndexList indexes = ui->strongPositionsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    positionsDialog *form = new positionsDialog(this->strongPositions.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(positionAdded(positionParameter*)), this, SLOT(positionStrongAdded(positionParameter*)));
    form->show();
}

void dataProcessorWidget::delStrongPosition(){
    QModelIndexList indexes = ui->strongPositionsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    strongPositions.removeAt(indexes.at(0).row());
    refreshStrongPosition();
}

void dataProcessorWidget::addWeakPosition(){
    positionsDialog *form = new positionsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(positionAdded(positionParameter*)), this, SLOT(positionWeakAdded(positionParameter*)));
    form->show();
}

void dataProcessorWidget::modWeakPosition(){
    QModelIndexList indexes = ui->weakPositionsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    positionsDialog *form = new positionsDialog(this->strongPositions.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(positionModded(positionParameter*)), this, SLOT(positionWeakModed(positionParameter*)));
    form->show();
}

void dataProcessorWidget::delWeakPosition(){
    QModelIndexList indexes = ui->weakPositionsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weakPositions.removeAt(indexes.at(0).row());
    refreshWeakPosition();
}

void dataProcessorWidget::aspectStrongAdded(metAstro::aspectParameter *asp){
    this->strongAspects << asp;
    refreshStrongAspect();
}
void dataProcessorWidget::aspectStrongModed(metAstro::aspectParameter *asp){
    refreshStrongAspect();
}
void dataProcessorWidget::aspectWeakAdded(metAstro::aspectParameter *asp){
    this->weakAspects << asp;
    refreshWeakAspect();
}
void dataProcessorWidget::aspectWeakModed(metAstro::aspectParameter *asp){
    refreshWeakAspect();
}

void dataProcessorWidget::houseStrongAdded(metAstro::housesParameter *asp){
    this->strongHouses << asp;
    refreshStrongHouse();
}
void dataProcessorWidget::houseStrongModed(metAstro::housesParameter *asp){
    refreshStrongHouse();
}
void dataProcessorWidget::houseWeakAdded(metAstro::housesParameter *asp){
    this->weakHouses << asp;
    refreshWeakHouse();
}
void dataProcessorWidget::houseWeakModed(metAstro::housesParameter *asp){
    refreshWeakHouse();
}

void dataProcessorWidget::signStrongAdded(metAstro::signsParameter *asp){
    this->strongSigns << asp;
    refreshStrongSign();
}
void dataProcessorWidget::signStrongModed(metAstro::signsParameter *asp){
    refreshStrongSign();
}
void dataProcessorWidget::signWeakAdded(metAstro::signsParameter *asp){
    this->weakSigns << asp;
    refreshWeakSign();
}
void dataProcessorWidget::signWeakModed(metAstro::signsParameter *asp){
    refreshWeakSign();
}

void dataProcessorWidget::weatherStrongAdded(metAstro::weatherParameter *asp){
    this->strongWeather << asp;
    refreshStrongWeather();
}
void dataProcessorWidget::weatherStrongModed(metAstro::weatherParameter *asp){
    refreshStrongWeather();
}
void dataProcessorWidget::weatherWeakAdded(metAstro::weatherParameter *asp){
    this->weakWeather << asp;
    refreshWeakWeather();
}
void dataProcessorWidget::weatherWeakModed(metAstro::weatherParameter *asp){
    refreshWeakWeather();
}

void dataProcessorWidget::cuadranteStrongAdded(metAstro::cuadrantesParameter *asp){
    this->strongCuadrantes << asp;
    refreshStrongCuadrante();
}
void dataProcessorWidget::cuadranteStrongModed(metAstro::cuadrantesParameter *asp){
    refreshStrongCuadrante();
}
void dataProcessorWidget::cuadranteWeakAdded(metAstro::cuadrantesParameter *asp){
    this->weakCuadrantes << asp;
    refreshWeakCuadrante();
}
void dataProcessorWidget::cuadranteWeakModed(metAstro::cuadrantesParameter *asp){
    refreshWeakCuadrante();
}

void dataProcessorWidget::positionStrongAdded(metAstro::positionParameter *asp){
    this->strongPositions << asp;
    refreshStrongPosition();
}
void dataProcessorWidget::positionStrongModed(metAstro::positionParameter *asp){
    refreshStrongPosition();
}
void dataProcessorWidget::positionWeakAdded(metAstro::positionParameter *asp){
    this->weakPositions << asp;
    refreshWeakPosition();
}
void dataProcessorWidget::positionWeakModed(metAstro::positionParameter *asp){
    refreshWeakPosition();
}

void dataProcessorWidget::refreshStrongAspect(){
    qDebug() << "refreshAspect";
    QStringList headers;
    headers << "Planeta 1" << "Aspecto" << "Planeta2" << "Grados" << "Minutos" << "Segundos";
    ui->strongAspectTableWidget->clear();
    ui->strongAspectTableWidget->setColumnCount(0);
    ui->strongAspectTableWidget->setRowCount(0);
    ui->strongAspectTableWidget->setColumnCount(6);
    ui->strongAspectTableWidget->setRowCount(this->strongAspects.count());
    ui->strongAspectTableWidget->setHorizontalHeaderLabels(headers);
    QString planet1, planet2, aspect;
    metAstro::aspectParameter *asp;
    for(int i = 0; i < this->strongAspects.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongAspects.at(i);
        planet1 = processor->retrievePlanet1(asp);
        planet2 = processor->retrievePlanet2(asp);
        aspect = processor->retrieveAspect(asp);
        ui->strongAspectTableWidget->setItem(i, 0, new QTableWidgetItem(planet1));
        ui->strongAspectTableWidget->setItem(i, 1, new QTableWidgetItem(aspect));
        ui->strongAspectTableWidget->setItem(i, 2, new QTableWidgetItem(planet2));
        ui->strongAspectTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->grade)));
        ui->strongAspectTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->minutes)));
        ui->strongAspectTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->seconds)));
    }
}

void dataProcessorWidget::refreshWeakAspect(){
    qDebug() << "refreshAspect";
    QStringList headers;
    headers << "Planeta 1" << "Aspecto" << "Planeta2" << "Grados" << "Minutos" << "Segundos";
    ui->weakAspectTableWidget->clear();
    ui->weakAspectTableWidget->setColumnCount(0);
    ui->weakAspectTableWidget->setRowCount(0);
    ui->weakAspectTableWidget->setColumnCount(6);
    ui->weakAspectTableWidget->setRowCount(this->weakAspects.count());
    ui->weakAspectTableWidget->setHorizontalHeaderLabels(headers);
    QString planet1, planet2, aspect;
    metAstro::aspectParameter *asp;
    for(int i = 0; i < this->weakAspects.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->weakAspects.at(i);
        planet1 = processor->retrievePlanet1(asp);
        planet2 = processor->retrievePlanet2(asp);
        aspect = processor->retrieveAspect(asp);
        ui->weakAspectTableWidget->setItem(i, 0, new QTableWidgetItem(planet1));
        ui->weakAspectTableWidget->setItem(i, 1, new QTableWidgetItem(aspect));
        ui->weakAspectTableWidget->setItem(i, 2, new QTableWidgetItem(planet2));
        ui->weakAspectTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->grade)));
        ui->weakAspectTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->minutes)));
        ui->weakAspectTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->seconds)));
    }
}

void dataProcessorWidget::refreshStrongPosition(){
    qDebug() << "refreshPosition";
    QStringList headers;

    headers << "Planeta" << "Signo" << "Gr. Lon" << "Min. Lon" << "Seg. Lon"<< "Gr. Lat" << "Min. Lat" << "Seg. Lat"<< "Gr. Vel" << "Min. Vel" << "Seg. Vel" << "distancia" << "casa";
    ui->strongPositionsTableWidget->clear();
    ui->strongPositionsTableWidget->setColumnCount(0);
    ui->strongPositionsTableWidget->setRowCount(0);
    ui->strongPositionsTableWidget->setColumnCount(13);
    ui->strongPositionsTableWidget->setRowCount(this->strongPositions.count());
    ui->strongPositionsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet, signs;
    metAstro::positionParameter *asp;
    for(int i = 0; i < this->strongPositions.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongPositions.at(i);
        planet = processor->retrievePlanet(asp->planet);
        signs = processor->retrieveSign(asp->sign);
        ui->strongPositionsTableWidget->setItem(i, 0, new QTableWidgetItem(planet));
        ui->strongPositionsTableWidget->setItem(i, 1, new QTableWidgetItem(signs));
        ui->strongPositionsTableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(asp->gradesLon.value)));
        ui->strongPositionsTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->minutesLon.value)));
        ui->strongPositionsTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->secondsLon.value)));
        ui->strongPositionsTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->gradesLat.value)));
        ui->strongPositionsTableWidget->setItem(i, 6, new QTableWidgetItem(QString("%1").arg(asp->minutesLat.value)));
        ui->strongPositionsTableWidget->setItem(i, 7, new QTableWidgetItem(QString("%1").arg(asp->secondsLat.value)));
        ui->strongPositionsTableWidget->setItem(i, 8, new QTableWidgetItem(QString("%1").arg(asp->gradesVel.value)));
        ui->strongPositionsTableWidget->setItem(i, 9, new QTableWidgetItem(QString("%1").arg(asp->minutesVel.value)));
        ui->strongPositionsTableWidget->setItem(i, 10, new QTableWidgetItem(QString("%1").arg(asp->secondsVel.value)));
        ui->strongPositionsTableWidget->setItem(i, 11, new QTableWidgetItem(QString("%1").arg(asp->distance)));
        ui->strongPositionsTableWidget->setItem(i, 12, new QTableWidgetItem(QString("%1").arg(asp->house)));
    }
}

void dataProcessorWidget::refreshWeakPosition(){
    qDebug() << "refreshPosition";
    QStringList headers;

    headers << "Planeta" << "Signo" << "Gr. Lon" << "Min. Lon" << "Seg. Lon"<< "Gr. Lat" << "Min. Lat" << "Seg. Lat"<< "Gr. Vel" << "Min. Vel" << "Seg. Vel" << "distancia" << "casa";
    ui->weakPositionsTableWidget->clear();
    ui->weakPositionsTableWidget->setColumnCount(0);
    ui->weakPositionsTableWidget->setRowCount(0);
    ui->weakPositionsTableWidget->setColumnCount(13);
    ui->weakPositionsTableWidget->setRowCount(this->weakPositions.count());
    ui->weakPositionsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet, signs;
    metAstro::positionParameter *asp;
    for(int i = 0; i < this->weakPositions.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->weakPositions.at(i);
        planet = processor->retrievePlanet(asp->planet);
        signs = processor->retrieveSign(asp->sign);
        ui->weakPositionsTableWidget->setItem(i, 0, new QTableWidgetItem(planet));
        ui->weakPositionsTableWidget->setItem(i, 1, new QTableWidgetItem(signs));
        ui->weakPositionsTableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(asp->gradesLon.value)));
        ui->weakPositionsTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->minutesLon.value)));
        ui->weakPositionsTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->secondsLon.value)));
        ui->weakPositionsTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->gradesLat.value)));
        ui->weakPositionsTableWidget->setItem(i, 6, new QTableWidgetItem(QString("%1").arg(asp->minutesLat.value)));
        ui->weakPositionsTableWidget->setItem(i, 7, new QTableWidgetItem(QString("%1").arg(asp->secondsLat.value)));
        ui->weakPositionsTableWidget->setItem(i, 8, new QTableWidgetItem(QString("%1").arg(asp->gradesVel.value)));
        ui->weakPositionsTableWidget->setItem(i, 9, new QTableWidgetItem(QString("%1").arg(asp->minutesVel.value)));
        ui->weakPositionsTableWidget->setItem(i, 10, new QTableWidgetItem(QString("%1").arg(asp->secondsVel.value)));
        ui->weakPositionsTableWidget->setItem(i, 11, new QTableWidgetItem(QString("%1").arg(asp->distance)));
        ui->weakPositionsTableWidget->setItem(i, 12, new QTableWidgetItem(QString("%1").arg(asp->house)));
    }
}

void dataProcessorWidget::refreshStrongHouse(){
    qDebug() << "refreshHouse";
    QStringList headers;
    headers << "Codigo Casa" << "Tipo" << "Planeta";
    ui->strongHousesTableWidget->clear();
    ui->strongHousesTableWidget->setColumnCount(0);
    ui->strongHousesTableWidget->setRowCount(0);
    ui->strongHousesTableWidget->setColumnCount(3);
    ui->strongHousesTableWidget->setRowCount(this->strongHouses.count());
    ui->strongHousesTableWidget->setHorizontalHeaderLabels(headers);
    QString planet;
    metAstro::housesParameter *asp;
    for(int i = 0; i < this->strongHouses.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongHouses.at(i);
        planet = processor->retrievePlanet(asp->planet);
        ui->strongHousesTableWidget->setItem(i, 0, new QTableWidgetItem(processor->retrieveHouse(asp->house)));
        ui->strongHousesTableWidget->setItem(i, 1, new QTableWidgetItem(asp->houseType));
        ui->strongHousesTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    }
}

void dataProcessorWidget::refreshWeakHouse(){
    qDebug() << "refreshHouse";
    QStringList headers;
    headers << "Codigo Casa" << "Tipo" << "Planeta";
    ui->weakHousesTableWidget->clear();
    ui->weakHousesTableWidget->setColumnCount(0);
    ui->weakHousesTableWidget->setRowCount(0);
    ui->weakHousesTableWidget->setColumnCount(3);
    ui->weakHousesTableWidget->setRowCount(this->weakHouses.count());
    ui->weakHousesTableWidget->setHorizontalHeaderLabels(headers);
    QString planet;
    metAstro::housesParameter *asp;
    for(int i = 0; i < this->weakHouses.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->weakHouses.at(i);
        planet = processor->retrievePlanet(asp->planet);
        ui->weakHousesTableWidget->setItem(i, 0, new QTableWidgetItem(processor->retrieveHouse(asp->house)));
        ui->weakHousesTableWidget->setItem(i, 1, new QTableWidgetItem(asp->houseType));
        ui->weakHousesTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    }
}

void dataProcessorWidget::refreshStrongCuadrante(){
    qDebug() << "refreshQuadrants";
    QStringList headers;
    headers << "Tipo" << "Posicion" << "Planeta";
    ui->strongCuadrantesTableWidget->clear();
    ui->strongCuadrantesTableWidget->setColumnCount(0);
    ui->strongCuadrantesTableWidget->setRowCount(0);
    ui->strongCuadrantesTableWidget->setColumnCount(3);
    ui->strongCuadrantesTableWidget->setRowCount(this->strongCuadrantes.count());
    ui->strongCuadrantesTableWidget->setHorizontalHeaderLabels(headers);
    QString planet;
    metAstro::cuadrantesParameter *asp;
    for(int i = 0; i < this->strongCuadrantes.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongCuadrantes.at(i);
        planet = processor->retrievePlanet(asp->planet);
        ui->strongCuadrantesTableWidget->setItem(i, 0, new QTableWidgetItem(asp->code));
        ui->strongCuadrantesTableWidget->setItem(i, 1, new QTableWidgetItem(asp->eastwest == "es" ? "este" : "oeste"));
        ui->strongCuadrantesTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    }
}

void dataProcessorWidget::refreshWeakCuadrante(){
    qDebug() << "refreshQuadrants";
    QStringList headers;
    headers << "Tipo" << "Posicion" << "Planeta";
    ui->weakCuadrantesTableWidget->clear();
    ui->weakCuadrantesTableWidget->setColumnCount(0);
    ui->weakCuadrantesTableWidget->setRowCount(0);
    ui->weakCuadrantesTableWidget->setColumnCount(3);
    ui->weakCuadrantesTableWidget->setRowCount(this->weakCuadrantes.count());
    ui->weakCuadrantesTableWidget->setHorizontalHeaderLabels(headers);
    QString planet;
    metAstro::cuadrantesParameter *asp;
    for(int i = 0; i < this->weakCuadrantes.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->weakCuadrantes.at(i);
        planet = processor->retrievePlanet(asp->planet);
        ui->weakCuadrantesTableWidget->setItem(i, 0, new QTableWidgetItem(asp->code));
        ui->weakCuadrantesTableWidget->setItem(i, 1, new QTableWidgetItem(asp->eastwest == "es" ? "este" : "oeste"));
        ui->weakCuadrantesTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    }
}

void dataProcessorWidget::refreshStrongSign(){
    qDebug() << "refreshSigns";
    QStringList headers;
    headers << "Columna" << "Elemento" << "Planeta";
    ui->strongSignsTableWidget->clear();
    ui->strongSignsTableWidget->setColumnCount(0);
    ui->strongSignsTableWidget->setRowCount(0);
    ui->strongSignsTableWidget->setColumnCount(3);
    ui->strongSignsTableWidget->setRowCount(this->strongSigns.count());
    ui->strongSignsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet, sign;
    metAstro::signsParameter *asp;
    for(int i = 0; i < this->strongSigns.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongSigns.at(i);
        planet = processor->retrievePlanet(asp->planet);
        ui->strongSignsTableWidget->setItem(i, 0, new QTableWidgetItem(asp->column));
        ui->strongSignsTableWidget->setItem(i, 1, new QTableWidgetItem(asp->sign));
        ui->strongSignsTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    }
}

void dataProcessorWidget::refreshWeakSign(){
    qDebug() << "refreshSigns";
    QStringList headers;
    headers << "Columna" << "Elemento" << "Planeta";
    ui->weakSignsTableWidget->clear();
    ui->weakSignsTableWidget->setColumnCount(0);
    ui->weakSignsTableWidget->setRowCount(0);
    ui->weakSignsTableWidget->setColumnCount(3);
    ui->weakSignsTableWidget->setRowCount(this->weakSigns.count());
    ui->weakSignsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet, sign;
    metAstro::signsParameter *asp;
    for(int i = 0; i < this->weakSigns.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->weakSigns.at(i);
        planet = processor->retrievePlanet(asp->planet);
        ui->weakSignsTableWidget->setItem(i, 0, new QTableWidgetItem(asp->column));
        ui->weakSignsTableWidget->setItem(i, 1, new QTableWidgetItem(asp->sign));
        ui->weakSignsTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    }
}

void dataProcessorWidget::refreshStrongWeather(){
    qDebug() << "refresh Weather";
    QStringList headers;
    headers << "Tipo" << "valor" << "tolerancia";
    ui->strongWeatheresTableWidget->clear();
    ui->strongWeatheresTableWidget->setColumnCount(0);
    ui->strongWeatheresTableWidget->setRowCount(0);
    ui->strongWeatheresTableWidget->setColumnCount(3);
    ui->strongWeatheresTableWidget->setRowCount(this->strongWeather.count());
    ui->strongWeatheresTableWidget->setHorizontalHeaderLabels(headers);
    //QString planet, sign;
    metAstro::weatherParameter *asp;
    for(int i = 0; i < this->strongWeather.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongWeather.at(i);
        ui->strongWeatheresTableWidget->setItem(i, 0, new QTableWidgetItem(asp->parameter));
        ui->strongWeatheresTableWidget->setItem(i, 1, new QTableWidgetItem(asp->value));
        ui->strongWeatheresTableWidget->setItem(i, 2, new QTableWidgetItem(asp->tolerance));
    }
}

void dataProcessorWidget::refreshWeakWeather(){
    qDebug() << "refresh Weather";
    QStringList headers;
    headers << "Tipo" << "valor" << "tolerancia";
    ui->weakWeatheresTableWidget->clear();
    ui->weakWeatheresTableWidget->setColumnCount(0);
    ui->weakWeatheresTableWidget->setRowCount(0);
    ui->weakWeatheresTableWidget->setColumnCount(3);
    ui->weakWeatheresTableWidget->setRowCount(this->weakWeather.count());
    ui->weakWeatheresTableWidget->setHorizontalHeaderLabels(headers);
    metAstro::weatherParameter *asp;
    for(int i = 0; i < this->strongWeather.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->strongWeather.at(i);
        ui->weakWeatheresTableWidget->setItem(i, 0, new QTableWidgetItem(asp->parameter));
        ui->weakWeatheresTableWidget->setItem(i, 1, new QTableWidgetItem(asp->value));
        ui->weakWeatheresTableWidget->setItem(i, 2, new QTableWidgetItem(asp->tolerance));
    }
}

void dataProcessorWidget::processData(){
    //subir todo al procesador
    processor->setAspects(ui->aspectsGroupBox->isChecked());
    processor->setStrongAspects(ui->strongAspectGroupBox->isChecked());
    processor->setWeakAspects(ui->weakAspectGroupBox->isChecked());

    processor->setSigns(ui->signsGroupBox->isChecked());
    processor->setStrongSigns(ui->signsGroupBox->isChecked());
    processor->setWeakSigns(ui->weakSingsGroupBox->isChecked());

    processor->setHouses(ui->housesGroupBox->isChecked());
    processor->setStrongHouses(ui->strongHousesGroupBox->isChecked());
    processor->setWeakHouses(ui->weakHousesGroupBox->isChecked());

    processor->setPositions(ui->positionsGroupBox->isChecked());
    processor->setStrongPositions(ui->strongPositionsGroupBox->isChecked());
    processor->setWeakPositions(ui->weakPositionsGroupBox->isChecked());

    processor->setQuadrants(ui->cuadrantesGroupBox->isChecked());
    processor->setStrongQuadrants(ui->strongAspectGroupBox->isChecked());
    processor->setWeakQuadrants(ui->weakQuadrantsGroupBox->isChecked());

    processor->setAspects(ui->aspectsGroupBox->isChecked());
    processor->setStrongAspects(ui->strongAspectGroupBox->isChecked());
    processor->setWeakAspects(ui->weakAspectGroupBox->isChecked());

    processor->startProcess();
}

void dataProcessorWidget::processFinished(){

}
