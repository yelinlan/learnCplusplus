//
// Created by 夜林蓝 on 2024/4/8.
//

#ifndef LEARNCPLUSPLUS_ABSTRACTCALCULATOR_H
#define LEARNCPLUSPLUS_ABSTRACTCALCULATOR_H


class AbstractCalculator {

public:

    //纯虚函数 没有实现。=====>java抽象函数  子类去实现
    virtual int cal() = 0;
    //虚函数  能够实现上转型 因为有 虚函数指针 虚函数表

//    virtual int cal() {
//        return 0;
//    }

//cal方法没有virtual修饰时，只会调用父类本来的方法，无法实现上转型。多态

//    int cal() {
//        return 0;
//    }

    int a;
    int b;
};

class AddCalculator : public AbstractCalculator {

public:
    int cal() {
        return a + b;
    }

};

class SubCalculator : public AbstractCalculator {

public:
    int cal() {
        return a - b;
    }

};

class MultiplyCalculator : public AbstractCalculator {

public:
    int cal() {
        return a * b;
    }

};

class DivideCalculator : public AbstractCalculator {

public:
    int cal() {
        return a / b;
    }

};


#endif //LEARNCPLUSPLUS_ABSTRACTCALCULATOR_H
