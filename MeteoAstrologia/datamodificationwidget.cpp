#include "datamodificationwidget.h"
#include "ui_datamodificationwidget.h"

#include "signsdialog.h"
#include "aspectsdialog.h"
#include "cuadrantesdialog.h"
#include "housesdialog.h"
#include "positionsdialog.h"

dataModificationWidget::dataModificationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataModificationWidget)
{
    usaf = "";
    ui->setupUi(this);
    dataMeaning = new dataProcessor();
    ui->typeComboBox->addItem("Normal", "normal");
    ui->typeComboBox->addItem("Sisigia de Equinoccio", "%Equinoccio%");
    ui->typeComboBox->addItem("Sisigia de Solsticio", "%Solsticio%");
    ui->typeComboBox->addItem("Sisiga Mensual", "mensual");
    changeType();
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(closed()));
    connect(ui->typeComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeType()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(eraseData()));

    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadData()));

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);
    /*connect(ui->aspectsAddButton, SIGNAL(clicked()), this, SLOT(addAspect()));
    connect(ui->aspectsModButton, SIGNAL(clicked()), this, SLOT(modAspect()));
    connect(ui->aspectsDelButton, SIGNAL(clicked()), this, SLOT(delAspect()));

    connect(ui->cuadrantsAddButton, SIGNAL(clicked()), this, SLOT(addQuadrant()));
    connect(ui->cuadrantsModButton, SIGNAL(clicked()), this, SLOT(modQuadrant()));
    connect(ui->cuadrantsDelButton, SIGNAL(clicked()), this, SLOT(delQuadrant()));

    connect(ui->singsAddButton, SIGNAL(clicked()), this, SLOT(addSign()));
    connect(ui->singsModButton, SIGNAL(clicked()), this, SLOT(modSign()));
    connect(ui->singsDelButton, SIGNAL(clicked()), this, SLOT(delSign()));

    connect(ui->positionAddButton, SIGNAL(clicked()), this, SLOT(addPosition()));
    connect(ui->positionModButton, SIGNAL(clicked()), this, SLOT(modPosition()));
    connect(ui->positionDelButton, SIGNAL(clicked()), this, SLOT(delPosition()));

    connect(ui->housesAddButton, SIGNAL(clicked()), this, SLOT(addHouses()));
    connect(ui->housesModButton, SIGNAL(clicked()), this, SLOT(modHouses()));
    connect(ui->housesDelButton, SIGNAL(clicked()), this, SLOT(delHouses()));*/
}

dataModificationWidget::~dataModificationWidget()
{
    delete ui;
}

void dataModificationWidget::changeType(){
    QSqlQuery *query = new QSqlQuery();
    ui->dateComboBox->clear();
    query->exec(QString("SELECT DISTINCT fecha FROM estadotiempos_diarios WHERE tipo LIKE '%1' ORDER BY fecha").arg(ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString())); // Modificacion de diego
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        ui->dateComboBox->addItem(query->record().field("fecha").value().toString());
    }
    delete query;
}

void dataModificationWidget::accepted(){
    eraseData();
    saveData();
    ui->filterGroupBox->setEnabled(true);
    ui->dataGroupBox->setEnabled(false);
}
void dataModificationWidget::closed(){
    ui->filterGroupBox->setEnabled(true);
    ui->dataGroupBox->setEnabled(false);
}

void dataModificationWidget::loadData(){
    ui->filterGroupBox->setEnabled(false);
    ui->dataGroupBox->setEnabled(true);
    aspects.clear();
    positions.clear();
    houses.clear();
    signs.clear();
    quadrants.clear();

    QSqlQuery *query = new QSqlQuery();

    //weather
    query->exec(QString("SELECT * FROM estadotiempos_diarios WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));  // Modificacion de diego
    query->next();
    /*maxima	minima	vientovel	direccionviento	precipitacion	mil500	observaciones*/
    ui->data1000500SpinBox->setValue(query->record().field("mil500").value().toInt());
    ui->tempMaxDoubleSpinBox->setValue(query->record().field("maxima").value().toDouble());
    ui->tempMinDoubleSpinBox->setValue(query->record().field("minima").value().toDouble());
    ui->precipitacionSpinBox->setValue(query->record().field("precipitacion").value().toDouble());
    ui->dirVientoSpinBox->setValue(query->record().field("direccionviento").value().toInt());
    ui->velVientoDoubleSpinBox->setValue(query->record().field("vientovel").value().toInt());
    ui->observacionTextEdit->setPlainText(query->record().field("observaciones").value().toString());

    ui->kindComboBox->setCurrentIndex(ui->kindComboBox->findText(query->record().field("tipo").value().toString(), Qt::MatchFixedString));

    delete query;

    refresh();
}

void dataModificationWidget::saveData(){
    QDateTime span;
    span = QDateTime::fromString(ui->kindComboBox->currentText(), "yyyy-MM-dd hh:mm:ss");
    QSqlQuery *query = new QSqlQuery();

    // Modificacion de diego
    query->exec(QString("UPDATE estadotiempos_diarios SET maxima = %1, minima = %2, vientovel= %3, direccionviento = %4, precipitacion = %5, mil500 = %6, observaciones = %7 "
                        " WHERE fecha = '%8' AND USAF = '%9'")
                .arg(ui->tempMaxDoubleSpinBox->value())
                .arg(ui->tempMinDoubleSpinBox->value())
                .arg(ui->velVientoDoubleSpinBox->value())
                .arg(ui->dirVientoSpinBox->value())
                .arg(ui->precipitacionSpinBox->value())
                .arg(ui->data1000500SpinBox->value())
                .arg(ui->observacionTextEdit->toPlainText())
                .arg(ui->dateComboBox->currentText())
                .arg(usaf));
    qDebug() << query->lastQuery() << query->lastError();

    delete query;

}

void dataModificationWidget::eraseData(){
    QSqlQuery *query = new QSqlQuery();

    query->exec(QString("DELETE FROM estadotiempos_diarios WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));  // Modificacion de diego
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM aspectariums WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM casas WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM signos WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM cuadrantes WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();

    query->exec(QString("DELETE FROM posiciones WHERE fecha = '%1'").arg(ui->dateComboBox->currentText()));
    qDebug() << query->lastQuery() << query->lastError();
    delete query;
}

void dataModificationWidget::refresh(){
}

void dataModificationWidget::on_cboEstacion_currentTextChanged(const QString &arg1)
{
    usaf = arg1;
}
