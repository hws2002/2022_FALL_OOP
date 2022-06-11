#include <functional>
#include <iostream>
using namespace std;
int main() {
	auto func = greater<int>();
	cout << func(2, 1) << endl;	//True
	cout << func(1, 1) << endl;	//False
	cout << func(1, 2) << endl;	//False
	return 0;
}

