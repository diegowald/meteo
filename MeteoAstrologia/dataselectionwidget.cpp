#include "dataselectionwidget.h"
#include "ui_dataselectionwidget.h"

dataSelectionWidget::dataSelectionWidget(QList<QStringList> *list, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataSelectionWidget)
{
    ui->setupUi(this);
    connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(select()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(select()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    data = list;
    for(int i = 0; i < data->length(); ++i){
        QString fecha = data->at(i).at(0);
        ui->listWidget->addItem(new QListWidgetItem(QDate::fromString(fecha.mid(1,8), "yyyyMMdd").toString("dd-MM-yyyy") + "  " + fecha.mid(9, 2)));
    };
}

dataSelectionWidget::~dataSelectionWidget()
{
    delete ui;
}

void dataSelectionWidget::select(){
    QModelIndex in = ui->listWidget->selectionModel()->selectedRows(0).at(0);
    returnList = data->at(in.row());
    emit dataSelected(returnList);
    this->accept();
}
