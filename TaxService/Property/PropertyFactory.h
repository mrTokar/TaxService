#pragma once
#include "Apartament/Apartament.h"
#include "Car/Car.h"
#include "CountryHouse/CountryHouse.h"

class PropertyFactory
{
	PropertyFactory() {};
public:
	template<class T>
	static T* create() { return T(); }
};

