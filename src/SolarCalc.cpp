// =============================================================================
//
// SolarCalc.cpp
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
#include "SolarCalc.h"

// Constructor
SolarCalc::SolarCalc() {

}

SolarCalc::SolarCalc(
QDate &d, QTime &t, Location &l, const double &tz, const bool &dst) {
    this->date = d;
    this->time = t;
    this->location = l;
    this->timeZone = tz;
    this->dst = dst;
    
    this->julianDay = d.toJulianDay() - 0.5;
    this->localTime = t.hour()*60 -
        (dst? 60.0 : 0.0) + t.minute() + t.second()/60; // In minutes
}

//
bool SolarCalc::isNumber(const double &num) {
    bool decimal = false;
    QString numStr = QString::number(num);
    QChar ch;
    
    for (int i=0; i<numStr.length(); i++) {
        ch = numStr.at(i);
        if (i == 0 && (ch == QChar('-') || ch == QChar('+'))) {
            continue;
        }
        if (ch == QChar('.') && !decimal) {
            decimal = true;
            continue;
        }
        if (!ch.isDigit()) {
            return false;
        }
    }
    
    return true;
}

// Converts minutes of time in HH:mm format
QString SolarCalc::convertMinsToHHmm(const double &mins) {
    QString hourStr, minuteStr;
    int hour = floor(mins/60);
    if (hour < 10) {
        hourStr = "0";
        hourStr.append(QString::number(hour));
    }
    else {
        hourStr = QString::number(hour);
    }
    
    int minute = floor((mins/60 - hour)*60);
    if (minute < 10) {
        minuteStr = "0";
        minuteStr.append(QString::number(minute));
    }
    else {
        minuteStr = QString::number(minute);
    }
    
    return QString(hourStr + ":" + minuteStr);
}

//
double SolarCalc::timeJulianCent(const double &jd) {
    double T = (jd - 2451545.0)/36525.0;
    return T;
}

//
double SolarCalc::jdFromJulianCent(const double &t) {
    double jd = t*36525.0 + 2451545.0;
    return jd;
}

// Determines if the current year is a leap year
bool SolarCalc::isLeapYear(const int &yr) {
    return ((yr%4 == 0 && yr%100 != 0) || yr%400 == 0);
}

// 
int SolarCalc::doyFromJD(const double &jd) {
    double z = floor(jd + 0.5);
    double f = (jd + 0.5) - z;
    double A, alpha;
    
    if (z < 2299161) {
        A = z;
    }
    else {
        alpha = floor((z - 1867216.25)/36524.25);
        A = z + 1 + alpha - floor(alpha/4);
    }
    
    double B = A + 1524;
    double C = floor((B - 122.1)/365.25);
    double D = floor(365.25*C);
    double E = floor((B - D)/30.6001);
    
    int day = B - D - floor(30.6001*E) + f;
    int month = (E < 14) ? E - 1 : E - 13;
    int year = (month > 2) ? C - 4716 : C - 4715;
    double k = isLeapYear(year) ? 1 : 2;
    
    int doy = floor((275*month)/9) - k*floor((month + 9)/12) + day - 30;
    return doy;
}

//
double SolarCalc::sunGeoMeanLon(const double &t) {
    double L0 = 280.46646 + t*(36000.76983 + t*0.0003032);
    while (L0 > 360.0) {
        L0 -= 360.0;
    }
    while (L0 < 0.0) {
        L0 += 360.0;
    }
    return L0;  // In degrees
}

//
double SolarCalc::sunGeoMeanAnomaly(const double &t) {
    double M = 357.52911 + t*(35999.05029 - t*0.0001537);
    return M;   // In degrees
}

//
double SolarCalc::earthEccentricityOrbit(const double &t) {
    double e = 0.016708634 - t*(0.000042037 + t*0.0000001267);
    return e;  // Unitless
}

//
double SolarCalc::sunEquationofCenter(const double &t) {
    double m = sunGeoMeanAnomaly(t);
    double sinm = sin(m*RAD);
    double sin2m = sin(2.0*m*RAD);
    double sin3m = sin(3.0*m*RAD);
    
    double C = sinm*(1.914602 - t*(0.004817 + t*0.000014)) + 
            sin2m*(0.019993 - t*0.000101) + sin3m*0.000289;
    return C;   // In degrees
}

//
double SolarCalc::sunTrueLon(const double &t) {
    double L0 = sunGeoMeanLon(t);
    double C = sunEquationofCenter(t);
    
    return (L0 + C);  // In degrees
}

