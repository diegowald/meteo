#include "processbypositionwidget.h"
#include "ui_processbypositionwidget.h"

processByPositionWidget::processByPositionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processByPositionWidget)
{
    ui->setupUi(this);
}

processByPositionWidget::~processByPositionWidget()
{
    delete ui;
}
