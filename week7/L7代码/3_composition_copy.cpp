#include <iostream>
using namespace std;

class C1{
public:
	int i;
	C1(int n):i(n){}
	C1(const C1 &other) /// 显式定义拷贝构造函数
		{i=other.i; cout << "C1(const C1 &other)" << endl;}
};

class C2{
public:
	int j;
	C2(int n):j(n){}
	C2& operator= (const C2& right){/// 显式定义赋值运算符
		if(this != &right){
			j = right.j;
			cout << "operator=(const C2&)" << endl;
		}
		return *this;
	}
};
class C3{
public:
	C1 c1;
	C2 c2;
	C3():c1(0), c2(0){}
	C3(int i, int j):c1(i), c2(j){}
	void print(){cout << "c1.i = " << c1.i << " c2.j = " << c2.j << endl;}
};
int main(){
	C3 a(1, 2);
	C3 b(a);  //C1执行显式定义的拷贝构造，                               C2执行隐式定义的拷贝构造
	cout << "b: ";
	b.print();
	cout << endl;

	C3 c;
	cout << "c: ";
	c.print();
	c = a;  //C1执行隐式定义的拷贝赋值，                          C2执行显式定义的拷贝赋值
	cout << "c: ";
	c.print();
	return 0;
}

