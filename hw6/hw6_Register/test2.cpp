#include <string>
#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char * argv[]) {
    string test = "test replacing \"these characters\"";
    regex reg("[^\\w]+");
    test = regex_replace(test, reg, "_");
    cout << test << endl;

	test = "test replacing \"these characters\"";
	test = regex_replace(test, regex("\\s+"), "_");
    cout << test << endl; 	

	test = "test replacing \"these characters\"";
	test = regex_replace(test, regex("\\W+"), "");
    cout << test << endl;

}