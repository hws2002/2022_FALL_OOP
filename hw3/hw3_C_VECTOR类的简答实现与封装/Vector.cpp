#include "Vector.h"


Vector::Vector(int n){
    capacity = n;
    len = 0;
    array = new Node[n];
}
Vector::~Vector(){
    if(array) delete [] array;
}

Node& Vector::operator [] (int pos){
    return array[pos];
}
Vector::Vector(const Vector & other): capacity(other.capacity), len(other.len){
	array = new Node[capacity];
    for(int i=0;i<len;i++){
        array[i] = other.array[i];
    }
}

Vector::Vector(Vector && other) : capacity(std::move(other.capacity)),len(std::move(other.len)){
    array = std::move(other.array);
	other.array = nullptr;
}

Vector & Vector::operator=(const Vector & other){
    if (this!=&other){
		if(array) delete []array;`
        capacity = other.capacity;
        len = other.len;
        array = new Node[capacity];
        for(int i=0;i<len;i++){
            array[i] = other.array[i];
        }
    }
    return *this;
}

Vector & Vector::operator=(Vector && other) {
    if(this!= &other){
        if(array) delete []array;
        capacity = other.capacity;
        len = other.len;
        array = std::move(other.array);
        other.capacity = 0;
        other.len = 0;
        other.array = nullptr;
    }
    return *this;
}

void Vector::append(int value){
    array[len++] = value;
}

void Vector::swap(int pos1, int pos2){
    Node tmp = std::move(array[pos1]);
    array[pos1] = std::move(array[pos2]);
    array[pos2] = std::move(tmp);
}

void Vector::insert(int pos, int value){
    for(int i=len;i>pos;i--){
        array[i] = std::move(array[i-1]);
    }
    array[pos] = value;
    len++;
}

void Vector::dilatation(){
    capacity *=2;
    Node * new_array = new Node[capacity];
    for(int i=0;i<len;i++){
        new_array[i] = std::move(array[i]);
    }
	if(array) delete []array;
    array = new_array;
}

int Vector::getlen(){
    return len;
}