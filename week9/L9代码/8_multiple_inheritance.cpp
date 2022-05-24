#include <iostream>
using namespace std;

class WhatCanSpeak {
public:
	virtual ~WhatCanSpeak() {}
	virtual void speak() = 0;  };
class WhatCanMotion {
public:
	virtual ~WhatCanMotion() {}
	virtual void motion() = 0;   };
class Human : public WhatCanSpeak, public WhatCanMotion
{
	void speak() { cout << "say" << endl; }
	void motion() { cout << "walk" << endl; }
};

void doSpeak(WhatCanSpeak* obj) { obj->speak(); }
void doMotion(WhatCanMotion* obj) { obj->motion(); }
int main()
{
	Human human;
	doSpeak(&human); doMotion(&human);
	return 0;
}
