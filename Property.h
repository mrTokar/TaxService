#pragma once
class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual int �alculationTax() = 0;
	int calculatIonIncomeTax();
};

