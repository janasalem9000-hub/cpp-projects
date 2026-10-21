
#pragma once

class Drone
{
private:
    // Drone properties
    double speed;              // Flight speed (m/s)
    double batteryCapacity;    // Battery capacity (Wh)
    double batteryPercentage;  // Current charge (%)
    double baseEnergyRate;     // Energy consumption (Wh/m)

public:
    // Constructor
    Drone(double speed, double batteryCapacity,
          double batteryPercentage, double baseEnergyRate);

    // Getter methods
    double getSpeed();
    double getBatteryCapacity();
    double getBatteryPercentage();
    double getBaseEnergyRate();

    // Calculate currently stored battery energy (Wh)
    double getStoredEnergy();
};
