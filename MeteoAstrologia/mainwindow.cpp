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
#include "seteoestacioneswidget.h"
#include "automaticdownloaderwidget.h"

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
    connect(ui->actionEstaciones_a_trabajar, SIGNAL(triggered()), this, SLOT(onSeteoEstaciones()));

    connect(ui->actionCalcular_Pto_Primordiales, SIGNAL(triggered()), this, SLOT(calcPrimordialPoints()));
    connectToDatabase();

    ui->actionProceso_por_Posicion_Astral->setVisible(false);
    ui->actionCarga_en_Batch->setEnabled(false);
    ui->actionCarga_de_Dia->setVisible(false);
    ui->actionCarga_de_Sizigia->setVisible(false);
    ui->actionCarga_en_Batch->setVisible(false);

    ui->actionCarga_de_Archivos->setVisible(false);

    date = QDateTime::currentDateTime();
}

MainWindow::~MainWindow()
{
    excel->close();
    delete excel;
    delete ui;
}

void MainWindow::connectToDatabase(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("localbase.dat");
    qDebug() << db.open();
}

void MainWindow::workingDate(){
    workingDateDialog *form = new workingDateDialog();
    connect(form, SIGNAL(dateSubmited(QDateTime)), this, SLOT(setWorkingDate(QDateTime)));
    showForm(form, true);
}

void MainWindow::refreshWeather(){
    QSettings sets("config.ini");
    sets.beginGroup("program");
    QString filename = sets.value("SFDfile", "87750SFC.SFD").toString();
    QFile file(filename);
    QSqlQuery *query = new QSqlQuery();
    QSqlQuery *insert = new QSqlQuery();
    if(file.open(QIODevice::ReadOnly)){;
        while(!file.atEnd()){
            QString readed = QString(file.read(233));
            QString toParse = readed;
            if(readed.count("M ", Qt::CaseSensitive) == 20) continue; //no fue tomado

            QStringList parsed;
            while(toParse.length() > 11){
                parsed << toParse.left(11);
                toParse.remove(0,11);
            }

            query->exec(QString("SELECT *, date(fecha) as t, time(fecha) as h, timediff(time(fecha), '%1:00:00') as dif, hour(timediff(time(fecha), '%1:00:00')) * 60 + minute(timediff(time(fecha), '%1:00:00')) as minutes FROM estadotiempos_diarios WHERE date(fecha) = '%2'").arg(parsed.at(0).mid(9,2)).arg(QDate::fromString(readed.mid(1, 8), tr("yyyyMMdd")).toString("yyyy-MM-dd")));  // Modificacion de diego

            qDebug() << query->lastQuery() << query->lastError();
            while(query->next()){
                qDebug() << query->record().field("minutes").value();
                    double precipitaciones = parsed.at(16).toDouble();
                    if(precipitaciones >= 990){ precipitaciones = (precipitaciones - 990) / 10; }
                    if(parsed.at(1).toDouble() == -99) continue;
                    if(parsed.at(2).toDouble() == -99) continue;

                    // Modificacion de diego
                    insert->exec(QString("UPDATE estadotiempos_diarios SET maxima = %1, minima = %2, vientovel = %3, direccionviento = %4,"
                                        "precipitacion = %5 WHERE id = %6 AND maxima = 0 AND minima = 0")
                                .arg(parsed.at(1).toDouble() == -99 ? 0 : parsed.at(1).toDouble())
                                .arg(parsed.at(2).toDouble() == -99 ? 0 : parsed.at(2).toDouble())
                                .arg(parsed.at(6).toInt() * 1.852)
                                .arg(parsed.at(7).toInt())
                                .arg(precipitaciones == -99 ? 0 : precipitaciones)
                                .arg(query->record().field("id").value().toInt()));
                    qDebug() << insert->lastQuery() << insert->lastError();
            }
        }
    }else{
        qDebug() << "i cannot open the file";
    }

    filename = sets.value("RBDfile", "87750RAO.RBD").toString();
    file.close();
    file.setFileName(filename);

    if(file.open(QIODevice::ReadOnly)){
        while(!file.atEnd()){
            QString parsed = QString(file.read(33));
            qDebug() << parsed;
            if(parsed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado

            query->exec(QString("SELECT *, date(fecha) as t, time(fecha) as h, timediff(time(fecha), '%1:00:00') as dif, hour(timediff(time(fecha), '%1:00:00')) * 60 + minute(timediff(time(fecha), '%1:00:00')) as minutes FROM estadotiempos_diarios WHERE date(fecha) = '%2'").arg(parsed.mid(9,2)).arg(QDate::fromString(parsed.mid(1, 8), tr("yyyyMMdd")).toString("yyyy-MM-dd"))); // Modificacion de diego

            qDebug() << query->lastQuery() << query->lastError();
            while(query->next()){
                qDebug() << query->record().field("minutes").value();
                if(query->record().field("minutes").value().toInt() < 120){
                    query->exec(QString("UPDATE estadotiempos_diarios SET mil500 = %1 WHERE id = %2")
                                .arg(parsed.mid(21,7).toInt())
                                .arg(query->record().field("id").value().toInt())); // Modificacion de diego
                    qDebug() << query->lastQuery() << query->lastError();
                }
            }
        }
    }else{
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo de informacion, compruebe que no lo este usando otro programa en este momento"), QMessageBox::Ok);
    }
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
    }

    lite->exec("SELECT * FROM casas");
    while(lite->next()){
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO casas (fecha, codigocasa, codigotipo, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("codigocasa").value().toInt())
                    .arg(lite->record().field("codigotipo").value().toString())
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    }

    lite->exec("SELECT * FROM cuadrantes");
    while(lite->next()){
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO cuadrantes (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("codigo").value().toString())
                    .arg(lite->record().field("esteoeste").value().toString())
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    }

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS") */
    lite->exec("SELECT * FROM estadotiempos_diarios");  // Modificacion de diego
    while(lite->next()){
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO estadotiempos_diarios (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500, observaciones, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, '%8', '%9')")
                    .arg(lite->record().field("fecha").value().toString())
                    .arg(lite->record().field("maxima").value().toDouble())
                    .arg(lite->record().field("minima").value().toDouble())
                    .arg(lite->record().field("vientovel").value().toDouble())
                    .arg(lite->record().field("direccviento").value().toDouble())
                    .arg(lite->record().field("precipitacio").value().toDouble())
                    .arg(lite->record().field("mil500").value().toInt())
                    .arg(lite->record().field("observacione").value().toString())
                    .arg(lite->record().field("tipo").value().toString())); // Modificacion de diego
        qDebug() << query->lastQuery() << query->lastError();
    }

    lite->exec("SELECT * FROM posiciones");
    while(lite->next()){
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
    }

    /*("ASPECTARIUM", "CASAS", "CUADRA", "ESTADO", "MESES", "PLANETAS", "POSICIO", "SIGNOS")*/
    lite->exec("SELECT * FROM signos");
    while(lite->next()){
        span = QDateTime::fromString(lite->record().field("fecha").value().toString(), QString("ddd d. MMM hh:mm:ss yyyy"));
        query->exec(QString("INSERT INTO signos (fecha, signo, columna, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(span.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(lite->record().field("signo").value().toString())
                    .arg(lite->record().field("columna").value().toString())
                    .arg(lite->record().field("planeta").value().toInt())
                    .arg(lite->record().field("tipo").value().toString()));
        qDebug() << query->lastQuery() << query->lastError();
    }

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

    QFile file(sets.value("SFDfile", "87750SFC.SFD").toString());

    QSqlQuery query;
    quint64 readedbytes = 0;
    query.exec("START TRANSACTION");
    if(file.open(QIODevice::ReadOnly)){
        dialog.setLabelText("Importando datos de archivo SFD...");
        dialog.setMaximum(file.size());
        dialog.setValue(readedbytes);
        while(!(file.atEnd() || dialog.wasCanceled())){
            QString readed = QString(file.read(233));
            readedbytes += 233;
            if(readed.count("M ", Qt::CaseSensitive) == 20) continue; //no fue tomado

            QStringList parsed;
            QDateTime date;
            while(readed.length() > 11){
                parsed << readed.left(11);
                readed.remove(0,11);
            }

            date.setDate(QDate::fromString(parsed.at(0).mid(1,8), "yyyyMMdd"));
            date.setTime(QTime::fromString(parsed.at(0).mid(9, 2) + ":00:00", "HH:mm:ss"));

            double precipitaciones = parsed.at(16).toDouble();

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
            dialog.setValue(readedbytes);
            if(dialog.wasCanceled()) break;
        }
    }else{
        dialog.setLabelText("Error al importar archivo SFD");
    }
    file.close();
    file.setFileName(sets.value("RBDfile", "87750RAO.RBD").toString());

    if(file.open(QIODevice::ReadOnly)){
        readedbytes = 0;
        dialog.setLabelText("Importando datos de archivo RBD...");
        dialog.setMaximum(file.size());
        dialog.setValue(readedbytes);
        while(!(file.atEnd() || dialog.wasCanceled())){
            QString readed = QString(file.read(33));
            readedbytes += 33;
            dialog.setValue(readedbytes);
            if(readed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado
            query.exec(QString("UPDATE tiempos SET mil500 = %1 WHERE DATE(fecha) = '%2'")
                       .arg(readed.mid(21,7).toInt())
                       .arg(QDate::fromString(readed.mid(1, 8), QString("yyyyMMdd")).toString("yyyy-MM-dd")));
            dialog.setValue(readedbytes);            
        }
    }else{
        dialog.setLabelText("Error al importar archivo RBD");
    }

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
    }

    tps->exec("SELECT * FROM " + db2.tables().at(1));
    tps->next();
    for(int i = 0; i < 20; ++i){
        qDebug() << tps->record().fieldName(i);
    }
    delete query;
}

