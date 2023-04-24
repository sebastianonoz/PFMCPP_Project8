#include "Highway.h"
#include "Vehicle.h"
#include <cassert>
#include "Motorcycle.h"
#include "Car.h"
#include "SemiTruck.h"

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    //assert(false);
    if (auto* car = dynamic_cast<Car*>(v))
    {
        car->closeWindows();
    }
    else if (auto* mc = dynamic_cast<Motorcycle*>(v))
    {
        mc->lanesplitAndRace(100);
    }
    else if (auto* st = dynamic_cast<SemiTruck*>(v))
    {
        st->upShift();
    }
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    do not call `setSpeed`.  Pick a different function.
    */
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);
    if (auto* car = dynamic_cast<Car*>(v))
    {
        car->tryToEvade();
    }
    else if (auto* mc = dynamic_cast<Motorcycle*>(v))
    {
        mc->tryToEvade();
    }
    else if (auto* st = dynamic_cast<SemiTruck*>(v))
    {
        st->pullOver();
    }
    /*
    depending on the derived type, call the member function that tries to evade the cops. 
    do not call `setSpeed`.  Pick a different function.
    trucks pull over, but cars and bikes try to evade!!
    */
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
