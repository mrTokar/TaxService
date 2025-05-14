#include "Apartament.h"
#include "TaxRate.h"
using namespace TAX_RATES;
using namespace pugi;

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
	try {
		square = json["square"].get<double>();
		worth = json["worth"].get<unsigned int>();
	}
	catch (...) {
		throw std::runtime_error("No required keys in json");
	}
}

void Apartament::fromXml(xml_node& node)
{
	try {
		square = node.attribute("square").as_double();
		worth = node.attribute("worth").as_double();
	}
	catch (...) {
		throw std::runtime_error("No required attribute in xml");
	}
}

void Apartament::toXml(xml_node& root)
{
	xml_node apartament = root.append_child("Apartament");
	
	xml_attribute square_attr = apartament.append_attribute("square");
	square_attr.set_value(square);

	xml_attribute worth_attr = apartament.append_attribute("worth");
	worth_attr.set_value(worth);

	apartament.text().set(ñalculationTax());
}
