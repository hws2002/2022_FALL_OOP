#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string s("this subject has a submarine");
	regex e(R"((sub)([\S]*))");
	//regex_replace返回值即为替换后的字符串 
	cout << regex_replace(s,e,"SUBJECT") << endl;
	//$&表示所有匹配成功的部分，[$&]表示将其用[]括起来
	cout << regex_replace(s,e,"[$&]") << endl;
	//$i输出e中第i个括号匹配到的值
	cout << regex_replace(s,e,"$1") << endl;
	cout << regex_replace(s,e,"$2") << endl;
	cout << regex_replace(s,e,"$1 and [$2]") << endl;
	return 0;
}

