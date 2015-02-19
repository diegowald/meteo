#ifndef SWEPH_H
#define SWEPH_H

#include <QObject>
#include <QLibrary>
#include <QDebug>
#include <QTime>
#include <QCoreApplication>

class sweph : public QObject
{
    Q_OBJECT
    Q_ENUMS(flags)
    Q_ENUMS(planets)
    public:
        enum flags{SEFLG_JPLEPH=1, SEFLG_SWIEPH=2, SEFLG_MOSEPH=4, SEFLG_HELCTR=8, SEFLG_TRUEPOS=16, SEFLG_J2000=32, SEFLG_NONUT=64, SEFLG_SPEED3=128, SEFLG_SPEED=256, SEFLG_NOGDEFL=512, SEFLG_NOABERR=1024, SEFLG_EQUATORIAL=(2*1024), SEFLG_XYZ=(4*1024), SEFLG_RADIANS=(8*1024), SEFLG_BARYCTR=(16*1024), SEFLG_TOPOCTR=(32*1024), SEFLG_SIDEREAL=(64*1024)};
        enum planets{SE_SUN=0, SE_MOON=1, SE_MERCURY=2, SE_VENUS=3, SE_MARS=4, SE_JUPITER=5, SE_SATURN=6, SE_URANUS=7, SE_NEPTUNE=8, SE_PLUTO=9, SE_MEAN_NODE=10, SE_TRUE_NODE=11, SE_MEAN_APOG=12, SE_OSCU_APOG=13, SE_EARTH=14, SE_CHIRON=15};
        explicit sweph(QString dllpath = "swedll32.dll", QObject *parent = 0);
        ~sweph();
        double  swe_julday(int Day, int Month, int Year, double Hour);
        void    swe_set_ephe_path(QString path);
        QString swe_get_planet_name(int planet);
        double* swe_calc_ut(double Julday, int PlanetNumber);
        double* swe_calc(double Julday, int PlanetNumber, int Ephe);
        double  swe_sidtime(double tjd_ut);
        void    swe_houses(double julday, double lat, double lon, double* cusps, double* ascmc);
        double  swe_house_pos(double armc, double geolat, double eps, double* position);

        double  getLon(){   return lon; }
        void    getLon(double val){ lon = val; }
        double  getLat(){   return lat; }
        void    getLat(double val){ lat = val; }

    signals:

    public slots:

    private:
        QLibrary mylib;
        typedef double (* Swe_Sidtime) (double);
        typedef double(* Swe_Julday) (int, int, int, double, int);
        typedef void (* Swe_Set_Ephe_Path) (char *);
        typedef char* (* Swe_Get_Planet_Name) (int, char *);
        typedef qint32 (* Swe_Calc_Ut) (double, qint32, qint32, double*, char*);
        typedef int (* Swe_Houses) (double, double, double, int, double*, double*);
        typedef double (* Swe_House_Pos)(double, double, double, int, double*, char*);
        double  lon, lat;

        Swe_Julday julday;
        Swe_Set_Ephe_Path set_path;
        Swe_Get_Planet_Name get_planet_name;
        Swe_Calc_Ut calc_ut;
        Swe_Houses houses;
        Swe_House_Pos houses_pos;
        Swe_Sidtime sidtime;
};
/*
#define SE_SUN          0
#define SE_MOON         1
#define SE_MERCURY      2
#define SE_VENUS        3
#define SE_MARS         4
#define SE_JUPITER      5
#define SE_SATURN       6
#define SE_URANUS       7
#define SE_NEPTUNE      8
#define SE_PLUTO        9
#define SE_MEAN_NODE    10
#define SE_TRUE_NODE    11
#define SE_MEAN_APOG    12
#define SE_OSCU_APOG    13
#define SE_EARTH        14
#define SE_CHIRON       15
#define SE_PHOLUS       16
#define SE_CERES        17
#define SE_PALLAS       18
#define SE_JUNO         19
#define SE_VESTA        20
*/
#endif // SWEPH_H
