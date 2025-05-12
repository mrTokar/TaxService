#include "Owner.h"

Owner::Owner(string fullname, string inn, vector<Property*> const& properties):
	properties(properties)
{
	this->fullname = fullname;
	this->inn = inn;
}

nlohmann::json Owner::toJson()
{
	nlohmann::json json;
	json["fullname"] = fullname;
	json["inn"] = inn;
	json["sumtax"] = calculateTax();

	vector<nlohmann::json> jproperties;

	for (auto property : properties)
	{
		nlohmann::json jproperty;
		jproperty[typeid(*property).name()] = property->toJson();
		jproperties.push_back(jproperty);
	}

	json["properties"] = jproperties;
	return json;
}

double Owner::calculateTax()
{
	double tax = 0;
	for (auto property : properties)
	{
		tax += property->ñalculationTax();
	}
	return tax;
}

double Owner::calculateIncomeTax()
{
	double tax = 0;
	for (auto property : properties)
	{
		tax += property->calculationIncomeTax();
	}
	return tax;
}

void Owner::addProperty(Property* property)
{
	properties.push_back(property);
}

void Owner::removeProperty(size_t index)
{
	delete properties[index];
	properties.erase(properties.begin() + index);
}
