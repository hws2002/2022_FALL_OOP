#include <iostream>
#include <algorithm>

template<class T, unsigned size>
class MyArr
{
	T data[size];
public:	
	void sort(){
		for(int i = 0; i < size; i++){ //选择排序
			for(int j = i + 1; j < size; j++) {
				if(data[i] > data[j])
					std::swap(data[i], data[j]); //交换两者位置
			}
		}
	}
	void output(){
		for(int i = 0; i < size; i++)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}
	void input(){
		for(int i = 0; i < size; i++)
			std::cin >> data[i];
	}
};
int main()
{
	MyArr<int, 5> arr_a;
	arr_a.input();
	arr_a.sort();
	arr_a.output();
	
	MyArr<float, 5> arr_b;
	arr_b.input();
	arr_b.sort();
	arr_b.output();
	return 0;
}


