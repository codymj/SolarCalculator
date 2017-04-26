/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _SOLARCALC_H_
#define _SOLARCALC_H_

#include <cmath>
#include <QDate>
#include "Location.h"
#include "Elevation.h"

#define RAD 3.14159265/180

class SolarCalc {
public:
    // Constructor
    SolarCalc(Location &l, Elevation &e);
    
private:
    Location location;
    Elevation elevation;
    qint64 J_date;
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
};

#endif // _SOLARCALC_H_
