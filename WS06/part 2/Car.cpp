///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

#include <iomanip>
#include <iostream>

namespace sdds {
Car::Car(std::istream& in) {
    std::string str = std::string();
    
    std::getline(in, str, ',');
    m_maker = trim(str);

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

    std::getline(in, str, ',');
    try {
        m_topSpeed = std::stod(trim(str));
    } catch (...) {  // Handle Any Type of Exceptions
        throw "Invalid record!";
    }
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
    out << " | " << std::right << std::setw(6) << topSpeed() << " |";
}
}  // namespace sdds