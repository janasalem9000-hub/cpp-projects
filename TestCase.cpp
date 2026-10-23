#include <iostream>
#include "Grid.h"
#include "PathFinder.h"
#include "Drone.h"
#include "Mission.h"

using namespace std;

int main()
{
    // Open 10x10 map, no obstacles
    Grid grid(10, 10);
    Pathfinder pathFinder(grid);

    // speed (m/s), capacity (Wh), charge (%), energy rate (Wh/m)
    Drone drone(5.0, 100.0, 80.0, 2.0);

    Position start{0, 0};
    Position destination{5, 5};

    // 20% safety reserve, no return to base
    Mission mission(drone, pathFinder, start, destination, 20, false);
    MissionResult result = mission.evaluate();

    cout << "Test: open map, (0,0) to (5,5), one way, 20% reserve" << endl;
    cout << "  Path found:        " << (result.pathFound ? "yes" : "no") << endl;
    cout << "  Distance:          " << result.distance << " m" << endl;
    cout << "  Flight time:       " << result.flightTime << " s" << endl;
    cout << "  Energy required:   " << result.energyRequired << " Wh" << endl;
    cout << "  Remaining battery: " << result.remainingBattery << " %" << endl;
    cout << "  Feasible:          " << (result.feasible ? "YES" : "NO") << endl;

    cout << endl;
    cout << "Expected (hand-calculated): 10 m, 2 s, 20 Wh, 60 %, feasible" << endl;

    return 0;
}
