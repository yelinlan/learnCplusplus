//
// Created by 夜林蓝 on 2024/4/14.
//

#include "SpeechManager.h"

#include <random>
#include <regex>

SpeechManager::SpeechManager() {
    initSpeech();
    createSpeaker();
    loadRecord();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::showMenu() {
    cout << "================================================" << endl;
    cout << "==============    欢迎参加演讲比赛   ===============" << endl;
    cout << "==============    1.开始演讲比赛    ===============" << endl;
    cout << "==============    2.查看往届记欢    ===============" << endl;
    cout << "==============    3.清空比赛记录    ===============" << endl;
    cout << "==============    0.退出比赛程序    ===============" << endl;
    cout << "=================================================" << endl;
    cout << endl;
}

void SpeechManager::start() {
    system("chcp 65001");
    int input;
    do {
        this->showMenu();
        cout << "请输入选项" << endl << ">>";
        cin >> input;
        switch (input) {
            case 1:
                //1.开始演讲比赛
                this->startSpeech();
                break;
            case 2:
                //2.查看往届记欢
                showRecord();
                break;
            case 3:
                //3.清空比赛记录
                clearRecord();
                break;
            case 0:
                //0.退出比赛程序
                exitSystem();
                break;
            default:
                clear();
                break;
        }


    } while (input);
}

void SpeechManager::exitSystem() {
    cout << "欢迎下次使用！" << endl;
    clear();
    exit(0);
}

void SpeechManager::clear() {
    system("pause");
    system("cls");
}

void SpeechManager::initSpeech() {
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m1.clear();
    this->index = 1;

}

void SpeechManager::createSpeaker() {
    string p = "ABCDEFGHIJKL";
    for (int i = 0; i < p.size(); ++i) {
        int no = i + 1001;
        string s;
        s += p[i];
        Speaker speaker;
        speaker.name = s;
        speaker.id = no;
        for (double &e: speaker.score) {
            e = 0;
        }
        this->m1.insert(pair<int, Speaker>(no, speaker));
        this->v1.push_back(no);
    }
}

void SpeechManager::startSpeech() {
    this->v2.clear();
    this->v3.clear();
    this->index = 1;
    //第一轮比赛
    // 1、抽签
    speechDraw();


    //2、比赛
    speechContest();
    //3、显示晋级结果
    showScore();
    this->index++;
    //第二轮比赛
    //1、抽签
    speechDraw();
    //2、比赛
    speechContest();
    //3、显示最终结果
    showScore();
    //4、保存分数
    saveRecord();

}

void SpeechManager::speechDraw() {
    cout << "第【" << this->index << " 】轮比赛选手正在抽签" << endl;
    cout << "----------------------" << endl;
    cout << "抽签后演讲顺序如下:" << endl;
    if (this->index == 1) {
        shuffle(v1.begin(), v1.end(), std::mt19937(std::random_device()()));
        for (const auto &item: v1) {
            cout << item << " ";
        }
        cout << endl;
    } else if (this->index == 2) {
        shuffle(v2.begin(), v2.end(), std::mt19937(std::random_device()()));
        for (const auto &item: v2) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << "----------------------" << endl;
    clear();
}

void SpeechManager::speechContest() {
    cout << "-------------第" << this->index << "轮正式比赛开始:  -------------" << endl;
    multimap<double, int, greater<>> groupScore;//临时容器，保存key分数value选手编号
    vector<int> src;//比赛的人员容器
    src = this->index == 1 ? v1 : v2;

    int num = 0;//记录人员致，6个为1组
    for (const auto &item: src) {
        num++;
        deque<double> d;
        for (int i = 0; i < 10; ++i) {
            d.push_back((rand() % 401 + 600) / 10);
        }
        d.pop_back();
        d.pop_front();
        unsigned long long int ave = accumulate(d.begin(), d.end(), 0) / d.size();
        this->m1[item].score[index - 1] = ave;
        groupScore.insert(pair<double, int>(ave, item));
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次" << endl;
            int count = 0;
            for (const auto &score: groupScore) {
                cout << this->m1[score.second] << endl;
                if ((count++) < 3) {
                    this->index == 1 ? this->v2.push_back(score.second) : this->v3.push_back(score.second);
                }
            }
            groupScore.clear();
        }
    }
    clear();
}

void SpeechManager::showScore() {
    cout << "-------------第" << this->index << "轮晋级选手信息如下:  -------------" << endl;
    vector<int> src;//比赛的人员容器
    src = this->index == 1 ? v2 : v3;
    for (const auto &item: src) {
        cout << this->m1[item] << endl;
    }
    clear();
}

void SpeechManager::saveRecord() {
    fstream f;
    f.open(FILE_NAME, ios::out | ios::app);
    for (const auto &item: v3) {
        f << m1[item];
    }
    f << endl;
    f.close();
}

void SpeechManager::loadRecord() {
    fstream f;
    f.open(FILE_NAME, ios::in);
    if (!f.is_open()) {
        cout << "文件不存在" << endl;
        this->m_FileIsEmpty = true;
        f.close();
        return;
    }

    char ch;
    f >> ch;
    if (f.eof()) {
        cout << "文件为空" << endl;
        this->m_FileIsEmpty = true;
        f.close();
        return;
    }
    this->m_FileIsEmpty = false;

    this->record.clear();

    f.putback(ch);
    string data;
    int index = 1;
    while (getline(f, data)) {
        string s;
        s = s + '\t';
        regex reg(s);
        vector<string> elems(sregex_token_iterator(data.begin(), data.end(), reg, -1), sregex_token_iterator());
        this->record.insert(pair<int, vector<string>>(index++, elems));
    }
    f.close();
}

void SpeechManager::showRecord() {
    loadRecord();
    cout << "-------------往届选手信息如下:  -------------" << endl;
    for (const auto &item: record) {
        cout
                << "第"<< item.first<<"届："
                << "| 冠军编号：" << item.second[0]
                << "  姓名：" << item.second[1]
                << "  得分：" << item.second[2]
                << "| 亚军编号：" << item.second[3]
                << "  姓名：" << item.second[4]
                << "  得分：" << item.second[5]
                << "| 季军编号：" << item.second[6]
                << "  姓名：" << item.second[7]
                << "  得分：" << item.second[8]
                << endl;
    }
    clear();
}

void SpeechManager::clearRecord() {
    int s;
    cout << "确定清空？" << endl;
    cout << "1.确定" << endl;
    cout << "0.返回上一级" << endl;
    cin >> s;
    if (s==1){
        fstream f;
        f.open(FILE_NAME, ios::out | ios::trunc);
        f.close();
        cout << "清空成功！" << endl;
        this->record.clear();
        clear();
    }
}

