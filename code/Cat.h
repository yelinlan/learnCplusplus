//
// Created by 夜林蓝 on 2024/4/7.
//

#ifndef LEARNCPLUSPLUS_CAT_H
#define LEARNCPLUSPLUS_CAT_H


#include "Animal.h"

//public 继承所有成员（但private 成员会被编译器隐藏，不可访问）。继承后的成员最大获取权限变为public
//protect 继承所有成员（但private 成员会被编译器隐藏，不可访问）。继承后的成员最大获取权限变为protect
//private 继承所有成员（但private 成员会被编译器隐藏，不可访问）。继承后的成员最大获取权限变为private
class Cat : public Animal {

private:
    int like = 2;
public:
    ~Cat() override;

    void fun();

    static void fun1();

    int name = 2;
    static int w;

    Cat();
};


#endif //LEARNCPLUSPLUS_CAT_H
