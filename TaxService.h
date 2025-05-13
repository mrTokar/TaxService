#pragma once
#include "Owner.h"
#include <fstream>
#include <iostream>
#include <regex>
using namespace std;

const int JSON = 1;
const int ANOTHER = 0;

class TaxService
{
	vector<Owner> owners;
	
	void fromJson(string const& filename);
	void toJson(string const& filename);

	const int define_file(string const& filename);
public:
	TaxService(string const& input) {};
	~TaxService();

};

