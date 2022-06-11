#include <algorithm>
#include <functional>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}
template<class Iterator, class Compare>
void mysort(Iterator first, Iterator last, Compare comp)
//mysort的时间复杂度为O(n^2)，std::sort的时间复杂度为O(nlogn)
{
	for (auto i = first; i != last; i++)
		for (auto j = i; j != last; j++)
			if (!comp(*i, *j)) swap(*i, *j);
}
int main()
{
	int arr[5] = { 5, 2, 3, 1, 7 };
	mysort(arr, arr + 5, comp);
	mysort(arr, arr + 5, greater<int>()); 
    //既可接受函数指针，又可接受函数对象
	return 0;
}

