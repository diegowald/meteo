#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
#include <QHash>
#include <QDate>
#include <QtSql>
#include <QProgressDialog>
#include <QThread>
#include "astroinfo.h"

namespace metAstro {
struct weatherParameter{
    QString parameter;
    double value;
    double tolerance;
};

struct aspectParameter{
    quint8 planet1;
    quint8 planet2;
    quint8 aspect;
    quint8 grade;
    quint8 minutes;
    quint8 seconds;
    quint8 gradeTolerance;
    quint8 secondsTolerance;
    quint8 minutesTolerance;
    quint8 computeGrade;
    quint8 computeMinutes;
    quint8 computeSeconds;
};

struct valor{
    qint16  value;
    qint16  tolerance;
    bool    compute;
};
struct positionParameter{
    quint8  planet;
    quint8  sign;
    valor   gradesLon;
    valor   minutesLon;
    valor   secondsLon;
    valor   gradesLat;
    valor   minutesLat;
    valor   secondsLat;
    valor   gradesVel;
    valor   minutesVel;
    valor   secondsVel;
    float   distance;
    float   distanceTolerance;
    bool    computeDistance;
    quint8  house;
    bool    computeHouse;
};

struct housesParameter{
    quint8  house;
    QString houseType;
    quint8  planet;
};

struct cuadrantesParameter{
    QString code;
    QString eastwest;
    quint8  planet;
};

struct signsParameter{
    QString sign;
    QString column;
    quint8  planet;
};

enum dignityType{ None = 1, Rules = 2, Exaltation = 4, Detriment = 8, Fall = 16};

struct dignityParam{
    dignityType dignity;
    quint8  planet;
};

struct aspectResultParam{
    astroInfo::AspectInfo data;
    quint16               times;
};

struct positionResultParam{
    astroInfo::PositionInfo data;
    quint16                 times;
};

struct quadrantsResultParam{
    astroInfo::QuadrantsInfo data;
    quint16                  times;
};

struct signResultParam{
    astroInfo::DistributionSignInfo data;
    quint16                     times;
};

struct houseResultParam{
    astroInfo::DistributionHousesInfo data;
    quint16                           times;
};

}
class dataProcessor : public QObject
{
    Q_OBJECT
    Q_ENUMS(processTypeReturn)

public:
    enum    processTypeReturn { Aspects, Weathers, Houses, Positions, Sings, Quadrants};
    explicit dataProcessor(QObject *parent = 0);
    ~dataProcessor();

    /* data management */
    void    addAspect(metAstro::aspectParameter* aspect){ this->aspects << aspect; }
    void    modAspect(metAstro::aspectParameter* aspect){ this->aspects.removeAll(aspect); this->aspects.append(aspect); }
    void    delAspect(metAstro::aspectParameter* aspect){ this->aspects.removeAll(aspect); }
    void    addAspectWeak(metAstro::aspectParameter* aspect){ this->aspectsWeak << aspect; }
    void    modAspectWeak(metAstro::aspectParameter* aspect){ this->aspectsWeak.removeAll(aspect); this->aspectsWeak.append(aspect); }
    void    delAspectWeak(metAstro::aspectParameter* aspect){ this->aspectsWeak.removeAll(aspect); }
    void    clearAspects(){ aspects.clear(); }
    void    clearAspectsWeak(){ aspectsWeak.clear(); }

    void    addWeather(metAstro::weatherParameter* weather){ this->weathers << weather; }
    void    modWeather(metAstro::weatherParameter* weather){ this->weathers.removeAll(weather); this->weathers.append(weather); }
    void    delWeather(metAstro::weatherParameter* weather){ this->weathers.removeAll(weather); }
    void    addWeatherWeak(metAstro::weatherParameter* weather){ this->weathersWeak << weather; }
    void    modWeatherWeak(metAstro::weatherParameter* weather){ this->weathersWeak.removeAll(weather); this->weathersWeak.append(weather); }
    void    delWeatherWeak(metAstro::weatherParameter* weather){ this->weathersWeak.removeAll(weather); }
    void    clearWeather(){ weathers.clear(); }
    void    clearWeatherWeak(){ weathersWeak.clear(); }

    void    setInitDate(QDate init){ this->initDate = init; }
    void    setFinishDate(QDate finish){ this->finishDate = finish; }
    QDate   getInitDate(){ return this->initDate; }
    QDate   getFinishDate(){ return this->finishDate; }

    void    addAspects(QList<metAstro::aspectParameter*> aspects);
    void    addWeakAspects(QList<metAstro::aspectParameter*> aspectsWeak);
    void    addWeathers(QList<metAstro::weatherParameter*> weathers);
    void    addWeakWeathers(QList<metAstro::weatherParameter*> weathersWeak);
    void    addPositions(QList<metAstro::positionParameter*> positions);
    void    addWeakPositions(QList<metAstro::positionParameter*> positionsWeak);
    void    addHouses(QList<metAstro::housesParameter*> houses);
    void    addWeakHouses(QList<metAstro::housesParameter*> housesWeak);
    void    addQuadrants(QList<metAstro::cuadrantesParameter*> quadrants);
    void    addWeakQuadrants(QList<metAstro::cuadrantesParameter*> quadrantsWeak);
    void    addSings(QList<metAstro::signsParameter*> signs);
    void    addWeakSings(QList<metAstro::signsParameter*> signsWeak);

    int     getWeatherPercent(){ return weatherPercent; }
    int     getAspectPercent(){ return aspectPercent; }
    int     getSignPercent(){ return signPercent; }
    int     getPositionPercent(){ return positionPercent; }
    int     getQuadrantPercent(){ return quadrantPercent;}
    int     getHousePercent(){ return housePercent; }

