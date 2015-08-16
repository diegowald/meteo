#include "automaticdownloaderwidget.h"
#include "ui_automaticdownloaderwidget.h"
#include <QDebug>
#include <qcompressor.h>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileInfo>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <QDate>

AutomaticDownloaderWidget::AutomaticDownloaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AutomaticDownloaderWidget)
{
    ui->setupUi(this);
    obtenerEstaciones();
    // Obtengo la informacion a descargar
    generarListadoArchivosADescargar();
}

AutomaticDownloaderWidget::~AutomaticDownloaderWidget()
{
    delete ui;
}

void AutomaticDownloaderWidget::on_btnDescargar_released()
{

    // Descargo la informacion
    doDownload();
    ui->btnDescargar->setEnabled(false);
}

void AutomaticDownloaderWidget::processFiles()
{
    for (int i = 0; i < ui->tblProcess->rowCount(); ++i)
    {
        QString tipo = ui->tblProcess->item(i, 1)->text();
        QString filename = ui->tblProcess->item(i, 0)->text();
        ui->tblProcess->item(i, 3)->setText("Procesando");
        bool resultado = false;
        if (tipo == "Estado Tiempo")
        {
            resultado = processDiaryWeather(filename);
        }
        else if (tipo == "Niño")
        {
            resultado = processNinoMonthly(filename);
        }
        else if (tipo == "Manchas solares Diarias")
        {
            resultado = processDiarySunspots(filename);
        }
        else
        {
            resultado = processMonthlySunspots(filename);
        }
        ui->tblProcess->item(i, 3)->setText(resultado ? "OK" : "Error");
    }
}


