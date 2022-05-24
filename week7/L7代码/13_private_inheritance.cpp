#include <iostream>
using namespace std;

class Base{
private:
	int data{0};
public:
	int getData(){return data;}
	void setData(int i){data = i;}
};
class Derive1: private Base {
public:
	using Base::getData;
};

int main(){
	Derive1 d1;
	cout << d1.getData();
	//d1.setData(10);
	//Base& b = d1;
	//b.setData(10);
	return 0;
}
