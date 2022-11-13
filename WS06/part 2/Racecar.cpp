///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Racecar.h"

#include <iostream>

namespace sdds {
Racecar::Racecar(std::istream& in) : Car(in) {
    std::string str = std::string();
    std::getline(in, str, '\n');
    m_booster = std::stod(trim(str));
}
void Racecar::display(std::ostream& out) const {
    Car::display(out);
    out << "*";
}
double Racecar::topSpeed() const {
    return Car::topSpeed() * (1 + m_booster);
}
}  // namespace sdds