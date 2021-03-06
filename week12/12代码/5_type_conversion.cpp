#include <iostream>
#include <sstream>
using namespace std;

template<class outtype, class intype>
outtype convert(intype val)
{
	static stringstream ss;
						//使用静态变量避免重复初始化
	ss.str(""); 	//清空缓冲区
	ss.clear(); 	//清空状态位（不是清空内容）
	ss << val;
	outtype res;
	ss >> res;
	return res;
}

int main() {
	string x = convert<string>(123);
	int y = convert<int>("456");
	cout << x << endl;
	cout << y << endl;
	return 0;
}


