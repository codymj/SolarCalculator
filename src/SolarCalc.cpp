/*
 * SolarCalc.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "SolarCalc.h"

#define myqDebug() qDebug() << fixed << qSetRealNumberPrecision(16)

// Constructor
SolarCalc::SolarCalc(Location &l, Elevation &e) {
    location = l;
    elevation = e;
}

// Calculating function
void SolarCalc::calculate() {
    // Set current Julian date
    qint64 J_dateTemp = QDate::currentDate().toJulianDay();
    
    // Set Julian time and add it to the Julian date
    double HH, MM, SS, J_time = 0.0;
    QTime currentTime = QTime::currentTime();
    HH = currentTime.hour();
    MM = currentTime.minute();
    SS = currentTime.second();
    J_time = HH/24 + MM/1440 + SS/86400;
    J_date = (double)((double)J_dateTemp + J_time);
    
    myqDebug() << J_date;
    
    // Calculate days since 01/01/2000
    n = J_date - 2451545.0 + 0.0008;
    myqDebug() << n;
    
    // Calculate mean solar noon:
    double l_w = location.getLon();
    J_n = n - (l_w / 360);
    
    // Calculate solar mean anomaly
    M = fmod((357.5291 + 0.98560028 * J_n), 360);
    
    // Calculate equation of the center
    C = 1.9148*sin(M*RAD) + 0.0200*sin(2*M*RAD) + 0.0003*sin(3*M*RAD);
    
    // Calculate ecliptic longitude
    lambda = fmod((M + C + 180 + 102.9372), 360);
    
    // Calculate solar transit
    J_trans = 2451545.5 + J_n + 0.0053*sin(M*RAD) - 0.0069*sin(2*lambda*RAD);
    
    // Calculate declination of sun
    delta = asin(sin(lambda*RAD) * sin(23.44));
    
    // Calculate hour angle
    double phi = location.getLat();
    
    // For elevation in feet
    if (elevation.getUnit() == 0) {
        double E = elevation.getMagnitude();
        double EC = -1.15*sqrt(E)/60;   // Elevation correction
        w = acos((sin((-0.83+EC)*RAD) - sin(phi*RAD)*sin(delta*RAD))/(cos(phi*RAD)*cos(delta*RAD)));
    }
    
    // For elevation in meters
    if (elevation.getUnit() == 0) {
        double E = elevation.getMagnitude();
        double EC = -2.076*sqrt(E)/60;   // Elevation correction
        w = acos((sin((-0.83+EC)*RAD) - sin(phi*RAD)*sin(delta*RAD))/(cos(phi*RAD)*cos(delta*RAD)));
    }
    
    // Calculate sunrise and sunset
    J_rise = J_trans - (w/360);
    J_set = J_trans + (w/360);
    
    // Convert and store HH:MM format
    this->sunriseTime = convertJT(J_rise);
    this->noonTime = convertJT(J_n);
    this->sunsetTime = convertJT(J_set);
}

QString SolarCalc::convertJT(double &jt) {
    double hour, minute = 0;
    
    // Break Julian datetime into two parts, integer (date) and decimal (time)
    double intPart = 0;
    double fractPart = modf(jt, &intPart);
    
    // floor(fractPart * 24) gives HH
    fractPart *= 24;
    hour = floor(fractPart);
    
    // Resulting decimal value * 60 gives MM
    fractPart = modf(fractPart, &intPart);
    fractPart *= 60;
    minute = floor(fractPart);
    
    QString timeHHMM = QString::number(hour) + ":" + QString::number(minute);
    
    return timeHHMM;
}

// Returns sunrise time as a QString, HH:MM
QString SolarCalc::getSunrise() {
    return sunriseTime;
}

// Returns mean solar noon time as a QString, HH:MM
QString SolarCalc::getMeanSolarNoon() {
    return noonTime;
}

// Returns sunset time as a QString, HH:SS
QString SolarCalc::getSunset() {
    return sunsetTime;
}
