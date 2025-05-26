#pragma once
#include "../Property/Property.h"
#include "../Property/PropertyFactory.h"
#include <string>
#include <vector>
using namespace std;

class Owner:
	virtual public Ijsonio,
	virtual public Ixmlio
{
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(string fullname, string inn, vector<Property*> const& properties);

	nlohmann::json toJson() override;
	void fromJson(nlohmann::json) override;

	void fromXml(pugi::xml_node& node) override;
	void toXml(pugi::xml_node& root) override;

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

