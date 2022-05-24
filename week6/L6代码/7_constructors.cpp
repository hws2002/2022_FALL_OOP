#include <iostream>

class Test {
public:
	Test() {
		printf("Test()\n");
	} //默认构造函数
	
	~Test() {
		printf("~Test()\n");
	} //析构函数
	
	Test(const Test &con) {
		printf("Test(const Test &con)\n");
	} //拷贝构造函数	

	Test(Test &&con) {
		printf("Test(Test &&con)\n");
	} //移动构造函数

};

Test func(Test a) {
	return Test();
}

int main() {
	Test a;
	Test b = func(a);
	return 0;
}

//编译指令加 g++ 7_constructors.cpp --std=c++11 -fno-elide-constructors -o test
/*
我们用(1+)和(1-)这样的形式来对应类的构造和析构。

Test()					//(1+) 执行Test a；
Test(const Test &con) //(2+)Test b = func(a);
						//func(a)传参调用拷贝构造函数
Test()					//(3+)return Test();
						//Test()对应的构造函数
Test(Test &&con) 		//(4+)return Test();
						//为了传值调用的移动构造函数
~Test() 				//(3-)return Test();
						//Test()对应的析构函数
Test(Test &&con) 		//(5+)Test b = func(a);
						//中给b传值时调用的移动构造函数
~Test()					//(4-)Test b = func(a);
					   //完成赋值后func(a)返回值							对应的析构函数
~Test()				   //(2-)Test b = func(a);
					   //参数释放对应的析构函数
~Test()				   //(5-) 析构b
~Test()				   //(1-) 析构a
*/
