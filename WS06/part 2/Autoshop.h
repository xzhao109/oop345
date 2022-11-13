///////////////////////////////////////////////////
// WorkShop#6 :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 6
///////////////////////////////////////////////////
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <list>
#include <vector>

#include "Vehicle.h"

namespace sdds {
class Autoshop {
    std::vector<Vehicle*> m_vehicles;

   public:
    ~Autoshop();
    Autoshop& operator+=(Vehicle* theVechicle);
    void display(std::ostream& out) const;

    template <typename T>
    void select(T test, std::list<const Vehicle*>& vehicles) {
        for (Vehicle* vehicle : m_vehicles) {
            if (test(vehicle))
                vehicles.push_back(vehicle);
        }
    }
};
}  // namespace sdds

#endif
