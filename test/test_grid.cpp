#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    // ========================================
    // Test 1: Create a Grid object
    // ========================================

    //  Create a Grid object named myGrid
    // with width = 5 and height = 4.
    Grid myGrid(5, 4);

    // ========================================
    // Test 2: Display the empty grid
    // ========================================

    cout << "Initial Grid:" << endl;
    myGrid.display();

    //  Call the display() method.


    // ========================================
    // Test 3: Add obstacles
    // ========================================

    //  Add an obstacle at (1,1).
    //  Add another obstacle at (3,2).
    myGrid.addObstacle(1,1);
    myGrid.addObstacle(3, 2);


    // ========================================
    // Test 4: Display the updated grid
    // ========================================

    cout << "\nGrid After Adding Obstacles:" << endl;
    myGrid.display();

    //  Call display() again.


    // ========================================
    // Test 5: Check accessibility
    // ========================================

    //  Check whether (1,1) is accessible.
    //  Check whether (0,0) is accessible.
    // Display both results.


    // ========================================
    // Test 6: Check boundaries
    // ========================================

    //  Check whether (5,2) is inside the grid.
    //  Check whether (4,3) is inside the grid.
    // Display both results.


    // ========================================
    // Test 7: Test invalid obstacle placement
    // ========================================

    //  Try adding an obstacle at (7,7).
    // Display whether the operation succeeded.


    return 0;
}

