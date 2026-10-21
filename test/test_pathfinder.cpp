
#include <iostream>
#include <vector>
#include "PathFinder.h"
#include "Position.h"
#include "Grid.h"

using namespace std;

int main()
{
    // ========================================
    // Test 1: Create Grid and Pathfinder
    // ========================================

    Grid myGrid(5, 5);
    Pathfinder myPathfinder(myGrid);

    cout << "Initial Grid:" << endl;
    myGrid.display();


    // ========================================
    // Test 2: Find path without obstacles
    // ========================================

    Position start{0, 0};
    Position destination{4, 4};

    vector<Position> path =
        myPathfinder.findPath(start, destination);

    cout << "\nPath Without Obstacles:" << endl;

    for (Position p : path)
    {
        cout << "(" << p.x << "," << p.y << ") ";
    }

    cout << endl;

    if (!path.empty())
    {
        cout << "Distance: " << path.size() - 1
             << " meters" << endl;
    }


    // ========================================
    // Test 3: Add obstacles
    // ========================================

    myGrid.addObstacle(1, 0);
    myGrid.addObstacle(1, 1);
    myGrid.addObstacle(1, 2);

    cout << "\nGrid After Adding Obstacles:" << endl;
    myGrid.display();


    // ========================================
    // Test 4: Find path with obstacles
    // ========================================

    path = myPathfinder.findPath(start, destination);

    cout << "\nPath With Obstacles:" << endl;

    for (Position p : path)
    {
        cout << "(" << p.x << "," << p.y << ") ";
    }

    cout << endl;

    if (!path.empty())
    {
        cout << "Distance: " << path.size() - 1
             << " meters" << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }


    // ========================================
    // Test 5: Block the destination
    // ========================================

    myGrid.addObstacle(4, 4);

    path = myPathfinder.findPath(start, destination);

    cout << "\nBlocked Destination Test:" << endl;

    if (path.empty())
    {
        cout << "No path found (expected)." << endl;
    }
    else
    {
        cout << "Unexpected path found!" << endl;
    }


    // ========================================
    // Test 6: Start equals destination
    // ========================================

    Position samePoint{0, 0};

    path = myPathfinder.findPath(samePoint, samePoint);

    cout << "\nStart Equals Destination Test:" << endl;

    for (Position p : path)
    {
        cout << "(" << p.x << "," << p.y << ") ";
    }

    cout << endl;


    // ========================================
    // Test 7: Invalid starting position
    // ========================================

    Position invalidStart{-1, 0};

    path = myPathfinder.findPath(invalidStart, destination);

    cout << "\nInvalid Start Test:" << endl;

    if (path.empty())
    {
        cout << "No path found (expected)." << endl;
    }
    else
    {
        cout << "Unexpected path found!" << endl;
    }


    return 0;
}
