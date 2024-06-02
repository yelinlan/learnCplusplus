//
// Created by 夜林蓝 on 2024/4/13.
//

#ifndef LEARNCPLUSPLUS_S_H
#define LEARNCPLUSPLUS_S_H

#include<iostream>

using namespace std;

template<class T>
class P {
};

/**
 * 类模板专用名  .hpp => .h+.cpp
 */
template<class T2, class T>
class S : public P<T> {
public:
    S() {
        cout << "T:" << typeid(T).name() << endl;
        cout << "T2:" << typeid(T2).name() << endl;
    }

    S(T2 name);

    void showS();

    T2 name;
};

template<class T2, class T>
void S<T2, T>::showS() {
    cout << "name:" << this->name << endl;
}

template<class T2, class T>
S<T2, T>::S(T2 name) {
    this->name = name;
}

#endif //LEARNCPLUSPLUS_S_H
