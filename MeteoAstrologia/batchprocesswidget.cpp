#include "batchprocesswidget.h"
#include "ui_batchprocesswidget.h"

BatchProcessWidget::BatchProcessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatchProcessWidget)
{
    ui->setupUi(this);
    ui->endDateEdit->setDate(QDate::currentDate());
    // Latitus y Longitud de calculo spara Bahia Blanca
    information.setLon(-(62.0 + (17.0 / 60.0)));
    information.setLat(-(38.0 + (43.0 / 60.0)));

    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->doButton, SIGNAL(clicked()), this, SLOT(doCalc()));
}

BatchProcessWidget::~BatchProcessWidget()
{
    delete ui;
}

void BatchProcessWidget::doCalc(){
    QSqlQuery dates;
    QSqlQuery insertQuery;

    db = QSqlDatabase::addDatabase("QMYSQL", "away");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("meteoastrologia");
    qDebug() << db.open();

    /* init values */
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    ui->progressBar->setEnabled(true);
    dates.exec("BEGIN TRANSACTION");

    dates.exec(QString("SELECT count(fecha) as t FROM estadotiempos WHERE fecha >= '%1' AND fecha <= '%2'").arg(ui->initDateEdit->date().toString("yyyy-MM-dd")).arg(ui->endDateEdit->date().toString("yyyy-MM-dd")));
    dates.next();
    ui->progressBar->setMaximum(dates.record().field("t").value().toInt());


    dates.exec(QString("SELECT fecha FROM estadotiempos WHERE fecha >= '%1' AND fecha <= '%2'").arg(ui->initDateEdit->date().toString("yyyy-MM-dd")).arg(ui->endDateEdit->date().toString("yyyy-MM-dd")));
    qDebug() << dates.lastQuery() << dates.lastError();
    int i = 0;
    while(dates.next()){
        //qDebug() << dates.record().field("fecha").value().toString();
        QDateTime date;
        QString sdate = dates.record().field("fecha").value().toString();
        date = date.fromString(sdate, "yyyy-MM-dd HH:mm:ss");
        //date.setTime(date.time().addSecs(+3*3600)); // corrimiento a G-3 Argentina
        ui->progressBar->setValue(++i);
        if(!ui->overwriteCheckBox->isChecked() && insertQuery.next()) continue;
        //qDebug() << date;
        if(ui->astroCheckBox->isChecked()) saveCurrentAstrology(date);
        //date.setTime(date.time().addSecs(-3*3600));
        if(ui->weatherCheckBox->isChecked()) saveCurrentWeather(date);
        qApp->processEvents();
    };
    dates.exec("COMMIT TRANSACTION");

    db.close();
    ui->progressBar->setEnabled(false);
}

