#pragma once
#include "Owner.h"
#include <fstream>
#include <iostream>
using namespace std;

class TaxService
{
	vector<Owner> owners;
	
	void fromJson(string const& filename);
public:
	TaxService(string const& input) {};
	~TaxService();

};

