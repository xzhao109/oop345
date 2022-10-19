///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
std::string trim(std::string& str, char delim) {
    size_t found = str.find(delim);
    std::string res = str.substr(0, found);
    str.erase(0, found + 1);
    res.erase(0, res.find_first_not_of(' '));
    res.erase(res.find_last_not_of(' ') + 1);  // trims from ' ' to the end of the string
    return res;
}
Book::Book(const std::string& strBook) {
    std::string str = strBook;
    m_author = trim(str, ',');
    m_title = trim(str, ',');
    m_country = trim(str, ',');
    m_price = stod(trim(str, ','));
    m_year = stoi(trim(str, ','));
    m_desc = trim(str, '\n');
}
const std::string& Book::title() const {
    return m_title;
}
const std::string& Book::country() const {
    return m_country;
}
const size_t& Book::year() const {
    return m_year;
}
double& Book::price() {
    return m_price;  // can be modified by client code
}
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << std::setw(20) << book.m_author << " | ";
    os << std::setw(22) << book.m_title << " | ";
    os << std::setw(5) << book.m_country << " | ";
    os << std::setw(4) << book.m_year << " | ";
    os.setf(std::ios::fixed);
    os.precision(2);
    os << std::setw(6) << book.m_price << " | ";
    os << std::setw(6) << book.m_desc << "\n";
    return os;
}
}  // namespace sdds