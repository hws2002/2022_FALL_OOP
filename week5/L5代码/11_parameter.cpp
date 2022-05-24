#include <iostream>
using namespace std;

class A {
public:
	const char* s;
	A(const char* str):s(str) { 
		cout << s << " A constructing" << endl;
	}
	~A() { cout << s << " A destructing" << endl; }
};

void fun(A b) {
	cout << "In fun: b.s=" << b.s << endl;
}

int main() {
	A a("a");
	fun(a);
	return 0;
}

