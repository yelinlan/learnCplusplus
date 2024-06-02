//
// Created by 夜林蓝 on 2024/4/9.
//

#ifndef LEARNCPLUSPLUS_BOSS_H
#define LEARNCPLUSPLUS_BOSS_H

#include "Worker.h"

class Boss:public Worker {
public:

    Boss(int wId, int wDeptId, const string &wName);

    void showInfo() override;

    string getDeptInfo() override ;


};

#endif //LEARNCPLUSPLUS_BOSS_H
