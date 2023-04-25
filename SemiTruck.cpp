#include <iostream>
#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) { }

SemiTruck::SemiTruck(const SemiTruck&) = default;

SemiTruck::~SemiTruck() = default;

SemiTruck& SemiTruck::operator=(const SemiTruck&) = default;

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << " is getting pulled over." << std::endl;
}

void SemiTruck::upShift()
{
    setSpeed(66);
    std::cout << name << ": Shifting up a gear!" << std::endl;
}

