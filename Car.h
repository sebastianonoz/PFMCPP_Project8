#pragma once

#include "Vehicle.h"

struct Car : Vehicle
{
    Car(const std::string& s);
    Car(const Car&);
    ~Car() override;
    Car& operator=(const Car&);

    void closeWindows();
    void tryToEvade() override;
};
