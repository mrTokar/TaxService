#include <iostream>
#include <Windows.h>
#include "Owner.h"
#include "Apartament.h"
#include "Car.h"
#include "CountryHouse.h"
#include "UI.h"
using namespace std;

int main() {

	auto owner = readjson();

	if (owner.getFullname() == "") {
		return 0;
	}

	nlohmann::json json= owner.toJson();
	writejson(json);

	return 0;
}