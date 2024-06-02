//
// Created by 夜林蓝 on 2024/4/5.
//

#ifndef LEARNCPLUSPLUS_CUBE_H
#define LEARNCPLUSPLUS_CUBE_H

#include <iostream>

using namespace std;
class Cube {
    friend class Person;
private:
    double l;
public:

    //无参构造器
    Cube() : l(10)//:l(10) 初始化列表 可不要
    {
        cout << __TIME__ << ": No Args Constructor init..." << endl;
    }

//    有参构造
    Cube(double l) {
        Cube::l = l;
        cout << __TIME__ << ": Args  Constructor init..." << endl;
    }

//    拷贝构造函数
    Cube(Cube &c2) {
        Cube::l = c2.l;
        cout << __TIME__ << ": copy  Constructor init..." << endl;
    }

    //销毁器
    virtual ~Cube() {
        cout << __TIME__ << ": destroy..." << endl;
    }

    double area() {
        return 6 * l * l;
    }

    double bulk() {
        return l * l * l;
    }

    bool equals(Cube &c) {
        return Cube::l == c.l;
    }

    void setL(double l) {
        Cube::l = l;
    }

    double getL() const {
        return l;
    }

};

void printCube(Cube cube);

bool equals(Cube &c, Cube &c1);

#endif //LEARNCPLUSPLUS_CUBE_H
