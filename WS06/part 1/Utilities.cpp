///////////////////////////////////////////////////
// WorkShop#6 :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 4
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

#include <sstream>

#include "Car.h"
#include "Van.h"

namespace sdds {
std::string trim(std::string& str, char delim) {
    int found = str.find(delim);
    std::string res = str.substr(0, found);
    str.erase(0, found + 1);
    res.erase(0, res.find_first_not_of(' '));
    res.erase(res.find_last_not_of(' ') + 1);
    return res;
}
Vehicle* createInstance(std::istream& in) {
    std::string str, type = std::string();
    std::getline(in, str);
    type = trim(str, ',');
    std::stringstream os(str);  // get buffer into stringstream
    if (type == "c" || type == "C")
        return new Car(os);
    else if (type == "v" || type == "V")
        return new Van(os);
    return nullptr;
}
}  // namespace sdds