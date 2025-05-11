#include "Property.h"

Property::Property(int wort)
{
	this->worth = worth;
}

int Property::incomeTax()
{
	return worth * 0.13;
}
