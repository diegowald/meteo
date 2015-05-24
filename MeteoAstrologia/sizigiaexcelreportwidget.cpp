#include "sizigiaexcelreportwidget.h"
#include "ui_sizigiaexcelreportwidget.h"
#include "utils.h"

int sizigiaExcelReportWidget::moonTolerance = 5;
int sizigiaExcelReportWidget::sunTolerance = 3;


sizigiaExcelReportWidget::sizigiaExcelReportWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sizigiaExcelReportWidget),
    fechaTable(new QSqlQueryModel)
{
    setLocale(QLocale::system());
    ui->setupUi(this);
    setWindowTitle("Exportación por sizigias");
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(test()));

    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(filter()));
    connect(ui->exportButton, SIGNAL(clicked()), this, SLOT(exportToExcel()));

    connect(ui->tipoDeDatoComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(typeChange(QString)));

    ui->tipoDeDatoComboBox->addItem("Sizigia Luna Llena", "llena");
    ui->tipoDeDatoComboBox->addItem("Sizigia Luna Nueva", "nueva");
    ui->tipoDeDatoComboBox->addItem("Equinoccios", "Equinoccio%");
    ui->tipoDeDatoComboBox->addItem("Solsticio", "Solsticio%");
    ui->tipoDeDatoComboBox->addItem("Sol en Pto. Primordial Cancer", "sol cancer");
    ui->tipoDeDatoComboBox->addItem("Sol en Pto. Primordial Capricornio", "sol capricornio");
    QSqlQuery query;
    query.exec(QString("SELECT DISTINCT planeta, signo FROM puntosprimordiales_sec"));
    if(query.next()){
        ui->tipoDeDatoComboBox->addItem(QString("Pto. Primordial %1 %2").arg(utils::planetName(query.record().field("planeta").value().toInt())).arg(utils::zodiacName(query.record().field("signo").value().toInt())), "special");
    };
    //ui->tipoDeDatoComboBox->addItem("Sol en Pto. Primordia Capricornio", "sol capricornio");
    ui->tipoDeDatoComboBox->addItem("Luna en Pto. Primordial Capricornio", "luna capricornio");
    ui->tipoDeDatoComboBox->addItem("Luna en Pto. Primordial Libra", "luna libra");

    ui->aExportarComboBox->addItem("Temp. Maxima", "temp_max");
    ui->aExportarComboBox->addItem("Temp. Media", "temp_media");
    ui->aExportarComboBox->addItem("Temp. Minima", "temp_min");
    ui->aExportarComboBox->addItem("Presion", "presion");
    ui->aExportarComboBox->addItem("Visibilidad", "visibilidad");
    ui->aExportarComboBox->addItem("Vel. Viento", "viento_vel");
    ui->aExportarComboBox->addItem("Vel. Rafaga", "viento_rafaga");
    ui->aExportarComboBox->addItem("Punto de Rocio", "punto_rocio");
    ui->aExportarComboBox->addItem("Precipitaciones", "precipitaciones");
    ui->aExportarComboBox->addItem("Nieve", "nieve");
    ui->aExportarComboBox->addItem("Sunspots", "sunspots");

    ui->fechaComboBox->setModel(fechaTable);

    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);

    typeChange(ui->tipoDeDatoComboBox->currentText());
}

sizigiaExcelReportWidget::~sizigiaExcelReportWidget()
{
    delete fechaTable;
    delete ui;
}

