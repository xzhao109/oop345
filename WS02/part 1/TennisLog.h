#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
struct TennisMatch {
    string m_tid{};
    string m_name{};
    int m_mid{};  // unsigned
    string m_winner{};
    string m_loser{};

    // method
    // TennisMatch(const string tid, const string name,
    //                  const int mid, const string winner, const string loser);
    TennisMatch& set(const string tid, const string name,
                     const int mid, const string winner, const string loser);
    std::ostream& display(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, const TennisMatch& tm);
//
//
class TennisLog {
    TennisMatch* m_match{};
    int m_cnt{};

   public:
    TennisLog();
    TennisLog(const char* filename);

    void setEmpty();
    int recsCount(const char* filename);

    void addMatch(const TennisMatch tm);  //
    const TennisLog& findMatches(const char* name);
    TennisMatch operator[](size_t index) const;
    operator size_t();
};

}  // namespace sdds

#endif