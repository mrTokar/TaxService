#pragma once
#include "Owner.h"
#include "Car.h"
#include "Apartament.h"
#include "CountryHouse.h"

#ifndef UI
#define UI

Owner readjson();
void writejson(nlohmann::json& json);

#endif // !UI
