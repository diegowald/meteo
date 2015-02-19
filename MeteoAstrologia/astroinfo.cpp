#include "astroinfo.h"

astroInfo::astroInfo(QObject *parent) :
    QObject(parent),
    swe(new sweph())
{
    //swe->swe_set_ephe_path("E:\\shaka\\dev\\current\\soft\\MeteoAstrologia\\sweph\\ephe");
    qDebug() << QDir::currentPath().replace("/", "\\");
    swe->swe_set_ephe_path(QDir::currentPath().replace("/", "\\") + "\\sweph\\ephe");
    infook = false;
    bodyPositions = new Body[16];
    juliandate = 0.0;
    armc = 0.0;
    Sun = 0;
    maxOrb = 8.0;
    AspectSet = new Aspect[20];
    this->housesAscmc = 0;
    this->housesCusps = 0;

    loadAspectSet();
    loadBodySet();
}

astroInfo::~astroInfo(){
    delete swe;
}

void astroInfo::setLat(int deg, int min, int seg, char pos){
    double newlat = deg + (min / 60.0) + (seg / 3600.0);
    if(pos == 'w' || pos == 'W') newlat = -newlat;
    this->lat = newlat;
    infook = false;
}

void astroInfo::setLon(int deg, int min, int seg, char pos){
    double newlon = deg + (min / 60.0) + (seg / 3600.0);
    if(pos == 'E' || pos == 'e') newlon = -newlon;
    this->lon = newlon;
    infook = false;
}

