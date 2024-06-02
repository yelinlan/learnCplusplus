//
// Created by 夜林蓝 on 2024/4/9.
//

#ifndef LEARNCPLUSPLUS_WORKMANAGER_H
#define LEARNCPLUSPLUS_WORKMANAGER_H

#include<iostream>
#include<fstream>
#include "Worker.h"

using namespace std;

#define FILE_NAME "empFile.txt"

class WorkManager {
public:
    WorkManager();

    void showMenu();

    virtual ~WorkManager();

    void start();

    void exitSystem();

    int empNum;

    Worker **empArr;

    bool m_FileIsEmpty;

    int get_EmpNum();

    void init_Emp();

    void addBatchEmployee();

    void save();

    Worker *buildWorker(int wId, int wDeptId, const string &wName);

    void listEmployee();

    void clear();

    void del_Emp();

    int Is_Exist(int id);

    void modifyEmployee();

    void queryEmployee();

    void searchById();

    void searchByName();

    void sortEmployee();


    void sort(int flag);

    void bubbleSort(int flag);

    static int compare(const void *,const void *);

    void clearEmployee();

    void cleanFile();
};


#endif //LEARNCPLUSPLUS_WORKMANAGER_H
