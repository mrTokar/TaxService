#include "CountryHouse.h"

CountryHouse::CountryHouse(int worth, double distanceFromCity): Property(worth)
{
	this->distanceFromCity = distanceFromCity;
}
