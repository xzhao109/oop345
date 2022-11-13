///////////////////////////////////////////////////
// WorkShop#6 :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 4
///////////////////////////////////////////////////
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>

#include "Vehicle.h"

namespace sdds {
class Autoshop {
    std::vector<Vehicle*> m_vehicles;

   public:
    Autoshop() = default;
    ~Autoshop();
    Autoshop& operator+=(Vehicle* theVechicle);
    void display(std::ostream& out) const;
};
}  // namespace sdds

#endif
