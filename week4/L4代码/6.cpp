#include <iostream>
using namespace std;
class Example
{
	int index;

public:
	Example(int i) : index(i)
	{
		cout << index << " is created\n";
	}
	~Example() { cout << index << " is destroyed\n"; }
};
void create_example(int i)
{
	Example e(i); // 只在函数内存在
	cout << "Function is over\n";
}
int main()
{
	for (int i = 1; i < 3; i++)
	{
		Example e(0); // 只在当前循环内存在
		create_example(i);
	}
	return 0;
}
// 0 created
// i is created
// function is over,
// i is destroyed
//0 is destrooyed
// 