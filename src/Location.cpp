/*
 * Location.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "Location.h"

// Default onstructor
Location::Location() {
    this->lat = 0.0;
    this->lon = 0.0;
}

// Constructor
Location::Location(double &lat, int &ns, double &lon, int &ew) {
    this->lat = lat;
    this->lon = lon;
    
    // Make sure N is positive
    if (ns == 0 && lat < 0) {
        this->lat *= -1;
    }
    
    // Make sure S is negative
    if (ns == 1 && lat > 0) {
        this->lat *= -1;
    }
    
    // Make sure E is postive
    if (ew == 0 && lon < 0) {
        this->lon *= -1;
    }
    
    // Make sure W is negative
    if (ew == 1 && lon > 0) {
        this->lon *= -1;
    }
}
