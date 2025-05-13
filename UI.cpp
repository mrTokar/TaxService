#include "UI.h"
#include <iostream>
#include <fstream>
using namespace std;

Owner readjson()
{
	string filename;
	cout << "Введите файл ввода: ";
	getline(cin, filename);

	ifstream fin(filename);
	if (!fin.is_open()) {
		clog << "ERROR: File " << filename << " don't exist" << endl;
		return Owner("", "", {});
	}

	nlohmann::json json_file = nlohmann::json::parse(fin);
	fin.close();

	Owner owner("", "", {});
	try {
		owner.fromJson(json_file);
	}
	catch (exception e) {
		clog << "ERROR: " << e.what() << endl;
		return Owner("", "", {});
	}
	return owner;
}

void writejson(nlohmann::json& json)
{
	string filename;
	cout << "Введите файл вывода: ";
	getline(cin, filename);

	ofstream fout(filename);
	if (!fout.is_open()) {
		clog << "ERROR: File " << filename << " don't exist" << endl;
		return;
	}

	fout << json.dump(4);
	fout.close();
}
