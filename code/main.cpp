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
#include "Circle.h"
#include "Cube.h"
#include "Person.h"
#include "Integer.h"
#include "Cat.h"
#include "AbstractCalculator.h"
#include "WorkManager.h"
#include "S.hpp"
#include "MyArray.hpp"
#include "SpeechManager.h"
#include <functional>

using namespace std;

#define PRINT(VALUE)\
 cout<<#VALUE<<" \t===>\t "<<VALUE<<endl;

template<class INT = int, class STRING = string, class DOUBLE = double>
class user {
public:
    INT id{};
    STRING name;
    INT sex{};
    DOUBLE first = 0;
    DOUBLE second = 0;


    user() {}

    user(INT id, STRING name, INT sex) {
        this->id = id;
        this->name = name;
        this->sex = sex;
    }


    friend ostream &operator<<(ostream &os, const user &user) {
        os << "id: " << user.id << " name: " << user.name << " sex: " << user.sex << " first_score: " << user.first
           << " second_score: " << user.second << endl;
        return os;
    }

    bool operator<(const user &rhs) const {
        return id < rhs.id;
    }

    bool operator>(const user &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const user &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const user &rhs) const {
        return !(*this < rhs);
    }

    bool operator()(user a, user b) const {
        return a > b;
    }

};