void MainWindow::showForm(QWidget *form, bool modal){
    form->setAttribute(Qt::WA_DeleteOnClose);
    if(modal){
        form->setWindowModality(Qt::ApplicationModal);
        form->show();
    }else{
        QMdiSubWindow *f = ui->mdiArea->addSubWindow(form);
        connect(form, SIGNAL(destroyed()), f, SLOT(close()));
        f->setAttribute(Qt::WA_DeleteOnClose);
        f->show();
    }
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


void MainWindow::batchProcessor(){
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
    excel->show();
}

void MainWindow::fileProcessor(){
    fileLoadWidget *form = new fileLoadWidget();
    showForm(form);
}

void MainWindow::onSeteoEstaciones()
{
    SeteoEstacionesWidget *form = new SeteoEstacionesWidget(this);
    showForm(form);
}

void MainWindow::recalcMothlyValues(){
    monthCalcDialog *form = new monthCalcDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
}

void MainWindow::calcPrimordialPoints(){
    calcPtosPrimordialesDialog *form = new calcPtosPrimordialesDialog();
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->exec();
}

MainWindow* MainWindow::instance(){
    if(mahself == 0){
        mahself = new MainWindow();
    }
    return mahself;
}

void MainWindow::on_actionActualizar_Datos_triggered()
{
    AutomaticDownloaderWidget *form =  new AutomaticDownloaderWidget(this);
    showForm(form);
}
