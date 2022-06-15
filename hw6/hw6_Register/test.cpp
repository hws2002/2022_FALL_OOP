#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string source;//다음과 같은 string이 있다고하자.
    getline(cin,source);
    istringstream ss(source);//istringstream ss 변수에 string 변수 as로 초기화한다.
    string buff;
    while (getline(ss, buff, ' '))//ss stream 변수에서 ' '(공백)까지 입력으로 받아들인다.
    {
        // getline으로 읽어들인 값을 buff에 저장해 출력한다.
        switch ((buff=="Muzi")){
            case 0:
                cout<<"hello"<<endl;
                break;
            case 1:
                cout<<"Muzi"<<endl;
        }
    }
    cout<<"end";
    return 0;
}