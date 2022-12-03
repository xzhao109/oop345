///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "CustomerOrder.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "Utilities.h"

namespace sdds {
size_t CustomerOrder::m_widthField{0u};

CustomerOrder::CustomerOrder(const std::string& record) {
    Utilities ul;
    size_t next{0u};
    bool more{true};

    m_name = ul.extractToken(record, next, more);
    m_product = ul.extractToken(record, next, more);
    m_cntItem = std::count(record.begin(), record.end(), ul.getDelimiter()) - 1u;
    CustomerOrder::m_widthField = std::max(ul.getFieldWidth(), CustomerOrder::m_widthField);

    size_t index{0u};
    if (m_cntItem) {
        m_lstItem = new Item*[m_cntItem + 1];
        while (more) {
            m_lstItem[index] = new Item(ul.extractToken(record, next, more));
            index++;
        }
    }
}
CustomerOrder::CustomerOrder(const CustomerOrder& cs) {
    throw "No copying allowed";
}
CustomerOrder::CustomerOrder(CustomerOrder&& cs) noexcept {
    operator=(std::move(cs));
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cs) noexcept {
    if (&cs != this) {
        for (size_t i{0u}; i < m_cntItem; i++)
            delete m_lstItem[i];
        delete[] m_lstItem;
        m_name = cs.m_name;
        cs.m_name = {};
        m_product = cs.m_product;
        cs.m_product = {};
        m_cntItem = cs.m_cntItem;
        cs.m_cntItem = {0u};
        m_lstItem = cs.m_lstItem;
        cs.m_lstItem = {nullptr};
    }
    return *this;
}
CustomerOrder::~CustomerOrder() {
    for (size_t i{0u}; i < m_cntItem; i++)
        delete m_lstItem[i];
    delete[] m_lstItem;
}
bool CustomerOrder::isOrderFilled() const {
    return std::all_of(m_lstItem, (m_lstItem + m_cntItem), [=](const Item* item) {
        return item->m_isFilled;
    });
}
bool CustomerOrder::isItemFilled(const std::string& itemName) const {
    bool isFilled{true};
    std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) {
        if (item->m_itemName == itemName)
            isFilled = item->m_isFilled;
    });
    return isFilled;
}
void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    for (size_t i{0u}; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == station.getItemName() && m_lstItem[i]->m_isFilled == false) {
            if (station.getQuantity()) {
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                os << "    Filled " << m_name << ", " << m_product << " ["
                   << m_lstItem[i]->m_itemName << "]\n";
                break;
            } else {
                os << "    Unable to fill " << m_name << ", " << m_product << " ["
                   << m_lstItem[i]->m_itemName << "]\n";
            }
        }
    }
}
void CustomerOrder::display(std::ostream& os) const {
    os << m_name << " - " << m_product << '\n';
    std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) {
        os << "[" << std::setw(6) << std::setfill('0') << std::right << item->m_serialNumber << "] ";
        os << std::setw(CustomerOrder::m_widthField) << std::setfill(' ') << std::left << item->m_itemName;
        os << " - " << (item->m_isFilled ? "FILLED" : "TO BE FILLED") << '\n';
    });
}
}  // namespace sdds