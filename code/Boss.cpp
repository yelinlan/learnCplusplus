//
// Created by 夜林蓝 on 2024/4/9.
//

#include "Boss.h"

Boss::Boss(int wId, int wDeptId, const string &wName) {
    this->wId = wId;
    this->wDeptId = wDeptId;
    this->wName = wName;
}

void Boss::showInfo() {
    cout << "wId: " << this->wId << " \twDeptId: " << this->wDeptId << " \twName: " << this->wName
         << " \t岗位职责:管理公司所有事务 " << endl;
}

string Boss::getDeptInfo() {
    return string("总裁");
}
