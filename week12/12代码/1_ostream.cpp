#include <cstdio>

class ostream
{
public:
	ostream& operator<<(char c)
	{
		printf("%c", c);
		return *this;
	}
	ostream& operator<<(const char* str)
	{
		printf("%s", str);
		return *this;
	}
}cout;
int main()
{
	cout << "hello" << ' '
		 << "world";
    return 0;
}


