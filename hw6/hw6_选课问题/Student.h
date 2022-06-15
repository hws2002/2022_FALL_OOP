#pragma once
#include "select.h"
using namespace std;
class Student {
    public :
        int l;
        int r;
        Student() : l(0),r(0) {};
        virtual vector<int> select_class(vector<int> & credit)=0;
        virtual ~Student() {cout<<"Student deleted"<<endl;};     
};

class StudentTypeA : public Student {
    public :
    StudentTypeA() : Student(){};
    vector<int> select_class(vector<int> & credit){
        vector<int> res;
        for(int i=l-1;i<r;i++){
            if (credit[i]<=2) res.push_back(i+1);
        }
        return res;
    }
    ~StudentTypeA(){cout<<"StudentTypeA deleted"<<endl;};
};

class StudentTypeB : public Student {
    public :
    StudentTypeB() : Student(){};

    bool is_prime(int number){
        if (number ==1 ) return false;
        for(int i=2;i*i<=number;i++){
            if (number %i ==0) return false;
        }
        return true;
    };

    vector<int> select_class(vector<int> &credit){
        vector<int> res;
        for(int i=l-1;i<r;i++){
            if(is_prime(i+1)) res.push_back(i+1);
        }
        return res;
    }
    ~StudentTypeB(){cout<<"StudentTypeB deleted"<<endl;};
};

class StudentTypeC : public Student {
    public :
    StudentTypeC() : Student(){};

    vector<int> select_class(vector<int> &credit){
        vector<int> res;
        for(int i=l-1;i<r;i++){
            if((i+1)%credit[i] ==0) res.push_back(i+1);
        }
        return res;
    }
    ~StudentTypeC(){cout<<"StudentTypeC deleted"<<endl;};
};