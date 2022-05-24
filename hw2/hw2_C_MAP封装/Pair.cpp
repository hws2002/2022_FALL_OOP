#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;


Pair::Pair():val(0){
}

void Pair::reset(string k, int v){
    key = k;
    val = v;
}

bool Pair::hasKey(string k){
    return key == k;
}

int & Pair::getVal(){
    return val;
}

Pair::~Pair(){
}
