#ifndef DATAMODIFICATIONWIDGET_H
#define DATAMODIFICATIONWIDGET_H

#include <QWidget>
#include <QtSql>
#include <QDateTime>
#include "dataprocessor.h"

namespace Ui {
    class dataModificationWidget;
}

class dataModificationWidget : public QWidget
{
    Q_OBJECT

public:
   explicit dataModificationWidget(QWidget *parent = 0);
    ~dataModificationWidget();

public slots:
    /*void    addAspect();
    void    modAspect();
    void    delAspect();

    void    addPosition();
    void    modPosition();
    void    delPosition();

    void    addHouses();
    void    modHouses();
    void    delHouses();

    void    addQuadrant();
    void    modQuadrant();
    void    delQuadrant();

    void    addSign();
    void    modSign();
    void    delSign();

    void    aspectAdded(metAstro::aspectParameter *asp);
    void    aspectModed(metAstro::aspectParameter *asp);
    void    houseAdded(metAstro::housesParameter *asp);
    void    houseModed(metAstro::housesParameter *asp);
    void    signAdded(metAstro::signsParameter *asp);
    void    signModed(metAstro::signsParameter *asp);
    void    cuadranteAdded(metAstro::cuadrantesParameter *asp);
    void    cuadranteModed(metAstro::cuadrantesParameter *asp);
    void    positionAdded(metAstro::positionParameter *asp);
    void    positionModed(metAstro::positionParameter *asp);*/

    void    accepted();
    void    closed();

    /*void    refreshAspects();
    void    refreshPositions();
    void    refreshHouses();
    void    refreshQuadrants();
    void    refreshSigns();*/

    void    refresh();
    void    changeType();
    void    loadData();
    void    saveData();
    void    eraseData();


private:
    QDateTime *timespan;
    QList<metAstro::aspectParameter*> aspects;
    QList<metAstro::positionParameter*> positions;
    QList<metAstro::housesParameter*> houses;
    QList<metAstro::cuadrantesParameter*> quadrants;
    QList<metAstro::signsParameter*> signs;

    Ui::dataModificationWidget *ui;
    dataProcessor *dataMeaning;
};

#endif // DATAMODIFICATIONWIDGET_H
