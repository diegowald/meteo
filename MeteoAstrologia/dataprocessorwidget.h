#ifndef DATAPROCESSORWIDGET_H
#define DATAPROCESSORWIDGET_H

#include <QWidget>
#include <QList>
#include "dataprocessor.h"
#include "aspectsdialog.h"
#include "signsdialog.h"
#include "housesdialog.h"
#include "weatherdialog.h"
#include "cuadrantesdialog.h"
#include "positionsdialog.h"

namespace Ui {
    class dataProcessorWidget;
}

class dataProcessorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit dataProcessorWidget(QWidget *parent = 0);
    ~dataProcessorWidget();
public slots:
    void    addStrongAspect();
    void    modStrongAspect();
    void    delStrongAspect();
    void    addWeakAspect();
    void    modWeakAspect();
    void    delWeakAspect();

    void    addStrongHouse();
    void    modStrongHouse();
    void    delStrongHouse();
    void    addWeakHouse();
    void    modWeakHouse();
    void    delWeakHouse();

    void    addStrongSign();
    void    modStrongSign();
    void    delStrongSign();
    void    addWeakSign();
    void    modWeakSign();
    void    delWeakSign();

    void    addStrongWeather();
    void    modStrongWeather();
    void    delStrongWeather();
    void    addWeakWeather();
    void    modWeakWeather();
    void    delWeakWeather();

    void    addStrongCuadrante();
    void    modStrongCuadrante();
    void    delStrongCuadrante();
    void    addWeakCuadrante();
    void    modWeakCuadrante();
    void    delWeakCuadrante();

    void    addStrongPosition();
    void    modStrongPosition();
    void    delStrongPosition();
    void    addWeakPosition();
    void    modWeakPosition();
    void    delWeakPosition();

    void    aspectStrongAdded(metAstro::aspectParameter *asp);
    void    aspectStrongModed(metAstro::aspectParameter *asp);
    void    aspectWeakAdded(metAstro::aspectParameter *asp);
    void    aspectWeakModed(metAstro::aspectParameter *asp);

    void    houseStrongAdded(metAstro::housesParameter *asp);
    void    houseStrongModed(metAstro::housesParameter *asp);
    void    houseWeakAdded(metAstro::housesParameter *asp);
    void    houseWeakModed(metAstro::housesParameter *asp);

    void    signStrongAdded(metAstro::signsParameter *asp);
    void    signStrongModed(metAstro::signsParameter *asp);
    void    signWeakAdded(metAstro::signsParameter *asp);
    void    signWeakModed(metAstro::signsParameter *asp);

    void    weatherStrongAdded(metAstro::weatherParameter *asp);
    void    weatherStrongModed(metAstro::weatherParameter *asp);
    void    weatherWeakAdded(metAstro::weatherParameter *asp);
    void    weatherWeakModed(metAstro::weatherParameter *asp);

    void    cuadranteStrongAdded(metAstro::cuadrantesParameter *asp);
    void    cuadranteStrongModed(metAstro::cuadrantesParameter *asp);
    void    cuadranteWeakAdded(metAstro::cuadrantesParameter *asp);
    void    cuadranteWeakModed(metAstro::cuadrantesParameter *asp);

    void    positionStrongAdded(metAstro::positionParameter *asp);
    void    positionStrongModed(metAstro::positionParameter *asp);
    void    positionWeakAdded(metAstro::positionParameter *asp);
    void    positionWeakModed(metAstro::positionParameter *asp);

    void    refreshStrongAspect();
    void    refreshWeakAspect();
    void    refreshStrongSign();
    void    refreshWeakSign();
    void    refreshStrongCuadrante();
    void    refreshWeakCuadrante();
    void    refreshStrongPosition();
    void    refreshWeakPosition();
    void    refreshStrongHouse();
    void    refreshWeakHouse();
    void    refreshStrongWeather();
    void    refreshWeakWeather();

    void    processData();

    void    processFinished();

signals:

private:
    Ui::dataProcessorWidget *ui;
    QList<metAstro::aspectParameter*> strongAspects;
    QList<metAstro::aspectParameter*> weakAspects;
    QList<metAstro::housesParameter*> strongHouses;
    QList<metAstro::housesParameter*> weakHouses;
    QList<metAstro::signsParameter*> strongSigns;
    QList<metAstro::signsParameter*> weakSigns;
    QList<metAstro::weatherParameter*> strongWeather;
    QList<metAstro::weatherParameter*> weakWeather;
    QList<metAstro::cuadrantesParameter*> strongCuadrantes;
    QList<metAstro::cuadrantesParameter*> weakCuadrantes;
    QList<metAstro::positionParameter*> strongPositions;
    QList<metAstro::positionParameter*> weakPositions;
    dataProcessor *processor;
};

#endif // DATAPROCESSORWIDGET_H
