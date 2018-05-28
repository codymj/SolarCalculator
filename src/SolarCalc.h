// =============================================================================
//
// SolarCalc.h
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
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

#define PI 3.14159265   // pi constant
#define RAD PI/180.0    // Convert degrees to radians
#define DEG 180.0/PI    // Convert radians to degrees
#define myqDebug() qDebug() << fixed << qSetRealNumberPrecision(6)

class SolarCalc {
public:
    // Constructor
    SolarCalc();
    SolarCalc(QDate &, QTime &, Location &, const double &, const bool &);
    
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
    void azimuthElevation(const double &T, const double &tLocal, const double &lat,
        const double &lon, const double &tz);
    void solarNoon(const double &jd, const double &lon, const double &tz, const bool &dst);
    double sunriseSunsetUTC(
        const int &i, const double &jd, const double &lat, const double &lon);
    void sunriseSunset(
        const int &i, const double &jd, const double &lat, const double &lon,
        const double &tz, const bool &dst);
    double jdOfNextPrevRiseSet(const int &next, const int &i, const double &jd,
        const double &lat, const double &lon, const double &tz, const bool &dst);
    void calculate();
    
    // Get'er functions
    QString getEquationOfTime();
    QString getSolarDeclination();
    QString getAzimuthElevation();
    QString getSunrise();
    QString getNoon();
    QString getSunset();
    Location getLocation();
    QDate getDate();
    QTime getTime();
    double getTimeZone();
    bool getDST();
    QString getId();

    // Set ID
    void setId(QString &);
    
private:
    QString id;
    Location location;
    QString dateStr;
    QDate date;
    QTime time;
    double julianDay;
    double localTime;  // In minutes
    double timeZone;
    bool dst;

    QString sunriseTimeStr;
    QString noonTimeStr;
    QString sunsetTimeStr;
    QString equationOfTimeStr;
    QString solarDeclinationStr;
    QString azimuthElevationStr;
};

#endif // _SOLARCALC_H_
