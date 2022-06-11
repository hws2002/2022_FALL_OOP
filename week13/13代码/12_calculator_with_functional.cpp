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
void process(
        function<string()> read,
        function<string(string)> calculate,
        function<void(string)> write)
{
    string data = read();
    string output = calculate(data);
    write(output);
}
string calculateAdd(string x)
{
    return x;
}
void writeToScreen(string x)
{
    cout << x;
}
int main()
{
    process(readFromScreen, calculateAdd, writeToScreen);
    process(ReadFromFile(), calculateAdd, writeToScreen);
    return 0;
}

