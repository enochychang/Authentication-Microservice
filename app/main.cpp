#include <iostream>
#include <vector>
#include "LocationStruct.hpp"
#include "ReadInput.hpp"
#include "PrintOutput.hpp"
#include "DetermineRanking.hpp"

int main() {

    //starting location
    Location origin = ReadInput();

    //get number of target locations
    int numLocations = NumTargetLocations();

    //create vector to store all target locations 
    std::vector<Location> targetLocs;

    //fill vector with each target location x or numLocations number of times
    FillTargetLocations(numLocations, targetLocs);

    //calculate distances and determine ranking
    Location closest = DetermineClosest(origin, targetLocs);
    Location farthest = DetermineFarthest(origin, targetLocs);
    
    //print results
    PrintOutput(origin, closest, farthest);

    return 0;
}

