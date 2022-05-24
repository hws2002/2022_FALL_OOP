#include <iostream>
using namespace std;

class Test {
public:
	int * buf; //// only for demo.
	Test() {
		buf = new int[10]; //申请一块内存
		cout << "Test(): this->buf @ " << hex << buf << endl;
	}
	~Test() {
		cout << "~Test(): this->buf @ " << hex << buf << endl;
		if (buf) delete[] buf;
	}
	Test(const Test& t) : buf(new int[10]) {
		for(int i=0; i<10; i++)
			buf[i] = t.buf[i]; //拷贝数据
		cout << "Test(const Test&) called. this->buf @ "
			<< hex << buf << endl;
	}
	Test(Test&& t) : buf(t.buf) { //直接复制地址，避免拷贝
		cout << "Test(Test&&) called. this->buf @ "
			<< hex << buf << endl;
		t.buf = nullptr; //将t.buf改为nullptr，使其不再指向原来内存区域
	}
};

Test GetTemp() {
	Test tmp;
	cout << "GetTemp(): tmp.buf @ "
		<< hex << tmp.buf << endl;
	return tmp;
}
void fun(Test t) {
	cout << "fun(Test t): t.buf @ "
		<< hex << t.buf << endl;
}
int main() {
	Test a = GetTemp();
	cout << "main() : a.buf @ " << hex << a.buf << endl;
	fun(a);
	return 0;
}
/*
编译指令：
g++ 6_move_constructor.cpp --std=c++11 -o test
Test(): this->buf @ 0x600000c00060
GetTemp(): tmp.buf @ 0x600000c00060
main() : a.buf @ 0x600000c00060
Test(const Test&) called. this->buf @ 0x600000c00120
fun(Test t): t.buf @ 0x600000c00120
~Test(): this->buf @ 0x600000c00120
~Test(): this->buf @ 0x600000c00060
*/

/*
增加编译选项，禁止编译器进行返回值优化
g++ 6_move_constructor.cpp --std=c++11 -fno-elide-constructors -o test

Test(): this->buf @ 0x600003a88270
GetTemp(): tmp.buf @ 0x600003a88270
Test(Test&&) called. this->buf @ 0x600003a88270
~Test(): this->buf @ 0x0
Test(Test&&) called. this->buf @ 0x600003a88270
~Test(): this->buf @ 0x0
main() : a.buf @ 0x600003a88270
Test(const Test&) called. this->buf @ 0x600003a882a0
fun(Test t): t.buf @ 0x600003a882a0
~Test(): this->buf @ 0x600003a882a0
~Test(): this->buf @ 0x600003a88270
*/

/*
删除移动构造函数、并且禁止编译器优化的输出结果
g++ 6_move_constructor.cpp --std=c++11 -fno-elide-constructors -o test
Test(): this->buf @ 0x600002ec4270
GetTemp(): tmp.buf @ 0x600002ec4270
Test(const Test&) called. this->buf @ 0x600002ec42a0
~Test(): this->buf @ 0x600002ec4270
Test(const Test&) called. this->buf @ 0x600002ec4270
~Test(): this->buf @ 0x600002ec42a0
main() : a.buf @ 0x600002ec4270
Test(const Test&) called. this->buf @ 0x600002ec42a0
fun(Test t): t.buf @ 0x600002ec42a0
~Test(): this->buf @ 0x600002ec42a0
~Test(): this->buf @ 0x600002ec4270

注意：在Test a = GetTemp()完成赋值后，GetTemp()返回值的析构函数，即第二个。
注意这里，虽然地址只有两个，但是实际上重新分配了内存三次。（系统将同一块地址重新分配）

*/


