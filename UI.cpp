#include "UI.h"
#include <iostream>
using namespace std;

void printOwner(Owner const& owner)
{
    cout << "Собственник: " << owner.getFullname() << ", ИНН: " << owner.getInn() << std::endl;
    for (const auto& property : owner.getProperties()) {
        cout << "\tОбъект: " << typeid(*property).name() << ", ценность: " << property->getWorth() << endl;
    }
    cout << endl;
}
