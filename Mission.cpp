
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
                 PathFinder& pathFinder,
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
    // TODO: Throw invalid_argument if safetyReserve is invalid.
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

    // TODO: result.path = ...


    // --------------------------------------------------
    // STEP 2.2: Check whether a route exists
    // --------------------------------------------------
    // If result.path is empty:
    //     return result immediately.
    //
    // Otherwise:
    //     result.pathFound = true;

    // TODO: Implement the check.


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

    // TODO: Calculate the distance.


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
        // TODO 2.4.1: Find return path.

        // TODO 2.4.2: Check whether return path is empty.

        // TODO 2.4.3: Add return distance.

        // TODO 2.4.4: Append return path without
        //             duplicating the destination.
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

    // TODO: result.flightTime = ...


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

    // TODO: result.energyRequired = ...


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

    // TODO: Calculate storedEnergy.
    // TODO: Calculate remainingEnergy.
    // TODO: Calculate remainingBattery percentage.


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

    // TODO: Set result.feasible to true or false.


    // --------------------------------------------------
    // STEP 2.9: Return the result
    // --------------------------------------------------

    return result;
}
