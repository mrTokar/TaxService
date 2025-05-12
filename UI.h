#pragma once
#include "Owner.h"
#include "Car.h"
#include "Apartament.h"
#include "CountryHouse.h"

#ifndef UI
#define UI

void printOwner(Owner const& owner);

Owner createNewOwner();

void addProperty(Owner& owner);
void deleteProperty(Owner& owner);

Property* createNewCar();
Property* createNewApartament();
Property* createNewCountryHouse();

#endif // !UI
