///////////////////////////////////////////////////
// Milestone  :  2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 26
///////////////////////////////////////////////////
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds {
class Station {
    int m_id{};
    std::string m_name{};
    std::string m_desc{};
    size_t m_nextSerial{};
    size_t m_quantity{};
    // declares the static member variable
    static size_t m_widthField;  // static member variables are shared
    static size_t id_generator;  // by all objects of the class

   public:
    Station(const std::string& record);
    const std::string& getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
}  // namespace sdds
#endif