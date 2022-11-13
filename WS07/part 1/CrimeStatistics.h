///////////////////////////////////////////////////
// WorkShop#7 :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 11
///////////////////////////////////////////////////
#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <iostream>
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

   public:
    CrimeStatistics(const char* filename);
    void display(std::ostream& out) const;
};
std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}  // namespace sdds

#endif