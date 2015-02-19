#ifndef BROWSEWIDGET_H
#define BROWSEWIDGET_H

#include <QWidget>

namespace Ui {
    class browseWidget;
}

class browseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit browseWidget(QWidget *parent = 0);
    ~browseWidget();

private:
    Ui::browseWidget *ui;
};

#endif // BROWSEWIDGET_H
