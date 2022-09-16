///////////////////////////////////////////////////
// WorkShop#1  :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 16
///////////////////////////////////////////////////

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>

// Global Variables
extern double g_taxrate;
extern double g_discount;

namespace sdds {
class Cars {
    char m_brand[10]{};
    char m_model[15]{};
    int m_year{};
    double m_price{};
    char m_status{};
    bool m_promotion{};

   public:
    Cars();
    std::istream& read(std::istream& is);
    void display(bool reset);
    char getStatus();
};

// Global Function
void listArgs(int argc, char* argv[]);

}  // namespace sdds

#endif