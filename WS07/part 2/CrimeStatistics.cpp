///////////////////////////////////////////////////
// WorkShop#7 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 13
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "CrimeStatistics.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace sdds {
CrimeStatistics::CrimeStatistics(const char* file) {
    auto trim{[&](std::string& str, size_t found) {
        std::string res = str.substr(0, found);
        str = str.substr(found);
        res.erase(0, res.find_first_not_of(' '));
        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }};

    std::ifstream inf(file);
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
        m_totalCases += crime.m_cases;
        m_totalResolved += crime.m_resolved;
        m_crimes.push_back(crime);
    }
}
void CrimeStatistics::display(std::ostream& out) const {
    auto printline{[&](const Crime& theCrime) { out << theCrime << '\n'; }};
    std::for_each(m_crimes.begin(), m_crimes.end(), printline);

    out << std::setw(89) << std::setfill('-') << '\n'
        << std::setfill(' ');
    out << "|" << std::setw(80) << std::setfill(' ') << std::right
        << "Total Crimes:  " << m_totalCases << " |\n";
    out << "|" << std::setw(80) << std::setfill(' ')
        << "Total Resolved Cases:  " << m_totalResolved << " |\n";
}
void CrimeStatistics::sort(const std::string field) {
    auto compare{[field](const Crime& lo, const Crime& ro) {
        if (field.compare("Province") == 0)
            return lo.m_province < ro.m_province;
        else if (field.compare("Crime") == 0)
            return lo.m_crime < ro.m_crime;
        else if (field.compare("Cases") == 0)
            return lo.m_cases < ro.m_cases;
        else if (field.compare("Resolved") == 0)
            return lo.m_resolved < ro.m_resolved;
        else
            return false;
    }};
    std::sort(m_crimes.begin(), m_crimes.end(), compare);
}
void CrimeStatistics::cleanList() {
    for (auto& crime : m_crimes)
        if (crime.m_crime == "[None]")
            crime.m_crime = "";
}
bool CrimeStatistics::inCollection(const std::string crime) const {
    auto find{[crime](const Crime& theCrime) { return theCrime.m_crime == crime; }};
    return !std::none_of(m_crimes.begin(), m_crimes.end(), find);
}
std::list<Crime> CrimeStatistics::getListForProvince(const std::string province) const {
    std::list<Crime> crime;
    auto copy{[province](const Crime& theCrime) { return theCrime.m_province == province; }};
    std::copy_if(m_crimes.begin(), m_crimes.end(), back_inserter(crime), copy);
    return crime;
}
std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
    out << "| " << std::setw(21) << std::setfill(' ') << std::left << theCrime.m_province;
    out << " | " << std::setw(15) << std::setfill(' ') << theCrime.m_district;
    out << " | " << std::setw(20) << std::setfill(' ') << theCrime.m_crime;
    out << " | " << std::setw(6) << std::setfill(' ') << std::right << theCrime.m_year;
    out << " | " << std::setw(4) << std::setfill(' ') << theCrime.m_cases;
    out << " | " << std::setw(3) << theCrime.m_resolved << " |";
    return out;
}
}  // namespace sdds