bool AutomaticDownloaderWidget::processDiaryWeather(const QString &filename)
{
    qDebug() << "processDiary Weather. File: " << filename;

    QString _filename = "./downloads/" + filename;
    if (_filename.endsWith(".gz", Qt::CaseInsensitive))
    {
        QString file2 = _filename + ".decompressed";

        QCompressor::gzipDecompress(_filename, file2);
        _filename = file2;
    }
    QFile file(_filename);
    bool first;

    QFileInfo fileInfo(_filename);
    // Chequear esta funcion de abajo
    QString usaf = fileInfo.fileName().split('-')[0];
    first = true;
    if(file.open(QIODevice::ReadOnly))
    {
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd())
        {
            QString line(file.readLine());
            if(first)
            {
                first = false;
            }
            else
            {
                QString querystring, selectstring;
                selectstring = "SELECT fecha FROM estadotiempos_diarios WHERE usaf = '%4' AND fecha = '%1-%2-%3'";
                selectstring = selectstring.arg(line.mid(14, 4));
                selectstring = selectstring.arg(line.mid(18, 2));
                selectstring = selectstring.arg(line.mid(20, 2));
                selectstring = selectstring.arg(usaf);
                query.exec(selectstring);
                if(query.next())
                {
                    querystring = "UPDATE estadotiempos_diarios SET temp_media = %1, temp_max = %2, temp_min = %3, presion = %4, "
                                  "visibilidad = %5, viento_vel = %6, viento_rafaga = %7, punto_rocio = %8, precipitaciones = %9, nieve = %10, flags = %11 "
                                  " WHERE fecha = '%12-%13-%14' AND usaf = '%15'";
                }
                else
                {
                    querystring = "INSERT INTO estadotiempos_diarios (temp_media, temp_max, temp_min, presion, "
                                  "visibilidad, viento_vel, viento_rafaga, punto_rocio, precipitaciones, nieve, flags, fecha, usaf) VALUES "
                                  "(%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, '%12-%13-%14', '%15')";
                }
                //temp media
                if(line.mid(24,6) == "9999.9")
                {
                    querystring = querystring.arg(line.mid(24,6));
                }
                else
                {
                    double celc = line.mid(24, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                }
                //temp maxima
                if(line.mid(102,6) == "9999.9")
                {
                    querystring = querystring.arg(line.mid(102, 6));
                }
                else
                {
                    double celc = line.mid(102, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                }

                //temp minima
                if(line.mid(110,6) == "9999.9")
                {
                    querystring = querystring.arg(line.mid(110, 6));
                }
                else
                {
                    double celc = line.mid(110, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                }

                //presion
                querystring = querystring.arg( line.mid(46, 6) == "9999.9" ? line.mid(57, 6) : line.mid(46, 6) );

                //visibilidad
                if(line.mid(68, 5) == "999.9")
                {
                    querystring = querystring.arg(line.mid(68, 5));
                }
                else
                {
                    double miles = line.mid(68, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(miles * 1.609));
                }

                //viento velocidad
                if(line.mid(78, 5) == "999.9")
                {
                    querystring = querystring.arg(line.mid(78, 5));
                }
                else
                {
                    double knot = line.mid(78, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(knot * 1.852));
                }

                //viento rafaga
                if(line.mid(88, 5) == "999.9")
                {
                    querystring = querystring.arg(line.mid(88, 5));
                }
                else
                {
                    double knot = line.mid(88, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(knot * 1.852));
                }

                //punto rocio
                if(line.mid(35, 6) == "9999.9")
                {
                    querystring = querystring.arg(line.mid(35, 6));
                }
                else
                {
                    double celc = line.mid(35, 6).toDouble();
                    querystring = querystring.arg(QString("%1").arg((celc - 32)/1.8));
                }

                //precipitaciones
                if(line.mid(118, 5) != "99.99")
                {
                    double pulg = line.mid(118, 5).toDouble();
                    querystring = querystring.arg(QString("%1").arg(pulg * 25.4));
                }
                else
                {
                    querystring = querystring.arg("999.9");
                }

                // nieve
                if(line.mid(125, 5) == "999.9")
                {
                    querystring = querystring.arg(line.mid(125, 5));
                }
                else
                {
                    double pulg = line.mid(125, 5).toDouble();
                    querystring = querystring.arg("999.9");
                }

                //flags
                querystring = querystring.arg(line.mid(132, 6));

                //fecha
                querystring = querystring.arg(line.mid(14, 4));
                querystring = querystring.arg(line.mid(18, 2));
                querystring = querystring.arg(line.mid(20, 2));

                querystring = querystring.arg(usaf);

                qDebug() << line;
                query.exec(querystring);

                qDebug() << query.lastQuery() << query.lastError();
            }
        }
        query.exec("COMMIT TRANSACTION");
    }
    return true;
}


bool AutomaticDownloaderWidget::processNinoMonthly(const QString &filename){
    qDebug() << "processDiary Weather: " << filename;
    QFile file("./downloads/" + filename);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly))
    {
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd())
        {
            QString line(file.readLine());
            if(first){ first = false; continue; }
            foreach (QString estacion, _estaciones)
            {
                QString usaf = estacion.split('-')[0];
                QString querystring, selectstring;
                QString month;
                month = QString::number(line.mid(6, 2).toInt());
                qDebug() << month;
                selectstring = "SELECT fecha FROM estadotiempos_mensuales WHERE fecha = '%1-%2-01' AND usaf = '%3'";
                selectstring = selectstring.arg(line.mid(0, 4));
                selectstring = selectstring.arg(month.rightJustified(2, '0'));
                selectstring = selectstring.arg(usaf);
                query.exec(selectstring);
                if(query.next())
                {
                    querystring = "UPDATE estadotiempos_mensuales SET ninonina = %1 WHERE fecha = '%2-%3-01' AND usaf = '%4'";
                    querystring = querystring.arg(line.mid(27, 4));
                    querystring = querystring.arg(line.mid(0, 4));
                    querystring = querystring.arg(month.rightJustified(2, '0'));
                    querystring = querystring.arg(usaf);
                }
                else
                {
                    querystring = "INSERT INTO estadotiempos_mensuales (fecha, ninonina, usaf) VALUES ('%1-%2-01', %3, '%4')";
                    querystring = querystring.arg(line.mid(0, 4));
                    querystring = querystring.arg(month.rightJustified(2, '0'));
                    querystring = querystring.arg(line.mid(27, 4));
                    querystring = querystring.arg(usaf);
                }

                query.exec(querystring);

                qDebug() << query.lastQuery() << query.lastError();
            }
        }
        query.exec("COMMIT TRANSACTION");
    }
    return true;
}