void BatchProcessWidget::saveCurrentAstrology(QDateTime date)
{
    QDateTime idate;
    idate = date;
    idate.setTime(date.time().addSecs(+3*3600)); // corrimiento a G-3 Argentina
    information.setTimestamp(idate);
    information.doCalc();
    QString tipo = "";
    QSqlQuery *query = new QSqlQuery();
    /*for(int i = 0; i < information.aspectarium.size(); i++){
        astroInfo::AspectInfo asp = information.aspectarium.at(i);
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo, diference)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8', %9)")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(asp.planet1)
                    .arg(asp.planet2)
                    .arg(asp.aspect)
                    .arg(utils::getGrade(asp.diff))
                    .arg(utils::getMinutes(asp.diff))
                    .arg(utils::getSeconds(asp.diff))
                    .arg(tipo)
                    .arg(asp.diff));
    };*/

    //delete query; return;

    /*for(int i = 0; i < information.signDistribution.size(); i++){
        astroInfo::DistributionSignInfo sign = information.signDistribution.at(i);
        query->exec(QString("INSERT INTO `signos` (fecha, signo, columna, planeta, tipo) VALUES"
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(sign.sign)
                    .arg(sign.column)
                    .arg(sign.planet)
                    .arg(tipo));
        //qDebug() << query->lastQuery() << query->lastError();
    };*/

    for(int i = 0; i < information.houseDistribution.size(); i++){
        astroInfo::DistributionHousesInfo house = information.houseDistribution.at(i);
        query->exec(QString("INSERT INTO `casas` (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(house.house)
                    .arg(house.type)
                    .arg(house.planet)
                    .arg(tipo));
        //qDebug() << query->lastQuery() << query->lastError();
    };

    /*for(int i = 0; i < information.quadrantsDistribution.size(); i++){
        astroInfo::QuadrantsInfo quad = information.quadrantsDistribution.at(i);
        query->exec(QString("INSERT INTO `cuadrantes` (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(quad.code)
                    .arg(quad.eastwest)
                    .arg(quad.planet)
                    .arg(tipo));
        //qDebug() << query->lastQuery() << query->lastError();
    };*/

    for(int i = 0; i < information.positions.size(); i++){
        astroInfo::PositionInfo pos = information.positions.at(i);
        /*query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo, longitude, latitude, velocity) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15', %16, %17, %18)")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
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
        qDebug() << pos.velocity;*/
        query->exec(QString("UPDATE posiciones SET casa = %1 WHERE fecha = '%2'")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(pos.house));

        //qDebug() << query->lastQuery() << query->lastError();
    }

    delete query;
}

void BatchProcessWidget::saveCurrentWeather(QDateTime date)
{
    QDateTime dates;
    dates.setDate(date.date());
    if(date.time() > QTime(21, 0)){
        dates = dates.addDays(1);
        dates.setTime(QTime(0, 0));
    }else{
        if(date.time() <= QTime(3, 0)) dates.setTime(QTime(0, 0));
        if(date.time() > QTime(3, 0) && date.time() <= QTime(9, 0)) dates.setTime(QTime(6, 0));
        if(date.time() > QTime(9, 0) && date.time() <= QTime(15, 0)) dates.setTime(QTime(12, 0));
        if(date.time() > QTime(15, 0) && date.time() <= QTime(21, 0)) dates.setTime(QTime(18, 0));
    };

    QSqlQuery insert;
    QSqlQuery select(db);

    select.exec(QString("SELECT * FROM tiempos WHERE fecha = '%1'").arg(dates.toString("yyyy-MM-dd hh:mm:ss")));
    qDebug() << select.lastQuery() << select.lastError();
    if(select.next()){
        insert.exec(QString("UPDATE estadotiempos SET maxima = %1, minima = %2, vientovel = %3, direccionviento = %4"
                            ", precipitacion = %5, mil500 = %6 WHERE fecha LIKE '%7'")
                    .arg(select.record().field("maxima").value().toDouble())
                    .arg(select.record().field("minima").value().toDouble())
                    .arg(select.record().field("vientovel").value().toDouble())
                    .arg(select.record().field("direccionviento").value().toDouble())
                    .arg(select.record().field("precipitacion").value().toInt())
                    .arg(select.record().field("mil500").value().toInt())
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    );
        qDebug() << insert.lastQuery() << insert.lastError();
    };

    /*QList<QStringList> wheaterData;

    QSettings sets("config.ini");
    sets.beginGroup("program");
    /*QFileDialog diag(this);
    if(diag.exec()){*
    QString filename = sets.value("SFDfile", "87750SFC.SFD").toString();
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly)){
        wheaterData.clear();
        bool seguir = true;
        while(!file.atEnd() && seguir){
            //qDebug() << "wepa";
            QString readed = QString(file.read(233));
            //qDebug() << readed;
            if(readed.count("M ", Qt::CaseSensitive) == 20) continue; //no fue tomado
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) < date.date()) continue;
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) > date.date()){
                seguir = false;
                continue;
            };

            QStringList parsed;
            while(readed.length() > 11){
                parsed << readed.left(11);
                readed.remove(0,11);
            };
            wheaterData.append(parsed);
        };
        if(wheaterData.isEmpty()){
            //QMessageBox::warning(this, tr("Atencion"), tr("No hay informacion para esta fecha en el archivo seleccionado."), QMessageBox::Ok);
            //si esta vacio, no lo cargo, no me importa
        }else{
            int i = 0;
            while(i < wheaterData.count()){
                QString hour = wheaterData.at(i).at(0);
                hour = hour.mid(9, 2);
            };
        };

    }else{
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo de informacion, compruebe que no lo este usando otro programa en este momento"), QMessageBox::Ok);
    };

    filename = sets.value("RBDfile", "87750RAO.RBD").toString();
    //QFile file(filename);
    file.close();
    file.setFileName(filename);

    if(file.open(QIODevice::ReadOnly)){
        bool seguir = true;
        while(!file.atEnd() && seguir){
            //qDebug() << "wepa";
            QString readed = QString(file.read(33));
            //qDebug() << readed;
            if(readed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) < date.date()) continue;
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) > date.date()){
                seguir = false;
                continue;
            };
            //ui->data1000500SpinBox->setValue(readed.mid(21,7).toInt());
            /*QStringList parsed;
            while(readed.length() > 11){
                parsed << readed.left(11);
                readed.remove(0,11);
            };
            wheaterData->append(parsed);*
        };
    }else{
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo de informacion, compruebe que no lo este usando otro programa en este momento"), QMessageBox::Ok);
    };
    sets.endGroup();*/
}
