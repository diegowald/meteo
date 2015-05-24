#include "processbyweatherwidget.h"
#include "ui_processbyweatherwidget.h"
#include "weatherdisplaywidget.h"
#include "mainwindow.h"

processByWeatherWidget::processByWeatherWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processByWeatherWidget),
    information(new dataProcessor)
{
    ui->setupUi(this);
    form = 0;
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(openWeatherDialog()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(delWeather()));
    connect(ui->buscarButton, SIGNAL(clicked()), this, SLOT(doFilter()));
    connect(ui->datesList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openDateWidget(QModelIndex)));

    connect(ui->aspectariumPorcentajeSpinBox, SIGNAL(valueChanged(int)), information, SLOT(setAspectPercent(int)));
    connect(ui->signPorcentajeSpinBox, SIGNAL(valueChanged(int)), information, SLOT(setSignPercent(int)));
    connect(ui->housesPorcentajeSpinBox, SIGNAL(valueChanged(int)), information, SLOT(setHousePercent(int)));
    connect(ui->quadrantsProcentajeSpinBox, SIGNAL(valueChanged(int)), information, SLOT(setQuadrantPercent(int)));
    connect(ui->positionsPorcentajeSpinBox, SIGNAL(valueChanged(int)), information, SLOT(setPositionPercent(int)));

    connect(ui->desdeLaTablaComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(typeChange()));

    information->setAspectPercent(ui->aspectariumPorcentajeSpinBox->value());
    information->setSignPercent(ui->signPorcentajeSpinBox->value());
    information->setHousePercent(ui->housesPorcentajeSpinBox->value());
    information->setQuadrantPercent(ui->quadrantsProcentajeSpinBox->value());
    information->setPositionPercent(ui->positionsPorcentajeSpinBox->value());

    ui->desdeLaTablaComboBox->addItem("Astral", "validweather");
    ui->desdeLaTablaComboBox->addItem("NOAA", "estadotiempos_diarios");

    QSqlQuery query;
    query.exec("SELECT * FROM STATIONS WHERE SELECTED = 1;");
    ui->cboEstacion->clear();
    while (query.next())
    {
        ui->cboEstacion->addItem(query.record().field("USAF").value().toString());
    }
    ui->cboEstacion->setCurrentIndex(0);
    ui->datesList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->datesList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(dayMenu(QPoint)));
}

processByWeatherWidget::~processByWeatherWidget()
{
    delete ui;
    delete information;
}

void processByWeatherWidget::addWeather(metAstro::weatherParameter *param){
    weatherList.append(param);
    refresh();
}

void processByWeatherWidget::delWeather(){
    qDebug() << "del weather";
    QModelIndexList indexes = ui->weatherTable->selectionModel()->selectedRows(0);
    if(indexes.isEmpty()) return;
    weatherList.removeAt(indexes.at(0).row());
    refresh();
}

void processByWeatherWidget::openWeatherDialog(){
    bool isNOAA;
    isNOAA = (ui->desdeLaTablaComboBox->currentText() == "NOAA");
    form = new weatherDialog(0, isNOAA);
    connect(form, SIGNAL(weatherAdd(metAstro::weatherParameter*)), this, SLOT(addWeather(metAstro::weatherParameter*)));
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}

void processByWeatherWidget::refresh(){
    ui->weatherTable->clear();
    ui->weatherTable->setColumnCount(3);
    ui->weatherTable->setRowCount(weatherList.count());
    ui->weatherTable->setHorizontalHeaderLabels(QStringList() << "Parametro" << "Valor" << "Tolerancia");

    for(int i = 0; i < weatherList.count(); i++){
        metAstro::weatherParameter *param = weatherList.at(i);
        ui->weatherTable->setItem(i, 0, new QTableWidgetItem(param->parameter));
        ui->weatherTable->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(param->value)));
        ui->weatherTable->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(param->tolerance)));
    };
}

