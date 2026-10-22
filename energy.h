#ifndef ENERGY_H
#define ENERGY_H

#include "mission_types.h"

double calculateEnergyUsed(double distance, Drone drone);
double calculateFlightTime(double distance, Drone drone);
double calculateRemainingBattery(double energyUsed, Drone drone);
bool isMissionFeasible(double energyUsed, Drone drone);

#endif
