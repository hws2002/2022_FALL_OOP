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

