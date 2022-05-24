# **stringstream**
它在对象内部维护了一个buffer

使用流输出函数可以将数据写入buffer

使用流输入函数可以从buffer中读出数据

## **构造方式**
```C++
stringstream ss; //空字符串流
stringstream ss(str); //以字符串初始化流
```

## **获取stringstream的buffer**
ss.str();
```c++
#include <sstream>
#include <iostream>
using namespace std;

int main() {
	stringstream ss;
	ss << "100 200";
	cout << ss.str() << endl;  //输出"100 200"
	int a;
	ss >> a;					 // a = 100
	cout << ss.str() << endl;  //输出"100 200"
	return 0;
}
```

