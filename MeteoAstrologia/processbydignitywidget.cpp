#include "processbydignitywidget.h"
#include "ui_processbydignitywidget.h"
#include "dignitydialog.h"

processByDignityWidget::processByDignityWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processByDignityWidget),
    fechaModel(new QSqlTableModel),
    resultModel(new QSqlTableModel),
    noaaResultModel(new QSqlTableModel),
    information(new dataProcessor)
{
    ui->setupUi(this);
    QStringList items;

    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(doCalc()));
    connect(ui->dignityFilterButton, SIGNAL(clicked()), this, SLOT(calcDignity()));

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(del()));

    items << "Normal" << "Luna llena" << "Luna nueva" << "Equinoccios" << "Solsticios";
    ui->tipoComboBox->addItems(items);
    fechaModel->setTable("view_estadotiempos");
    fechaModel->select();
    //resultModel->setTable("validweather");
    resultModel->setTable("view_estadotiempos");
    noaaResultModel->setTable("estadotiempos_diarios");
    ui->tableView->setModel(resultModel);
    ui->noaaTableView->setModel(noaaResultModel);
    ui->fechaComboBox->setModel(fechaModel);
    ui->fechaComboBox->setModelColumn(0);
    dateTypeChanged("Normal");
    setWindowTitle("Procesar por Dignidades");
    connect(ui->tipoComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(dateTypeChanged(QString)));

    ui->noaaTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->noaaTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(noaaMenu(QPoint)));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(dailyMenu(QPoint)));

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);
}

processByDignityWidget::~processByDignityWidget()
{
    delete fechaModel;
    delete resultModel;
    delete noaaResultModel;
    delete ui;
    delete information;
}

void processByDignityWidget::addDignity(metAstro::dignityParam &param){
    dignityList << param;
    refresh();
}

void processByDignityWidget::del(){
    qDebug() << "del dignity";
    QModelIndexList indexes = ui->dignityTableWidget->selectionModel()->selectedRows(0);
    if(indexes.isEmpty()) return;
    dignityList.removeAt(indexes.at(0).row());
    refresh();
}
void processByDignityWidget::add(){
    dignityDialog *form = new dignityDialog();
    form->setWindowModality(Qt::ApplicationModal);
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(addDignity(metAstro::dignityParam&)), this, SLOT(addDignity(metAstro::dignityParam&)));
    form->show();
}

void processByDignityWidget::doCalc(){
    QString filter, filterTemp;
    //QStringList filterlist;
    metAstro::dignityParam param;

    foreach(param, dignityList){
       int sign = information->getSignByDignity(param);
       if(sign == 0) continue;
       if(sign > 12){
           int sign2 = sign / 100;
           sign = sign - (sign2 * 100);
           filterTemp = QString("(planeta = %1 AND (signo = %2 OR signo = %3))").arg(param.planet).arg(sign).arg(sign2);
       }else{
           filterTemp = QString("(planeta = %1 AND signo = %2)").arg(param.planet).arg(sign);
       };
       if(filter == ""){
           filter = QString("SELECT fecha FROM posiciones WHERE fecha IN (SELECT DISTINCT fecha FROM posiciones WHERE %1)").arg(filterTemp);
       }else{
           filter = QString("SELECT fecha FROM posiciones WHERE fecha IN (%1) AND fecha IN (SELECT DISTINCT fecha FROM posiciones WHERE %2)").arg(filter).arg(filterTemp);
       };
   };


   /* foreach(param, dignityList){
        int sign = information->getSignByDignity(param);
        if(sign == 0) continue;
        if(sign > 12){
            int sign2 = sign / 100;
            sign = sign - (sign2 * 100);
            filterlist << QString("(planeta = %1 AND (signo = %2 OR signo = %3))").arg(param.planet).arg(sign).arg(sign2);
        }else{
            filterlist << QString("(planeta = %1 AND signo = %2)").arg(param.planet).arg(sign);
        };
    };

    filter = QString("SELECT DISTINCT fecha FROM posiciones WHERE %1").arg(filterlist.join(" AND "));*/
    resultModel->setFilter(QString("fecha IN (%1)").arg(filter));
    resultModel->select();
    noaaResultModel->setFilter(QString("fecha IN (%1) AND usaf = '%2'")
                               .arg(filter.replace(7, 5, "strftime('%Y-%m-%d', fecha)"))
                               .arg(usaf()));
    noaaResultModel->select();
    qDebug() << resultModel->query().lastQuery() << resultModel->lastError();
    qDebug() << noaaResultModel->query().lastQuery() << noaaResultModel->lastError();
    ui->tableView->resizeColumnsToContents();
    ui->noaaTableView->resizeColumnsToContents();
}

