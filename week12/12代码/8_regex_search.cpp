#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string s("this subject has a submarine");
	regex e(R"((sub)([\S]*))");
	smatch sm;
	//每次搜索时当仅保存第一个匹配到的子串
	while(regex_search(s,sm,e)){
		for (unsigned i=0; i<sm.size(); ++i)
			cout << "[" << sm[i] << "] ";
		cout << endl;
		s = sm.suffix().str();
	}
	return 0;
}

