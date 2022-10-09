///////////////////////////////////////////////////
// WorkShop#4 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 9
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
Restaurant::Restaurant(const Restaurant& res) {
    operator=(res);
}
Restaurant& Restaurant::operator=(const Restaurant& res) {
    if (this != &res) {
        m_cnt = res.m_cnt;
        delete[] m_ptr;
        m_ptr = new Reservation[m_cnt];
        for (auto i{0u}; i < size(); i++)
            m_ptr[i] = res.m_ptr[i];
    }
    return *this;
}
Restaurant::Restaurant(Restaurant&& res) noexcept {
    operator=(std::move(res));
}
Restaurant& Restaurant::operator=(Restaurant&& res) noexcept {
    if (this != &res) {
        delete[] m_ptr;
        m_ptr = res.m_ptr;
        res.m_ptr = nullptr;
        m_cnt = res.m_cnt;
        res.m_cnt = 0u;
    }
    return *this;
}
Restaurant::~Restaurant() {
    delete[] m_ptr;
}
Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
    m_cnt = cnt;
    m_ptr = new Reservation[m_cnt];
    for (auto i{0u}; i < size(); i++) {
        m_ptr[i] = *reservations[i];
    }
}
size_t Restaurant::size() const {
    return m_cnt;
}
std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
    static int counter{};
    os << "--------------------------\n"
       << "Fancy Restaurant (" << ++counter << ")\n"
       << "--------------------------\n";
    if (res.size() == 0u)
        os << "This restaurant is empty!\n";
    else {
        for (auto i{0u}; i < res.size(); i++)
            os << res.m_ptr[i];
    }
    os << "--------------------------\n";
    return os;
}
}  // namespace sdds