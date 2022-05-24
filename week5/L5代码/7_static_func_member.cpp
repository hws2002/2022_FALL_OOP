#include <iostream>
using namespace std;

class A {  
	int data;
public:    
	static void output() {  
        cout << data << endl; // 编译错误
    }  
};  
int main()  
{  
    A a;  
    a.output();  
 	return 0;
} 

