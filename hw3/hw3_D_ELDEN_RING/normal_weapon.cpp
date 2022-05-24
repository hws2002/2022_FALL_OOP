#include "normal_weapon.h"

int NormalWeapon::index =0;

NormalWeapon::NormalWeapon(string name) : Weapon(name){
    grade = 0;
    index++;
}
NormalWeapon::~NormalWeapon(){
    if(get_level() ==0)
        std::cout<<"Normal weapon "<<get_name()<<" was destroyed."<<std::endl;
    else 
        std::cout<<"Normal weapon "<<get_name()<<"+"<<get_level()<<" was destroyed."<<std::endl;
}

bool NormalWeapon::find_name(string name){
    return get_name() == name;
}
int NormalWeapon::find_level(){
    return get_level();
}
void NormalWeapon::upgrade_normal_weapon(){
    upgrade();
    if(get_level()==1)
    std::cout<<"Normal weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<std::endl;
    else 
    std::cout<<"Normal weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<std::endl;
}
void NormalWeapon::c_upgrade_normal_weapon(int start){
    if(start == 0)
    std::cout<<"Upgrade "<<get_name()<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
    else
    std::cout<<"Upgrade "<<get_name()<<"+"<<start<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
}