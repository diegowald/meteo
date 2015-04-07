#include "fileloadwidget.h"
#include "ui_fileloadwidget.h"
#include <QUrl>
#include "qcompressor.h"

fileLoadWidget::fileLoadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileLoadWidget)
{
    ui->setupUi(this);

    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addFiles()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(removeFiles()));

    connect(ui->calcButton, SIGNAL(clicked()), this, SLOT(processFiles()));
    downloader = NULL;
}

fileLoadWidget::~fileLoadWidget()
{
    delete ui;
}

void fileLoadWidget::addFiles(){
    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setWindowTitle("Seleccione los archivos a cargar");

    if(dialog.exec() != QDialog::Accepted) return;

    QStringList files = dialog.selectedFiles();
    for(int i = 0; i < files.count(); i++){
        filenames.append(files.at(i));
        //qDebug() << files.at(i);
        fileprogress.append(0);
    };

    refresh();
}

void fileLoadWidget::removeFiles(){
    QModelIndexList list = ui->tableWidget->selectionModel()->selectedRows(0);
    if(list.isEmpty()) return;

    QModelIndex data;
    foreach(data, list){
        filenames.removeAt(data.row());
        fileprogress.removeAt(data.row());
    };

    refresh();
}


void fileLoadWidget::processFiles(){
    ui->addButton->setEnabled(false);
    ui->delButton->setEnabled(false);
    ui->closeButton->setEnabled(false);
    int i = 0;

    if(ui->weatherDiaryRadioButton->isChecked()){
        QString filename;
        foreach(filename, filenames){
            processDiaryWeather(filename);
            fileprogress.replace(i++, 100);
            refresh();
        };
    };
    if(ui->ninoMonthlyRadioButton->isChecked()){
        QString filename;
        foreach(filename, filenames){
            processNinoMonthly(filename);
            fileprogress.replace(i++, 100);
            refresh();
        };
    };
    if(ui->sunspotDiaryRadioButton->isChecked()){
        QString filename;
        foreach(filename, filenames){
            processDiarySunspots(filename);
            fileprogress.replace(i++, 100);
            refresh();
            filenames.removeOne(filename);
        };
    };
    if(ui->sunspotMonthlyRadioButton->isChecked()){
        QString filename;
        foreach(filename, filenames){
            processMonthlySunspots(filename);
            fileprogress.replace(i++, 100);
            refresh();
        };
    };
}

void fileLoadWidget::refresh(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(filenames.count());
    QProgressBar *bar;
    for(int i = 0; i < filenames.count(); i++){
        bar = new QProgressBar();
        bar->setValue(fileprogress.at(i));
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(filenames.at(i)));
        ui->tableWidget->setCellWidget(i, 1, bar);
    };
}

