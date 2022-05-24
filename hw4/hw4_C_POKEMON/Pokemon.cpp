#include "Pokemon.h"
Pokemon::Pokemon(){};

Pokemon::Pokemon(int hp, int atk, string name) : tot_hp(hp),hp(hp),atk(atk),name(name){
}  
void Pokemon::use_skill(int idx, Pokemon*target){};
void Pokemon::hurt(int dmg, Pokemon* from){};// 受到来自from的dmg点伤害时的反应

string Pokemon::get_name(){
    return name;
}

bool Pokemon::alive(){
    return hp>0;
}

int Pokemon::get_hp(){
    return hp;
}

int Pokemon::get_atk(){
    return atk;
}

Pokemon::~Pokemon(){

};

Squirtle::Squirtle(int hp, int atk,string name) : Pokemon(hp, atk, name){
};

void Squirtle::use_Regen(){
        int heal = ceil(tot_hp/5);
        hp += heal;
        if(hp>tot_hp) hp = tot_hp;
        std::cout<<get_name()<<" used Regen"<<std::endl;
};

void Squirtle::use_Splash(Pokemon* target){
        std::cout<<get_name()<<" used Splash to "<<target->get_name()<<std::endl;
        target->hurt(get_atk(),this);
};
void Squirtle::use_skill (int indx, Pokemon* target){
    if(indx ==0) use_Regen();
    else use_Splash(target);
}

void Squirtle::hurt(int dmg, Pokemon* from){
    int final_damage = 0;
    if(hp<=ceil(tot_hp/5)){
        if(ceil(dmg/5)>=1) final_damage = ceil(dmg/5);
        else final_damage = 1;
    } else final_damage = dmg;  
    hp -= final_damage;
    std::cout<<get_name()<<" received "<<final_damage<< " damage from "<<from->get_name()<<std::endl;
}



Charizard::Charizard(int hp, int atk, string name) : Pokemon(hp, atk, name){
        fire = 1;
};

void Charizard::use_Ignite(){
    std::cout<<get_name()<<" used Ignite"<<std::endl;
    fire+=1;
    atk*=2;
    std::cout<<get_name()<<" received "<<fire*10<<" damage from "<<get_name()<<std::endl;
    hp-=fire*10;
}
void Charizard::use_Flame(Pokemon * target){
    std::cout<<get_name()<<" used Flame to "<<target->get_name()<<std::endl;
    target->hurt(get_atk(),this);
}

void Charizard::use_skill(int indx, Pokemon * target){
    if(indx ==0) use_Ignite();
    else use_Flame(target);
}

void Charizard::hurt(int dmg, Pokemon* from){
    hp-=dmg;
    std::cout<<get_name()<<" received "<<dmg<<" damage from "<<from->get_name()<<std::endl;
    if(dmg>10){
        from->hurt(ceil(dmg/5),this);
    }
}
