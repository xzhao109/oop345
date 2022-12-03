///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "Utilities.h"

namespace sdds {
// defines the static member variable
size_t Station::m_widthField{0u};
size_t Station::id_generator{0u};

Station::Station(const std::string& record) {
    Utilities ul;
    size_t next{0u};
    bool more{true};
    m_id = ++Station::id_generator;
    m_name = ul.extractToken(record, next, more);
    m_nextSerial = std::stoi(ul.extractToken(record, next, more));
    m_quantity = std::stoi(ul.extractToken(record, next, more));
    Station::m_widthField = std::max(ul.getFieldWidth(), Station::m_widthField);
    m_desc = ul.extractToken(record, next, more);
}

const std::string& Station::getItemName() const {
    return m_name;
}
size_t Station::getNextSerialNumber() {
    return m_nextSerial++;
}
size_t Station::getQuantity() const {
    return m_quantity;
}
void Station::updateQuantity() {
    if (m_quantity > 0)
        m_quantity--;
}
void Station::display(std::ostream& os, bool full) const {
    os << std::right << std::setw(3) << std::setfill('0') << m_id << " | ";
    os << std::left << std::setw(Station::m_widthField)
       << std::setfill(' ') << m_name << " | ";
    os << std::right << std::setw(6)
       << std::setfill('0') << m_nextSerial << " | ";
    if (full)
        os << std::setw(4) << std::setfill(' ') << m_quantity << " | " << m_desc;
    os << '\n';
}
}  // namespace sdds