#include "grabdatawidget.h"
#include "ui_grabdatawidget.h"
#include "utils.h"

grabDataWidget::grabDataWidget(bool isSizigia, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grabDataWidget)
{
    ui->setupUi(this);
    connect(ui->satelmecPushButton, SIGNAL(clicked()), this, SLOT(addSatelmecData()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveData()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->astroInfoButton, SIGNAL(clicked()), this, SLOT(calculateAstro()));

    starFisher = new QProcess();
    starFisherParser = new QProcess();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    sizigia = isSizigia;
    ui->SizigiagroupBox->setEnabled(sizigia);
    ui->SizigiagroupBox->setVisible(sizigia);
    this->wheaterData = new QList<QStringList>;

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);
}

grabDataWidget::~grabDataWidget()
{
    delete ui;
    delete wheaterData;
}

void grabDataWidget::addSatelmecData(){
    QSettings sets("config.ini");
    sets.beginGroup("program");
    QString filename = sets.value("SFDfile", "87750SFC.SFD").toString();
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly)){
        wheaterData->clear();
        bool seguir = true;
        while(!file.atEnd() && seguir){
            QString readed = QString(file.read(233));
            if(readed.count("M ", Qt::CaseSensitive) == 20) continue; //no fue tomado
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) < ui->dateTimeEdit->date()) continue;
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) > ui->dateTimeEdit->date()){
                seguir = false;
                continue;
            }

            QStringList parsed;
            while(readed.length() > 11){
                parsed << readed.left(11);
                readed.remove(0,11);
            }
            wheaterData->append(parsed);
        }
        if(wheaterData->isEmpty()){
            QMessageBox::warning(this, tr("Atencion"), tr("No hay informacion para esta fecha en el archivo seleccionado."), QMessageBox::Ok);
        }else{
            dataSelectionWidget *dialog =  new dataSelectionWidget(wheaterData, dialog);
            if(dialog->exec()){
                qDebug() << "culo";
                QStringList dataAccepted = dialog->getDataList();
                ui->tempMaxDoubleSpinBox->setValue(dataAccepted.at(1).toDouble());
                ui->tempMinDoubleSpinBox->setValue(dataAccepted.at(2).toDouble());
                double precipitaciones = dataAccepted.at(16).toDouble();
                if(precipitaciones > 990){ precipitaciones = (precipitaciones - 990) / 10; }
                ui->precipitacionSpinBox->setValue(precipitaciones);
                ui->velVientoDoubleSpinBox->setValue(dataAccepted.at(6).toInt() * 1.852);
                ui->dirVientoSpinBox->setValue(dataAccepted.at(7).toInt());
            }
            delete dialog;
        }

    }else{
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo de informacion, compruebe que no lo este usando otro programa en este momento"), QMessageBox::Ok);
    }

    filename = sets.value("RBDfile", "87750RAO.RBD").toString();
    //QFile file(filename);
    file.close();
    file.setFileName(filename);

    if(file.open(QIODevice::ReadOnly)){
        bool seguir = true;
        while(!file.atEnd() && seguir){
            QString readed = QString(file.read(33));
            if(readed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) < ui->dateTimeEdit->date()) continue;
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) > ui->dateTimeEdit->date()){
                seguir = false;
                continue;
            }
            ui->data1000500SpinBox->setValue(readed.mid(21,7).toInt());
        }
    }else{
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo de informacion, compruebe que no lo este usando otro programa en este momento"), QMessageBox::Ok);
    }
    sets.endGroup();
}

void grabDataWidget::addStarFisherData(){
    QSettings sets("config.ini");
    sets.beginGroup("program");
    qDebug() << starFisher->state();
    qDebug() << starFisherParser->state();
    qDebug() << sets.value("SFfile").toString();
    if(starFisher->state() == QProcess::NotRunning){
        starFisher->start(sets.value("SFfile").toString());
    }
    if(starFisherParser->state() == QProcess::NotRunning){
        starFisherParser->start("starFisherParser.exe");
    }
    sets.endGroup();
}

void grabDataWidget::calculateAstro(){
    information.setTimestamp(ui->dateTimeEdit->dateTime().addSecs(+3*3600));
    information.setLon(-(62.0 + (17.0 / 60.0)));
    information.setLat(-(38.0 + (43.0 / 60.0)));
    information.doCalc();
    QMessageBox::information(0, tr("Informacion"), tr("Calculos astrologicos completos"), QMessageBox::Ok);
}

