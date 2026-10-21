
#include "Drone.h"
#include <stdexcept>
using namespace std;

// Constructor
Drone::Drone(double speed, double batteryCapacity,
             double batteryPercentage, double baseEnergyRate)
{

    // 1. Validate the input values.
    // 2. Initialize the private attributes.
    if (speed <= 0 || batteryCapacity <= 0 || batteryPercentage < 0 || 
        batteryPercentage > 100 || baseEnergyRate <= 0)
    {
        throw invalid_argument("Argument with invalid input");
    }

    this->baseEnergyRate = baseEnergyRate;
    this->batteryPercentage = batteryPercentage;
    this->batteryCapacity = batteryCapacity;
    this->speed = speed;

}


// Getter methods

double Drone::getSpeed()
{
    // Return drone speed.
    return this->speed;
}

double Drone::getBatteryCapacity()
{
    // Return battery capacity.
    return this->batteryCapacity;
}

double Drone::getBatteryPercentage()
{
    // Return battery percentage.
    return this->batteryPercentage;
}

double Drone::getBaseEnergyRate()
{
    // Return base energy consumption rate.
    return this->baseEnergyRate;
}


// Battery calculation

double Drone::getStoredEnergy()
{
    // Calculate stored energy in Wh.
    // Use battery capacity and current battery percentage.
    return (this->batteryCapacity * (this->batteryPercentage/100));
}
