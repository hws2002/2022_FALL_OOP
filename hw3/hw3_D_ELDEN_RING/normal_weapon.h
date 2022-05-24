#pragma once
#include "weapon.h"
#include <iostream>
class NormalWeapon : public Weapon{
    public : 
    static int index;
    int grade;
    NormalWeapon(string name);
    // NormalWeapon(NormalWeapon&& other);
    // NormalWeapon & operator=(NormalWeapon && other );
    bool find_name(string name);
    int find_level();
    void upgrade_normal_weapon();
    void c_upgrade_normal_weapon(int start);
    ~NormalWeapon();
};