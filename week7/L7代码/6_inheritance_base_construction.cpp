#include <iostream>
using namespace std;
class Base 
{
    int data;
public:
    Base() : data(0) { cout << "Base::Base(" << data << ")\n"; }
			/// 默认构造函数
    Base(int i) : data(i) { cout << "Base::Base(" << data << ")\n"; }
};
class Derive : public Base {
public:
    Derive(int i) : Base(i) { cout << "Derive::Derive()" << endl; } 
    /// 显式调用基类构造函数
};
int main() {
    Derive obj(356);	
	return 0;
} // g++ 1.cpp –o 1.out -std=c++11

