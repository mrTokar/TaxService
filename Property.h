#pragma once
class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual double �alculationTax() = 0;
	double calculationIncomeTax();

	inline unsigned int getWorth() const { return worth; };
	inline void setWorth(unsigned int value) { worth = value; };
};

