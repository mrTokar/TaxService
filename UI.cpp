#include "UI.h"
#include <iostream>
using namespace std;

void printOwner(Owner const& owner)
{
    cout << "�����������: " << owner.getFullname() << ", ���: " << owner.getInn() << std::endl;
    for (const auto& property : owner.getProperties()) {
        cout << "\t������: " << typeid(*property).name() << ", ��������: " << property->getWorth() << endl;
    }
    cout << endl;
}

void printOwners(vector<Owner> const& owners)
{
    cout << "=====================" <<endl;
    for (const auto& owner : owners)
    {
        printOwner(owner);
    }
    cout << "=====================" << endl;
}

Owner& chooseOwner(vector<Owner>& owners)
{
    int index;
    do {
        cout << "������� ����� ���������: ";
        cin >> index;
        index--;
    } while (index < 0 || owners.size() <= index);

    return owners[index];
}

Owner createNewOwner()
{
    string name;
    cout << "������� ���: ";
    getline(cin, name);

    string inn;
    bool valid = true;
    do {
        valid = true;
        cout << "������� ��� (10 ����): ";
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
        cout << "������� ���������� ���������: ";
        cin >> cnt;
    } while (cnt <= 0);

    for (size_t i = 0; i < cnt; i++)
    {
        addProperty(owner);
    }
}

void editOwner(Owner& owner)
{
    int cmd;
    do {
        cout << "������� ����� �������:\n" << \
            "\t1) �������� ���\n" << \
            "\t2) �������� ���\n" << \
            "\t3) �������� �������������\n" << \
            "\t4) ������� ������������ �������������\n" << \
            ">>>";
        cin >> cmd;
    } while (cmd < 1 || 4 < cmd);

    switch (cmd)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

void deleteOwner(vector<Owner>& owners)
{
    int index;
    do {
        cout << "������� ����� ���������: ";
        cin >> index;
        index--;
    } while (index < 0 || owners.size() <= index);

    owners.erase(owners.begin() + index);
}

void changeOwnerName(Owner& owner)
{
    string name;
    cout << "������� ����� ���: ";
    getline(cin, name);
    owner.setFullname(name);
}

void addProperty(Owner& owner)
{
    int usr;
    do {
        cout << "�������� ����� ���������:" << \
            "\t1) Car\n" << \
            "\t2) Apartament\n" << \
            "\t3) Country House\n" << \
            ">>>";
        cin >> usr;
    } while (usr < 1 || 3 < usr);

    Property* new_property;
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
    int usr;
    do {
        cout << "������� ����� ���������: ";
        cin >> usr;
        usr--;
    } while (usr < 0 || size <= usr);

    owner.removeProperty(usr);
}

Property* createNewCar()
{
    int worth;
    do {
        cout << "������� ��������� ������: ";
        cin >> worth;
    } while (worth <= 0);

    float horsepower;
    do {
        cout << "������� �������� ������ (� �.�.): ";
        cin >> horsepower;
    } while (horsepower <= 0);

    Property* car = new Car(worth, horsepower);
    return car;
}

Property* createNewApartament()
{
    int worth;
    do {
        cout << "������� ��������� ��������: ";
        cin >> worth;
    } while (worth <= 0);

    double square;
    do {
        cout << "������� ������� �������� (� �^2): ";
        cin >> square;
    } while (square <= 0);

    Property* apart = new Apartament(worth, square);
    return apart;
}

Property* createNewCountryHouse()
{
    int worth;
    do {
        cout << "������� ��������� ��������: ";
        cin >> worth;
    } while (worth <= 0);

    int distance;
    do {
        cout << "������� ������� �������� (� �^2): ";
        cin >> distance;
    } while (distance <= 0);

    Property* house = new CountryHouse(worth, distance);
    return house;
}
