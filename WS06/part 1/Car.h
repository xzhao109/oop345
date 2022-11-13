///////////////////////////////////////////////////
// WorkShop#6 :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 4
///////////////////////////////////////////////////
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>

#include "Utilities.h"  // for trim()
#include "Vehicle.h"

namespace sdds {
class Car : public Vehicle {
    std::string m_maker{};
    std::string m_condition{};
    double m_topSpeed{};

   public:
    Car(std::istream& in);
    std::string condition() const;
    double topSpeed() const;
    void display(std::ostream& out) const;
};
}  // namespace sdds

#endif
