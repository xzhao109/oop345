///////////////////////////////////////////////////
// WorkShop3  :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 2
///////////////////////////////////////////////////

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <cmath>
#include <iostream>

#include "Queue.h"
#define VALUE 0.005

namespace sdds {
template <typename T>
class UniqueQueue : public Queue<T, 100> {
   public:
    UniqueQueue() = default;
    bool push(const T &item);
};

template <typename T>
bool UniqueQueue<T>::push(const T &item) {
    bool added = false;
    bool cmp = true;
    
    for (int i{0}; i < Queue<T, 100>::size() && cmp; i++) {
        if (Queue<T, 100>::operator[](i) == item) {
            cmp = false;
        }
    }
    if (cmp) {
        added = Queue<T, 100>::push(item);
    }
    return added;
}

template <>
bool UniqueQueue<double>::push(const double &item) {
    bool added = false;
    bool cmp = true;

    for (int i{0}; i < size() && cmp; i++) {
        if (std::fabs(this->operator[](i) - item) <= VALUE) {
            cmp = false;
        }
    }
    if (cmp) {
        added = Queue<double, 100>::push(item);
    }
    return added;
}
}  // namespace sdds

#endif