#include <vector>

using namespace std;
class Server{
public:
    int server_time;
    int CPU_num;
    int CPU_memory;
    int CPU[100];//i번쨰 CPU의 메모리 사용 현황!(얼마만큼 남았는지를 저장해둠)
    vector<Task> tasks;
    vector< vector<int> > task_cpu;//i번째 임무가 사용하고 있는 cpu의 번호를 저장!
    Server(int N, int M) : CPU_num(N), CPU_memory(M){
        fill(CPU,CPU+N+1,M);
        server_time = 0;
    };
    friend class Task;
    void tick(){
        this->server_time++;
        //그 시간 안에 끝난 임무 있는지 확인
        for(int i=0;i<tasks.size();i++){
            if(tasks[i].end_time==this->server_time){//만약start_time+required time<=server_time 
            //CPU 정리하기
                int r_memory = tasks[i].r_cpumem;
                for(int j=0;j<task_cpu[i].size();j++){
                    CPU[task_cpu[i][j]] += r_memory;
                }            
            //임무리스트에서 삭제하기
                tasks.erase(tasks.begin()+i);
                task_cpu.erase(task_cpu.begin()+i);
            }
        }
    };
    bool submit_task(Task task){
        //먼저 이 task가 실행될 수 있는지 여부 확인
        //사용할 cpu 의 번호를 담을 배열!
        int index = tasks.size();
        vector<int> location;
        int memory = task.r_cpumem;
        for(int i=0;i<CPU_num;i++){
            if (CPU[i]>=memory){
                location.push_back(i);
                if(location.size() == task.r_cpunum)
                    break;
            }
        }
        if(location.size()==task.r_cpunum){
            task_cpu.push_back(location);
            for(int i=0;i<location.size();i++){
                CPU[location[i]] -=memory;
            }
            tasks.push_back(task);//tasks는 0부터 의미있음
            tasks.back().end_time = this->server_time+task.r_time;
            return true;
        } else {
            return false;//임무를 실행할 수 있을만큼의 cpu가 존재하지않을때
        }
    };

    bool cancel_task(char * task_name){
        //먼저 이 task가 존재하는지 확인
        std::string target(task_name);
        bool exist = false;
        for(int i=0;i<tasks.size();i++){
            if(tasks[i].task_name == task_name){
                exist = true;
            //CPU메모리 증가
                int memory = tasks[i].r_cpumem;
                for(int j=0;j<task_cpu[i].size();j++){
                    CPU[task_cpu[i][j]] +=memory;
                }
                tasks.erase(tasks.begin()+i); 
                task_cpu.erase(task_cpu.begin()+i);
            }
        }   
        if(exist){//존재하면 canceled 출력
            return true;
        } else {//존재하지않으면
            return false;
        }
    };
};
