#include <iostream>
#include "LocationStruct.hpp"
#include "PrintOutput.hpp"

void PrintOutput(Location& origin, Location& closest, Location& farthest) {
    
    std::cout << "Start Location: ";
    Print(origin);
    std::cout << std::endl;
    
    std::cout << "Closest Location: ";
    Print(closest);
    std::cout << std::endl;

    std::cout << "Farthest Location: ";
    Print(farthest);
    std::cout << std::endl;
}

void Print(Location& airport) {

    RemoveNegatives(airport);

    std::cout << airport.latitude << "/";
    std::cout << airport.latDirection << " ";
    std::cout << airport.longitude << "/";
    std::cout << airport.longDirection << " (";
    std::cout << airport.airport << ")";

    if (airport.distancefromOrigin != 0.0) {
        std::cout << " (" << airport.distancefromOrigin;
        std::cout << " miles)";
    }
}

void RemoveNegatives(Location& place) {
    
    if (place.latitude < 0) {
        place.latitude = - place.latitude;
    }

    if (place.longitude < 0) {
        place.longitude = - place.longitude;
    }

}
