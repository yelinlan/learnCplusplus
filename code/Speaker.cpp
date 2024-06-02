//
// Created by 夜林蓝 on 2024/4/14.
//

#include "Speaker.h"

ostream &operator<<(ostream &os, const Speaker &speaker) {
    os << speaker.id << "\t" << speaker.name << "\t"
       << speaker.score[(speaker.score[1] != 0 ? 1 : 0)] << "\t";
    return os;
}
