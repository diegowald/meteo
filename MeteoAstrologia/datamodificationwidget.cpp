#include "datamodificationwidget.h"
#include "ui_datamodificationwidget.h"

#include "signsdialog.h"
#include "aspectsdialog.h"
#include "cuadrantesdialog.h"
#include "housesdialog.h"
#include "positionsdialog.h"

dataModificationWidget::dataModificationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataModificationWidget)
{
    ui->setupUi(this);
    dataMeaning = new dataProcessor();
    ui->typeComboBox->addItem("Normal", "normal");
    ui->typeComboBox->addItem("Sisigia de Equinoccio", "%Equinoccio%");
    ui->typeComboBox->addItem("Sisigia de Solsticio", "%Solsticio%");
    ui->typeComboBox->addItem("Sisiga Mensual", "mensual");
    changeType();
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));
    connect(ui->typeComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeType()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(eraseData()));

    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadData()));
    /*connect(ui->aspectsAddButton, SIGNAL(clicked()), this, SLOT(addAspect()));
    connect(ui->aspectsModButton, SIGNAL(clicked()), this, SLOT(modAspect()));
    connect(ui->aspectsDelButton, SIGNAL(clicked()), this, SLOT(delAspect()));

    connect(ui->cuadrantsAddButton, SIGNAL(clicked()), this, SLOT(addQuadrant()));
    connect(ui->cuadrantsModButton, SIGNAL(clicked()), this, SLOT(modQuadrant()));
    connect(ui->cuadrantsDelButton, SIGNAL(clicked()), this, SLOT(delQuadrant()));

    connect(ui->singsAddButton, SIGNAL(clicked()), this, SLOT(addSign()));
    connect(ui->singsModButton, SIGNAL(clicked()), this, SLOT(modSign()));
    connect(ui->singsDelButton, SIGNAL(clicked()), this, SLOT(delSign()));

    connect(ui->positionAddButton, SIGNAL(clicked()), this, SLOT(addPosition()));
    connect(ui->positionModButton, SIGNAL(clicked()), this, SLOT(modPosition()));
    connect(ui->positionDelButton, SIGNAL(clicked()), this, SLOT(delPosition()));

    connect(ui->housesAddButton, SIGNAL(clicked()), this, SLOT(addHouses()));
    connect(ui->housesModButton, SIGNAL(clicked()), this, SLOT(modHouses()));
    connect(ui->housesDelButton, SIGNAL(clicked()), this, SLOT(delHouses()));*/
}

dataModificationWidget::~dataModificationWidget()
{
    delete ui;
}

void dataModificationWidget::changeType(){
    QSqlQuery *query = new QSqlQuery();
    ui->dateComboBox->clear();
    query->exec(QString("SELECT DISTINCT fecha FROM estadotiempos WHERE tipo LIKE '%1' ORDER BY fecha").arg(ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString()));
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        ui->dateComboBox->addItem(query->record().field("fecha").value().toString());
    };
    delete query;
}

void dataModificationWidget::accepted(){
    eraseData();
    saveData();
    ui->filterGroupBox->setEnabled(true);
    ui->dataGroupBox->setEnabled(false);
}
void dataModificationWidget::closed(){
    ui->filterGroupBox->setEnabled(true);
    ui->dataGroupBox->setEnabled(false);
}

