///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "SpellChecker.h"

#include <fstream>
#include <iomanip>
#include <string>

namespace sdds {
SpellChecker::SpellChecker(const char* filename) {
    std::ifstream file(filename);
    if (!file)
        throw "Bad file name!";
    else {
        std::string str;
        size_t cnt = 0;
        do {
            std::getline(file, str);
            if (file) {
                m_badWords[cnt] = str.substr(0, str.find(' '));
                str.erase(0, str.find(' '));

                str.erase(0, str.find_first_not_of(' '));
                m_goodWords[cnt] = str.substr(0, str.find(' '));
                cnt++;
            }
        } while (file);
    }
}
void SpellChecker::operator()(std::string& text) {
    for (size_t i{0}; i < MAX_ARRAY_LENGTH; i++) {
        while ((text.find(m_badWords[i])) != std::string::npos) {
            text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
            m_cnt[i]++;
        }
    }
}
void SpellChecker::showStatistics(std::ostream& os) const {
    os << "Spellchecker Statistics\n";
    for (size_t i{0}; i < MAX_ARRAY_LENGTH; i++) {
        os << std::setw(15) << std::right << m_badWords[i] << ": "
           << m_cnt[i] << " replacements\n";
    }
}
}  // namespace sdds