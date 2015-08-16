#include "excelexportwidget.h"
#include "ui_excelexportwidget.h"

excelExportWidget::excelExportWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::excelExportWidget)
{
    ui->setupUi(this);

    setWindowTitle("Exportacion a Excel");

    connect(ui->addButton, SIGNAL(clicked()), this ,SLOT(add()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(del()));

    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(filter()));
    connect(ui->exportButton, SIGNAL(clicked()), this, SLOT(excelExport()));
    refreshList();

    ui->typeComboBox->addItem("Temp. Maxima", "temp_max");
    ui->typeComboBox->addItem("Temp. Media", "temp_media");
    ui->typeComboBox->addItem("Temp. Minima", "temp_min");
    ui->typeComboBox->addItem("Presion", "presion");
    ui->typeComboBox->addItem("Visibilidad", "visibilidad");
    ui->typeComboBox->addItem("Vel. Viento", "viento_vel");
    ui->typeComboBox->addItem("Vel. Rafaga", "viento_rafaga");
    ui->typeComboBox->addItem("Punto de Rocio", "punto_rocio");
    ui->typeComboBox->addItem("Precipitaciones", "precipitaciones");
    ui->typeComboBox->addItem("Nieve", "nieve");
    ui->typeComboBox->addItem("Sunspots", "sunspots");
    ui->typeComboBox->addItem("Corriente Niño", "ENSO");

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);

}

excelExportWidget::~excelExportWidget()
{
    delete ui;
}

void excelExportWidget::del(){
    QModelIndexList list = ui->listWidget->selectionModel()->selectedIndexes();
    QModelIndex index;
    QList<int> toRemove;
    int i;
    foreach(index, list){
        toRemove.append(index.row());
        bool stop = false;
        i = toRemove.count() - 2;
        while(!stop && (i != -1)){
            if(toRemove.at(i) < toRemove.at(i+1)){
                toRemove.swap(i, i+1);
            }else{
                stop = true;
            }
            i--;
        }
    }
    foreach(i, toRemove) dateList.removeAt(i);
    refreshList();
}