bool fileLoadWidget::processDiaryWeather(QString filename){
    qDebug() << "processDiary Weather";

    QString file2 = filename + ".decompressed";

    QCompressor::gzipDecompress(filename, file2);

    QFile file(file2);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly)){
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd()){
            QString line(file.readLine());
            if(first){
                first = false;
            }else{
                QString querystring, selectstring;
                selectstring = "SELECT fecha FROM estadotiempos_diarios WHERE fecha = '%1-%2-%3'";
                selectstring = selectstring.arg(line.mid(14, 4));
                selectstring = selectstring.arg(line.mid(18, 2));
                selectstring = selectstring.arg(line.mid(20, 2));
                query.exec(selectstring);
                if(query.next()){
                    querystring = "UPDATE estadotiempos_diarios SET temp_media = %1, temp_max = %2, temp_min = %3, presion = %4, "
                                  "visibilidad = %5, viento_vel = %6, viento_rafaga = %7, punto_rocio = %8, precipitaciones = %9, nieve = %10, flags = %11 "
                                  " WHERE fecha = '%12-%13-%14'";
                }else{
                    querystring = "INSERT INTO estadotiempos_diarios (temp_media, temp_max, temp_min, presion, "
                                  "visibilidad, viento_vel, viento_rafaga, punto_rocio, precipitaciones, nieve, flags, fecha) VALUES "
                                  "(%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, '%12-%13-%14')";
                };
                //temp media
                if(line.mid(24,6) == "9999.9"){
                    querystring = querystring.arg(line.mid(24,6));
                }else{
                    double celc = line.mid(24, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                };
                //temp maxima
                if(line.mid(102,6) == "9999.9"){
                    querystring = querystring.arg(line.mid(102, 6));
                }else{
                    double celc = line.mid(102, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                };

                //temp minima
                if(line.mid(110,6) == "9999.9"){
                    querystring = querystring.arg(line.mid(110, 6));
                }else{
                    double celc = line.mid(110, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                };

                //presion
                querystring = querystring.arg( line.mid(46, 6) == "9999.9" ? line.mid(57, 6) : line.mid(46, 6) );

                //visibilidad
                if(line.mid(68, 5) == "999.9"){
                    querystring = querystring.arg(line.mid(68, 5));
                }else{
                    double miles = line.mid(68, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(miles * 1.609));
                };

                //viento velocidad
                if(line.mid(78, 5) == "999.9"){
                    querystring = querystring.arg(line.mid(78, 5));
                }else{
                    double knot = line.mid(78, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(knot * 1.852));
                };

                //viento rafaga
                if(line.mid(88, 5) == "999.9"){
                    querystring = querystring.arg(line.mid(88, 5));
                }else{
                    double knot = line.mid(88, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(knot * 1.852));
                };

                //punto rocio
                if(line.mid(35, 6) == "9999.9"){
                    querystring = querystring.arg(line.mid(35, 6));
                }else{
                    double celc = line.mid(35, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                };

                //precipitaciones
                if(line.mid(118, 5) != "99.99"){
                    double pulg = line.mid(118, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(pulg * 25.4));
                }else{
                    querystring = querystring.arg("999.9");
                }

                // nieve
                if(line.mid(125, 5) == "999.9"){
                    querystring = querystring.arg(line.mid(125, 5));
                }else{
                    double pulg = line.mid(125, 5).toDouble();
                    querystring = querystring.arg("999.9");
                };

                //flags
                querystring = querystring.arg(line.mid(132, 6));

                //fecha
                querystring = querystring.arg(line.mid(14, 4));
                querystring = querystring.arg(line.mid(18, 2));
                querystring = querystring.arg(line.mid(20, 2));
                //}else{
                /* querystring = "INSERT INTO estadotiempos_diarios (fecha, temp_media, temp_max, temp_min, presion, "
                            "visibilidad, viento_vel, viento_rafaga, punto_rocio, precipitaciones, nieve, flags) VALUES "
                            "('%1-%2-%3', %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14)";*/
                /*querystring = querystring.arg(line.mid(14, 4));
                    querystring = querystring.arg(line.mid(18, 2));
                    querystring = querystring.arg(line.mid(20, 2));
                    querystring = querystring.arg(line.mid(24,6));
                    querystring = querystring.arg(line.mid(102, 6));
                    querystring = querystring.arg(line.mid(110, 6));
                    querystring = querystring.arg( line.mid(46, 6) == "9999.9" ? line.mid(57, 6) : line.mid(46, 6) );
                    querystring = querystring.arg(line.mid(68, 5));
                    querystring = querystring.arg(line.mid(78, 5));
                    querystring = querystring.arg(line.mid(88, 5));
                    querystring = querystring.arg(line.mid(35, 6));
                    querystring = querystring.arg(line.mid(118, 5));
                    querystring = querystring.arg(line.mid(125, 5));
                    querystring = querystring.arg(line.mid(132, 6));
                };*/


                qDebug() << line;
                query.exec(querystring);

                qDebug() << query.lastQuery() << query.lastError();
                /*qDebug() << line.mid(14, 4);
                qDebug() << line.mid(18, 2);
                qDebug() << line.mid(20, 2);
                qDebug() << line.mid(24,6);
                qDebug() << line.mid(35, 6);*/
                /*qDebug() << line.mid(46, 6);
                qDebug() << line.mid(57, 6);*/
                /*qDebug() << line.mid(68, 5);
                qDebug() << line.mid(78, 5);
                qDebug() << line.mid(88, 5);
                qDebug() << line.mid(95, 5);*/
                /*qDebug() << line.mid(102, 6);
                qDebug() << line.mid(110, 6);
                /*qDebug() << line.mid(118, 5);
                qDebug() << line.mid(125, 5);
                qDebug() << line.mid(132, 6);*/
            };
        };
        query.exec("COMMIT TRANSACTION");
    };
}
bool fileLoadWidget::processNinoMonthly(QString filename){
    qDebug() << "processDiary Weather";
    QFile file(filename);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly)){
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd()){
            if(first){ first = false; continue; };
            QString line(file.readLine());
            QString querystring, selectstring;
            QString month;
            month = QString::number(line.mid(6, 2).toInt());
            qDebug() << month;
            selectstring = "SELECT fecha FROM estadotiempos_mensuales WHERE fecha = '%1-%2-01'";
            selectstring = selectstring.arg(line.mid(0, 4));
            selectstring = selectstring.arg(month.rightJustified(2, '0'));
            query.exec(selectstring);
            if(query.next()){
                querystring = "UPDATE estadotiempos_mensuales SET ninonina = %1 WHERE fecha = '%2-%3-01'";
                querystring = querystring.arg(line.mid(27, 4));
                querystring = querystring.arg(line.mid(0, 4));
                querystring = querystring.arg(month.rightJustified(2, '0'));
            }else{
                querystring = "INSERT INTO estadotiempos_mensuales (fecha, ninonina) VALUES ('%1-%2-01', %4)";
                querystring = querystring.arg(line.mid(27, 4));
                querystring = querystring.arg(line.mid(0, 4));
                querystring = querystring.arg(month.rightJustified(2, '0'));
            };

            query.exec(querystring);

            qDebug() << query.lastQuery() << query.lastError();
        };
        query.exec("COMMIT TRANSACTION");
    };
}
bool fileLoadWidget::processDiarySunspots(QString filename){
    qDebug() << "processDiary Weather";
    QFile file(filename);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly)){
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd()){
            QString line(file.readLine());
            QStringList rec = line.split(" ", QString::SkipEmptyParts);
            if (rec[2] != "?")
            {
                QString querystring, selectstring;
                selectstring = "SELECT fecha FROM estadotiempos_diarios WHERE fecha = '%1-%2-%3'";
                selectstring = selectstring.arg(line.mid(0, 4));
                selectstring = selectstring.arg(line.mid(4, 2));
                selectstring = selectstring.arg(line.mid(6, 2));
                query.exec(selectstring);
                //esto tiene un error muy grosero, cuando el parametro sunspots es un  ? el mid devielve cualquier cosa.

                if(query.next())
                {
                    querystring = "UPDATE estadotiempos_diarios SET sunspots = %1 WHERE fecha = '%2-%3-%4'";
                    //querystring = querystring.arg(line.mid(10,5));
                    querystring = querystring.arg(rec[2]);
                    querystring = querystring.arg(line.mid(0, 4));
                    querystring = querystring.arg(line.mid(4, 2));
                    querystring = querystring.arg(line.mid(6, 2));

                }
                else
                {
                    querystring = "INSERT INTO estadotiempos_diarios (fecha, sunspots) VALUES ('%1-%2-%3', %4)";
                    querystring = querystring.arg(line.mid(0, 4));
                    querystring = querystring.arg(line.mid(4, 2));
                    querystring = querystring.arg(line.mid(6, 2));
                    //querystring = querystring.arg(line.mid(10,5));
                    querystring = querystring.arg(rec[2]);
                }
                query.exec(querystring);

                qDebug() << query.lastQuery() << query.lastError();
            }
        };
        query.exec("COMMIT TRANSACTION");
    };
}
bool fileLoadWidget::processMonthlySunspots(QString filename){
    qDebug() << "processDiary Weather";
    QFile file(filename);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly)){
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd()){
            if(first){ first = false; continue; };
            QString line(file.readLine());
            QString querystring, selectstring;
            selectstring = "SELECT fecha FROM estadotiempos_mensuales WHERE fecha = '%1-%2-01'";
            selectstring = selectstring.arg(line.mid(0, 4));
            selectstring = selectstring.arg(line.mid(4, 2));
            query.exec(selectstring);
            if(query.next()){
                querystring = "UPDATE estadotiempos_mensuales SET sunspots = %1 WHERE fecha = '%2-%3-01'";
                querystring = querystring.arg(line.mid(19, 5));
                querystring = querystring.arg(line.mid(0, 4));
                querystring = querystring.arg(line.mid(4, 2));
            }else{
                querystring = "INSERT INTO estadotiempos_mensuales (fecha, sunspots) VALUES ('%1-%2-01', %4)";
                querystring = querystring.arg(line.mid(0, 4));
                querystring = querystring.arg(line.mid(4, 2));
                querystring = querystring.arg(line.mid(19, 5));
            };

            query.exec(querystring);

            qDebug() << query.lastQuery() << query.lastError();
        };
        query.exec("COMMIT TRANSACTION");
    };
}

