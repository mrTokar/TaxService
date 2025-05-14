#pragma once
#include "pugixml.hpp"

class Ixmlio
{
public:
	virtual void fromXml(pugi::xml_node node) = 0;
	virtual pugi::xml_node toXml(pugi::xml_node& root) = 0;
	virtual ~Ixmlio() {};
};

