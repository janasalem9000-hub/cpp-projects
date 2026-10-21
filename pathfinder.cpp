
#include "PathFinder.h"
#include "Grid.h"
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm> //for reverse()

using namespace std;

// Constructor
Pathfinder::Pathfinder(Grid& grid)
    : grid(grid)
{
}


// Manhattan Heuristic
int Pathfinder::heuristic(Position a, Position b)
{
    int distance = abs(a.x - b.x) + abs(a.y - b.y);
    return distance;
}


// Find Path Using A* Algorithm
vector<Position> Pathfinder::findPath(Position start, Position destination)
{

    //Validate start and destination
    if (!grid.isAccessible(start.x, start.y) ||
        !grid.isAccessible(destination.x, destination.y))
    {
        return {};
    }

    // STEP 2: Initialize A* data structures   
    vector<Position> openSet;
    openSet.push_back(start);

    // 2.2 closed Set.
    vector<vector<bool>> closedSet = 
    vector<vector<bool>>(grid.getHeight(), vector<bool>(grid.getWidth(), false));



    // 2.3 Create the gCost table.
    vector<vector<int>> gCost = 
    vector<vector<int>>(grid.getHeight(), vector<int>(grid.getWidth(), INT_MAX));    


    // 2.4: Set the starting cell's gCost to 0.
    gCost[start.y][start.x] = 0;

    // 2.5: Create the hCost table.
    // Use a 2D vector of int.
    // Calculate Manhattan distance for each cell.
    vector<vector<int>> hCost =  
    vector<vector<int>>(grid.getHeight(), vector<int>(grid.getWidth(), 0));
    for (int row = 0; row < grid.getHeight(); row++)
    {
        for (int col = 0; col < grid.getWidth(); col++)
        {
            Position current{col, row};
            hCost[row][col] = heuristic(current, destination);
        }
    }


    //2.6: Create the parent data structure.
  
    vector<vector<Position>> parent = vector<vector<Position>>(grid.getHeight(),
                        vector<Position>(grid.getWidth(), Position{-1, -1}));

    // STEP 3: Begin A* search
 
   
    // While the Open Set is not empty:
    //
    // 1. Find the position with the lowest f = g + h.
    // 2. Remove it from the Open Set.
    // 3. Check whether it is the destination.
    // 4. Mark it as explored.
    // STEP 3: A* Search Loop
    while (!openSet.empty())
    {
    // STEP 3.2: Find the position with the lowest fCost
        int bestIndex = 0;

        for (int i = 1; i < openSet.size(); i++)
        {
            if (hCost[openSet[i].y][openSet[i].x] +
                gCost[openSet[i].y][openSet[i].x] <
                hCost[openSet[bestIndex].y][openSet[bestIndex].x] +
                gCost[openSet[bestIndex].y][openSet[bestIndex].x])
            {
                bestIndex = i;
            }
        }

        // STEP 3.3: Select and remove the best position
        Position current = openSet[bestIndex];
        openSet.erase(openSet.begin() + bestIndex);

        // STEP 3.4: Check if destination is reached
        if (current.y == destination.y && current.x == destination.x)
        {
            vector<Position> path;
            Position step = destination;
            path.push_back(step);
            while (step.x != start.x || step.y != start.y)
            {
                step = parent[step.y][step.x];
                path.push_back(step);
                
            }

            reverse(path.begin(), path.end());
            return path;
        }

      
        // STEP 3.5: Mark current position as explored
        closedSet[current.y][current.x] = true;

        // STEP 4: Explore the four neighboring cells
        Position right{current.x + 1, current.y};
        Position left{current.x - 1, current.y};
        Position up{current.x, current.y - 1};
        Position down{current.x, current.y + 1};

        vector<Position> neighbors = {right, left, up, down};

        for (int i = 0; i < 4; i++)
        {
            if (grid.isAccessible(neighbors[i].x, neighbors[i].y) &&
            !closedSet[neighbors[i].y][neighbors[i].x])
            {
                int tentativeG = gCost[current.y][current.x] + 1;
                if (tentativeG < gCost[neighbors[i].y][neighbors[i].x])
                {
                    gCost[neighbors[i].y][neighbors[i].x] = tentativeG;
                    parent[neighbors[i].y][neighbors[i].x] = current;

                // Check whether neighbor is already in openSet
                bool alreadyInOpenSet = false;
                for (int position = 0; position < openSet.size(); position++)
                {
                    if (openSet[position].x == neighbors[i].x && 
                        openSet[position].y == neighbors[i].y)
                        {
                            alreadyInOpenSet = true;
                            break;
                        }
                }
                
                if (!alreadyInOpenSet)
                {
                    openSet.push_back(neighbors[i]);
                }

                } 
            }

        }
    }
   

    return {};
}