void fileLoadWidget::on_btnDownload_released()
{
    QString url = "";
    if (ui->ninoMonthlyRadioButton->isChecked())
    {
        url = "http://www.cpc.ncep.noaa.gov/products/analysis_monitoring/ensostuff/detrend.nino34.ascii.txt";
    }
    else if (ui->sunspotDiaryRadioButton->isChecked())
    {
        //url = "http://sidc.oma.be/sunspot-data/dailyssn.php";
        url = "http://www.sidc.be/silso/DATA/dayssn.dat";
    }
    else if (ui->sunspotMonthlyRadioButton->isChecked())
    {
        url = "http://sidc.oma.be/DATA/monthssn.dat";
    }
    else if (ui->weatherDiaryRadioButton->isChecked())
    {
        if (ui->cboCiudad->currentText() == "Bahia Blanca")
        {
            url = "ftp://ftp.ncdc.noaa.gov/pub/data/gsod/2015/877500-99999-2015.op.gz";
        }
        else if (ui->cboCiudad->currentText() == "Tres Arroyos")
        {
            url = "ftp://ftp.ncdc.noaa.gov/pub/data/gsod/2015/087688-99999-2015.op.gz";
        }
        else if (ui->cboCiudad->currentText() == "Mar del Plata")
        {
            url = "ftp://ftp.ncdc.noaa.gov/pub/data/gsod/2015/08692-99999-2015.op.gz";
        }
        else if (ui->cboCiudad->currentText() == "Buenos Aires")
        {
            url = "ftp://ftp.ncdc.noaa.gov/pub/data/gsod/2015/087582-99999-2015.op.gz";
        }
    }

    if (downloader == NULL && url.length() > 0)
    {
        downloader = new FileDownloader(QUrl(url));
        connect(downloader, SIGNAL(downloaded(QString)), this, SLOT(fileDownloaded(QString)));
        ui->btnDownload->setEnabled(false);
    }
}

void fileLoadWidget::fileDownloaded(const QString &filename)
{
    qDebug() << filename;
    QByteArray bytes = downloader->downloadedData();
    ui->btnDownload->setEnabled(true);

    QFile file(QString("./downloads/%1").arg(filename));
    file.open(QIODevice::WriteOnly);
    file.write(bytes);
    file.close();

    filenames.append(file.fileName());
    //qDebug() << files.at(i);
    fileprogress.append(0);
    refresh();
    downloader->deleteLater();
    downloader = NULL;
}
