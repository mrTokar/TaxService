#pragma once
#include "Property.h"
class CountryHouse :
    public Property
{
    double distanceFromCity;
public:
    CountryHouse(int worth, double distanceFromCity);
};

