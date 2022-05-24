## **静态变量、函数**

**静态变量**：**使用static修饰的变量**

定义示例：static int i = 1;

初始化：初次定义时需要初始化，且只能初始化一次。

静态局部变量存储在静态存储区，生命周期将持续到整个程序结束

静态全局变量是内部可链接的，作用域仅限其声明的文件，不能被其他文件所用，可以避免和其他文件中的同名变量冲突

**静态函数**：**使用static修饰的函数**
定义示例：static int func() {…}

静态函数是内部可链接的，作用域仅限其声明的文件，不能被其他文件所用，可以避免和其他文件中的同名函数冲突

**区别：静态全局变量/静态函数和非静态全局变量/非静态全局函数**
静态全局变量/静态函数是内部可链接的，作用域仅限其声明的文件，不能被其他文件所用

非静态全局变量/非静态全局函数是外部可链接的，可以被其他文件所用

示例
```C
//a.cpp
#include <iostream>
using namespace std;

static int i = 1; //静态全局变量，只能用于a.cpp
int j = 2; //非静态全局变量，可用于其他文件
int add_i(int k);
int add_j(int k);

int main() {
  cout << i << “ ” << j << endl;
  return 0;
}
//b.cpp
extern int i; //链接时出错，因为i为静态全局变量，仅能用于其声明的文件a.cpp
extern int j;

int add_i(int k) { return k+i; };
int add_j(int k) { return k+j; };

//g++ a.cpp b.cpp -o test1 
//b.cpp: undefined reference to ‘i’ 链接错误
```
```C
//a.cpp
#include <iostream>
using namespace std;

int j = 2; 
static int add_j(int k) { //静态函数，只能用于a.cpp
  return k+j; 
};

int main() {
  cout << add_j(3) << endl;
  return 0;
}

//b.cpp
extern int add_j(int k); 
//链接时出错，因为add_j为静态函数，仅能用于其声明的文件a.cpp
int add() { return add_j(1); };

//g++ a.cpp b.cpp -o test1 
//b.cpp: undefined reference to ‘add_j(int)’ 链接错误
```
## **静态数据成员**

**静态数据成员：使用static修饰的数据成员，是隶属于类的，称为类的静态数据成员，也称“类变量”**
静态数据成员被该类的所有对象共享（即所有对象中的这个数据域处在同一内存位置）

类的静态成员（数据、函数）既可以通过对象来访问，也可以通过类名来访问，如ClassName::static_var或者a.static_var（a为ClassName类的对象

类的静态数据成员要在实现文件中赋初值，格式为：Type ClassName::static_var = Value; 

和全局变量一样，类的静态数据成员在程序开始前初始化

**静态数据成员应该在.h文件中声明，在.cpp文件中定义。**
如果在.h文件中同时完成声明和定义，会出现问题。

包含了该头文件的所有源文件中都定义了这些静态成员变量，即该头文件被包含了多少次，这些变量就定义了多少次。
同一个变量被定义多次，会导致链接无法进行，程序编译失败。

示例

```C++
//Test.h
class Test {
public:
  static int count; //声明静态数据成员 
  Test();
  ~Test();
};
//Test.cpp
#include “Test.h”

int Test::count = 0;//定义静态数据成员
Test::Test() { count ++; }
Test::~Test() { count --; }
//main.cpp
#include <iostream>
#include “Test.h”
using namespace std;

int main() {
  Test t[10];
  cout << “Test#: ” << Test::count << “ or ” << t[0].count << endl;
  //通过类名或对象访问静态数据成员
  return 0;
}
```

## **静态成员函数**
**静态成员函数：在返回值前面添加static修饰的成员函数，称为类的静态成员函数**

和静态数据成员类似，类的静态成员函数既可以通过对象来访问，也可以通过类名来访问，如ClassName::static_function或者a.static_function(a为ClassName类的对象）

**静态成员函数不能访问非静态成员**
静态成员函数属于整个类，在类实例化对象之前已经分配了内存空间。
类的非静态成员必须在类实例化对象后才分配内存空间。
如果使用静态成员函数访问非静态成员，相当于没有定义一个变量却要使用它。

```C++
#include <iostream>
using namespace std;

class Test {
public:
  static int count; //声明静态数据成员
  float value;
  Test(int v): value(v) { count ++; }
  ~Test() { count --; }
  static int how_many() { return count; } 
  //静态成员函数how_many仅能访问count，无法访问value
};

int Test::count = 0;//定义静态数据成员

int main() {
  Test t(2);
  cout << “Test#: ” << Test::how_many() << endl;
  cout << “Test.value: ” << t.value << endl;
  return 0;
}
```
静态成员函数错误调用示例
```C++
	#include <iostream>
	using namespace std;

class A {  
	int data;
public:    
	static void output() {  
        cout << data << endl; // 编译错误
    }  
};  
int main()  
{  
    A a;  
    a.output();  
 	return 0;
} 
//*编译器错误提示：
//[Error] invalid use of member 'A::data' in static member function
```

## **静态对象的构造与析构**

**静态全局对象的构造与析构时机和普通全局对象相同**

### **函数中静态对象：在函数内部定义的静态局部对象**
在程序执行到该静态局部对象的代码时被初始化。
离开作用域不析构。
第二次执行到该对象代码时，不再初始化，直接使用上一次的对象
在main()函数结束后被析构。
```C++
void fun(int i, int n) {
	if (i >= n) 
		static A static_obj("static");
}
```
### **类静态对象：类A的对象a作为类B的静态变量**
a的构造与析构表现和全局对象类似，即在main()函数调用之前进行初始化，在main()函数执行完return，程序结束时，对象被析构
和B是否实例化无关
```C++
class A {};

class B {
	static A a; //
};
```

示例 
```C++
#include <iostream>
using namespace std;

class A {
	const char* s;
public:
	A(const char* str):s(str) { 
		cout << s << " A constructing" << endl;
	}
	~A() { 
		cout << s << " A destructing" << endl; 
	}
};

class B {
	static A a1;
	const A a2;
public:
	B(const char* str):a2(str) { }
	~B() { }
};

void fun() {
	static A static_obj("static");
}

const A c_a("const c_a");
static A s_a("static s_a");
A B::a1("static B::a1");

int main() {
	cout << "main starts" << endl;
	static B main_b("static main_b");
	for (int i = 0; i < 4; i++) {
		fun();
	}
	cout << "main ends" << endl;
	return 0;
}
// const c_a A constructing
// static s_a A constructing
// static B::a1 A constructing
// main starts
// static main b A constructing
// static A constructing
// main ends
// static A destructing
// static B::a1 A destructing
// static s_a A destructing
// const c_a A destructing
```