void astroInfo::doCalc(){
    aspectarium.clear();
    signDistribution.clear();
    houseDistribution.clear();
    quadrantsDistribution.clear();
    positions.clear();

    double lon, lat, sidt, armc;
    QTime mytimer;
    mytimer.start();
    QDate mydate = this->timestamp.date();
    QTime mytime = this->timestamp.time();

    qDebug() << "ñaña";
    double jdy = swe->swe_julday(mydate.day(),mydate.month(),mydate.year(), mytime.hour() + (mytime.minute() / 60.0) + (mytime.second() / 3600.0));
    qDebug() << "ñaña";
    this->juliandate = jdy;
    /*qDebug()<< "time" << mytime.hour() + (mytime.minute() / 60.0) + (mytime.second() / 3600.0);
    qDebug() << mytime.hour();
    qDebug() << mytime.minute();
    qDebug() << mytime.second();
    qDebug() << "ñaña";*/
    sidt = swe->swe_sidtime(jdy);
    /*qDebug() << "ñaña";
    *qDebug() << "swe_swe_julday" << QString("%1").arg(jdy, 0, 'g', 20);
    qDebug() << "swe_swe_julday2" << QString("%1").arg(mydate.toJulianDay(), 0, 'g', 20);*/

    //calc houses
    if(this->housesAscmc != 0) delete this->housesAscmc;
    if(this->housesCusps != 0) delete this->housesCusps;
    this->housesAscmc = new double[10];
    this->housesCusps = new double[13];
    /*qDebug() << this->juliandate;
    qDebug() << this->lat;
    qDebug() << this->lon;*/
    swe->swe_houses(this->juliandate, this->lat, this->lon, this->housesCusps, /*ascmc*/this->housesAscmc);
    for(int i = 0; i < 14; i++){
        qDebug() << "cusps i:" << i << " "  << this->housesCusps[i];/* ascmc[i];*/
    };

    //calc for every planet
    for(int planet = 0; planet <= 12; ++planet){
        /*qDebug() << "Doby name: " << bodyPositions[planet].name;
        qDebug() << "Doby number: " << bodyPositions[planet].number;*/
        double* result = swe->swe_calc_ut(this->juliandate, bodyPositions[planet].number);
        for(int i = 0; i <= 6; ++i){
            bodyPositions[planet].bodyData[i] = result[i];
        };
        /*double sign2*/ int sign2 = GetHousePos(bodyPositions[planet].longitude, bodyPositions[planet].latitude, this->housesCusps);
        bodyPositions[planet].house = sign2;//(int)sign2 % 13;
        /*qDebug() << "Signo: " << (((int)bodyPositions[planet].longitude / 30) % 12) + 1;*/
        /*qDebug() << "planeta: " << bodyPositions[planet].name;
        qDebug() << "Casa: " << bodyPositions[planet].house;*/
        if(bodyPositions[planet].name == "Earth") continue;
        PositionInfo info;
        info.sign = (((int)bodyPositions[planet].longitude / 30) % 12) + 1;
        info.planet = bodyPositions[planet].number;
        info.distance = bodyPositions[planet].distance;
        info.house = bodyPositions[planet].house;
        info.latitud = bodyPositions[planet].latitude;
        info.longitude = bodyPositions[planet].longitude;
        info.velocity = bodyPositions[planet].longSpeed;
        positions << info;
        //qDebug() << "latitud: " << bodyPositions[planet].latitude;
    };    

    //calc part of fortune
    bodyPositions[13].longitude = Normalize((this->housesAscmc[0] + bodyPositions[4].longitude) - bodyPositions[0].longitude);
    //qDebug() << "Part of Fortune" << bodyPositions[13].longitude;

    //calc asc and mc as bodies
    this->bodyPositions[14].longitude = this->housesAscmc[0];
    this->bodyPositions[15].longitude = this->housesAscmc[1];

    /*double *result;
    qDebug() << "Doby name: " << "Lilith";
    qDebug() << "Doby number: " << 12;
    result = swe->swe_calc_ut(this->juliandate, 12);*/

    /*qDebug() << "Doby name: " << "true node";
    qDebug() << "Doby number: " << 13;
    result = swe->swe_calc_ut(this->juliandate, 13);*/

    //return;
    // calc of aspects
    for(int planet1 = 0; planet1 <= 15; ++planet1){
        if(planet1 == 3) continue;
        for(int planet2 = planet1; planet2 <= 15; ++planet2){
            bool find = false;
            int j = 1;
            if(planet1 == planet2) continue;
            double angle = this->distanceDegree(bodyPositions[planet1].longitude, bodyPositions[planet2].longitude);
            /*qDebug() << "planet: " << bodyPositions[planet1].name << "angle: " << bodyPositions[planet1].longitude;
            qDebug() << "angle: " << angle;
            qDebug() << "planet 2: " << bodyPositions[planet2].name << "angle: " << bodyPositions[planet2].longitude;*/
            while(!find && (j <= 18)){
                //chequeo por aspecto j
                //qDebug() << "j: " << j;

                /*qDebug() << "angle: " << angle;
                qDebug() << "angle2: " << distanceDegree(angle, AspectSet[j].angle);*/
                if(diffDegree(angle, AspectSet[j].angle) < (AspectSet[j].orb * .85)){
                    /*qDebug() << "woah!";
                    qDebug() << "planet: " << bodyPositions[planet1].name;
                    qDebug() << "angle: " << angle;
                    qDebug() << "aspect angle: " << AspectSet[j].angle << " orb: " << AspectSet[j].orb;
                    qDebug() << "asp: " << AspectSet[j].name;
                    qDebug() << "planet 2: " << bodyPositions[planet2].name;*/
                    find = true;
                    AspectInfo asp;
                    asp.asp = &AspectSet[j];
                    asp.aspect = AspectSet[j].number;
                    asp.diff = diffDegree(angle, AspectSet[j].angle);
                    asp.planet1 = bodyPositions[planet1].number;
                    asp.planet2 = bodyPositions[planet2].number;
                    aspectarium.append(asp);
                };
                j++;
            };
            //if(find){};
        };
    };

    //qDebug() << "1";
    //lon = pd.lon_deg + pd.lon_min / 60.0 + pd.lon_sec / 3600.0;
    lon = -(10/60.0);
    sidt += lon / 15;
    //qDebug() << sidt;
    if (sidt >= 24) sidt -= 24;
    if (sidt < 0) sidt += 24;
    armc = sidt * 15;
    //qDebug() << "armc: " << armc;

    //qDebug() << "houses";
/*    for(int i = 0; i <=12; i++){
        qDebug() << "House " << i << " : " << this->housesCusps[i];
    };*/

    //double x[6];
    //double *x = swe->swe_calc(this->juliandate, -1, 0);
    /*for(int i = 0; i < 6; i++){
        qDebug() << "x[" << i << "]: " << x[i];
    };*/

    //calculo de houses
    //QVector<QString> dist[4][3];
    qDebug() << "q";
    QVector<int> dist[4][3];
    for(int i = 0; i <= 12; ++i){
        //if(sky.skyObject[i].body->GetType() != Body::ePlanet) continue;
        //double sign2, sign3;
        int sign;
        //int element;
        /*if(bySign){
                sign = sky.GetSign(i)';
                element = horoscope.settings->signSet.sign[sign].GetElement();
        }else{
                sign = sky.GetHouse(i);
                element = (GlyphObj::Element)(sign % 4);
        }*/
        /*sign2 = GetHousePos(bodyPositions[i].longitude, bodyPositions[i].latitude, this->housesCusps);
        double pos[2];

        pos[0] = bodyPositions[i].longitude;
        pos[1] = bodyPositions[i].latitude;
        sign3 = swe->swe_house_pos(armc, this->lat, x[0], pos);
        sign = sign2;
        /*bodyPositions[i].house = sign3 +.5;
        sign = sign3 + .5;*/
        //element = sign 4;
        if(bodyPositions[i].name == "Earth") continue;
        sign = bodyPositions[i].house;
        qDebug() << "sign: " << sign;

        //dist[sign % 4][sign % 3].push_back(bodyPositions[i].name);
        dist[sign % 4][sign % 3].push_back(bodyPositions[i].number);
    };
    qDebug() << "q";
    for(unsigned int el = 0; el < 4; el++){
        for(unsigned int mod = 0; mod < 3; mod++){
            //qDebug() << "el: " << el << "mod: " << mod;
            for(unsigned int i =0; i < dist[el][mod].size(); i++){
                //qDebug() << dist[el][mod][i];
                if(dist[el][mod][i] == 14) continue;
                DistributionHousesInfo info;
                if(el == 0) info.house = 4;
                if(el == 1) info.house = 1;
                if(el == 2) info.house = 10;
                if(el == 3) info.house = 7;

                if(mod == 0) info.type = "ca";
                if(mod == 1) info.type = "an";
                if(mod == 2) info.type = "su";

                info.planet = dist[el][mod][i];

                houseDistribution << info;
            }
        }
    }

    QVector<int> dist2[4][3];
    for(int i = 0; i <= 10; ++i){
        //if(sky.skyObject[i].body->GetType() != Body::ePlanet) continue;
        double sign2, sign3;
        int sign;
        int element;
        /*if(bySign){
                sign = sky.GetSign(i);
                element = horoscope.settings->signSet.sign[sign].GetElement();
        }else{
                sign = sky.GetHouse(i);
                element = (GlyphObj::Element)(sign % 4);
        }*/
        sign = (int)(bodyPositions[i].longitude / 30.0) % 12;
        element = sign % 4;
        switch(element){
            case 0:
                {
                    dist2[0][sign % 3].push_back(bodyPositions[i].number);
                    break;
                }
            case 1:
                {
                    dist2[1][sign % 3].push_back(bodyPositions[i].number);
                    break;
                }
            case 2:
                {
                    dist2[2][sign % 3].push_back(bodyPositions[i].number);
                    break;
                }
            case 3:
                {
                    dist2[3][sign % 3].push_back(bodyPositions[i].number);
                    break;
                }
            default:
                dist2[sign % 4][sign % 3].push_back(bodyPositions[i].number);
        }
        //qDebug() << "body: " << bodyPositions[i].name << " house: " << sign2 << "  " << sign3;

        //dist[sign % 4][sign % 3].push_back(bodyPositions[i].number);
    };

    for(unsigned int el = 0; el < 4; el++){
        for(unsigned int mod = 0; mod < 3; mod++){
            //qDebug() << "el: " << el << "mod: " << mod;
            for(unsigned int i =0; i < dist2[el][mod].size(); i++){
                //qDebug() << dist2[el][mod][i];
                    DistributionSignInfo info;
                    if(dist2[el][mod][i] == 14) continue;
                    if(mod == 0) info.column = "ca";
                    if(mod == 1) info.column = "fi";
                    if(mod == 2) info.column = "mu";

                    if(el == 0) info.sign = "fu";
                    if(el == 1) info.sign = "ti";
                    if(el == 2) info.sign = "ai";
                    if(el == 3) info.sign = "ag";

                    info.planet = dist2[el][mod][i];

                    signDistribution << info;
            }
        }
    }

    QVector<int> dist3[2][2];
    for(unsigned int i = 0; i <= 10; i++){
        if(Normalize(this->housesAscmc[0] - bodyPositions[i].longitude) < 180.0){
            if(Normalize(this->housesAscmc[1] - bodyPositions[i].longitude) > 180.0){
                dist3[0][0].push_back(bodyPositions[i].number);
            }else{
                dist3[0][1].push_back(bodyPositions[i].number);
            }
        }else{
            if(Normalize(this->housesAscmc[1] - bodyPositions[i].longitude) > 180.0){
                dist3[1][0].push_back(bodyPositions[i].number);
            }else{
                dist3[1][1].push_back(bodyPositions[i].number);
            }
        }
    }
    for(unsigned int el = 0; el < 2; el++){
        for(unsigned int mod = 0; mod < 2; mod++){
            //qDebug() << "el: " << el << "mod: " << mod;
            for(unsigned int i =0; i < dist3[el][mod].size(); i++){
                //qDebug() << dist3[el][mod][i];
                if(dist3[el][mod][i] == 14) continue;
                QuadrantsInfo info;
                if(el == 0) info.code = "ab"; else info.code = "be";
                if(mod == 0) info.eastwest = "es"; else info.eastwest = "we";
                info.planet = dist3[el][mod][i];
                quadrantsDistribution << info;
            }
        }
    };

    //aspectarium.clear(); ta
    //signDistribution.clear();
    //houseDistribution.clear();
    // quadrantsDistribution.clear();
    // positions.clear(); ta;

    //qDebug() << "elapsed: " << mytimer.elapsed();

    /*for(int i = 0; i < aspectarium.length(); i++){
        qDebug() << i;
    };*/

    /*qDebug() << aspectarium;
    qDebug() << quadrantsDistribution;
    qDebug() << signDistribution;
    qDebug() << positions;
    qDebug() << houseDistribution;*/
    qDebug() << "fin";
}

