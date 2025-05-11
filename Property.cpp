#include "Property.h"

Property::Property(unsigned int worth)
{
	this->worth = worth;
}

int Property::calculatIonIncomeTax()
{
	return worth * 0.13;
}
