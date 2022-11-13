///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

#include <sstream>

#include "Car.h"
#include "Luxuryvan.h"
#include "Racecar.h"
#include "Van.h"

namespace sdds {
std::string trim(std::string& str) {
    bool noSpacee{};
    while (!noSpacee) {
        if (str[0] == ' ')
            str.erase(0, str.find_first_not_of(' '));
        else if (str[str.length() - 1] == ' ')
            str.erase(str.find_last_not_of(' ') + 1);
        else
            noSpacee = true;
    }
    return str;
}
Vehicle* createInstance(std::istream& in) {
    std::string str = std::string();
    char type = '\0', comma = '\0';

    std::getline(in, str);
    str.erase(0, str.find_first_not_of(' '));
    std::stringstream os(str);  // get buffer into stringstream
    os >> type >> comma;

    if (type) {  // extract first non-blank character
        if (type == 'c' || type == 'C')
            return new Car(os);
        else if (type == 'v' || type == 'V')
            return new Van(os);
        else if (type == 'r' || type == 'R')
            return new Racecar(os);
        else if (type == 'l' || type == 'L')
            return new Luxuryvan(os);
        else
            throw "Unrecognized record type: [" + std::string(1, type) + "]";
    }
    return nullptr;
}
}  // namespace sdds