#pragma once
#include "Property.h"
class Apartament :
    public Property
{
    double square;
public:
    Apartament(int worth, double square);
    inline ~Apartament() override {};
    double ñalculationTax() override;
    void fromJson(nlohmann::json) override;
};

