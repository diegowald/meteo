#ifndef PROCESSBYDIGNITYWIDGET_H
#define PROCESSBYDIGNITYWIDGET_H

#include <QWidget>
#include <QtSql>
#include <QMenu>
#include "dataprocessor.h"
#include "utils.h"
#include "mainwindow.h"

namespace Ui {
class processByDignityWidget;
}

class processByDignityWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit processByDignityWidget(QWidget *parent = 0);
    ~processByDignityWidget();
public slots:
    void    doCalc();
    void    calcDignity();
    void    dateTypeChanged(QString value);
    void    add();
    void    del();

    void    refresh();
    void    addDignity(metAstro::dignityParam & param);

    void    dailyMenu(QPoint pt);
    void    noaaMenu(QPoint pt);

private:
    QString usaf() const;

private:
    Ui::processByDignityWidget *ui;
    QList<metAstro::dignityParam> dignityList;

    dataProcessor  *information;

    QSqlTableModel *fechaModel, *resultModel, *noaaResultModel;
};

#endif // PROCESSBYDIGNITYWIDGET_H