void processByWeatherWidget::refreshResult(){
    ui->aspectariumTableWidget->clear();
    ui->housesTableWidget->clear();
    ui->signsTableWidget->clear();
    ui->positionsTableWidget->clear();
    ui->quadrantesTableWidget->clear();
    int i;

    //aspectos
    ui->aspectariumTableWidget->setRowCount(information->aspectsResult.count());
    ui->aspectariumTableWidget->setColumnCount(3);
    ui->aspectariumTableWidget->setHorizontalHeaderLabels(QStringList() << "Cuerpo 1" << "Cuerpo 2" << "Ocurrencias");
    for(i = 0; i < information->aspectsResult.count(); i++){
        metAstro::aspectResultParam param = information->aspectsResult.at(i);
        ui->aspectariumTableWidget->setItem(i, 0, new QTableWidgetItem(information->retrievePlanet(param.data.planet1)));
        ui->aspectariumTableWidget->setItem(i, 1, new QTableWidgetItem(information->retrievePlanet(param.data.planet2)));
        ui->aspectariumTableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(param.times)));
    };

    //positions
    ui->positionsTableWidget->setRowCount(information->positionResult.count());
    ui->positionsTableWidget->setColumnCount(3);
    ui->positionsTableWidget->setHorizontalHeaderLabels(QStringList() << "Cuerpo" << "Signo" << "Ocurrencias");
    for(i = 0; i< information->positionResult.count(); i++){
        metAstro::positionResultParam param = information->positionResult.at(i);
        ui->positionsTableWidget->setItem(i, 0, new QTableWidgetItem(information->retrievePlanet(param.data.planet)));
        ui->positionsTableWidget->setItem(i, 1, new QTableWidgetItem(information->retrieveSign(param.data.sign)));
        ui->positionsTableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(param.times)));
    };

    //houses
    ui->housesTableWidget->setRowCount(information->housesResult.count());
    ui->housesTableWidget->setColumnCount(4);
    ui->housesTableWidget->setHorizontalHeaderLabels(QStringList() << "Cuerpo" << "Casa" << "Tipo" << "Ocurrencias");
    for(i = 0; i < information->housesResult.count(); i++){
        metAstro::houseResultParam param = information->housesResult.at(i);
        QString type, casa;
        if(param.data.type == "ca"){
            type = "Cadent";
        }else{
            if(param.data.type == "su"){
                type = "Succedent";
            }else{
                type = "Angular";
            };
        };
        if(param.data.house == 1) casa = "1 5 9";
        if(param.data.house == 4) casa = "4 8 12";
        if(param.data.house == 7) casa = "7 11 3";
        if(param.data.house == 10) casa = "10 2 6";

        ui->housesTableWidget->setItem(i, 0, new QTableWidgetItem(information->retrievePlanet(param.data.planet)));
        ui->housesTableWidget->setItem(i, 1, new QTableWidgetItem(casa));
        ui->housesTableWidget->setItem(i, 2, new QTableWidgetItem(type));
        ui->housesTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(param.times)));
    };

    //signs
    ui->signsTableWidget->setRowCount(information->signResult.count());
    ui->signsTableWidget->setColumnCount(4);
    ui->signsTableWidget->setHorizontalHeaderLabels(QStringList() << "Cuerpo" << "Columna" << "T. Signo" << "Ocurrencias");
    for(i = 0; i < information->signResult.count(); i++){
        metAstro::signResultParam param = information->signResult.at(i);
        QString column, sign;
        if(param.data.column == "ca"){
            column = "Cadinal";
        }else{
            if(param.data.column == "fi"){
                column = "Fixed";
            }else{
                column = "Mutable";
            };
        };
        if(param.data.sign == "fu") sign = "Fuego";
        if(param.data.sign == "ag") sign = "Agua";
        if(param.data.sign == "ti") sign = "Tierra";
        if(param.data.sign == "ai") sign = "Aire";

        ui->signsTableWidget->setItem(i, 0, new QTableWidgetItem(information->retrievePlanet(param.data.planet)));
        ui->signsTableWidget->setItem(i, 1, new QTableWidgetItem(column));
        ui->signsTableWidget->setItem(i, 2, new QTableWidgetItem(sign));
        ui->signsTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(param.times)));
    };

    //quadrants
    ui->quadrantesTableWidget->setRowCount(information->quadrantsResult.count());
    ui->quadrantesTableWidget->setColumnCount(4);
    ui->quadrantesTableWidget->setHorizontalHeaderLabels(QStringList() << "Cuerpo" << "Este Oeste" << "Posicion" << "Ocurrencias");
    for(i = 0; i < information->quadrantsResult.count(); i++){
        metAstro::quadrantsResultParam param = information->quadrantsResult.at(i);
        ui->quadrantesTableWidget->setItem(i, 0, new QTableWidgetItem(information->retrievePlanet(param.data.planet)));
        ui->quadrantesTableWidget->setItem(i, 1, new QTableWidgetItem((param.data.eastwest == "es") ? "Este" : "Oeste"));
        ui->quadrantesTableWidget->setItem(i, 2, new QTableWidgetItem((param.data.code == "ab") ? "Above" : "Beneath"));
        ui->quadrantesTableWidget->setItem(i, 3, new QTableWidgetItem(QString("%1").arg(param.times)));
    };

    ui->aspectariumTableWidget->resizeColumnsToContents();
    ui->positionsTableWidget->resizeColumnsToContents();
    ui->housesTableWidget->resizeColumnsToContents();
    ui->signsTableWidget->resizeColumnsToContents();
    ui->quadrantesTableWidget->resizeColumnsToContents();
}

