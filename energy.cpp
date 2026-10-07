#include "mission_types.h"
// Noor Tasks here: add distance, time, and battery calculations here
double calculateEnergyUsed(double distance, Drone drone) {
    return distance * drone.energyConsumptionRate;
}