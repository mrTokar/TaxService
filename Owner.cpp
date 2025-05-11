#include "Owner.h"

Owner::Owner(string fullname, string inn, vector<Property*> const& properties):
	properties(properties)
{
	this->fullname = fullname;
	this->inn = inn;
}

void Owner::addProperty(Property* property)
{
	properties.push_back(property);
}
