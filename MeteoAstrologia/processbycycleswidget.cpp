#include "processbycycleswidget.h"
#include "ui_processbycycleswidget.h"

processByCyclesWidget::processByCyclesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processByCyclesWidget),
    fechaModel(new QSqlTableModel),
    phase19Model(new QSqlTableModel),
    phase37Model(new QSqlTableModel),
    phase96Model(new QSqlTableModel),
    nPhaseModel(new QSqlTableModel),
    monthlyModel(new QSqlTableModel),
    dailyModel(new QSqlTableModel),
    astralDailyModel(new QSqlTableModel)
{
    ui->setupUi(this);

    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(doCalc()));


    connect(ui->phase19ListView, SIGNAL(clicked(QModelIndex)), this, SLOT(phaseSelected(QModelIndex)));
    connect(ui->phase37ListView, SIGNAL(clicked(QModelIndex)), this, SLOT(phaseSelected(QModelIndex)));
    connect(ui->phase96ListView, SIGNAL(clicked(QModelIndex)), this, SLOT(phaseSelected(QModelIndex)));
    connect(ui->nMonthListView, SIGNAL(clicked(QModelIndex)), this, SLOT(phaseSelected(QModelIndex)));

    connect(ui->phase19ListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(phaseMenu(QPoint)));
    connect(ui->phase37ListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(phaseMenu(QPoint)));
    connect(ui->phase96ListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(phaseMenu(QPoint)));
    connect(ui->nMonthListView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(phaseMenu(QPoint)));
    QStringList items;
    items << "Normal" << "Luna llena" << "Luna nueva" << "Equinoccios" << "Solsticios";
    ui->tipoFechaComboBox->addItems(items);

    fechaModel->setTable("estadotiempos_diarios"); // Modificacion de diego
//TODO: terminar aca
    phase19Model->setTable("estadotiempos_diarios");
    phase19Model->setSort(0, Qt::AscendingOrder);
    phase37Model->setTable("estadotiempos_diarios");
    phase37Model->setSort(0, Qt::AscendingOrder);
    phase96Model->setTable("estadotiempos_diarios");
    phase96Model->setSort(0, Qt::AscendingOrder);
    nPhaseModel->setTable("estadotiempos_diarios");
    nPhaseModel->setSort(0, Qt::AscendingOrder);
    monthlyModel->setTable("estadotiempos_mensuales");
    dailyModel->setTable("estadotiempos_diarios");
    astralDailyModel->setTable("view_estadotiempos");

    ui->phase19ListView->setModel(phase19Model);
    ui->phase37ListView->setModel(phase37Model);
    ui->phase96ListView->setModel(phase96Model);
    ui->nMonthListView->setModel(nPhaseModel);

    ui->astrologycalDaysTableView->setModel(astralDailyModel);
    ui->daysTableView->setModel(dailyModel);
    ui->monthTableView->setModel(monthlyModel);

    phase19Model->select();
    phase37Model->select();
    phase96Model->select();
    nPhaseModel->select();

    ui->diaComboBox->setModel(fechaModel);
    ui->diaComboBox->setModelColumn(1);    
    typeChanged("Normal");

    setWindowTitle("Proceso por Ciclos Lunares");

    ui->astrologycalDaysTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->daysTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->monthTableView->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->phase19ListView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->phase37ListView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->phase96ListView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->nMonthListView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->astrologycalDaysTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(astralMenu(QPoint)));
    connect(ui->daysTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(noaaMenu(QPoint)));
    connect(ui->monthTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(monthMenu(QPoint)));
    connect(ui->tipoFechaComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(typeChanged(QString)));


}

processByCyclesWidget::~processByCyclesWidget()
{
    delete fechaModel;
    delete phase19Model;
    delete phase37Model;
    delete phase96Model;
    delete monthlyModel;
    delete dailyModel;
    delete astralDailyModel;
    delete ui;
}