void astroInfo::loadAspectSet(){
    this->AspectSet[1].name = QString("Conjunction");
    this->AspectSet[1].angle = 0.0;
    this->AspectSet[1].orb = 10.0;
    this->AspectSet[1].solilunarExt = 2.0;
    this->AspectSet[1].number = 1;

    this->AspectSet[2].name = QString("Opposition");
    this->AspectSet[2].angle = 180.0;
    this->AspectSet[2].orb = 10.0;
    this->AspectSet[2].solilunarExt = 2.0;
    this->AspectSet[2].number = 2;

    this->AspectSet[3].name = QString("Trine");
    this->AspectSet[3].angle = 120.0;
    this->AspectSet[3].orb = 6.0;//8.0;
    this->AspectSet[3].solilunarExt = 0.0;
    this->AspectSet[3].number = 3;

    this->AspectSet[4].name = QString("Square");
    this->AspectSet[4].angle = 90.0;
    this->AspectSet[4].orb = 6.0;
    this->AspectSet[4].solilunarExt = 0.0;
    this->AspectSet[4].number = 4;

    this->AspectSet[5].name = QString("Quintile");
    this->AspectSet[5].angle = 72.0;
    this->AspectSet[5].orb = 3.0;
    this->AspectSet[5].solilunarExt = 0.0;
    this->AspectSet[5].number = 5;

    this->AspectSet[6].name = QString("Biquintile");
    this->AspectSet[6].angle = 144.0;
    this->AspectSet[6].orb = 3.0;
    this->AspectSet[4].solilunarExt = 0.0;
    this->AspectSet[4].number = 6;

    this->AspectSet[7].name = QString("Sextile");
    this->AspectSet[7].angle = 60.0;
    this->AspectSet[7].orb = 4.0;
    this->AspectSet[7].solilunarExt = 0.0;
    this->AspectSet[7].number = 7;

    this->AspectSet[8].name = QString("Septile");
    this->AspectSet[8].angle = 51 + (25.0 / 60.0) + (43.0 / 3600.0);
    this->AspectSet[8].orb = 1.5;
    this->AspectSet[8].solilunarExt = 0.0;
    this->AspectSet[8].number = 8;

    this->AspectSet[9].name = QString("Biseptile");
    this->AspectSet[9].angle = 102 + (51.0 / 60.0) + (26.0 / 3600.0);
    this->AspectSet[9].orb = 1.5;
    this->AspectSet[9].solilunarExt = 0.0;
    this->AspectSet[9].number = 9;

    this->AspectSet[10].name = QString("Triseptile");
    this->AspectSet[10].angle = 154 +(17.0 / 60.0) +(9 / 3600.0);
    this->AspectSet[10].orb = 1.5;
    this->AspectSet[10].solilunarExt = 0.0;
    this->AspectSet[10].number = 10;

    this->AspectSet[11].name = QString("Octile");
    this->AspectSet[11].angle = 45.0;
    this->AspectSet[11].orb = 3.0;
    this->AspectSet[11].solilunarExt = 0.0;
    this->AspectSet[11].number = 11;

    this->AspectSet[12].name = QString("Trioctile");
    this->AspectSet[12].angle = 135.0;
    this->AspectSet[12].orb = 3.0;
    this->AspectSet[12].solilunarExt = 0.0;
    this->AspectSet[12].number = 12;

    this->AspectSet[13].name = QString("Novile");
    this->AspectSet[13].angle = 40.0;
    this->AspectSet[13].orb = 2.0;
    this->AspectSet[13].solilunarExt = 0.0;
    this->AspectSet[13].number = 13;

    this->AspectSet[14].name = QString("Decile");
    this->AspectSet[14].angle = 36.0;
    this->AspectSet[14].orb = 2.0;
    this->AspectSet[14].solilunarExt = 0.0;
    this->AspectSet[14].number = 14;

    this->AspectSet[15].name = QString("Tridecile");
    this->AspectSet[15].angle = 108.0;
    this->AspectSet[15].orb = 2.0;
    this->AspectSet[15].solilunarExt = 0.0;
    this->AspectSet[15].number = 15;

    this->AspectSet[16].name = QString("Semisextile");
    this->AspectSet[16].angle = 30.0;
    this->AspectSet[16].orb = 2.0;
    this->AspectSet[16].solilunarExt = 0.0;
    this->AspectSet[16].number = 16;

    this->AspectSet[17].name = QString("Quincunx");
    this->AspectSet[17].angle = 150.0;
    this->AspectSet[17].orb = 2.0;
    this->AspectSet[17].solilunarExt = 0.0;
    this->AspectSet[17].number = 17;

    this->AspectSet[18].name = QString("Undecile");
    this->AspectSet[18].angle = 32 + (43 / 60.0) + (38 / 3600.0);
    this->AspectSet[18].orb = 0.5;
    this->AspectSet[18].solilunarExt = 0.0;
    this->AspectSet[18].number = 18;
}

