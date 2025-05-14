#pragma once
#include "../Property.h"
#include "../TaxService/TaxRate.h"

class CountryHouse :
    public Property
{
    unsigned int distanceFromCity;
public:
    CountryHouse(int worth, unsigned int distanceFromCity);
    inline ~CountryHouse() override {};
    double ñalculationTax() override;

    void fromJson(nlohmann::json json) override;

    void fromXml(pugi::xml_node& node) override;
    void toXml(pugi::xml_node& root) override;
};

