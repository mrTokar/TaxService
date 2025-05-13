#include "TaxService.h"

TaxService::~TaxService()
{
	for (auto& owner : owners)
	{
		for (auto property : owner.getProperties())
		{
			delete property;
		}
	}
}
