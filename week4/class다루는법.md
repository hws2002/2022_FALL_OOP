## **类的运算符重载**

Q: 为什么需要类运算符重载？

A: 用户自定义类，没有对常用的运算符进行定义，比如想要表示两个类对象相加，无法采用a+b这种方式。
可以采取定义一个add函数的方式，解决这种问题。

! 但这种实现方式，在调用的时候，会和基础类型差别很大，缺少编程的一致性。需要过多地区分自定义类和基础类别，调用起来也不方便。
因此，我们引入运算符重载
```C++
#include <iostream>
using namespace std;
class A {
public:
    int data;
    A(int i) { data = i; }
    A& operator+=(A& a) { data += a.data; return *this;}
    // A operator+(A& a) { 
    //     A new_a(data + a.data);
    //     return new_a;
    // }
};
A operator+(A& a1, A& a2) {
    A new_a(a1.data + a2.data);
    return new_a;
}
int main() {
    A a1(2), a2(3);
    a1 += a2; // 调用operator+=()
    cout << a1.data << endl; // 5
    cout << (a1 + a2).data << endl; // 调用operator+()
    A a3 = a1+a2;
    return 0;
}

```

??Q??
class A{
    public:
    int data;
    A(int i):data(i){}
};랑
    A(int i) {
        data = i;
    }
    차이?
};