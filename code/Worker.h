//
// Created by 夜林蓝 on 2024/4/9.
//

#ifndef LEARNCPLUSPLUS_WORKER_H
#define LEARNCPLUSPLUS_WORKER_H

#pragma once

#include<string>
#include<iostream>

using namespace std;

class Worker {

public:

    virtual void showInfo() = 0;

    virtual string getDeptInfo() = 0;

    int wId;
    int wDeptId;
    string wName;

};


#endif //LEARNCPLUSPLUS_WORKER_H
