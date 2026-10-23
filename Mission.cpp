
#include "Mission.h"
#include <stdexcept>
#include <vector>

using namespace std;

// ======================================================
// STEP 1: Constructor
// ======================================================
// Initialize the six Mission attributes.
//
// Parameters:
// drone         -> existing Drone object
// pathFinder    -> existing PathFinder object
// starting      -> starting position
// destination   -> delivery destination
// safetyReserve -> required battery reserve (0 to 100)
// returnToBase  -> true if drone must return to start
//
// TODO 1.1: Complete the initializer list.
// TODO 1.2: Validate safetyReserve is between 0 and 100.

Mission::Mission(Drone& drone,
                 Pathfinder& pathFinder,
                 Position starting,
                 Position destination,
                 double safetyReserve,
                 bool returnToBase)
    : drone(drone),
      pathFinder(pathFinder),
      startingPosition(starting),
      destinationPosition(destination),
      safetyReserve(safetyReserve),
      returnBaseFlag(returnToBase)
{
  // Throw invalid_argument if safetyReserve is invalid.
  if (safetyReserve < 0 || safetyReserve > 100)
    throw invalid_argument("safetyReserve must be between 0 and 100");
}

// ======================================================
// STEP 2: Evaluate the Mission
// ======================================================

MissionResult Mission::evaluate()
{
  // Create a result object.
  // Its fields already have default values.
  MissionResult result;
  // --------------------------------------------------
  // STEP 2.1: Find the delivery route
  // --------------------------------------------------
  // Call pathFinder.findPath() using:
  // startingPosition and destinationPosition.
  //
  // Store the returned vector in result.path. 
  result.path = pathFinder.findPath(startingPosition, destinationPosition);

// --------------------------------------------------
// STEP 2.2: Check whether a route exists
// --------------------------------------------------
// If result.path is empty:
//     return result immediately.
//
// Otherwise:
//     result.pathFound = true;
  
     if (result.path.empty())
        return result;
     else result.pathFound = true;
  
    // --------------------------------------------------
    // STEP 2.3: Calculate delivery distance
    // --------------------------------------------------
    // Each movement between neighboring cells = 1 meter.
    //
    // Number of movements = path.size() - 1.
    //
    // Example:
    // 5 positions = 4 movements = 4 meters.
    //
    // Store in result.distance.

    result.distance = result.path.size() - 1;

    // --------------------------------------------------
    // STEP 2.4: Handle return to base
    // --------------------------------------------------
    // Only execute if returnBaseFlag is true.
    //
    // Call findPath again:
    //     from destinationPosition to startingPosition.
    //
    // If no return route exists:
    //     mark pathFound = false;
    //     return result.
    //
    // Otherwise:
    //     Add the return distance to result.distance.
    //     Append the return positions to result.path.
    //
    // IMPORTANT:
    // Skip the FIRST position of the return path.
    // It is the delivery destination, which is already
    // the last position of the outbound path.

    if (returnBaseFlag)
    {
        //Find return path.
      vector<Position> back = pathFinder.findPath(destinationPosition, startingPosition);

        //Check whether return path is empty.
      if (back.empty())
        {
            result.pathFound = false;
            return result;
        }
        // Add return distance.
      result.distance += back.size() - 1;
        //Append return path without duplicating the destination.
      result.path.insert(result.path.end(), back.begin() + 1, back.end());
    }
  
    // --------------------------------------------------
    // STEP 2.5: Calculate flight time
    // --------------------------------------------------
    // Formula:
    //
    // flightTime = total distance / drone speed
    //
    // Assuming speed is measured in meters/second,
    // the result will be in seconds.
    //
    // Use your Drone class speed getter.
  
result.flightTime = result.distance / drone.getSpeed();

    // --------------------------------------------------
    // STEP 2.6: Calculate required energy
    // --------------------------------------------------
    // Formula:
    //
    // energyRequired = total distance * baseEnergyRate
    //
    // Energy consumption rate must be in Wh/m.
    //
    // Use your Drone class energy-rate getter.

result.energyRequired = result.distance * drone.getBaseEnergyRate();

    // --------------------------------------------------
    // STEP 2.7: Calculate remaining battery percentage
    // --------------------------------------------------
   // The Drone class already stores:
    //  - battery capacity (Wh)
    //  - battery percentage (%)
    //
    // Stored energy:
    //
    // storedEnergy = capacity * batteryPercentage / 100
    //
    // Or use drone.getStoredEnergy() if available.
    //
    // Remaining energy:
    //
    // remainingEnergy = storedEnergy - energyRequired
    //
    // Remaining battery percentage:
    //
    // remainingBattery = remainingEnergy / capacity * 100
    //
    // Store in result.remainingBattery. 

    double storedEnergy = drone.getStoredEnergy();
    double remainingEnergy = storedEnergy - result.energyRequired;
  result.remainingBattery = remainingEnergy / drone.getBatteryCapacity() * 100.0;
    //
    // --------------------------------------------------
    // STEP 2.8: Determine mission feasibility
    // --------------------------------------------------
    // A mission is feasible when:
    //
    // 1. A valid route exists (already checked).
    // 2. Required energy does not exceed stored energy.
    // 3. Remaining battery percentage is at least
    //    safetyReserve.
    //
    // Store the final answer in result.feasible.
result.feasible = (result.energyRequired <= storedEnergy) && (result.remainingBattery >= safetyReserve);

    // --------------------------------------------------
    // STEP 2.9: Return the result
    // --------------------------------------------------
    return result;
}
