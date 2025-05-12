#include <iostream>
#include <Windows.h>
#include "Owner.h"
#include "Apartament.h"
#include "Car.h"
#include "CountryHouse.h"
#include "UI.h"
using namespace std;

vector<Owner> generateOwners();
void freememory(vector<Owner>& owners);
    Owner& chooseOwner(vector<Owner>& owners);
    bool show_menu(vector<Owner>& array);

int main() {
    setlocale(LC_ALL, "ru");
	auto owners = generateOwners();
    
    bool exit;
    do {
        exit = show_menu(owners);
    } while (!exit);

	freememory(owners);
    return 0;
}

vector<Owner> generateOwners()
{
    // Создание объектов собственности для первого собственника
    Property* apart1 = new Apartament(5000000, 100);
    Property* car1 = new Car(1500000, 200);
    Property* house1 = new CountryHouse(3000000, 50);
    Property* apart2 = new Apartament(4500000, 80);

    // Создание объектов собственности для второго собственника
    Property* car2 = new Car(1200000, 180);
    Property* house2 = new CountryHouse(2500000, 70);
    Property* apart3 = new Apartament(6000000, 120);
    Property* car3 = new Car(2000000, 220);

    // Создание объектов собственности для третьего собственника
    Property* house3 = new CountryHouse(4000000, 90);
    Property* apart4 = new Apartament(5500000, 110);
    Property* car4 = new Car(1800000, 190);
    Property* house4 = new CountryHouse(3500000, 60);

    // Создание собственников
    Owner owner1("Иван Иванов", "1234567890", { apart1, car1, house1, apart2 });
    Owner owner2("Петр Петров", "0987654321", { car2, house2, apart3, car3 });
    Owner owner3("Сергей Сергеев", "1122334455", { house3, apart4, car4, house4 });

    vector<Owner> owners = { owner1, owner2, owner3 };
	return owners;
}

void freememory(vector<Owner>& owners)
{
	for (auto& owner : owners) {
		for (auto property : owner.getProperties()) {
			delete property;
		}
	}
	owners.clear();
}

Owner& chooseOwner(vector<Owner>& owners)
{
    int index;
    do {
        cout << "Введите номер владельца: ";
        cin >> index;
        index--;
    } while (index < 0 || owners.size() <= index);

    return owners[index];
}

bool show_menu(vector<Owner>& array)
{
    printOwners(array);
    int cmd;
    do {
        cout << "Введите номер команды:\n" << \
            "\t0) Выход\n" << \
            "\t1) Добавить нового владельца\n" << \
            "\t2) Удалить существующего владельца\n" << \
            "\t3) Редактировать существующего владельца\n" << \
            ">>>";
        cin >> cmd;
    } while (cmd < 0 || 3 < cmd);

    switch (cmd)
    {
    case 0:
        return true;
    case 1:
        array.push_back(createNewOwner());
        break;
    case 2:
        deleteOwner(array);
        break;
    case 3:
        editOwner(chooseOwner(array));
        break;
    default:
        break;
    }
    return false;
}
