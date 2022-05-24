#pragma once
#include "animal.h"
void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone){
    Dog * ptr1 = static_cast<Dog *> (animal);
    Bird * ptr2 = static_cast<Bird *> (animal);
    if(ptr1 != nullptr) //is dog
        dogzone.push_back(std::move(*ptr1));
    else // is bird
        birdzone.push_back(std::move(*ptr2));
}