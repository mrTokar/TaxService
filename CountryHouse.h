#pragma once
#include "Property.h"
class CountryHouse :
    public Property
{
    unsigned int distanceFromCity;
public:
    CountryHouse(int worth, unsigned int distanceFromCity);
};

