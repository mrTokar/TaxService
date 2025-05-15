#pragma once
#include "../Property.h"
#include "../Service/TaxRate.h"

class Car :
    public Property
{
    float horsepower;
public:
    Car(int worth, float horsepower);
    inline ~Car() override {};
    double ñalculationTax() override;

    void fromJson(nlohmann::json json) override;

    void fromXml(pugi::xml_node& node) override;
    void toXml(pugi::xml_node& root) override;
};