void grabDataWidget::saveData2(){
    //read files
    QSqlQuery *query = new QSqlQuery();
    QString tipo;
    if(sizigia){
        if(ui->sizigiaComboBox->currentIndex() < 11){
            tipo = "mensual";
        }else{
            tipo = ui->sizigiaComboBox->currentText();
        }
    }else{
        tipo = "normal";
    }

    QFile file;
    file.setFileName("aspectarium.dat");
    qDebug() << file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        qDebug() << readed;
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0,2))
                    .arg(readed.mid(2,2))
                    .arg(readed.mid(4,2))
                    .arg(readed.mid(6))
                    .arg(readed.mid(6,2))
                    .arg(readed.mid(8))
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
        /*
Tabla grande (ASPECTARIUM)
P1P2CCMMSS.SS

P1,P2 Planetas en conjuncion
CC codigo de conjuncion
MM    Minutos Diferencia
*/
    }
    file.close();

    file.setFileName("distributionsigns.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        qDebug() << readed;
        query->exec(QString("INSERT INTO `signos` (fecha, signo, columna, planeta, tipo) VALUES"
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0, 2))
                    .arg(readed.mid(2, 2))
                    .arg(readed.mid(4, 2))
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
    }
    file.close();

    file.setFileName("distributionhouses.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        qDebug() << readed;
        query->exec(QString("INSERT INTO `casas` (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0, 2))
                    .arg(readed.mid(2, 2))
                    .arg(readed.mid(4, 2))
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
    }
    file.close();

    file.setFileName("distributionquadrants.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();qDebug() << readed;
        query->exec(QString("INSERT INTO `cuadrantes` (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0, 2))
                    .arg(readed.mid(2, 2))
                    .arg(readed.mid(4, 2))
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
    }
    file.close();

    file.setFileName("positions.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        qDebug() << readed;
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0,2))
                    .arg(readed.mid(2,2))
                    .arg(readed.mid(4,2))
                    .arg(readed.mid(6,2))
                    .arg(readed.mid(8,2))
                    .arg(readed.mid(10,2))
                    .arg(readed.mid(12,2))
                    .arg(readed.mid(14,2))
                    .arg(readed.mid(16,2))
                    .arg(readed.mid(18,2))
                    .arg(readed.mid(20,2))
                    .arg(readed.mid(22,7))
                    .arg(readed.mid(29,2))
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
        /*
ppSSG1M1S1G2M2S2G3M3S3nn.nnnnhh

donde
pp  codigo de plantea
SS  codigo de signo para la longitud
G1M1S1  Grados Minutos y Segundos Longitud
G2M2S2  Grados Minutos y Segundos Latitud
G3M3S3  Grados Minutos y Segundos Velocidad
nn.nnnn Distancia (2 enteros y cuatro decimales)
H          codigo 1-12
*/
    }
    file.close();

    QString luna = "none";

    if(ui->lunaGroupBox->isEnabled()){
        if(ui->fullMoonRadioButton->isChecked()) luna = "llena";
        if(ui->newMoonRadioButton->isChecked()) luna = "nueva";
    }

    // Modificacion de diego
    query->exec(QString("INSERT INTO estadotiempos_diarios (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500, observaciones, tipo, luna, usaf) VALUES "
                        "('%1', %2, %3, %4, %5, %6, %7, '%8', '%9', '%10', '%11')")
                .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(ui->tempMaxDoubleSpinBox->value())
                .arg(ui->tempMinDoubleSpinBox->value())
                .arg(ui->velVientoDoubleSpinBox->value())
                .arg(ui->dirVientoSpinBox->value())
                .arg(ui->precipitacionSpinBox->value())
                .arg(ui->data1000500SpinBox->value())
                .arg(ui->observacionesTextEdit->toPlainText())
                .arg(tipo)
                .arg(luna)
                .arg(usaf()));
    qDebug() << query->lastQuery() << query->lastError();

    delete query;

    close();
}


void grabDataWidget::saveData(){
    //read files
    QSqlQuery *query = new QSqlQuery();
    QString tipo;
    if(sizigia){
        if(ui->sizigiaComboBox->currentIndex() < 11){
            tipo = "mensual";
        }else{
            tipo = ui->sizigiaComboBox->currentText();
        }
    }else{
        tipo = "normal";
    }

    QFile file;

    for(int i = 0; i < information.aspectarium.size(); i++){
        astroInfo::AspectInfo asp = information.aspectarium.at(i);
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo, diference)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8', %9)")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(asp.planet1)
                    .arg(asp.planet2)
                    .arg(asp.aspect)
                    .arg(utils::getGrade(asp.diff))
                    .arg(utils::getMinutes(asp.diff))
                    .arg(utils::getSeconds(asp.diff))
                    .arg(tipo)
                    .arg(asp.diff));
    }

    for(int i = 0; i < information.signDistribution.size(); i++){
        astroInfo::DistributionSignInfo sign = information.signDistribution.at(i);
        query->exec(QString("INSERT INTO `signos` (fecha, signo, columna, planeta, tipo) VALUES"
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(sign.sign)
                    .arg(sign.column)
                    .arg(sign.planet)
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
    }

    for(int i = 0; i < information.houseDistribution.size(); i++){
        astroInfo::DistributionHousesInfo house = information.houseDistribution.at(i);
        query->exec(QString("INSERT INTO `casas` (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(house.house)
                    .arg(house.type)
                    .arg(house.planet)
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
    }

    for(int i = 0; i < information.quadrantsDistribution.size(); i++){
        astroInfo::QuadrantsInfo quad = information.quadrantsDistribution.at(i);
        query->exec(QString("INSERT INTO `cuadrantes` (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(quad.code)
                    .arg(quad.eastwest)
                    .arg(quad.planet)
                    .arg(tipo));
        qDebug() << query->lastQuery() << query->lastError();
    }

    for(int i = 0; i < information.positions.size(); i++){
        astroInfo::PositionInfo pos = information.positions.at(i);
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo, longitude, latitude, velocity) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15', %16, %17, %18)")
                    .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(pos.planet)
                    .arg(pos.sign)
                    .arg(utils::getGrade(pos.longitude))
                    .arg(utils::getMinutes(pos.longitude))
                    .arg(utils::getSeconds(pos.longitude))
                    .arg(utils::getGrade(pos.latitud))
                    .arg(utils::getMinutes(pos.latitud))
                    .arg(utils::getSeconds(pos.latitud))
                    .arg(utils::getGrade(pos.velocity))
                    .arg(utils::getMinutes(pos.velocity))
                    .arg(utils::getSeconds(pos.velocity))
                    .arg(pos.distance)
                    .arg(pos.house)
                    .arg(tipo)
                    .arg(pos.longitude)
                    .arg(pos.latitud)
                    .arg(pos.velocity));
        qDebug() << pos.longitude;
        qDebug() << pos.latitud;
        qDebug() << pos.velocity;

        qDebug() << query->lastQuery() << query->lastError();
        /*
ppSSG1M1S1G2M2S2G3M3S3nn.nnnnhh

donde
pp  codigo de plantea
SS  codigo de signo para la longitud
G1M1S1  Grados Minutos y Segundos Longitud
G2M2S2  Grados Minutos y Segundos Latitud
G3M3S3  Grados Minutos y Segundos Velocidad
nn.nnnn Distancia (2 enteros y cuatro decimales)
H          codigo 1-12
*/
    }
    file.close();

    QString luna = "none";

    if(ui->lunaGroupBox->isEnabled()){
        if(ui->fullMoonRadioButton->isChecked()) luna = "llena";
        if(ui->newMoonRadioButton->isChecked()) luna = "nueva";
    }
    // Modificacion de diego
    query->exec(QString("INSERT INTO estadotiempos_diarios (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500, observaciones, tipo, luna, usaf) VALUES "
                        "('%1', %2, %3, %4, %5, %6, %7, '%8', '%9', '%10', '%11')")
                .arg(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(ui->tempMaxDoubleSpinBox->value())
                .arg(ui->tempMinDoubleSpinBox->value())
                .arg(ui->velVientoDoubleSpinBox->value())
                .arg(ui->dirVientoSpinBox->value())
                .arg(ui->precipitacionSpinBox->value())
                .arg(ui->data1000500SpinBox->value())
                .arg(ui->observacionesTextEdit->toPlainText())
                .arg(tipo)
                .arg(luna)
                .arg(ui->cboEstacion->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    delete query;

    close();
}

QString grabDataWidget::usaf() const
{
    return ui->cboEstacion->currentText();
}
