#include <iostream>
using namespace std;

class Pet { public:  virtual ~Pet() {} };
class Dog : public Pet { 
public: 	void run() { cout << "dog run" << endl; }
};
class Bird : public Pet {
public: 	void fly() { cout << "bird fly" << endl; }
};

void action(Pet* p) {
	auto d = dynamic_cast<Dog*>(p);	/// 向下类型转换
	auto b = dynamic_cast<Bird*>(p);	/// 向下类型转换
	if (d) /// 运行时根据实际类型表现特性
		d->run();
	else if(b)
		b->fly();
}
int main() {
	Pet* p[2];
	p[0] = new Dog; /// 向上类型转换
	p[1] = new Bird; /// 向上类型转换
	for (int i = 0; i < 2; ++i) {
		action(p[i]);
	}
	return 0;
}
