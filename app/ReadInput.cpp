#include <iostream>
#include <vector>
#include <limits>
#include "LocationStruct.hpp"
#include "ReadInput.hpp"

Location ReadInput() {
    
    //note to self: we cannot pass a Location into ReadInput 
    //and then update it because it is pass by copy
    //so we create a new Location and return it instead
    Location place;

    //Get starting location
    std::cin >> place.latitude;
    std::cin.ignore(1);
    std::cin >> place.latDirection;

    std::cin >> place.longitude;
    //for cin.ignore, noskipws set to true which means that 
    //"as many initial whitespace characters as necessary are read and discarded from the stream until a non-whitespace character is found"
    //which makes this work, but we need std::ws later
    std::cin.ignore(1);
    std::cin >> place.longDirection;

    //here we still have leading white spaces in the buffer
    //we can discard them with std::ws
    std::cin >> std::ws;
    std::getline(std::cin, place.airport);

    return place;  
  
}

int NumTargetLocations() {

    int numLocations = 0;    
    std::cin >> numLocations;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return numLocations;

}

void FillTargetLocations(int numLocations, std::vector<Location>& targetLocs) {

    for (int i = 0; i < numLocations; ++i) {
        Location newLoc = ReadInput();
        //should work because push_back is implemented by creating a copy
        targetLocs.push_back(newLoc);
    }

}
