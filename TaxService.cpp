#include "TaxService.h"
using namespace extensions;
using namespace pugi;

void TaxService::fromJson(string const& filename)
{
	// read file 
	ifstream fin(filename);
	if (!fin.is_open()) {
		clog << "ERROR: File " << filename << " don't exist" << endl;
		throw runtime_error("File don't exist");
	}

	nlohmann::json json_file = nlohmann::json::parse(fin);
	fin.close();
	
	// parse json obj
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

void TaxService::toJson(string const& filename)
{	
	// create json object 
	vector<nlohmann::json> json_owners;
	for (auto& owner : owners)
	{
		json_owners.push_back(owner.toJson());
	}
	nlohmann::json root;
	root["owners"] = json_owners;

	// save to file
	ofstream fout(filename);
	if (!fout.is_open()) {
		clog << "ERROR: ñan't open file: " << filename << endl;
		throw exception("ñan't open file");
	}

	fout << root.dump(4);
	fout.close();
}

void TaxService::fromXml(string const& filename)
{
	// read file
	xml_document xmldoc;
	xml_parse_result result = xmldoc.load_file(filename.c_str());
	if (!result) {
		clog << "ERROR: File " << filename << " don't exist" << endl;
		throw runtime_error("File don't exist");
	}

	// parse file
	Owner owner("", "", {});
	try {
		for (xml_node xmlowner : xmldoc.child("owners").children("onwer")) {
			owner.fromXml(xmlowner);
			owners.push_back(owner);
		}
	}
	catch (exception e) {
		clog << "ERROR: " << e.what() << endl;
		throw e;
	}
}

void TaxService::toXml(string const& filename)
{
	xml_document doc;
	xml_node root = doc.append_child("owners");
	for (auto& owner : owners)
	{
		xml_node xmlowner = root.append_child("owner");
		owner.toXml(xmlowner);
	}
	doc.save_file(filename.c_str(), "\t", format_default);
}

const int TaxService::define_file(string const& filename)
{
	const regex jsonr(R"(.json$)");
	if (regex_search(filename, jsonr)) {
		return JSON;
	}
	else {
		return ANOTHER;
	}
}

TaxService::TaxService(string const& input)
{
	switch (define_file(input))
	{
	case JSON:
		fromJson(input);
		break;
	default:
		clog << "Invalid file extension" << endl;
		throw exception("Invalid file extension");
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

void TaxService::calculate_and_save(string const& output)
{
	switch (define_file(output))
	{
	case JSON:
		toJson(output);
		break;
	default:
		clog << "Invalid file extension" << endl;
		throw exception("Invalid file extension");
	}
}

