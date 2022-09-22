#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <string>
// #include <string_view>

namespace sdds {
struct TennisMatch {
    std::string m_tid{};
    std::string m_name{};
    int m_mid{};  // unsigned
    std::string m_winner{};
    std::string m_loser{};

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

    void addMatch(const TennisLog* tl);  //
    // const TennisLog& findMatches(const char* name);
    TennisMatch operator[](size_t index) const;
    operator size_t();
};

}  // namespace sdds

#endif