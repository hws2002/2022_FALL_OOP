#include <iostream>
#include "Task.h"
#include "Server.h"
using namespace std;
int main()
{
    int N;
    int M;
    cin >> N >> M;
    Server server(N, M);
    int o;
    cin >> o;
    int cur_time = 0;
    for(int i = 0; i < o; i++) 
    {
        int t, d, n, m;// t = 임무를 받은 시기, n= 필요한 글카 수
                       // m = 각 글카에서 필요한 메모리 , d = 임무 완료할때까지 필요한 시간
        char o;// submit or cancel
        char s[30];// 임무 이름 
        cin >> t >> o;//받은 시기, 임무종류
        scanf("%s", s);//임무 이름
        for (int j = 0; j < t - cur_time; j++)
            server.tick();//시간이 들어올때마다 server시간을 늘리는거야, 그래서 그 시간만큼 지났을때, 끝난 임무가 있으면 임무 끝내기
        cur_time = t;
        if(o == 's')//submit일때
        {
            cin >> n >> m >> d;//갯수, 메모리, 시간
            Task task(s, d, n, m);
            if(server.submit_task(task)) 
            {
                cout << "Accepted " << s << endl;// 임무실행가능시 ->1
            }
            else
            {
                cout << "Rejected " << s << endl;//실행 불가능시 ->0
            }
        }
        else if(o == 'c') //cancel일때
        {
            if(server.cancel_task(s))
            {
                cout << "Cancelled " << s << endl;//임무가 실행중일때 ->1
            }
            else
            {
                cout << "Not found " << s << endl;//임무가 이미 끝났을때(존재하지 않을때) ->0
            }
        }
        else
        {
            cout << "Invalid operation" << endl; // submit도 아니고 cancel 도 아닐때
        }
    }
    return 0;
}