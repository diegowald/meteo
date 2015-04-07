#include "monthviewwidget.h"
#include "ui_monthviewwidget.h"

monthViewWidget::monthViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::monthViewWidget),
    astroModel(new QSqlTableModel),
    //monthModel(new QSqlTableModel),
    dailyModel(new QSqlTableModel),
    astralModel(new QSqlQueryModel)
{
    ui->setupUi(this);
    monthModel = new specialRowTableModel(MainWindow::instance()->getWorkingDate(), specialRowTableModel::month);
    setWindowTitle("Datos Segun mes");
    QStringList comboData;
    comboData << "Posiciones" << "Aspectos" << "Casas" << "Cuadrantes" << "Signos";
    ui->astralComboBox->addItems(comboData);

    connect(ui->monthTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectedMonth(QModelIndex)));
    connect(ui->astralComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeCombo(QString)));
    connect(ui->astroDailyTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectedDay(QModelIndex)));

    astroModel->setTable("view_estadotiempos");
    astroModel->setSort(0, Qt::AscendingOrder);
    dailyModel->setTable("estadotiempos_diarios");
    dailyModel->setSort(0, Qt::AscendingOrder);
    monthModel->setTable("view_estadotiempos_mensuales");
    monthModel->setSort(0, Qt::AscendingOrder);

    astroModel->select();
    dailyModel->select();
    monthModel->select();

    while(monthModel->canFetchMore()) monthModel->fetchMore();

    ui->monthTableView->setModel(monthModel);
    ui->dailyTableView->setModel(dailyModel);
    ui->astroDailyTableView->setModel(astroModel);
    ui->astralTableView->setModel(astralModel);

    QModelIndexList list = monthModel->match(monthModel->index(0, 0), Qt::BackgroundRole, QColor(Qt::green));
    if(!list.isEmpty()){
        qDebug() << list.at(0);
        ui->monthTableView->scrollTo(list.at(0), QAbstractItemView::PositionAtCenter);
    }

    changeCombo("Posiciones");
    resize();
}

monthViewWidget::~monthViewWidget()
{
    delete astroModel;
    delete dailyModel;
    delete monthModel;
    delete astralModel;
    delete ui;
}

void monthViewWidget::selectedMonth(QModelIndex index){
    QModelIndexList list = ui->monthTableView->selectionModel()->selectedRows();
    if(list.isEmpty()) return;
    QModelIndex data = list.at(0);
    data = data.sibling(data.row(), 0);
    qDebug() << data.data().toDateTime().toString("yyyy-MM-dd");
    astroModel->setFilter(QString("fecha LIKE '%1%'").arg(data.data().toDateTime().toString("yyyy-MM")));
    dailyModel->setFilter(QString("fecha LIKE '%1%'").arg(data.data().toDateTime().toString("yyyy-MM")));
    qDebug() << astroModel->lastError() << astroModel->query().lastQuery();
    qDebug() << dailyModel->lastError() << dailyModel->query().lastQuery();
    changeCombo(ui->astralComboBox->currentText());

    resize();
}

void monthViewWidget::selectedDay(QModelIndex index)
{
    qDebug() << "selectDay";
    QString data = ui->astralComboBox->currentText();

    QModelIndexList list = ui->astroDailyTableView->selectionModel()->selectedRows(0);
    if(list.isEmpty()) return;
    QModelIndex ind = list.at(0);
    //ind = ind.sibling(ind.row(), 1);
    qDebug() << ind.data();
    QString date = ind.data().toDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << date;
    if(data == "Posiciones"){
        astralModel->setQuery(QString("SELECT * FROM view_posiciones WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Aspectos"){
        astralModel->setQuery(QString("SELECT * FROM view_aspectaiums WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Casas"){
        astralModel->setQuery(QString("SELECT * FROM view_casas WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Cuadrantes"){
        astralModel->setQuery(QString("SELECT * FROM view_cuadrantes WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Signos"){
        astralModel->setQuery(QString("SELECT * FROM view_signos WHERE fecha LIKE '%1%'").arg(date));
    };
    qDebug() << astroModel->lastError() << astroModel->query().lastQuery();
    resize();

}

void monthViewWidget::changeCombo(QString data){
    qDebug() << "changeCombo";
    selectedDay(QModelIndex());
    return;

    QModelIndexList list = ui->monthTableView->selectionModel()->selectedRows();
    if(list.isEmpty()) return;
    QModelIndex index = list.at(0);
    index = index.sibling(index.row(), 0);
    QString date = index.data().toDateTime().toString("yyyy-MM");
    list = ui->astroDailyTableView->selectionModel()->selectedRows();
    //qDebug() << list.isEmpty();
    if(!list.isEmpty()){        
        index = list.at(0);
        qDebug() << index.data();
        index = index.sibling(index.row(), 1);
        //date = index.data().toDateTime().toString("yyyy-MM-dd");
        date = index.data().toString();
    };
    qDebug() << index.data().toDateTime().toString("yyyy-MM-dd");
    qDebug() << date;

    if(data == "Posiciones"){
        astralModel->setQuery(QString("SELECT * FROM view_posiciones WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Aspectos"){
        astralModel->setQuery(QString("SELECT * FROM view_aspectariums WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Casas"){
        astralModel->setQuery(QString("SELECT * FROM view_houses WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Cuadrantes"){
        astralModel->setQuery(QString("SELECT * FROM view_cuadrantes WHERE fecha LIKE '%1%'").arg(date));
    };
    if(data == "Signos"){
        astralModel->setQuery(QString("SELECTE * FROM view_signos WHERE fecha LIKE '%1%'").arg(date));
    };

    resize();
}

void monthViewWidget::resize()
{
    ui->astralTableView->resizeColumnsToContents();
    ui->astroDailyTableView->resizeColumnsToContents();
    ui->dailyTableView->resizeColumnsToContents();
    ui->monthTableView->resizeColumnsToContents();
}
