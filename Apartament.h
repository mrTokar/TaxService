#pragma once
#include "Property.h"
class Apartament :
    public Property
{
    double square;
public:
    Apartament(int worth, double square);
    double �alculationTax() override;
    void fromJson(nlohmann::json) override;
};

