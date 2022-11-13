///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include <iostream>

#include "Utilities.h"
#include "Vehicle.h"

namespace sdds {
class Van : public Vehicle {
    std::string m_maker{};
    std::string m_type{};
    std::string m_condition{};
    std::string m_purpose{};
    double m_topSpeed{};

   public:
    Van(std::istream& in);
    std::string condition() const;
    double topSpeed() const;
    std::string type() const;
    std::string usage() const;
    void display(std::ostream& out) const;
};
}  // namespace sdds

#endif