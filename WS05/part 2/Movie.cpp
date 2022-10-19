///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
std::string Movie::trim(std::string& str, char delim) {
    size_t found = str.find(delim);
    std::string res = str.substr(0, found);
    str.erase(0, found + 1);
    res.erase(0, res.find_first_not_of(' '));
    res.erase(res.find_last_not_of(' ') + 1);
    return res;
}
const std::string& Movie::title() const {
    return m_title;
}
Movie::Movie(const std::string& strMovie) {
    std::string str = strMovie;
    m_title = trim(str, ',');
    m_year = stoi(trim(str, ','));
    m_desc = trim(str, '\n');
}
std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << std::setw(40) << movie.title() << " | ";
    os << std::setw(4) << movie.m_year << " | ";
    os << movie.m_desc << "\n";
    return os;
}
}  // namespace sdds