#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string s("subject");
	regex e("sub.*");
	smatch sm;
	if(regex_match(s,e))
		cout << "matched" << endl;
	return 0;
}