void dataModificationWidget::loadData(){
    ui->filterGroupBox->setEnabled(false);
    ui->dataGroupBox->setEnabled(true);
    aspects.clear();
    positions.clear();
    houses.clear();
    signs.clear();
    quadrants.clear();

    QSqlQuery *query = new QSqlQuery();
    //aspects
    //query->exec(QString("SELECT * FROM aspectariums WHERE fecha = '%1' AND tipo LIKE '%2'").arg(ui->dateComboBox->currentText()).arg(ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString()));
    /*query->exec(QString("SELECT * FROM aspectariums WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        metAstro::aspectParameter *asp = new metAstro::aspectParameter;
        /*id	fecha	planeta1	planeta2	conjuncion	totaldif	mindif	segdif	tipo*
        asp->aspect = query->record().field("conjuncion").value().toInt();
        asp->planet1 = query->record().field("planeta1").value().toInt();
        asp->planet2 = query->record().field("planeta2").value().toInt();
        asp->grade = query->record().field("totaldif").value().toInt();
        asp->minutes = query->record().field("mindif").value().toInt();
        asp->seconds = query->record().field("segdif").value().toInt();
        aspects << asp;
    };

    //positions
    //query->exec(QString("SELECT * FROM posiciones WHERE fecha = '%1' AND tipo LIKE '%2'").arg(ui->dateComboBox->currentText()).arg(ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString()));
    query->exec(QString("SELECT * FROM posiciones WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        /* id	fecha	planeta	signo	Glon	Mlon	Slon	Glat	Mlat	Slat	Gvel	Mvel	Svel	distancia	casa	tipo *
        metAstro::positionParameter *asp = new metAstro::positionParameter;
        asp->planet = query->record().field("planeta").value().toInt();
        asp->sign = query->record().field("signo").value().toInt();
        asp->gradesLon.value = query->record().field("Glon").value().toInt();
        asp->minutesLon.value = query->record().field("Mlon").value().toInt();
        asp->secondsLon.value = query->record().field("Slon").value().toInt();
        asp->gradesLat.value = query->record().field("Glat").value().toInt();
        asp->minutesLat.value = query->record().field("Mlat").value().toInt();
        asp->secondsLat.value = query->record().field("Slat").value().toInt();
        asp->gradesVel.value = query->record().field("Gvel").value().toInt();
        asp->minutesVel.value = query->record().field("Mvel").value().toInt();
        asp->secondsVel.value = query->record().field("Svel").value().toInt();
        asp->distance = query->record().field("distancia").value().toDouble();
        asp->house = query->record().field("casa").value().toInt();
        positions << asp;
    };

    //houses
    query->exec(QString("SELECT * FROM casas WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        /*codigocasa	codigotipo	planeta	*
        metAstro::housesParameter *asp = new metAstro::housesParameter;
        asp->house = query->record().field("codigocasa").value().toInt();
        asp->houseType = query->record().field("codigotipo").value().toString();
        asp->planet = query->record().field("planeta").value().toInt();
        houses << asp;
    };

    //signs
    query->exec(QString("SELECT * FROM signos WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        /*signo	columna	planeta*
        metAstro::signsParameter *asp = new metAstro::signsParameter;
        asp->column = query->record().field("columna").value().toString();
        asp->sign = query->record().field("signo").value().toString();
        asp->planet = query->record().field("planeta").value().toInt();
        signs << asp;
    };

    //quadrants
    query->exec(QString("SELECT * FROM cuadrantes WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
            /*codigo	esteoeste	planeta	*
        metAstro::cuadrantesParameter *asp = new metAstro::cuadrantesParameter;
        asp->code = query->record().field("codigo").value().toString();
        asp->eastwest = query->record().field("esteoeste").value().toString();
        asp->planet = query->record().field("planeta").value().toInt();
        quadrants << asp;
    };*/

    //weather
    query->exec(QString("SELECT * FROM estadotiempos WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    query->next();
    /*maxima	minima	vientovel	direccionviento	precipitacion	mil500	observaciones*/
    ui->data1000500SpinBox->setValue(query->record().field("mil500").value().toInt());
    ui->tempMaxDoubleSpinBox->setValue(query->record().field("maxima").value().toDouble());
    ui->tempMinDoubleSpinBox->setValue(query->record().field("minima").value().toDouble());
    ui->precipitacionSpinBox->setValue(query->record().field("precipitacion").value().toDouble());
    ui->dirVientoSpinBox->setValue(query->record().field("direccionviento").value().toInt());
    ui->velVientoDoubleSpinBox->setValue(query->record().field("vientovel").value().toInt());
    ui->observacionTextEdit->setPlainText(query->record().field("observaciones").value().toString());

    ui->kindComboBox->setCurrentIndex(ui->kindComboBox->findText(query->record().field("tipo").value().toString(), Qt::MatchFixedString));
    //qDebug() << query->record().field("tipo").value().toString() << ui->kindComboBox->findText(query->record().field("tipo").value().toString(), Qt::MatchFixedString);

    delete query;

    refresh();
}

void dataModificationWidget::saveData(){
    QDateTime span;
    span = QDateTime::fromString(ui->kindComboBox->currentText(), "yyyy-MM-dd hh:mm:ss");
    QSqlQuery *query = new QSqlQuery();
    /*for(int i = 0; i < aspects.count(); ++i){
        metAstro::aspectParameter *asp = aspects.at(i);
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8')")
                    .arg(span.toString("ddd d. mmm hh:mm:ss yyyy"))
                    .arg(asp->planet1)
                    .arg(asp->planet2)
                    .arg(asp->aspect)
                    .arg(asp->grade)
                    .arg(asp->minutes)
                    .arg(asp->seconds)
                    .arg(ui->kindComboBox->currentText()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    for(int i = 0; i < signs.count(); ++i){
        metAstro::signsParameter *asp = signs.at(i);
        query->exec(QString("INSERT INTO `signos` (fecha, signo, columna, planeta, tipo) VALUES"
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("ddd d. mmm hh:mm:ss yyyy"))
                    .arg(asp->sign)
                    .arg(asp->column)
                    .arg(asp->planet)
                    .arg(ui->kindComboBox->currentText()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    for(int i = 0; i < houses.count(); ++i){
        metAstro::housesParameter *asp = houses.at(i);
        query->exec(QString("INSERT INTO `casas` (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(span.toString("ddd d. mmm hh:mm:ss yyyy"))
                    .arg(asp->house)
                    .arg(asp->houseType)
                    .arg(asp->planet)
                    .arg(ui->kindComboBox->currentText()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    for(int i = 0; i < quadrants.count(); ++i){
        metAstro::cuadrantesParameter *asp = quadrants.at(i);
        query->exec(QString("INSERT INTO `cuadrantes` (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("ddd d. mmm hh:mm:ss yyyy"))
                    .arg(asp->code)
                    .arg(asp->eastwest)
                    .arg(asp->planet)
                    .arg(ui->kindComboBox->currentText()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    for(int i = 0; i < positions.count(); ++i){
        metAstro::positionParameter *asp = positions.at(i);
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15')")
                    .arg(span.toString("ddd d. mmm hh:mm:ss yyyy"))
                    .arg(asp->planet)
                    .arg(asp->sign)
                    .arg(asp->gradesLon.value)
                    .arg(asp->minutesLon.value)
                    .arg(asp->secondsLon.value)
                    .arg(asp->gradesLat.value)
                    .arg(asp->minutesLat.value)
                    .arg(asp->secondsLat.value)
                    .arg(asp->gradesVel.value)
                    .arg(asp->minutesVel.value)
                    .arg(asp->secondsVel.value)
                    .arg(asp->distance)
                    .arg(asp->house)
                    .arg(ui->kindComboBox->currentText()));
        qDebug() << query->lastQuery() << query->lastError();
    };*/

    query->exec(QString("UPDATE estadotiempos SET maxima = %1, minima = %2, vientovel= %3, direccionviento = %4, precipitacion = %5, mil500 = %6, observaciones = %7 "
                        " WHERE fecha = '%8'")
                //.arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(ui->tempMaxDoubleSpinBox->value())
                .arg(ui->tempMinDoubleSpinBox->value())
                .arg(ui->velVientoDoubleSpinBox->value())
                .arg(ui->dirVientoSpinBox->value())
                .arg(ui->precipitacionSpinBox->value())
                .arg(ui->data1000500SpinBox->value())
                .arg(ui->observacionTextEdit->toPlainText())
                //.arg(ui->dateComboBox->dateTime().toString("yyyy-MM-dd hh:mm:ss")));
                .arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    delete query;

}

void dataModificationWidget::eraseData(){
    QSqlQuery *query = new QSqlQuery();

    query->exec(QString("DELETE FROM estadotiempos WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM aspectariums WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM casas WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM signos WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM cuadrantes WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM posiciones WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    delete query;
}

void dataModificationWidget::refresh(){
    /*refreshAspects();
    refreshPositions();
    refreshHouses();
    refreshQuadrants();
    refreshSigns();*/
}

/*void dataModificationWidget::refreshAspects(){
    qDebug() << "refreshAspect";
    QStringList headers;
    headers << "Planeta 1" << "Aspecto" << "Planeta2" << "Grados" << "Minutos" << "Segundos";
    ui->aspectsTableWidget->clear();
    ui->aspectsTableWidget->setColumnCount(0);
    ui->aspectsTableWidget->setRowCount(0);
    ui->aspectsTableWidget->setColumnCount(6);
    ui->aspectsTableWidget->setRowCount(this->aspects.count());
    ui->aspectsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet1, planet2, aspect;
    metAstro::aspectParameter *asp;
    for(int i = 0; i < this->aspects.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->aspects.at(i);
        planet1 = dataMeaning->retrievePlanet1(asp);
        planet2 = dataMeaning->retrievePlanet2(asp);
        aspect = dataMeaning->retrieveAspect(asp);
        ui->aspectsTableWidget->setItem(i, 0, new QTableWidgetItem(planet1));
        ui->aspectsTableWidget->setItem(i, 1, new QTableWidgetItem(aspect));
        ui->aspectsTableWidget->setItem(i, 2, new QTableWidgetItem(planet2));
        ui->aspectsTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->grade)));
        ui->aspectsTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->minutes)));
        ui->aspectsTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->seconds)));
    };
}
void dataModificationWidget::refreshPositions(){
    qDebug() << "refreshPosition";
    QStringList headers;

    headers << "Planeta" << "Signo" << "Gr. Lon" << "Min. Lon" << "Seg. Lon"<< "Gr. Lat" << "Min. Lat" << "Seg. Lat"<< "Gr. Vel" << "Min. Vel" << "Seg. Vel" << "distancia" << "casa";
    ui->positionTableWidget->clear();
    ui->positionTableWidget->setColumnCount(0);
    ui->positionTableWidget->setRowCount(0);
    ui->positionTableWidget->setColumnCount(13);
    ui->positionTableWidget->setRowCount(this->positions.count());
    ui->positionTableWidget->setHorizontalHeaderLabels(headers);
    QString planet, signs;
    metAstro::positionParameter *asp;
    for(int i = 0; i < this->positions.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->positions.at(i);
        planet = dataMeaning->retrievePlanet(asp->planet);
        signs = dataMeaning->retrieveSign(asp->sign);
        ui->positionTableWidget->setItem(i, 0, new QTableWidgetItem(planet));
        ui->positionTableWidget->setItem(i, 1, new QTableWidgetItem(signs));
        ui->positionTableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(asp->gradesLon.value)));
        ui->positionTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->minutesLon.value)));
        ui->positionTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->secondsLon.value)));
        ui->positionTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->gradesLat.value)));
        ui->positionTableWidget->setItem(i, 6, new QTableWidgetItem(QString("%1").arg(asp->minutesLat.value)));
        ui->positionTableWidget->setItem(i, 7, new QTableWidgetItem(QString("%1").arg(asp->secondsLat.value)));
        ui->positionTableWidget->setItem(i, 8, new QTableWidgetItem(QString("%1").arg(asp->gradesVel.value)));
        ui->positionTableWidget->setItem(i, 9, new QTableWidgetItem(QString("%1").arg(asp->minutesVel.value)));
        ui->positionTableWidget->setItem(i, 10, new QTableWidgetItem(QString("%1").arg(asp->secondsVel.value)));
        ui->positionTableWidget->setItem(i, 11, new QTableWidgetItem(QString("%1").arg(asp->distance)));
        ui->positionTableWidget->setItem(i, 12, new QTableWidgetItem(QString("%1").arg(asp->house)));
    };
}
void dataModificationWidget::refreshHouses(){
    qDebug() << "refreshHouse";
    QStringList headers;
    headers << "Codigo Casa" << "Tipo" << "Planeta";
    ui->housesTableWidget->clear();
    ui->housesTableWidget->setColumnCount(0);
    ui->housesTableWidget->setRowCount(0);
    ui->housesTableWidget->setColumnCount(3);
    ui->housesTableWidget->setRowCount(this->houses.count());
    ui->housesTableWidget->setHorizontalHeaderLabels(headers);
    QString planet;
    metAstro::housesParameter *asp;
    for(int i = 0; i < this->houses.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->houses.at(i);
        planet = dataMeaning->retrievePlanet(asp->planet);
        ui->housesTableWidget->setItem(i, 0, new QTableWidgetItem(dataMeaning->retrieveHouse(asp->house)));
        ui->housesTableWidget->setItem(i, 1, new QTableWidgetItem(asp->houseType));
        ui->housesTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    };
}
void dataModificationWidget::refreshQuadrants(){
    qDebug() << "refreshQuadrants";
    QStringList headers;
    headers << "Tipo" << "Posicion" << "Planeta";
    ui->cuadrantsTableWidget->clear();
    ui->cuadrantsTableWidget->setColumnCount(0);
    ui->cuadrantsTableWidget->setRowCount(0);
    ui->cuadrantsTableWidget->setColumnCount(3);
    ui->cuadrantsTableWidget->setRowCount(this->quadrants.count());
    ui->cuadrantsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet;
    metAstro::cuadrantesParameter *asp;
    for(int i = 0; i < this->quadrants.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->quadrants.at(i);
        planet = dataMeaning->retrievePlanet(asp->planet);
        ui->cuadrantsTableWidget->setItem(i, 0, new QTableWidgetItem(asp->code));
        ui->cuadrantsTableWidget->setItem(i, 1, new QTableWidgetItem(asp->eastwest == "es" ? "este" : "oeste"));
        ui->cuadrantsTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    };
}
void dataModificationWidget::refreshSigns(){
    qDebug() << "refreshSigns";
    QStringList headers;
    headers << "Columna" << "Elemento" << "Planeta";
    ui->signsTableWidget->clear();
    ui->signsTableWidget->setColumnCount(0);
    ui->signsTableWidget->setRowCount(0);
    ui->signsTableWidget->setColumnCount(3);
    ui->signsTableWidget->setRowCount(this->signs.count());
    ui->signsTableWidget->setHorizontalHeaderLabels(headers);
    QString planet, sign;
    metAstro::signsParameter *asp;
    for(int i = 0; i < this->signs.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->signs.at(i);
        planet = dataMeaning->retrievePlanet(asp->planet);
        //sign = dataMeaning->retrieveSign(asp->sign);
        ui->signsTableWidget->setItem(i, 0, new QTableWidgetItem(asp->column));
        ui->signsTableWidget->setItem(i, 1, new QTableWidgetItem(asp->sign));
        ui->signsTableWidget->setItem(i, 2, new QTableWidgetItem(planet));
    };
}

void dataModificationWidget::addAspect(){
    aspectsDialog *form = new aspectsDialog(0, true);
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsAdd(aspectParameter*)), this, SLOT(aspectAdded(aspectParameter*)));
    form->show();
}
void dataModificationWidget::modAspect(){
    QModelIndexList indexes = ui->aspectsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    aspectsDialog *form = new aspectsDialog(aspects.at(indexes.at(0).row()), true);
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsMod(aspectParameter*)), this, SLOT(aspectModed(aspectParameter*)));
    form->show();
}
void dataModificationWidget::delAspect(){
    QModelIndexList indexes = ui->aspectsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    aspects.removeAt(indexes.at(0).row());
    refreshAspects();
}

void dataModificationWidget::addPosition(){
    positionsDialog *form = new positionsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(positionAdded(positionParameter*)), this, SLOT(positionAdded(positionParameter*)));
    form->show();
}
void dataModificationWidget::modPosition(){
    QModelIndexList indexes = ui->positionTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    positionsDialog *form = new positionsDialog(positions.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(positionModded(positionParameter*)), this, SLOT(positionModed(positionParameter*)));
    form->show();
}
void dataModificationWidget::delPosition(){
    QModelIndexList indexes = ui->positionTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    positions.removeAt(indexes.at(0).row());
    refreshPositions();
}

void dataModificationWidget::addHouses(){
    housesDialog *form = new housesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(housesAdded(housesParameter*)), this, SLOT(houseAdded(housesParameter*)));
    form->show();
}
void dataModificationWidget::modHouses(){
    QModelIndexList indexes = ui->housesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    housesDialog *form = new housesDialog(houses.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(housesModded(housesParameter*)), this, SLOT(houseModed(housesParameter*)));
    form->show();
}
void dataModificationWidget::delHouses(){
    QModelIndexList indexes = ui->housesTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    houses.removeAt(indexes.at(0).row());
    refreshHouses();
}

void dataModificationWidget::addQuadrant(){
    cuadrantesDialog *form = new cuadrantesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(cuadranteAdded(cuadrantesParameter*)), this, SLOT(cuadranteAdded(cuadrantesParameter*)));
    form->show();
}
void dataModificationWidget::modQuadrant(){
    QModelIndexList indexes = ui->cuadrantsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    cuadrantesDialog *form = new cuadrantesDialog(quadrants.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(cuadranteModded(cuadrantesParameter*)), this, SLOT(cuadranteModed(cuadrantesParameter*)));
    form->show();
}
void dataModificationWidget::delQuadrant(){
    QModelIndexList indexes = ui->cuadrantsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    quadrants.removeAt(indexes.at(0).row());
    refreshQuadrants();
}

void dataModificationWidget::addSign(){
    signsDialog *form = new signsDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(signsAdded(signsParameter*)), this, SLOT(signAdded(signsParameter*)));
    form->show();
}
void dataModificationWidget::modSign(){
    QModelIndexList indexes = ui->signsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    signsDialog *form = new signsDialog(signs.at(indexes.at(0).row()));
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(signsModded(signsParameter*)), this, SLOT(signModed(signsParameter*)));
    form->show();
}
void dataModificationWidget::delSign(){
    QModelIndexList indexes = ui->signsTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    signs.removeAt(indexes.at(0).row());
    refreshSigns();
}

void dataModificationWidget::aspectAdded(metAstro::aspectParameter *asp){
    this->aspects << asp;
    refreshAspects();
}
void dataModificationWidget::aspectModed(metAstro::aspectParameter *asp){
    refreshAspects();
}
void dataModificationWidget::houseAdded(metAstro::housesParameter *asp){
    this->houses << asp;
    refreshHouses();
}
void dataModificationWidget::houseModed(metAstro::housesParameter *asp){
    refreshHouses();
}
void dataModificationWidget::signAdded(metAstro::signsParameter *asp){
    this->signs << asp;
    refreshSigns();
}
void dataModificationWidget::signModed(metAstro::signsParameter *asp){
    refreshSigns();
}
void dataModificationWidget::cuadranteAdded(metAstro::cuadrantesParameter *asp){
    this->quadrants << asp;
    refreshQuadrants();
}
void dataModificationWidget::cuadranteModed(metAstro::cuadrantesParameter *asp){
    refreshQuadrants();
}
void dataModificationWidget::positionAdded(metAstro::positionParameter *asp){
    this->positions << asp;
    refreshPositions();
}
void dataModificationWidget::positionModed(metAstro::positionParameter *asp){
    refreshPositions();
}
*/
