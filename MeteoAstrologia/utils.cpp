#include "utils.h"

QString utils::addSlashes(QString value){
    QString result;
    for(int i = 0; i < value.length(); ++i){
        if(value.at(i).toAscii() == '\''){
                result.append("\\'");
                continue;
        };
        if(value.at(i).toAscii() == '\\'){
            result.append("\\\\");
            continue;
        };
        result.append(value.at(i));
    };
    return result;
}

int utils::getMinutes(double angle){
    int grade = (int) angle;
    double minutes = angle - grade;
    return minutes * 60;
}
int utils::getSeconds(double angle){
    int grade = (int) angle;
    int minutes = (angle - grade) * 60;
    return ((angle - (double)grade) - (minutes / 60.0)) * 3600;
}

int utils::getGrade(double angle){
    return (int) angle;
}

QString utils::aspectName(int aspect){
    if(aspect == 1) return "Conjunction";
    if(aspect == 2) return "Opposition";
    if(aspect == 3) return "Trine";
    if(aspect == 4) return "Square";
    if(aspect == 5) return "Quintile";
    if(aspect == 6) return "Biquintile";
    if(aspect == 7) return "Sextile";
    if(aspect == 8) return "Septile";
    if(aspect == 9) return "Biseptile";
    if(aspect == 10) return "Triseptile";
    if(aspect == 11) return "Octile";
    if(aspect == 12) return "Trioctile";
    if(aspect == 13) return "Novile";
    if(aspect == 14) return "Decile";
    if(aspect == 15) return "Tridecile";
    if(aspect == 16) return "Semisextile";
    if(aspect == 17) return "Quincunx";
    if(aspect == 18) return "Undecile";
}

QString utils::planetName(int planet){
    if(planet == 0) return "sol";
    if(planet == 1) return "luna";
    if(planet == 2) return "mercurio";
    if(planet == 3) return "venus";
    if(planet == 4) return "marte";
    if(planet == 5) return "jupiter";
    if(planet == 6) return "saturno";
    if(planet == 7) return "urano";
    if(planet == 8) return "neptuno";
    if(planet == 9) return "pluton";
    if(planet == 15) return "ascendente";
    if(planet == 13) return "MC";
    if(planet == 10) return "Nodo";
    if(planet == 12) return "Lilith";
    if(planet == 11) return "Fortuna";
}

QString utils::zodiacName(int sign){
    if(sign == 1) return "Aries";
    if(sign == 2) return "Tauro";
    if(sign == 3) return "Geminis";
    if(sign == 4) return "Cancer";
    if(sign == 5) return "Leo";
    if(sign == 6) return "Virgo";
    if(sign == 7) return "Libra";
    if(sign == 8) return "Escorpio";
    if(sign == 9) return "Sagitario";
    if(sign == 10) return "Capricornio";
    if(sign == 11) return "Acuario";
    if(sign == 12) return "Pisis";

}
