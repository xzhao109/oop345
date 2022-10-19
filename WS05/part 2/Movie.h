///////////////////////////////////////////////////
// WorkShop#5 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Oct 16
///////////////////////////////////////////////////

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds {
class Movie {
    std::string m_title{};
    size_t m_year{};
    std::string m_desc{};

   public:
    Movie() = default;
    const std::string& title() const;
    Movie(const std::string& strMovie);
    std::string trim(std::string& str, char delim);
    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

    template <typename T>
    void fixSpelling(T& spellChecker) {
        spellChecker(m_title);
        spellChecker(m_desc);
    }
};
}  // namespace sdds

#endif