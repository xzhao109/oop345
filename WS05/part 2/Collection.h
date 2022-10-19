///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {
template <typename T>
class Collection {
    std::string m_name{};
    T* m_array{};
    size_t m_size{};
    void (*observer)(const Collection<T>&, const T&){};  // a pointer to a function

   public:
    Collection(std::string name);
    Collection(const Collection& source) = delete;
    Collection& operator=(const Collection& source) = delete;
    ~Collection();

    const std::string& name() const;
    size_t size() const;
    void setObserver(void (*observer)(const Collection<T>&, const T&));
    Collection<T>& operator+=(const T& item);
    T& operator[](size_t idx) const;
    T* operator[](std::string title) const;
};

template <typename T>
Collection<T>::Collection(std::string name) {
    m_name = name;
}
template <typename T>
Collection<T>::~Collection() {
    delete[] m_array;
};

template <typename T>
const std::string& Collection<T>::name() const {
    return m_name;
};

template <typename T>
size_t Collection<T>::size() const {
    return m_size;
};

template <typename T>
void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&)) {
    this->observer = observer;
};

template <typename T>
Collection<T>& Collection<T>::operator+=(const T& item) {
    bool isExist{};  // default initialize to false
    for (size_t i{0}; i < m_size; i++) {
        if (m_array[i].title() == item.title())
            isExist = true;
    }
    if (!isExist) {
        T* array = new T[m_size + 1];
        for (size_t i{0}; i < m_size; i++) {
            array[i] = m_array[i];
        }
        array[m_size] = item;
        delete[] m_array;
        m_size++;

        // resizes the array of items to accommodate the new item
        m_array = new T[m_size];
        for (size_t i{0}; i < m_size; i++) {
            m_array[i] = array[i];
        }
        delete[] array;

        if (observer) {
            observer((*this), item);
        }
    }
    return *this;
}

template <typename T>
T& Collection<T>::operator[](size_t idx) const {
    if (idx >= size()) {
        std::string err = "Bad index [" + std::to_string(idx) +
                          "]. Collection has [" + std::to_string(size()) + "] items.";
        throw std::out_of_range(err);
    }
    return m_array[idx];
};

template <typename T>
T* Collection<T>::operator[](std::string title) const {
    T* array{};
    for (size_t i{0}; i < m_size; i++) {
        if (m_array[i].title() == title) {
            array = &m_array[i];
        }
    }
    return array;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Collection<T>& cl) {
    for (size_t i{0}; i < cl.size(); i++) {
        os << cl[i];
    }
    return os;
};
}  // namespace sdds

#endif