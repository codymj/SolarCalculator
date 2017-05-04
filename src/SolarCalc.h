/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _SOLARCALC_H_
#define _SOLARCALC_H_

#include <cmath>
#include <QChar>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include <QString>
#include <QTime>
#include <QTimeZone>
#include "Location.h"
#include "Elevation.h"

#define PI 3.14159265   // pi constant
#define RAD PI/180.0    // Convert degrees to radians
#define DEG 180.0/PI    // Convert radians to degrees

class SolarCalc {
public:
    // Constructor
    SolarCalc(Location &l);
    
    // Calculating functions
    bool isNumber(const double &num);
    QString convertMinsToHHmm(const double &mins);
    double timeJulianCent(const double &jd);
    double jdFromJulianCent(const double &t);
    bool isLeapYear(const int &yr);
    int doyFromJD(const double &jd);
    double sunGeoMeanLon(const double &t);
    double sunGeoMeanAnomaly(const double &t);
    double earthEccentricityOrbit(const double &t);
    double sunEquationofCenter(const double &t);
    double sunTrueLon(const double &t);
    double sunTrueAnomaly(const double &t);
    double sunRadialVector(const double &t);
    double sunApparentLon(const double &t);
    double earthMeanObliquityOfEcliptic(const double &t);
    double earthObliquityCorrection(const double &t);
    double sunRightAscension(const double &t);
    double sunDeclination(const double &t);
    double equationOfTime(const double &t);
    double hourAngleSunrise(const double &lat, const double &sd);
    void solarNoon(const double &jd, const double &lon, const int &tz);
    double sunriseSunsetUTC(
        const int &i, const double &jd, const double &lat, const double &lon);
    void sunriseSunset(
        const int &i, const double &jd, const double &lat, const double &lon, const int &tz);
    double jdOfNextPrevRiseSet(const int &next, const int &i, const double &jd,
        const double &lat, const double &lon, const int &tz);
    void calculate();
    
    // Get'er functions
    QString getSunrise();
    QString getNoon();
    QString getSunset();
    QString getDate();
    
private:
    Location location;
    Elevation elevation;
    QString dateStr;
    QDateTime currentDateTime;
    int julianDay;
    int localTime;
    int timeZone;

    QString sunriseTimeStr;
    QString noonTimeStr;
    QString sunsetTimeStr;
};

#endif // _SOLARCALC_H_
