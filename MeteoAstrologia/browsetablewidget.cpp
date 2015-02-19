#include "browsetablewidget.h"
#include "ui_browsetablewidget.h"

browseTableWidget::browseTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::browseTableWidget)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    fechaModel = new QSqlQueryModel();
    ui->tableView->setModel(model);
    ui->datesComboBox->setModel(fechaModel);
    ui->typeComboBox->addItem("Normal", "normal");
    ui->typeComboBox->addItem("Sisigia de Equinoccio", "%Equinoccio%");
    ui->typeComboBox->addItem("Sisigia de Solsticio", "%Solsticio%");
    ui->typeComboBox->addItem("Sisiga Mensual", "mensual");

    ui->tableComboBox->addItem("Aspectos", "view_aspectaiums");
    ui->tableComboBox->addItem("Posiciones", "view_posiciones");
    ui->tableComboBox->addItem("Estados", "view_estadotiempos");
    ui->tableComboBox->addItem("Casas", "view_casas");
    ui->tableComboBox->addItem("Cuadrantes", "view_cuadrantes");
    ui->tableComboBox->addItem("Signos", "view_signos");

    connect(ui->tableComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeTable(int)));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    connect(ui->typeComboBox,SIGNAL(currentIndexChanged(int)), this, SLOT(changeType()));

    /*int index = ui->datesComboBox->findText(MainWindow::instance()->getWorkingDate().toString("yyyy-MM-dd"), Qt::MatchStartsWith);
    qDebug() << index;
    if(index != -1) ui->datesComboBox->setCurrentIndex(index);*/
    QString type = ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString();
    fechaModel->setQuery(QString("SELECT DISTINCT fecha FROM estadotiempos WHERE tipo LIKE '%1' ORDER BY fecha ASC").arg(type));
    while(fechaModel->canFetchMore()) fechaModel->fetchMore();
    int index = ui->datesComboBox->findText(MainWindow::instance()->getWorkingDate().toString("yyyy-MM-dd"), Qt::MatchStartsWith);
    if(index != -1) ui->datesComboBox->setCurrentIndex(index);
    QString tablename = ui->tableComboBox->itemData(ui->tableComboBox->currentIndex()).toString();
    model->setTable(tablename);
   // setWindowTitle(QString("Visualizar Tablas de Datos (%1)").arg());
    connect(ui->datesComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(fechaChange(QString)));
    fechaChange(ui->datesComboBox->currentText());
}

browseTableWidget::~browseTableWidget()
{
    delete model;
    delete ui;
}

void browseTableWidget::changeType()
{
    QString type = ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString();
   /* model->clear();
    model->setTable(tablename);
    //qDebug() << model->lastError();
    model->select();*/
    QString fecha = ui->datesComboBox->currentText();
    fechaModel->setQuery(QString("SELECT DISTINCT fecha FROM estadotiempos WHERE tipo LIKE '%1' ORDER BY fecha ASC").arg(type));
    while(fechaModel->canFetchMore()) fechaModel->fetchMore();
    int index = ui->datesComboBox->findText(fecha, Qt::MatchStartsWith);
    if(index != -1) ui->datesComboBox->setCurrentIndex(index);
    fechaChange(fecha);
}

void browseTableWidget::changeTable(int table){
    //QString tablename = ui->tableComboBox->itemData(table).toString();
    QString tablename = ui->tableComboBox->itemData(ui->tableComboBox->currentIndex()).toString();
    //QString type = ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString();
    model->clear();
    model->setTable(tablename);
    model->setFilter(QString("fecha = '%1'").arg(ui->datesComboBox->currentText()));
    //qDebug() << model->lastError();
    model->select();

    /*fechaModel->setQuery(QString("SELECT DISTINCT fecha FROM estadotiempos WHERE tipo LIKE '%1' ORDER BY fecha ASC").arg(type));
    while(fechaModel->canFetchMore()) fechaModel->fetchMore();*/
    //qDebug() << fechaModel->query().lastQuery() << fechaModel->lastError();
}

void browseTableWidget::fechaChange(QString date){
    model->setFilter(QString("fecha = '%1'").arg(date));
    model->select();
    ui->tableView->clearSpans();
    qDebug() << model->query().lastQuery() << model->lastError();
    setWindowTitle(QString("Visualizar Tablas de Datos (%1)").arg(date));
}
