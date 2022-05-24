#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main () {
	string s("version10");
	regex e(R"(version(\d+))"); smatch sm;
	if(regex_match(s,sm,e)) {
		cout << sm.size() << " matches\n";
		cout << "the matches were:" << endl;
		for (unsigned i=0; i<sm.size(); ++i) {
			cout << sm[i] << endl;
		}
	}
	return 0;
}

