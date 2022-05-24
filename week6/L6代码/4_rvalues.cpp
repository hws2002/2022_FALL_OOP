#include <iostream>
using namespace std;

void ref(int &x) {
	cout << "left " << x << endl;
}

void ref(int &&x) {
	cout << "right " << x << endl;
}

int main() {
	int a = 1;
	ref(a);
	ref(2); //2是一个常量
	return 0;
}

