#include "dataprocessor.h"

dataProcessor::dataProcessor(QObject *parent) :
    QObject(parent)
{
    useSisigia = false;
    useNormal = true;

    weatherPercent = 100;
    aspectPercent = 100;
    signPercent = 100;
    positionPercent = 100;
    quadrantPercent = 100;
    housePercent = 100;

    /*QSqlQuery *query = new QSqlQuery();
    query->exec("CREATE TEMPORARY TABLE IF NOT EXISTS processedWeather ("
                "`id` int(11) NOT NULL AUTO_INCREMENT,"
                "`fecha` datetime NOT NULL,"
                "`maxima` decimal(7,4) NOT NULL,"
                "`minima` decimal(7,4) NOT NULL,"
                "`vientovel` decimal(7,4) NOT NULL,"
                "`direccionviento` decimal(7,4) NOT NULL,"
                "`precipitacion` smallint(6) NOT NULL,"
                "`mil500` smallint(6) NOT NULL,"
                "`observaciones` text NOT NULL,"
                "`tipo` varchar(32) NOT NULL,"
                "PRIMARY KEY (`id`)"
                ")");
    qDebug() << query->lastQuery() << query->lastError();*/
    setAstralWeather();
}

dataProcessor::~dataProcessor(){
    clearAspects();
    clearWeather();
}