class MyCompare {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

class SpeechCompare {
public:
    bool operator()(const user<int, string> a, const user<int, string> b) const {
        return (a.second == 0 && a.second == b.second) ? a.first > b.first : a.second > b.second;
    }
};


void hello();

void printstr();

void printstring();

void sizeofType();

void newint();

void newintarr();

void alias();

void myswap0(int a, int b);

void myswap1(int *a, int *b);

void myswap2(int &a, int &b);

void myswaptest();

int &local();

void leftValue();

long getVal(const int &a);

void constalias();

int sum(int a, int b = 0, int c = 0);

void defaultFun();

void testCircle();

void testCube1();

void testCube2();

void testCube3();

void testNullPointerSize();

void testConstFun();

void testFriendFUn();

void testFriendClass();

void testOverload();

void testExtends();

void testSameInvoke();

void testNoVirtual();

void testVirtual();

void testOut();

void testFileOutAppend();

void testFileInLine();

void testFileInChar();

void testFileInBufferString();

void testFileOutBinary();

void testFileInBinary();

void testEms();

void testWorkManager();

template<class T>
void sortChoice(T &a, int len);

template<class T>
void mySwap(T &a, T &b);

void testTemplateSort();

void testTemplateExtends();

void testTemplateExternMethod();

void testMyArrayInt();

void testMyArrayUser();

void testVectorInt();

int testVectorUser();

void testVectorMatrix();

void testStringConstructor();

void testStringAssign();

void testStringAppend();

void testStringMethod();

template<class T>
void printVector(vector<T> &v);

void testVectorDeque();

void testSet();

void testSetUsr();

void testMap();

void testMapVectorMultiMap();

void testSpeech();

int main() {
    SpeechManager speechManager;
    speechManager.start();
    return 0;
}

void testSpeech() {//组数
    int g = 2;
    int num = 12;
    int p = 10;
    int first_up = 3;

    //1. 12人参加
    cout << num << "位选手分别为：" << endl;
    vector<user<int, string>> v;
    for (int i = 1; i <= num; ++i) {
        int val = 1000 + i;
        cout << val << " ";
        v.push_back({1000 + i, "usr_" + to_string(val), val});
    }
    cout << "" << endl;

    //分组 ls
    shuffle(v.begin(), v.end(), mt19937(random_device()()));
    map<int, vector<user<int, string>>> ls;
    int step = v.size() / g;
    for (int i = 0; i < g; ++i) {
        vector<user<int, string>> v1;
        v1.reserve(step);
        for (int j = 0; j < step; ++j) {
            v1.push_back(v[j + i * step]);
        }
        ls.insert(pair<int, vector<user<int, string>>>(i + 1, v1));
    }

    //分组后结果
    for (const auto &item: ls) {
        cout << "=========第" << item.first << "组选手：==========" << endl;
        for (const auto &usr: item.second) {
            cout << usr.id << " ";
        }
        cout << "" << endl;
    }

    //打分
    cout << "=============================第一轮===============================" << endl;
    //生成0到9之间（包含）均匀分布的随机数
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e;//生成一个无符号随机整数
    for (auto &item: ls) {
        cout << "=========第" << item.first << "组选手成绩为：==========" << endl;
        for (auto &usr: item.second) {
            cout << "第" << usr.id << "位选手: " << usr;
            deque<int> score;
            for (int i = 0; i < p; ++i) {
                score.push_back(u(e));
                cout << score[i] << " ";
            }
            //7  8 6  1  7
            cout << "" << endl;
            sort(score.begin(), score.end());
            cout << "去掉一个最低分：" << score[0] << endl;
            cout << "去掉一个最高分：" << score[score.size() - 1] << endl;
            score.erase(score.begin());
            score.erase(score.end());
            cout << "有效总分： " << accumulate(score.begin(), score.end(), 0) << endl;
            cout << "有效评委数：： " << score.size() << endl;
            usr.first = accumulate(score.begin(), score.end(), 0.0) / score.size();
            cout << "最后得分：" << usr.first << "分" << endl << endl;
        }
    }

    //淘汰每组后三名
    vector<user<int, string>> v2;
    cout << "===================================晋级名单==================================" << endl;
    for (auto &item: ls) {
        cout << "=========第" << item.first << "组选手：==========" << endl;
        vector<user<int, string>> &second = item.second;
        sort(second.begin(), second.end(), SpeechCompare());
        int count = 0;
        for (auto &usr: second) {
            if (count < first_up) {
                cout << "第" << usr.id << "位选手: " << usr;
                count++;
                v2.push_back(usr);
            }
        }
    }


    //打分
    cout << "" << endl;
    cout << "=============================第二轮===============================" << endl;
    for (auto &usr: v2) {
        cout << "第" << usr.id << "位选手: " << usr;
        deque<int> score;
        for (int i = 0; i < p; ++i) {
            score.push_back(u(e));
            cout << score[i] << " ";
        }
        //7  8 6  1  7
        cout << "" << endl;
        sort(score.begin(), score.end());
        cout << "去掉一个最低分：" << score[0] << endl;
        cout << "去掉一个最高分：" << score[score.size() - 1] << endl;
        score.erase(score.begin());
        score.erase(score.end());
        cout << "有效总分： " << accumulate(score.begin(), score.end(), 0) << endl;
        cout << "有效评委数：： " << score.size() << endl;
        usr.second = accumulate(score.begin(), score.end(), 0.0) / score.size();
        cout << "最后得分：" << usr.second << "分" << endl << endl;
    }


    //最终选手
    cout << "===================================前三名==================================" << endl;
    int count = 0;
    sort(v2.begin(), v2.end(), SpeechCompare());
    for (auto &usr: v2) {
        if (count < first_up) {
            cout << "第" << usr.id << "位选手: " << usr;
            count++;
            v2.push_back(usr);
        }
    }
}

void testMapVectorMultiMap() {
    string p = "ABCDEFGHIJ";
    vector<user<int, string>> v;
    for (int i = 0; i < 10; ++i) {
        string s;
        s += p.at(i);
        v.push_back({i, s, i});
    }

    map<int, string> deptMap;
    string dept[] = {"策划", "美术", "研发"};
    for (int i = 0; i < 3; ++i) {
        deptMap.insert(pair<int, string>(i, dept[i]));
    }

    uniform_int_distribution<unsigned> u(0, 2);
    default_random_engine e;//生成一个无符号随机整数
    multimap<int, user<int, string>> mm;
    for (const auto &item: v) {
        mm.insert(pair<int, user<int, string>>(u(e), item));
    }

    int flag = -1;
    for (const auto &item: mm) {
        if (item.first != flag) {
            cout << "===============" << deptMap[item.first] << "================" << endl;
            flag = item.first;
        }
        cout << "dept: " << deptMap[item.first] << "  usr:  " << item.second << endl;
    }
}

void testMap() {
    map<int, string, MyCompare> m;
    for (int i = 0; i < 20; ++i) {
        m.insert(pair<int, string>(i, "zs"));
    }
    for (const auto &item: m) {
        cout << "key:" << item.first << "  value: " << item.second << endl;
    }
}

void testSetUsr() {
    set<user<int, string>, user<int, string>> s;
    for (int i = 0; i < 20; ++i) {
        s.insert({i, "ls", i});
    }
    for (const auto &item: s) {
        cout << item << " ";
    }
}

void testSet() {
    set<int, MyCompare> s;
    for (int i = 0; i < 20; ++i) {
        s.insert(i);
    }
    for (const auto &item: s) {
        cout << item << " ";
    }
}

void testVectorDeque() {
    string name[] = {"zs", "ls", "ww", "zl", "lq"};
    vector<user<int, string>> v;
    v.reserve(5);
    for (int i = 0; i < 5; ++i) {
        v.push_back({i + 1, name[i], 1});
    }

    //生成0到9之间（包含）均匀分布的随机数
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e;//生成一个无符号随机整数
    for (const auto &usr: v) {
        cout << "第" << usr.id << "位选手: " << usr;
        deque<int> score;
        for (int i = 0; i < 10; ++i) {
            //将u作为随机数源，每个调用返回在指定范围内并服从均与分布的值
            score.push_back(u(e));
            cout << score[i] << " ";
        }
        cout << "" << endl;
        sort(score.begin(), score.end());
        cout << "去掉一个最低分：" << score[0] << endl;
        cout << "去掉一个最高分：" << score[score.size() - 1] << endl;
        score.erase(score.begin());
        score.erase(score.end());
        double average = 0;
        for (int i: score) {
            average += i;
        }
        cout << "  最后得分：" << average / score.size() << "分" << endl << endl;
    }
}

void testVectorMatrix() {
    vector<vector<user<int, string>>> v;
    v.reserve(20);
    for (int i = 0; i < 20; ++i) {
        vector<user<int, string>> v1(20, {1, "a", 1});
        v.emplace_back(v1);
    }
    for (const vector<user<int, string>> &v1: v) {
        for (const user<int, string> &user: v1) {
            cout << user << endl;
        }
    }
}

int testVectorUser() {
    vector<user<int, string>> v(20, {1, "a", 1});
    printVector(v);
    return 0;
}

void testVectorInt() {
    vector<int> v(20, 100);
    printVector(v);
}

template<class T>
void printVector(vector<T> &v) {
    for (const auto &item: v) {
        cout << item << " ";
    }
}

void testStringMethod() {
    string s1 = "123456123456";
    string s2 = "123456123456";
    PRINT(s1.find("34", 0));
    PRINT(s1.rfind("34", s1.size()));
    PRINT(s1.replace(3, 6, "***"));
    PRINT(s1.compare(s2));
    PRINT(s1[1]);
    s1[1] = 'X';
    PRINT(s1.at(1));
    PRINT(s1.insert(2, "MMM"));
    PRINT(s1.erase(2, 3));
    PRINT(s1.substr(s1.size() - 3, 3))
}

void testStringAppend() {
    char *ch = "123";
    string s1;
    s1 += ch;
    PRINT(s1);
    s1 += '4';
    PRINT(s1);
    s1 += "56";
    PRINT(s1);
    s1.append("78");
    PRINT(s1);
    s1.append(ch);
    PRINT(s1);
    s1.append(ch, 1);
    PRINT(s1);
    s1.append("abc", 2, 3);
    PRINT(s1);
}

void testStringAssign() {//赋值=
    char *ch = "123";
    string s1;
    s1 = ch;
    string s2;
    s2 = "456";
    string s3;
    s3 = 'a';
    PRINT(s1);
    PRINT(s2);
    PRINT(s3);
    //赋值assign
    string s4;
    s4.assign(ch);
    string s5;
    s5.assign(ch, 2);
    string s6;
    s6.assign("apple");
    string s7;
    s7.assign(4, 'd');
    PRINT(s4);
    PRINT(s5);
    PRINT(s6);
    PRINT(s7);
}

void testStringConstructor() {//构造
    char *ch = "123";
    string s0();
    string s1(ch);
    string s2("456");
    string s3(3, 'a');
    cout << "" << endl;
    PRINT(s0);
    PRINT(s1);
    PRINT(s2);
    PRINT(s3);
}

void testMyArrayUser() {
    MyArray<user<int, string>> arr(3);
    for (int i = 0; i < 3; ++i) {
        arr.add({i, "a", i});
    }
    cout << arr << endl;
    arr.remove();
    cout << arr << endl;
    cout << "大小：" << arr.getSize() << " ，容量：" << arr.getCapacity() << endl;
    cout << arr[1] << endl;
    cout << arr[5] << endl;
}

void testMyArrayInt() {
    MyArray<int> arr(3);
    for (int i = 0; i < 3; ++i) {
        arr.add(i);
    }
    cout << arr << endl;
    arr.remove();
    cout << arr << endl;
    cout << "大小：" << arr.getSize() << " ，容量：" << arr.getCapacity() << endl;
    cout << arr[1] << endl;
    cout << arr[5] << endl;
}

void testTemplateExternMethod() {
    S<double, long> s(123);
    s.showS();
}

void testTemplateExtends() { S<double, long> s; }

void testTemplateSort() {
//    int a[] = {1, 4, 3, 5, 6, 2, 7};
//    int len = sizeof(a) / sizeof(a[0]);
//    char a[] = {'a', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
//    char len = sizeof(a) / sizeof(a[0]);

//
//    user<> a[] = {{2, "a", 0},
//                             {3, "a", 0},
//                             {1, "a", 0},
//                             {4, "a", 0}};
    user<int, string> a[] = {{2, "a", 0},
                             {3, "a", 0},
                             {1, "a", 0},
                             {4, "a", 0}};
    char len = sizeof(a) / sizeof(a[0]);
    sortChoice(a, len);
    for (int i = 0; i < len; ++i) {
        cout << a[i] << "" << endl;
    }
}

template<class T>
void sortChoice(T &a, int len) {
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (a[max] > a[j]) {
                max = j;
            }
        }
        if (max != i) {
            mySwap(a[max], a[i]);
        }
    }
}

