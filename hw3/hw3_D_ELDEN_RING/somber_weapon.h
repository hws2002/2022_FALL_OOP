#pragma once
#include "weapon.h"
class SomberWeapon : public Weapon{
    public :
    static int index;
    int grade;
    SomberWeapon(string name);
    // SomberWeapon & operator = (NormalWeapon && other);
    ~SomberWeapon();
    bool find_name(string name);
    int find_level();
    void upgrade_somber_weapon();
    void c_upgrade_somber_weapon(int start);
};