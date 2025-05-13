#pragma once
#include "Apartament.h"
#include "Car.h"
#include "CountryHouse.h"

class PropertySimpleFactory
{
public:
	static Property* getProperty(std::string key);
};

