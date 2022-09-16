///////////////////////////////////////////////////
// WorkShop#1  :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 16
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
Cars::Cars() {
    m_brand[0] = '\0';
    m_model[0] = '\0';
    m_year = 0;
    m_price = 0;
    m_status = 'N';
    m_promotion = false;
}
std::istream& Cars::read(std::istream& is) {
    char ch{};
    char brand[10]{};
    char model[15]{};
    int year{};
    double price{};
    char status{};
    char promotion{};

    if (is.good()) {
        // store the information
        is >> status;
        is.ignore();
        is.getline(brand, 10, ',');
        is.getline(model, 15, ',');
        is >> year >> ch >> price >> ch >> promotion;
        is.ignore(1000, '\n');  // flush keyboard

        // read into current object
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
// Global Function
void listArgs(int argc, char* argv[]) {
    cout << "Command Line:\n";
    cout << "--------------------------\n";
    for (int i = 0; i < argc; ++i) {
        cout << "  " << i + 1 << ": ";
        cout << argv[i] << "\n";
    }
    cout << "--------------------------\n\n";
}
}  // namespace sdds