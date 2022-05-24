#include <iostream>
using namespace std;

class Base {
public:
  void print() { cout << "Base::print()" << endl; }
};

class Derive : public Base {
public:
  void print() { cout << "Derive::print()" << endl; }
};

void fun(Base obj) { obj.print(); }

int main() 
{
  Derive d;
  d.print();	
  fun(d);		/// 本意：希望对Drive::print的调用
  return 0;
}

