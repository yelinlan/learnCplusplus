//
// Created by 夜林蓝 on 2024/4/7.
//

#include "Cat.h"

Cat::Cat() {
    cout << "Cat 构造函数" << endl;
}

Cat::~Cat() {
    cout << "Cat 析构函数" << endl;
}

void Cat::fun() {
    cout << "Cat fun" << endl;
}

int Cat::w = 2;

void Cat::fun1() {
    cout << "Cat fun1 static" << endl;
}
