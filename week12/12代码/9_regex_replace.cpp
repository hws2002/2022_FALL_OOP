#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string s("this subject has a submarine");
	regex e(R"(sub[\S]*)");
	//regex_replace返回值即为替换后的字符串 
	cout << regex_replace(s,e,"SUB") << "\n";
	return 0;
}

