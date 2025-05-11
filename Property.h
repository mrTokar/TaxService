#pragma once
class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int worth);
	virtual int ñalculationTax() = 0;
	int calculatIonIncomeTax();
};