//
double SolarCalc::sunTrueAnomaly(const double &t) {
    double M = sunGeoMeanAnomaly(t);
    double C = sunEquationofCenter(t);
    
    return (M + C);   // In degrees
}

//
double SolarCalc::sunRadialVector(const double &t) {
    double v = sunTrueAnomaly(t);
    double e = earthEccentricityOrbit(t);
    
    double R = (1.000001018*(1 - e*e))/(1 + e*cos(v*RAD));
    return R;  // In AUs (astronomical units)
}

//
double SolarCalc::sunApparentLon(const double &t) {
    double o = sunTrueLon(t);
    double omega = 125.04 - t*1934.136;
    
    double lambda = o - 0.00569 - 0.00478*sin(omega*RAD);
    return lambda;    // In degrees
}

//
double SolarCalc::earthMeanObliquityOfEcliptic(const double &t) {
    double seconds = 21.448 - t*(46.8150 + t*(0.00059 - t*(0.001813)));
    
    double e0 = 23.0 + (26.0 + (seconds/60.0))/60.0;
    return e0;  // In degrees
}

//
double SolarCalc::earthObliquityCorrection(const double &t) {
    double e0 = earthMeanObliquityOfEcliptic(t);
    double omega = 125.04 - t*1934.136;
    
    double e = e0 + 0.00256*cos(omega*RAD);
    return e; // In degrees
}

//
double SolarCalc::sunRightAscension(const double &t) {
    double e = earthObliquityCorrection(t);
    double lambda = sunApparentLon(t);
    
    double alpha = atan2(cos(e*RAD)*sin(lambda*RAD), cos(lambda*RAD))*DEG;
    return alpha;  // In degrees
}

//
double SolarCalc::sunDeclination(const double &t) {
    double e = earthObliquityCorrection(t);
    double lambda = sunApparentLon(t);
    double sint = sin(e*RAD)*sin(lambda*RAD);
    
    double theta = asin(sint)*DEG;
    return theta;    // In degrees
}

//
double SolarCalc::equationOfTime(const double &t) {
    double epsilon = earthObliquityCorrection(t);
    double L0 = sunGeoMeanLon(t);
    double e = earthEccentricityOrbit(t);
    double m = sunGeoMeanAnomaly(t);
    double y = tan(epsilon*RAD/2.0);
    y *= y;
    double sin2L0 = sin(2.0*L0*RAD);
    double cos2L0 = cos(2.0*L0*RAD);
    double sin4L0 = sin(4.0*L0*RAD);
    double sinm = sin(m*RAD);
    double sin2m = sin(2.0*m*RAD);
    
    double Etime = y*sin2L0 - 2.0*e*sinm + 4.0*e*y*sinm*cos2L0
        - 0.5*y*y*sin4L0 - 1.25*e*e*sin2m;
    return 4.0*Etime*DEG;   // In minutes of time
}

//
double SolarCalc::hourAngleSunrise(const double &lat, const double &sd) {
    double HAarg = cos(90.833*RAD)/(cos(lat*RAD)*cos(sd*RAD))
        - tan(lat*RAD)*tan(sd*RAD);
    
    return acos(HAarg); // Hour Angle (HA) in radians. For sunset, use -HA
}

