///////////////////////////////////////////////////
// Milestone  :  2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 26
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

#include <algorithm>

namespace sdds {
char Utilities::m_delimiter = ';';  // defines the static member variable

void Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
}
size_t Utilities::getFieldWidth() const {
    return m_widthField;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
    size_t found = (str.find(getDelimiter(), next_pos));
    std::string token = str.substr(next_pos, found - next_pos);
    if (found == next_pos) {
        more = false;
        throw "   ERROR: No token.\n";
    }
    more = (found != std::string_view::npos);  // success to find the delimiter
    next_pos = found + 1;
    setFieldWidth(std::max(m_widthField, token.length()));
    token.erase(0, token.find_first_not_of(' '));
    return token.erase(token.find_last_not_of(' ') + 1);
}
void Utilities::setDelimiter(char newDelimiter) {
    m_delimiter = newDelimiter;
}
char Utilities::getDelimiter() {
    return m_delimiter;
}
}  // namespace sdds