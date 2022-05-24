#pragma once
#include "Node.h"
#include <iostream>

class Vector {
private:
	int capacity;
	int len;
	Node* array;
public:
	Vector(int n);//ok
	~Vector();
	Vector(const Vector & other);//ok
	Vector(Vector && other);//ok
	Vector & operator=(const Vector & other);//ok
	Vector & operator=(Vector && other);//ok
	Node& operator [] (int pos);//ok
	void append(int value);//ok
	void insert(int pos, int value);
	void swap(int pos1, int pos2);
	void dilatation();//ok
	int getlen();//ok
};