void dataProcessor::processAspects(){
    qDebug() << "processAspects";
    spatResult.clear();

    qDebug() << "process weather";
    QStringList weakAspectQuery;
    QStringList strongAspectQuery;
    QString querystring;
    QSqlQuery query;

    querystring = "SELECT fecha FROM  ";

    for(int i = 0; i < aspectsWeak.count(); i++){
        metAstro::aspectParameter *param = aspectsWeak.at(i);
        weakAspectQuery << QString("(SELECT fecha FROM aspectariums WHERE (((planeta1 = %1 AND planeta2 = %2) OR (planeta1 = %3 AND planeta2 = %4)) AND conjuncion = %5))").arg(param->planet1).arg(param->planet2).arg(param->planet2).arg(param->planet1).arg(param->aspect);
    };

    for(int i = 0; i < aspects.count(); i++){
        metAstro::aspectParameter *param = aspects.at(i);
        strongAspectQuery << QString("(SELECT fecha FROM aspectariums WHERE (((planeta1 = %1 AND planeta2 = %2) OR (planeta1 = %3 AND planeta2 = %4)) AND conjuncion = %5))").arg(param->planet1).arg(param->planet2).arg(param->planet2).arg(param->planet1).arg(param->aspect);
    };

    if(doStrongAspects){
        //if(!strongAspectQuery.isEmpty()) querystring += "WHERE " + strongAspectQuery.join(" AND ");
        if(!strongAspectQuery.isEmpty()){
            if(strongAspectQuery.count() > 1)
                querystring += strongAspectQuery.join(" JOIN ") + " USING (fecha)";
            else
                querystring += strongAspectQuery.at(0);
        };
    }else{
        if(doWeakAspects){
            //if(strongAspectQuery.isEmpty()) querystring += "WHERE " + weakAspectQuery.join(" AND ");
            if(weakAspectQuery.isEmpty()){
                if(weakAspectQuery.count() > 1)
                    querystring += weakAspectQuery.join(" JOIN ") + " USING (fecha)";
                else
                    querystring += weakAspectQuery.at(0);
            };
        };
    };

    querystring += " ORDER BY fecha";

    query.exec(querystring);
    lastSqlResult = querystring;
    qDebug() << query.lastQuery() << query.lastError();
    while(query.next()) spatResult << QDateTime::fromString(query.record().field("fecha").value().toString(), "yyyy-MM-dd hh:mm:ss");


    /*QString querystring = QString("(SELECT * FROM aspectariums WHERE fecha >= '%1' AND fecha <= '%2')").arg(this->initDate.toString("yyyy-MM-dd")).arg(this->finishDate.toString("yyyy-MM-dd"));
    QString where = "", whereWeak = "";
    QStringList closures;
    QStringList weakClosures;
    QList<QDateTime> timestamps;
    metAstro::aspectParameter *asp;

    if(doStrongAspects){
        for(int i = 0; i < this->aspects.count(); ++i){
            where = "(";
            asp = this->aspects.at(i);
            where += QString(" planeta1 = %1 AND ").arg(asp->planet1);
            where += QString(" planeta2 = %1 AND ").arg(asp->planet2);
            where += QString(" conjuncion = %1 ").arg(asp->aspect);
            if(asp->computeGrade) where += QString("AND ((totaldif => %1) OR (totaldif <= %2))").arg(asp->grade - asp->gradeTolerance).arg(asp->grade + asp->gradeTolerance);
            if(asp->computeMinutes) where += QString("AND ((mindif => %1) OR (mindif <= %2))").arg(asp->minutes - asp->minutesTolerance).arg(asp->minutes + asp->minutesTolerance);
            if(asp->computeSeconds) where += QString("AND ((segdif => %1) OR (segdif <= %2))").arg(asp->seconds - asp->secondsTolerance).arg(asp->seconds + asp->secondsTolerance);
            where += ")";
            closures << where;
        };
        where = closures.join(" AND ");
    };

    if(doWeakAspects){
        for(int i = 0; i < this->aspectsWeak.count(); ++i){
            whereWeak = "(";
            asp = this->aspectsWeak.at(i);
            whereWeak += QString(" planeta1 = %1 AND ").arg(asp->planet1);
            whereWeak += QString(" planeta2 = %1 AND ").arg(asp->planet2);
            whereWeak += QString(" conjuncion = %1 ").arg(asp->aspect);
            if(asp->computeGrade) whereWeak += QString("AND ((totaldif => %1) OR (totaldif <= %2))").arg(asp->grade - asp->gradeTolerance).arg(asp->grade + asp->gradeTolerance);
            if(asp->computeMinutes) whereWeak += QString("AND ((mindif => %1) OR (mindif <= %2))").arg(asp->minutes - asp->minutesTolerance).arg(asp->minutes + asp->minutesTolerance);
            if(asp->computeSeconds) whereWeak += QString("AND ((segdif => %1) OR (segdif <= %2))").arg(asp->seconds - asp->secondsTolerance).arg(asp->seconds + asp->secondsTolerance);
            whereWeak += ")";
            closures << whereWeak;
        };
        whereWeak = "(" + weakClosures.join(" OR ") + ")";
    };

    if(doWeakAspects){
        if(where.isEmpty()){
            where = whereWeak;
        }else{
            if(!whereWeak.isEmpty()){
                where += " AND " + whereWeak;
            }
        };
    };

    QSqlQuery *query = new QSqlQuery();
    if(firstTest){
        query->exec(querystring);
        while(query->next()) this->spatResult << query->record().field("fecha").value().toDateTime();
        firstTest = false;
    };

    for(int i = 0; i < this->spatResult.count(); ++i){
        query->exec(QString("SELECT fecha FROM aspectarium WHERE fecha = '%1' AND %2"));
        if(query->next()) timestamps << this->spatResult.at(i);
    };

    //refresh valid timestamp
    this->spatResult.clear();
    for(int i = 0; i < timestamps.count(); ++i) this->spatResult << timestamps.at(i);

    /*query->exec("TRUNCATE TABLE processedWeather");
    qDebug() << query->lastQuery() << query->lastError();

    query->exec("INSERT INTO processedWeather SELECT * FROM estadotiempos WHERE fecha IN (SELECT fecha FROM " + querystring + " AS tabla WHERE " + where + ")");
    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        qDebug() << query->record().field("fecha").value().toDateTime();
        timestamps << query->record().field("fecha").value().toDateTime();
        //timestamps;
    };*
    qDebug() << "aspect finish";
    delete query;
    emit finish();*/
}

