///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H
#include <iostream>

#include "Station.h"

namespace sdds {
struct Item {
    std::string m_itemName;
    size_t m_serialNumber{0};
    bool m_isFilled{false};

    Item(const std::string& src) : m_itemName(src){};
};

class CustomerOrder {
    std::string m_name{};
    std::string m_product{};
    size_t m_cntItem{};
    Item** m_lstItem{};
    static size_t m_widthField;

   public:
    CustomerOrder() = default;
    CustomerOrder(const std::string& record);
    CustomerOrder(const CustomerOrder& cs);
    CustomerOrder& operator=(const CustomerOrder& cs) = delete;
    CustomerOrder(CustomerOrder&& cs) noexcept;
    CustomerOrder& operator=(CustomerOrder&& cs) noexcept;
    ~CustomerOrder();

    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
};
};  // namespace sdds

#endif
