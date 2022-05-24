#include <sstream>
#include <iostream>
using namespace std;

int main() {
	stringstream ss;
	ss << "10";
	ss << "0 200";

	int a, b;
	ss >> a >> b;		//a=100 b=200
	cout<<a<<" "<<b;
	return 0;
}

