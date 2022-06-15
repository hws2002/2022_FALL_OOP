#include <iostream>
#include <fstream>
#include <functional>
#include <string>
using namespace std;

string readFromScreen()
{
    string input; getline(cin, input);
    return input;
}

class ReadFromFile
{
public:
    string operator()(){
        string input;
        getline(ifstream("input.txt"), input);
        return input;
    }
};


string calculateAdd(string x)
{
    return x;
}

void writeToScreen(string x)
{
    cout << x;
}
template<class ReadFunc, class CalFunc, class WriteFunc>
void process(ReadFunc read, CalFunc calculate, WriteFunc write)
{
	string data = read();
	string output = calculate(data);
	write(output);
}

int main()
{
    process(readFromScreen, calculateAdd, writeToScreen);
    process(ReadFromFile(), calculateAdd, writeToScreen);
    return 0;
}

