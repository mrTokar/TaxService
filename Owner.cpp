#include "Owner.h"
using namespace pugi;

Owner::Owner(string fullname, string inn, vector<Property*> const& properties):
	properties(properties)
{
	this->fullname = fullname;
	this->inn = inn;
}

nlohmann::json Owner::toJson()
{
	nlohmann::json json;
	json["fullname"] = fullname;
	json["inn"] = inn;
	json["sumtax"] = calculateTax();

	vector<nlohmann::json> jproperties;

	for (auto property : properties)
	{
		nlohmann::json jproperty;
		jproperty[typeid(*property).name()] = property->toJson();
		jproperties.push_back(jproperty);
	}

	json["properties"] = jproperties;
	return json;
}

void Owner::fromJson(nlohmann::json json)
{
	fullname = json["fullname"].get<string>();
	inn = json["inn"].get<string>();
	auto jpropertyes = json["properties"].get<vector<nlohmann::json>>();

	string key;
	Property* property;
	for (auto& jproperty : jpropertyes)
	{
		key = jproperty.items().begin().key();
		try {
			property = PropertySimpleFactory::getProperty(key);
			property->fromJson(jproperty[key]);
			properties.push_back(property);
		}
		catch (exception e) {
			throw e;
		}
	}
}

void Owner::fromXml(pugi::xml_node& node)
{
	try {
		fullname = node.attribute("fullname").as_string();
		inn = node.attribute("inn").as_string();
	}
	catch (...) {
		throw std::runtime_error("No required attribute in xml");
	}
		
	Property* property;
	string key;
	for (xml_node xml_property : node.children()) {
		try {
			key = xml_property.name();
			property = PropertySimpleFactory::getProperty(key);
			property->fromXml(xml_property);
			properties.push_back(property);
		}
		catch (exception e) {
			throw e;
		}
	}
}

void Owner::toXml(pugi::xml_node& root)
{
	xml_node owner = root.append_child("owner");

	xml_attribute fullname_attr = owner.append_attribute("fullname");
	fullname_attr.set_value(fullname.c_str());

	xml_attribute inn_attr = owner.append_attribute("inn");
	inn_attr.set_value(inn.c_str());

	xml_attribute sumtax_attr = owner.append_attribute("sumtax");
	sumtax_attr.set_value(calculateTax());

	for (auto property : properties)
	{
		property->toXml(owner);
	}
}

double Owner::calculateTax()
{
	double tax = 0;
	for (auto property : properties)
	{
		tax += property->ñalculationTax();
	}
	return tax;
}

double Owner::calculateIncomeTax()
{
	double tax = 0;
	for (auto property : properties)
	{
		tax += property->calculationIncomeTax();
	}
	return tax;
}

void Owner::addProperty(Property* property)
{
	properties.push_back(property);
}

void Owner::removeProperty(size_t index)
{
	delete properties[index];
	properties.erase(properties.begin() + index);
}