void sizigiaExcelReportWidget::typeChange(QString value){
    /*qDebug() << value;
    qDebug() << value.startsWith("Sizigia");
    qDebug() << value.contains("Pto. Primordia");*/
    if(value.startsWith("Sizigia")){
        fechaTable->setQuery(QString("SELECT fecha FROM estadotiempos WHERE luna = '%1' ORDER BY fecha").arg(ui->tipoDeDatoComboBox->itemData(ui->tipoDeDatoComboBox->currentIndex()).toString()));
        ui->aExportarComboBox->setEnabled(false);
        ui->allInCheckBox->setEnabled(false);
    };
    if(value.startsWith("Solsticio") || value.startsWith("Equinoccios")){
        fechaTable->setQuery(QString("SELECT fecha FROM estadotiempos WHERE tipo LIKE '%1' ORDER BY fecha").arg(ui->tipoDeDatoComboBox->itemData(ui->tipoDeDatoComboBox->currentIndex()).toString()));
        ui->aExportarComboBox->setEnabled(false);
        ui->allInCheckBox->setEnabled(false);
    };

    if(value.contains("Pto. Primordial")){
        QString pp = ui->tipoDeDatoComboBox->itemData(ui->tipoDeDatoComboBox->currentIndex()).toString();
        int signo;
        double degress, degressmax, degressmin;
        if(pp.startsWith("sol")){
            signo = pp.mid(4) == "cancer" ? 4 : 10;
            degress = (((signo - 1) * 30) + 20 + (10.0/60.0));
            degressmax = degress + sunTolerance;
            degressmin = degress - sunTolerance;
            fechaTable->setQuery(QString("SELECT DISTINCT strftime('%Y-%m-%d', fecha) FROM puntosprimordiales WHERE planeta = %1 AND signo = %2 AND degress >= %3 AND degress <= %4 ORDER BY fecha").arg(0).arg(signo).arg(degressmin).arg(degressmax));
        };
        if(pp.startsWith("luna")){
            signo = pp.mid(5) == "libra" ? 7 : 10;
            degress = (((signo - 1) * 30));
            degressmax = degress + moonTolerance;
            degressmin = degress;
            fechaTable->setQuery(QString("SELECT DISTINCT strftime('%Y-%m-%d', fecha) FROM puntosprimordiales WHERE planeta = %1 AND signo = %2 AND degress >= %3 AND degress <= %4 ORDER BY fecha").arg(1).arg(signo).arg(degressmin).arg(degressmax));
        };
        if(pp.startsWith("special")){
            /*signo = pp.mid(4) == "libra" ? 7 : 10;
            degress = (((signo - 1) * 30));
            degressmax = degress + moonTolerance;
            degressmin = degress;
            fechaTable->setQuery(QString("SELECT DISTINCT strftime('%Y-%m-%d', fecha) FROM puntosprimordiales_sec WHERE planeta = %1 AND signo = %2 AND degress >= %3 AND degress <= %4 ORDER BY fecha").arg(1).arg(signo).arg(degressmin).arg(degressmax));*/
            fechaTable->setQuery(QString("SELECT DISTINCT strftime('%Y-%m-%d', fecha) FROM puntosprimordiales_sec"));
        };
        //fechaTable->setQuery(QString("SELECT fecha FROM puntosprimordiales WHERE tipo = '%1' ORDER BY fecha").arg(ui->tipoDeDatoComboBox->itemData(ui->tipoDeDatoComboBox->currentIndex())));
        ui->aExportarComboBox->setEnabled(true);
        ui->allInCheckBox->setEnabled(true);
    };
}

