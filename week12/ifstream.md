# **文件输入输出流**

ifstream是istream的子类

## **打开文件**
```C++
ifstream ifs("input.txt");
ifstream ifs("binary.bin", ifstream::binary);
//以二进制形式打开文件
ifstream ifs;
ifs.open("file")
//do something
ifs.close()
```
输入示例
```C++
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

int main() {
ifstream ifs("input.txt");
while(ifs) {			//判断文件是否到末尾 利用了重载的bool运算符
	ifs >> ws;  		//除去前导空格 ws也是流操纵算子
	int c = ifs.peek();		//检查下一个字符，但不读取
	if (c == EOF) break;
	if (isdigit(c))			//<cctype>库函数
	{
		int n;
		ifs >> n;
		cout << "Read a number: " << n << endl;
	} else {
		string str;
		ifs >> str;
		cout << "Read a word: " << str << endl;
	}
}
return 0;
}
```

### **其他操作**
ifstream이 istream의 子类라서, 
getline이 仍然有效
```C++
getline(cin, str)
```
```C++
get()     读取一个字符
ignore(int n=1, int delim=EOF)
//	    丢弃n个字符，或者直至遇到delim分隔符
peek()    查看下一个字符
putback(char c) 返还一个字符
unget()   返还一个字符
```

### **istream与scanf**
#### **为什么C++使用流输入取代了scanf**
```C++
//scanf不友好，不同类型要使用不同的标识符
scanf("%d %hd %f %lf %s", &i, &s, &f, &d, name);
cin >> i >> s >> f >> d >> name;
//安全性
scanf("%d", &a);  //可能写入非法内存
//可拓展性
MyClass obj;
cin >> obj;
//性能
scanf在运行期间需要对格式字符串进行解析
istream在编译期间已经解析完毕
```



