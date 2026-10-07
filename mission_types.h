#ifndef MISSION_TYPES_H
#define MISSION_TYPES_H
#include <vector>
struct Position {
    int x;
    int y;
};

struct Drone {
    double speed;
    double batteryCapacity;
    double currentBattery;
    double energyConsumptionRate;
};
struct Environment {
    int gridWidth;
    int gridHeight;

    Position start;
    Position destination;
    std::vector<Position> obstacles;
    std::vector<Position> noFlyZones;
};

#endif
