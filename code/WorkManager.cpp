//
// Created by 夜林蓝 on 2024/4/9.
//

#include "WorkManager.h"
#include "Employee.h"
#include "Boss.h"
#include "Manager.h"

WorkManager::WorkManager() {
    fstream f;
    f.open(FILE_NAME, ios::in);
    if (!f.is_open()) {
        cout << "文件不存在" << endl;
        this->empNum = 0;
        this->empArr = nullptr;
        this->m_FileIsEmpty = true;
        f.close();
        return;
    }

    char ch;
    f >> ch;
    if (f.eof()) {
        cout << "文件为空" << endl;
        this->empNum = 0;
        this->empArr = nullptr;
        this->m_FileIsEmpty = true;
        f.close();
        return;
    }

    this->empNum = this->get_EmpNum();
    cout << "职工人数为：" << this->empNum << endl;
    this->empArr = new Worker *[this->empNum];
    init_Emp();
    f.close();
    return;
}

WorkManager::~WorkManager() {
    if (this->empArr != nullptr) {
        for (int i = 0; i < this->empNum; ++i) {
            if (this->empArr[i] != nullptr) {
                delete empArr[i];
                empArr[i] = nullptr;
            }
        }
        delete[] this->empArr;
        this->empArr = nullptr;
    }
}

void WorkManager::showMenu() {
    cout << "====================================" << endl;
    cout << "===========欢迎使用职工管理系统=========" << endl;
    cout << "===   0.退出管理程序 1.增加职工信息   ===" << endl;
    cout << "===   2.显示职工信息 3.删除离职员工   ===" << endl;
    cout << "===   4.修改职工信息 5.查找职工信息   ===" << endl;
    cout << "===   6.按照编号排序 7.清空所有文档   ===" << endl;
    cout << "====================================" << endl;
}

void WorkManager::start() {

    int input;
    do {
        showMenu();
        cout << "请输入选项" << endl << ">>";
        cin >> input;
        switch (input) {
            case 1:
                //1.增加职工信息
                addBatchEmployee();
                break;
            case 2:
                //2.显示职工信息
                listEmployee();
                break;
            case 3:
                //3.删除离职员工
                del_Emp();
                break;
            case 4:
                //4.修改职工信息
                modifyEmployee();
                break;
            case 5:
                //5.查找职工信息
                queryEmployee();
                break;
            case 6:
                //6.按照编号排序
                sortEmployee();
                break;
            case 7:
                //7.清空所有文档
                clearEmployee();
                break;
            case 0:
                //0.退出管理程序
                exitSystem();
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;
        }


    } while (input);
}

void WorkManager::exitSystem() {
    cout << "退出管理程序..." << endl;
    exit(0);
}

void WorkManager::addBatchEmployee() {
    cout << "请输入添加职工的数量：" << endl << ">>";
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->empNum + addNum;
        Worker **pWorker = new Worker *[newSize];

        if (this->empArr != NULL) {
            for (int i = 0; i < this->empNum; ++i) {
                pWorker[i] = this->empArr[i];
            }

        }

        for (int i = 0; i < addNum; ++i) {
            int wId;
            int wDeptId;
            string wName;
            while (true) {
                cout << "请输入第" << i + 1 << "个新员工编号：" << endl << ">>";
                cin >> wId;
                if (Is_Exist(wId) == -1) {
                    break;
                } else {
                    cout << "员工编号重复！" << endl;
                }
            }
            cout << "请输入第" << i + 1 << "个新员工姓名：" << endl << ">>";
            cin >> wName;
            cout << "请选择该职工岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> wDeptId;
            pWorker[this->empNum + i] = buildWorker(wId, wDeptId, wName);
        }
        delete this->empArr;
        this->empArr = pWorker;
        this->empNum = newSize;
        cout << "成功添加" << addNum << "个新员工" << endl;
        this->save();
    } else {
        cout << "输入数据有误！" << endl;
    }
    this->clear();
}

void WorkManager::clear() {
    system("chcp 65001");
    system("pause");
    system("cls");
}

Worker *WorkManager::buildWorker(int wId, int wDeptId, const string &wName) {
    Worker *worker = NULL;
    switch (wDeptId) {
        case 1:
            worker = new Employee(wId, wDeptId, wName);
            break;
        case 2:
            worker = new Manager(wId, wDeptId, wName);
            break;
        case 3:
            worker = new Boss(wId, wDeptId, wName);
            break;
        default:
            break;
    }
    return worker;
}

void WorkManager::save() {
    fstream f;
    f.open(FILE_NAME, ios::out);
    for (int i = 0; i < this->empNum; ++i) {
        f << this->empArr[i]->wId << "\t"
          << this->empArr[i]->wName << "\t"
          << this->empArr[i]->wDeptId << endl;
    }
    f.close();
}

int WorkManager::get_EmpNum() {
    fstream f;
    f.open(FILE_NAME, ios::in);
    int wId;
    int wDeptId;
    string wName;
    int num = 0;
    while (f >> wId && f >> wName && f >> wDeptId) {
        num++;
    }
    f.close();
    return num;
}

void WorkManager::init_Emp() {
    fstream f;
    f.open(FILE_NAME, ios::in);
    int wId;
    int wDeptId;
    string wName;
    int i = 0;
    while (f >> wId && f >> wName && f >> wDeptId) {
        this->empArr[i++] = buildWorker(wId, wDeptId, wName);
    }
    f.close();
}