void dataProcessor::processWeather(){
    spatResult.clear();

    qDebug() << "process weather";
    QStringList weakWeatherQuery;
    QStringList strongWeatherQuery;
    QString querystring;
    QSqlQuery query;

    for(int i = 0; i < weathersWeak.count(); i++){
        metAstro::weatherParameter *param = weathersWeak.at(i);
        weakWeatherQuery << "(" + param->parameter + " >= " + QString("%1").arg(param->value - param->tolerance) + " AND " + param->parameter + " <= " + QString("%1").arg(param->value + param->tolerance) + ")";
    };

    for(int i = 0; i < weathers.count(); i++){
        metAstro::weatherParameter *param = weathers.at(i);
        strongWeatherQuery << "(" + param->parameter + " >= " + QString("%1").arg(param->value - param->tolerance) + " AND " + param->parameter + " <= " + QString("%1").arg(param->value + param->tolerance) + ")";
    };

    querystring = "SELECT strftime('%Y-%m-%d', fecha) as fecha FROM " + weatherTable;
    Q_ASSERT(_usaf.length() > 0);
    if(doStrongWeathers){
        if(!strongWeatherQuery.isEmpty()){
            querystring += " WHERE usaf = '" + _usaf + "'" + strongWeatherQuery.join(" AND ");
        };
    }else{
        if(doWeakWeathers){
            if(!weakWeatherQuery.isEmpty()){
                querystring += " WHERE usaf = '" + _usaf + "'" + strongWeatherQuery.join(" OR ");
            };
        };
    };

    querystring += " ORDER BY fecha";

    query.exec(querystring);
    lastSqlResult = querystring;
    qDebug() << query.lastQuery() << query.lastError();
    //while(query.next()) spatResult << QDateTime::fromString(query.record().field("fecha").value().toString(), "yyyy-MM-dd hh:mm:ss");
    while(query.next()) spatResult << QDateTime::fromString(query.record().field("fecha").value().toString(), "yyyy-MM-dd");
}

int dataProcessor::getDignity(int planet, double longitude){
    int sign;
    int dignity;
    dignity = metAstro::None;
    //sign = ((int)longitude % 30) + 1;
    sign = (((int)longitude / 30) % 12) + 1;
    switch(sign){
        case 1:
            if(planet == 4) dignity = metAstro::Rules;
            if(planet == 0) dignity = metAstro::Exaltation;
            if(planet == 3) dignity = metAstro::Detriment;
            if(planet == 6) dignity = metAstro::Fall;
            break;
        case 2:
            if(planet == 3) dignity = metAstro::Rules;
            if(planet == 1) dignity = metAstro::Exaltation;
            if(planet == 4) dignity = metAstro::Detriment;
            break;
        case 3:
            if(planet == 2) dignity = metAstro::Rules;
            if(planet == 5) dignity = metAstro::Detriment;
            break;
        case 4:
            if(planet == 1) dignity = metAstro::Rules;
            if(planet == 5) dignity = metAstro::Exaltation;
            if(planet == 6) dignity = metAstro::Detriment;
            if(planet == 4) dignity = metAstro::Fall;
            break;
        case 5:
            if(planet == 0) dignity = metAstro::Rules;
            if(planet == 6) dignity = metAstro::Detriment;
            break;
        case 6:
            //if(planet == 2) dignity = metAstro::Rules;
            if(planet == 2) dignity = metAstro::Rules | metAstro::Exaltation;
            if(planet == 6) dignity = metAstro::Detriment;
            if(planet == 3) dignity = metAstro::Fall;
            break;
        case 7:
            if(planet == 3) dignity = metAstro::Rules;
            if(planet == 6) dignity = metAstro::Exaltation;
            if(planet == 4) dignity = metAstro::Detriment;
            if(planet == 0) dignity = metAstro::Fall;
            break;
        case 8:
            if(planet == 4) dignity = metAstro::Rules;
            if(planet == 3) dignity = metAstro::Detriment;
            if(planet == 1) dignity = metAstro::Fall;
            break;
        case 9:
            if(planet == 5) dignity = metAstro::Rules;
            if(planet == 2) dignity = metAstro::Detriment;
            break;
        case 10:
            if(planet == 6) dignity = metAstro::Rules;
            if(planet == 4) dignity = metAstro::Exaltation;
            if(planet == 1) dignity = metAstro::Detriment;
            if(planet == 5) dignity = metAstro::Fall;
            break;
        case 11:
            if(planet == 6) dignity = metAstro::Rules;
            if(planet == 0) dignity = metAstro::Detriment;
            break;
        case 12:
            if(planet == 5) dignity = metAstro::Rules;
            if(planet == 3) dignity = metAstro::Exaltation;
            //if(planet == 2) dignity = metAstro::Detriment;
            if(planet == 2) dignity = metAstro::Fall | metAstro::Detriment;
            break;
    };
    return dignity;
}

