///////////////////////////////////////////////////
// WorkShop#1  :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 18
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "carads.h"

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

// Global Variables
double g_taxrate{};
double g_discount{};

namespace sdds {
void Cars::setEmpty() {
    m_brand = nullptr;
    m_model[0] = '\0';
    m_year = 0;
    m_price = 0;
    m_status = 'N';
    m_promotion = false;
}
Cars::Cars() {
    setEmpty();
}
// rule of three
Cars::Cars(const Cars& cars) {
    setEmpty();
    operator=(cars);
}
Cars& Cars::operator=(const Cars& cars) {
    if (this != &cars) {
        // deep copy
        delete[] m_brand;
        m_brand = new char[strlen(cars.m_brand) + 1];
        strcpy(m_brand, cars.m_brand);
        // shadow copy
        strcpy(m_model, cars.m_model);
        m_year = cars.m_year;
        m_price = cars.m_price;
        m_status = cars.m_status;
        m_promotion = ((cars.m_promotion == true) ? 1 : 0);
    }
    return *this;
}
Cars::~Cars() {
    delete[] m_brand;
}
//
std::istream& Cars::read(std::istream& is) {
    char ch{};
    char brand[256]{};
    char model[15]{};
    int year{};
    double price{};
    char status{};
    char promotion{};

    if (is.good()) {
        // store the information
        is >> status;
        is.ignore();
        is.getline(brand, 256, ',');
        is.getline(model, 15, ',');
        is >> year >> ch >> price >> ch >> promotion;
        is.ignore(1000, '\n');  // flush keyboard

        // read into current object
        delete[] m_brand;
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);
        strcpy(m_model, model);
        m_year = year;
        m_price = price;
        m_status = status;
        m_promotion = ((promotion == 'Y') ? 1 : 0);
    }
    return is;
}
void Cars::display(bool reset) {
    static int counter{1};
    if (reset) {
        counter = 1;
    }
    if (m_brand[0]) {
        cout << setw(2) << left << counter << ". "
             << setw(10) << left << m_brand << "| "
             << setw(15) << m_model << "| "
             << m_year << " |";

        counter++;
        m_price *= (1 + g_taxrate);  // price with tax

        cout.setf(ios::fixed);
        cout.precision(2);
        cout << setw(12) << right << m_price << "|";
        if (m_promotion) {
            cout << setw(12) << right << m_price * (1 - g_discount);
        }
    } else {
        cout << "No Car";
    }
    cout << endl;
}
char Cars::getStatus() {
    return m_status;
}
Cars::operator bool() const {
    return (m_status == 'N');
}
// Global Functions
void listArgs(int argc, char* argv[]) {
    cout << "Command Line:\n";
    cout << "--------------------------\n";
    for (int i = 0; i < argc; ++i) {
        cout << "  " << i + 1 << ": ";
        cout << argv[i] << "\n";
    }
    cout << "--------------------------\n\n";
}
std::istream& operator>>(std::istream& is, Cars& car) {
    return car.read(is);
}
void operator>>(const Cars& car1, Cars& car2) {
    car2 = car1;
}
}  // namespace sdds