void sizigiaExcelReportWidget::filter(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    QSqlQuery query;
    QString value = ui->tipoDeDatoComboBox->currentText();
    QDateTime selectedTime;
    QString ppTable;
    if(value.startsWith("Sizigia"))
    {
        selectedTime = QDateTime::fromString(ui->fechaComboBox->currentText(), "yyyy-MM-dd hh:mm:ss");
        query.exec(QString("SELECT * FROM estadotiempos_diarios WHERE fecha >= '%1' AND fecha <='%2' AND usaf = '%3'")
                   .arg(ui->fechaComboBox->currentText())
                   .arg(selectedTime.addDays(28).toString("yyyy-MM-dd hh:mm:ss"))
                   .arg(usaf()));
    }
    if(value.startsWith("Solsticio") || value.startsWith("Equinoccios"))
    {
        selectedTime = QDateTime::fromString(ui->fechaComboBox->currentText(), "yyyy-MM-dd hh:mm:ss");
        query.exec(QString("SELECT * FROM estadotiempos_diarios WHERE fecha >= '%1' AND fecha <='%2' AND usaf = '%3'")
                   .arg(ui->fechaComboBox->currentText())
                   .arg(selectedTime.addMonths(3).toString("yyyy-MM-dd hh:mm:ss"))
                   .arg(usaf()));
    }

    if(value.contains("Pto. Primordial"))
    {
        selectedTime = QDateTime::fromString(ui->fechaComboBox->currentText(), "yyyy-MM-dd");
        ppTable = ui->aExportarComboBox->itemData(ui->aExportarComboBox->currentIndex()).toString();
        //ppTable = ui->tipoDeDatoComboBox->itemData(ui->tipoDeDatoComboBox->currentIndex()).toString();
        qDebug() << ppTable;
        query.exec(QString("SELECT * FROM view_estadotiempos_mensuales WHERE fecha >= '%1-01' AND fecha <='%2-01' AND usaf = '%3'")
                   .arg(selectedTime.toString("yyyy-MM"))
                   .arg(selectedTime.addYears(1).toString("yyyy-MM"))
                   .arg(usaf()));
    }

    if(value.contains("Pto. Primordial") && !ui->allInCheckBox->isChecked())
    {
        qDebug() << query.lastQuery() << query.lastError();
        //fechaTable->setQuery(QString("SELECT fecha FROM puntosprimordiales WHERE tipo = '%1' ORDER BY fecha").arg(ui->tipoDeDatoComboBox->itemData(ui->tipoDeDatoComboBox->currentIndex())));
        QDate tempDate;
        int row, column, currentyear;
        row = -1;
        currentyear = 0;
        ui->tableWidget->setColumnCount(12);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Enero" << "Febrero" << "Marzo" << "Abril" << "Mayo" << "Junio" << "Julio" << "Agosto" << "Septiembre" << "Octubre" << "Noviembre" << "Diciembre");
        while(query.next()){
            tempDate = QDate::fromString(query.record().field("fecha").value().toString(), "yyyy-MM-dd");
            if(currentyear < tempDate.year()){
                row++;
                currentyear = tempDate.year();
                ui->tableWidget->setRowCount(row + 1);
                ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(tempDate.toString("yyyy")));
            };
            column = tempDate.month() - 1;
            ui->tableWidget->setItem(row, column, new QTableWidgetItem(QString("%1").arg(query.record().field(ppTable).value().toString())));
        };
    }else{

    //};

        int row, column, i;
        row = 1;
        //currentyear = 0;
        //ui->tableWidget->setColumnCount(query.record().field());
        query.next();
        i = 0;
        QStringList fields;
        while(query.record().fieldName(i) != ""){
            fields << query.record().fieldName(i);
            i++;
        };
        ui->tableWidget->setColumnCount(fields.count());
        ui->tableWidget->setHorizontalHeaderLabels(fields);
        do{
            ui->tableWidget->setRowCount(row);
            for(column = 0; column < fields.count(); column++){
                ui->tableWidget->setItem(row - 1, column, new QTableWidgetItem(QString("%1").arg(query.record().field(column).value().toString())));
            };
            row++;
        }while(query.next());
   };


}

void sizigiaExcelReportWidget::exportToExcel(){
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
    };

    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        for(int j = 0; j < ui->tableWidget->rowCount(); j++){
            //cell = sheet->querySubObject("Cells( Int, Int )", i, j);
            //Cells(fila, columna)
            cell = sheet->querySubObject("Cells(int,int)", j+2, i+1);
            cell->setProperty("Value", QVariant::fromValue(ui->tableWidget->item(j, i)->data(Qt::DisplayRole).toString().replace('.', ",")));
            /*qDebug() << ui->tableWidget->item(j, i)->data(Qt::UserRole);
            qDebug() << ui->tableWidget->item(j, i)->data(Qt::DisplayRole);*/
            dialog.setValue(step++);
        };
    };

    app->setProperty("Visible", true );
}

void sizigiaExcelReportWidget::test(){
    QAxObject* excel = new QAxObject("Excel.Application", 0);
    QAxObject* app = excel->querySubObject("Application()");
    QAxObject* wbks = excel->querySubObject("Workbooks");
    QAxObject* wb = wbks->querySubObject("Add()");
    QAxObject* ws = wb->querySubObject("Worksheets");
    QAxObject* sheet = ws->querySubObject("Item( int )", 1);
    QAxObject* cell;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            //cell = sheet->querySubObject("Cells( Int, Int )", i, j);
            cell = sheet->querySubObject("Cells(int,int)", i+1, j+1);
            cell->setProperty("Value", QVariant::fromValue(i*j));
        };
    };

    //Show Excel
    app->setProperty("Visible", true );
}

QString sizigiaExcelReportWidget::usaf() const
{
    return ui->cboEstacion->currentText();
}
