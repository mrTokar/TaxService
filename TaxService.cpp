#include "TaxService.h"

void TaxService::fromJson(string const& filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		clog << "ERROR: File " << filename << " don't exist" << endl;
		throw runtime_error("File don't exist");
	}

	nlohmann::json json_file = nlohmann::json::parse(fin);
	fin.close();
	
	if (json_file.contains("owners")) 
	{
		auto json_owners = json_file["owners"].get<vector<nlohmann::json>>();

		Owner owner("", "", {});
		for (auto& json_owner : json_owners)
		{
			try {
				owner.fromJson(json_owner);
				owners.push_back(owner);
			}
			catch (exception e) {
				clog << "ERROR: " << e.what() << endl;
				throw e;
			}
		}
	}
	else {
		clog << "No key: 'owners'" << endl;
		throw exception("No key: 'owners'");
	}
}

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

