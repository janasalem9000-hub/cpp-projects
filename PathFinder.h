#pragma once

#include "Grid.h"
#include "Position.h"
#include <vector>

class Pathfinder
{
private:
    Grid& grid;
    int heuristic(Position a, Position b);

public:
    Pathfinder(Grid& grid);

    std::vector<Position> findPath(Position start, Position destination);
};
