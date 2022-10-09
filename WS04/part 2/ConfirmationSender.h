///////////////////////////////////////////////////
// WorkShop#4 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 9
///////////////////////////////////////////////////

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include <string>

#include "Reservation.h"

namespace sdds {
class ConfirmationSender {
    const Reservation** m_pptr{};  // pointer to a pointer to an array object
    size_t m_pcnt{};

   public:
    ConfirmationSender() = default;
    ConfirmationSender(const ConfirmationSender& cs);
    ConfirmationSender& operator=(const ConfirmationSender& cs);
    ConfirmationSender(ConfirmationSender&& cs) noexcept;
    ConfirmationSender& operator=(ConfirmationSender&& cs) noexcept;
    ~ConfirmationSender();

    ConfirmationSender& operator+=(const Reservation& res);
    ConfirmationSender& operator-=(const Reservation& res);
    friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
};
}  // namespace sdds

#endif