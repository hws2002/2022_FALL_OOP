//看下列代码，猜猜运行结果
/*
#include <iostream>
using namespace std;
class A
{
public:
	int a;
	int b = 1;
};
A obj1;
int main()
{
	A obj2;
	static A obj3;
	cout << obj1.a << " " << obj1.b << endl;
	cout << obj2.a << " " << obj3.b << endl;
	cout << obj3.a << " " << obj3.b << endl;
	return 0;
}
提示
全局变量和函数静态变量会自动置0
局部变量一般不会自动初始化，其值为未定义。具体运行结果可能会和系统、编译器有关。

拓展阅读
https://blog.csdn.net/dog250/article/details/107403337

*/

//试试运算符重载吧
/*
我们知道，int的范围是-2^31~2^31-1。请你实现一个范围更大的Int，定义如下

class Int
{
private:
	int high, low; //实际值为high * 10^8 + low;
};

尝试重载运算符
可以试试成员函数重载与全局重载两种方法
下一页给出几个最核心的几个运算符，更多的查看课上运算符列表

简单难度：
双目算术运算符	
+ (加)，-(减)
关系运算符
==(等于)， < (小于)
中等难度
单目运算符 -（负号）
高级难度
（注意返回值是否需要引用，有什么区别？）
自增运算符（前置和后置）两种 ++（自增）
赋值运算符 =, +=
流运算符 (cout) <<, >>

*/
