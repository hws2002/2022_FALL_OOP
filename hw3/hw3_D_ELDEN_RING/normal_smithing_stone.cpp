#include "normal_smithing_stone.h"
#include <iostream>
NormalSmithingStone::NormalSmithingStone(int level): SmithingStone(level){
};

NormalSmithingStone::~NormalSmithingStone(){
    std::cout<<"Normal smithing stone "<<get_level()<<" was destroyed."<<std::endl;
};

void NormalSmithingStone::add_stone(int amount){
    add_amount(amount);
};

bool NormalSmithingStone::enough_stone(int needed){
    // if(this==nullptr) return false;
    return greater_equal(needed);
}

void NormalSmithingStone::substract_stone(int needed){
    add_amount(-needed);
    std::cout<<"Normal smithing stone "<<get_level()<<" was substracted with "<<needed<<"."<<std::endl;
}

bool NormalSmithingStone::should_destroy(){
    return !greater_equal(1);
};
