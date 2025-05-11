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
