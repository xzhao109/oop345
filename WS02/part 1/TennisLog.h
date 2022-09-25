///////////////////////////////////////////////////
// WorkShop#2 :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 25
///////////////////////////////////////////////////

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
struct TennisMatch {
    string m_tid{};
    string m_name{};
    int m_mid{};
    string m_winner{};
    string m_loser{};
};

class TennisLog {
    TennisMatch* m_match{};
    int m_cnt{};

   public:
    TennisLog();
    TennisLog(const char* filename);
    ~TennisLog();

    void setEmpty();
    int recsCount(const char* filename);

    void addMatch(const TennisMatch& tm);
    TennisLog findMatches(const char* name) const;
    TennisMatch operator[](size_t index) const;
    operator size_t() const;
};

// helper function
std::ostream& operator<<(std::ostream& os, const TennisMatch& tm);

}  // namespace sdds

#endif