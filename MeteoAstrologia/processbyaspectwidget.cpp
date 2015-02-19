#include "processbyaspectwidget.h"
#include "ui_processbyaspectwidget.h"

processByAspectWidget::processByAspectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processByAspectWidget),
    information(new dataProcessor)
{
    ui->setupUi(this);
    setWindowTitle("Procesar por Aspectos");

    QSqlQuery query;
    query.exec("CREATE TEMPORARY TABLE IF NOT EXISTS pedro (fecha     DATESTAMP        NOT NULL,"
               "planeta1   SHORT            NOT NULL,"
               "signo1     SHORT            NOT NULL,"
               "planeta2   SHORT            NOT NULL,"
               "signo2     SHORT            NOT NULL"
               ");");
    qDebug() << query.lastQuery() << query.lastError();
    query.exec("DELETE FROM pedro WHERE 1 = 1");
    qDebug() << query.lastQuery() << query.lastError();

    astroModel = new QSqlTableModel();
    dairyModel = new QSqlTableModel();
    signModel = new QSqlTableModel();
    ui->dairyTableView->setModel(dairyModel);
    ui->astroTableView->setModel(astroModel);
    ui->occurenciasTableView->setModel(signModel);

    dairyModel->setTable("estadotiempos_diarios");
    astroModel->setTable("view_estadotiempos");
    signModel->setTable("pedro");

    refreshResult();

    connect(ui->addlButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->dellButton, SIGNAL(clicked()), this, SLOT(del()));
    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(doCalc()));

    ui->dairyTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->astroTableView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->dairyTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(noaaMenu(QPoint)));
    connect(ui->astroTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(daysMenu(QPoint)));
}

processByAspectWidget::~processByAspectWidget()
{
    delete ui;
    delete information;
}

void processByAspectWidget::add(){
    aspectsDialog *form = new aspectsDialog();
    form->setWindowModality(Qt::ApplicationModal);
    form->setAttribute(Qt::WA_DeleteOnClose);
    connect(form, SIGNAL(aspectsAdd(metAstro::aspectParameter*)), this, SLOT(aspectsAdded(metAstro::aspectParameter*)));
    form->show();
}

void processByAspectWidget::del(){
    qDebug() << "del aspects";
    QModelIndexList indexes = ui->aspectTableWidget->selectionModel()->selectedRows(0);
    if(indexes.isEmpty()) return;
    aspects.removeAt(indexes.at(0).row());
    refreshAspects();
}

void processByAspectWidget::aspectsAdded(metAstro::aspectParameter *asp){
    aspects << *(asp);
    refreshAspects();
}

void processByAspectWidget::refreshAspects(){
    ui->aspectTableWidget->clear();
    ui->aspectTableWidget->setColumnCount(3);
    ui->aspectTableWidget->setRowCount(aspects.count());
    ui->aspectTableWidget->setHorizontalHeaderLabels(QStringList() << "Planeta" << "Planeta" << "Aspecto");

    for(int i = 0; i < aspects.count(); i++){
        metAstro::aspectParameter param = aspects.at(i);
        qDebug() << param.planet1;
        ui->aspectTableWidget->setItem(i, 0, new QTableWidgetItem(utils::planetName(param.planet1)));
        ui->aspectTableWidget->setItem(i, 1, new QTableWidgetItem(utils::planetName(param.planet2)));
        ui->aspectTableWidget->setItem(i, 2, new QTableWidgetItem(utils::aspectName(param.aspect)));
    };
}

void processByAspectWidget::doCalc(){
    ui->filterButton->setText("Buscando...");
    ui->filterButton->setEnabled(false);
    //ui->datesList->clear();
    qApp->processEvents();
    information->clearWeather();
    information->setAspects(true);
    information->setStrongAspects(true);
    for(int i = 0; i < aspects.count(); i++){
        metAstro::aspectParameter *param = &(aspects[i]);
        information->addAspect(param);
    };
    information->processAspects();
    //QList<QDateTime> result = information->getMatchDates();
    /*for(int i = 0; i < result.count(); i++){
        qDebug() << result.at(i).toString();
        ui->datesList->addItem(result.at(i).toString("yyyy-MM-dd hh:mm:ss"));
    };*/

    //ui->fechasLabel->setText(QString("Fechas: %1 items").arg(result.count()));

    //information->processResults();

    refreshResult();
    ui->filterButton->setText("Filtrar");
    ui->filterButton->setEnabled(true);
}

void processByAspectWidget::refreshResult(){
    ui->filterButton->setText("Buscando...");
    ui->filterButton->setEnabled(false);
    QList<QDateTime> result = information->getMatchDates();
    QDateTime q;
    QStringList daily, astro;
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION");
    foreach(q, result){
        daily << QString("(fecha = '%1')").arg(q.toString("yyyy-MM-dd"));
        astro << QString("(fecha = '%1')").arg(q.toString("yyyy-MM-dd hh:mm:ss"));

        QString planeta1, planeta2, signo1, signo2;
        metAstro::aspectParameter param;
        foreach(param, aspects){
            query.exec(QString("SELECT * FROM posiciones WHERE fecha = '%1' AND (planeta = %2 OR planeta = %3)").arg(q.toString("yyyy-MM-dd hh:mm:ss")).arg(param.planet1).arg(param.planet2));
            query.next();
            planeta1 = utils::planetName(query.record().field("planeta").value().toInt());
            signo1 = utils::zodiacName(query.record().field("signo").value().toInt());
            query.next();
            planeta2 = utils::planetName(query.record().field("planeta").value().toInt());
            signo2 = utils::zodiacName(query.record().field("signo").value().toInt());

            query.exec(QString("INSERT INTO pedro (fecha, planeta1, signo1, planeta2, signo2) VALUES ('%1', '%2', '%3', '%4', '%5')")
                       .arg(q.toString("yyyy-MM-dd hh:mm:ss"))
                       .arg(planeta1)
                       .arg(signo1)
                       .arg(planeta2)
                       .arg(signo2));
        };
    };
    query.exec("END TRANSACTION");

    astroModel->setFilter(astro.join(" OR "));
    dairyModel->setFilter(daily.join(" OR "));
    astroModel->select();
    dairyModel->select();
    signModel->select();
    qDebug()<< astroModel->lastError();
    qDebug() << dairyModel->lastError();
    qDebug() << signModel->lastError();
    ui->filterButton->setText("Filtrar");
    ui->filterButton->setEnabled(true);
}

void processByAspectWidget::noaaMenu(QPoint val){
    QMenu menu;
    QPoint gpt = ui->dairyTableView->mapToGlobal(val);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        //QMessageBox::warning(this, tr("wo"), result->text(), QMessageBox::Ok);
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->dairyTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->dairyTableView->rootIndex();
            for(int i = 0; i < ui->dairyTableView->model()->rowCount(); i++){
                index = ui->dairyTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
    };
}

void processByAspectWidget::daysMenu(QPoint val){
    QMenu menu;
    QPoint gpt = ui->astroTableView->mapToGlobal(val);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        //QMessageBox::warning(this, tr("wo"), result->text(), QMessageBox::Ok);
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->astroTableView->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd hh:mm:ss")));
            }
        };
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->astroTableView->rootIndex();
            for(int i = 0; i < ui->astroTableView->model()->rowCount(); i++){
                index = ui->astroTableView->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd hh:mm:ss")));
            }
        };
    };
}
