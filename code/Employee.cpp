//
// Created by 夜林蓝 on 2024/4/9.
//

#include "Employee.h"


Employee::Employee(int wId, int wDeptId, const string &wName) {
    this->wId = wId;
    this->wDeptId = wDeptId;
    this->wName = wName;
}

void Employee::showInfo() {
    cout << "wId: " << this->wId << " \twDeptId: " << this->wDeptId << " \twName: " << this->wName
         << " \t岗位职责:完成经理交给的任务 " << endl;
}


string Employee::getDeptInfo() {
    return string("员工");
}
