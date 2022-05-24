#include "tarnished.h"
#include <iostream>

Tarnished::Tarnished(){};
Tarnished::~Tarnished(){
    for(int i=1;i<MAX_STONES;i++){
        if(normal_smithing_stones[i]) {delete normal_smithing_stones[i]; normal_smithing_stones[i] = nullptr;}
    }
    for(int i=1;i<MAX_STONES;i++){   
        if(somber_smithing_stones[i]) {delete somber_smithing_stones[i]; somber_smithing_stones[i] = nullptr;}
    }
    for(int i=1;i<=NormalWeapon::index;i++){
        delete normal_weapons[i];
        normal_weapons[i] = nullptr;
    };
    for(int i =1;i<=SomberWeapon::index;i++){
        delete somber_weapons[i];
        somber_weapons[i] = nullptr;
    }
};

void Tarnished::pick_up_stone(int type, int level, int number){
    if(type == 0){
        if(normal_smithing_stones[level] == nullptr){//created 멘트 날려야됨
            normal_smithing_stones[level] = new NormalSmithingStone(level);
            std::cout<<"Normal smithing stone "<<level<<" was created."<<std::endl;
        }
        normal_smithing_stones[level]->add_stone(number);
        std::cout<<"Normal smithing stone "<<level<<" was added with "<<number<<"."<<std::endl;
    } else {//type ==1
        if(somber_smithing_stones[level]==nullptr){
            somber_smithing_stones[level] = new SomberSmithingStone(level);
            std::cout<<"Somber smithing stone "<<level<<" was created."<<std::endl;
        }
        somber_smithing_stones[level]->add_stone(number);
        std::cout<<"Somber smithing stone "<<level<<" was added with "<<number<<"."<<std::endl;
    }
};

void Tarnished::pick_up_weapon(int type, string name){
    if (type ==0){
        normal_weapons[NormalWeapon::index] = new NormalWeapon(name);
        std::cout<<"Normal weapon "<<name<<" was created."<<std::endl;
    } else {
        somber_weapons[SomberWeapon::index] = new SomberWeapon(name);
        std::cout<<"Somber weapon "<<name<<" was created."<<std::endl;
    }
};

void Tarnished::upgrade_weapon(int target, string name){
    int index  = 0;
    for(int i=1;i<=SomberWeapon::index;i++){
        if(somber_weapons[i] == nullptr) continue;
        if(somber_weapons[i]->find_name(name)){
            index = i;
            break;
        }
    }
    if(index!=0){
        int grade = somber_weapons[index]->find_level();
        if(target<=grade) {
            std::cout<<"Stay calm!"<<std::endl; 
            return;
        }
        bool will_upgrade = false;
        for(int i=grade+1;i<=target;i++){
            if(somber_smithing_stones[i]==nullptr){
                std::cout<<"Upgrade failed for lacking somber smithing stone "<<i<<"."<<std::endl;
                return;
            }
            if(i==target) will_upgrade = true;
        }
        if(will_upgrade){
            for(int i=grade+1;i<=target;i++){
                somber_smithing_stones[i]->substract_stone();
                if(somber_smithing_stones[i]->should_destroy()) {
                    delete somber_smithing_stones[i];
                    somber_smithing_stones[i] = nullptr;
                }
                somber_weapons[index]->upgrade_somber_weapon();
            }
            somber_weapons[index]->c_upgrade_somber_weapon(grade);
            return;
        }
    } else {//somber_weapons 에 없을떄(index == 0)
        for(int i=1;i<=NormalWeapon::index;i++){
            if(normal_weapons[i] == nullptr) continue;
            if(normal_weapons[i]->find_name(name)){
                index = i;
                break;
            }
        }
        if(index!=0){
            int grade = normal_weapons[index]->find_level();
            if(target<=grade){
                std::cout<<"Stay calm!"<<std::endl;
                return;
            }
            bool will_upgrade = false;
            int size = target - grade;
            int *upgrade_step = new int[size];
            int count = 0;
            for(int i=grade+1;i<=target;i++){
                int stage = (i-1)/3 + 1;
                int needed = 0;
                int total_needed = 0;
                while((i-1)/3+1 == stage && i<=target){
                    if(i%3 == 1) needed =2;
                    else if (i%3 == 2) needed =4;
                    else needed = 6;
                    upgrade_step[count++] = needed;
                    total_needed+=needed;
                    i++;
                }
                i--;
                if(normal_smithing_stones[stage]==nullptr||!normal_smithing_stones[stage]->enough_stone(total_needed)){
                    std::cout<<"Upgrade failed for lacking normal smithing stone "<<stage<<"."<<std::endl;
                    delete [] upgrade_step;
                    return;
                }
                if(i==target) will_upgrade = true;
            }
            if(will_upgrade){
                for(int i=0;i<size;i++){
                    int k = (grade+i)/3+1;
                    normal_smithing_stones[k]->substract_stone(upgrade_step[i]);
                    if(normal_smithing_stones[k]->should_destroy()){
                        delete normal_smithing_stones[k];
                        normal_smithing_stones[k] = nullptr;
                    }
                    normal_weapons[index]->upgrade_normal_weapon();
                }
                normal_weapons[index]->c_upgrade_normal_weapon(grade);
                delete [] upgrade_step;
                return;
            }
        } else {//무기 존재안함
            std::cout<<"You don't have the right!"<<std::endl;
            return;
        }
    }
};
