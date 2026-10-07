#ifndef MISSION_TYPES_H
#define MISSION_TYPES_H

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

#endif
