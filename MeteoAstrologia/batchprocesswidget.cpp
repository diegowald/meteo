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

    QString _usaf = "diego";
    dates.exec(QString("SELECT count(fecha) as t FROM estadotiempos_diarios WHERE fecha >= '%1' AND fecha <= '%2' AND usaf = '%3'")
               .arg(ui->initDateEdit->date().toString("yyyy-MM-dd"))
               .arg(ui->endDateEdit->date().toString("yyyy-MM-dd"))
               .arg(_usaf));
    dates.next();
    ui->progressBar->setMaximum(dates.record().field("t").value().toInt());


    dates.exec(QString("SELECT fecha FROM estadotiempos_diarios WHERE fecha >= '%1' AND fecha <= '%2' AND usaf = '%3'")
               .arg(ui->initDateEdit->date().toString("yyyy-MM-dd"))
               .arg(ui->endDateEdit->date().toString("yyyy-MM-dd"))
               .arg(_usaf));
    qDebug() << dates.lastQuery() << dates.lastError();
    int i = 0;
    while(dates.next()){
        QDateTime date;
        QString sdate = dates.record().field("fecha").value().toString();
        date = date.fromString(sdate, "yyyy-MM-dd HH:mm:ss");
        ui->progressBar->setValue(++i);
        if(!ui->overwriteCheckBox->isChecked() && insertQuery.next()) continue;
        if(ui->astroCheckBox->isChecked()) saveCurrentAstrology(date);
        if(ui->weatherCheckBox->isChecked()) saveCurrentWeather(date);
        qApp->processEvents();
    }
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

    for(int i = 0; i < information.houseDistribution.size(); i++){
        astroInfo::DistributionHousesInfo house = information.houseDistribution.at(i);
        query->exec(QString("INSERT INTO `casas` (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(house.house)
                    .arg(house.type)
                    .arg(house.planet)
                    .arg(tipo));
    }

    for(int i = 0; i < information.positions.size(); i++){
        astroInfo::PositionInfo pos = information.positions.at(i);
        query->exec(QString("UPDATE posiciones SET casa = %1 WHERE fecha = '%2'")
                    .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(pos.house));

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
    }

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
    }
}
