///////////////////////////////////////////////////
// WorkShop#1  :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 18
///////////////////////////////////////////////////

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>

// Global Variables
extern double g_taxrate;
extern double g_discount;

namespace sdds {
class Cars {
    char* m_brand{};  // dynamic
    char m_model[15]{};
    int m_year{};
    double m_price{};
    char m_status{};
    bool m_promotion{};

   public:
    Cars();
    // rule of three
    Cars(const Cars& cars);
    Cars& operator=(const Cars& cars);
    ~Cars();

    // setters
    void setEmpty();
    std::istream& read(std::istream& is);

    // getters
    void display(bool reset);
    char getStatus();
    operator bool() const;
};

// Global Functions
void listArgs(int argc, char* argv[]);
std::istream& operator>>(std::istream& is, Cars& car);
void operator>>(const Cars& car1, Cars& car2);

}  // namespace sdds

#endif