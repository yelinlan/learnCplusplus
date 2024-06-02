//
// Created by 夜林蓝 on 2024/4/9.
//

#include "Manager.h"

Manager::Manager(int wId, int wDeptId, const string &wName) {
    this->wId = wId;
    this->wDeptId = wDeptId;
    this->wName = wName;
}

void Manager::showInfo() {
    cout << "wId: " << this->wId << " \twDeptId: " << this->wDeptId << " \twName: " << this->wName
         << " \t岗位职责:完成老板交给的任务,并下发任务给员工 " << endl;
}

string Manager::getDeptInfo() {
    return string("经理");
}
