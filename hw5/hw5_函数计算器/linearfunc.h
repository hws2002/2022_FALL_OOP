#pragma once

#include "func.h"

class LinearFunc : public Func{
private:
    double _k;
    double _b;
public:
    LinearFunc(double a, double b) : _k(a),_b(b) {};
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个一次函数类
    double getPoint(double point){
        // f(x) = ax + b;
        return _k*point+_b;
    }
};