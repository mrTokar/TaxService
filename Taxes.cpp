#include <iostream>
#include <Windows.h>
#include "Owner.h"
#include "Apartament.h"
#include "Car.h"
#include "CountryHouse.h"
#include "UI.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	auto owner = readjson();

	if (owner.getFullname() == "") {
		return 0;
	}

	nlohmann::json json= owner.toJson();
	writejson(json);

	// clear mem
	for (auto prop : owner.getProperties())
	{
		delete prop;
	}

	return 0;
}