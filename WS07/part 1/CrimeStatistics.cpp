///////////////////////////////////////////////////
// WorkShop#7 :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 11
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "CrimeStatistics.h"

#include <algorithm>  // for_each()
#include <fstream>
#include <iomanip>
#include <iostream>

namespace sdds {
CrimeStatistics::CrimeStatistics(const char* filename) {
    auto trim{[&](std::string& str, size_t found) {
        std::string res = str.substr(0, found);
        str = str.substr(found);
        res.erase(0, res.find_first_not_of(' '));
        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }};

    std::ifstream inf(filename);
    std::string strline;
    Crime crime;

    if (!inf)
        throw "The filename is incorrect";

    while (getline(inf, strline)) {
        crime.m_province = trim(strline, 25);
        crime.m_district = trim(strline, 25);
        crime.m_crime = trim(strline, 25);
        crime.m_year = std::stoi(trim(strline, 5));
        crime.m_cases = std::stoi(trim(strline, 5));
        crime.m_resolved = std::stoi(trim(strline, strline.length()));
        m_crimes.push_back(crime);
    }
}
void CrimeStatistics::display(std::ostream& out) const {
    auto printline{[&](const Crime& theCrime) { out << theCrime; }};
    std::for_each(m_crimes.begin(), m_crimes.end(), printline);
}
std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
    out << "| " << std::setw(21) << std::setfill(' ') << std::left << theCrime.m_province;
    out << " | " << std::setw(15) << std::setfill(' ') << theCrime.m_district;
    out << " | " << std::setw(20) << std::setfill(' ') << theCrime.m_crime;
    out << " | " << std::setw(6) << std::setfill(' ') << std::right << theCrime.m_year;
    out << " | " << std::setw(4) << std::setfill(' ') << theCrime.m_cases;
    out << " | " << std::setw(3) << theCrime.m_resolved << " |\n";
    return out;
}
}  // namespace sdds