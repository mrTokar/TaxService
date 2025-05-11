#include "CountryHouse.h"

CountryHouse::CountryHouse(int worth, unsigned int distanceFromCity): Property(worth)
{
	this->distanceFromCity = distanceFromCity;
}
