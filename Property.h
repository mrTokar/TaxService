#pragma once
class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual double �alculationTax() = 0;
	double calculatIonIncomeTax();
};