QString dataProcessor::getDignityName(metAstro::dignityType type){
    if(type == metAstro::None) return "Ninguno";
    if(type == metAstro::Rules) return "Rige";
    if(type == metAstro::Exaltation) return "Exaltado";
    if(type == metAstro::Detriment) return "Detrimento";
    if(type == metAstro::Fall) return "Caida";
}

int dataProcessor::getSignByDignity(metAstro::dignityParam param){
    int sign = 0;
    int planet = param.planet;
    switch(param.dignity){
        case metAstro::Rules:
            if(planet == 0) sign = 5;
            if(planet == 1) sign = 4;
            if(planet == 2) sign = 306;
            if(planet == 3) sign = 702;
            if(planet == 4) sign = 108;
            if(planet == 5) sign = 913;
            if(planet == 6) sign = 1110;
            break;
        case metAstro::Exaltation:
            if(planet == 0) sign = 1;
            if(planet == 1) sign = 2;
            if(planet == 5) sign = 4;
            if(planet == 2) sign = 6;
            if(planet == 6) sign = 7;
            if(planet == 4) sign = 10;
            if(planet == 3) sign = 12;
            break;
        case metAstro::Detriment:
            if(planet == 0) sign = 11;
            if(planet == 1) sign = 10;
            if(planet == 2) sign = 912;
            if(planet == 3) sign = 108;
            if(planet == 4) sign = 207;
            if(planet == 5) sign = 306;
            if(planet == 6) sign = 405;
            break;
        case metAstro::Fall:
            if(planet == 0) sign = 7;
            if(planet == 1) sign = 8;
            if(planet == 2) sign = 12;
            if(planet == 3) sign = 6;
            if(planet == 4) sign = 4;
            if(planet == 5) sign = 10;
            if(planet == 6) sign = 1;
            break;
        default:
            sign = 0;
    };
    return sign;
}

void dataProcessor::processHouses(){

}

void dataProcessor::processPositions(){

}

void dataProcessor::processQuadrants(){

}

void dataProcessor::processSings(){

}

void dataProcessor::startProcess(){
    this->firstTest = true;

    processAspects();
    processWeather();
    processHouses();
    processPositions();
    processQuadrants();
    processSings();
}

