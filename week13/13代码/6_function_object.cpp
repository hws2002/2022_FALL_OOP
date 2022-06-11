#include <iostream>
using namespace std;
template<class T>
class Greater {
public:
	bool operator()(const T &a, const T &b) const	{
		return a > b;
	}
};
int main(){
	auto func = Greater<int>();
	cout << func(2, 1) << endl;	//True
	cout << func(1, 1) << endl;	//False
	cout << func(1, 2) << endl;	//False
	return 0;
}


