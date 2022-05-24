#include <iostream>

using namespace std;

void ref(int &x) {
	cout << "left " << x << endl;
}

void ref(int &&x) {
	cout << "right " << x << endl;
	ref(x); //调用哪一个函数？
}

int main() {
	ref(1); //1是一个常量
	return 0;
}
// Output：
// right 1
// left 1

// ref(1)首先调用ref(int &&x)函数，此时右值引用x为左值，因此ref(x)调用ref(int &x)函数。

