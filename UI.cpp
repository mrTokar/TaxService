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

void addProperty(Owner const& owner)
{
    int usr;
    do {
        cout << "Ввведите новое имущество:" << \
            "\t1) Car\n" << \
            "\t2) Apartament\n" << \
            "\t3) Country House\n" << \
            ">>>";
        cin >> usr;
    } while (usr < 1 || 3 < usr);
}
