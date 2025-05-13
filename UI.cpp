#include "UI.h"
#include <iostream>
using namespace std;

void printOwner(Owner const& owner)
{
    cout << "Собственник: " << owner.getFullname() << ", ИНН: " << owner.getInn() << std::endl;
    int i = 1;
    for (const auto& property : owner.getProperties()) {
        cout << "\t" << i++ << ") Объект: " << typeid(*property).name() << ", ценность: " << property->getWorth() << endl;
    }
    cout << endl;
}

void printOwners(vector<Owner> const& owners)
{
    cout << "=====================" <<endl;
    int i = 1;
    for (const auto& owner : owners)
    {
        cout << i++ << ") ";
        printOwner(owner);
    }
    cout << "=====================" << endl;
}

Owner createNewOwner()
{
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите ФИО (без кирилицы): ";
    getline(cin, name);

    string inn;
    bool valid = true;
    do {
        valid = true;
        cout << "Введите ИНН (10 цифр): ";
        cin >> inn;
        
        if (inn.size() == 10) {
            for (auto& c : inn)
            {
                if (!isdigit(c)) {
                    valid = false;
                }
            }
        }
        else {
            valid = false;
        }

    } while (!valid);

    Owner owner(name, inn, {});

    int cnt;
    do {
        cout << "Введите количество имущества: ";
        cin >> cnt;
    } while (cnt <= 0);

    for (size_t i = 0; i < cnt; i++)
    {
        addProperty(owner);
    }

    return owner;
}

void editOwner(Owner& owner)
{
    int cmd;
    do {
        cout << "Введите номер команды:\n" << \
            "\t1) Изменить имя\n" << \
            "\t2) Изменить ИНН\n" << \
            "\t3) Добавить собственность\n" << \
            "\t4) Удалить существующую собственность\n" << \
            ">>>";
        cin >> cmd;
    } while (cmd < 1 || 4 < cmd);

    switch (cmd)
    {
    case 1:
        changeOwnerName(owner);
        break;
    case 2:
        changeOwnerInn(owner);
        break;
    case 3:
        addProperty(owner);
        break;
    case 4:
        deleteProperty(owner);
        break;
    default:
        break;
    }
}

void deleteOwner(vector<Owner>& owners)
{
    if (owners.size() == 0) {
        cout << "Удалять некого\n";
        return;
    }

    int index;
    do {
        cout << "Введите номер владельца: ";
        cin >> index;
        index--;
    } while (index < 0 || owners.size() <= index);
    
    size_t cnt = owners[index].getProperties().size();
    for (size_t i = 0; i < cnt; i++)
    {
        owners[index].removeProperty(0);
    }

    owners.erase(owners.begin() + index);
}

void changeOwnerName(Owner& owner)
{
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите новое имя (без кирилицы): ";
    getline(cin, name);
    owner.setFullname(name);
}

void changeOwnerInn(Owner& owner)
{
    string inn;
    bool valid = true;
    do {
        valid = true;
        cout << "Введите ИНН (10 цифр): ";
        cin >> inn;

        if (inn.size() == 10) {
            for (auto& c : inn)
            {
                if (!isdigit(c)) {
                    valid = false;
                }
            }
        }
        else {
            valid = false;
        }

    } while (!valid);

    owner.setInn(inn);
}

void addProperty(Owner& owner)
{
    int usr;
    do {
        cout << "Ввведите новое имущество:\n" << \
            "\t1) Car\n" << \
            "\t2) Apartament\n" << \
            "\t3) Country House\n" << \
            ">>>";
        cin >> usr;
    } while (usr < 1 || 3 < usr);

    Property* new_property = nullptr;
    switch (usr)
    {
    case 1:
        new_property = createNewCar();
        break;
    case 2:
        new_property = createNewApartament();
        break;
    case 3:
        new_property = createNewCountryHouse();
        break;
    default:
        break;
    }

    owner.addProperty(new_property);
}

void deleteProperty(Owner& owner)
{
    printOwner(owner);

    int size = owner.getProperties().size();
    if (size == 0) {
        cout << "Удалять нечего" << endl;
    }

    int usr;
    do {
        cout << "Введите номер имущества: ";
        cin >> usr;
        usr--;
    } while (usr < 0 || size <= usr);

    owner.removeProperty(usr);
}

void calculateTax(Owner& owner)
{
    cout.precision(2);
    cout << fixed;
    cout << "Налог на имущество составляет: " << owner.calculateTax();
    cout << endl;
    cout.unsetf(ios::fixed);
}

void caluclateIncomeTax(Owner& owner)
{
    cout.precision(2);
    cout << fixed;
    cout << "Налог на имущество составляет: " << owner.calculateIncomeTax();
    cout << endl;
    cout.unsetf(ios::fixed);
}

Property* createNewCar()
{
    int worth;
    do {
        cout << "Введите стоимость машины: ";
        cin >> worth;
    } while (worth <= 0);

    float horsepower;
    do {
        cout << "Введите мощность машины (в л.с.): ";
        cin >> horsepower;
    } while (horsepower <= 0);

    Property* car = new Car(worth, horsepower);
    return car;
}

Property* createNewApartament()
{
    int worth;
    do {
        cout << "Введите стоимость квартиры: ";
        cin >> worth;
    } while (worth <= 0);

    double square;
    do {
        cout << "Введите площадь квартиры (в м^2): ";
        cin >> square;
    } while (square <= 0);

    Property* apart = new Apartament(worth, square);
    return apart;
}

Property* createNewCountryHouse()
{
    int worth;
    do {
        cout << "Введите стоимость квартиры: ";
        cin >> worth;
    } while (worth <= 0);

    int distance;
    do {
        cout << "Введите площадь квартиры (в м^2): ";
        cin >> distance;
    } while (distance <= 0);

    Property* house = new CountryHouse(worth, distance);
    return house;
}
