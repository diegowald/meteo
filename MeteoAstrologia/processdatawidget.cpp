#include "processdatawidget.h"
#include "ui_processdatawidget.h"
#include "aspectsdialog.h"
#include "weatherdialog.h"

processDataWidget::processDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processDataWidget)
{
    ui->setupUi(this);
    setWindowTitle("Procesar datos guardados");
    this->dataMeaning = new dataProcessor();

    ui->finishDateEdit->setDate(QDate::currentDate());
    connect(ui->addAspectButton, SIGNAL(clicked()), this, SLOT(addAspects()));
    connect(ui->modAspectButton, SIGNAL(clicked()), this, SLOT(modAspects()));
    connect(ui->delAspectButton, SIGNAL(clicked()), this, SLOT(delAspects()));

    connect(ui->addWeatherButton, SIGNAL(clicked()), this, SLOT(addWeather()));
    connect(ui->modWeatherButton, SIGNAL(clicked()), this, SLOT(modWeather()));
    connect(ui->delWeatherButton, SIGNAL(clicked()), this, SLOT(delWeather()));

    connect(ui->processAspectButton, SIGNAL(clicked()), this, SLOT(processAspect()));
    connect(ui->processWeatherButton, SIGNAL(clicked()), this, SLOT(processWeather()));
    connect(this->dataMeaning, SIGNAL(finish()), this, SLOT(refreshResult()));
    model = new QSqlTableModel();
    model->setTable("processedWeather");
    ui->tableView->setModel(model);
    refresh();

}

processDataWidget::~processDataWidget()
{
    delete ui;
    delete dataMeaning;
}

void processDataWidget::refresh(){
    refreshWeather();
    refreshAspect();
}

void processDataWidget::delAspects(){
    QModelIndexList indexes = ui->aspectTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    metAstro::aspectParameter *asp = this->aspects.takeAt(indexes.at(0).row());
    this->dataMeaning->delAspect(asp);
    delete asp;
    refreshAspect();
}

void processDataWidget::modAspects(){
    QModelIndexList indexes = ui->aspectTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    aspectsDialog *form = new aspectsDialog(this->aspects.at(indexes.at(0).row()));
    connect(form, SIGNAL(aspectsMod(aspectParameter*)), this, SLOT(aspectsModif(aspectParameter*)));
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void processDataWidget::addAspects(){
    aspectsDialog *form = new aspectsDialog();
    connect(form, SIGNAL(aspectsAdd(aspectParameter*)), this, SLOT(aspectsAdded(aspectParameter*)));
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void processDataWidget::delWeather(){
    QModelIndexList indexes = ui->weatherTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    this->weathers.removeAt(indexes.at(0).row());
    refreshWeather();
}
void processDataWidget::modWeather(){
    QModelIndexList indexes = ui->weatherTableWidget->selectionModel()->selectedIndexes();
    if(indexes.isEmpty()) return;
    weatherDialog *form = new weatherDialog(this->weathers.at(indexes.at(0).row()));
    connect(form, SIGNAL(weatherMod(weatherParameter*)), this, SLOT(weatherModif(weatherParameter*)));
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void processDataWidget::addWeather(){
    weatherDialog *form = new weatherDialog();
    connect(form, SIGNAL(weatherAdd(weatherParameter*)), this, SLOT(weatherAdded(weatherParameter*)));
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void processDataWidget::aspectsAdded(metAstro::aspectParameter* aspect){
    this->aspects.append(aspect);
    this->dataMeaning->addAspect(aspect);
    refreshAspect();
}
void processDataWidget::aspectsModif(metAstro::aspectParameter* aspect){
    qDebug() << "aspectsModif";
    this->dataMeaning->modAspect(aspect);
    refreshAspect();
}

void processDataWidget::weatherAdded(metAstro::weatherParameter* weather){
    this->weathers << weather;
    refreshWeather();
}
void processDataWidget::weatherModif(metAstro::weatherParameter* weather){
    refreshWeather();
}

void processDataWidget::refreshAspect(){
    qDebug() << "refreshAspect";
    QStringList headers;
    headers << "Planeta 1" << "Aspecto" << "Planeta2" << "Grados" << "Tolerancia" << "Minutos" << "Tolerancia" << "Segundos" << "Tolerancia";
    ui->aspectTableWidget->clear();
    ui->aspectTableWidget->setColumnCount(0);
    ui->aspectTableWidget->setRowCount(0);
    ui->aspectTableWidget->setColumnCount(9);
    ui->aspectTableWidget->setRowCount(this->aspects.count());
    ui->aspectTableWidget->setHorizontalHeaderLabels(headers);
    QString planet1, planet2, aspect;
    metAstro::aspectParameter *asp;
    for(int i = 0; i < this->aspects.count(); ++i){
        qDebug() << "aspect index: " << i;
        asp = this->aspects.at(i);
        planet1 = dataMeaning->retrievePlanet1(asp);
        planet2 = dataMeaning->retrievePlanet2(asp);
        aspect = dataMeaning->retrieveAspect(asp);
        ui->aspectTableWidget->setItem(i, 0, new QTableWidgetItem(planet1));
        ui->aspectTableWidget->setItem(i, 1, new QTableWidgetItem(aspect));
        ui->aspectTableWidget->setItem(i, 2, new QTableWidgetItem(planet2));
        ui->aspectTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(asp->grade)));
        ui->aspectTableWidget->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(asp->gradeTolerance)));
        ui->aspectTableWidget->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(asp->minutes)));
        ui->aspectTableWidget->setItem(i, 6, new QTableWidgetItem(QString("%1").arg(asp->minutesTolerance)));
        ui->aspectTableWidget->setItem(i, 7, new QTableWidgetItem(QString("%1").arg(asp->seconds)));
        ui->aspectTableWidget->setItem(i, 8, new QTableWidgetItem(QString("%1").arg(asp->secondsTolerance)));
    };

}
void processDataWidget::refreshWeather(){
    QStringList headers;
    headers << "Fenomeno" << "Valor" << "Tolerancia";
    ui->weatherTableWidget->clear();
    ui->weatherTableWidget->setColumnCount(3);
    ui->weatherTableWidget->setRowCount(this->weathers.count());
    ui->weatherTableWidget->setHorizontalHeaderLabels(headers);
    metAstro::weatherParameter *wea;
    for(int i = 0; i < this->weathers.count(); ++i){
        wea = this->weathers.at(i);
        qDebug() << wea->parameter;
        ui->weatherTableWidget->setItem(i, 0, new QTableWidgetItem(wea->parameter));
        ui->weatherTableWidget->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(wea->value)));
        ui->weatherTableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(wea->tolerance)));
    };
}

void processDataWidget::processAspect(){
    this->dataMeaning->setInitDate(ui->initDateEdit->date());
    this->dataMeaning->setFinishDate(ui->finishDateEdit->date());
    this->dataMeaning->processAspects();
}
void processDataWidget::processWeather(){
}

void processDataWidget::refreshResult(){
    model->select();
}
