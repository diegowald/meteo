#ifndef ASTROINFO_H
#define ASTROINFO_H

#include <QObject>
#include <QDateTime>
#include <QStringList>
#include <QDir>
#include <QVector>
#include <math.h>
#include "sweph.h"

class astroInfo : public QObject
{
    Q_OBJECT
public:
    struct Body{
        QString name;
        QString error;
        int     number;
        union{
            struct{
                double longitude;
                double latitude;
                double distance;
                double longSpeed;
                double latSpeed;
                double distSpeed;
            };
            double bodyData[6];
        };
        double maxSpeed;
        double minSpeed;
        double avgSpeed;
        double house;
        void Clear() {
                memset(bodyData, 0, 6*sizeof(double));
                name = QString("");
                maxSpeed = minSpeed = avgSpeed = 0;
        }
    };

    struct Aspect{
        QString name;
        int     number;
        double  angle;
        double  orb;
        double  solilunarExt;
    };

    struct AspectInfo{
        Aspect* asp;
        int     planet1;
        int     planet2;
        int     aspect;
        double  diff;
    };

    struct DistributionSignInfo{
        QString sign;
        QString column;
        int     planet;
    };

    struct DistributionHousesInfo{
        int     house;
        QString type;
        int     planet;
    };

    struct QuadrantsInfo{
        QString code;
        QString eastwest;
        int     planet;
    };

    struct PositionInfo{
        int     planet;
        int     sign;
        double  longitude;
        double  latitud;
        double  velocity;
        double  distance;
        int     house;
    };

    explicit astroInfo(QObject *parent = 0);
    ~astroInfo();
    QDateTime getTimestamp(){ return timestamp; }
    double getLat(){ return this->lat; }
    double getLon(){ return this->lon; }
    double Normalize(double val){
        val = fmod(val, 360.0);
        if(val < 0.0) val += 360;
        return val;
    }
    double diffDegree(double val1, double val2){ double res = fabs(val1 - val2); return res; }
    double distanceDegree(double val1, double val2){
        double res = Normalize(val1 - val2);
        if(res > 180.0) res = 360.0 - res;
         return res;
    }

    double GetHousePos(double longitude, double latitude, double* cusp);
    double GetSignPos(double longitude, double latitude) const{
        return  longitude / 30.0;
    }
    //get info - ToDo
    //cleanInfo
    QList<AspectInfo> aspectarium;
    QList<DistributionSignInfo> signDistribution;
    QList<DistributionHousesInfo> houseDistribution;
    QList<QuadrantsInfo> quadrantsDistribution;
    QList<PositionInfo> positions;

signals:
    void    calcDone();

public slots:
    void    setTimestamp(QDateTime datetime){ this->timestamp = datetime; }
    void    doCalc();
    void    setLat(double newlat){ this->lat = newlat; infook = false;}
    void    setLon(double newlon){ this->lon = newlon; infook = false;}
    void    setLat(int deg, int min, int seg, char pos);
    void    setLon(int deg, int min, int seg, char pos);

private:
    enum Planets {Mercury = 2, Venus = 3, Earth = 14, Moon = 1, Mars = 4, Jupiter = 5, Saturn = 6, Uranus = 7, Neptune = 8, Pluto = 9};
    enum Sings {Aries = 1, Tauro = 2, Geminis = 3, Cancer = 4, Leo = 5, Virgo = 6, Libra = 7, Escorpio = 8, Sagitario = 9, Capricornio = 10, Acuario= 11, Piscis = 12};
    enum Elements {eFire = 0, eEarth = 1, eAir = 2, eWater = 3};
    int Sun;
    double maxOrb;

    QDateTime timestamp;
    double lon;
    double lat;
    sweph *swe;
    Aspect* AspectSet;

    // raw info;
    double juliandate;
    double armc;
    Body*   bodyPositions;
    double* housesCusps;
    double* housesAscmc;

    //Errors
    QStringList errors;
    bool infook;

    //funcs
    void clearBody(Body *b){
        b->error = QString("");
        b->name = QString("");
        for(int i = 0; i < 7; i++){
            b->bodyData[i] = 0.0;
        };
        b->number = 0;
    }

    void    loadAspectSet();
    void    loadBodySet();
};

#endif // ASTROINFO_H
