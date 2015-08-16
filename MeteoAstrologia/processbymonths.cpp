#include "processbymonths.h"
#include "ui_processbymonths.h"

processByMonths::processByMonths(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processByMonths),
    positionModel(new QSqlTableModel),
    aspectsModel(new QSqlTableModel),
    quadrantsModel(new QSqlTableModel),
    signsModel(new QSqlTableModel),
    housesModel(new QSqlTableModel),
    weatherModel(new QSqlTableModel),
    resultModel(new QSqlQueryModel),
    noaaModel(new QSqlTableModel)
{
    ui->setupUi(this);

    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(doCalc()));
    connect(ui->dayResultTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(dayChange(QModelIndex)));
    connect(ui->noaaResultTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(dayChange(QModelIndex)));
    connect(ui->monthResultTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(weatherChange(QModelIndex)));

    ui->positionTableView->setModel(positionModel);
    ui->quadrantsTableView->setModel(quadrantsModel);
    ui->AspectsTableView->setModel(aspectsModel);
    ui->signsTableView->setModel(signsModel);
    ui->housesTableView->setModel(housesModel);
    ui->monthResultTableView->setModel(resultModel);
    ui->noaaResultTableView->setModel(noaaModel);
    ui->dayResultTableView->setModel(weatherModel);

    positionModel->setTable("view_posiciones");
    aspectsModel->setTable("view_aspectaiums");
    quadrantsModel->setTable("view_cuadrantes");
    signsModel->setTable("view_signos");
    housesModel->setTable("view_casas");
    weatherModel->setTable("view_estadotiempos");
    noaaModel->setTable("estadotiempos_diarios");

    ui->mesSpinBox->setValue(MainWindow::instance()->getWorkingDate().date().month());

    ui->monthResultTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->dayResultTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->noaaResultTableView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->monthResultTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(monthMenu(QPoint)));
    connect(ui->dayResultTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(dayMenu(QPoint)));
    connect(ui->noaaResultTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(noaaMenu(QPoint)));

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);
}

processByMonths::~processByMonths()
{
    delete positionModel;
    delete aspectsModel;
    delete quadrantsModel;
    delete signsModel;
    delete housesModel;
    delete weatherModel;
    delete resultModel;
    delete noaaModel;
    delete ui;
}

void processByMonths::weatherChange(QModelIndex index){
    QModelIndexList indexes = ui->monthResultTableView->selectionModel()->selectedRows(0);
    if(indexes.isEmpty()) return;
    //aspects.removeAt(indexes.at(0).row());
    QModelIndex dato = indexes.at(0).sibling(indexes.at(0).row(), 0);
    weatherModel->setFilter(QString("fecha LIKE '%1-%'").arg(dato.data().toString()));
    weatherModel->select();
    noaaModel->setFilter(QString("fecha LIKE '%1-%' AND usaf = '%2'").arg(dato.data().toString())
                         .arg(usaf()));
    noaaModel->select();
    qDebug()<< noaaModel->query().lastQuery() << noaaModel->lastError();
    ui->dayResultTableView->resizeColumnsToContents();
    ui->noaaResultTableView->resizeColumnsToContents();
}

void processByMonths::dayChange(QModelIndex index){
    QModelIndex dato = index.sibling(index.row(), 0);
    positionModel->setFilter(QString("fecha LIKE '%1%'").arg(dato.data().toString()));;
    aspectsModel->setFilter(QString("fecha LIKE '%1%'").arg(dato.data().toString()));;
    quadrantsModel->setFilter(QString("fecha LIKE '%1%'").arg(dato.data().toString()));;
    signsModel->setFilter(QString("fecha LIKE '%1%'").arg(dato.data().toString()));;
    housesModel->setFilter(QString("fecha LIKE '%1%'").arg(dato.data().toString()));;
    positionModel->select();
    aspectsModel->select();
    quadrantsModel->select();
    signsModel->select();
    housesModel->select();
    ui->positionTableView->resizeColumnsToContents();
    ui->AspectsTableView->resizeColumnsToContents();
    ui->quadrantsTableView->resizeColumnsToContents();
    ui->signsTableView->resizeColumnsToContents();
    ui->housesTableView->resizeColumnsToContents();
}

void processByMonths::noaaChange(QModelIndex index)
{
    QModelIndexList indexes = ui->noaaResultTableView->selectionModel()->selectedRows(0);
    if(indexes.isEmpty()) return;
    QModelIndex dato = indexes.at(0).sibling(indexes.at(0).row(), 0);

    positionModel->setFilter(QString("fecha LIKE '%1-%'").arg(dato.data().toString()));;
    aspectsModel->setFilter(QString("fecha LIKE '%1-%'").arg(dato.data().toString()));;
    quadrantsModel->setFilter(QString("fecha LIKE '%1-%'").arg(dato.data().toString()));;
    signsModel->setFilter(QString("fecha LIKE '%1-%'").arg(dato.data().toString()));;
    housesModel->setFilter(QString("fecha LIKE '%1-%'").arg(dato.data().toString()));;
    positionModel->select();
    aspectsModel->select();
    quadrantsModel->select();
    signsModel->select();
    housesModel->select();
}

void processByMonths::doCalc(){
    QSqlQuery query;
    double rainmax, rainmin;
    rainmax = ui->lluviasDoubleSpinBox->value() + ui->toleranciaDoubleSpinBox->value();
    rainmin = ui->lluviasDoubleSpinBox->value() - ui->toleranciaDoubleSpinBox->value();
    resultModel->setQuery(QString("SELECT strftime('%Y-%m', fecha) as result, strftime('%m', fecha) as month FROM estadotiempos_mensuales WHERE month = '%1' AND precipitaciones >= %2 AND precipitaciones <=%3 AND usaf = '%4' ORDER BY result")
                          .arg(QString("%1")
                               .arg(ui->mesSpinBox->value()).rightJustified(2, '0'))
                          .arg(rainmin)
                          .arg(rainmax)
                          .arg(usaf()));
    qDebug() << resultModel->query().lastQuery() << resultModel->lastError();
}

void processByMonths::refresh(){
}

void processByMonths::monthMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->monthResultTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->monthResultTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString() + "-01", "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->monthResultTableView->rootIndex();
            for(int i = 0; i < ui->monthResultTableView->model()->rowCount(); i++){
                index = ui->monthResultTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString() + "-01", "yyyy-MM-dd")));
            }
        }
    }
}

void processByMonths::dayMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->dayResultTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        //QMessageBox::warning(this, tr("wo"), result->text(), QMessageBox::Ok);
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->dayResultTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->dayResultTableView->rootIndex();
            for(int i = 0; i < ui->dayResultTableView->model()->rowCount(); i++){
                index = ui->dayResultTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
    }
}

void processByMonths::noaaMenu(QPoint pt)
{
    QMenu menu;
    QPoint gpt = ui->noaaResultTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->noaaResultTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->dayResultTableView->rootIndex();
            for(int i = 0; i < ui->noaaResultTableView->model()->rowCount(); i++){
                index = ui->noaaResultTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
    }
}

QString processByMonths::usaf() const
{
    return ui->cboEstacion->currentText();
}
