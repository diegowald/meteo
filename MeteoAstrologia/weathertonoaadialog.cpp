#include "weathertonoaadialog.h"
#include "ui_weathertonoaadialog.h"

weatherToNoaaDialog::weatherToNoaaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weatherToNoaaDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(doCalc()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);
}

weatherToNoaaDialog::~weatherToNoaaDialog()
{
    delete ui;
}

void weatherToNoaaDialog::doCalc()
{
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION");
    QProgressDialog dialog(tr("Calculando "), tr("Cancelar"), 0, ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date()), this);
    dialog.setWindowModality(Qt::ApplicationModal);
    dialog.setMinimumDuration(500);
    query.exec(
                QString("SELECT * FROM estadotiempos_diarios WHERE fecha >= '%1 00:00:00' AND fecha <= '%2 00:00:00' AND usaf = '%3'")
                .arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd"))
                .arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd"))
                .arg(usaf()));
    while(query.next() && !dialog.wasCanceled()){
        dialog.setValue(dialog.value() + 1);
        QDateTime date = QDateTime::fromString(query.record().field("fecha").value().toString(), "yyyy-MM-dd");
        processDay(date);
    }
    query.exec("COMMIT TRANSACTION");
}

void weatherToNoaaDialog::processDay(QDateTime date)
{
    QSqlQuery select;
    select.exec(QString("SELECT * FROM tiempos WHERE fecha = '%1'").arg(date.toString("yyyy-MM-dd hh:mm:ss")));
    qDebug() << select.lastQuery() << select.lastError();
    double  temperatura = 0;
    double  tempmax = -100;
    double  tempmin = 100;
    double  presion = 0;
    double  visibilidad = 0;
    double  viento_vel = 0;
    double  punto_rocio = 0;
    double  precipitaciones = 0;

    int     ctemperatura = 0;
    int     ctempmax = 0;
    int     ctempmin = 0;
    int     cpresion = 0;
    int     cvisibilidad = 0;
    int     cviento_vel = 0;
    int     cpunto_rocio = 0;
    int     cprecipitaciones = 0;

    if(select.next()){
        if(select.record().field("tempmin").value().toDouble() != -99){
            if(tempmin > select.record().field("tempmin").value().toDouble())
                tempmin = select.record().field("tempmin").value().toDouble();
            ctempmin++;
        }
        if(select.record().field("tempmax").value().toDouble() != -99){
            if(tempmax < select.record().field("tempmax").value().toDouble())
                tempmax = select.record().field("tempmax").value().toDouble();
            ctempmax++;
        }
        if(select.record().field("temperatura").value().toDouble() != -99){
            temperatura = select.record().field("temperatura").value().toDouble();
            ctemperatura++;
        }
        if(select.record().field("visibilidad").value().toDouble() != -99){
            visibilidad = select.record().field("visibilidad").value().toDouble();
            cvisibilidad++;
        }
        if(select.record().field("velocidadviento").value().toDouble() != -99){
            viento_vel = select.record().field("velocidadviento").value().toDouble() * 1.875;
            cviento_vel++;
        }
        if(select.record().field("puntorocio").value().toDouble() != -99){
            punto_rocio = select.record().field("puntorocio").value().toDouble();
            cpunto_rocio++;
        }
        if(select.record().field("lluvia").value().toDouble() != -99){
            precipitaciones = select.record().field("lluvia").value().toDouble();
            cprecipitaciones++;
        }
        if(select.record().field("presion").value().toDouble() != -99){
            presion = select.record().field("presion").value().toDouble();
            cpresion++;
        }
    }

    if(ctemperatura != 0)   select.exec(QString("UPDATE estadotiempos_diarios SET temp_media = %1 WHERE fecha = '%2' AND temp_media = -99 AND usaf = '%3'")
                                        .arg(temperatura / ctemperatura)
                                        .arg(date.toString("yyyy-MM-dd"))
                                        .arg(usaf()));
    qDebug() << select.lastQuery() << select.lastError();
    if(ctempmax != 0)       select.exec(QString("UPDATE estadotiempos_diarios SET temp_max = %1 WHERE fecha = '%2' AND temp_max = -99").arg(tempmax).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();
    if(ctempmin != 0)       select.exec(QString("UPDATE estadotiempos_diarios SET temp_min = %1 WHERE fecha = '%2' AND temp_min = -99").arg(tempmin).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();
    if(cpresion != 0)       select.exec(QString("UPDATE estadotiempos_diarios SET presion= %1 WHERE fecha = '%2' AND presion = -99").arg(presion / cpresion).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();
    if(cvisibilidad != 0)   select.exec(QString("UPDATE estadotiempos_diarios SET visibilidad = %1 WHERE fecha = '%2' AND visibilidad = -99").arg(visibilidad / cvisibilidad).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();
    if(cviento_vel != 0)    select.exec(QString("UPDATE estadotiempos_diarios SET viento_vel = %1 WHERE fecha = '%2' AND viento_vel = -99").arg(viento_vel / cviento_vel).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();
    if(cpunto_rocio != 0)   select.exec(QString("UPDATE estadotiempos_diarios SET punto_rocio = %1 WHERE fecha = '%2' AND punto_rocio = -99").arg(punto_rocio / cpunto_rocio).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();
    if(cprecipitaciones !=0)select.exec(QString("UPDATE estadotiempos_diarios SET precipitaciones = %1 WHERE fecha = '%2' AND precipitaciones = -99").arg(precipitaciones).arg(date.toString("yyyy-MM-dd")));
    qDebug() << select.lastQuery() << select.lastError();

}

QString weatherToNoaaDialog::usaf() const
{
    return ui->cboEstacion->currentText();
}
