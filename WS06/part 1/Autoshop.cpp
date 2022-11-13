///////////////////////////////////////////////////
// WorkShop#6 :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 4
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Autoshop.h"

#include <iostream>
#include <vector>

namespace sdds {
Autoshop::~Autoshop() {
    for (Vehicle* vehicle : m_vehicles)
        delete vehicle;
}
Autoshop& Autoshop::operator+=(Vehicle* theVechicle) {
    m_vehicles.push_back(theVechicle);
    return *this;
}
void Autoshop::display(std::ostream& out) const {
    std::vector<Vehicle*>::const_iterator it;
    it = m_vehicles.cbegin();  // assign iterator to start of vector
    while (it != m_vehicles.cend()) {
        (*it)->display(out);
        ++it;
    }
}
}  // namespace sdds