///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Luxuryvan.h"

#include <iostream>

namespace sdds {
Luxuryvan::Luxuryvan(std::istream& in) : Van(in) {
    std::string str = std::string();
    std::getline(in, str, '\n');
    str = trim(str);
    if (str == "e") {
        m_consumption = "electric van";
    } else if (str == "g") {
        m_consumption = "gas consumed van";
        throw "Invalid record!";
    }
}
void Luxuryvan::display(std::ostream& out) const {
    Van::display(out);
    out << " " << consumption() << "  *";
}
std::string Luxuryvan::consumption() const {
    return m_consumption;
}
}  // namespace sdds