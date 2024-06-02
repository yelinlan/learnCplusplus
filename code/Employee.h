//
// Created by 夜林蓝 on 2024/4/9.
//

#ifndef LEARNCPLUSPLUS_EMPLOYEE_H
#define LEARNCPLUSPLUS_EMPLOYEE_H


#include "Worker.h"

class Employee: public Worker {
public:

    Employee(int wId, int wDeptId, const string &wName);

    void showInfo() override;

    string getDeptInfo() override ;


};


#endif //LEARNCPLUSPLUS_EMPLOYEE_H
