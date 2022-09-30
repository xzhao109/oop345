///////////////////////////////////////////////////
// WorkShop3  :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 30
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Dictionary.h"

#include <iomanip>
#include <iostream>

namespace sdds {
std::ostream& operator<<(std::ostream& os, const Dictionary& ro) {
    os << std::setw(20) << std::right << std::setfill(' ')
       << ro.getTerm() << ": ";
    os << ro.getDefinition();
    return os;
}
}  // namespace sdds