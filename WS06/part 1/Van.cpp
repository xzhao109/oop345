///////////////////////////////////////////////////
// WorkShop#6 :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 4
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Van.h"

#include <iomanip>
#include <iostream>

namespace sdds {
Van::Van(std::istream& in) {
    std::string str, str2 = std::string();  
    std::getline(in, str);
    m_maker = trim(str, ',');

    str2 = trim(str, ',');
    if (str2 == "p")
        m_type = "pickup";
    else if (str2 == "m")
        m_type = "mini-bus";
    else if (str2 == "c")
        m_type = "camper";

    str2 = trim(str, ',');
    if (str2 == "d")
        m_purpose = "delivery";
    else if (str2 == "p")
        m_purpose = "passenger";
    else if (str2 == "c")
        m_purpose = "camping";

    str2 = trim(str, ',');
    if (str2 == "n")
        m_condition = "new";
    else if (str2 == "b")
        m_condition = "broken";
    else if (str2 == "u")
        m_condition = "used";

    m_topSpeed = stod(trim(str, '\n'));
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
    out << " | " << std::right << std::setw(6) << topSpeed() << " |\n";
}
}  // namespace sdds