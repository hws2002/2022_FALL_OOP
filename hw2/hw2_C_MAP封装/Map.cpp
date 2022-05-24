#include <iostream>
#include "Map.h"
using namespace std;

Map::Map(int n): sz(0) {
    //数据成员sz表明Map对象实际包含的键值对数量（必有0≤sz≤n)。
    data = new Pair[n];
    //在构造函数内开辟一个大小为n个Pair对象的数组，并让数据成员data指向该数组的首位。   
}
int& Map::operator[] (string key){
    for(int i=0;i<sz;i++){
        if (data[i].hasKey(key)){
            return data[i].getVal();
        }
    }
    data[sz].reset(key,0);
    return data[sz++].getVal();
}

int Map::operator[] (string key) const{
    for(int i=0;i<sz;i++){
        if(data[i].hasKey(key)){
            return data[i].getVal();//data[i].getVal()返回值是int&
        }
    }
    return 0;
}

int Map::size(){
    return sz;
}

Map:: ~Map(){
    if(data) delete[] data;
}
