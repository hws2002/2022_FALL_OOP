#include <iostream>
using namespace std;
class Base { 
public: 
	virtual void func()=0; 
};
class Derive1: public Base {}; //Derive1仍为抽象类
class Derive2: public Base {
public: 
	void func() {
		cout << "Derive2::func" << endl;
} 
};

int main()
{
	// Derive1 d1; //编译错误，Derive1仍为抽象类
	Derive2 d2;
	d2.func();
    return 0;
}
