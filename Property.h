#pragma once
class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual double ñalculationTax() = 0;
	double calculatIonIncomeTax();
};

