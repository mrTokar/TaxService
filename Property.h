#pragma once
class Property
{
protected:
	int worth;
public:
	Property(int worth);
	virtual int ñalculationTax() = 0;
	int calculatIonIncomeTax();
};

