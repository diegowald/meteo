#ifndef MONTHVIEWWIDGET_H
#define MONTHVIEWWIDGET_H

#include <QWidget>
#include <QtSql>
#include "specialrowtablemodel.h"
#include "mainwindow.h"

namespace Ui {
class monthViewWidget;
}

class monthViewWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit monthViewWidget(QWidget *parent = 0);
    ~monthViewWidget();
public slots:
    void    selectedMonth(QModelIndex index);
    void    selectedDay(QModelIndex index);
    void    changeCombo(QString data);
    void    resize();

private:
    QString usaf() const;

private:
    Ui::monthViewWidget *ui;
    QSqlTableModel /**monthModel,*/ *astroModel, *dailyModel;
    QSqlQueryModel *astralModel;
    specialRowTableModel *monthModel;
};

#endif // MONTHVIEWWIDGET_H
