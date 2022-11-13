///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Van.h"

#include <iomanip>
#include <iostream>

namespace sdds {
Van::Van(std::istream& in) {
    std::string str = std::string();

    std::getline(in, str, ',');
    m_maker = trim(str);

    std::getline(in, str, ',');
    str = trim(str);
    if (str == "p")
        m_type = "pickup";
    else if (str == "m")
        m_type = "mini-bus";
    else if (str == "c")
        m_type = "camper";
    else
        throw "Invalid record!";

    std::getline(in, str, ',');
    str = trim(str);
    if (str == "d")
        m_purpose = "delivery";
    else if (str == "p")
        m_purpose = "passenger";
    else if (str == "c")
        m_purpose = "camping";
    else
        throw "Invalid record!";

    std::getline(in, str, ',');
    str = trim(str);
    if (str.empty() || str == "n")
        m_condition = "new";
    else if (str == "b")
        m_condition = "broken";
    else if (str == "u")
        m_condition = "used";
    else
        throw "Invalid record!";

    getline(in, str, ',');
    try {
        m_topSpeed = std::stod(trim(str));
    } catch (...) {  // Handle Any Type of Exceptions
        throw "Invalid record!";
    }
}
std::string Van::condition() const {
    return m_condition;
}
double Van::topSpeed() const {
    return m_topSpeed;
}
std::string Van::type() const {
    return m_type;
}
std::string Van::usage() const {
    return m_purpose;
}
void Van::display(std::ostream& out) const {
    out << "| " << std::setw(8) << m_maker;
    out << " | " << std::left << std::setw(12) << type();
    out << " | " << std::left << std::setw(12) << usage();
    out << " | " << std::left << std::setw(6) << condition();
    out << std::setprecision(2) << std::fixed;
    out << " | " << std::right << std::setw(6) << topSpeed() << " |";
}
}  // namespace sdds