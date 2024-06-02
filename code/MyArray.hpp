//
// Created by 夜林蓝 on 2024/4/13.
//

#ifndef LEARNCPLUSPLUS_MYARRAY_HPP
#define LEARNCPLUSPLUS_MYARRAY_HPP

#include<iostream>

using namespace std;

template<class T>
class MyArray {
private:
    T *pAddress;
    int capacity;
    int size;
public:
    MyArray(int capacity) {
        cout << "MyArray(int capacity)" << endl;
        this->capacity = capacity;
        this->size = 0;
        this->pAddress = new T[this->capacity];
    }

    MyArray() {}

    MyArray(const MyArray &arr) {
//        cout << "MyArray(const MyArray &arr)" << endl;
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->pAddress = new T[this->capacity];
        for (int i = 0; i < this->size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    MyArray &operator=(const MyArray &arr) {
//        cout << "&operator=(const MyArray &arr)" << endl;
        if (this->pAddress != nullptr) {
            delete[] this->pAddress;
            this->capacity = 0;
            this->size = 0;
            this->pAddress = nullptr;
        }
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->pAddress = new T[this->capacity];
        for (int i = 0; i < this->size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }


    virtual ~MyArray() {
//        cout << "~MyArray()" << endl;
        if (pAddress != nullptr) {
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->capacity = 0;
            this->size = 0;
        }
    }

    int add(const T &e) {
        if (this->size == this->capacity) {
            cout << "容量已达最大！插入失败！" << endl;
            return -1;
        }
        this->pAddress[this->size++] = e;
        return this->size;
    }

    int remove() {
        if (this->size == 0) {
            cout << "数组内没有数据！删除失败！" << endl;
            return -1;
        }
        return --this->size;
    }

    T &operator[](int index) {
        if (index < 0 || index >= this->size) {
            cout << "index out of array bounds!" << endl;
        }
        return this->pAddress[index];
    }

    int getCapacity() const {
        return capacity;
    }

    int getSize() const {
        return size;
    }

    friend ostream &operator<<(ostream &os, const MyArray &array) {
        os << "T: "<<endl;
        for (int i = 0; i < array.size; ++i) {
            os << array.pAddress[i] << " ";
        }
        return os;
    }

};


#endif //LEARNCPLUSPLUS_MYARRAY_HPP
