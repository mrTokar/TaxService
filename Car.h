#pragma once
#include "Property.h"
class Car :
    public Property
{
    float horsepower;
public:
    Car(int worth, float horsepower);
    inline ~Car() override {};
    double �alculationTax() override;
    void fromJson(nlohmann::json json) override;
};

