#pragma once
#include "Apartament/Apartament.h"
#include "Car/Car.h"
#include "CountryHouse/CountryHouse.h"

class PropertyFactory
{
	PropertyFactory() {};
public:
	template <class T, typename = std::enable_if_t<std::is_base_of<Property, T>::value>>
	static T* create() { return new T(); }
};

