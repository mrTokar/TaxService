#pragma once
#include "../Property.h"
#include "../Service/TaxRate.h"

class Apartament :
    public Property
{
    double square;
public:
    Apartament(int worth, double square);
    inline ~Apartament() override {};
    double ñalculationTax() override;

    void fromJson(nlohmann::json) override;

    void fromXml(pugi::xml_node& node) override;
    void toXml(pugi::xml_node& root) override;
};

