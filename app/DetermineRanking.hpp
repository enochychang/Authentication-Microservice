#ifndef DETERMINERANKING_HPP
#define DETERMINERANKING_HPP

#include <vector>
#include "LocationStruct.hpp"

Location DetermineClosest(Location& origin, std::vector<Location>& targetLocs);

Location DetermineFarthest(Location& origin, std::vector<Location>& targetLocs);

double CalculateDistance(Location& x, Location& y);

void CorrectLatLong(Location& place);

double DegreesToRadian(double degree);

#endif