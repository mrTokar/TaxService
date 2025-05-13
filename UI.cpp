#include "UI.h"
#include <iostream>
using namespace std;

void printOwner(Owner const& owner)
{
    cout << "�����������: " << owner.getFullname() << ", ���: " << owner.getInn() << std::endl;
    int i = 1;
    for (const auto& property : owner.getProperties()) {
        cout << "\t" << i++ << ") ������: " << typeid(*property).name() << ", ��������: " << property->getWorth() << endl;
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
    cout << "������� ��� (��� ��������): ";
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

    return owner;
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
        cout << "������� ������\n";
        return;
    }

    int index;
    do {
        cout << "������� ����� ���������: ";
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
    cout << "������� ����� ��� (��� ��������): ";
    getline(cin, name);
    owner.setFullname(name);
}

void changeOwnerInn(Owner& owner)
{
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

    owner.setInn(inn);
}

void addProperty(Owner& owner)
{
    int usr;
    do {
        cout << "�������� ����� ���������:\n" << \
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
        cout << "������� ������" << endl;
    }

    int usr;
    do {
        cout << "������� ����� ���������: ";
        cin >> usr;
        usr--;
    } while (usr < 0 || size <= usr);

    owner.removeProperty(usr);
}

void calculateTax(Owner& owner)
{
    cout.precision(2);
    cout << fixed;
    cout << "����� �� ��������� ����������: " << owner.calculateTax();
    cout << endl;
    cout.unsetf(ios::fixed);
}

void caluclateIncomeTax(Owner& owner)
{
    cout.precision(2);
    cout << fixed;
    cout << "����� �� ��������� ����������: " << owner.calculateIncomeTax();
    cout << endl;
    cout.unsetf(ios::fixed);
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
