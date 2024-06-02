//
// Created by 夜林蓝 on 2024/4/13.
//

#include "S.h"


//调用时编译 会报错
//1.#include<.cpp>
//2..h和.cpp合并到hpp 标记为类模板
//template<class T2, class T>
//void S<T2, T>::showS() {
//    cout << "name:" << this->name << endl;
//}
//
//template<class T2, class T>
//S<T2, T>::S(T2 name) {
//    this->name = name;
//}