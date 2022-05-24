#include <iostream>
using namespace std;

class Test {
	int id;
public:
	Test(int i) : id(i) { cout << "obj_" << id << " created\n"; } 
	
	friend istream& operator>> (istream& in, Test& dst); 
	friend ostream& operator<< (ostream& out, const Test& src); 
};
istream& operator>> (istream& in, Test& dst) {
	in >> dst.id;
	return in;
}
ostream& operator<< (ostream& out, const Test& src) {
	out << src.id;
	return out;
}
int main() {
	Test test(0);
	cin >> test;
	cout << test << endl;
}

