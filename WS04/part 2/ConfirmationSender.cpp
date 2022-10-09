///////////////////////////////////////////////////
// WorkShop#4 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 9
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "ConfirmationSender.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
    operator=(cs);
}
ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
    if (this != &cs) {
        m_pcnt = cs.m_pcnt;
        delete[] m_pptr;
        m_pptr = nullptr;
        m_pptr = new const Reservation*[m_pcnt];
        for (auto i{0u}; i < m_pcnt; i++) {
            m_pptr[i] = cs.m_pptr[i];
        }
    }
    return *this;
}
ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) noexcept {
    operator=(std::move(cs));
}
ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) noexcept {
    if (this != &cs) {
        delete[] m_pptr;
        m_pptr = cs.m_pptr;
        cs.m_pptr = nullptr;
        m_pcnt = cs.m_pcnt;
        cs.m_pcnt = 0u;
    }
    return *this;
}
ConfirmationSender::~ConfirmationSender() {
    delete[] m_pptr;
}
ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
    bool isExist{};  // default initialize to false
    for (auto i{0u}; i < m_pcnt; i++) {
        if (m_pptr[i] == &res)
            isExist = true;
    }
    if (!isExist) {
        const Reservation** pptr = new const Reservation*[m_pcnt + 1u];
        for (auto i{0u}; i < m_pcnt; i++) {
            pptr[i] = m_pptr[i];
        }
        pptr[m_pcnt] = &res;
        delete[] m_pptr;
        m_pptr = pptr;
        m_pcnt++;
    }
    return *this;
}
ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
    for (auto i{0u}; i < m_pcnt; i++) {
        if (m_pptr[i] == &res) {
            const Reservation** pptr = new const Reservation*[m_pcnt - 1u];
            for (auto before{0u}; before < i; before++) {
                pptr[before] = m_pptr[before];
            }
            for (auto after{i + 1u}; after < m_pcnt; after++) {
                pptr[after - 1u] = m_pptr[after];
            }
            delete[] m_pptr;
            m_pptr = pptr;
            m_pcnt--;
        }
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
    os << "--------------------------\n"
       << "Confirmations to Send\n"
       << "--------------------------\n";
    if (cs.m_pcnt == 0u) {
        os << "There are no confirmations to send!\n";
    } else {
        for (auto i{0u}; i < cs.m_pcnt; i++)
            os << *cs.m_pptr[i];
    }
    os << "--------------------------\n";
    return os;
}
}  // namespace sdds