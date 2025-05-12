#include "Property.h"

Property::Property(unsigned int worth)
{
	this->worth = worth;
}

double Property::calculationIncomeTax()
{
	return worth * 0.13;
}

nlohmann::json Property::toJson()
{
	nlohmann::json json;
	json["tax"] = ñalculationTax();
	return json;
}
