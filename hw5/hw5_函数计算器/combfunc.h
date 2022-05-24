#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    // Todo
    // 声明成员变量
    Func * fx;
    Func * gx;
    double _a;
    double _b;
public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2) : fx(fun_1),gx(fun_2),_a(coe_1),_b(coe_2){
    };
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个组合函数类
    double getPoint(double point){
        return _a * fx->getPoint(point) + _b * gx->getPoint(point);
    }
    // 并且要求，传入的参数的析构在该类被析构时同时析构
    ~CombFunc(){
        if (fx) delete fx;
        if (gx) delete gx;
    };
};