void processByCyclesWidget::typeChanged(QString type){
    QString filter;
    if(type == "Normal") filter = "tipo = 'normal'";
    if(type == "Luna llena") filter = "luna LIKE 'llena'";
    if(type == "Luna nueva") filter = "luna LIKE 'nueva'";
    if(type == "Equinoccios") filter = "tipo LIKE 'Equinoccio%'";
    if(type == "Solsticios") filter = "tipo LIKE 'Solsticio%'";
    fechaModel->setFilter(filter);
    fechaModel->select();
    while(fechaModel->canFetchMore()) fechaModel->fetchMore();
    int index = ui->diaComboBox->findText(MainWindow::instance()->getWorkingDate().toString("yyyy-MM-dd"), Qt::MatchStartsWith);
    ui->diaComboBox->setCurrentIndex(index);
}

void processByCyclesWidget::doCalc(){
    QString strdate = ui->diaComboBox->currentText();
    setWindowTitle(QString("Proceso por Ciclos Lunares").arg(strdate));
    QDate currentdate, tempdate;
    qDebug() << strdate;
    currentdate = QDateTime::fromString(strdate, "yyyy-MM-dd hh:mm:ss").date();
    phase19.clear();
    phase37.clear();
    phase96.clear();
    phaseN.clear();
    phase19month.clear();
    phase37month.clear();
    phase96month.clear();
    phaseNmonth.clear();

    qDebug() << currentdate;
    tempdate = currentdate;
    qDebug() << "init";
    while(tempdate < QDate::currentDate()){
        phase19 << tempdate.toString("yyyy-MM-dd");
        phase19month << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addYears(18.6);
    }
    qDebug() << "done 19 up";

    tempdate = currentdate;
    while(tempdate < QDate::currentDate()){
        phase96 << tempdate.toString("yyyy-MM-dd");
        phase96month << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addMonths((12*8) + 10);
    }
    qDebug() << "done 96 up";

    tempdate = currentdate;
    while(tempdate < QDate::currentDate()){
        phase37 << tempdate.toString("yyyy-MM-dd");
        phase37month << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addYears(37);
    }
    qDebug() << "done 37 up";

    tempdate = currentdate;
    while(tempdate < QDate::currentDate()){
        phaseN << tempdate.toString("yyyy-MM-dd");
        phaseNmonth << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addMonths(ui->nMonthSpinBox->value());
    }
    qDebug() << "done N up";

    tempdate = currentdate;
    while(tempdate > QDate(1700, 01, 01)){
        phase19 << tempdate.toString("yyyy-MM-dd");
        phase19month << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addYears(-18.6);
    }
    qDebug() << "done 19 down";

    tempdate = currentdate;
    while(tempdate > QDate(1700, 01, 01)){
        phase96 << tempdate.toString("yyyy-MM-dd");
        phase96month << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addMonths(-((12*8) + 10));
    }
    qDebug() << "done 96 down";

    tempdate = currentdate;
    while(tempdate > QDate(1700, 01, 01)){
        phase37 << tempdate.toString("yyyy-MM-dd");
        phase37month << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addYears(-37);
    }

    qDebug() << "done 37 down";

    tempdate = currentdate;
    while(tempdate > QDate(1700, 01, 01)){
        phaseN << tempdate.toString("yyyy-MM-dd");
        phaseNmonth << tempdate.toString("yyyy-MM");
        tempdate = tempdate.addMonths(-ui->nMonthSpinBox->value());
    }
    qDebug() << "done N up";
    int i;
    for(i = 0; i < phase19.count(); i++) phase19.replace(i, QString("(fecha LIKE '%1%')").arg(phase19.at(i)));
    for(i = 0; i < phase37.count(); i++) phase37.replace(i, QString("(fecha LIKE '%1%')").arg(phase37.at(i)));
    for(i = 0; i < phase96.count(); i++) phase96.replace(i, QString("(fecha LIKE '%1%')").arg(phase96.at(i)));
    for(i = 0; i < phaseN.count(); i++) phaseN.replace(i, QString("(fecha LIKE '%1%')").arg(phaseN.at(i)));

    for(i = 0; i < phase19month.count(); i++) phase19month.replace(i, QString("(fecha LIKE '%1%')").arg(phase19month.at(i)));
    for(i = 0; i < phase37month.count(); i++) phase37month.replace(i, QString("(fecha LIKE '%1%')").arg(phase37month.at(i)));
    for(i = 0; i < phase96month.count(); i++) phase96month.replace(i, QString("(fecha LIKE '%1%')").arg(phase96month.at(i)));
    for(i = 0; i < phaseNmonth.count(); i++) phaseNmonth.replace(i, QString("(fecha LIKE '%1%')").arg(phaseNmonth.at(i)));

    phase19Model->setFilter(phase19.join(" OR "));
    phase37Model->setFilter(phase37.join(" OR "));
    phase96Model->setFilter(phase96.join(" OR "));
    nPhaseModel->setFilter(phaseN.join(" OR "));

    qDebug() << "wash";
    phase19Model->select();
    qDebug() << phase19Model->query().lastQuery() << phase19Model->lastError();
    qDebug() << "wash";
    phase37Model->select();
    qDebug() << phase37Model->query().lastQuery() << phase37Model->lastError();
    qDebug() << "wash";
    phase96Model->select();
    qDebug() << phase96Model->query().lastQuery() << phase96Model->lastError();

    nPhaseModel->select();
    qDebug() << nPhaseModel->query().lastQuery() << nPhaseModel->lastError();
}

