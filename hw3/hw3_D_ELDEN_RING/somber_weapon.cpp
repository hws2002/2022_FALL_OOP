#include "somber_weapon.h"
#include <iostream>
int SomberWeapon::index =0;

SomberWeapon::SomberWeapon(string name):Weapon(name){
    index++;
}

SomberWeapon::~SomberWeapon(){
    if(get_level()==0)
    std::cout<<"Somber weapon "<<get_name()<<" was destroyed."<<std::endl;
    else 
    std::cout<<"Somber weapon "<<get_name()<<"+"<<get_level()<<" was destroyed."<<std::endl;

}
bool SomberWeapon::find_name(string name){
    return get_name()==name;
}
int SomberWeapon::find_level(){
    return get_level();
}

void SomberWeapon::upgrade_somber_weapon(){
    upgrade();
    if(get_level() == 1)
    std::cout<<"Somber weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<std::endl; 
    else 
    std::cout<<"Somber weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<std::endl; 
}

void SomberWeapon::c_upgrade_somber_weapon(int start){
    if(start == 0)
    std::cout<<"Upgrade "<<get_name()<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
    else
    std::cout<<"Upgrade "<<get_name()<<"+"<<start<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
}
