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
    static T m_object;
    int m_size{};

   public:
    Queue() = default;
    virtual ~Queue() = default;
    virtual bool push(const T& item);
    T pop();
    int size() const;
    std::ostream& display(std::ostream& os = std::cout) const;
    const T& operator[](int index) const;
};

template <typename T, int CAPACITY>
T Queue<T, CAPACITY>::m_object{};  // be explicitly defined
template <>  // specialize the class-member variable
Dictionary Queue<Dictionary, 100u>::m_object{"Empty Term", "Empty Substitute"};

template <typename T, int CAPACITY>
T Queue<T, CAPACITY>::pop() {
    T item{};
    item = m_array[0];
    if (size() > 0) {
        for (int i{0}; i < size(); i++) {
            m_array[i] = m_array[i + 1];
        }
        m_size--;
    }
    return item;
}

template <typename T, int CAPACITY>
bool Queue<T, CAPACITY>::push(const T& item) {
    bool isAdded{};  // default initialize to false
    if (size() < CAPACITY) {
        m_array[size()] = item;
        isAdded = true;
        m_size++;
    }
    return isAdded;
}

template <typename T, int CAPACITY>
int Queue<T, CAPACITY>::size() const {
    return m_size;
}

template <typename T, int CAPACITY>
const T& Queue<T, CAPACITY>::operator[](int index) const {
    if (index > size()) {
        return m_object;
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
}  // namespace sdds

#endif
