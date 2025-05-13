#include "CountryHouse.h"
#include "TaxRate.h"
using namespace TAX_RATES;

CountryHouse::CountryHouse(int worth, unsigned int distanceFromCity): Property(worth)
{
	this->distanceFromCity = distanceFromCity;
}

double CountryHouse::ñalculationTax()
{
	if (distanceFromCity <= LIMIT_DISTANCE_FROM_CITY) {
		return worth * Apartment_TAX;
	}
	else {
		return worth * COUNTRY_HOUSE_TAX;
	}
}

void CountryHouse::fromJson(nlohmann::json json)
{
	try {
		distanceFromCity = json["distance"].get<unsigned int>();
		worth = json["worth"].get<unsigned int>();
	}
	catch (...) {
		throw std::runtime_error("No required keys in json");
	}
}
