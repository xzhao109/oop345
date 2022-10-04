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

namespace sdds {
template <typename T>
class UniqueQueue : public Queue<T, 100u> {
   public:
    bool push(const T &item);  // override the inherited function
};

template <typename T>
bool UniqueQueue<T>::push(const T &item) {
    bool isAdded{};  // default initialize to false
    bool isUnique{true};
    for (int i{0}; i < Queue<T, 100u>::size(); i++) {
        if (Queue<T, 100u>::operator[](i) == item) {
            isUnique = false;
        }
    }
    if (isUnique) {
        isAdded = Queue<T, 100u>::push(item);
    }
    return isAdded;
}

template <>  // template specialization <double>
bool UniqueQueue<double>::push(const double &item) {
    bool isAdded{};
    bool isUnique{true};
    for (int i{0}; i < Queue<double, 100u>::size(); i++) {
        if (std::fabs(Queue<double, 100u>::operator[](i) - item) <= 0.005) {
            isUnique = false;
        }
    }
    if (isUnique) {
        isAdded = Queue<double, 100u>::push(item);
    }
    return isAdded;
}
}  // namespace sdds

#endif