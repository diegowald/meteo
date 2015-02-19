#include "monthcalcdialog.h"
#include "ui_monthcalcdialog.h"

monthCalcDialog::monthCalcDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monthCalcDialog)
{
    ui->setupUi(this);

    ui->hastaDateEdit->setDate(QDate::currentDate());

    connect(this, SIGNAL(accepted()), this, SLOT(save()));
}

monthCalcDialog::~monthCalcDialog()
{
    delete ui;
}

void monthCalcDialog::save()
{
    QString col;
    QStringList columnas, columnasesp;
    QSqlQuery query, insert;
    QProgressDialog dialog;

    dialog.setWindowTitle("Calculando Mensualidades: ");
    //dialog.setMaximum(9600);
    dialog.setValue(0);
    int count = 0;

    /*query.exec("select count(q) as q FROM (select distinct substr(fecha,0, 8) as q from estadotiempos_diarios)");
    query.next();*/
    qDebug() << "dias:" << ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date());
    qDebug() << "meses:" << ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date()) / 30;
    dialog.setMaximum(ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date()) / 30);
    dialog.setMinimumDuration(0);

    /*columnas << "temp_media" << "temp_max" << "temp_min" << "presion" << "visibilidad";
    columnas << "viento_vel" << "viento_rafaga" << "punto_rocio" << "precipitaciones"  << "nieve";*/

    columnas << "temp_media" << "presion" << "visibilidad" << "viento_vel" << "viento_rafaga" << "punto_rocio";
    columnasesp << "temp_max" << "temp_min" << "precipitaciones" << "nieve";

    query.exec(QString("select distinct substr(fecha,0, 8) as q from estadotiempos_diarios WHERE fecha >= '%1' AND fecha <= '%2'").arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd")).arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd")));
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
                /*if(col == "precipitaciones"){
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
                };*/
                insert.exec(QString("UPDATE estadotiempos_mensuales SET %1 = %2 WHERE fecha = '%3-01'").arg(col).arg("9999.9").arg(query.record().field("q").value().toString()));
            };
            //qDebug() << insert.lastQuery() << insert.lastError();
        };
        dialog.setValue(++count);
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
    };
    insert.exec("END TRANSACTION");
}
