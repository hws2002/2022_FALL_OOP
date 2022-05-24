#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	for (int i = 0; i < n; i++) 
		e[i] = new Example(i);
			
	// (6)
	static Example sixth_example(2333);
	e[0]->getData();
	e[1]->getData();
	e[2]->getData();
	for(int i=0;i<n;i++)
		delete e[i];
	sixth_example.getData();
	cout << "--------create_example is over--------\n";
}

// (7)
Example first_example(23);
int main() {

	cout << "--------main_function is ready--------\n";
	// (8)
	Example second_example(233);
	create_example(3);
	// (9)
	Example seventh_example(23333);
	first_example.getData();
	second_example.getData();
	seventh_example.getData();
	cout << "--------main_function is over---------\n";

	return 0;
}
