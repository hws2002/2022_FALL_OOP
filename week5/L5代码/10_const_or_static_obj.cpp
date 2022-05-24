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