bool AutomaticDownloaderWidget::processDiarySunspots(const QString &filename){
    qDebug() << "processDiary Weather";
    QFile file("./downloads/" + filename);
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
                foreach (QString estacion, _estaciones)
                {
                    QString usaf = estacion.split('-')[0];
                    QString querystring, selectstring;
                    selectstring = "SELECT fecha FROM estadotiempos_diarios WHERE fecha = '%1-%2-%3' AND usaf = '%4'";
                    selectstring = selectstring.arg(line.mid(0, 4));
                    selectstring = selectstring.arg(line.mid(4, 2));
                    selectstring = selectstring.arg(line.mid(6, 2));
                    selectstring = selectstring.arg(usaf);
                    query.exec(selectstring);
                    //esto tiene un error muy grosero, cuando el parametro sunspots es un  ? el mid devielve cualquier cosa.

                    if(query.next())
                    {
                        querystring = "UPDATE estadotiempos_diarios SET sunspots = %1 WHERE fecha = '%2-%3-%4' AND usaf = '%5'";
                        //querystring = querystring.arg(line.mid(10,5));
                        querystring = querystring.arg(rec[2]);
                        querystring = querystring.arg(line.mid(0, 4));
                        querystring = querystring.arg(line.mid(4, 2));
                        querystring = querystring.arg(line.mid(6, 2));
                        querystring = querystring.arg(usaf);
                    }
                    else
                    {
                        querystring = "INSERT INTO estadotiempos_diarios (fecha, sunspots, usaf) VALUES ('%1-%2-%3', %4, '%5')";
                        querystring = querystring.arg(line.mid(0, 4));
                        querystring = querystring.arg(line.mid(4, 2));
                        querystring = querystring.arg(line.mid(6, 2));
                        querystring = querystring.arg(rec[2]);
                        querystring = querystring.arg(usaf);
                    }
                    query.exec(querystring);

                }
            }
        }
        query.exec("COMMIT TRANSACTION");
    }
    return true;
}


bool AutomaticDownloaderWidget::processMonthlySunspots(const QString &filename)
{
    qDebug() << "processDiary Weather";
    QFile file("./downloads/" + filename);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly))
    {
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd())
        {
            if(first){ first = false; continue; }
            QString line(file.readLine());
            foreach (QString estacion, _estaciones)
            {
                QString usaf = estacion.split('-')[0];
                QString querystring, selectstring;
                selectstring = "SELECT fecha FROM estadotiempos_mensuales WHERE fecha = '%1-%2-01' AND usaf = '%3'";
                selectstring = selectstring.arg(line.mid(0, 4));
                selectstring = selectstring.arg(line.mid(4, 2));
                selectstring = selectstring.arg(usaf);
                query.exec(selectstring);
                if(query.next())
                {
                    querystring = "UPDATE estadotiempos_mensuales SET sunspots = %1 WHERE fecha = '%2-%3-01' AND usaf = '%4'";
                    querystring = querystring.arg(line.mid(19, 5));
                    querystring = querystring.arg(line.mid(0, 4));
                    querystring = querystring.arg(line.mid(4, 2));
                    querystring = querystring.arg(usaf);
                }
                else
                {
                    querystring = "INSERT INTO estadotiempos_mensuales (fecha, sunspots, usaf) VALUES ('%1-%2-01', %3, '%4')";
                    querystring = querystring.arg(line.mid(0, 4));
                    querystring = querystring.arg(line.mid(4, 2));
                    querystring = querystring.arg(line.mid(19, 5));
                    querystring = querystring.arg(usaf);
                }

                query.exec(querystring);

                qDebug() << query.lastQuery() << query.lastError();
            }
        }
        query.exec("COMMIT TRANSACTION");
    }
    return true;
}


void AutomaticDownloaderWidget::obtenerEstaciones()
{
    _estaciones.clear();
    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE selected = 1;");
    while (query.next())
    {
        _estaciones << (query.record().field("usaf").value().toString()
                        + "-" +
                        query.record().field("WBAN").value().toString());
    }
}

