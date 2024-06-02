//
// Created by 夜林蓝 on 2024/4/7.
//

#ifndef LEARNCPLUSPLUS_INTEGER_H
#define LEARNCPLUSPLUS_INTEGER_H

#include <cstdlib>
#include <ostream>
#include <string.h>

using namespace std;
class Integer {

private:
    int *val;
public:
    explicit Integer(int n);

    virtual ~Integer();

    friend std::ostream &operator<<(std::ostream &os, const Integer &integer);

    //前置++
    Integer &operator++();

    Integer &operator--();

    //后置++
    const Integer operator++(int);

    //后置--
    const Integer operator--(int);

    Integer &operator=(const Integer &integer);

    bool operator==(const Integer &rhs) const;

    bool operator!=(const Integer &rhs) const;

    bool operator<(const Integer &rhs) const;

    bool operator>(const Integer &rhs) const;

    bool operator<=(const Integer &rhs) const;

    bool operator>=(const Integer &rhs) const;

    int operator()(string a) const;

};


#endif //LEARNCPLUSPLUS_INTEGER_H