void processByCyclesWidget::phaseSelected(QModelIndex index){
    QString filter;
    qDebug() << "phase selected";

    QString datem = QString("fecha LIKE '%1%'").arg(index.data().toString().left(4+1+2));
    if(ui->phase19ListView->hasFocus()){
        monthlyModel->setFilter(phase19month.join(" OR "));
        dailyModel->setFilter(datem);
        astralDailyModel->setFilter(datem);
    }
    if(ui->phase37ListView->hasFocus()){
        monthlyModel->setFilter(phase37month.join(" OR "));
        dailyModel->setFilter(datem);
        astralDailyModel->setFilter(datem);
    }
    if(ui->phase96ListView->hasFocus()){
        monthlyModel->setFilter(phase96month.join(" OR "));
        dailyModel->setFilter(datem);
        astralDailyModel->setFilter(datem);
    }

    if(ui->nMonthListView->hasFocus()){
        monthlyModel->setFilter(phaseNmonth.join(" OR "));
        dailyModel->setFilter(datem);
        astralDailyModel->setFilter(datem);
    }

    monthlyModel->select();
    dailyModel->select();
    astralDailyModel->select();
    qDebug() << monthlyModel->query().lastQuery() << monthlyModel->query().lastError();
    qDebug() << dailyModel->query().lastQuery() << dailyModel->query().lastError();
    qDebug() << astralDailyModel->query().lastQuery() << astralDailyModel->query().lastError();

    ui->monthTableView->resizeColumnsToContents();
    ui->daysTableView->resizeColumnsToContents();
    ui->astrologycalDaysTableView->resizeColumnsToContents();
}

void processByCyclesWidget::astralMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->astrologycalDaysTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->astrologycalDaysTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->astrologycalDaysTableView->rootIndex();
            for(int i = 0; i < ui->astrologycalDaysTableView->model()->rowCount(); i++){
                index = ui->astrologycalDaysTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
    }
}

void processByCyclesWidget::noaaMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->daysTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->daysTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->daysTableView->rootIndex();
            for(int i = 0; i < ui->daysTableView->model()->rowCount(); i++){
                index = ui->daysTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
    }
}

void processByCyclesWidget::monthMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->monthTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->monthTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->monthTableView->rootIndex();
            for(int i = 0; i < ui->monthTableView->model()->rowCount(); i++){
                index = ui->monthTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
    }
}

void processByCyclesWidget::phaseMenu(QPoint pt)
{
    QListView *view = dynamic_cast<QListView*>(sender());
    QMenu menu;
    QPoint gpt = view->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = view->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = view->rootIndex();
            for(int i = 0; i < view->model()->rowCount(); i++){
                index = view->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        }
    }
}

