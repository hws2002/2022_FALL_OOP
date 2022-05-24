#include "somber_smithing_stone.h"
#include <iostream>

SomberSmithingStone::SomberSmithingStone(int level): SmithingStone(level){
};

SomberSmithingStone::~SomberSmithingStone(){
    std::cout<<"Somber smithing stone "<<get_level()<<" was destroyed."<<std::endl;
};

void SomberSmithingStone::substract_stone(){
    add_amount(-1);
    std::cout<<"Somber smithing stone "<<get_level()<<" was substracted with 1."<<std::endl;
}

void SomberSmithingStone::add_stone(int amount){
    add_amount(amount);
};

bool SomberSmithingStone::should_destroy(){
    return !greater_equal(1);
};