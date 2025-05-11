#pragma once
class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual double ñalculationTax() = 0;
	double calculationIncomeTax();

	inline unsigned int getWorth() { return worth; };
	inline void setWorth(unsigned int value) { worth = value; };
};

