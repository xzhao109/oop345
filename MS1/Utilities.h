///////////////////////////////////////////////////
// Milestone  :  1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 19
///////////////////////////////////////////////////
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

namespace sdds {
class Utilities {
    size_t m_widthField{1u};
    static char m_delimiter;  // declares the static member variable

   public:
    void setFieldWidth(size_t newWidth);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
};
}  // namespace sdds
#endif