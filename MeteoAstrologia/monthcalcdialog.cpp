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
    dialog.setValue(0);
    int count = 0;


    qDebug() << "dias:" << ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date());
    qDebug() << "meses:" << ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date()) / 30;

    dialog.setMinimumDuration(0);

    columnas << "temp_media" << "presion" << "visibilidad" << "viento_vel" << "viento_rafaga" << "punto_rocio";
    columnasesp << "temp_max" << "temp_min" << "precipitaciones" << "nieve";

    dialog.setMaximum(columnas.count() + columnasesp.count());


    insert.exec("BEGIN TRANSACTION");

    // inserto los meses que no estan en la tabla de meses
    insert.exec("insert into estadotiempos_mensuales (usaf, fecha) select t1.usaf, t1.mes "
                " from (select distinct usaf, substr(fecha, 0, 8) || '-01' as mes from estadotiempos_diarios) t1 "
                " left join (select usaf, fecha as mes from estadotiempos_mensuales) t2 on "
                " t1.usaf = t2.usaf and t1.mes = t2.mes where t2.mes is null; ");


    foreach (QString col, columnas)
    {
        QString q = "select %3 as valor, substr(fecha, 0, 8) as mes, usaf from estadotiempos_diarios where %4 and fecha >= '%1' AND fecha <= '%2' group by substr(fecha, 0, 8), usaf;";

        QString qry;
        if (col == "presion")
        {
            qry = q.arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                    .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                    .arg("avg(presion)")
                    .arg("presion < 9999.9");
        }
        else
        {
            qry = q.arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                    .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                    .arg("avg("  + col + " )")
                    .arg(col + " < 999.9");
        }

        query.exec(qry);

        qDebug() << query.lastQuery() << query.lastError();
        QString updateTemplate = "UPDATE estadotiempos_mensuales SET %1 = %2 WHERE usaf = '%3' AND fecha = '%4-01'";
        while(query.next() && !dialog.wasCanceled())
        {
            QString updQry = updateTemplate.arg(col).arg(query.record().field("valor").value().toDouble())
                    .arg(query.record().field("usaf").value().toString())
                    .arg(query.record().field("mes").value().toString());

            insert.exec(updQry);
            //qDebug() << insert.lastQuery() << insert.lastError();
        }
        dialog.setValue(++count);
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
    }

    foreach(col, columnasesp)
    {
        QString q = "select %3 as valor, substr(fecha, 0, 8) as mes, usaf from estadotiempos_diarios where %4 and fecha >= '%1' AND fecha <= '%2' group by substr(fecha, 0, 8), usaf;";
        QString qry;
        //"temp_max" << "temp_min" << "precipitaciones" << "nieve";
        if(col == "temp_max")
        {
            qry = q.arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                    .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                    .arg("max(" + col + ")")
                    .arg(col + " < 999.9");
        }
        else if(col == "temp_min")
        {
            qry = q.arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                    .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                    .arg("min(" + col + ")")
                    .arg(col + " < 999.9");
        }
        else if(col == "precipitaciones")
        {
            qry = q.arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                    .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                    .arg("sum(" + col + ")")
                    .arg(col + " < 999.9");
        }
        else if(col == "nieve")
        {
            qry = q.arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                    .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                    .arg("sum(" + col + ")")
                    .arg(col + " < 999.9");
        }
        query.exec(qry);
        qDebug() << query.lastQuery() << query.lastError();
        QString updateTemplate = "UPDATE estadotiempos_mensuales SET %1 = %2 WHERE usaf = '%3' AND fecha = '%4-01'";
        while(query.next() && !dialog.wasCanceled())
        {
            QString updQry = updateTemplate.arg(col).arg(query.record().field("valor").value().toDouble())
                    .arg(query.record().field("usaf").value().toString())
                    .arg(query.record().field("mes").value().toString());

            insert.exec(updQry);
            //qDebug() << insert.lastQuery() << insert.lastError();
        }
        dialog.setValue(++count);
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
    }
    insert.exec("END TRANSACTION");
}
