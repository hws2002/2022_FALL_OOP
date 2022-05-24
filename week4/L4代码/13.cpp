#include <iostream>
using namespace std;

class Test
{
public:
	int operator()(int a, int b)
	{
		cout << "operator() called. " << a << ' ' << b << endl;
		return a + b;
	}
};

int main()
{
	Test sum;
	int s = sum(3, 4); /// sum对象看上去象是一个函数，故也称“函数对象”
	cout << "a + b = " << s << endl;

	int t = sum.operator()(5, 6);
	cout<<t;
	return 0;
}
