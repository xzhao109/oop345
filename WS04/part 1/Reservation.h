///////////////////////////////////////////////////
// WorkShop#4 :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 7
///////////////////////////////////////////////////

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds {
constexpr const char* WHITESPACE = " ";

class Reservation {
    std::string m_id{};
    std::string m_name{};
    std::string m_email{};
    int m_noOfPeople{};
    int m_day{};
    int m_hour{};

   public:
    Reservation();
    Reservation(const std::string& res);
    void update(int day, int time);
    friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    // trim functions
    friend std::string ltrim(const std::string& s);
    friend std::string rtrim(const std::string& s);
    friend std::string trim(const std::string& s);
};
}  // namespace sdds

#endif