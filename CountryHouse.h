#pragma once
#include "Property.h"

class CountryHouse :
    public Property
{
    unsigned int distanceFromCity;
public:
    CountryHouse(int worth, unsigned int distanceFromCity);
    inline ~CountryHouse() override {};
    double �alculationTax() override;
    void fromJson(nlohmann::json json) override;
};