    int getDignity(int planet, double longitude);
    QString     getDignityName(metAstro::dignityType type);
    int getSignByDignity(metAstro::dignityParam param);

    /*data formating*/
    QString retrievePlanet(int planet);
    QString retrievePlanet1(metAstro::aspectParameter *aspect);
    QString retrievePlanet2(metAstro::aspectParameter *aspect);
    QString retrieveAspect(metAstro::aspectParameter *aspect);
    QString retrieveAspect(int aspect);

    QString retrieveSign(int sign);

    QString retrieveHouse(int house);

    processTypeReturn   currentReturnType(){ return returnType; }
    void                setReturnType(processTypeReturn ret){ returnType = ret; }
    QString getSqlResult(processTypeReturn ret);

    QList<QDateTime>    getMatchDates(){ return spatResult; }

signals:
    void    begin();
    void    endFirstPass();
    void    endSecondPass();
    void    finish();

    void    message(QString msg);

    void    setMaximun(int value);
    void    setMinimun(int value);
    void    setProgress(int value, int max);

public slots:
    void setAspects(bool value){doAspects = value; }
    void setStrongAspects(bool value){doStrongAspects = value; }
    void setWeakAspects(bool value){doWeakAspects = value; }
    void setWeathers(bool value){doWeathers = value; }
    void setStrongWeathers(bool value){doStrongWeathers = value; }
    void setWeakWeathers(bool value){doWeakWeathers = value; }
    void setPositions(bool value){doPositions = value; }
    void setStrongPositions(bool value){doStrongPositions = value; }
    void setWeakPositions(bool value){doWeakPositions = value; }
    void setHouses(bool value){doHouses = value; }
    void setStrongHouses(bool value){doStrongHouses = value; }
    void setWeakHouses(bool value){doWeakHouses = value; }
    void setQuadrants(bool value){doQuadrants = value; }
    void setStrongQuadrants(bool value){doStrongQuadrants = value; }
    void setWeakQuadrants(bool value){doWeakQuadrants = value; }
    void setSigns(bool value){doSigns = value; }
    void setStrongSigns(bool value){doStrongSigns = value; }
    void setWeakSigns(bool value){doWeakSigns = value; }
    void setUSAF(const QString &usaf) { _usaf = usaf; }

    QString USAF() const { return _usaf; }

    void	setWeatherPercent(int percent){  weatherPercent = percent; }
    void	setAspectPercent(int percent){  aspectPercent = percent; }
    void	setSignPercent(int percent){  signPercent = percent; }
    void	setPositionPercent(int percent){  positionPercent = percent; }
    void	setQuadrantPercent(int percent){  quadrantPercent = percent; }
    void	setHousePercent(int percent){  housePercent = percent; }

    void    processAspects();
    void    processWeather();
    void    processHouses();
    void    processPositions();
    void    processQuadrants();
    void    processSings();

    void    processResults();    

    void    startProcess();

    //void    processResult();
    void    setUseNormal(bool v){ useNormal = v; }
    void    setUseSisigia(bool v){ useSisigia = v; }

    void    setNOAAWeather(){ this->weatherTable = "estadotiempos_diarios"; }
    void    setAstralWeather(){ this->weatherTable = "validweather"; }
public:
    QList<metAstro::aspectResultParam> aspectsResult;
    QList<metAstro::houseResultParam> housesResult;
    QList<metAstro::signResultParam> signResult;
    QList<metAstro::positionResultParam> positionResult;
    QList<metAstro::quadrantsResultParam> quadrantsResult;

private:
    QList<metAstro::aspectParameter*> aspects;
    QList<metAstro::aspectParameter*> aspectsWeak;
    QList<metAstro::weatherParameter*> weathers;
    QList<metAstro::weatherParameter*> weathersWeak;
    QList<metAstro::positionParameter*> positions;
    QList<metAstro::positionParameter*> positionsWeak;
    QList<metAstro::housesParameter*> houses;
    QList<metAstro::housesParameter*> housesWeak;
    QList<metAstro::cuadrantesParameter*> quadrants;
    QList<metAstro::cuadrantesParameter*> quadrantsWeak;
    QList<metAstro::signsParameter*> signs;
    QList<metAstro::signsParameter*> signsWeak;

    /*QList<astroInfo::AspectInfo> aspectsResult;
    QList<astroInfo::DistributionHousesInfo> distributionResult;
    QList<astroInfo::DistributionSignInfo> signResult;
    QList<astroInfo::PositionInfo> positionResult;
    QList<astroInfo::QuadrantsInfo> quadrantsResult;*/

    bool    doAspects;
    bool    doStrongAspects;
    bool    doWeakAspects;

    bool    doWeathers;
    bool    doStrongWeathers;
    bool    doWeakWeathers;

    bool    doPositions;
    bool    doStrongPositions;
    bool    doWeakPositions;

    bool    doHouses;
    bool    doStrongHouses;
    bool    doWeakHouses;

    bool    doQuadrants;
    bool    doStrongQuadrants;
    bool    doWeakQuadrants;

    bool    doSigns;
    bool    doStrongSigns;
    bool    doWeakSigns;

    QList<QDateTime> spatResult;

    QDate   initDate;
    QDate   finishDate;

    bool    useSisigia;
    bool    useNormal;
    bool    firstTest;
    processTypeReturn returnType;

    int     weatherPercent;
    int     aspectPercent;
    int     signPercent;
    int     positionPercent;
    int     quadrantPercent;
    int     housePercent;


    QString lastSqlResult;
    QString weatherTable;
    QString _usaf;
};

#endif // DATAPROCESSOR_H
