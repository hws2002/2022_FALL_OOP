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

class MyInt
{
public:
	int data;
	MyInt(int val): data(val) {};
	bool operator>(const MyInt& b){ //用于sort
		return data > b.data;
	}
	friend std::ostream&  //用于output
			operator<<(std::ostream& out, const MyInt& obj){
		out << obj.data;
		return out;
	}
};

int main()
{
	MyInt arr_c[] = {3, 2, 4, 1, 5};
	sort(arr_c, 5);
	output(arr_c, 5);
	return 0;
}
