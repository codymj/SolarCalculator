/*
 * SolarCalc.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "SolarCalc.h"

#define myqDebug() qDebug() << fixed << qSetRealNumberPrecision(8)

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
    // double HH, MM, SS, J_time = 0.0;
    // QTime currentTime = QTime::currentTime();
    // HH = currentTime.hour();
    // MM = currentTime.minute();
    // SS = currentTime.second();
    // J_time = HH/24.0 + MM/1440.0 + SS/86400.0;
    J_date = (double)J_dateTemp;
    
    // Calculate days since 01/01/2000
    // 2451545.0 is the equivalent Julian year of Julian days for 2000, 1, 1.5.
    // (68.184 / 86400) is the fractional Julian Day for leap seconds and terrestrial time.
    n = J_date - 2451545.0 + (68.184 / 86400.0);
    
    // Calculate mean solar noon:
    double l_w = location.getLon();
    J_n = n - (l_w / 360.0);
    
    // Calculate solar mean anomaly
    M = fmod((357.5291 + 0.98560028 * J_n), 360.0);
    
    // Calculate equation of the center
    C = 1.9148*sin(M*RAD) + 0.0200*sin(2*M*RAD) + 0.0003*sin(3.0*M*RAD);
    
    // Calculate ecliptic longitude
    lambda = fmod((M + C + 180.0 + 102.9372), 360.0);
    
    // Calculate solar transit
    J_trans = 2451545.5 + J_n + 0.0053*sin(M*RAD) - 0.0069*sin(2.0*lambda*RAD);
    
    // Calculate declination of sun
    delta = asin(sin(lambda*RAD) * sin(23.44*RAD)) * DEG;
    
    // Calculate hour angle
    double w = 0.0;
    double phi = location.getLat();
    
    // For elevation in meters
    if (elevation.getUnit() == 0) {
        double E = elevation.getMagnitude();
        double EC = -2.076*sqrt(E)/60.0;   // Elevation correction
        w = acos((sin((-0.83+EC)*RAD) - sin(phi*RAD)*sin(delta*RAD))/(cos(phi*RAD)*cos(delta*RAD)))*DEG;
    }
    // For elevation in feet
    if (elevation.getUnit() == 1) {
        double E = elevation.getMagnitude();
        double EC = -1.15*sqrt(E)/60.0;   // Elevation correction
        w = acos((sin((-0.83+EC)*RAD) - sin(phi*RAD)*sin(delta*RAD))/(cos(phi*RAD)*cos(delta*RAD)))*DEG;
    }
    
    // Calculate sunrise and sunset
    J_rise = J_trans - (w / 360.0);
    J_set = J_trans + (w / 360.0);
    
    myqDebug() << J_rise;
    myqDebug() << J_set;
    
    
    // Convert and store HH:MM format
    this->sunriseTime = convertJT(J_rise);
    this->noonTime = convertJT(J_n);
    this->sunsetTime = convertJT(J_set);
}

QString SolarCalc::convertJT(double &jt) {
    double hour, minute = 0.0;
    
    // Break Julian datetime into two parts, integer (date) and decimal (time)
    double intPart = 0.0;
    double fractPart = modf(jt, &intPart);
    
    // floor(fractPart * 24) gives HH
    fractPart *= 24.0;
    hour = floor(fractPart);
    
    // Resulting decimal value * 60 gives MM
    fractPart = modf(fractPart, &intPart);
    fractPart *= 60.0;
    minute = floor(fractPart);
    
    QTime time = QTime(hour, minute);
    
    return time.toString(QString("HH:mm"));
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
