///////////////////////////////////////////////////
// WorkShop#4 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 9
///////////////////////////////////////////////////

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include <string>

#include "Reservation.h"

namespace sdds {
class Restaurant {
    Reservation* m_ptr{};  // dynamically allocated array of pointers to object
    size_t m_cnt{};

   public:
    Restaurant(const Restaurant& res);
    Restaurant& operator=(const Restaurant& res);
    Restaurant(Restaurant&& res) noexcept;
    Restaurant& operator=(Restaurant&& res) noexcept;
    ~Restaurant();

    size_t size() const;
    Restaurant(const Reservation* reservations[], size_t cnt);
    friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
};
}  // namespace sdds

#endif