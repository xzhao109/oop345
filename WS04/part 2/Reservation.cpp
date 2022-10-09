///////////////////////////////////////////////////
// WorkShop#4 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 9
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Reservation.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
std::string ltrim(const std::string& s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
std::string rtrim(const std::string& s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
std::string trim(const std::string& s) {
    return rtrim(ltrim(s));
}
Reservation::Reservation(const std::string& res) {
    std::string str = res;

    m_id = trim(str.substr(0, str.find(':')));
    str.erase(0, str.find(':') + 1);

    m_name = trim(str.substr(0, str.find(',')));
    str.erase(0, str.find(',') + 1);

    m_email = trim(str.substr(0, str.find(',')));
    str.erase(0, str.find(',') + 1);

    m_noOfPeople = std::stoi(trim(str.substr(0, str.find(','))));
    str.erase(0, str.find(',') + 1);

    m_day = std::stoi(trim(str.substr(0, str.find(','))));
    str.erase(0, str.find(',') + 1);

    m_hour = std::stoi(trim(str.substr(0, str.find(','))));
    str.erase(0, str.find(',') + 1);
}
void Reservation::update(int day, int time) {
    m_day = day;
    m_hour = time;
}
std::ostream& operator<<(std::ostream& os, const Reservation& res) {
    os << "Reservation "
       << std::setw(10) << res.m_id << ": "
       << std::setw(20) << res.m_name << "  ";
    os << std::setw(20) << std::left
       << "<" + res.m_email + ">" << std::right << "    ";

    std::string type = std::string();
    std::string checkPl = (res.m_noOfPeople == 1) ? " person." : " people.";

    if (res.m_hour >= 6 && res.m_hour <= 9)
        type = "Breakfast";
    else if (res.m_hour >= 11 && res.m_hour <= 15)
        type = "Lunch";
    else if (res.m_hour >= 17 && res.m_hour <= 21)
        type = "Dinner";
    else
        type = "Drinks";

    os << type << " on day " << res.m_day << " @ " << res.m_hour
       << ":00 for " << res.m_noOfPeople << checkPl << std::endl;
    return os;
}
}  // namespace sdds