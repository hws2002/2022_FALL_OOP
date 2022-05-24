## **全局对象的构造与析构**
**特点**

1. 在main()函数调用之前进行初始化。
2. 在同一编译单元中，按照定义顺序进行初始化。（编译单元：通常同一编译单元就是同一源文件。）
3. 不同编译单元中，对象初始化顺序不确定。
4. 在main()函数执行完return之后，对象被析构

### **尽量少用全局对象**
全局对象的构造顺序不能完全确定，所以全局对象之间不能有依赖关系，否则会出现问题

全局对象会增大代码的耦合性，导致程序难以复用或者测试

使用参数来替代全局对象
```C
//不要
void foo() {
    input.doSomething();
}
Input input;
int main() {
	foo();
}
```
```C
//这样
void foo(Input input) {
    input.doSomething();
}
int main() {
    Input input;
    foo(input);
}
```

### **특수한 operator overloading**
如果有哑元，则是postfix（后置）,否则，就是prefix（前置）。

**前缀运算符重载声明**
```C++
ClassName operator++();
ClassName operator--();
```
```C
#include <iostream>
using namespace std;

class Test {
public:
  int data = 1;
  Test(int d) {data = d;}
  Test& operator++ () {
    ++data;
    return *this;
  }
};	

int main() {
  Test test(1); 
  ++test;
  return 0;
}
```
全局重载
```C
#include <iostream>
using namespace std;

class A {
public:
    int data;
    A() { data = 0; }
    A(int i) { data = i; }
};

A operator++(A& a) {//前缀
    ++a.data;
    return a;
}
```
**后缀运算符重载声明**
```C++
ClassName operator++(int dummy);
ClassName operator--(int dummy);
```
```C
#include <iostream>
using namespace std;

class Test {
public:
  int data = 1;
  Test(int d) {data = d;}
  Test operator++ (int) {
    Test test(data);
    ++data;
    return test;
  }
};	

int main() {
  Test test(1); 
  test++;
  return 0;
}
```
全局重载
```C
A operator++(A& a, int) { //哑元，后缀
    A new_a(a.data);
    ++a.data;
    return new_a;
}

int main() {
    A a(1);
    cout << (++a).data << endl; // 2
    cout << (a++).data << endl; // 2
    cout << a.data << endl; // 3
    return 0;
}
```
