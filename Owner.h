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
public:
	Owner(string fullname, string inn, vector<Property*> const& properties);

	void addProperty(Property* property);
	void removeProperty(size_t index);

	inline string getFullname() { return fullname; };
	inline string getInn() { return inn; };
	inline vector<Property*> getProperties() { return properties; };

	inline void setFullname(string value) { fullname = value; };
	inline void setInn(string value) { inn = value; };
};

