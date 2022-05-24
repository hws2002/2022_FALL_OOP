#include <iostream>
using namespace std;

class Base
{
    int data;
public:
    Base(int i) : data(i) { cout << "Base::Base(" << i << ")\n"; }
};
class Derive : public Base {
public:
    using Base::Base; 		///相当于 Derive(int i):Base(i){};
};
int main() {
    Derive obj(356);

    return 0;
} // g++ 1.cpp –o 1.out -std=c++11

