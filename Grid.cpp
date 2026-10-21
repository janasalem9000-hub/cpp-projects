
#include "Grid.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

// 1. Initialize width and height.
// 2. Create the 2D vector with the required dimensions.
// 3. Initialize every cell as false (free).




Grid::Grid(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        throw invalid_argument("Grid width and height must be positive.");
    }

    this->width = width;
    this->height = height;
    this->cells = vector<vector<bool>>(height, vector<bool>(width, true));
}




// Check if a position is inside the grid

// SAMPLE IMPLEMENTATION
// Returns true if (x, y) is within the active grid.
// Otherwise, returns false.

bool Grid::isInside(int x, int y)
{
    if (x >= 0 && y >= 0 && x < width && y < height)
    {
        return true;
    }
    return false;
}



// Check if a cell is accessible

// 1. Check whether (x, y) is inside the grid.
// 2. If outside, return false.
// 3. If inside, check whether the cell is free.
// 4. Return true only if the cell is free.

bool Grid::isAccessible(int x, int y)
{
    if (this->isInside(x, y))
    {
        if (this->cells[y][x])
        {
            return true;
        }

    }
    return false;
}



// Add an obstacle

// 1. Check whether the coordinates are valid.
// 2. If invalid, return false.
// 3. If valid, mark the cell as blocked.
// 4. Return true.

bool Grid::addObstacle(int x, int y)
{
    if (this->isInside(x, y))
    {
        cells[y][x] = false;
        return true;
    }
    return false;
}


// Get grid width

//  Return the width attribute.

int Grid::getWidth()
{
    return this->width;
}



// Get grid height

//return the height attribute.

int Grid::getHeight()
{
    return this->height;
}



// Display the grid


// 
// 1. Loop through each row.
// 2. Inside each row, loop through each column.
// 3. Display a symbol for free cells and blocked cells.
// 4. Move to a new line after each row.

/*void Grid::display()
{

    for (int row = 0; row < this->height; row++)
    {
        for (int column = 0; column < this->width; column++)
        {
            if (this->cells[row][column])
            {
                cout << "*";
            }
            else
            {
                cout << "#";
            }
        }
        cout << endl;

    }
    
} */


void Grid::display()
{
    cout << "\n       DRONE DELIVERY GRID\n\n";

    // Display column numbers
    cout << "     ";
    for (int x = 0; x < width; x++)
    {
        cout << setw(3) << x;
    }
    cout << endl;

    // Top border
    cout << "    ┌";
    for (int x = 0; x < width; x++)
    {
        cout << "───";
    }
    cout << "┐" << endl;

    // Display grid rows
    for (int y = 0; y < height; y++)
    {
        cout << setw(3) << y << " │";

        for (int x = 0; x < width; x++)
        {
            if (cells[y][x])
            {
                cout << " · ";
            }
            else
            {
                cout << " ■ ";
            }
        }

        cout << "│" << endl;
    }

    // Bottom border
    cout << "    └";
    for (int x = 0; x < width; x++)
    {
        cout << "───";
    }
    cout << "┘" << endl;

    cout << "\nLegend: · Free   ■ Obstacle\n\n";
}
