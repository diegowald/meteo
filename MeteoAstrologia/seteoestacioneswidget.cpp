#include "seteoestacioneswidget.h"
#include "ui_seteoestacioneswidget.h"
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>

SeteoEstacionesWidget::SeteoEstacionesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeteoEstacionesWidget)
{
    ui->setupUi(this);
    _fileDownloader = NULL;
    llenarListadoConEstaciones();
}

SeteoEstacionesWidget::~SeteoEstacionesWidget()
{
    delete ui;
}

void SeteoEstacionesWidget::on_btnRefresh_released()
{
    QString url = "ftp://ftp.ncdc.noaa.gov/pub/data/gsod/isd-history.csv";
    if (_fileDownloader == NULL && url.length() > 0)
    {
        _fileDownloader = new FileDownloader(QUrl(url));
        connect(_fileDownloader, SIGNAL(downloaded(QString)), this, SLOT(fileDownloaded(QString)));
    }
}

void SeteoEstacionesWidget::fileDownloaded(const QString &filename)
{
    qDebug() << filename;
    QByteArray bytes = _fileDownloader->downloadedData();

    QString downloadedFile = QString("./downloads/%1").arg(filename);
    QFile file(downloadedFile);
    file.open(QIODevice::WriteOnly);
    file.write(bytes);
    file.close();

    _fileDownloader->deleteLater();
    _fileDownloader = NULL;

    processEstaciones(downloadedFile);
}

void SeteoEstacionesWidget::processEstaciones(const QString &filename)
{
    qDebug() << "process Estaciones";
    QFile file(filename);
    bool first;

    first = true;
    if(file.open(QIODevice::ReadOnly))
    {
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION");
        while(!file.atEnd())
        {
            QString line(file.readLine());
            if(first){ first = false; continue; };
            line = line.replace('\"', "").replace('\n', "");
            QStringList fields = line.split(',');
            QString querystring, selectstring;
            if (fields[3] == "AR")
            {
                selectstring = "SELECT fecha FROM STATIONS WHERE USAF = '%1'";
                selectstring = fields[0];
                query.exec(selectstring);
                if(!query.next())
                {
                    querystring = "INSERT INTO STATIONS (USAF, WBAN, NAME, COUNTRY, BEGINDATA, ENDDATA, selected) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', %7)";
                    querystring = querystring.arg(fields[0]).arg(fields[1])
                            .arg(fields[2]).arg(fields[3]).arg(fields[8]).arg(fields[9]).arg(0);
                };

                query.exec(querystring);

                qDebug() << query.lastQuery() << query.lastError();
            }
        };
        query.exec("COMMIT TRANSACTION");
    };
    llenarListadoConEstaciones();
}

void SeteoEstacionesWidget::llenarListadoConEstaciones()
{
    ui->lstCiudades->clear();
    QSqlQuery *query = new QSqlQuery();

    query->exec(QString("SELECT * from STATIONS order by name;"));

    qDebug() << query->lastQuery() << query->lastError();

    QString fieldFormat = "%1 - %2 - %3";
    while(query->next())
    {
        QString record = fieldFormat.arg(query->record().field("USAF").value().toString())
                .arg(query->record().field("NAME").value().toString())
                .arg(query->record().field("COUNTRY").value().toString());

        QListWidgetItem *item = new QListWidgetItem(record, ui->lstCiudades);

        item->setCheckState(query->record().field("selected").value().toInt() != 0 ? Qt::Checked : Qt::Unchecked);
        item->setData(Qt::UserRole, query->record().field("USAF").value().toString());
        ui->lstCiudades->addItem(item);
    };
}

void SeteoEstacionesWidget::on_btnSave_released()
{
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION");
    QString updateString = "UPDATE STATIONS SET selected = %1 WHERE USAF = '%2'";

    for (int i = 0; i < ui->lstCiudades->count(); ++i)
    {
        QListWidgetItem *item = ui->lstCiudades->item(i);

        QString sql = updateString.arg(item->checkState() == Qt::Checked ? 1 : 0)
                .arg(item->data(Qt::UserRole).toString());
        query.exec(sql);

        qDebug() << query.lastQuery() << query.lastError();

    }
    query.exec("COMMIT TRANSACTION");
}
