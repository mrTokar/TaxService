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
