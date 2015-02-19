#include "browsewidget.h"
#include "ui_browsewidget.h"

browseWidget::browseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::browseWidget)
{
    ui->setupUi(this);
}

browseWidget::~browseWidget()
{
    delete ui;
}
