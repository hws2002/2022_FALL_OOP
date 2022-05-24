
## **类的运算符重载**
### **为什么需要类运算符重载？**
用户自定义类，没有对常用的运算符进行定义，比如想要表示两个类对象相加，无法采用a+b这种方式。
可以采取定义一个add函数的方式，解决这种问题。
```C
A add(A a, A b) {
    return A(a.data + b.data);
}
```
但这种实现方式，在调用的时候，会和基础类型差别很大，缺少编程的一致性。需要过多地区分自定义类和基础类别，调用起来也不方便。
因此，我们引入运算符重载

### **operator overloading**
运算符重载需要按规则声明执行该运算的函数
例如 + 对应 operator+

运算重载一般有两种方式（注意参数不同）
全局函数的运算符重载
```C
	A operator+(A a, A b) {…}
```
成员函数的运算符重载
```C
class A{
	int data;
public:
	A operator+(A b) {…};
};
```

### **函数运算符 ( ) 重载示例**
```C
#include <iostream>
using namespace std;

class Test {
public:
  int operator() (int a, int b) {
    cout << "operator() called. " << a << ' ' << b << endl;
    return a + b;
  }
};	

int main() {
  Test sum;
  int s = sum(3, 4); /// sum对象看上去象是一个函数，故也称“函数对象”
  cout << "a + b = " << s << endl;
	
  int t = sum.operator()(5, 6); 
  return 0;
}
```

### **数组下标运算符 [ ] 重载**

函数声明形式

	返回类型 operator[] (参数); 

如果返回类型是引用，则数组运算符调用可以出现在等号左边，接受赋值，即
	Obj[index] = value;

如果返回类型不是引用，则只能出现在等号右边
	Var = Obj[index];
**!注意：这里Obj是一个对象，而不是一个数组!**

**!=,[],(),->只能通过成员函数来重载!**
为什么这么做？

当没有自定义operator=时，编译器会自动合成一个默认版本的赋值操作

在类内定义operator=，编译器则不会自动合成

如果允许使用全局函数重载，可能会对是否自动合成产生干扰

### **对象输入输出 —— 流运算符重载**
```C
istream& operator>> (istream& in, Test& dst );
 
ostream& operator<< (ostream& out, const Test& src ); 
```
函数名为：operator>> 和 operator<< 

不修改istream和ostream类的情况下，只能使用全局函数重载

返回值为：istream& 和 ostream&，均为引用

参数分别：流对象的引用、目标对象的引用。对于输出流，目标对象一般是常量引用
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
	out << src.id << endl;
	return out;
} 

int main() {
	Test obj(1);	
    cout << obj;  // operator<<(cout,obj)
	cin >> obj;	 // operator>>(cin,obj) 	
    cout << obj;	
	return 0;
}	
```

