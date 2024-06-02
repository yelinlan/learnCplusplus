//
// Created by 夜林蓝 on 2024/4/7.
//

#ifndef LEARNCPLUSPLUS_ANIMAL_H
#define LEARNCPLUSPLUS_ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal {

public:
    int name = 1;

    void fun();

    static void fun1();

    static int w;

    virtual ~Animal();

    Animal();

protected:
    int sex = 1;
private:
    int age = 1;

};




#endif //LEARNCPLUSPLUS_ANIMAL_H
