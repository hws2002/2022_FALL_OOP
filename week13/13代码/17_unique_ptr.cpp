#include <memory>
#include <utility>
using namespace std;
int main() {
	auto up1 = std::make_unique<int>(20);
	//unique_ptr<int> up2 = up1; 
			//错误，不能复制unique指针
	unique_ptr<int> up2 = std::move(up1);
			//可以移动unique指针
	int* p = up2.release();
			//放弃指针控制权，返回裸指针
	delete p;
	return 0;
}

