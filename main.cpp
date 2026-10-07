#include <iostream>
#include "mission_types.h"

using namespace std;

// main.cpp - Jana
// Connects all parts of the program together, handles the overall program flow,
// and displays the final mission results.
int main() {
    Position startPoint;
    startPoint.x = 0;
    startPoint.y = 0;

    Position endPoint;
    endPoint.x = 5;
    endPoint.y = 5;

    Drone myDrone;
    myDrone.speed = 5.0;
    myDrone.batteryCapacity = 100.0;
    myDrone.currentBattery = 80.0;
    myDrone.energyConsumptionRate = 2.0;

    Environment map;
    map.gridWidth = 10;
    map.gridHeight = 10;
    map.start = startPoint;
    map.destination = endPoint;

    cout << "Start: " << map.start.x << ", " << map.start.y << endl;
    cout << "Destination: " << map.destination.x << ", " << map.destination.y << endl;
    cout << "Drone speed: " << myDrone.speed << endl;

    return 0;
}
