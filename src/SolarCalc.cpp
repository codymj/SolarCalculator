/*
 * SolarCalc.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "SolarCalc.h"

// Constructor
SolarCalc::SolarCalc(Location &l) {
    location = l;
    
    julianDay = QDate::currentDate().toJulianDay();
    localTime = QTime::currentTime().hour()*60 + QTime::currentTime().minute(); // In minutes
    
    QDateTime date;
    currentDateTime = date.currentDateTime();
    dateStr = currentDateTime.date().toString(QString("dd.MMM.yyyy"));
    
    QTimeZone tz;
    timeZone = tz.offsetFromUtc(currentDateTime)/3600;
}

//
bool SolarCalc::isNumber(const double &num) {
    bool decimal = false;
    QString numStr = QString::number(num);
    QChar ch;
    
    for (int i=0; i<numStr.length(); i++) {
        ch = numStr.at(i);
        if (i == 0 && (ch == "-" || ch == "+")) {
            continue;
        }
        if (ch == "." && !decimal) {
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
    return (jd - 2451545.0)/36525.0;
}

//
double SolarCalc::jdFromJulianCent(const double &t) {
    return t*36525.0 + 2451545.0;
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
    double L0 = 280.46646 + t*(36000.76983 + t*(0.0003032));
    
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
    return 357.52911 + t*(35999.05029 - t*0.0001537);   // In degrees
}

//
double SolarCalc::earthEccentricityOrbit(const double &t) {
    return 0.016708634 - t*(0.000042037 + t*0.0000001267);  // Unitless
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
    
    return L0 + C;  // In degrees
}

//
double SolarCalc::sunTrueAnomaly(const double &t) {
    double M = sunGeoMeanAnomaly(t);
    double C = sunEquationofCenter(t);
    
    return M + C;   // In degrees
}

//
double SolarCalc::sunRadialVector(const double &t) {
    double v = sunTrueAnomaly(t);
    double e = earthEccentricityOrbit(t);
    
    return (1.000001018*(1 - e*e))/(1 + e*cos(v*RAD));  // In AUs (astronomical units)
}

//
double SolarCalc::sunApparentLon(const double &t) {
    double o = sunTrueLon(t);
    double omega = 125.04 - t*1934.136;
    
    return o - 0.00569 - 0.00478*sin(omega*RAD);    // In degrees
}

//
double SolarCalc::earthMeanObliquityOfEcliptic(const double &t) {
    double seconds = 21.448 - t*(46.8150 + t*(0.00059 - t*(0.001813)));
    
    return 23.0 + (26.0 + (seconds/60.0))/60.0;
}

//
double SolarCalc::earthObliquityCorrection(const double &t) {
    double e0 = earthMeanObliquityOfEcliptic(t);
    double omega = 125.04 - t*1934.136;
    
    return e0 + 0.00256*cos(omega*RAD); // In degrees
}

//
double SolarCalc::sunRightAscension(const double &t) {
    double e = earthObliquityCorrection(t);
    double lambda = sunApparentLon(t);
    
    return atan2(cos(e*RAD)*sin(lambda*RAD), cos(lambda*RAD));  // In degrees
}

//
double SolarCalc::sunDeclination(const double &t) {
    double e = earthObliquityCorrection(t);
    double lambda = sunApparentLon(t);
    
    return asin(sin(e*RAD)*sin(lambda*RAD))*DEG;    // In degrees
}

//
double SolarCalc::equationOfTime(const double &t) {
    double epsilon = earthObliquityCorrection(t);
    double L0 = sunGeoMeanLon(t);
    double e = earthEccentricityOrbit(t);
    double m = sunGeoMeanAnomaly(t);
    double y = tan(epsilon*RAD)/2.0;
    y *= y;
    double sin2L0 = sin(2.0*L0*RAD);
    double cos2L0 = cos(2.0*L0*RAD);
    double sin4L0 = sin(4.0*L0*RAD);
    double sinm = sin(m*RAD);
    double sin2m = sin(2.0*m*RAD);
    
    double Etime = y*sin2L0 - 2.0*e*sinm + 4.0*e*y*sinm*cos2L0 - 0.5*y*y*sin4L0 - 1.25*e*e*sin2m;
    return 4.0*Etime*DEG;   // In minutes of time
}

//
double SolarCalc::hourAngleSunrise(const double &lat, const double &sd) {
    double HAarg = cos(90.833*RAD)/(cos(lat*RAD)*cos(sd*RAD)) - tan(lat*RAD)*tan(sd*RAD);
    
    return acos(HAarg); // Hour Angle (HA) in radians. For sunset, use -HA
}

//
void SolarCalc::solarNoon(const double &jd, const double &lon, const int &tz) {
    double tNoon = timeJulianCent(jd - lon/360.0);
    double eqTime = equationOfTime(tNoon);
    double solarNoonOffset = 720.0 - lon*4.0 - eqTime;    // In minutes
    double tNew = timeJulianCent(jd + solarNoonOffset/1440.0);
    eqTime = equationOfTime(tNew);
    double solarNoonLocal = 720.0 - lon*4.0 - eqTime + (tz*60.0);   // In minutes
    
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
    if (i == 0) {HA = -HA;} // If i=0, get HA for sunset
    double delta = lon + HA*DEG;
    
    return 720 - 4.0*delta - eqTime; // In minutes
}

//
void SolarCalc::sunriseSunset(
const int &i, const double &jd, const double &lat, const double &lon, const int &tz) {
    double jDay = jd;
    double tUTC = sunriseSunsetUTC(i, jd, lat, lon);
    double tNewUTC = sunriseSunsetUTC(i, jd + tUTC/1400.0, lat, lon);
    
    if (isNumber(tNewUTC)) {
        double tLocal = tNewUTC + (tz*60.0);
        
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
            
            // Display new date & time
            QDate newDate = QDate::fromJulianDay(round(jDay));
            this->dateStr = newDate.toString("dd.MMM.yyyy");
            if (i == 0) {
                this->sunsetTimeStr = convertMinsToHHmm(tLocal);
            }
            else {
                this->sunriseTimeStr = convertMinsToHHmm(tLocal);
            }
        }
    }
    else {  // No sunrise or sunset time found, find next/prev sunrise/sunset date
        int doy = doyFromJD(jd);
        QString msg;
        
        if (((lat > 66.4) && (doy > 79) && (doy < 267)) || 
        ((lat < -66.4) && ((doy < 83) || (doy > 263)))) {
            if (i == 1) {   // Find previous sunrise (date)
                jDay = jdOfNextPrevRiseSet(0, i, jd, lat, lon, tz);
                msg = QString("Previous sunrise was ");
            }
            else {  // Find next sunset (date)
                jDay = jdOfNextPrevRiseSet(1, i, jd, lat, lon, tz);
                msg = QString("Next sunset is ");
            }
        }
        else {
            if (i == 1) {   // Find next sunrise (date)
                jDay = jdOfNextPrevRiseSet(1, i, jd, lat, lon, tz);
                msg = QString("Next sunrise is ");
            }
            else {  // Find previous sunset (date)
                jDay = jdOfNextPrevRiseSet(0, i, jd, lat, lon, tz);
                msg = QString("Previous sunset was ");
            }
        }
        QDate newDate = QDate::fromJulianDay(round(jDay));
        this->dateStr = msg + newDate.toString("dd.MMM.yyyy");
    }
}

//
double SolarCalc::jdOfNextPrevRiseSet(const int &next, const int &i, const double &jd,
const double &lat, const double &lon, const int &tz) {
    double jDay = jd;
    int increment = next ? 1 : -1;
    double t = sunriseSunsetUTC(i, jd, lat, lon);
    
    while (!isNumber(t)) {
        jDay += increment;
        t = sunriseSunsetUTC(i, jDay, lat, lon);
    }
    
    double tLocal = t + tz*60.0;
    
    while ((tLocal < 0.0) || (tLocal >= 1440.0)) {
        int incr = (tLocal < 0) ? 1 : -1;
        tLocal += (incr*1440.0);
        jDay -= incr;
    }
    
    return jDay;
}

// Calculating function
void SolarCalc::calculate() {
    // Noon
    solarNoon(julianDay, location.getLat(), timeZone);
    
    // Sunrise
    sunriseSunset(1, julianDay, location.getLat(), location.getLon(), timeZone);
    
    // Sunset
    sunriseSunset(0, julianDay, location.getLat(), location.getLon(), timeZone);
}

// Returns sunrise time as a QString, HH:MM
QString SolarCalc::getSunrise() {
    return sunriseTimeStr;
}

// Returns mean solar noon time as a QString, HH:MM
QString SolarCalc::getNoon() {
    return noonTimeStr;
}

// Returns sunset time as a QString, HH:SS
QString SolarCalc::getSunset() {
    return sunsetTimeStr;
}

// Returns date (may be updated), dd.MMM.yyyy
QString SolarCalc::getDate() {
    return dateStr;
}
