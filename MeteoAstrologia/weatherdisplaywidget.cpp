#include "weatherdisplaywidget.h"
#include "ui_weatherdisplaywidget.h"

weatherDisplayWidget::weatherDisplayWidget(QDateTime *current, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::weatherDisplayWidget),
    starFisher(new QProcess)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    model->setTable("estadotiempos_diarios");
    datesModel = new QSqlTableModel();
    datesModel->setTable("estadotiempos_diarios"); // Modificacion de diego
    ui->comboBox->setModel(datesModel);
    ui->comboBox->setModelColumn(1);
    datesModel->select();
    while(datesModel->canFetchMore()) datesModel->fetchMore();
    ui->tableView->setModel(model);
    datetime = 0;

    ui->typeComboBox->addItem("Normal", "normal");
    ui->typeComboBox->addItem("Mensual", "mensual");
    ui->typeComboBox->addItem("Solsticio de Invierno", "Solsticio de Invierno");
    ui->typeComboBox->addItem("Solsticio de Verano", "Solsticio de Verano");
    ui->typeComboBox->addItem("Equinoccio de Primavera", "Equinoccio de Primavera");
    ui->typeComboBox->addItem("Equinoccio de Otoño", "Equinoccio de Otoño");


    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);

    if(current != 0){
        datetime = current;
    }else{
        QDateTime d = MainWindow::instance()->getWorkingDate();
        datetime = &d;
    }
    refresh();

        QModelIndex index;
        QItemSelection selection;

        int id = ui->comboBox->findText(datetime->toString("yyyy-MM-dd"), Qt::MatchStartsWith);
        if(id != -1) ui->comboBox->setCurrentIndex(id);
        QModelIndexList list = model->match(model->index(0, 1), Qt::DisplayRole, datetime->toString("yyyy-MM-dd"), 1, Qt::MatchStartsWith);
        if(!list.isEmpty()){
            index = list.at(0);
            selection.select(index.sibling(index.row(), 0), index.sibling(index.row(), model->columnCount() - 1));
            ui->tableView->selectionModel()->select(selection, QItemSelectionModel::Select);
            ui->tableView->scrollTo(index.sibling(index.row(), 0), QAbstractItemView::PositionAtCenter);
        }

    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));

    connect(ui->daysSpinBox, SIGNAL(valueChanged(int)), this, SLOT(refresh()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh()));
    connect(ui->typeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeType(int)));
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openDate(QModelIndex)));
    setWindowTitle(QString("Rangos de Dias"));
}

weatherDisplayWidget::~weatherDisplayWidget()
{
    delete ui;
    delete model;
    delete datesModel;
    delete starFisher;
}

void weatherDisplayWidget::openDate(QModelIndex index){
    //open StarFisher
    QString currentDate = index.sibling(index.row(), 1).data().toString();
    excelExportWidget* excel = MainWindow::instance()->getExcelExport();
    excel->addDateTime(new QDateTime(QDateTime::fromString(currentDate, "yyyy-MM-dd hh:mm:ss")));
    excel->show();
}

void weatherDisplayWidget::refresh(){
    QDateTime temp = QDateTime::fromString(ui->comboBox->currentText(), "yyyy-MM-dd hh:mm:ss");
    datetime->setDate(temp.date());
    datetime->setTime(temp.time());
    QString filter;
    setWindowTitle(QString("Rangos de Dias (fecha: %1)").arg(datetime->toString("yyyy-MM-dd hh:mm:ss")));
    QDateTime date1(*datetime);
    QDateTime date2(*datetime);
    date1 = date1.addDays(-1 * ui->daysSpinBox->value());
    date2 = date2.addDays(ui->daysSpinBox->value());
    filter = "(";
    filter += "fecha >= '" + date1.toString("yyyy-MM-dd") + "' ";
    filter += "AND fecha <= '" + date2.toString("yyyy-MM-dd") + "' ";
    filter += ")";

    if(!ui->sizigiasCheckBox->isChecked()){
        filter += " AND tipo = 'normal'";
    }

    filter += QString(" AND usaf = '%1'").arg(usaf());

    model->setFilter(filter);
    model->setSort(0, Qt::AscendingOrder);
    model->select();
    while(model->canFetchMore()) model->fetchMore();
    ui->tableView->resizeColumnsToContents();
}

void weatherDisplayWidget::changeType(int index){
    QString filter;
    filter = ui->typeComboBox->itemData(index).toString();
    filter = "tipo = '" + filter + "'";
    datesModel->setFilter(filter);
    datesModel->select();
    while(datesModel->canFetchMore()) datesModel->fetchMore();
    QDateTime d = MainWindow::instance()->getWorkingDate();
    int cbi = ui->comboBox->findText(d.toString("yyyy-MM-dd hh:mm:ss"));
    if(cbi == -1) cbi = ui->comboBox->findText(d.toString("yyyy-MM-dd"), Qt::MatchStartsWith);
    if(cbi == -1) cbi = ui->comboBox->findText(d.toString("yyyy-MM"), Qt::MatchStartsWith);
    ui->comboBox->setCurrentIndex(cbi);
}

QString weatherDisplayWidget::usaf() const
{
    return ui->cboEstacion->currentText();
}
