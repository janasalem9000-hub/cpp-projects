#include <iostream>
#include "Position.h"

using namespace std;

int main()
{
    Position myPosition{1, 1};
    cout << "My x position is: " << myPosition.x << " my y position is: " << myPosition.y;

    return 0;
}

