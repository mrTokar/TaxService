#pragma once
class Property
{
protected:
	int worth;
public:
	Property(int worth);
	virtual int �alculationTax() = 0;
	int calculatIonIncomeTax();
};

