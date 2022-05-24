#include <iostream> // cout
#include <cstring>  // strcmp
using namespace std;

char week_name[7][4] = {"mon", "tu", "wed",
                        "thu", "fri", "sat", "sun"};

class WeekTemperature
{
    int temperature[7];
    int error_temperature;

public:
    int &operator[](const char *name) // 字符串作下标
    {
        for (int i = 0; i < 7; i++)
        {
            if (strcmp(week_name[i], name) == 0)
                return temperature[i];
        }
        return error_temperature; //没有匹配到字符串
    }
};

int main()
{
    WeekTemperature beijing;
    beijing["mon"] = -3;
    beijing["tu"] = -1;
    //如果返回类型是引用，则数组运算符调用可以出现在等号左边，接受赋值，即
	//Obj[index] = value;
    cout << "Monday Temperature: "
         << beijing["mon"] << endl;


    return 0;
}
