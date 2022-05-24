#include <iostream>
using namespace std;

class S1 { //Single1类别
  int ID;
public:
  S1(int id) : ID(id) { cout << "S1(int)" << endl; }
  ~S1() { cout << "~S1()" << endl; }
};

class S2 {//Single2类别
public:
  S2() { cout << "S2()" << endl; }
  ~S2() { cout << "~S2()" << endl; }
};
class C3 {//Composite3类别
  int num;
  S1 sub_obj1; /// 构造函数带参数
  S2 sub_obj2; /// 构造函数不带参数
public:
  C3() : num(0), sub_obj1(123) /// 构造函数初始化列表中构造子对象
		{ cout << "C3()" << endl; }
  C3(int n) : num(n), sub_obj1(123) 
		{ cout << "C3(int)" << endl; }
  C3(int n, int k) : num(n), sub_obj1(k) 
		{ cout << "C3(int, int)" << endl; }
  ~C3() { cout << "~C3()" << endl; }
};

int main()
{
  C3 a, b(1), c(2), d(3, 4);
  return 0;
}

