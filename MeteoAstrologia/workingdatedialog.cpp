#include "workingdatedialog.h"
#include "ui_workingdatedialog.h"

workingDateDialog::workingDateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workingDateDialog)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(accepted()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    ui->fechaDateTimeEdit->setDateTime(MainWindow::instance()->getWorkingDate());
    ui->okButton->setDefault(true);
}

workingDateDialog::~workingDateDialog()
{
    delete ui;
}

void workingDateDialog::accepted(){
    emit dateSubmited(ui->fechaDateTimeEdit->dateTime());
    QDialog::accept();
}
