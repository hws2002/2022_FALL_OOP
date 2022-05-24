/*
一家工厂生产飞机、汽车和摩托车。
一架飞机需要三个轮子，和两个机翼；一辆汽车需要四个轮子；一辆摩托车需要两个轮子。
这些交通工具都具有一个run 函数，其中汽车和摩托车调用时输出 “I am running”，但是飞机调用时输出 “I am running and flying”。
编写以下几个类： Plane，Motor，Car，Wing，Wheel，Vehicle(交通工具)，设计合理的继承、组合关系以及使用合理使用函数的继承与重写实现add_wing，add_wheel，finished 以及 run 函数。测试代码见下页：
*/

#include <iostream>

#include "Car.h"
#include "Plane.h"
#include "Motor.h"
#include "Wing.h"
#include "Wheel.h"

int main() {
    int m;
    std::cin >> m;
    Plane planes = new Plane[100];
    Car cars = new Car[100];
    Motor motors = new Motor[100];
    int i_p = 0, i_c = 0, i_m = 0;
    for (int i = 0; i < m; ++i) {
        int op;
        std::cin >> op;
        if (op == 0) {// plane
    		int part;
            std::cin >> part;
            if (part == 0) planes[i_p].add_wing(new Wing());
            else planes[i_p].add_wheel(new Wheel());
            if (planes[i_p].finished()) planes[i_p++].run();
        }
        else if (op == 1) { // car
            cars[i_c].add_wheel(new Wheel());
            if (cars[i_c].finished()) cars[i_c++].run();
        }
        else { // motor
            motors[i_m].add_wheel(new Wheel());
            if (motors[i_m].finished())motors[i_m++].run();
        }
    }
    return 0;
}
/*
输入：
0 0
0 0
0 1
0 1
0 1
1
1
2
2
1
1

输出：
I am running and flying
I am running
I am running

*/