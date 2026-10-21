#pragma once
#include <vector>
#include "Position.h"

struct MissionResult
{
    // Calculated route (start to destination)
    // Includes the return route if requested
    std::vector<Position> path;

    // Mission calculations
    double distance = 0.0;
    double flightTime = 0.0;
    double energyRequired = 0.0;
    double remainingBattery = 0.0; 

    // Mission status
    bool feasible = false;
    bool pathFound = false;
};
