#pragma once
#include "Property.h"
#include <string>
#include <vector>
using namespace std;

class Owner
{
	string fullname;
	string inn;
	vector<Property*> properties;
};

