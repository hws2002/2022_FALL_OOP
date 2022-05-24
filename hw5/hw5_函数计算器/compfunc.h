#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    // Todo
    // 声明成员变量
    Func * Fx;
    Func * gx;
public:
    CompFunc(Func *outer, Func* inner): Fx(outer),gx(inner) {}
    // compute f(g(x))
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个复合函数类
    double getPoint(double point){
        return Fx->getPoint(gx->getPoint(point));
    }
    // 并且要求，传入的参数的析构在该类被析构时同时析构
    ~CompFunc(){
        if(Fx) delete Fx;
        if(gx) delete gx;
    }   
};