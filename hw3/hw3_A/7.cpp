#include <iostream>
using namespace std;

class Animal{
public:
    // Animal(){};
    Animal(int d){};
    void move(double d) { cout << "Animal move" << d << "km\n"; }
    void eat(double d) { cout << "Animal eat " << d << "g food\n"; }
};

class Bird: public Animal{
public:
    using Animal::move;
    void move() { cout << "Bird move"; }
    void move(int i) { cout << "Bird move" << i << "m\n"; }
};

class Crow : public Bird{
public:
    using Bird::move;
    void move(int i) { cout << "Crow move" << i << "m\n"; }
};

int main() {
    Crow crow;
    crow.move(10);
    crow.move(4.9);
    crow.eat(4.8);
    crow.move();
    return 0;
}

/*
Crow move10m
Animal move4.9km
Animal eat 4.8g food
Bird move%   

14
Crow move10m
Crow move4m
Animal eat 4.8g food
Bird move% 
*/