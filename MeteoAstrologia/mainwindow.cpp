#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grabdatawidget.h"
#include "browsetablewidget.h"
#include "processdatawidget.h"
#include "dataprocessorwidget.h"
#include "datamodificationwidget.h"
#include "batchastrologicgrabdata.h"
#include "processbyweatherwidget.h"
#include "pingpongwidget.h"
#include "weatherdisplaywidget.h"
#include "processbyaspectwidget.h"
#include "processbydignitywidget.h"
#include "processbymonths.h"
#include "processbycycleswidget.h"
#include "monthviewwidget.h"
#include "sizigiaexcelreportwidget.h"
#include "workingdatedialog.h"
#include "rbdtoweatherdialog.h"
#include "weathertonoaadialog.h"
#include "calcptosprimordialesdialog.h"
#include "monthcalcdialog.h"

MainWindow* MainWindow::mahself = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    excel(new excelExportWidget)
{
    ui->setupUi(this);
    setWindowTitle("MeteoAstrlogia Ver: " + VERSION);

    connect(ui->actionDefinir_Fecha_de_Trabajo, SIGNAL(triggered()), this, SLOT(workingDate()));
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionCarga_de_Dia, SIGNAL(triggered()), this, SLOT(cargaDeDia()));
    connect(ui->actionCarga_de_Sizigia, SIGNAL(triggered()), this, SLOT(cargaDeSizigia()));
    connect(ui->actionVer_Tabla_de_Datos, SIGNAL(triggered()), this, SLOT(browseTables()));
    connect(ui->actionVer_Datos_Mensuales, SIGNAL(triggered()), this, SLOT(browseMonth()));
    connect(ui->actionOpciones, SIGNAL(triggered()), this, SLOT(showOptions()));
    //connect(ui->actionProcesar_Datos, SIGNAL(triggered()), this, SLOT(processData()));
    connect(ui->actionModificacion_de_Datos, SIGNAL(triggered()), this, SLOT(modifyData()));
    connect(ui->actionCarga_en_Batch, SIGNAL(triggered()), this, SLOT(batchProcessor()));
    connect(ui->actionCarga_de_Archivos, SIGNAL(triggered()), this, SLOT(fileProcessor()));
    connect(ui->actionVer_dias, SIGNAL(triggered()), this, SLOT(showDays()));
    connect(ui->actionExportar_por_Sizigias_P_Primordiales, SIGNAL(triggered()), this, SLOT(showSizigias()));
    connect(ui->actionExportar_por_Fechas_Escogidas, SIGNAL(triggered()), this, SLOT(showExcel()));
    connect(ui->actionRecalcular_datos_Mensuales, SIGNAL(triggered()), this, SLOT(recalcMothlyValues()));
    connect(ui->actionProceso_Por_Tiempo, SIGNAL(triggered()), this, SLOT(processByWeather()));
    connect(ui->actionProceso_Por_Aspectos, SIGNAL(triggered()), this, SLOT(processByAspects()));
    connect(ui->actionProceso_Por_Ciclos, SIGNAL(triggered()), this, SLOT(processByCycles()));
    connect(ui->actionProcesar_por_Dignidad, SIGNAL(triggered()), this, SLOT(processByDignity()));
    connect(ui->actionProcesar_por_mes_lluvia, SIGNAL(triggered()), this, SLOT(processByMonthRain()));
    connect(ui->actionCargar_datos_RBD_y_SFD, SIGNAL(triggered()), this, SLOT(loadRDBData()));
    connect(ui->actionTiempos_Astrales_a_NOAA, SIGNAL(triggered()), this, SLOT(weatherToNOAA()));
    connect(ui->actionRBD_a_Tiempos_Astrales, SIGNAL(triggered()), this, SLOT(refreshFromRBD()));

    connect(ui->actionCalcular_Pto_Primordiales, SIGNAL(triggered()), this, SLOT(calcPrimordialPoints()));
    connectToDatabase();

    ui->actionProceso_por_Posicion_Astral->setVisible(false);
    //ui->actionCalcular_Pto_Primordiales->setVisible(false);
    ui->actionCarga_en_Batch->setEnabled(false);
    ui->actionCarga_de_Dia->setVisible(false);
    ui->actionCarga_de_Sizigia->setVisible(false);
    ui->actionCarga_en_Batch->setVisible(false);

    date = QDateTime::currentDateTime();
}

MainWindow::~MainWindow()
{
    excel->close();
    delete excel;
    delete ui;
}

