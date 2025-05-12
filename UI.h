#pragma once
#include "Owner.h"
#include "Car.h"
#include "Apartament.h"
#include "CountryHouse.h"

#ifndef UI
#define UI

void printOwner(Owner const& owner);
void printOwners(vector<Owner> const& owners);

Owner createNewOwner();
void deleteOwner(vector<Owner>& owners);

void addProperty(Owner& owner);
void deleteProperty(Owner& owner);

Property* createNewCar();
Property* createNewApartament();
Property* createNewCountryHouse();

#endif // !UI
