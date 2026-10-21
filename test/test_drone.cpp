
#include <iostream>
#include "Drone.h"

using namespace std;

int main()
{
    // TEST 1: Create a valid Drone object
    Drone myDrone(5, 200, 75, 0.5);

    // Create a Drone object named myDrone
    // with these parameters:
    // speed = 5 m/s
    // battery capacity = 200 Wh
    // battery percentage = 75%
    // base energy rate = 0.5 Wh/m


    // TEST 2: Test getter methods

    // Display the drone's speed.
    cout << "Drone speed: " << myDrone.getSpeed() << endl;

    //  Display the battery capacity.
    cout << "Drone battery capcity: " << myDrone.getBatteryCapacity() << endl;

    //  Display the battery percentage.
    cout << "Drone battery percentage: " << myDrone.getBatteryPercentage() << endl;

    //  Display the base energy rate.
    cout << "Drone base energy rate: " << myDrone.getBaseEnergyRate() << endl;


    // ====================================
    // TEST 3: Test stored energy
    // ====================================

    //  Call getStoredEnergy().
    // Display the result.
    cout << "Drone stored energy: " << myDrone.getStoredEnergy() << endl;


    // ====================================
    // TEST 4: Test invalid input
    // ====================================

    //  Try creating a Drone with:
    // battery percentage = 120%.
    //
    // Expected: Constructor throws invalid_argument.
    //
    // Hint: Use try and catch to handle the exception.


    return 0;
}