void MainWindow::connectToDatabase(){
    /*db = QSqlDatabase::addDatabase("QMYSQL");
    *db.setHostName("c2si.com.ar");
    db.setUserName("shaka_ddodero");
    db.setPassword("ddodero");
    db.setDatabaseName("shaka_ddodero");*
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("meteoastrologia");*/

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("localbase.dat");
    //db.open()
    qDebug() << db.open();

    //qDebug() << db.tables();
    /*db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("localbase.dat");
    db.open();*/


    QSqlQuery *query = new QSqlQuery();


    /*query->exec("CREATE TABLE IF NOT EXISTS `signos` ("
                "  `id` INTEGER PRIMARY KEY,"
                "  `fecha` DATESTAMP NOT NULL,"
                "  `signo` varchar(2) NOT NULL,"
                "  `columna` varchar(2) NOT NULL,"
                "  `planeta` short NOT NULL,"
                "  `tipo` varchar(32) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `cuadrantes` ("
                "  `id` INTEGER PRIMARY KEY,"
                "  `fecha` DATESTAMP NOT NULL,"
                "  `codigo` varchar(2) NOT NULL,"
                "  `esteoeste` varchar(2) NOT NULL,"
                "  `planeta` short NOT NULL,"
                "  `tipo` varchar(32) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `casas` ("
                "  `id` INTEGER PRIMARY KEY,"
                "  `fecha` DATESTAMP NOT NULL,"
                "  `codigocasa` short NOT NULL,"
                "  `codigotipo` varchar(2) NOT NULL,"
                "  `planeta` short NOT NULL,"
                "  `tipo` varchar(32) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `posiciones` ("
                "  `id` INTEGER PRIMARY KEY,"
                "  `fecha` DATESTAMP NOT NULL,"
                "  `planeta` short NOT NULL,"
                "  `signo` short NOT NULL,"
                "  `Glon` short NOT NULL,"
                "  `Mlon` short NOT NULL,"
                "  `Slon` short NOT NULL,"
                "  `Glat` short NOT NULL,"
                "  `Mlat` short NOT NULL,"
                "  `Slat` short NOT NULL,"
                "  `Gvel` short NOT NULL,"
                "  `Mvel` short NOT NULL,"
                "  `Svel` short NOT NULL,"
                "  `distancia` decimal(7,4) NOT NULL,"
                "  `casa` short NOT NULL,"
                "  `tipo` varchar(32) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `aspectariums` ("
                "  `id` INTEGER PRIMARY KEY,"
                "  `fecha` DATESTAMP NOT NULL,"
                "  `planeta1` short NOT NULL,"
                "  `planeta2` short NOT NULL,"
                "  `conjuncion` short NOT NULL,"
                "  `totaldif` decimal(6,0) NOT NULL,"
                "  `mindif` decimal(4,0) NOT NULL,"
                "  `segdif` decimal(4,0) NOT NULL,"
                "  `tipo` varchar(32) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `estadotiempos` ("
                "  `id` INTEGER PRIMARY KEY,"
                "  `fecha` DATESTAMP NOT NULL,"
                "  `maxima` decimal(7,4) NOT NULL,"
                "  `minima` decimal(7,4) NOT NULL,"
                "  `vientovel` decimal(7,4) NOT NULL,"
                "  `direccionviento` decimal(7,4) NOT NULL,"
                "  `precipitacion` short NOT NULL,"
                "  `mil500` short NOT NULL,"
                "  `observaciones` TEXT NOT NULL,"
                "  `luna` varchar(5) NOT NULL,"
                "  `tipo` varchar(32) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `planetas` ("
                " num INTEGER NOT NULL, "
                " planeta VARCHAR(50) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("CREATE TABLE IF NOT EXISTS `conjunciones` ("
                " num INTEGER NOT NULL, "
                " conjuncion VARCHAR(50) NOT NULL"
                ");");
    qDebug() << query->lastQuery() << query->lastError();*/

    //query->exec("insert INTO planetas (num, planeta) VALUES (01,'sol')");
    /*query->exec("REPALCE INTO planetas (num, planeta) VALUES (00,'sol')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (01,'luna')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (02,'mercurio')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (03,'venus')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (04,'marte')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (05,'jupiter')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (06,'saturno')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (07,'urano')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (08,'neptuno')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (09,'pluton')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (14,'tierra')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (12,'ascendiente')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (13,'MC')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (10,'Nodo')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (12,'Lilith')");
    query->exec("REPLACE INTO planetas (num, planeta) VALUES (11,'Fortuna')");

    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (01,'Conjunction')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (02,'Opposition')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (03,'Trine')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (04,'Square')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (05,'Quintile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (06,'Biquintile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (07,'Sextile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (08,'Septile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (09,'Biseptile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (10,'Triseptile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (11,'Octile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (12,'Trioctile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (13,'Novile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (14,'Decile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (15,'Tridecile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (16,'Semisextile')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (17,'Quincunx')");
    query->exec("REPLACE INTO conjunciones (num, conjuncion) VALUES (18,'Undecile')");*/

    //doBatch();

    /*query->exec("DELETE FROM signos");
    qDebug() << query->lastQuery() << query->lastError();
    query->exec("DELETE FROM cuadrantes");
    qDebug() << query->lastQuery() << query->lastError();
    query->exec("DELETE FROM casas");
    qDebug() << query->lastQuery() << query->lastError();
    query->exec("DELETE FROM posiciones");
    qDebug() << query->lastQuery() << query->lastError();
    query->exec("DELETE FROM aspectariums");
    qDebug() << query->lastQuery() << query->lastError();*/
    /*query->exec("VACUUM");
    qDebug() << query->lastQuery() << query->lastError();*/

    delete query;/**/

   //loadTPSData();
   //loadSQLiteData();
   // refreshWeather();
}

void MainWindow::workingDate(){
    workingDateDialog *form = new workingDateDialog();
    connect(form, SIGNAL(dateSubmited(QDateTime)), this, SLOT(setWorkingDate(QDateTime)));
    showForm(form, true);
}