void astroInfo::loadBodySet(){
    for(int i = 0; i <= 10; i++){
        Body currentBody = bodyPositions[i];
        clearBody(&currentBody);
    };
    this->bodyPositions[0].name = QString("Sun");
    this->bodyPositions[0].number = 0;
    this->bodyPositions[1].name = QString("Mercury");
    this->bodyPositions[1].number = 2;
    this->bodyPositions[2].name = QString("Venus");
    this->bodyPositions[2].number = 3;
    this->bodyPositions[3].name = QString("Earth");
    this->bodyPositions[3].number = 14;
    this->bodyPositions[4].name = QString("Moon");
    this->bodyPositions[4].number = 1;
    this->bodyPositions[5].name = QString("Mars");
    this->bodyPositions[5].number = 4;
    this->bodyPositions[6].name = QString("Jupiter");
    this->bodyPositions[6].number = 5;
    this->bodyPositions[7].name = QString("Saturn");
    this->bodyPositions[7].number = 6;
    this->bodyPositions[8].name = QString("Uranus");
    this->bodyPositions[8].number = 7;
    this->bodyPositions[9].name = QString("Neptune");
    this->bodyPositions[9].number = 8;
    this->bodyPositions[10].name = QString("Pluto");
    this->bodyPositions[10].number = 9;
    this->bodyPositions[11].name = QString("Mean Node");
    this->bodyPositions[11].number = 10;
    this->bodyPositions[12].name = QString("Lilith");
    this->bodyPositions[12].number = 12;
    this->bodyPositions[13].name = QString("Part of Fortune");
    this->bodyPositions[13].number = 11;
    this->bodyPositions[14].name = QString("Asc");
    this->bodyPositions[14].number = 15;
    this->bodyPositions[15].name = QString("Mc");
    this->bodyPositions[15].number = 13;
}

