#ifndef WEATHERDISPLAYWIDGET_H
#define WEATHERDISPLAYWIDGET_H

#include <QWidget>
#include <QtSql>
#include <QSettings>
#include <QProcess>
#include "mainwindow.h"

namespace Ui {
class weatherDisplayWidget;
}

class weatherDisplayWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit weatherDisplayWidget(QDateTime *current = 0, QWidget *parent = 0);
    ~weatherDisplayWidget();
public slots:
    void    refresh();
    void    openDate(QModelIndex index);
    void    changeType(int index);
    
private:
    Ui::weatherDisplayWidget *ui;
    QSqlTableModel *model;
    QSqlTableModel *datesModel;
    QDateTime*      datetime;
    QProcess        *starFisher;
};

#endif // WEATHERDISPLAYWIDGET_H
