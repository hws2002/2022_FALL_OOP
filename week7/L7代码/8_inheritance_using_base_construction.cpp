#include <iostream>
using namespace std;

class Base
{
    int data;
public:
    Base(int i) : data(i) { cout << "Base::Base(" << i << ")\n"; }
	Base(int i, int j)
		{ cout << "Base::Base(" << i << "," << j << ")\n";}
};
class Derive : public Base {
public:
    using Base::Base; 		///相当于 Derive(int i):Base(i){};
                     ///加上 Derive(int i, int j):Base(i，j){};
};
int main() {
    Derive obj1(356);
	Derive obj2(356, 789);
    return 0;
} // g++ 1.cpp –o 1.out -std=c++11

