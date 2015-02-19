#include "rbdtoweatherdialog.h"
#include "ui_rbdtoweatherdialog.h"

RBDtoWeatherDialog::RBDtoWeatherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RBDtoWeatherDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(doCalc()));
}

RBDtoWeatherDialog::~RBDtoWeatherDialog()
{
    delete ui;
}

void RBDtoWeatherDialog::doCalc()
{
    QSqlQuery query;
    QProgressDialog dialog(tr("Calculando "), tr("Cancelar"), 0, ui->desdeDateEdit->date().daysTo(ui->hastaDateEdit->date()), this);
    dialog.setWindowModality(Qt::ApplicationModal);
    dialog.setMinimumDuration(500);
    query.exec(QString("SELECT * FROM estadotiempos WHERE fecha >= '%1 00:00:00' AND fecha <= '%2 00:00:00'").arg(ui->desdeDateEdit->date().toString("yyyy-MM-dd")).arg(ui->hastaDateEdit->date().toString("yyyy-MM-dd")));
    while(query.next() && !dialog.wasCanceled()){
        dialog.setValue(dialog.value() + 1);
        QDateTime date = QDateTime::fromString(query.record().field("fecha").value().toString(), "yyyy-MM-dd hh:mm:ss");
        processDay(date);
    };
}

void RBDtoWeatherDialog::processDay(QDateTime date)
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
    QSqlQuery select;

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
}