void processByWeatherWidget::openDateWidget(QModelIndex index){
    QWidgetList widgets = qApp->allWidgets();
    MainWindow *mainwidget;
    for(int i = 0; i < widgets.count(); i++){
        if(dynamic_cast<MainWindow*>(widgets.at(i)) != NULL){
            //qDebug() << "eureka";
            mainwidget = static_cast<MainWindow*>(widgets.at(i));
            QDateTime *param = new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd hh:mm:ss"));
            weatherDisplayWidget *form = new weatherDisplayWidget(param);
            mainwidget->showForm(form);
        };
    };
}

void processByWeatherWidget::typeChange(){
    //qDebug() << ui->desdeLaTablaComboBox->currentText();
    if(ui->desdeLaTablaComboBox->currentText() == "NOAA"){
        information->setNOAAWeather();
    }else{
        information->setAstralWeather();
    };
    weatherList.clear();
    refresh();
}

void processByWeatherWidget::doFilter(){
    ui->buscarButton->setText("Buscando...");
    ui->buscarButton->setEnabled(false);
    ui->datesList->clear();
    information->clearWeather();
    information->setWeathers(true);
    information->setStrongWeathers(true);
    for(int i = 0; i < weatherList.count(); i++){
        information->addWeather(weatherList.at(i));
    };
    information->setUSAF(usaf());
    information->processWeather();
    QList<QDateTime> result = information->getMatchDates();    
    for(int i = 0; i < result.count(); i++){
        qDebug() << result.at(i).toString();
        ui->datesList->addItem(result.at(i).toString("yyyy-MM-dd hh:mm:ss"));
    };

    ui->fechasLabel->setText(QString("Fechas: %1 items").arg(result.count()));

    information->processResults();
    refreshResult();
    ui->buscarButton->setText("Filtrar");
    ui->buscarButton->setEnabled(true);
}

void processByWeatherWidget::dayMenu(QPoint pt){
    QMenu menu;
    QPoint gpt = ui->datesList->mapToGlobal(pt);

    menu.addAction("Agregar fecha a planilla");
    menu.addAction("Agregar todas las fechas a planilla");
    QAction* result = menu.exec(gpt);
    if(result){
        //QMessageBox::warning(this, tr("wo"), result->text(), QMessageBox::Ok);
        excelExportWidget* excel = MainWindow::instance()->getExcelExport();
        if(result->text() == "Agregar fecha a planilla"){
            QModelIndexList list = ui->datesList->selectionModel()->selectedRows(0);
            QModelIndex index;
            foreach(index, list){
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
        if(result->text() == "Agregar todas las fechas a planilla"){
            QModelIndex index;
            index = ui->datesList->rootIndex();
            for(int i = 0; i < ui->datesList->model()->rowCount(); i++){
                index = ui->datesList->model()->sibling(i, 0, index);
                qDebug() << index.data().toString();
                excel->addDateTime(new QDateTime(QDateTime::fromString(index.data().toString(), "yyyy-MM-dd")));
            }
        };
    };
}

QString processByWeatherWidget::usaf() const
{
    return ui->cboEstacion->currentText();
}
