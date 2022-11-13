///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

#include "Vehicle.h"

namespace sdds {
Vehicle* createInstance(std::istream& in);
std::string trim(std::string& str);
}  // namespace sdds

#endif
