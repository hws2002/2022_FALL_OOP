#include <iostream>
using namespace std;

class Base{
public:
	int k = 0;
	void f(){cout << "Base::f()" << endl;}
	Base & operator= (const Base &right){
		if(this != &right){
			k = right.k;
			cout << "operator= (const Base &right)" << endl;
		}
		return *this;
	}
};
class Derive: public Base{};

int main(){
	Derive d, d2;
	cout << d.k << endl; //Base数据成员被继承
	d.f(); //Base::f()被继承
	
	Base e;
	//d = e; //编译错误，Base的赋值运算符不被继承
	d = d2;  //调用隐式定义的赋值运算符
	return 0;
}

