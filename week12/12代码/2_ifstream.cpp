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

