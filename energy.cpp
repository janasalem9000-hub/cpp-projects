#include "mission_types.h"

// energy.cpp - Noor
// Contains the engineering calculations for route distance, flight time,
// energy usage, remaining battery, safety reserve, and mission feasibility.

double calculateEnergyUsed(double distance, Drone drone) {
    return distance * drone.energyConsumptionRate;
}