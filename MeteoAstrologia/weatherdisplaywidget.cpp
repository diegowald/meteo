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
    datesModel->setTable("estadotiempos");
    ui->comboBox->setModel(datesModel);
    ui->comboBox->setModelColumn(1);
    datesModel->select();
    while(datesModel->canFetchMore()) datesModel->fetchMore();
    ui->tableView->setModel(model);
    datetime = 0;
    //ui->tableView->hideColumn(0);

    ui->typeComboBox->addItem("Normal", "normal");
    ui->typeComboBox->addItem("Mensual", "mensual");
    ui->typeComboBox->addItem("Solsticio de Invierno", "Solsticio de Invierno");
    ui->typeComboBox->addItem("Solsticio de Verano", "Solsticio de Verano");
    ui->typeComboBox->addItem("Equinoccio de Primavera", "Equinoccio de Primavera");
    ui->typeComboBox->addItem("Equinoccio de Otoño", "Equinoccio de Otoño");

    if(current != 0){
        datetime = current;
        /*ui->comboBox->setEnabled(false);
        ui->typeComboBox->setEnabled(false);*/
    }else{
        /*qDebug()<< ui->comboBox->currentText();
        qDebug() << QDateTime::fromString(ui->comboBox->currentText(), "yyyy-MM-dd hh:mm:ss");*/
        //datetime = new QDateTime(QDateTime::fromString(ui->comboBox->currentText(), "yyyy-MM-dd hh:mm:ss"));
        QDateTime d = MainWindow::instance()->getWorkingDate();
        datetime = &d;
    };
    refresh();

    //if(current != 0){
        QModelIndex index;
        QItemSelection selection;
        /*bool finded = false;
        int i = 0;
        QModelIndex index = model->index(0, 1);
        while(!finded && index.sibling(i, 1).isValid()){
            if(index.sibling(i, 1).data().toString() == datetime->toString("yyyy-MM-dd hh:mm:ss")){
                finded = true;
            }else{
                i++;
            };
        };*/
        //index = index.sibling(i, 1);
        int id = ui->comboBox->findText(datetime->toString("yyyy-MM-dd"), Qt::MatchStartsWith);
        if(id != -1) ui->comboBox->setCurrentIndex(id);
        QModelIndexList list = model->match(model->index(0, 1), Qt::DisplayRole, datetime->toString("yyyy-MM-dd"), 1, Qt::MatchStartsWith);
        if(!list.isEmpty()){
            //qDebug() << list.at(0);
            index = list.at(0);
            selection.select(index.sibling(index.row(), 0), index.sibling(index.row(), model->columnCount() - 1));
            ui->tableView->selectionModel()->select(selection, QItemSelectionModel::Select);
            ui->tableView->scrollTo(index.sibling(index.row(), 0), QAbstractItemView::PositionAtCenter);
        };

        //ui->tableView->scrollTo(index.sibling(i, 0), QAbstractItemView::PositionAtBottom);
    //};

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
    //qDebug() << "Open Starfisher";
    QString currentDate = index.sibling(index.row(), 1).data().toString();
    excelExportWidget* excel = MainWindow::instance()->getExcelExport();
    excel->addDateTime(new QDateTime(QDateTime::fromString(currentDate, "yyyy-MM-dd hh:mm:ss")));
    excel->show();
    /*QFile starfisherfile("test.sfs");
    starfisherfile.open(QIODevice::WriteOnly);
    starfisherfile.write(QString("EventData.New(_auto);"
                                 "_eventData.Latitude = \"38S43'00\";"
                                 "_eventData.Longitude = \"62W17'00\";"
                                 "_eventData.Date = \"%1 GMT-3:00\";"
                                 "_eventData.Caption = \"test\";"
                                 "_eventData.Location = \"Bahía Blanca\";"
                                 "_eventData.Zone = \"America/Argentina/Buenos_Aires\";"
                                 "_eventData.Note = \"\";"
                                 "_eventData.Keywords = \"\";"
                                 "Horoscope.New(\"test\", _settings, _eventData);").arg(currentDate).toAscii());
    starfisherfile.close();

    QSettings sets("config.ini");
    sets.beginGroup("program");
    qDebug() << starFisher->state();
    //qDebug() << starFisherParser->state();
    //qDebug() << sets.value("SFfile").toString();
    if(starFisher->state() == QProcess::NotRunning){
        starFisher->start(sets.value("SFfile").toString(), QStringList() << qApp->applicationDirPath() + "/" + starfisherfile.fileName());
    };*/
    //connect(starFisherParser, SIGNAL(finished(int)), this, SLOT(saveData()));
}

void weatherDisplayWidget::refresh(){
    /*if(dynamic_cast<QComboBox*>(sender()) != NULL){
        delete datetime;
        datetime = new QDateTime(QDateTime::fromString(ui->comboBox->currentText(), "yyyy-MM-dd hh:mm:ss"));
    }*/
    QDateTime temp = QDateTime::fromString(ui->comboBox->currentText(), "yyyy-MM-dd hh:mm:ss");
    datetime->setDate(temp.date());
    datetime->setTime(temp.time());
    QString filter;
    setWindowTitle(QString("Rangos de Dias (fecha: %1)").arg(datetime->toString("yyyy-MM-dd hh:mm:ss")));
    /*qDebug() << "halo";
    qDebug() << datetime;
    qDebug() << datetime->toString();*/
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
    };

    //filter += " ORDER BY fechas ASC";
    //qDebug() << filter;
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
