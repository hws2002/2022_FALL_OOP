#include <iostream>
using namespace std;
class Base{ 
public: 
	virtual ~Base()=0; 
};
Base::~Base() {cout<<"Base destroyed"<<endl;}

class Derive1: public Base {};
class Derive2: public Base {
public: 
	virtual ~Derive2() {cout<<"Derive2 destroyed"<<endl;} };
int main()
{
Base* p1 = new Derive1;
Base* p2 = new Derive2;
delete p1;
cout << "------" << endl;
delete p2;
return 0;
}
