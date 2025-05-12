#include "Apartament.h"
#include "TaxRate.h"
using namespace TAX_RATES;

Apartament::Apartament(int worth, double square): Property(worth)
{
	this->square = square;
}

double Apartament::ñalculationTax()
{
	if (square <= LIMIT_Apartment_SQUARE) {
		return worth * Apartment_TAX;
	}
	else {
		return worth * Apartment_LUXURY_TAX;
	}
}

void Apartament::fromJson(nlohmann::json json)
{
	square = json["square"].get<double>();
	worth = json["worth"].get<unsigned int>();
}