void MainWindow::refreshWeather(){
    QSettings sets("config.ini");
    sets.beginGroup("program");
    /*QFileDialog diag(this);
    if(diag.exec()){*/
    QString filename = sets.value("SFDfile", "87750SFC.SFD").toString();
    QFile file(filename);
    QSqlQuery *query = new QSqlQuery();
    QSqlQuery *insert = new QSqlQuery();
    if(file.open(QIODevice::ReadOnly)){;
        while(!file.atEnd()){
            //qDebug() << "wepa";
            QString readed = QString(file.read(233));
            QString toParse = readed;
            //qDebug() << readed;
            if(readed.count("M ", Qt::CaseSensitive) == 20) continue; //no fue tomado

            QStringList parsed;
            while(toParse.length() > 11){
                parsed << toParse.left(11);
                toParse.remove(0,11);
            };

            //query->exec(QString("SELECT *, date(fecha) as t FROM estadotiempos WHERE t = '%1'").arg(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")).toString("yyyy-MM-dd")));
            query->exec(QString("SELECT *, date(fecha) as t, time(fecha) as h, timediff(time(fecha), '%1:00:00') as dif, hour(timediff(time(fecha), '%1:00:00')) * 60 + minute(timediff(time(fecha), '%1:00:00')) as minutes FROM estadotiempos WHERE date(fecha) = '%2'").arg(parsed.at(0).mid(9,2)).arg(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")).toString("yyyy-MM-dd")));

            /*if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) < ui->dateTimeEdit->date()) continue;
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) > ui->dateTimeEdit->date()){
                seguir = false;
                continue;
            };*/
            qDebug() << query->lastQuery() << query->lastError();
            while(query->next()){
                qDebug() << query->record().field("minutes").value();
                //if(query->record().field("minutes").value().toInt() < 120){
                    double precipitaciones = parsed.at(16).toDouble();
                    if(precipitaciones >= 990){ precipitaciones = (precipitaciones - 990) / 10; };
                    if(parsed.at(1).toDouble() == -99) continue;
                    if(parsed.at(2).toDouble() == -99) continue;
                    insert->exec(QString("UPDATE estadotiempos SET maxima = %1, minima = %2, vientovel = %3, direccionviento = %4,"
                                        "precipitacion = %5 WHERE id = %6 AND maxima = 0 AND minima = 0")
                                .arg(parsed.at(1).toDouble() == -99 ? 0 : parsed.at(1).toDouble())
                                .arg(parsed.at(2).toDouble() == -99 ? 0 : parsed.at(2).toDouble())
                                .arg(parsed.at(6).toInt() * 1.852)
                                .arg(parsed.at(7).toInt())
                                .arg(precipitaciones == -99 ? 0 : precipitaciones)
                                .arg(query->record().field("id").value().toInt()));
                    qDebug() << insert->lastQuery() << insert->lastError();
                //};

            };

            //wheaterData->append(parsed);
        };
    }else{
        qDebug() << "i cannot open the file";
    };

    filename = sets.value("RBDfile", "87750RAO.RBD").toString();
    //QFile file(filename);
    file.close();
    file.setFileName(filename);

    if(file.open(QIODevice::ReadOnly)){
        while(!file.atEnd()){
            //qDebug() << "wepa";
            QString parsed = QString(file.read(33));
            qDebug() << parsed;
            if(parsed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado

            //ui->data1000500SpinBox->setValue(readed.mid(21,7).toInt());
            query->exec(QString("SELECT *, date(fecha) as t, time(fecha) as h, timediff(time(fecha), '%1:00:00') as dif, hour(timediff(time(fecha), '%1:00:00')) * 60 + minute(timediff(time(fecha), '%1:00:00')) as minutes FROM estadotiempos WHERE date(fecha) = '%2'").arg(parsed.mid(9,2)).arg(QDate::fromString(parsed.mid(1, 8), tr("yyyyMMdd")).toString("yyyy-MM-dd")));

            /*if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) < ui->dateTimeEdit->date()) continue;
            if(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")) > ui->dateTimeEdit->date()){
                seguir = false;
                continue;
            };*/
            qDebug() << query->lastQuery() << query->lastError();
            while(query->next()){
                qDebug() << query->record().field("minutes").value();
                if(query->record().field("minutes").value().toInt() < 120){
                    query->exec(QString("UPDATE estadotiempos SET mil500 = %1 WHERE id = %2")
                                .arg(parsed.mid(21,7).toInt())
                                .arg(query->record().field("id").value().toInt()));
                    qDebug() << query->lastQuery() << query->lastError();
                };

            };

        };
    }else{
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo de informacion, compruebe que no lo este usando otro programa en este momento"), QMessageBox::Ok);
    };
    sets.endGroup();

    delete query;
    delete insert;
}

void MainWindow::loadSQLiteData(){
    int milisecs, hour, secs, min;
    QDateTime span;

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "lite");
    db2.setDatabaseName("localbase.dat");
    db2.open();
    QSqlQuery *lite = new QSqlQuery(db2);
    QSqlQuery *query = new QSqlQuery();
    lite->exec("SELECT * FROM aspectarium");
    while(lite->next()){
        QDateTime span;
        //qDebug() << "date: " << QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(lite->record().field("fecha").value().toInt());
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));

        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        qDebug() << "time: " << time;
        qDebug() << lite->record().field("fecha").value().toInt();
        qDebug() << lite->record().field("hora").value();
        qDebug() << span;
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("planeta1").value().toInt())
                    .arg(lite->record().field("planeta2").value().toInt())
                    .arg(lite->record().field("conjuncion").value().toInt())
                    .arg(lite->record().field("totaldif").value().toInt())
                    .arg(lite->record().field("mindif").value().toInt())
                    .arg(lite->record().field("segdif").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    lite->exec("SELECT * FROM casas");
    while(lite->next()){
        //qDebug() << lite->record();
        //qDebug() << "date: " << QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(lite->record().field("fecha").value().toInt());
        //span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(lite->record().field("fecha").value().toInt()));
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        //span.setTime();
        query->exec(QString("INSERT INTO casas (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("codigocasa").value().toInt())
                    .arg(lite->record().field("codigotipo").value().toString())
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    lite->exec("SELECT * FROM cuadrantes");
    while(lite->next()){
        //qDebug() << lite->record();
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO cuadrantes (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("codigo").value().toString())
                    .arg(lite->record().field("esteoeste").value().toString())
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS") */
    lite->exec("SELECT * FROM estadotiempos");
    while(lite->next()){
        //qDebug() << lite->record();
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO estadotiempos (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500, observaciones, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, '%8', '%9')")
                    .arg(lite->record().field("fecha").value().toString())
                    .arg(lite->record().field("maxima").value().toDouble())
                    .arg(lite->record().field("minima").value().toDouble())
                    .arg(lite->record().field("vientovel").value().toDouble())
                    .arg(lite->record().field("direccviento").value().toDouble())
                    .arg(lite->record().field("precipitacio").value().toDouble())
                    .arg(lite->record().field("mil500").value().toInt())
                    .arg(lite->record().field("observacione").value().toString())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    lite->exec("SELECT * FROM posiciones");
    while(lite->next()){
        //qDebug() << lite->record();
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("signo").value().toInt())
                    .arg(lite->record().field("Glon").value().toInt())
                    .arg(lite->record().field("Mlon").value().toInt())
                    .arg(lite->record().field("Slon").value().toInt())
                    .arg(lite->record().field("Glat").value().toInt())
                    .arg(lite->record().field("Mlat").value().toInt())
                    .arg(lite->record().field("Slat").value().toInt())
                    .arg(lite->record().field("Gvel").value().toInt())
                    .arg(lite->record().field("Mvel").value().toInt())
                    .arg(lite->record().field("Svel").value().toInt())
                    .arg(lite->record().field("distancia").value().toDouble())
                    .arg(lite->record().field("casa").value().toString())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS")*/
    lite->exec("SELECT * FROM signos");
    while(lite->next()){
        //qDebug() << lite->record();
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO signos (fecha, signo, columna, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("signo").value().toString())
                    .arg(lite->record().field("columna").value().toString())
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();

    };

    delete lite;
    delete query;
}

void MainWindow::loadRDBData()
{
    QSettings sets("config.ini");
    QProgressDialog dialog;
    dialog.setWindowModality(Qt::ApplicationModal);
    dialog.setWindowTitle("Importancion de datos");
    dialog.setLabelText("Iniciando Importacion");
    dialog.setMinimumDuration(100);

    sets.beginGroup("program");
    /*sets.setValue("RBDfile", ui->archivoRBDLineEdit->text());
    sets.setValue("SFDfile", ui->archivoSFDLineEdit->text());
    sets.setValue("SFfile", ui->starFisherExeLineEdit->text());*/

    QFile file(sets.value("SFDfile", "87750SFC.SFD").toString());

    QSqlQuery query;
    quint64 readedbytes = 0;
    query.exec("START TRANSACTION");
    if(file.open(QIODevice::ReadOnly)){
        dialog.setLabelText("Importando datos de archivo SFD...");
        dialog.setMaximum(file.size());
        dialog.setValue(readedbytes);
        while(!(file.atEnd() || dialog.wasCanceled())){
            //qDebug() << "wepa";
            QString readed = QString(file.read(233));
            readedbytes += 233;
            //qDebug() << readed;
            if(readed.count("M ", Qt::CaseSensitive) == 20) continue; //no fue tomado

            QStringList parsed;
            QDateTime date;
            while(readed.length() > 11){
                parsed << readed.left(11);
                readed.remove(0,11);
            };

            date.setDate(QDate::fromString(parsed.at(0).mid(1,8), "yyyyMMdd"));
            date.setTime(QTime::fromString(parsed.at(0).mid(9, 2) + ":00:00", "HH:mm:ss"));

            //qDebug() << parsed.at(0) << " - " << parsed.at(0).mid(9, 2) + ":00:00";

            double precipitaciones = parsed.at(16).toDouble();
            /*query.exec(QString("INSERT INTO tiempos (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500) VALUES "
                               "('%1', %2, %3, %4, %5, %6, %7)")
                       .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                       .arg(parsed.at(1).toDouble())
                       .arg(parsed.at(2).toDouble())
                       .arg(parsed.at(6).toInt() * 1.852)
                       .arg(parsed.at(7).toInt())
                       .arg((precipitaciones > 990)? precipitaciones = (precipitaciones - 990) / 10 : precipitaciones)
                       .arg(0));*/
            query.exec(QString("INSERT OR IGNORE INTO tiempos (fecha, tempmin, tempmax, alturanubes, visibilidad, cantidadnubes, velocidadviento, direccionviento, temperatura, puntorocio, tiempopresente, tiempopasado3, "
                               "tiempopasado6, presion, tendenciabarometrica, valortbarometrica, lluvia, nubesbajas, tiponb, tiponm, tipona, mil500) VALUES"
                               " ('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, %15, %16, %17, %18, %19, %20, %21, %22)")
                       .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                       .arg(parsed.at(1).toDouble())
                       .arg(parsed.at(2).toDouble())
                       .arg(parsed.at(3).toDouble())
                       .arg(parsed.at(4).toDouble())
                       .arg(parsed.at(5).toDouble())
                       .arg(parsed.at(6).toInt() * 1.852)
                       .arg(parsed.at(7).toInt())
                       .arg(parsed.at(8).toDouble())
                       .arg(parsed.at(9).toDouble())
                       .arg(parsed.at(10).toDouble())
                       .arg(parsed.at(11).toDouble())
                       .arg(parsed.at(12).toDouble())
                       .arg(parsed.at(13).toDouble())
                       .arg(parsed.at(14).toDouble())
                       .arg(parsed.at(15).toDouble())
                       .arg((precipitaciones > 990)? precipitaciones = (precipitaciones - 990) / 10 : precipitaciones)
                       .arg(parsed.at(17).toDouble())
                       .arg(parsed.at(18).toDouble())
                       .arg(parsed.at(19).toDouble())
                       .arg(parsed.at(20).toDouble())
                       .arg(0));
            //qDebug() << query.lastQuery() << query.lastError();
            dialog.setValue(readedbytes);
            if(dialog.wasCanceled()) break;
        };
    }else{
        dialog.setLabelText("Error al importar archivo SFD");
    };
    file.close();
    //file.setFileName("87750RAO.RBD");
    file.setFileName(sets.value("RBDfile", "87750RAO.RBD").toString());

    if(file.open(QIODevice::ReadOnly)){
        readedbytes = 0;
        dialog.setLabelText("Importando datos de archivo RBD...");
        dialog.setMaximum(file.size());
        dialog.setValue(readedbytes);
        while(!(file.atEnd() || dialog.wasCanceled())){
            //qDebug() << "wepa";
            QString readed = QString(file.read(33));
            readedbytes += 33;
            dialog.setValue(readedbytes);
            //qDebug() << readed;
            if(readed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado
            query.exec(QString("UPDATE tiempos SET mil500 = %1 WHERE DATE(fecha) = '%2'")
                       .arg(readed.mid(21,7).toInt())
                       .arg(QDate::fromString(readed.mid(1, 8), QString("yyyyMMdd")).toString("yyyy-MM-dd")));
            //qDebug() << query.lastQuery() << query.lastError();
            dialog.setValue(readedbytes);            
        };
    }else{
        dialog.setLabelText("Error al importar archivo RBD");
    };

    query.exec("COMMIT");
    sets.endGroup();
}

void MainWindow::weatherToNOAA()
{
    weatherToNoaaDialog *form = new weatherToNoaaDialog();
    form->setWindowModality(Qt::ApplicationModal);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
}

void MainWindow::refreshFromRBD()
{
    RBDtoWeatherDialog *form = new RBDtoWeatherDialog();
    form->setWindowModality(Qt::ApplicationModal);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
}

void MainWindow::loadTPSData(){
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QODBC", "clarion");
    db2.setDatabaseName("Meteorito");
    qDebug() << db2.open();
    qDebug() << db2.tables();
    QSqlQuery *tps = new QSqlQuery(db2);
    QSqlQuery *query = new QSqlQuery();

    tps->exec("SELECT * FROM " + db2.tables().at(0));
    tps->next();
    for(int i = 0; i < 20; ++i){
        qDebug() << tps->record().fieldName(i) << tps->record().field(i).value();
    };

    tps->exec("SELECT * FROM " + db2.tables().at(1));
    tps->next();
    for(int i = 0; i < 20; ++i){
        qDebug() << tps->record().fieldName(i);
    };
    //return;

    int milisecs, hour, secs, min;
    QDateTime span;
    /*tps->exec("SELECT * FROM ASPECTARIUM");
    query->exec("DELETE FROM aspectariums WHERE 1=1");
    while(tps->next()){
        //qDebug() << tps->record();
        QDateTime span;
        //qDebug() << "date: " << QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt());
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;

        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        qDebug() << "time: " << time;
        qDebug() << tps->record().field("fecha").value().toInt();
        qDebug() << tps->record().field("hora").value();
        qDebug() << span;
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("plan1").value().toInt())
                    .arg(tps->record().field("plan2").value().toInt())
                    .arg(tps->record().field("conjuncion").value().toInt())
                    .arg(tps->record().field("totaldif").value().toInt())
                    .arg(tps->record().field("mindif").value().toInt())
                    .arg(tps->record().field("segdif").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
        //.arg(tps->record().field("").value())

    };

    tps->exec("SELECT * FROM ASPECTARIUM2");
    while(tps->next()){
        //qDebug() << tps->record();
        QDateTime span;
        //qDebug() << "date: " << QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt());
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;

        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        qDebug() << "time: " << time;
        qDebug() << tps->record().field("fecha").value().toInt();
        qDebug() << tps->record().field("hora").value();
        qDebug() << span;
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("plan1").value().toInt())
                    .arg(tps->record().field("plan2").value().toInt())
                    .arg(tps->record().field("conjuncion").value().toInt())
                    .arg(tps->record().field("totaldif").value().toInt())
                    .arg(tps->record().field("mindif").value().toInt())
                    .arg(tps->record().field("segdif").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
        //.arg(tps->record().field("").value())

    };*/

    /*tps->exec("SELECT * FROM casas");
    while(tps->next()){
        //qDebug() << tps->record();
        //qDebug() << "date: " << QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt());
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO casas (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("codigocasa").value().toInt())
                    .arg(tps->record().field("codigotipo").value().toString())
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    tps->exec("SELECT * FROM casas2");
    while(tps->next()){
        //qDebug() << tps->record();
        //qDebug() << "date: " << QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt());
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO casas (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("codigocasa").value().toInt())
                    .arg(tps->record().field("codigotipo").value().toString())
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };*/

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS") */
    /*tps->exec("SELECT * FROM cuadra");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO cuadrantes (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("codigo").value().toString())
                    .arg(tps->record().field("esteoeste").value().toString())
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    tps->exec("SELECT * FROM cuadra2");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO cuadrantes (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("codigo").value().toString())
                    .arg(tps->record().field("esteoeste").value().toString())
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };*/

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS") */
    /*tps->exec("SELECT * FROM estado");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO estadotiempos (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500, observaciones, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, '%8', '%9')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("maxima").value().toDouble())
                    .arg(tps->record().field("minima").value().toDouble())
                    .arg(tps->record().field("vientovel").value().toDouble())
                    .arg(tps->record().field("direccviento").value().toDouble())
                    .arg(tps->record().field("precipitacio").value().toDouble())
                    .arg(tps->record().field("mil500").value().toInt())
                    .arg(tps->record().field("observacione").value().toString())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    tps->exec("SELECT * FROM estado2");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO estadotiempos (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500, observaciones, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, '%8', '%9')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("maxima").value().toString())
                    .arg(tps->record().field("minima").value().toString())
                    .arg(tps->record().field("vientovel").value().toString())
                    .arg(tps->record().field("direccviento").value().toString())
                    .arg(tps->record().field("precipitacio").value().toString())
                    .arg(tps->record().field("mil500").value().toInt())
                    .arg(tps->record().field("observacione").value().toString())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    return;*/

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS") */
    /*tps->exec("SELECT * FROM posicio");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("signo").value().toInt())
                    .arg(tps->record().field("glon").value().toInt())
                    .arg(tps->record().field("mlon").value().toInt())
                    .arg(tps->record().field("slon").value().toInt())
                    .arg(tps->record().field("glat").value().toInt())
                    .arg(tps->record().field("mlat").value().toInt())
                    .arg(tps->record().field("slat").value().toInt())
                    .arg(tps->record().field("gvel").value().toInt())
                    .arg(tps->record().field("mvel").value().toInt())
                    .arg(tps->record().field("svel").value().toInt())
                    .arg(tps->record().field("distancia").value().toDouble())
                    .arg(tps->record().field("casa").value().toString())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };

    tps->exec("SELECT * FROM posicio2");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("signo").value().toInt())
                    .arg(tps->record().field("glon").value().toInt())
                    .arg(tps->record().field("mlon").value().toInt())
                    .arg(tps->record().field("slon").value().toInt())
                    .arg(tps->record().field("glat").value().toInt())
                    .arg(tps->record().field("mlat").value().toInt())
                    .arg(tps->record().field("slat").value().toInt())
                    .arg(tps->record().field("gvel").value().toInt())
                    .arg(tps->record().field("mvel").value().toInt())
                    .arg(tps->record().field("svel").value().toInt())
                    .arg(tps->record().field("distancia").value().toDouble())
                    .arg(tps->record().field("casa").value().toString())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    };*/

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS")*/
   /* tps->exec("SELECT * FROM signos");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO signos (fecha, signo, columna, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("signo").value().toString())
                    .arg(tps->record().field("columna").value().toString())
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();

    };

    tps->exec("SELECT * FROM signos2");
    while(tps->next()){
        //qDebug() << tps->record();
        span.setDate(QDate::fromString("28-12-1800", "dd-MM-yyyy").addDays(tps->record().field("fecha").value().toInt()));
        milisecs = tps->record().field("hora").value().toInt() / 100;
        min = milisecs / 60;
        hour = min / 60;
        secs = milisecs - min * 60;
        min -= hour * 60;
        QTime time;
        time.setHMS(hour, min, secs);
        span.setTime(time);
        query->exec(QString("INSERT INTO signos (fecha, signo, columna, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(tps->record().field("signo").value().toString())
                    .arg(tps->record().field("columna").value().toString())
                    .arg(tps->record().field("planeta").value().toInt())
                    .arg(tps->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();

    };*/

    //.arg(tps->record().field("").value())
    delete query;
}

void MainWindow::showForm(QWidget *form, bool modal){
    /*form->setAttribute(Qt::WA_DeleteOnClose);
    QMdiSubWindow *f = ui->mdiArea->addSubWindow(form);
    connect(form, SIGNAL(destroyed()), f, SLOT(close()));
    f->setAttribute(Qt::WA_DeleteOnClose);
    if(modal) f->setWindowModality(Qt::ApplicationModal);
    f->show();*/
    form->setAttribute(Qt::WA_DeleteOnClose);
    if(modal){
        form->setWindowModality(Qt::ApplicationModal);
        form->show();
    }else{
        QMdiSubWindow *f = ui->mdiArea->addSubWindow(form);
        connect(form, SIGNAL(destroyed()), f, SLOT(close()));
        f->setAttribute(Qt::WA_DeleteOnClose);
        f->show();
    };
}

void MainWindow::cargaDeDia(){
    grabDataWidget *form = new grabDataWidget();
    showForm(form);
}

void MainWindow::cargaDeSizigia(){
    grabDataWidget *form = new grabDataWidget(true);
    showForm(form);
}

void MainWindow::modifyData(){
    dataModificationWidget *form = new dataModificationWidget();
    showForm(form);
}

void MainWindow::showOptions(){
    optionsWidget *form = new optionsWidget();
    showForm(form);
}

void MainWindow::browseTables(){
    browseTableWidget *form = new browseTableWidget();
    showForm(form);
}

void MainWindow::browseMonth(){
    monthViewWidget *form = new monthViewWidget();
    showForm(form);
}

//void MainWindow::processData(){
    /*processDataWidget *form = new processDataWidget();
    showForm(form);*/
  /*  dataProcessorWidget *form = new dataProcessorWidget();
    showForm(form);
}*/

void MainWindow::batchProcessor(){
    //batchAstrologicGrabData *form = new batchAstrologicGrabData();
    BatchProcessWidget *form = new BatchProcessWidget();
    showForm(form);
}

void MainWindow::processByWeather(){
    processByWeatherWidget *form = new processByWeatherWidget();
    showForm(form);
}

void MainWindow::processByAspects(){
    processByAspectWidget *form = new processByAspectWidget();
    showForm(form);
}

void MainWindow::processByCycles(){
    processByCyclesWidget *form = new processByCyclesWidget();
    showForm(form);
}

void MainWindow::processByDignity(){
    processByDignityWidget *form = new processByDignityWidget();
    showForm(form);
}

void MainWindow::processByMonthRain(){
    processByMonths *form = new processByMonths();
    showForm(form);
}

void MainWindow::showDays(){
    weatherDisplayWidget *form = new weatherDisplayWidget(&date);
    showForm(form);
}

void MainWindow::showSizigias(){
    sizigiaExcelReportWidget *form = new sizigiaExcelReportWidget();
    showForm(form);
}

void MainWindow::showExcel(){
    //form->setAttribute(Qt::WA_DeleteOnClose);
    //QMdiSubWindow *f = ui->mdiArea->addSubWindow(excel);
    //connect(excel, SIGNAL(), f, SLOT(close()));
    //connect(f, SIGNAL(destroyed(QObject*)))
    //excel->setParent(0);
    //f->setAttribute(Qt::WA_DeleteOnClose, false);
    //if(modal) f->setWindowModality(Qt::ApplicationModal);
    //f->show();
    excel->show();
}

void MainWindow::fileProcessor(){
    fileLoadWidget *form = new fileLoadWidget();
    showForm(form);
}

void MainWindow::recalcMothlyValues(){
    monthCalcDialog *form = new monthCalcDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
    /*QString col;
    QStringList columnas, columnasesp;
    QSqlQuery query, insert;
    QProgressDialog dialog;

    dialog.setWindowTitle("Calculando Mensualidades: ");
    //dialog.setMaximum(9600);
    dialog.setValue(0);
    int count = 0;

    query.exec("select count(q) as q FROM (select distinct substr(fecha,0, 8) as q from estadotiempos_diarios)");
    query.next();
    dialog.setMaximum(query.record().field("q").value().toInt());

    /*columnas << "temp_media" << "temp_max" << "temp_min" << "presion" << "visibilidad";
    columnas << "viento_vel" << "viento_rafaga" << "punto_rocio" << "precipitaciones"  << "nieve";*

    columnas << "temp_media" << "presion" << "visibilidad" << "viento_vel" << "viento_rafaga" << "punto_rocio";
    columnasesp << "temp_max" << "temp_min" << "precipitaciones" << "nieve";

    query.exec("select distinct substr(fecha,0, 8) as q from estadotiempos_diarios");
    qDebug() << query.lastQuery() << query.lastError();
    insert.exec("BEGIN TRANSACTION");
    while(query.next() && !dialog.wasCanceled()){
        insert.exec(QString("SELECT fecha FROM estadotiempos_mensuales WHERE fecha = '%1-01'").arg(query.record().field("q").value().toString()));
        //qDebug() << insert.lastQuery() << insert.lastError();
        if(!insert.next()){
            insert.exec(QString("INSERT INTO estadotiempos_mensuales (fecha) VALUES ('%1-01')").arg(query.record().field("q").value().toString()));
            //qDebug() << insert.lastQuery() << insert.lastError();
        };
        dialog.setLabelText(QString("calculando dia: %1-01").arg(query.record().field("q").value().toString()));
        foreach(col, columnas){
            if(col == "presion"){
                insert.exec(QString("select avg(%1) as q from estadotiempos_diarios where substr(fecha, 0, 8) = '%2' AND %3 < 9999.9").arg(col).arg(query.record().field("q").value().toString()).arg(col));
            }else{
                insert.exec(QString("select avg(%1) as q from estadotiempos_diarios where substr(fecha, 0, 8) = '%2' AND %3 < 999.9").arg(col).arg(query.record().field("q").value().toString()).arg(col));
            };

            //qDebug() << insert.lastQuery() << insert.lastError();
            insert.next();
            //qDebug() << query.record().field("q").value().isNull();
            if(!insert.record().field("q").value().isNull()){
                insert.exec(QString("UPDATE estadotiempos_mensuales SET %1 = %2 WHERE fecha = '%3-01'").arg(col).arg(insert.record().field("q").value().toString()).arg(query.record().field("q").value().toString()));
                //qDebug() << insert.lastQuery() << insert.lastError();
            }else{
                insert.exec(QString("UPDATE estadotiempos_mensuales SET %1 = %2 WHERE fecha = '%3-01'").arg(col).arg("9999.9").arg(query.record().field("q").value().toString()));
            };
            //qDebug() << insert.lastQuery() << insert.lastError();
        };

        foreach(col, columnasesp){
            //"temp_max" << "temp_min" << "precipitaciones" << "nieve";
            if(col == "temp_max") insert.exec(QString("select max(%1) as q from estadotiempos_diarios where substr(fecha, 0, 8) = '%2' AND %3 < 999.9").arg(col).arg(query.record().field("q").value().toString()).arg(col));
            if(col == "temp_min") insert.exec(QString("select min(%1) as q from estadotiempos_diarios where substr(fecha, 0, 8) = '%2' AND %3 < 999.9").arg(col).arg(query.record().field("q").value().toString()).arg(col));
            if(col == "precipitaciones") insert.exec(QString("select sum(%1) as q from estadotiempos_diarios where substr(fecha, 0, 8) = '%2' AND %3 < 999.9").arg(col).arg(query.record().field("q").value().toString()).arg(col));
            if(col == "nieve") insert.exec(QString("select sum(%1) as q from estadotiempos_diarios where substr(fecha, 0, 8) = '%2' AND %3 < 999.9").arg(col).arg(query.record().field("q").value().toString()).arg(col));

            //qDebug() << insert.lastQuery() << insert.lastError();
            insert.next();
            //qDebug() << query.record().field("q").value().isNull();            
            if(!insert.record().field("q").value().isNull()){
                insert.exec(QString("UPDATE estadotiempos_mensuales SET %1 = %2 WHERE fecha = '%3-01'").arg(col).arg(insert.record().field("q").value().toString()).arg(query.record().field("q").value().toString()));
                //qDebug() << insert.lastQuery() << insert.lastError();
            }else{
                if(col == "precipitaciones"){
                    insert.exec(QString("SELECT precipitaciones FROM  estadotiempos_mensuales WHERE fecha = '%1-01'").arg(query.record().field("q").value().toString()));
                    if(insert.next()){
                        if(insert.record().field("precipitaciones").value().toDouble() < 9000) continue;
                    }
                };
                if(col == "temp_min"){
                    insert.exec(QString("SELECT temp_min FROM estadotiempos_mensuales WHERE fecha = '%1-01'").arg(query.record().field("q").value().toString()));
                    if(insert.next()){
                        if(insert.record().field("temp_min").value().toDouble() < 9000) continue;
                    }
                };
                if(col == "temp_max"){
                    insert.exec(QString("SELECT temp_max FROM estadotiempos_mensuales WHERE fecha = '%1-01'").arg(query.record().field("q").value().toString()));
                    if(insert.next()){
                        if(insert.record().field("temp_max").value().toDouble() < 9000) continue;
                    }
                };
                insert.exec(QString("UPDATE estadotiempos_mensuales SET %1 = %2 WHERE fecha = '%3-01'").arg(col).arg("9999.9").arg(query.record().field("q").value().toString()));
            };
            //qDebug() << insert.lastQuery() << insert.lastError();
        };
        dialog.setValue(++count);
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
    };
    insert.exec("END TRANSACTION");*/
}

void MainWindow::calcPrimordialPoints(){
    calcPtosPrimordialesDialog *form = new calcPtosPrimordialesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->exec();

    /*QDateTime fecha, fin;

    sweph swe;// = new sweph();
    swe.swe_set_ephe_path(QDir::currentPath().replace("/", "\\") + "\\sweph\\ephe");

    fecha.setDate(QDate(1740, 1, 1));
    fecha.setTime(QTime(0, 0, 0));
    fin.setDate(QDate(2100, 1, 1));
    fin.setTime(QTime(0, 0, 0));

    *QDateTime toUse;
    toUse.setDate(QDate(1729, 4, 19));
    toUse.setTime(QTime(22, 0, 0));
    double julday = swe.swe_julday(toUse.date().day(), toUse.date().month(), toUse.date().year(), toUse.time().hour());
    qDebug() << "julday: " << julday;
    double* res = swe.swe_calc_ut(julday, 0);
    for(int i = 0; i < 6; ++i) qDebug() << i << " : " << res[i];


    return;*
    QSqlQuery query;
    QProgressDialog dialog;
    QTime current;
    int count = 0;
    int total = 0;

    dialog.setWindowTitle("Calculando Ptos. Primordiales: ");
    dialog.setMaximum(9600);
    dialog.setValue(0);

    query.exec("BEGIN TRANSACTION");
    dialog.show();
    current.start();
    //double* result;// = new double[6];
    double result[6];
    while(fecha < fin){
        QDateTime toUse;
        //toUse = fecha;
        qDebug() << fecha;
        toUse = fecha.addSecs(+3*3600);
        //qDebug() << "l";
        double julday = swe.swe_julday(toUse.date().day(), toUse.date().month(), toUse.date().year(), toUse.time().hour());
        qDebug() << "julday: " << julday;
        double* res = swe.swe_calc_ut(julday, 0);
        qDebug() << "l";
        for(int i = 0; i < 6; ++i) /*qDebug() << i << " : " << result[i];* result[i] = res[i];
        qDebug() << "l";
        double longitud = result[0];
        qDebug() << "l";
        int sign = (((int)longitud / 30) % 12) + 1;
        qDebug() << sign;
        if(sign == 10 or sign == 4){
            query.exec(QString("INSERT INTO puntosprimordiales (fecha, degress, planeta, signo) VALUES ('%1', %2, %3, %4)").arg(fecha.toString("yyyy-MM-dd hh:mm:ss")).arg(longitud).arg(0).arg(sign));
        };

        res = swe.swe_calc_ut(julday, 1);
        qDebug() << "l";
        for(int i = 0; i < 6; ++i)/* qDebug() << i << " : " << result[i];* result[i] = res[i];
        qDebug() << "l";
        longitud = result[0];
        qDebug() << "l";
        sign = (((int)longitud / 30) % 12) + 1;
        qDebug() << sign;
        if(sign == 10 or sign == 7){
            query.exec(QString("INSERT INTO puntosprimordiales (fecha, degress, planeta, signo) VALUES ('%1', %2, %3, %4)").arg(fecha.toString("yyyy-MM-dd hh:mm:ss")).arg(longitud).arg(1).arg(sign));
        };
        qDebug() << "l";
        //fecha = toUse.addSecs(-2400);
        fecha = fecha.addSecs(3600);
        qDebug() << "l";
        count++;
        qDebug() << "l";
        dialog.setValue((total++)/365);
        qDebug() << "l";
        if(current.elapsed() > 1000){
            dialog.setLabelText(QString("%1 %2 calc/seg. ETA: %3 seg.").arg(fecha.toString("yyyy-MM-dd hh:mm:ss")).arg(count).arg((9600*365 - dialog.value()) / count));
            count = 0;
            current.restart();
        };
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
        longitud = 0;
        //delete result;
    };
    query.exec("END TRANSACTION");*/
}

MainWindow* MainWindow::instance(){
    if(mahself == 0){
        mahself = new MainWindow();
    };
    return mahself;
}
