///////////////////////////////////////////////////
// WorkShop#6 :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 4
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

#include <iomanip>
#include <iostream>

namespace sdds {
Car::Car(std::istream& in) {
    std::string str, str2 = std::string();
    std::getline(in, str);
    m_maker = trim(str, ',');

    str2 = trim(str, ',');
    if (str2 == "n")
        m_condition = "new";
    else if (str2 == "b")
        m_condition = "broken";
    else if (str2 == "u")
        m_condition = "used";

    m_topSpeed = stod(trim(str, '\n'));
}
std::string Car::condition() const {
    return m_condition;
}
double Car::topSpeed() const {
    return m_topSpeed;
}
void Car::display(std::ostream& out) const {
    out << "| " << std::setw(10) << m_maker;
    out << " | " << std::left << std::setw(6) << condition();
    out << std::setprecision(2) << std::fixed;
    out << " | " << std::right << std::setw(6) << topSpeed() << " |\n";
}
}  // namespace sdds