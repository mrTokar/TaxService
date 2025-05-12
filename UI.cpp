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

void addProperty(Owner const& owner)
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
}
