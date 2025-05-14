#pragma once
#include "Apartament/Apartament.h"
#include "Car/Car.h"
#include "CountryHouse/CountryHouse.h"

class PropertySimpleFactory
{
public:
	static Property* getProperty(std::string key);
};