void AutomaticDownloaderWidget::generarListadoArchivosADescargar()
{
    ui->tblProcess->setRowCount(0);
    QString filePattern = "%1-%2.op.gz";
    QString urlPattern = "ftp://ftp.ncdc.noaa.gov/pub/data/gsod/%1/%2";
    foreach (QString estacion, _estaciones)
    {
        QSqlQuery query;
        query.exec(QString("SELECT BEGINDATA, ENDDATA FROM STATIONS WHERE USAF || '-' || WBAN = '%1';").arg(estacion));
        while(query.next())
        {
            for (int i = 1901; i <= QDate::currentDate().year(); ++i)
            {
                QString filename = filePattern.arg(estacion).arg(i);
                QString url = urlPattern.arg(i).arg(filename);
                addFile(filename, url, "Estado Tiempo");
            }
        }
    }

    addFile(QString("detrend.nino34.ascii.txt"),
            QString("http://www.cpc.ncep.noaa.gov/products/analysis_monitoring/ensostuff/detrend.nino34.ascii.txt"),
            QString("Niño"));

    addFile(QString("dayssn.dat"),
            QString("http://www.sidc.be/silso/DATA/dayssn.dat"),
            QString("Manchas solares Diarias"));

    addFile(QString("monthssn.dat"),
            QString("http://sidc.oma.be/DATA/monthssn.dat"),
            QString("Manchas solares Mensuales"));
}


void AutomaticDownloaderWidget::addFile(const QString &filename, const QString &url, const QString &filetype)
{
    int row = ui->tblProcess->rowCount();
    ui->tblProcess->insertRow(row);
    ui->tblProcess->setItem(row, 0, new QTableWidgetItem(filename));
    ui->tblProcess->item(row, 0)->setData(Qt::UserRole, url);
    ui->tblProcess->setItem(row, 1, new QTableWidgetItem(filetype));
    ui->tblProcess->setItem(row, 2, new QTableWidgetItem(""));
    ui->tblProcess->setItem(row, 3, new QTableWidgetItem(""));
}

void AutomaticDownloaderWidget::doDownload()
{
    for (int i = 0; i < ui->tblProcess->rowCount(); ++i)
    {
        QString url = ui->tblProcess->item(i, 0)->data(Qt::UserRole).toString();
        _downloadQueue[i] = url;
    }
    updateDownloadQueue();
}

void AutomaticDownloaderWidget::downloading(int id, qint64 bytes, qint64 total)
{
    QString pattern = "Descargando %1 de %2 bytes.";
    ui->tblProcess->item(id, 2)->setText(pattern.arg(bytes, total));
}

void AutomaticDownloaderWidget::downloaded(int id, QString file)
{
    QByteArray bytes = _downloaderQueue[id]->downloadedData();

    QFile f(QString("./downloads/%1").arg(file));
    f.open(QIODevice::WriteOnly);
    f.write(bytes);
    f.close();

    QString pattern = "Descargado.";
    ui->tblProcess->item(id, 2)->setText(pattern);
    _downloaderQueue[id]->deleteLater();
    _downloaderQueue.remove(id);
    _downloadQueue.remove(id);
    updateDownloadQueue();
}

void AutomaticDownloaderWidget::updateDownloadQueue()
{
    if (_downloaderQueue.count() >= 3)
        return;

    QSet<int> listaADescargar = _downloadQueue.keys().toSet();
    QSet<int> listaDescargando = _downloaderQueue.keys().toSet();

    QSet<int> aProcesar = listaADescargar.subtract(listaDescargando);

    if (aProcesar.count() > 0)
    {
        for (int i = _downloaderQueue.count(); i <= 3; ++i)
        {
            int id = aProcesar.toList().first();
            QString url = _downloadQueue[id];
            FileDownloader *fileDownloader = new FileDownloader(id, url);
            connect(fileDownloader, SIGNAL(downloadProgress(int,qint64,qint64)),
                    this, SLOT(downloading(int,qint64,qint64)));
            connect(fileDownloader, SIGNAL(downloaded(int,QString)),
                    this, SLOT(downloaded(int,QString)));
            _downloaderQueue[id] = fileDownloader;
            aProcesar.remove(id);
            if (aProcesar.count() == 0)
            {
                break;
            }
        }
    }
    else
    {
        processFiles();
        ui->btnDescargar->setEnabled(true);
    }
}
