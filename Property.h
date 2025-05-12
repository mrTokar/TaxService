#pragma once
#include "Ijsonio.h"

class Property:
	public Ijsonio
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual double ñalculationTax() = 0;
	double calculationIncomeTax();

	nlohmann::json toJson() override;

	inline unsigned int getWorth() const { return worth; };
	inline void setWorth(unsigned int value) { worth = value; };
};

