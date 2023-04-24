#pragma once

#include "Vehicle.h"

struct SemiTruck : Vehicle
{
    SemiTruck(const std::string& n);
    SemiTruck(const SemiTruck&);
    ~SemiTruck() override;
    SemiTruck& operator=(const SemiTruck&);

    void pullOver();
    void upShift();
};
