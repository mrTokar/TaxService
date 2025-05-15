#pragma once
#include "Owner/Owner.h"
#include <fstream>
#include <iostream>
#include <regex>
using namespace std;

namespace extensions
{
	const int JSON = 1;
	const int XML = 2;
	const int ANOTHER = 0;
}

class TaxService
{
	vector<Owner> owners;
	
	void fromJson(string const& filename);
	void toJson(string const& filename);

	void fromXml(string const& filename);
	void toXml(string const& filename);

	const int define_file(string const& filename);
public:
	TaxService(string const& input);
	~TaxService();

	void calculate_and_save(string const& output);
};

