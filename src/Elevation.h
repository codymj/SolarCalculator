/*
 * Elevation.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _ELEVATION_H_
#define _ELEVATION_H_

class Elevation {
public:
    // Constructors (e = magnitude of elevation, u = unit (ft, m)
    Elevation();
    Elevation(double &e, int &u);
    
    // Converter functions
    void mToFt();
    void ftToM();
    
    // Get'er functions
    double getMagnitude() {return this->magnitude;}
    int getUnit() {return this->unit;}
    
    // Set'er functions
    void setMagnitude(double m) {this->magnitude = m;}
    void setUnit(int u) {this->unit = u;}
    
private:
    double magnitude;
    int unit;   // 0 for feet, 1 for meters
};

#endif // _ELEVATION_H_
