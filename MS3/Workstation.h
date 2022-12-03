///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include <iostream>

#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
extern std::deque<CustomerOrder> g_pending;
extern std::deque<CustomerOrder> g_completed;
extern std::deque<CustomerOrder> g_incomplete;

class Workstation : public Station {
    std::deque<CustomerOrder> m_orders;
    Workstation* m_pNextStation{};

   public:
    Workstation(const std::string& station);
    Workstation(const Workstation& station) = delete;
    Workstation& operator=(const Workstation& station) = delete;
    Workstation(Workstation&& station) = delete;
    Workstation& operator=(Workstation&& station) = delete;
    ~Workstation(){};

    void fill(std::ostream& os);
    bool attemptToMoveOrder();
    void setNextStation(Workstation* station);
    Workstation* getNextStation() const;
    void display(std::ostream& os) const;
    Workstation& operator+=(CustomerOrder&& newOrder);
};
}  // namespace sdds

#endif