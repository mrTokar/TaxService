#include "Factory.h"

Property* Factory::create(property_type type)
{
	propertyMap m = {
		{APARTAMENT, new Apartament(0,0)},
		{CAR, new Car(0,0)},
		{COUNTRYHOUSE, new CountryHouse(0,0)}
	};
	return m[type];
}

property_type Factory::getType(std::string str)
{
	std::map<std::string, property_type> m = {
		{"Apartament", APARTAMENT},
		{"Car", CAR},
		{"CountryHouse", COUNTRYHOUSE}
	};
	return m[str];
}
