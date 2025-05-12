#pragma once
#include "Property.h"

class CountryHouse :
    public Property
{
    unsigned int distanceFromCity;
public:
    CountryHouse(int worth, unsigned int distanceFromCity);
    double ñalculationTax() override;
    void fromJson(nlohmann::json json) override;
    nlohmann::json toJson() override;
};

