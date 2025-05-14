#include "Car.h"
#include "TaxRate.h"
using namespace TAX_RATES;
using namespace pugi;

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
	try {
		horsepower = json["horsepower"].get<float>();
		worth = json["worth"].get<unsigned int>();
	}
	catch (...) {
		throw std::runtime_error("No required keys in json");
	}
}

void Car::fromXml(pugi::xml_node& node)
{
	try {
		horsepower = node.attribute("horsepower").as_float();
		worth = node.attribute("worth").as_double();
	}
	catch (...) {
		throw std::runtime_error("No required attribute in xml");
	}
}

void Car::toXml(xml_node& root)
{
	xml_node apartament = root.append_child("Car");

	xml_attribute square_attr = apartament.append_attribute("horsepower");
	square_attr.set_value(horsepower);

	xml_attribute worth_attr = apartament.append_attribute("worth");
	worth_attr.set_value(worth);

	apartament.text().set(ñalculationTax());
}