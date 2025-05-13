#include "Property.h"

Property::Property(unsigned int worth)
{
	this->worth = worth;
}

double Property::calculationIncomeTax()
{
	return worth * 0.13;
}