void dataProcessor::processResults(){
    QSqlQuery query;

    // clear previous result
    aspectsResult.clear();
    housesResult.clear();
    positionResult.clear();
    quadrantsResult.clear();
    signResult.clear();

    // Aspectariums
    qDebug() << "Aspectariums";
    query.exec(QString("SELECT count(fecha) as t, * FROM aspectariums WHERE strftime('%Y-%m-%d', fecha) IN (%1) GROUP BY planeta1, planeta2 HAVING t >= %2 ORDER BY t DESC").arg(this->lastSqlResult).arg(spatResult.count() * (double)(positionPercent / 100.0)));
    qDebug() << query.lastQuery() << query.lastError();
    while(query.next()){
        astroInfo::AspectInfo dato;
        metAstro::aspectResultParam param;
        dato.planet1 = query.record().field("planeta1").value().toInt();
        dato.planet2 = query.record().field("planeta2").value().toInt();
        param.data = dato;
        param.times = query.record().field("t").value().toInt();
        aspectsResult << param;
    };
        //qDebug() << query.record().field("t").value().toInt() << query.record().field("planeta1").value().toInt() << query.record().field("planeta2").value().toInt();

    //positions
    qDebug() << "positions";
    query.exec(QString("SELECT count(fecha) as t, * FROM posiciones WHERE strftime('%Y-%m-%d', fecha) IN (%1) GROUP BY planeta, signo HAVING t >= %2 ORDER BY t DESC").arg(this->lastSqlResult).arg(spatResult.count() * (double)(positionPercent / 100.0)));
    qDebug() << query.lastQuery() << query.lastError();
    while(query.next()){
        astroInfo::PositionInfo dato;
        metAstro::positionResultParam param;
        dato.planet = query.record().field("planeta").value().toInt();
        dato.sign = query.record().field("signo").value().toInt();
        param.data = dato;
        param.times = query.record().field("t").value().toInt();
        positionResult << param;
    };
        //qDebug() << query.record().field("t").value().toInt() << query.record().field("planeta").value().toInt() << query.record().field("signo").value().toInt();

    //signs
    qDebug() << "signs";
    query.exec(QString("SELECT count(fecha) as t, * FROM signos WHERE strftime('%Y-%m-%d', fecha) IN (%1) GROUP BY planeta, signo, columna HAVING t >= %2 ORDER BY t DESC").arg(this->lastSqlResult).arg(spatResult.count() * (double)(signPercent / 100.0)));
    qDebug() << query.lastQuery() << query.lastError();
    while(query.next()){
        astroInfo::DistributionSignInfo dato;
        metAstro::signResultParam param;
        dato.column = query.record().field("columna").value().toString();
        dato.planet = query.record().field("planeta").value().toInt();
        dato.sign = query.record().field("signo").value().toString();
        param.data = dato;
        param.times = query.record().field("t").value().toInt();
        signResult << param;
    };
        //qDebug() << query.record().field("t").value().toInt() << query.record().field("planeta").value().toInt() << query.record().field("signo").value().toString() << query.record().field("columna").value().toString();

    //quadrants
    qDebug() << "quadrants";
    query.exec(QString("SELECT count(fecha) as t, * FROM cuadrantes WHERE strftime('%Y-%m-%d', fecha) IN (%1) GROUP BY planeta, codigo, esteoeste HAVING t >= %2 ORDER BY t DESC").arg(this->lastSqlResult).arg(spatResult.count() * (double)(quadrantPercent / 100.0)));
    qDebug() << query.lastQuery() << query.lastError();
    while(query.next()){
        astroInfo::QuadrantsInfo dato;
        metAstro::quadrantsResultParam param;
        dato.code = query.record().field("codigo").value().toInt();
        dato.eastwest = query.record().field("esteoeste").value().toString();
        dato.planet = query.record().field("planeta").value().toInt();
        param.data = dato;
        param.times = query.record().field("t").value().toInt();
        quadrantsResult << param;
    };
        //qDebug() << query.record().field("t").value().toInt() << query.record().field("planeta").value().toInt() << query.record().field("codigo").value().toInt() << query.record().field("esteoeste").value().toString();

    //houses
    qDebug() << "houses";
    qDebug() << spatResult.count() * (double)(positionPercent / 100.0);
    query.exec(QString("SELECT count(fecha) as t, * FROM casas WHERE strftime('%Y-%m-%d', fecha) IN (%1) GROUP BY planeta, codigotipo, codigocasa HAVING t >= %2 ORDER BY t DESC").arg(this->lastSqlResult).arg(spatResult.count() * (double)(housePercent / 100.0)));
    qDebug() << query.lastQuery() << query.lastError();
    while(query.next()){
        astroInfo::DistributionHousesInfo dato;
        metAstro::houseResultParam param;
        dato.house = query.record().field("codigocasa").value().toInt();
        dato.planet = query.record().field("planeta").value().toInt();
        dato.type = query.record().field("codigotipo").value().toString();
        param.data = dato;
        param.times = query.record().field("t").value().toInt();
        housesResult << param;
    };
        //qDebug() << query.record().field("t").value().toInt() << query.record().field("planeta").value().toInt() << query.record().field("codigotipo").value().toString() << query.record().field("codigocasa").value().toInt();


}

