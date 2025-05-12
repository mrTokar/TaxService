#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(std::string key)
{
	Property* obj = nullptr;
	if (key == "Apartament") {
		obj = new Apartament(0, 0);
	}
	else if (key == "Car") {
		obj = new Car(0, 0);
	}
	else if (key == "CountryHouse") {
		obj = new CountryHouse(0, 0);
	}
	return obj;
}
