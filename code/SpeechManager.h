//
// Created by 夜林蓝 on 2024/4/14.
//

#ifndef LEARNCPLUSPLUS_SPEECHMANAGER_H
#define LEARNCPLUSPLUS_SPEECHMANAGER_H

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
#include "Speaker.h"

using namespace std;
#define FILE_NAME "speech.csv"

class SpeechManager {
public:
    SpeechManager();

    virtual ~SpeechManager();

    void showMenu();

    void start();

    void exitSystem();

    void clear();

    void initSpeech();

    void createSpeaker();

    void startSpeech();

    void speechDraw();

    void speechContest();

    void showScore();

    void saveRecord();

    void loadRecord();

    void showRecord();

private:
    //比赛选手容器12人
    vector<int> v1;
    //第一轮晋级容器6人
    vector<int> v2;
    //胜利前三名容器3人
    vector<int> v3;
    //存放编号以及对应的具体选手容器
    map<int, Speaker> m1;
    //记录比赛轮数
    int index;
    bool m_FileIsEmpty;
    map<int, vector<string>> record;

    void clearRecord();
};


#endif //LEARNCPLUSPLUS_SPEECHMANAGER_H
