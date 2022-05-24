#include <iostream>
using namespace std;

template <typename T> class A {
	T data;
public:
	A(T _data): data(_data) {}
	void print();
};
 
template<typename T>
void A<T>::print() { cout << data << endl; }
int main() {
	A<int> a(1);
	a.print();
	return 0;
}
