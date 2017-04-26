/*
 * SolarCalc.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "SolarCalc.h"

// Constructor
SolarCalc::SolarCalc(Location &l, Elevation &e) {
    location = l;
    elevation = e;
    
    // Set current Julian date
    J_date = QDate::currentDate().toJulianDay();
    
    // Calculate days since 01/01/2000
    n = J_date - 2451545.0 + 0.0008;
    
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
}
