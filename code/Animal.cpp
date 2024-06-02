//
// Created by 夜林蓝 on 2024/4/7.
//

#include "Animal.h"

int Animal::w = 1;

Animal::Animal() {
    cout << "Animal 构造函数" << endl;
}

Animal::~Animal() {
    cout << "Animal 析构函数" << endl;
}

void Animal::fun() {
    cout << "Animal fun" << endl;
}

void Animal::fun1() {
    cout << "Animal fun1 static" << endl;
}
