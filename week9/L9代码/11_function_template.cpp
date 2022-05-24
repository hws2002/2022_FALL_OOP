#include <iostream>
#include <algorithm>

template<class T>
void sort(T* data, int len)
{
	for(int i = 0; i < len; i++){ //选择排序
		for(int j = i + 1; j < len; j++) {
			if(data[i] > data[j])
				std::swap(data[i], data[j]); //交换元素位置
		}
	}
}

template<class T>
void output(T* data, int len)
{
	for(int i = 0; i < len; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}
int main()
{
	int arr_a[] = {3,2,4,1,5};
	sort(arr_a, 5);  //调用int类型的sort
	output(arr_a, 5); //调用int类型的output
	
	float arr_b[] = {3.2, 2.1, 4.3, 1.5, 5.7};
	sort(arr_b, 5); //调用float类型的sort
	output(arr_b, 5);  //调用float类型的output
	return 0;
}
