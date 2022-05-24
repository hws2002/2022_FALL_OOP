#include <iostream>
#include "Example.h"
using namespace std;


	// (2)
int Example::num_obj=0;
int Example::num_added=0;

Example::Example(int data) {
	// (3)
	this->data = data;
	this->num_obj++;
	this->num_added++;
	this->own_num = num_obj;
	cout<<"Example #"<< this->num_obj<<" is created"<<endl;
}
void Example::getData() {
	// (4)
	cout<<"The data of Example #"<<this->own_num<<" is "<<this->data<<endl;
}

Example::~Example() {
	// (5)
	cout<<"Example #"<<this->own_num <<" is destroyed"<<endl;;
}
