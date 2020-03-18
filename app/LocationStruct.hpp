#ifndef LOCATIONSTRUCT_HPP
#define LOCATIONSTRUCT_HPP

#include <string>

struct Location {

    double latitude;
    char latDirection;
    double longitude;
    char longDirection;
    std::string airport;
    double distancefromOrigin;
    bool correctedLatLong;

    Location() : latitude(0.0), 
                latDirection('0'), 
                longitude(0.0),
                longDirection('0'),
                airport("Nowhere"), 
                distancefromOrigin(0.0),
                correctedLatLong(false) {};
    
};

#endif