#ifndef PROCESSDATAWIDGET_H
#define PROCESSDATAWIDGET_H

#include <QWidget>
#include <QList>
#include "dataprocessor.h"
#include "aspectsdialog.h"
#include "weatherdialog.h"

namespace Ui {
    class processDataWidget;
}

class processDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit processDataWidget(QWidget *parent = 0);
    ~processDataWidget();

public slots:
    void    aspectsAdded(metAstro::aspectParameter* aspect);
    void    aspectsModif(metAstro::aspectParameter* aspect);

    void    addAspects();
    void    modAspects();
    void    delAspects();

    void    weatherAdded(metAstro::weatherParameter* weather);
    void    weatherModif(metAstro::weatherParameter* weather);

    void    addWeather();
    void    modWeather();
    void    delWeather();

    void    refresh();
    void    refreshWeather();
    void    refreshAspect();
    void    refreshResult();

    void    processAspect();
    void    processWeather();

private:
    Ui::processDataWidget *ui;
    QList<metAstro::aspectParameter*> aspects;
    QList<metAstro::weatherParameter*> weathers;
    dataProcessor *dataMeaning;
    QSqlTableModel  *model;
};

#endif // PROCESSDATAWIDGET_H
