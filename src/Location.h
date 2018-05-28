// =============================================================================
//
// Location.h
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <QDebug>

class Location {
public:
    // Constructors
    Location();
    Location(double &lat, int &ns, double &lon, int &ew);
    
    // Get'er functions
    double getLat() {return this->lat;}
    double getLon() {return this->lon;}
    int getNS() {return this->ns;}
    int getEW() {return this->ew;}
    
    // Set'er functions
    void setLat(double l) {this->lat = l;}
    void setLon(double l) {this->lon = l;}
    void setNS(int i) {this->ns = i;}
    void setEW(int i) {this->ew = i;}
    
private:
    double lat;
    double lon;
    int ns;
    int ew;
};

#endif // _LOCATION_H_
