//
// Created by 夜林蓝 on 2024/4/7.
//

#include <iostream>
#include "Integer.h"

Integer::Integer(int num) : val(new int(num)) {}

Integer::~Integer() {
    if (val != nullptr) {
        delete val;
        val = nullptr;
    }
}

std::ostream &operator<<(std::ostream &os, const Integer &integer) {
    os << "value is: " << *integer.val;
    return os;
}

Integer &Integer::operator++() {
    *val = *val + 1;
    return *this;
}

Integer &Integer::operator--() {
    *val = *val - 1;
    return *this;
}

const Integer Integer::operator++(int) {
    Integer temp(0);
    temp = *this;
    *val = *val + 1;
    return temp;
}

const Integer Integer::operator--(int) {
    Integer temp(0);
    temp = *this;
    *val = *val - 1;
    return temp;
}

Integer &Integer::operator=(const Integer &integer) {
    if (val != nullptr) {
        delete val;
        val = nullptr;
    }
    val = new int(*integer.val);
    return *this;
}

bool Integer::operator==(const Integer &rhs) const {
    return *val == *rhs.val;
}

bool Integer::operator!=(const Integer &rhs) const {
    return !(rhs == *this);
}

bool Integer::operator<(const Integer &rhs) const {
    return *val < *rhs.val;
}

bool Integer::operator>(const Integer &rhs) const {
    return rhs < *this;
}

bool Integer::operator<=(const Integer &rhs) const {
    return !(rhs < *this);
}

bool Integer::operator>=(const Integer &rhs) const {
    return !(*this < rhs);
}

int Integer::operator()(string a) const {
    cout << "print " << a << endl;
    return 0;
}




