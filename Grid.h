#pragma once
#include <vector>
#include <stdexcept>
using namespace std;


// grid class created by lamees
class Grid
{
private:
    int width;
    int height;
    vector<vector<bool>> cells;

public:  

    Grid(int width, int height);

    bool isInside(int x, int y);

    bool isAccessible(int x, int y);

    bool addObstacle(int x, int y);

    int getWidth();

    int getHeight();
    
    void display();
};

