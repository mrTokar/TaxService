#include "UI.h"
#include <iostream>
#include <fstream>
using namespace std;

Owner readjson()
{
	string filename;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "¬ведите название файла ввода: ";
	getline(cin, filename);

	ifstream fin(filename);
	if (!fin.is_open()) {
		clog << "ERROR: File " << filename << " don't exist" << endl;
		cout << "ERROR: File " << filename << " don't exist" << endl;
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
		cout << "ERROR: " << e.what() << endl;
		return Owner("", "", {});
	}
	return owner;
}
