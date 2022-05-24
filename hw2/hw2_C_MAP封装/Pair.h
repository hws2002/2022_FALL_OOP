#pragma once
#include <string>
using namespace std;

class Pair{
    string key;
    int val;
public:
    Pair();
    void reset(string k, int v);
    bool hasKey(string k);
    int & getVal();
    ~Pair();
};