/*
 * Location.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _LOCATION_H_
#define _LOCATION_H_

class Location {
public:
    // Constructors
    Location();
    Location(double &lat, int &ns, double &lon, int &ew);
    
    // Get'er functions
    double getLat() {return this->lat;}
    double getLon() {return this->lon;}
    
    // Set'er functions
    void setLat(double l) {this->lat = l;}
    void setLon(double l) {this->lon = l;}
    
private:
    int lat;
    int lon;
};

#endif // _LOCATION_H_
