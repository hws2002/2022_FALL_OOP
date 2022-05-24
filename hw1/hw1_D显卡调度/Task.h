#include <cstring>
class Task{
public:
    int end_time;//끝나는시간
    std::string task_name;// 임무 이름
    int r_cpunum;// 필요한 메모리 갯수
    int r_cpumem;//필요한 메모리 
    int r_time;//필요한 시간
    Task(char * s, int d, int n, int m) {
        task_name = s;
        r_cpunum = n;
        r_cpumem = m;
        r_time = d;
        end_time = 0;
    };
};