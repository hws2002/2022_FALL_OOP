#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
cout << fixed << 2018.0 << " " << 0.0001 << endl;
				//浮点数 -> 2018.000000 0.000100
cout << scientific << 2018.0 << " " << 0.0001 << endl;
				//科学计数法 -> 2.018000e+03 1.000000e-04
cout << defaultfloat;  //还原默认输出格式
cout << setprecision(2) << 3.1415926 << endl;
				//输出精度设置为2 -> 3.2
cout << oct << 12 << " " << hex << 12 << endl; 
				//八进制输出 -> 14  十六进制输出 -> c
cout << dec;	//还原十进制
cout << setw(3) << setfill(' ') << 5 << endl;
				//设置对齐长度为3，对齐字符为* -> **5
                return 0;
}