double astroInfo::GetHousePos(double longitude, double latitude, double* cusp){
    int house = 0;
    int tope = 0;
    for(unsigned int i = 1; i < 13; i++){
        tope = i + 1;
        if(tope ==  13) tope = 1;
       // qDebug() << i;
        if(cusp[i] > cusp[tope]){
            if((cusp[i] <= longitude && longitude < 360) || (longitude > 0 && longitude <= cusp[tope])) house = i;
           // qDebug() << "al reves" << "cusp: " << cusp[i] << "long: " << longitude << "cusp+1: " << cusp[tope] << longitude << house;
        }else{
            if(cusp[i] <= longitude && cusp[tope] > longitude) house = i;
            //qDebug() << "cusp: " << cusp[i] << "long: " << longitude << "cusp+1: " << cusp[tope] << longitude << house;
        };


    };
    return house;
    /*double l = Normalize(longitude - cusp[0]);
    //qDebug() << l;
    for(unsigned int i = 0; i < 12; i++){
            double maxi = ((i == 11) ? 360 : Normalize(cusp[i + 1] - cusp[0]));
            double mini =  Normalize(cusp[i] - cusp[0]);
            if( l >= mini && l < maxi){
                    return  ((l - mini) / (maxi - mini) + (double)i); //* 10.0;
            }
    }
    return -1;*/
}
