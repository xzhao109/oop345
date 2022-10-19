///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
class Book {
    std::string m_author{};
    std::string m_title{};
    std::string m_country{};
    size_t m_year{};
    double m_price{};
    std::string m_desc{};

   public:
    Book() = default;
    Book(const std::string& strBook);
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    friend std::string trim(std::string& str, char delim);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    template <typename T>
    void fixSpelling(T& spellChecker) {
        spellChecker(m_desc);
    }
};
}  // namespace sdds

#endif