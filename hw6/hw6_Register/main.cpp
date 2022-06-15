#include <iostream>
#include <sstream>
#include <cstring>
#include <regex>
#include <map>
using namespace std;
vector<string> UPE{"username","password","email"};
map<string,string> Info;
int check_type(string temp){
    //앞에 공백먼저 다 없애고, {랑 "도 없애고, 그뒤가 username인지, password인지, email인지판단!
    //근데 문제에서 무조건 3번째부터 나오기때문에, 그/냥 3번쨰 단어부터 판단해도됨!
    if (regex_match (temp,regex("(.*\")(username)(\".*)") ))
        return 0;
    if (regex_match (temp,regex("(.*\")(password)(\".*)") ))
        return 1;
    if (regex_match (temp,regex("(.*\")(email)(\".*)") ))
        return 2;
}

bool check_username(string temp){
    //먼저 : 기준으로 나눈다
    istringstream ss(temp);
    string buff;
    getline(ss,buff, ':');
    getline(ss,buff, ':');
    if(regex_match (buff, regex("(.*\")([a-zA-Z][a-zA-Z_0-9]{3,14}\")(.*)"))) return true;
    else return false;

}
void encrypt_username(string temp){
    istringstream ss(temp);
    string buff;
    getline(ss,buff, ':');
    getline(ss,buff, ':');
    regex re("[a-zA-Z][a-zA-Z_0-9]{3,14}");
    //buff =" \"correct\""
    // string new_name = regex_replace(buff,re,"[a-zA-Z][a-zA-Z_0-9]{2}[*]+");
    smatch username;
    regex_search(buff,username,re);
    // res.push_back(new_name);
    string pre_name = username.str();
    for(int i=3;i<pre_name.size();i++){
        pre_name[i] = '*';
    }
    Info.insert({"username",pre_name});
}

bool check_password(string temp){
    istringstream ss(temp);
    string buff;
    getline(ss,buff, ':');
    getline(ss,buff, ':');
    if(regex_match (buff, regex("(.*\")((?=.*\\d)(?=.*[a-zA-Z])[a-zA-Z0-9]{8,20}\")(.*)"))) return true;
    else return false;
}
void encrypt_password(string temp){
    istringstream ss(temp);
    string buff;
    getline(ss,buff, ':');
    getline(ss,buff, ':');
    regex re("(?=.*\\d)(?=.*[a-zA-Z])[a-zA-Z0-9]{8,20}");
    string new_pass = regex_replace(buff,re,"");
    smatch password;
    regex_search(buff,password,re);
    regex re2("[a-zA-Z0-9]");
    Info.insert({"password",regex_replace(password.str(),re2,"*")});
}

bool check_email(string temp){
    istringstream ss(temp);
    string buff;
    getline(ss,buff, ':');
    getline(ss,buff, ':');
    if(regex_match (buff, regex("(.*\")([a-zA-Z0-9_]+(@)[a-zA-Z0-9_.]+)(\")(.*)"))) return true;
    else return false;
}
void encrypt_email(string temp){
    istringstream ss(temp);
    string buff;
    getline(ss,buff, ':');
    getline(ss,buff, ':');
    regex re("[a-zA-Z0-9_]+(@)[a-zA-Z0-9_.]+");
    smatch email;
    regex_search(buff,email,re);
    // res.push_back(email.str());
    regex re2("[a-zA-Z_0-9]");
    Info.insert({"email",regex_replace(email.str(),re2,"*")});
}
//思路：
/*
먼저 ,를 기주능로 나눈다
{"username" : "Wrongpass"
"password" : "abc"
"email":"example@qq.com"}
이런식으로 나뉘겠지,
그럼 각각 
*/

int main(){
    string source;
    getline(cin,source);
    istringstream ss(source);
    string temp;
    bool can_register = true;
    bool can_Register[3];
    bool can;
    while(getline(ss,temp,',')){
        switch (check_type(temp))
        {
            case 0 :
                {
                can = check_username(temp);
                if(!can) can_register = false;
                else encrypt_username(temp);
                can_Register[0] = can;
                break;
                }
            case 1 :
                {
                can = check_password(temp);
                if(!can) {
                    can_register = false;
                }
                else encrypt_password(temp);
                can_Register[1] = can;
                break;
                }
            case 2 :
                {
                can = check_email(temp);
                if(!can) {
                    can_register = false;
                }
                else encrypt_email(temp);
                can_Register[2] = can;
                break;
                }
            default:
                {
                cout<<"Unknown";
                break;
                }
        }
    }
    if(can_register){
        cout<<"Successfully registered."<<endl;
        cout<<"username: "<<Info["username"]<<endl;
        cout<<"password: "<<Info["password"]<<endl;
        cout<<"email: "<<Info["email"];
    } else {
        bool first_had = false;
        cout<<"Illegal ";
        for(int i=0;i<3;i++){
            if(!can_Register[i]) {
                if (first_had == false) {
                    cout<<UPE[i];
                    first_had = true;
                } else cout<<","<<UPE[i];
            }
        }
    }
    return 0;
}