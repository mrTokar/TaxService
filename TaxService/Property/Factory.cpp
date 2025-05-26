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
