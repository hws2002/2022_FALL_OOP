#include <iostream>

class Test{
public:
    Test& operator++ (){
        std::cout<<"prefix.";
        return *this;
    }
    Test& operator++ (int){
        std::cout<<"suffix.";
        return *this;
    }
};

int main(){
    Test t;
    ++t;
    t++;
}