#include <QtGui/QApplication>
#include <QtSql>
#include <QFile>
#include <QLibrary>
#include "astroinfo.h"
#include "mainwindow.h"
#include "utils.h"
#include <QDateTime>
#include <QtSql>

int main(int argc, char *argv[])
{
    /*astroInfo info;
    QDateTime mitiempo;
    mitiempo.setDate(QDate(1940, 05, 21));
    mitiempo.setTime(QTime(9, 33, 0, 0).addSecs(+3*3600));
    info.setTimestamp(mitiempo/*QDateTime::currentDateTime()*);
    info.setLon(-(62.0 + (17.0 / 60.0)));
    info.setLat(-(38.0 + (43.0 / 60.0)));
    info.doCalc();*/

    Q_INIT_RESOURCE(resource);
    QApplication a(argc, argv);        
    MainWindow* w = MainWindow::instance();
    w->setLocale(QLocale(QLocale::Spanish, QLocale::Argentina));
    w->show();
    return a.exec();
}

// useless info

/*astroInfo info;
QDateTime mitiempo;
mitiempo.setDate(QDate(2011, 11, 23));
mitiempo.setTime(QTime(15, 48, 41, 0).addSecs(+3*3600));
/*info.setTimestamp(mitiempo/*QDateTime::currentDateTime()*);
info.setLon(-(62.0 + (17.0 / 60.0)));
info.setLat(-(38.0 + (43.0 / 60.0)));
info.doCalc();*/


/*QSqlDatabase db;
db = QSqlDatabase::addDatabase("QMYSQL");
db.setHostName("127.0.0.1");
db.setUserName("root");
db.setPassword("");
db.setDatabaseName("meteoastrologia");
qDebug() << db.open();
// open db to insert the data

QFile file("87750SFC.SFD");

QSqlQuery query;
query.exec("START TRANSACTION");
if(file.open(QIODevice::ReadOnly)){

    while(!file.atEnd()){
        //qDebug() << "wepa";
        QString readed = QString(file.read(233));
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
        query.exec(QString("INSERT INTO tiempos (fecha, maxima, minima, vientovel, direccionviento, precipitacion, mil500) VALUES "
                           "('%1', %2, %3, %4, %5, %6, %7)")
                   .arg(date.toString("yyyy-MM-dd hh:mm:ss"))
                   .arg(parsed.at(1).toDouble())
                   .arg(parsed.at(2).toDouble())
                   .arg(parsed.at(6).toInt() * 1.852)
                   .arg(parsed.at(7).toInt())
                   .arg((precipitaciones > 990)? precipitaciones = (precipitaciones - 990) / 10 : precipitaciones)
                   .arg(0));
        //qDebug() << query.lastQuery() << query.lastError();

    };
};
file.close();
file.setFileName("87750RAO.RBD");

if(file.open(QIODevice::ReadOnly)){
    while(!file.atEnd()){
        //qDebug() << "wepa";
        QString readed = QString(file.read(33));
        //qDebug() << readed;
        if(readed.count("M ", Qt::CaseSensitive) == 2) continue; //no fue tomado
        query.exec(QString("UPDATE tiempos SET mil500 = %1 WHERE DATE(fecha) = '%2'")
                   .arg(readed.mid(21,7).toInt())
                   .arg(QDate::fromString(readed.mid(1, 8), QString("yyyyMMdd")).toString("yyyy-MM-dd")));
        //qDebug() << query.lastQuery() << query.lastError();
    };
};

query.exec("COMMIT");*/
