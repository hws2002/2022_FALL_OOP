#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Node;
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

class Node
{
private:
	static long long int num_createfunc_default, num_createfunc, num_copyfunc, num_movefunc, num_copyassign, num_moveassign, num_delfunc;
	int val;
public:	
	Node(int v);
	Node();
	~Node();
	Node(const Node &y);
	Node(Node &&y);
	Node& operator=(const Node &y);
	Node& operator=(Node &&y);
	bool operator!=(const Node &y);
	friend std::istream& operator>>(std::istream& in, Node& x);
	friend std::ostream& operator<<(std::ostream& out, const Node& x);
	static void outputResult(int ref_ans);
};

long long int Node::num_createfunc = 0, Node::num_copyfunc = 0, Node::num_movefunc = 0;
long long int Node::num_copyassign = 0, Node::num_moveassign = 0, Node::num_delfunc = 0;
long long int Node::num_createfunc_default = 0;

Node::Node(int v): val(v) {
	num_createfunc++;
}
Node::Node(){
	num_createfunc_default++;
}
Node::~Node() {
	num_delfunc++;
}
Node::Node(const Node &y): val(y.val) {
	num_copyfunc++;
}
Node::Node(Node &&y): val(y.val) {
	y.val = 0;
	num_movefunc++;
}
Node& Node::operator=(const Node &y) {
	val = y.val;
	num_copyassign++;
	return *this;
}
Node& Node::operator=(Node &&y) {
	val = y.val;
	y.val = 0;
	num_moveassign++;
	return *this;
}

bool Node::operator!=(const Node & y){
	return val != y.val;
}

void Node::outputResult(int ref_ans) {
	std::cout << Node::num_createfunc_default << " " << Node::num_createfunc << " " << Node::num_copyfunc << " " << Node::num_movefunc << " " << Node::num_copyassign << " " << Node::num_moveassign << " " << Node::num_delfunc << std::endl;
	long long int tmp = (Node::num_createfunc+Node::num_copyfunc+Node::num_copyassign)*10+Node::num_movefunc+Node::num_moveassign+Node::num_createfunc_default;
	if (tmp <= ref_ans && Node::num_createfunc + Node::num_createfunc_default + Node::num_copyfunc + Node::num_movefunc == Node:: num_delfunc){
		std::cout << "YES" << std::endl;
	}	
	else{
		std::cout << "NO" << std::endl;
	}
}

std::istream& operator>>(std::istream& in, Node& x){
	std::cin >> x.val;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Node& x){
	std::cout << x.val;
	return out;
}
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
		if(array) delete []array;
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

void test_equivalence(Vector & a, Vector & b, string msg){
	if(a.getlen() != b.getlen()){
		cout << msg << endl;
		return;
	}
	for(int i = 0; i < a.getlen(); ++i){
		if(a[i] != b[i]){
			cout << msg << endl;
			return;
		}
	}
	cout << "pass" << endl;
}

void outputArray(Vector& a, int len){
	for(int i = 0; i < len - 1; i ++){
		cout << a[i] << " ";
	}
	cout << a[len - 1] << endl;
}

void readArray(Vector& a, int n)
{
	int value;
	for(int i = 0; i < n; i++)
	{
		cin >> value;
		a.append(value);
	}
}

Vector test1()
{
	int len, k, n;
	int p, q, r;

	cin >> len;
	Vector a(len);
	cin >> n;
	readArray(a, n);//接下来m行，每行一个整数，按顺序加入Vector数组中。

	cin >> k;
	for (int i = 0; i < k; i ++){
		cin >> p;
		switch (p){
			case 0:
				cin >> q;
				a.append(q);
				break;
			case 1:
				cin >> q >> r;
				a.insert(q, r);
				break;
			case 2:
				cin >> q >> r;
				a.swap(q, r);
				break;
			case 3:
				a.dilatation();
				break;
			default:
				break;
		}
		outputArray(a, a.getlen());
	}
	Vector tmp(a);
	test_equivalence(a, tmp, "Wrong implementation of copy constructor");
	return tmp;
}

void test2(){
	Vector a(test1());
	outputArray(a, a.getlen());
	Vector b(1);
	if(b.getlen() != 0){
		cout << "Wrong implementation of constructor" << endl;
	}
	b = a;
	test_equivalence(a, b, "Wrong implementation of copy assignment operator");
	Vector c(1);
	c = move(a);
	if(a.getlen() != 0){
		cout << "Wrong implementation of move assignment operator" << endl;
	}
	outputArray(c, c.getlen());
}

int main()
{
	int ref_ans;
	cin >> ref_ans;
	test2();
	Node::outputResult(ref_ans);
	return 0;
}
