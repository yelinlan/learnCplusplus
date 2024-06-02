//
// Created by 夜林蓝 on 2024/4/9.
//

#ifndef LEARNCPLUSPLUS_MANAGER_H
#define LEARNCPLUSPLUS_MANAGER_H

#include "Worker.h"

class Manager: public Worker {
public:

    Manager(int wId, int wDeptId, const string &wName);

    void showInfo() override;

    string getDeptInfo() override ;


};

#endif //LEARNCPLUSPLUS_MANAGER_H