template<class T>
void mySwap(T &a, T &b) {
    T temp = b;
    b = a;
    a = temp;
}


void testWorkManager() {
    WorkManager workManager;
    workManager.start();
}


void testFileInBinary() {
    fstream f;
    f.open("./user.txt", ios::in | ios::binary);
    if (!f.is_open()) {
        cout << "文件打开失败" << endl;
    }
    user<int, string> usr;
    f.read((char *) &usr, sizeof(usr));
    cout << usr.id << usr.name << usr.sex << endl;
    f.close();
}

void testFileOutBinary() {
    fstream f;
    user usr = {1, "张三", 1};
    f.open("./user.txt", ios::out | ios::binary);
    f.write((char *) &usr, sizeof(usr));
    f.close();
}

void testFileInBufferString() {
    fstream f;
    f.open("./out.txt", ios::in);
    if (!f.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    char a[1024] = {0};
    while (f.getline(a, sizeof(a))) {
        cout << a << endl;
    }
    f.close();
}

void testFileInChar() {
    fstream f;
    f.open("./out.txt", ios::in);
    char a;
    while ((a = f.get()) != EOF) {
        cout << a << endl;
    }
    f.close();
}

void testFileInLine() {
    fstream f;
    f.open("./out.txt", ios::in);
    string a;
    while (getline(f, a)) {
        cout << a << endl;
    }
    f.close();
}

void testFileOutAppend() {
    fstream f;
    f.open("./out.txt", ios::app);
    f << "你好！" << endl;
    f << "你好！" << endl;
    f << "你好！" << endl;
    f << "你好！" << endl;
    f << "你好！" << endl;
    f.close();
}

void testFileOut() {
    fstream f;
    f.open("./out.txt", ios::out);
    f << "你好！";
    f.close();
}

void testVirtual() {
    AbstractCalculator *cal = new AddCalculator();
    cal->a = 9;
    cal->b = 3;
    cout << cal->cal() << endl;
    cal = new SubCalculator();
    cal->a = 9;
    cal->b = 3;
    cout << cal->cal() << endl;
    cal = new MultiplyCalculator();
    cal->a = 9;
    cal->b = 3;
    cout << cal->cal() << endl;
    cal = new DivideCalculator();
    cal->a = 9;
    cal->b = 3;
    cout << cal->cal() << endl;
}

//cal方法没有virtual修饰时，只会调用父类本来的方法，无法实现上转型。多态
void testNoVirtual() {
    AbstractCalculator *cal = new AddCalculator();
    cal->a = 9;
    cal->b = 3;
    cout << cal->cal() << endl;
}

void testSameInvoke() {//multiple definition of  ERROR:把变量或者方法放到cpp里
    Cat cat;
    //变量
    cout << cat.name << endl;
    cout << cat.Animal::name << endl;
    //方法
    cat.fun();
    cat.Animal::fun();
    //static变量
    cout << Cat::w << endl;
    cout << Animal::w << endl;
    //static方法
    Cat::fun1();
    //第一个冒号：调用静态成员
    //第二个冒号：调用Animal作用域下的成员
    Cat::Animal::fun1();
}

void testExtends() {
    Cat cat;
    //Animal 构造函数
//Cat 构造函数
//Cat 析构函数
//Animal 析构函数

}

void testOverload() {
    Integer a = Integer(1);
    Integer b = Integer(2);
    Integer c = Integer(2);
    Integer d = Integer(3);
    cout << ++(--a) << endl;
    cout << ++(++a) << endl;
    cout << --(--a) << endl;
    cout << a-- << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << (b == c) << endl;
    cout << (d >= b) << endl;
    a("我是仿函数");
}

void testFriendClass() {//友元类
    Person person;
    cout << person.getCubeL() << endl;
}

void testFriendFUn() {//全局友元函数
    Person person;
    getName(person);
}

void testConstFun() {
    Person person;
    cout << person.getOneAge() << endl;
}

void testNullPointerSize() {
    Person p;
    cout << sizeof(p) << endl;
}

void testCube3() {
    Cube cube = Cube(10);
    printCube(cube);
}


void testCube2() {//括号法
    Cube c1;
    c1.setL(3);
    Cube c2(4);
    Cube c3(c2);
    //下面会被认为是函数声明
//Cube c4();

    //显示法
    Cube c5 = Cube();
    c5.setL(3);
    Cube c6 = Cube(4);
    Cube c7 = Cube(c6);
    //Cube(4) 匿名对象 执行完立即销毁
//以下构造器 等价于Cube c5声明了变量。
//Cube(c5);

    //隐式法
    Cube c8 = 4;
    Cube c9 = c8;
}

void testCube1() {
    Cube c1;
    c1.setL(3);
    cout << c1.area() << endl;
    cout << c1.bulk() << endl;
    Cube c2;
    c2.setL(3);
    cout << c2.area() << endl;
    cout << c2.bulk() << endl;
    cout << c1.equals(c2) << endl;
    cout << equals(c1, c2) << endl;
}

void testCircle() {//结构体默认public
//    class默认private
    Circle circle;
    circle.r = 2;
    cout << "圆的周长是：" << circle.c() << endl;
}

//默认参数
void defaultFun() {
    cout << sum(1) << endl;
    cout << sum(1, 2) << endl;
    cout << sum(1, 2, 3) << endl;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

//常量不可更改
void constalias() {
    int a = 22;
    cout << getVal(a) << endl;
}

long getVal(const int &a) {
    return a;
}

void leftValue() {
    int &a = local();
    cout << a << endl;
    local() = 99;
    cout << a << endl;
}

int &local() {
    int static a = 100;
    return a;
}

void myswaptest() {
    int a = 1;
    int b = 2;
    //值传递
    myswap0(a, b);
    cout << " a= " << a << "; b= " << b << endl;
    //地址传递
    myswap1(&a, &b);
    cout << " a= " << a << "; b= " << b << endl;
//    引用传递
    myswap2(a, b);
    cout << " a= " << a << "; b= " << b << endl;
}

void myswap2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void myswap1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void myswap0(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

//引用（指针常量） 取别名
void alias() {
    int a = 199;
    int &b = a;
    cout << b << endl;

    //等价于  如下代码
    //int a = 199;
    //int const * b = &a;
    //cout << *b << endl;
}

void newintarr() {
    int *p = new int[10];
    for (int i = 0; i < 10; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        cout << p[i] << endl;
    }
    delete[] p;
}

void newint() {
    int *p = new int(10);
    cout << *p << endl;
    cout << *p << endl;
    //释放空间
    delete p;
    //野指针
    cout << *p << endl;
    cout << *p << endl;
}

void sizeofType() {
    cout << "short 类型所占内存空间为： " << sizeof(short) << endl;
    cout << "int 类型所占内存空间为： " << sizeof(int) << endl;
    cout << "long 类型所占内存空间为： " << sizeof(long) << endl;
    cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;
    float f1 = 3.14f;
    double d1 = 3.14;
    cout << f1 << endl;
    cout << d1 << endl;
    cout << "float  sizeof = " << sizeof(f1) << endl;
    cout << "double sizeof = " << sizeof(d1) << endl;
    //科学计数法
    float f2 = 3e2; // 3 * 10 ^ 2
    cout << "f2 = " << f2 << endl;
    float f3 = 3e-2;  // 3 * 0.1 ^ 2
    cout << "f3 = " << f3 << endl;
    char ch = 'a';
    cout << ch << endl;
    cout << sizeof(char) << endl;
    bool flag = true;
    cout << flag << endl; // 1
    flag = false;
    cout << flag << endl; // 0
    cout << "size of bool = " << sizeof(bool) << endl; //1
}

void printstring() {
    string p = "hello world!";
    cout << p << endl;
}

void printstr() {
    char p[] = "hello world!";
    cout << p << endl;
}

void hello() {
    string p;
    cout << "input>>" << endl;
    cin >> p;
    cout << "p=" << p << endl;
    system("pause");
}

