#ifndef READINPUT_HPP
#define READINPUT_HPP

#include <vector>
#include "LocationStruct.hpp"

Location ReadInput();

int NumTargetLocations();

void FillTargetLocations(int numLocations, std::vector<Location>& targetLocs);

#endif