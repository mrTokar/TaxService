#pragma once
#include "xml-lib/pugixml.hpp"

class Ixmlio
{
public:
	virtual void fromXml(pugi::xml_node& node) = 0;
	virtual void toXml(pugi::xml_node& root) = 0;
	virtual ~Ixmlio() {};
};

