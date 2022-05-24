#include "weapon.h"
#include <iostream>
using namespace std;
int Weapon::magic = 0;

Weapon::~Weapon()
{
    print_magic();
    cout << "Weapon destroyed: " << name << endl;
}


Weapon::Weapon(string name) : name(name), level(0)
{
    print_magic();
    cout << "Weapon created: " << name << endl;
}

void Weapon::upgrade()
{
    print_magic();
    cout << "Weapon upgraded: " << name << endl;
    level++;
}

string Weapon::get_name() const
{
    return name;
}

int Weapon::get_level() const
{
    return level;
}

void Weapon::set_magic(int _magic)
{
    magic = _magic;
}
void Weapon::print_magic()
{
    cout << "[magic=" << magic << "] ";
}
