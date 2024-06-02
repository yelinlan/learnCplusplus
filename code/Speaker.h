//
// Created by 夜林蓝 on 2024/4/14.
//

#ifndef LEARNCPLUSPLUS_SPEAKER_H
#define LEARNCPLUSPLUS_SPEAKER_H

#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <set>
#include <map>
#include <functional>

using namespace std;

class Speaker {
public:
    int id;
    string name;
    double score[2];

    friend ostream &operator<<(ostream &os, const Speaker &speaker);


};


#endif //LEARNCPLUSPLUS_SPEAKER_H