QString dataProcessor::getSqlResult(processTypeReturn ret){
    QString where, sqlquery;
    sqlquery = "SELECT * FROM ";
    enum    processTypeReturn { Aspects, Weathers, Houses, Positions, Signs, Quadrants};
    switch(ret){
        case Aspects:
            sqlquery += "aspectariums";
            break;
        case Weathers:
            sqlquery += "estadotiempos";
            break;
        case Houses:
            sqlquery += "casas";
            break;
        case Positions:
            sqlquery += "posiciones";
            break;
        case Sings:
            sqlquery += "signos";
            break;
        case Quadrants:
            sqlquery += "cuadrantes";
            break;
    };
    QStringList wherelist;
    for(int i = 0; i < this->spatResult.count(); ++i){
        wherelist << "fecha LIKE '" + this->spatResult.at(i).toString() + "'";
    };
    where = wherelist.join(" OR ");
    sqlquery += " WHERE " + where;
    return sqlquery;
}

QString dataProcessor::retrievePlanet(int planet){
    QString result;
    QSqlQuery query;
    query.exec(QString("SELECT * FROM planetas WHERE num = %1").arg(planet));
    query.next();
    result = query.record().field("planeta").value().toString();
    /*switch(planet){
        case 1:
            result = "Sol";
            break;
        case 2:
            result = "Luna";
            break;
        case 3:
            result = "Mercurio";
            break;
        case 4:
            result = "Venus";
            break;
        case 5:
            result = "Martes";
            break;
        case 6:
            result = "Jupiter";
            break;
        case 7:
            result = "Saturno";
            break;
        case 8:
            result = "Urano";
            break;
        case 9:
            result = "Neptuno";
            break;
        case 10:
            result = "Pluton";
            break;
        case 11:
            result = "Ascendente";
            break;
        case 12:
            result = "MC";
            break;
        case 13:
            result = "Nodo";
            break;
        case 14:
            result = "Lilith";
            break;
        case 15:
            result = "Fortuna";
            break;
        default:
            result = "null";
            break;
    };*/
    return result;
}

QString dataProcessor::retrievePlanet1(metAstro::aspectParameter *aspect){
    return this->retrievePlanet(aspect->planet1);
}
QString dataProcessor::retrievePlanet2(metAstro::aspectParameter *aspect){
    return this->retrievePlanet(aspect->planet2);
}
QString dataProcessor::retrieveAspect(metAstro::aspectParameter *aspect){
    QString result;
    switch(aspect->aspect){
        case 1:
                result = "Conjunction";
                break;
        case 2:
                result = "Opposition";
                break;
        case 3:
                result = "Trine";
                break;
        case 4:
                result = "Square";
                break;
        case 5:
                result = "Quintile";
                break;
        case 6:
                result = "Biquintile";
                break;
        case 7:
                result = "Sextile";
                break;
        case 8:
                result = "Septile";
                break;
        case 9:
                result = "Biseptile";
                break;
        case 10:
                result = "Triseptile";
                break;
        case 11:
                result = "Octile";
                break;
        case 12:
                result = "Trioctile";
                break;
        case 13:
                result = "Novile";
                break;
        case 14:
                result = "Decile";
                break;
        case 15:
                result = "Tridecile";
                break;
        case 16:
                result = "Semisextile";
                break;
        case 17:
                result = "Quincunx";
                break;
        case 18:
                result = "Undecile";
                break;
         default:
                result = "null";
    };

    return result;
}



QString dataProcessor::retrieveAspect(int aspect){
    QString result;
    switch(aspect){
        case 1:
                result = "Conjunction";
                break;
        case 2:
                result = "Opposition";
                break;
        case 3:
                result = "Trine";
                break;
        case 4:
                result = "Square";
                break;
        case 5:
                result = "Quintile";
                break;
        case 6:
                result = "Biquintile";
                break;
        case 7:
                result = "Sextile";
                break;
        case 8:
                result = "Septile";
                break;
        case 9:
                result = "Biseptile";
                break;
        case 10:
                result = "Triseptile";
                break;
        case 11:
                result = "Octile";
                break;
        case 12:
                result = "Trioctile";
                break;
        case 13:
                result = "Novile";
                break;
        case 14:
                result = "Decile";
                break;
        case 15:
                result = "Tridecile";
                break;
        case 16:
                result = "Semisextile";
                break;
        case 17:
                result = "Quincunx";
                break;
        case 18:
                result = "Undecile";
                break;
         default:
                result = "null";
    };

    return result;
}

