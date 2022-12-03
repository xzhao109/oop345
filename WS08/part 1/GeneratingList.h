///////////////////////////////////////////////////
// WorkShop#8 :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 18
///////////////////////////////////////////////////
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace sdds {
template <typename T>
class GeneratingList {
    std::vector<T> list;

   public:
    GeneratingList() {}
    GeneratingList(const char* f) {
        std::ifstream file(f);
        if (!file)
            throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

        while (file) {
            T t;
            if (t.load(file))
                list.push_back(T(t));
        }
    }

    size_t size() const { return list.size(); }
    const T& operator[](size_t i) const { return list[i]; }

    // TODO: Implement the Luhn Algorithm to check the
    //       valadity of SIN No's
    bool sinValidator(const std::string& sin) {
        bool isValid{};
        int sum = 0;
        int check = sum % 10;

        // sum odds
        for (int i = 0; i <= 8; i += 2)
            sum += sin[i] - '0';
        // sum evens
        for (int i = 1; i <= 7; i += 2) {
            if (2 * (sin[i] - '0') >= 10)
                sum += 2 * (sin[i] - '0') - 9;
            else
                sum += 2 * (sin[i] - '0');
        }

        if (check == 0 && sin.size() == 9)
            isValid = true;
        else
            throw std::string("*** SIN is not valid");
        return isValid;
    }

    // TODO: Overload the += operator with a raw pointer
    //  as a second operand.
    void operator+=(const T* res) {
        list.push_back(*res);
    }

    void print(std::ostream& os) const {
        os << std::fixed << std::setprecision(2);
        for (auto& e : list)
            e.print(os);
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
    rd.print(os);
    return os;
}
}  // namespace sdds
#endif  // !SDDS_GENERATINGLIST_H
