#include "UI.h"
#include <iostream>
using namespace std;

void printOwner(Owner const& owner)
{
    cout << "—обственник: " << owner.getFullname() << ", »ЌЌ: " << owner.getInn() << std::endl;
    for (const auto& property : owner.getProperties()) {
        cout << "\tќбъект: " << typeid(*property).name() << ", ценность: " << property->getWorth() << endl;
    }
    cout << endl;
}

void addProperty(Owner const& owner)
{
    int usr;
    do {
        cout << "¬введите новое имущество:" << \
            "\t1) Car\n" << \
            "\t2) Apartament\n" << \
            "\t3) Country House\n" << \
            ">>>";
        cin >> usr;
    } while (usr < 1 || 3 < usr);
}

Property* createNewCar()
{
    unsigned int worth;
    cout << "¬ведите стоимость машины: ";
    cin >> worth;

    float horsepower;
    do {
        cout << "¬ведите мощность машины (в л.с.): ";
        cin >> horsepower;
    } while (horsepower <= 0);

    Property* car = new Car(worth, horsepower);
    return car;
}

Property* createNewApartament()
{
    unsigned int worth;
    cout << "¬ведите стоимость квартиры: ";
    cin >> worth;

    double square;
    do {
        cout << "¬ведите площадь квартиры (в м^2): ";
        cin >> square;
    } while (square <= 0);

    Property* apart = new Apartament(worth, square);
    return apart;
}

Property* createNewCountryHouse()
{
    unsigned int worth;
    cout << "¬ведите стоимость квартиры: ";
    cin >> worth;

    int distance;
    do {
        cout << "¬ведите площадь квартиры (в м^2): ";
        cin >> distance;
    } while (distance <= 0);

    Property* house = new CountryHouse(worth, distance);
    return house;
}
