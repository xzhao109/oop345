///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include <iostream>

#include "Van.h"

namespace sdds {
class Luxuryvan : public Van {
    std::string m_consumption{};

   public:
    Luxuryvan(std::istream& in);
    void display(std::ostream& out) const;
    std::string consumption() const;
};
}  // namespace sdds

#endif