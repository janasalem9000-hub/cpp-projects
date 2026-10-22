#include "mission_types.h"
#include "energy.h"

// energy.cpp - Noor
// Contains the engineering calculations for route distance, flight time,
// energy usage, remaining battery, safety reserve, and mission feasibility.
double calculateFlightTime(double distance, Drone drone) {
    return distance / drone.speed;
}

double calculateRemainingBattery(double energyUsed, Drone drone) {
    return (drone.currentBattery - energyUsed) / drone.batteryCapacity * 100.0;
}

bool isMissionFeasible(double energyUsed, Drone drone) {
    return energyUsed <= drone.currentBattery &&
           calculateRemainingBattery(energyUsed, drone) >= drone.safetyReserve;
}

double calculateEnergyUsed(double distance, Drone drone) {
    return distance * drone.energyConsumptionRate;
}
