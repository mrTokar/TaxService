#pragma once
#include "Owner.h"
#include "Car.h"
#include "Apartament.h"
#include "CountryHouse.h"

#ifndef UI
#define UI

void printOwner(Owner const& owner);
void addProperty(Owner const& owner);
Property* createNewCar();

#endif // !UI
