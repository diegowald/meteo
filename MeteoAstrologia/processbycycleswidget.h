#ifndef PROCESSBYCYCLESWIDGET_H
#define PROCESSBYCYCLESWIDGET_H

#include <QWidget>
#include <QtSql>
#include <QMenu>
#include <QAction>
#include "mainwindow.h"
#include <QMessageBox>

namespace Ui {
class processByCyclesWidget;
}

class processByCyclesWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit processByCyclesWidget(QWidget *parent = 0);
    ~processByCyclesWidget();

public slots:
    void    doCalc();
    void    phaseSelected(QModelIndex index);
    void    typeChanged(QString type);
    void    astralMenu(QPoint pt);
    void    noaaMenu(QPoint pt);
    void    monthMenu(QPoint pt);
    void    phaseMenu(QPoint pt);
    
private:
    Ui::processByCyclesWidget *ui;

    QSqlTableModel *fechaModel, *phase19Model, *phase37Model, *phase96Model, *nPhaseModel;
    QSqlTableModel *monthlyModel, *dailyModel, *astralDailyModel;

    QStringList phase19, phase37, phase96, phaseN;
    QStringList phase19month, phase37month, phase96month, phaseNmonth;

};

#endif // PROCESSBYCYCLESWIDGET_H
