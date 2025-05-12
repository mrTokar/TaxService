#include "Owner.h"

Owner::Owner(string fullname, string inn, vector<Property*> const& properties):
	properties(properties)
{
	this->fullname = fullname;
	this->inn = inn;
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

void Owner::addProperty(Property* property)
{
	properties.push_back(property);
}

void Owner::removeProperty(size_t index)
{
	delete properties[index];
	properties.erase(properties.begin() + index);
}
