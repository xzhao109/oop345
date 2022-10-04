///////////////////////////////////////////////////
// WorkShop3  :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 2
///////////////////////////////////////////////////

#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <iostream>
#include <string>

namespace sdds {
class Dictionary {
    std::string m_term{};
    std::string m_definition{};

   public:
    Dictionary() = default;
    const std::string& getTerm() const { return m_term; }
    const std::string& getDefinition() const { return m_definition; }
    Dictionary(const std::string& term, const std::string& definition)
        : m_term{term}, m_definition{definition} {}
    friend std::ostream& operator<<(std::ostream& os, const Dictionary& ro);
    friend bool operator==(const Dictionary& lo, const Dictionary& ro);
};
}  // namespace sdds

#endif