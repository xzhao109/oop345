///////////////////////////////////////////////////
// WorkShop#7 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 13
///////////////////////////////////////////////////
#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <iostream>
#include <list>
#include <vector>

namespace sdds {
struct Crime {
    std::string m_province{};
    std::string m_district{};
    std::string m_crime{};
    size_t m_year{};
    size_t m_cases{};
    size_t m_resolved{};
};
class CrimeStatistics {
    std::vector<Crime> m_crimes;
    size_t m_totalCases{};
    size_t m_totalResolved{};

   public:
    CrimeStatistics(const char* file);
    void display(std::ostream& out) const;
    void sort(const std::string field);
    void cleanList();
    bool inCollection(const std::string crime) const;
    std::list<Crime> getListForProvince(const std::string province) const;
};
std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}  // namespace sdds

#endif