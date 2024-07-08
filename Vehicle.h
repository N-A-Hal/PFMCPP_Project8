#pragma once

#include <string>
#include <iostream>

struct HighwayPatrol;

struct Vehicle
{
    Vehicle(const std::string& n);
    
    //Special member Functions.  See instruction 9) and note in main()
    virtual ~Vehicle();
    Vehicle(const Vehicle&) = default;
    Vehicle& operator=(const Vehicle&) = default;
    
    virtual void setSpeed(int s);
    virtual void tryToEvade();

protected:
    int speed = 0;
    std::string name;
private:
    friend HighwayPatrol;
};
