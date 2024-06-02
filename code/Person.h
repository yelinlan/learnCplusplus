//
// Created by 夜林蓝 on 2024/4/7.
//

#ifndef LEARNCPLUSPLUS_PERSON_H
#define LEARNCPLUSPLUS_PERSON_H

#include <iostream>
#include "Cube.h"

using namespace std;

class Person {
    friend void getName(Person &person);

public:
    //修改常函数变量
    mutable int age = 12;

    //const 常函数  ==> const Person const *person;
    int getOneAge() const {
        //不允许修改 除非字段添加mutable 修饰符
        this->age = 10;
        return age;
    }

    double getCubeL();

private:
    int sex = 999;

};

void getName(Person &person);

#endif //LEARNCPLUSPLUS_PERSON_H
