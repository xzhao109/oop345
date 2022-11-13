///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>

#include "Car.h"

namespace sdds {
class Racecar : public Car {
    double m_booster{};

   public:
    Racecar(std::istream& in);
    void display(std::ostream& out) const;
    double topSpeed() const;
};
}  // namespace sdds

#endif