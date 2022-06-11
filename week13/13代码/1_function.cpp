#include <iostream>
int arr[5] = { 5, 2, 3, 1, 7 };
void increase(int &x){x++;}
void decrease(int &x){x--;}
int main()
{
	int flag; std::cin >> flag;
	if (flag == 1) {
		for (int &x : arr) { 	increase(x);}
	}else{
		for (int &x : arr) { 	decrease(x);}
	}
	return 0;
}

