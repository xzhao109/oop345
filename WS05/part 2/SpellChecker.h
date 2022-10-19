///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
constexpr int MAX_ARRAY_LENGTH = 6;

#include <iostream>
#include <string>

namespace sdds {
class SpellChecker {
    std::string m_badWords[MAX_ARRAY_LENGTH]{};   // creates an array of 6 distinct
    std::string m_goodWords[MAX_ARRAY_LENGTH]{};  // default-constructed objects
    size_t m_cnt[MAX_ARRAY_LENGTH]{};             // of type std::string / size_t

   public:
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& os) const;
};
}  // namespace sdds

#endif