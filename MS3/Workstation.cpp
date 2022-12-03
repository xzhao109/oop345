///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Workstation.h"

namespace sdds {
std::deque<CustomerOrder> g_pending{};
std::deque<CustomerOrder> g_completed{};
std::deque<CustomerOrder> g_incomplete{};

Workstation::Workstation(const std::string& station) : Station(station) {
    m_pNextStation = nullptr;
}
void Workstation::fill(std::ostream& os) {
    if (!m_orders.empty())
        m_orders.front().fillItem(*this, os);
}
bool Workstation::attemptToMoveOrder() {
    bool isMoved = false;
    if (!m_orders.empty()) {
        if (m_orders.front().isItemFilled(getItemName())) {
            if (!m_pNextStation)
                if (m_orders.front().isOrderFilled())
                    g_completed.push_back(std::move(m_orders.front()));
                else
                    g_incomplete.push_back(std::move(m_orders.front()));
            else
                *m_pNextStation += std::move(m_orders.front());
            isMoved = true;
            m_orders.pop_front();
        } else if (!getQuantity()) {
            if (!m_pNextStation)
                g_incomplete.push_back(std::move(m_orders.front()));
            else
                *m_pNextStation += std::move(m_orders.front());
            isMoved = true;
            m_orders.pop_front();
        }
    }
    return isMoved;
}
void Workstation::setNextStation(Workstation* station) {
    m_pNextStation = station;
}
Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}
void Workstation::display(std::ostream& os) const {
    os << getItemName() << " --> ";
    os << (m_pNextStation == nullptr ? "End of Line" : m_pNextStation->getItemName()) << '\n';
}
Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
    m_orders.push_back(std::move(newOrder));
    return *this;
}
}  // namespace sdds
