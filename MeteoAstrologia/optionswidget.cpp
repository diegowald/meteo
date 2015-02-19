#include "optionswidget.h"
#include "ui_optionswidget.h"

optionsWidget::optionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::optionsWidget)
{
    ui->setupUi(this);

    connect(ui->rbdButton, SIGNAL(clicked()), this, SLOT(searchForRBD()));
    connect(ui->sfdButton, SIGNAL(clicked()), this, SLOT(searchForSFD()));
    connect(ui->starFisherButton, SIGNAL(clicked()), this, SLOT(searchForSF()));

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));

    sets = new QSettings("config.ini");

    sets->beginGroup("program");
    ui->archivoRBDLineEdit->setText(sets->value("RBDfile", "").toString());
    ui->archivoSFDLineEdit->setText(sets->value("SFDfile", "").toString());
    ui->starFisherExeLineEdit->setText(sets->value("SFfile", "").toString());
    sets->endGroup();
}

optionsWidget::~optionsWidget()
{
    delete ui;
    delete sets;
}

void optionsWidget::accept(){
    sets->beginGroup("program");
    sets->setValue("RBDfile", ui->archivoRBDLineEdit->text());
    sets->setValue("SFDfile", ui->archivoSFDLineEdit->text());
    sets->setValue("SFfile", ui->starFisherExeLineEdit->text());
    sets->endGroup();
    this->close();
}

void optionsWidget::searchForRBD(){
    QString response = this->searchForFile("*.RBD");
    if(response != ""){
        ui->archivoRBDLineEdit->setText(response);
    };
}

void optionsWidget::searchForSFD(){
    QString response = this->searchForFile("*.SFD");
    if(response != ""){
        ui->archivoSFDLineEdit->setText(response);
    };
}

void optionsWidget::searchForSF(){
    QString response = this->searchForFile("*.exe");
    if(response != ""){
        ui->starFisherExeLineEdit->setText(response);
    };
}

QString optionsWidget::searchForFile(QString kind){
    QFileDialog dialog;
    dialog.setFilter(kind);
    QString response = "";
    if(dialog.exec()){
        QFileInfo fileinfo(dialog.selectedFiles().at(0));
        response = fileinfo.absoluteFilePath();
    };

    return response;
}
