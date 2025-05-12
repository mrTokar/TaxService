#pragma once
#include "Property.h"
class Car :
    public Property
{
    float horsepower;
public:
    Car(int worth, float horsepower);
    double ñalculationTax() override;
    void fromJson(nlohmann::json json) override;
    nlohmann::json toJson() override;
};

