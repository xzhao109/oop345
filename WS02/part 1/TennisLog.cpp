#define _CRT_SECURE_NO_WARNINGS
#include "TennisLog.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
// TennisMatch& TennisMatch::set(const string tid, const string name,
//                               const int mid, const string winner, const string loser) {
//     m_tid = tid;
//     m_name = name;
//     m_mid = mid;
//     m_winner = winner;
//     m_loser = loser;
//     return *this;
// }
std::ostream& TennisMatch::display(std::ostream& os) const {
    if (m_tid[0]) {
        os << setw(20) << right << setfill('.') << "Tourney ID";
        os << " : " << setw(30) << left << setfill('.') << m_tid << "\n";
        os << setw(20) << right << setfill('.') << "Match ID";
        os << " : " << setw(30) << left << setfill('.') << m_mid << "\n";
        os << setw(20) << right << setfill('.') << "Tourney";
        os << " : " << setw(30) << left << setfill('.') << m_name << "\n";
        os << setw(20) << right << setfill('.') << "Winner";
        os << " : " << setw(30) << left << setfill('.') << m_winner << "\n";
        os << setw(20) << right << setfill('.') << "Loser";
        os << " : " << setw(30) << left << setfill('.') << m_loser << "\n";
    } else {
        os << "Empty Match";
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const TennisMatch& tm) {
    return tm.display(os);
}
//
//
void TennisLog::setEmpty() {
    m_match = nullptr;
    m_cnt = 0;
}
int TennisLog::recsCount(const char* filename) {
    int rec{0};
    ifstream inf(filename);
    while (inf) {
        if (inf.get() == '\n') {
            ++rec;
        }
    }
    return (rec - 1);  // not ccount the heading line
}
TennisLog::TennisLog() {
    setEmpty();
}
TennisLog::TennisLog(const char* filename) {
    setEmpty();
    string str;
    m_cnt = recsCount(filename);

    delete[] m_match;
    m_match = new TennisMatch[m_cnt];

    ifstream inf(filename);
    getline(inf, str, '\n');

    while (!inf.eof()) {
        TennisMatch tm{};
        for (int i{0}; i < m_cnt; i++) {
            getline(inf, tm.m_tid, ',');
            getline(inf, tm.m_name, ',');

            cin >> tm.m_mid;
            cin.ignore(1000, ',');

            getline(inf, tm.m_winner, ',');
            getline(inf, tm.m_loser, '\n');

            // if (i < 10)
            //     cout << "m_tid: " << tl.m_match[i].m_tid << ", m_name: "
            //          << tl.m_match[i].m_name << ", m_id: " << tl.m_match[i].m_mid << endl;

            m_match[i] = tm;
        }
    }
    inf.close();
}
// void TennisLog::addMatch(const TennisMatch tm) {
//     if (!m_match[m_cnt + 1].m_mid) {
//         m_match[m_cnt + 1].set(tm.m_tid, tm.m_name, tm.m_mid, tm.m_winner, tm.m_loser);
//         m_cnt++;
//     }
// }
const TennisLog& TennisLog::findMatches(const char* name) {
}
TennisMatch TennisLog::operator[](size_t index) const {
    TennisMatch obj{};
    if (m_match) {
        obj = m_match[index];
    }
    return obj;
}
TennisLog::operator size_t() {
    return (size_t)m_match;
}
}  // namespace sdds