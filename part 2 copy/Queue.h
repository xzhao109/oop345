///////////////////////////////////////////////////
// WorkShop3  :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 2
///////////////////////////////////////////////////

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>

#include "Dictionary.h"

namespace sdds {
template <typename T, int CAPACITY>
class Queue {
    T m_array[CAPACITY]{};
    int m_size{};
    static T m_data;

   public:
    Queue() = default;
    int size() const;
    std::ostream& display(std::ostream& os = std::cout) const;
    const T& operator[](int index) const;

    // part 2
    virtual ~Queue() = default;
    virtual bool push(const T& item);
    T pop();
};

template <typename T, int CAPACITY>
bool Queue<T, CAPACITY>::push(const T& item) {
    bool added = false;
    if (size() < CAPACITY) {
        m_array[size()] = item;
        added = true;
        m_size++;
    }
    return added;
}

template <typename T, int CAPACITY>
int Queue<T, CAPACITY>::size() const {
    return m_size;
}

template <typename T, int CAPACITY>
const T& Queue<T, CAPACITY>::operator[](int index) const {
    if (index > size()) {
        return m_data;
    }
    return m_array[index];
}

template <typename T, int CAPACITY>
std::ostream& Queue<T, CAPACITY>::display(std::ostream& os) const {
    os << "----------------------\n"
       << "| Dictionary Content |\n"
       << "----------------------\n";
    for (int i{0}; i < size(); i++) {
        os << m_array[i] << "\n";
    }
    os << "----------------------\n";
    return os;
}

template <typename T, int CAPACITY>
std::ostream& operator<<(std::ostream& os, const Queue<T, CAPACITY>& ro) {
    return ro.display(os);
}

// part 2
template <typename T, int CAPACITY>
T Queue<T, CAPACITY>::m_data{};

template <>
Dictionary Queue<Dictionary, 100>::m_data{"Empty Term", "Empty Substitute"};

template <typename T, int CAPACITY>
T Queue<T, CAPACITY>::pop() {
    T tmp{};
    if (m_size > 0) {
        tmp = m_array[0];
        for (int i{0}; i < m_size; i++) {
            m_array[i] = m_array[i + 1];
        }
        m_size--;
    }
    return tmp;
}
}  // namespace sdds

#endif