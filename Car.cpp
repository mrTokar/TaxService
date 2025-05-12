#include "Car.h"
#include "TaxRate.h"
using namespace TAX_RATES;

Car::Car(int worth, float horsepower): Property(worth)
{
	this->horsepower = horsepower;
}

double Car::ñalculationTax()
{
	if (horsepower < LOW_HORSEPOWER) {
		return worth * CAR_TAX;
	}
	else if (horsepower > HIGH_HORSEPOWER) {
		return worth * CAR_LUXURY_TAX;
	}
	else {
		return worth * CAR_TRUCK_TAX;
	}
}

void Car::fromJson(nlohmann::json json)
{
	horsepower = json["horsepower"].get<float>();
	worth = json["worth"].get<unsigned int>();
}

nlohmann::json Car::toJson()
{
	nlohmann::json json;
	json["horsepower"] = horsepower;
	json["worth"] = worth;
	return json;
}