void excelExportWidget::add(){
    QDateTimeEdit *widget = new QDateTimeEdit();
    widget->setCalendarPopup(true);
    widget->setAttribute(Qt::WA_DeleteOnClose);
    ui->verticalLayout->addWidget(widget);
    disconnect(ui->addButton, SIGNAL(clicked()), this ,SLOT(add()));
    disconnect(ui->delButton, SIGNAL(clicked()), this, SLOT(del()));
    connect(ui->addButton, SIGNAL(clicked()), this ,SLOT(added()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(cancel()));
}

void excelExportWidget::added(){
    qDebug() << "added";
    QWidgetList list = qApp->allWidgets();
    QWidget *ob;
    foreach(ob, list) {
        if(dynamic_cast<QDateTimeEdit*>(ob) != NULL){
            qDebug() << "yahoo!";
            QDateTimeEdit* date = static_cast<QDateTimeEdit*>(ob);
            addDateTime(new QDateTime(date->dateTime()));
        }
    }
    cancel();
}

void excelExportWidget::cancel(){
    QWidgetList list = qApp->allWidgets();
    QWidget *ob;
    foreach(ob, list) {
        if(dynamic_cast<QDateTimeEdit*>(ob) != NULL){
            QDateTimeEdit* date = static_cast<QDateTimeEdit*>(ob);
            date->close();
        }
    }
    disconnect(ui->addButton, SIGNAL(clicked()), this ,SLOT(added()));
    disconnect(ui->delButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->addButton, SIGNAL(clicked()), this ,SLOT(add()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(del()));
}

void excelExportWidget::refreshList(){
    ui->listWidget->clear();
    QDateTime* date;
    foreach(date, dateList){
        ui->listWidget->addItem(new QListWidgetItem(date->toString("yyyy-MM-dd hh:mm:ss")));
    }
}
void excelExportWidget::filter(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QSqlQuery query;
    QString ppTable, filter;
    QStringList filterList;
    QStringList fields;
    QList<QDateTime*> trueDateList;
    QDateTime *item;
    bool isMonth = false;
    int row, column, i;

    if(ui->astralRadio->isChecked()) ppTable = "estadotiempos_diarios"; // Modificacion de diego
    if(ui->noaaRadio->isChecked()) ppTable = "estadotiempos_diarios";
    if(ui->rbdButton->isChecked()) ppTable = "tiempos";
    if(ui->monthRadio->isChecked()){ ppTable = "view_estadotiempos_mensuales"; isMonth = true; }
    if(ui->annoButton->isChecked()){ ppTable = "view_estadotiempos_mensuales"; }

    if(ui->allRadio->isChecked()){
        trueDateList = dateList;
    }else{
        QModelIndexList list = ui->listWidget->selectionModel()->selectedIndexes();
        QModelIndex index;
        foreach(index, list) trueDateList << dateList.at(index.row());
    }

    if(isMonth){
        if(ui->onlyRadio->isChecked()){
            foreach(item, trueDateList){
                filterList << QString("(strftime('%Y', fecha) = '%1')").arg(item->toString("yyyy"));
            }
        }else{
            foreach(item, trueDateList){
                filterList << QString("(strftime('%Y', fecha) >= '%1' AND strftime('%Y', fecha) <= '%2')").arg(item->addMonths(-ui->spinBox->value()).toString("yyyy")).arg(item->addMonths(ui->spinBox->value()).toString("yyyy"));
            }
        }
        filter = filterList.join(" OR ");
        query.exec(
                    QString("SELECT strftime('%m', fecha) as month, strftime('%Y', fecha) as year, %1 as q FROM %2 WHERE %3 AND usaf = '%4'' ORDER BY year, month")
                    .arg(ui->typeComboBox->itemData(ui->typeComboBox->currentIndex()).toString())
                    .arg(ppTable)
                    .arg(filter)
                    .arg(usaf()));

        i = 0;
        row = -1;
        column = 1;
        fields << "Año" << "Enero" << "Febrero"<< "Marzo" << "Abril" << "Mayo" << "Junio";
        fields << "Julio" << "Agosto" << "Septiembre" << "Octubre" << "Noviembre" << "Diciembre";

        ui->tableWidget->setColumnCount(fields.count());
        ui->tableWidget->setHorizontalHeaderLabels(fields);
        QString anno = "";
        while(query.next()){
            if(anno != query.record().field("year").value().toString()){
                anno = query.record().field("year").value().toString();
                row++;
                qDebug() << "Row: " << row << "Year: " << anno;
                ui->tableWidget->setRowCount(row+1);
                qDebug() << "row count: " << ui->tableWidget->rowCount() << " column count: " << ui->tableWidget->columnCount();
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString("%1").arg(query.record().field("year").value().toString())));
            }
            ui->tableWidget->setItem(row, query.record().field("month").value().toInt(), new QTableWidgetItem(QString("%1").arg(query.record().field("q").value().toString())));
        }
    }else{
        if(ui->annoButton->isChecked()){
            if(ui->onlyRadio->isChecked()){
                foreach(item, trueDateList){
                    filterList << QString("(fecha LIKE '%1%')").arg(item->toString("yyyy"));
                }
            }else{
                foreach(item, trueDateList){
                    filterList << QString("(fecha >= '%1-01-01' AND fecha <= '%2-12-31')").arg(item->addYears(-ui->spinBox->value()).toString("yyyy")).arg(item->addYears(ui->spinBox->value()).toString("yyyy"));
                }
            }
            filter = filterList.join(" OR ");
            if(ui->astralRadio->isChecked()) filter = filter.replace("fecha", "strftime('%Y-%m-%d', fecha)");
            query.exec(QString("SELECT * FROM %1 WHERE %2 ORDER BY fecha").arg(ppTable).arg(filter));
        }else{
            if(ui->onlyRadio->isChecked()){
                foreach(item, trueDateList){
                    filterList << QString("(fecha = '%1')").arg(item->toString("yyyy-MM-dd"));
                }
            }else{
                foreach(item, trueDateList){
                    filterList << QString("(fecha >= '%1' AND fecha <= '%2')").arg(item->addDays(-ui->spinBox->value()).toString("yyyy-MM-dd")).arg(item->addDays(ui->spinBox->value()).toString("yyyy-MM-dd"));
                }
            }
            filter = filterList.join(" OR ");
            if(ui->astralRadio->isChecked()) filter = filter.replace("fecha", "strftime('%Y-%m-%d', fecha)");
            query.exec(QString("SELECT * FROM %1 WHERE %2 ORDER BY fecha").arg(ppTable).arg(filter));
        }
        query.next();
        i = 0;
        row = 1;
        while(query.record().fieldName(i) != ""){
            fields << query.record().fieldName(i);
            i++;
        }
        ui->tableWidget->setColumnCount(fields.count());
        ui->tableWidget->setHorizontalHeaderLabels(fields);
        do{
            ui->tableWidget->setRowCount(row);
            for(column = 0; column < fields.count(); column++){
                ui->tableWidget->setItem(row - 1, column, new QTableWidgetItem(QString("%1").arg(query.record().field(column).value().toString())));
            }
            row++;
        }while(query.next());
    }

    qDebug() << query.lastQuery() << query.lastError();    
    ui->tableWidget->resizeColumnsToContents();
}

void excelExportWidget::excelExport(){
    QProgressDialog dialog;
    dialog.setWindowTitle("Exportando a Excel");
    dialog.setMaximum(ui->tableWidget->columnCount() * ui->tableWidget->rowCount());
    dialog.setValue(0);
    dialog.show();

    QAxObject* excel = new QAxObject("Excel.Application", 0);
    QAxObject* app = excel->querySubObject("Application()");
    QAxObject* wbks = excel->querySubObject("Workbooks");
    QAxObject* wb = wbks->querySubObject("Add()");
    QAxObject* ws = wb->querySubObject("Worksheets");
    QAxObject* sheet = ws->querySubObject("Item( int )", 1);

    QAxObject* cell;

    int step = 0;

    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        cell = sheet->querySubObject("Cells(int,int)", 1, i+1);
        cell->setProperty("Value", QVariant::fromValue(ui->tableWidget->horizontalHeaderItem(i)->text()));
    }

    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        for(int j = 0; j < ui->tableWidget->rowCount(); j++){
            cell = sheet->querySubObject("Cells(int,int)", j+2, i+1);
            cell->setProperty("Value", QVariant::fromValue(ui->tableWidget->item(j, i)->data(Qt::DisplayRole).toString().replace('.', ",")));
            dialog.setValue(step++);
        }
    }

    app->setProperty("Visible", true );
}

QString excelExportWidget::usaf() const
{
    return ui->cboEstacion->currentText();
}
