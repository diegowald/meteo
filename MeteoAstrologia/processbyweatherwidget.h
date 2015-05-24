#ifndef PROCESSBYWEATHERWIDGET_H
#define PROCESSBYWEATHERWIDGET_H

#include <QWidget>
#include <weatherdialog.h>
#include "dataprocessor.h"
#include "mainwindow.h"
#include <QDateTime>
#include <QMenu>

namespace Ui {
    class processByWeatherWidget;
}

class processByWeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit processByWeatherWidget(QWidget *parent = 0);
    ~processByWeatherWidget();
public slots:
    void    openWeatherDialog();
    void    addWeather(metAstro::weatherParameter *param);
    void    delWeather();
    void    refresh();
    void    refreshResult();
    void    openDateWidget(QModelIndex index);

    void    typeChange();

    void    doFilter();

    void    dayMenu(QPoint pt);
signals:

private:
    QString usaf() const;
private:
    Ui::processByWeatherWidget *ui;
    weatherDialog *form;
    QList<metAstro::weatherParameter*> weatherList;
    QList<QDateTime> datesList;
    dataProcessor *information;
};

#endif // PROCESSBYWEATHERWIDGET_H
