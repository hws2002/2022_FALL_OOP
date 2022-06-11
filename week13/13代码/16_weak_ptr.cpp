#include <memory>
#include <iostream>
using namespace std;
int main()
{
	std::weak_ptr<int> wp;
	{
		auto sp1 = std::make_shared<int>(20);
		wp = sp1;
		cout << wp.use_count() << endl;	//1
		auto sp2 = wp.lock();	//从弱引用中获得一个shared_ptr
		cout << wp.use_count() << endl;	//2
		sp1.reset();							//sp1释放指针
		cout << wp.use_count() << endl;	//1
	}	//sp2销毁
	cout << wp.use_count() << endl;	//0
	cout << wp.expired() << endl;	  //检查弱引用是否失效：True
	return 0;
}

