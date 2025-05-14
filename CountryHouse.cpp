#include "CountryHouse.h"
#include "TaxRate.h"
using namespace TAX_RATES;
using namespace pugi;

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

void CountryHouse::fromXml(xml_node& node)
{
	distanceFromCity = node.attribute("distance").as_uint();
	worth = node.attribute("worth").as_double();
	if (distanceFromCity == 0 || worth == 0) {
		throw std::runtime_error("No required attribute in xml");
	}
}

void CountryHouse::toXml(xml_node& root)
{
	xml_node apartament = root.append_child("CountryHouse");

	xml_attribute square_attr = apartament.append_attribute("distance");
	square_attr.set_value(distanceFromCity);

	xml_attribute worth_attr = apartament.append_attribute("worth");
	worth_attr.set_value(worth);

	apartament.text().set(ñalculationTax());
}