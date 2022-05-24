## **友元函数**
被声明为友元的函数或类，具有对出现友元声明的类的private及protected成员的访问权限，即可以访问该类的一切成员。

友元的声明只能在类内进行。

```C
class A {
    int data;//默认私有成员 
    friend void foo(A &a);
};
void foo(A &a) {
    cout << a.data << endl;
}

```
有时需要允许某些函数访问对象的私有成员，可以通过声明该函数为类的“友元”来实现
```C
#include <iostream>
using namespace std;

class Test {
	int id;
public:
	Test(int i) : id(i) { cout << "obj_" << id << " created\n"; } 
	
	friend istream& operator>> (istream& in, Test& dst); 
	friend ostream& operator<< (ostream& out, const Test& src); 
};
istream& operator>> (istream& in, Test& dst) {
	in >> dst.id;
	return in;
}
ostream& operator<< (ostream& out, const Test& src) {
	out << src.id;
	return out;
} 	// 以上类中声明了Test类的两个友元函数 —— 全局流运算符重载函数，
	// 使这两个函数在实现时可以访问对象的私有成员（如int id）. 	
```
被友元声明的函数一定不是当前类的成员函数，即使该函数的定义写在当前类内

当前类的成员函数也不需要友元修饰

```C
#include <iostream>
using namespace std;
class A {
private:
    int data;
public:
    A(int i) : data(i) {}
    void print() { cout << data << " inside\n"; }
    friend void print(A a)  // 这一行的print是全局函数
		{ cout << a.data << " outside\n"; }
};
int main() {
    A c(1);
    c.print(); // 1 inside
    print(c); // 1 outside
    return 0;
}
```
**可以声明别的类的成员函数，为当前类的友元。**
其中，构造函数、析构函数也可以是友元。
```C
class Y {
    int data; 
    friend void X::foo(Y); 
    friend X::X(Y), X::~X(); 
};
```
X的构造函数X::X()和析构函数X::~X()为Y的友元函数，则在它们的函数体内可直接访问/修改Y的私有成员。

**友元的声明与当前所在域是否为private或public无关**
```C
class Y {
private:
	friend void X::foo(Y); 
};
```
<=>
```C
class Y {
public:
	friend void X::foo(Y); 
};
```
## **友元**
**一个普通函数可以是多个类的友元函数**
```C
class Y;
class X    
{    
    int data;
    friend void show(X &x, Y &y);
};  
class Y  
{  
    int data;
    friend void show(X &x, Y &y);
};  
  
void show(X &x, Y &y)  //全局函数，可以访问X，Y的私有数据
{  
    cout << x.data << " " << y.data << endl;  
} 
```
## **友元类**
可对class/struct/union进行友元声明，代表该类的所有成员函数均为友元函数
*对基础类型的友元声明会被忽略（因为没有实际价值）*。编译器可能会发出警告，但不会认为是错误。
```C
class Y {}; // 定义类Y，且Y能访问A的所有成员
class A {
    int data;  // 私有数据成员

    friend class X;  // 友元类前置声明（详细类型指定符）
    friend Y;  // 友元类声明（简单类型指定符） (C++11起)
}; 
class X {}; // 定义类X，X能访问A的所有成员
```
**注意事项**
**非对称关系**：类A中声明B是A的友元类，则B可以访问A的私有成员，但A不能访问B的私有成员。
**友元不传递**：朋友的朋友不是你的朋友
**友元不继承**（继承为后续内容）:朋友的孩子不是你的朋友
**友元声明不能定义新的class**，如
```C
class X    
{    
    friend class Y {};//안됌!
}
```
