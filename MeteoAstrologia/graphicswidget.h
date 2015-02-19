#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H

#include <QWidget>

namespace Ui {
    class graphicsWidget;
}

class graphicsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit graphicsWidget(QWidget *parent = 0);
    ~graphicsWidget();

private:
    Ui::graphicsWidget *ui;
};

#endif // GRAPHICSWIDGET_H