QString dataProcessor::retrieveSign(int sign){
    QString result;
    switch(sign){
        case 1:
                result = "Aries";
                break;
        case 2:
                result = "Tauro";
                break;
        case 3:
                result = "Geminis";
                break;
        case 4:
                result = "Cancer";
                break;
        case 5:
                result = "Leo";
                break;
        case 6:
                result = "Virgo";
                break;
        case 7:
                result = "Libra";
                break;
        case 8:
                result = "Escorpio";
                break;
        case 9:
                result = "Sagitario";
                break;
        case 10:
                result = "Capricornio";
                break;
        case 11:
                result = "Acuario";
                break;
        case 12:
                result = "Piscis";
                break;
        default:
            result = "null";
    };
    return result;
}

QString dataProcessor::retrieveHouse(int house){
    QString result;
    switch(house){
        case 1:
            result  = "1 5 9";
            break;
        case 10:
            result  = "10 2 6";
            break;
        case 7:
            result  = "7 11 3";
            break;
        case 4:
            result  = "4 8 12";
            break;
        default:
            result  = "null";
            break;
    };
    return result;
}


void dataProcessor::addAspects(QList<metAstro::aspectParameter*> aspects){
    this->aspects.clear();
    for(int i = 0; i < aspects.length(); ++i){
        this->aspects << aspects.at(i);
    };
}

void dataProcessor::addWeakAspects(QList<metAstro::aspectParameter*> aspectsWeak){
    this->aspectsWeak.clear();
    for(int i = 0; i < aspectsWeak.length(); ++i){
        this->aspectsWeak << aspectsWeak.at(i);
    };
}

void dataProcessor::addWeathers(QList<metAstro::weatherParameter*> weathers){
    this->weathers.clear();
    for(int i = 0; i < weathers.length(); ++i){
        this->weathers << weathers.at(i);
    };
}

void dataProcessor::addWeakWeathers(QList<metAstro::weatherParameter*> weathersWeak){
    this->weathersWeak.clear();
    for(int i = 0; i < weathersWeak.length(); ++i){
        this->weathersWeak << weathersWeak.at(i);
    };
}

void dataProcessor::addPositions(QList<metAstro::positionParameter*> positions){
    this->positions.clear();
    for(int i = 0; i < positions.length(); ++i){
        this->positions << positions.at(i);
    };
}

void dataProcessor::addWeakPositions(QList<metAstro::positionParameter*> positionsWeak){
    this->positionsWeak.clear();
    for(int i = 0; i < positionsWeak.length(); ++i){
        this->positionsWeak << positionsWeak.at(i);
    };
}

void dataProcessor::addHouses(QList<metAstro::housesParameter*> houses){
    this->houses.clear();
    for(int i = 0; i < houses.length(); ++i){
        this->houses << houses.at(i);
    };
}

void dataProcessor::addWeakHouses(QList<metAstro::housesParameter*> housesWeak){
    this->housesWeak.clear();
    for(int i = 0; i < housesWeak.length(); ++i){
        this->housesWeak << housesWeak.at(i);
    };
}

void dataProcessor::addQuadrants(QList<metAstro::cuadrantesParameter*> quadrants){
    this->quadrants.clear();
    for(int i = 0; i < quadrants.length(); ++i){
        this->quadrants << quadrants.at(i);
    };
}

void dataProcessor::addWeakQuadrants(QList<metAstro::cuadrantesParameter*> quadrantsWeak){
    this->quadrantsWeak.clear();
    for(int i = 0; i < quadrantsWeak.length(); ++i){
        this->quadrantsWeak << quadrantsWeak.at(i);
    };
}

void dataProcessor::addSings(QList<metAstro::signsParameter*> signs){
    this->signs.clear();
    for(int i = 0; i < signs.length(); ++i){
        this->signs << signs.at(i);
    };
}

void dataProcessor::addWeakSings(QList<metAstro::signsParameter*> signsWeak){
    this->signsWeak.clear();
    for(int i = 0; i < signsWeak.length(); ++i){
        this->signsWeak << signsWeak.at(i);
    };
}