//
void SolarCalc::azimuthElevation(
const double &T, const double &tLocal,
const double &lat, const double &lon, const double &tz) {
    double eqTime = equationOfTime(T);
    double theta = sunDeclination(T);
    double solarTimeFix = eqTime + 4.0*lon - 60.0*tz;
    
    //double eqt = floor(eqTime*100 + 0.5)/100.0;
    QString eqTimeStr = QString::number(eqTime, 'f', 3);
    this->equationOfTimeStr = eqTimeStr;
    
    //double sd = floor(theta*100 + 0.5)/100.0;
    QString sdStr = QString::number(theta, 'f', 3);
    this->solarDeclinationStr = sdStr;
    
    double trueSolarTime = tLocal + solarTimeFix;
    while (trueSolarTime > 1440.0) {
        trueSolarTime -= 1440.0;
    }
    
    double hourAngle = trueSolarTime/4.0 - 180.0;
    if (hourAngle < -180.0) {
        hourAngle += 360.0;
    }
    
    double csz = sin(lat*RAD)*sin(theta*RAD)
        + cos(lat*RAD)*cos(theta*RAD)*cos(hourAngle*RAD);
    if (csz > 1.0) {
        csz = 1.0;
    }
    else if (csz < -1.0) {
        csz = -1.0;
    }
    
    double zenith = acos(csz)*DEG;
    double azimuthNum = sin(lat*RAD)*cos(zenith*RAD) - sin(theta*RAD);
    double azimuthDenom = cos(lat*RAD)*sin(zenith*RAD);
    double azimuth = 0.0;
    
    double azimuthRadian = 0.0;
    if (fabs(azimuthDenom) > 0.001) {
        azimuthRadian = azimuthNum/azimuthDenom;
        if (fabs(azimuthRadian) > 1.0) {
            if (azimuthRadian < 0.0) {
                azimuthRadian = -1.0;
            }
            else {
                azimuthRadian = 1.0;
            }
        }
        azimuth = 180.0 - acos(azimuthRadian)*DEG;
        if (hourAngle > 0.0) {
            azimuth = -azimuth;
        }
    }
    else {
        if (lat > 0.0) {
            azimuth = 180.0;
        }
        else {
            azimuth = 0.0;
        }
    }
    if (azimuth < 0.0) {
        azimuth += 360.0;
    }
    
    double elevation = 90.0 - zenith;
    
    // Atmospheric refraction correction
    double refractionCorrection = 0.0;
    if (elevation > 85.0) {
        refractionCorrection = 0.0;
    }
    else {
        double te = tan(elevation*RAD);
        if (elevation > 5.0 && elevation < 85.0) {
            refractionCorrection = 58.1/te
                - 0.07/pow(te,3) + 0.000086/pow(te,5);
        }
        else if (elevation > -0.575 && elevation < 5.0) {
            refractionCorrection = 1735.0 - 518.2*elevation
                + 103.4*pow(elevation,2)
                - 12.79*pow(elevation,3) + 0.711*pow(elevation,4);
        }
        else {
            refractionCorrection = -20.774/te;
        }
        refractionCorrection /= 3600.0;
    }
    
    double solarZenith = zenith - refractionCorrection;
    QString azimuthStr, elevationStr;
    if (solarZenith > 108.0) {
        azimuthStr = "DARK";
        elevationStr = "DARK";
    }
    else {
        azimuthStr = QString::number(azimuth, 'f', 3);
        elevationStr = QString::number((90.0 - solarZenith), 'f', 3);
    }
    this->azimuthElevationStr = QString(azimuthStr + " | " + elevationStr);
}

//
void SolarCalc::solarNoon(const double &jd, const double &lon,
const double &tz, const bool &dst) {
    double tNoon = timeJulianCent(jd - lon/360.0);
    double eqTime = equationOfTime(tNoon);
    double solarNoonOffset = 720.0 - lon*4.0 - eqTime;    // In minutes
    double tNew = timeJulianCent(jd + solarNoonOffset/1440.0);
    eqTime = equationOfTime(tNew);
    double solarNoonLocal = 720.0 - lon*4.0 - eqTime + tz*60.0;   // In minutes
    if (dst) {
        solarNoonLocal += 60.0;
    }
    
    while (solarNoonLocal < 0.0) {
        solarNoonLocal += 1440.0;
    }
    while (solarNoonLocal >= 1440.0) {
        solarNoonLocal -= 1440.0;
    }
    
    this->noonTimeStr = convertMinsToHHmm(solarNoonLocal);
}

//
double SolarCalc::sunriseSunsetUTC(
const int &i, const double &jd, const double &lat, const double &lon) {
    double t = timeJulianCent(jd);
    double eqTime = equationOfTime(t);
    double sd = sunDeclination(t);
    double HA = hourAngleSunrise(lat, sd);
    if (i == 0) {
        HA = -HA;
    } // If i=0, get HA for sunset
    
    double delta = lon + HA*DEG;
    
    return 720 - 4.0*delta - eqTime; // In minutes
}

