#pragma once
#include "Property.h"
#include <string>
#include <vector>
using namespace std;

class Owner:
	public Ijsonio
{
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(string fullname, string inn, vector<Property*> const& properties);

	double calculateTax();
	double calculateIncomeTax();

	void addProperty(Property* property);
	void removeProperty(size_t index);

	inline string getFullname() const { return fullname; };
	inline string getInn() const { return inn; };
	inline vector<Property*> getProperties() const { return properties; };

	inline void setFullname(string value) { fullname = value; };
	inline void setInn(string value) { inn = value; };
};

