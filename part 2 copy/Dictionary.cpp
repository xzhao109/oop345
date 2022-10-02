///////////////////////////////////////////////////
// WorkShop3  :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 2
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

// part 2
bool operator==(const Dictionary& lo, const Dictionary& ro) {
    bool cmp = false;
    if (lo.getTerm() == ro.getTerm() && lo.getDefinition() == ro.getDefinition()) {
        cmp = true;
    }
    return cmp;
}
}  // namespace sdds