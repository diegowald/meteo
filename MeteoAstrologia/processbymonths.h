#ifndef PROCESSBYMONTHS_H
#define PROCESSBYMONTHS_H

#include <QWidget>
#include <QDialog>
#include <QtSql>
#include <QMenu>
#include "dataprocessor.h"
#include "mainwindow.h"

namespace Ui {
    class processByMonths;
}

class processByMonths : public QWidget
{
    Q_OBJECT
public:
    explicit processByMonths(QWidget *parent = 0);
    ~processByMonths();
public slots:
    void    refresh();

    void    weatherChange(QModelIndex index);
    void    dayChange(QModelIndex index);
    void    noaaChange(QModelIndex index);

    void    doCalc();

    void    monthMenu(QPoint pt);
    void    dayMenu(QPoint pt);
    void    noaaMenu(QPoint pt);

private:
    Ui::processByMonths *ui;
    QSqlTableModel *positionModel, *aspectsModel, *quadrantsModel, *signsModel, *housesModel, *weatherModel, *noaaModel;
    QSqlQueryModel *resultModel;

    QList<QDate> resultList;
};

#endif // PROCESSBYMONTHS_H
