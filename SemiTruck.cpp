#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

SemiTruck::~SemiTruck() = default;

void SemiTruck::pullOver()
{
    std::cout << name << ": this was not me!" << std::endl;
    setSpeed(0);
}

void SemiTruck::dumpTheCargo()
{
    std::cout << name << ": I leave it here!" << std::endl;
    setSpeed(50);
}
