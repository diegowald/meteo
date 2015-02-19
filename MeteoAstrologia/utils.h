#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include "mainwindow.h"

namespace utils{
    QString addSlashes(QString value);
    int getMinutes(double angle);
    int getSeconds(double angle);
    int getGrade(double angle);
    QString planetName(int planet);
    QString aspectName(int aspect);
    QString zodiacName(int sign);    
}

#endif // UTILS_H