//
void SolarCalc::sunriseSunset(
const int &i, const double &jd, const double &lat, const double &lon,
const double &tz, const bool &dst) {
    double jDay = jd;
    double tUTC = sunriseSunsetUTC(i, jd, lat, lon);
    double tNewUTC = sunriseSunsetUTC(i, jd + tUTC/1400.0, lat, lon);
    
    if (isNumber(tNewUTC)) {
        double tLocal = tNewUTC + tz*60.0;
        tLocal += dst ? 60.0 : 0.0;
        if ((tLocal >= 0.0) && (tLocal < 1440.0)) {
            if (i == 0) {
                this->sunsetTimeStr = convertMinsToHHmm(tLocal);
            }
            else {
                this->sunriseTimeStr = convertMinsToHHmm(tLocal);
            }
        }
        else {
            int increment = (tLocal < 0) ? 1 : -1;
            while ((tLocal < 0.0) || (tLocal >= 1440.0)) {
                tLocal += increment*1440.0;
                jDay -= increment;
            }
            if (i == 0) {
                this->sunsetTimeStr = convertMinsToHHmm(tLocal);
            }
            else {
                this->sunriseTimeStr = convertMinsToHHmm(tLocal);
            }
        }
    }
    else {  // No sunrise or sunset time found, find next/prev sunrise/sunset
        double doy = (double)doyFromJD(jd);
        QDate newDate;
        
        if (((lat > 66.4) && (doy > 79) && (doy < 267)) || 
        ((lat < -66.4) && ((doy < 83) || (doy > 263)))) {
            if (i == 1) {   // Find previous sunrise (date)
                jDay = jdOfNextPrevRiseSet(0, i, jd, lat, lon, tz, dst);
                newDate = QDate::fromJulianDay(round(jDay));
                this->sunriseTimeStr = newDate.toString("dd/MMM/yyyy");
            }
            else {  // Find next sunset (date)
                jDay = jdOfNextPrevRiseSet(1, i, jd, lat, lon, tz, dst);
                newDate = QDate::fromJulianDay(round(jDay));
                this->sunsetTimeStr = newDate.toString("dd/MMM/yyyy");
            }
        }
        else {
            if (i == 1) {   // Find next sunrise (date)
                jDay = jdOfNextPrevRiseSet(1, i, jd, lat, lon, tz, dst);
                newDate = QDate::fromJulianDay(round(jDay));
                this->sunriseTimeStr = newDate.toString("dd/MMM/yyyy");
            }
            else {  // Find previous sunset (date)
                jDay = jdOfNextPrevRiseSet(0, i, jd, lat, lon, tz, dst);
                newDate = QDate::fromJulianDay(round(jDay));
                this->sunsetTimeStr = newDate.toString("dd/MMM/yyyy");
            }
        }
    }
}

//
double SolarCalc::jdOfNextPrevRiseSet(const int &next,
const int &i, const double &jd, const double &lat,
const double &lon, const double &tz, const bool &dst) {
    double jDay = jd;
    int increment = next ? 1 : -1;
    double t = sunriseSunsetUTC(i, jd, lat, lon);
    
    while (!isNumber(t)) {
        jDay += increment;
        t = sunriseSunsetUTC(i, jDay, lat, lon);
    }
    
    double tLocal = t + tz*60.0 + (dst ? 60.0 : 0.0);
    
    while ((tLocal < 0.0) || (tLocal >= 1440.0)) {
        int incr = (tLocal < 0) ? 1 : -1;
        tLocal += (incr*1440.0);
        jDay -= incr;
    }
    
    return jDay;
}

// Calculating function
void SolarCalc::calculate() {
    double totalTime = julianDay + localTime/1440.0 - timeZone/24.0;
    double T = timeJulianCent(totalTime);
    
    // Azimuth & elevation
    azimuthElevation(T, localTime, location.getLat(),
        location.getLon(), timeZone);
    
    // Noon
    solarNoon(julianDay, location.getLon(), timeZone, dst);
    
    // Sunrise
    sunriseSunset(1, julianDay, location.getLat(),
        location.getLon(), timeZone, dst);
    
    // Sunset
    sunriseSunset(0, julianDay, location.getLat(),
        location.getLon(), timeZone, dst);
}

// Returns sunrise time as a QString, HH:MM
QString SolarCalc::getSunrise() {
    return this->sunriseTimeStr;
}

// Returns mean solar noon time as a QString, HH:MM
QString SolarCalc::getNoon() {
    return this->noonTimeStr;
}

// Returns sunset time as a QString, HH:SS
QString SolarCalc::getSunset() {
    return this->sunsetTimeStr;
}

// Returns equation of time as a QString in minutes
QString SolarCalc::getEquationOfTime() {
    return this->equationOfTimeStr;
}

// Returns solar declination as a QString in degrees
QString SolarCalc::getSolarDeclination() {
    return this->solarDeclinationStr;
}

// Returns azimuth & elevation as a QString, both in degrees
QString SolarCalc::getAzimuthElevation() {
    return this->azimuthElevationStr;
}

// Returns location
Location SolarCalc::getLocation() {
    return this->location;
}

// Returns date
QDate SolarCalc::getDate() {
    return this->date;
}

// Returns time
QTime SolarCalc::getTime() {
    return this->time;
}

// Returns time zone
double SolarCalc::getTimeZone() {
    return this->timeZone;
}

// Returns DST
bool SolarCalc::getDST() {
    return this->dst;
}

QString SolarCalc::getId() {
    return this->id;
}

void SolarCalc::setId(QString &id) {
    this->id = id;
}
