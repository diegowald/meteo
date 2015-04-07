#include "sweph.h"

sweph::sweph(QString dllpath, QObject *parent) :
    QObject(parent)
{
    mylib.setFileName(dllpath);
    mylib.load();

    julday = (Swe_Julday)mylib.resolve("_swe_julday@24");
    qDebug() << julday;
    set_path = (Swe_Set_Ephe_Path)mylib.resolve("_swe_set_ephe_path@4");
    qDebug() << set_path;
    get_planet_name = (Swe_Get_Planet_Name)mylib.resolve("_swe_get_planet_name@8");
    qDebug() << get_planet_name;
    calc_ut = (Swe_Calc_Ut)mylib.resolve("_swe_calc_ut@24");
    qDebug() << calc_ut;    
    houses_pos = (Swe_House_Pos)mylib.resolve("_swe_house_pos@36");
    qDebug() << houses_pos;
    houses = (Swe_Houses)mylib.resolve("_swe_houses@36");
    qDebug() << houses;
    sidtime = (Swe_Sidtime)mylib.resolve("_swe_sidtime@8");
    qDebug() << sidtime;
    qDebug() << "done";

    lon = 0.0;
    lat = 0.0;
}

sweph::~sweph(){

}

double sweph::swe_julday(int Day, int Month, int Year, double Hour){
    qDebug() << "swe_julday";
    return julday(Year, Month, Day, Hour, 1);
}

void sweph::swe_set_ephe_path(QString path){
    set_path(path.toLatin1().data());
}

QString sweph::swe_get_planet_name(int planet){
    char x[256];
    return get_planet_name(planet, x);
}

double* sweph::swe_calc(double Julday, int PlanetNumber, int Ephe){
/*    QTime dieTime = QTime::currentTime().addSecs(2);
    while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);*/
    //qDebug() << "swe_calc";
    char err[256];
    double *result = new double[6];
    result[0] = 0.0;
    result[1] = 0.0;
    result[2] = 0.0;
    result[3] = 0.0;
    result[4] = 0.0;
    result[5] = 0.0;
    //result[6] = 0.0;
    qDebug() << calc_ut(Julday, PlanetNumber, Ephe, result, err);
    qDebug() << result[0];
    qDebug() << result[1];
    qDebug() << result[2];
    qDebug() << result[3];
    qDebug() << result[4];
    qDebug() << result[5];
    qDebug() << QString(err);
    return result;
}

double* sweph::swe_calc_ut(double Julday, int PlanetNumber){
    //qDebug() << "swe_calc_ut";
    return swe_calc(Julday, PlanetNumber, 256);
}

double sweph::swe_sidtime(double tjd_ut){
    //qDebug() << "swe_sidtime";
    return sidtime(tjd_ut);
}

void sweph::swe_houses(double julday, double lat, double lon, double *cusps, double *ascmc){
    //qDebug() << "swe_calc_houses";
    //char err[255];
    int results = houses(julday, lat, lon, (int)'p', cusps, ascmc);
    //qDebug() << "swe_result: " << results << QString(err);
}

double sweph::swe_house_pos(double armc, double geolat, double eps, double *position){
    char serr[255];
    double result = houses_pos(armc, geolat, eps, (int)'p', position, serr);
    qDebug() << serr;
    return result;
}
