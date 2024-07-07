#include "HighwayPatrol.h"
#include <iostream>
#include <cassert>
#include "Highway.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"


HighwayPatrol::HighwayPatrol() : Vehicle("HighwayPatrol")
{
}

HighwayPatrol::~HighwayPatrol() = default;

void HighwayPatrol::scanHighway(Highway* h)
{
    std::cout << name << ": scanning highway for speeders" << std::endl;

    for( size_t i = h->vehicles.size(); i-- > 0; )
    {
        auto* v = h->vehicles[i];
        if( v->speed > h->speedLimit + 5 )
        {
            pullOver(v, v->speed > (h->speedLimit + 15), h );
            h->changeSpeed(50); //slow down for the highway patrol
        }
    }
}

void HighwayPatrol::pullOver( Vehicle* v, bool willArrest, Highway* h )
{
    std::cout << "\n\n";
    std::cout << name << ": vehicle is traveling " << v->speed - h->speedLimit << " miles per hour over the speed limit" << std::endl;
    if( willArrest )
    {
        //assert(false);
        //print the vehicle type in this std::cout between "THE [" and "] PULL".
        std::string typeOfVehicle = " ";

        if( auto* car = dynamic_cast<Car*>(v) )
        {
            typeOfVehicle = "car";
        }
        else if ( auto* bike = dynamic_cast<Motorcycle*>(v) )
        {
            typeOfVehicle = "motorcycle";
        }
        else if ( auto* truck = dynamic_cast<SemiTruck*>(v) )
        {
            typeOfVehicle = "semi-truck";
        }
        
        
        std::cout << name << ": YOU IN THE [ " << typeOfVehicle << " ] PULL OVER AND SHOW YOUR HANDS" << std::endl;
        std::cout << "EVERYONE ELSE, SLOW DOWN!! \n\n\n";
        h->removeVehicle(v);
    }
}
