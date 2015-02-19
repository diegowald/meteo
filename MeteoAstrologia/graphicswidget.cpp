#include "graphicswidget.h"
#include "ui_graphicswidget.h"

graphicsWidget::graphicsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphicsWidget)
{
    ui->setupUi(this);
}

graphicsWidget::~graphicsWidget()
{
    delete ui;
}
