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
    double getMagnitude();
    int getUnit();
    
private:
    double magnitude;
    int unit;   // 0 for feet, 1 for meters
};

#endif // _ELEVATION_H_
