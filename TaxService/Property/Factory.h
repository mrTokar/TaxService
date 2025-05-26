#pragma once
#include "Apartament/Apartament.h"
#include "Car/Car.h"
#include "CountryHouse/CountryHouse.h"

enum property_type {APARTAMENT, CAR, COUNTRYHOUSE};
typedef std::map<property_type, Property*> propertyMap;



class Factory
{
	Factory() {};
public:
	static Property* create(property_type type);
	static property_type getType(std::string str);
};