void processByDignityWidget::refresh(){
    ui->dignityTableWidget->clear();
    ui->dignityTableWidget->setColumnCount(2);
    ui->dignityTableWidget->setRowCount(dignityList.count());
    ui->dignityTableWidget->setHorizontalHeaderLabels(QStringList() << "Planeta" << "Dignidad");

    for(int i = 0; i < dignityList.count(); i++){
        metAstro::dignityParam param = dignityList.at(i);
        ui->dignityTableWidget->setItem(i, 0, new QTableWidgetItem(utils::planetName(param.planet)));
        ui->dignityTableWidget->setItem(i, 1, new QTableWidgetItem(information->getDignityName(param.dignity)));
    };
}

void processByDignityWidget::calcDignity(){
    QString date = ui->fechaComboBox->currentText();
    QSqlQuery query;

    dignityList.clear();
    query.exec(QString("SELECT * FROM posiciones WHERE fecha = '%1'").arg(date));
    while(query.next()){
        int dignities, planet;
        planet = query.record().field("planeta").value().toInt();
        dignities = information->getDignity(planet, query.record().field("longitude").value().toDouble());
        if(dignities & metAstro::Rules){
            metAstro::dignityParam param;
            param.planet = planet;
            param.dignity = metAstro::Rules;
            dignityList << param;
        };
        if(dignities & metAstro::Exaltation){
            metAstro::dignityParam param;
            param.planet = planet;
            param.dignity = metAstro::Exaltation;
            dignityList << param;
        };
        if(dignities & metAstro::Detriment){
            metAstro::dignityParam param;
            param.planet = planet;
            param.dignity = metAstro::Detriment;
            dignityList << param;
        };
        if(dignities & metAstro::Fall){
            metAstro::dignityParam param;
            param.planet = planet;
            param.dignity = metAstro::Fall;
            dignityList << param;
        };
    };
    refresh();
}

void processByDignityWidget::dateTypeChanged(QString value){
    QString filter;
    if(value == "Normal") filter = "tipo = 'normal'";
    if(value == "Luna llena") filter = "luna LIKE 'llena'";
    if(value == "Luna nueva") filter = "luna LIKE 'nueva'";
    if(value == "Equinoccios") filter = "tipo LIKE 'Equinoccio%'";
    if(value == "Solsticios") filter = "tipo LIKE 'Solsticio%'";
    fechaModel->setFilter(filter);
    fechaModel->select();
    while(fechaModel->canFetchMore()){
        fechaModel->fetchMore();
    };
    qDebug() << MainWindow::instance()->getWorkingDate().toString("yyyy-MM-dd");
    int index = ui->fechaComboBox->findText(MainWindow::instance()->getWorkingDate().toString("yyyy-MM-dd"), Qt::MatchContains);
    qDebug() << index;
    ui->fechaComboBox->setCurrentIndex(index);
    //qDebug() << fechaModel->query().lastQuery();
}

void processByDignityWidget::dailyMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->tableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        //QMessageBox::warning(this, tr("wo"), result->text(), QMessageBox::Ok);
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->tableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->tableView->rootIndex();
            for(int i = 0; i < ui->tableView->model()->rowCount(); i++){
                index = ui->tableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
    };
}

void processByDignityWidget::noaaMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->noaaTableView->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        //QMessageBox::warning(this, tr("wo"), result->text(), QMessageBox::Ok);
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->noaaTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->noaaTableView->rootIndex();
            for(int i = 0; i < ui->noaaTableView->model()->rowCount(); i++){
                index = ui->noaaTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
    };
}

QString processByDignityWidget::usaf() const
{
    return ui->cboEstacion->currentText();
}
