//for pi constant
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "DetermineRanking.hpp"
#include "LocationStruct.hpp"

//used in calculate distance
const double RADIUS_OF_EARTH = 3959.9;

Location DetermineClosest(Location& origin, std::vector<Location>& targetLocs) {
    
    Location closest;
    if (targetLocs.size() > 0) {

        double smallest = CalculateDistance(origin, targetLocs.at(0));
        closest = targetLocs.at(0);
        closest.distancefromOrigin = smallest;

        double compare = 0.0;
        for (int i = 1; i < targetLocs.size(); ++i) {
            compare = CalculateDistance(origin, targetLocs.at(i));
            if (compare < smallest) {
                smallest = compare;
                closest = targetLocs.at(i);
                closest.distancefromOrigin = smallest;
            }
        }
    }
    return closest;

}

Location DetermineFarthest(Location& origin, std::vector<Location>& targetLocs) {

    Location farthest;
    if (targetLocs.size() > 0) {

        double largest = CalculateDistance(origin, targetLocs.at(0));
        farthest = targetLocs.at(0);
        farthest.distancefromOrigin = largest;

        double compare = 0.0;
        for (int i = 1; i < targetLocs.size(); ++i) {
            compare = CalculateDistance(origin, targetLocs.at(i));
            if (compare > largest) {
                largest = compare;
                farthest = targetLocs.at(i);
                farthest.distancefromOrigin = largest;
            }
        }
    }
    return farthest;
}

//calculates great circle distance
//to calculate distance from origin, plug origin into x 
double CalculateDistance(Location& x, Location& y) {

    //fix lat and long by converting to negative value if needed
    CorrectLatLong(x);
    CorrectLatLong(y);

    //convert to radian
    double lat1 = DegreesToRadian(x.latitude);
    double lat2 = DegreesToRadian(y.latitude);
    double lon1 = DegreesToRadian(x.longitude);
    double lon2 = DegreesToRadian(y.longitude);

    double dlat = lat1 - lat2;
    double dlon = lon1 - lon2;

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = RADIUS_OF_EARTH * c;
    
    return d;
}

void CorrectLatLong(Location& place) {

    //we don't want already corrected locations to be corrected again
    if (!place.correctedLatLong) {

        if (place.latDirection == 'S') {
            place.latitude = - place.latitude;
        }

        if (place.longDirection == 'W') {
            place.longitude = - place.longitude;
        }

        place.correctedLatLong = true;
    }

}

double DegreesToRadian(double degree) {

    return degree * (M_PI / 180);

}
