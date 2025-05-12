#pragma once
#include "Owner.h"
#include "Car.h"
#include "Apartament.h"
#include "CountryHouse.h"

#ifndef UI
#define UI

void printOwner(Owner const& owner);
void addProperty(Owner& owner);
Property* createNewCar();
Property* createNewApartament();
Property* createNewCountryHouse();

#endif // !UI
