#ifndef PROCESSBYPOSITIONWIDGET_H
#define PROCESSBYPOSITIONWIDGET_H

#include <QWidget>

namespace Ui {
class processByPositionWidget;
}

class processByPositionWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit processByPositionWidget(QWidget *parent = 0);
    ~processByPositionWidget();
    
private:
    Ui::processByPositionWidget *ui;
};

#endif // PROCESSBYPOSITIONWIDGET_H
