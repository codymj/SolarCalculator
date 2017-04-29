/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _SOLARCALC_H_
#define _SOLARCALC_H_

#include <cmath>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include <QString>
#include <QTime>
#include "Location.h"
#include "Elevation.h"

#define PI 3.14159265
#define RAD PI/180.0
#define DEG 180.0/PI

class SolarCalc {
public:
    // Constructor
    SolarCalc(Location &l, Elevation &e);
    
    // Calculating functions
    void calculate();
    QString convertJT(double &);
    
    // Get'er functions
    QString getSunrise();
    QString getMeanSolarNoon();
    QString getSunset();
    
private:
    Location location;
    Elevation elevation;
    double J_date;
    double n;
    double J_n;
    double M;
    double C;
    double lambda;
    double J_trans;
    double delta;
    double w;
    double J_rise;
    double J_set;
    QString sunriseTime;
    QString noonTime;
    QString sunsetTime;
};

#endif // _SOLARCALC_H_
