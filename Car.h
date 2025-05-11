#pragma once
#include "Property.h"
class Car :
    public Property
{
    float horsepower;
public:
    Car(int worth, float horsepower);
};