void WorkManager::listEmployee() {
    cout << "wId    \twDeptId    \twName     \t岗位职责            " << endl;
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        for (int i = 0; i < this->empNum; ++i) {
            this->empArr[i]->showInfo();
        }
    }
    this->clear();
}

void WorkManager::del_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "操作失败！职工数据为空！" << endl;
        return;
    }
    int id;
    cout << "输入删除的职工号：" << endl << ">>";
    cin >> id;
    int index = this->Is_Exist(id);
    if (index == -1) {
        cout << "删除的职工号【" << id << "】不存在！" << endl;
    } else {
        Worker *pWorker = this->empArr[index];
        for (int i = index; i < this->empNum - 1; ++i) {
            this->empArr[i] = this->empArr[i + 1];
        }
        delete pWorker;
        pWorker = NULL;
        this->empNum--;
        this->save();
        cout << "【" << id << "】号职工删除成功！" << endl;
    }
    this->clear();
}

int WorkManager::Is_Exist(int id) {
    for (int i = 0; i < this->empNum; ++i) {
        if (this->empArr[i]->wId == id) {
            return i;
        }
    }
    return -1;
}

void WorkManager::modifyEmployee() {

    if (this->m_FileIsEmpty) {
        cout << "操作失败！职工数据为空！" << endl;
        return;
    }

    int id;
    cout << "输入修改的职工号：" << endl << ">>";
    cin >> id;
    int index = this->Is_Exist(id);
    if (index == -1) {
        cout << "修改的的职工号【" << id << "】不存在！" << endl;
    } else {
        delete this->empArr[index];

        int wId = id;
        int wDeptId;
        string wName;
        cout << "请输入员工姓名：" << endl << ">>";
        cin >> wName;
        cout << "请选择职工岗位：" << endl;
        cout << "1.普通职工" << endl;
        cout << "2.经理" << endl;
        cout << "3.老板" << endl;
        cin >> wDeptId;

        this->empArr[index] = buildWorker(wId, wDeptId, wName);
        this->save();
        cout << "【" << id << "】号职工修改成功！" << endl;
    }
    this->clear();
}

void WorkManager::queryEmployee() {
    if (this->m_FileIsEmpty) {
        cout << "操作失败！职工数据为空！" << endl;
        return;
    }
    int s;
    while (true) {
        cout << "请选择查找方式：" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按职工姓名查找" << endl;
        cout << "0.返回上一级" << endl;
        cin >> s;
        switch (s) {
            case 1:
                searchById();
                break;
            case 2:
                searchByName();
                break;
            default:
                break;
        }
        if (s == 0) {
            break;
        }
        clear();
    }
}

void WorkManager::searchById() {
    int s;
    cout << "请输入职工编号：" << endl << ">>";
    cin >> s;
    cout << "结果如下：" << endl;
    for (int i = 0; i < this->empNum; ++i) {
        if (this->empArr[i]->wId == s) {
            this->empArr[i]->showInfo();
        }
    }
}

void WorkManager::searchByName() {
    string s;
    cout << "请输入职工编号：" << endl << ">>";
    cin >> s;
    cout << "结果如下：" << endl;
    for (int i = 0; i < this->empNum; ++i) {
        if (this->empArr[i]->wName.find(s) != string::npos) {
            this->empArr[i]->showInfo();
        }
    }
}

void WorkManager::sortEmployee() {
    if (this->m_FileIsEmpty) {
        cout << "操作失败！职工数据为空！" << endl;
        return;
    }
    int s;
    while (true) {
        cout << "请选择排序方式：" << endl;
        cout << "1.升序" << endl;
        cout << "2.降序" << endl;
        cout << "0.返回上一级" << endl;
        cin >> s;
        switch (s) {
            case 1:
                sort(1);
                break;
            case 2:
                sort(2);
                break;
            default:
                break;
        }
        if (s == 0) {
            break;
        }
    }
    clear();
}

void WorkManager::sort(int flag) {

    //qsort(this->empArr, this->empNum, sizeof(this->empArr[0]), compare);
    sort(flag);
    this->save();
    listEmployee();
}

int WorkManager::compare(const void *a, const void *b) {

    Worker *p = *(Worker **) a;
    Worker *q = *(Worker **) b;
    return -(p->wId - q->wId);

}

void WorkManager::bubbleSort(int flag) {
    for (int i = 0; i < empNum - 1; ++i) {
        for (int j = 0; j < empNum - i - 1; ++j) {
            if (flag == 1 ? empArr[j]->wId > empArr[j + 1]->wId : empArr[j]->wId < empArr[j + 1]->wId) {
                Worker *temp = empArr[j];
                empArr[j] = empArr[j + 1];
                empArr[j + 1] = temp;
            }
        }
    }
}

void WorkManager::clearEmployee() {
    int s;
    cout << "确定清空？" << endl;
    cout << "1.确定" << endl;
    cout << "0.返回上一级" << endl;
    cin >> s;
    switch (s) {
        case 1:
            cleanFile();
            break;
        default:
            break;
    }
    clear();
}

void WorkManager::cleanFile() {
//    ofstream f(FILE_NAME, ios::trunc);
//    f.close();
    fstream f;
    f.open(FILE_NAME, ios::out|ios::trunc);
    f.close();
    if (this->empArr != nullptr) {
        for (int i = 0; i < this->empNum; ++i) {
            if (this->empArr[i] != nullptr) {
                delete empArr[i];
                empArr[i] = nullptr;
            }
        }
        delete[] this->empArr;
        this->empArr = nullptr;
        this->empNum = 0;
        this->m_FileIsEmpty = true;
    }
    cout << "清空成功！" << endl;
}
