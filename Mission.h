#pragma once

#include "Drone.h"
#include "PathFinder.h"
#include "Position.h"
#include "MissionResult.h"

class Mission
{
private:
    Drone& drone;
    Pathfinder& pathFinder;
    Position startingPosition;
    Position destinationPosition;

    double safetyReserve;
    bool returnBaseFlag;

public:
    // Constructor
    Mission(Drone& drone,
            Pathfinder& pathFinder,
            Position starting,
            Position destination,
            double safetyReserve,
            bool returnToBase);

    // Evaluate the mission
    MissionResult evaluate();
};