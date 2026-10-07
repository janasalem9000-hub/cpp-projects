#ifndef MISSION_TYPES_H
#define MISSION_TYPES_H

#include <vector>
// mission_types.h - Jana
// Defines the shared data structures for the project, including positions,
// drone information, obstacles, no-fly zones, and environment settings.

struct Position {
    int x;
    int y;
};

struct Area {
    Position location;
    int width;
    int height;
};

struct Drone {
    double speed;
    double batteryCapacity;
    double currentBattery;
    double energyConsumptionRate;
    double packageWeight;
    double packageEnergyRate;
    double safetyReserve;
};

struct Environment {
    int gridWidth;
    int gridHeight;

    Position start;
    Position destination;

    std::vector<Area> obstacles;
    std::vector<Area> noFlyZones;

    bool simulationMode;
    bool returnTrip;
};

#endif