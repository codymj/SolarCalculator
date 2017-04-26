/*
 * Elevation.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "Elevation.h"

// Default constructor
Elevation::Elevation() {
    this->magnitude = 0;
    this->unit = 0;
}

// Constructor
Elevation::Elevation(double &e, int &u) {
    this->magnitude = e;
    this->unit = u;
}

// Converts meters to feet
void Elevation::mToFt() {
    // If unit is already in meters, return
    if (this->unit == 1) {
        return;
    }
    
    this->unit = 0;
    this->magnitude *= 3.281;
}

// Converts feet to meters
void Elevation::ftToM() {
    // If unit is already in feet, return
    if (this->unit == 0) {
        return;
    }
    
    this->unit = 1;
    this->magnitude /= 3.281;
}

// Returns magnitude of elevation
double Elevation::getMagnitude() {
    return this->magnitude;
}

// Returns unit of elevation
int Elevation::getUnit() {
    return this->unit;
}
