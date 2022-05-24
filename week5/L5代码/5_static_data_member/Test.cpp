//Test.cpp
#include "Test.h"

int Test::count = 0;//定义静态数据成员
Test::Test() { count ++; }
Test::~Test() { count --; }

