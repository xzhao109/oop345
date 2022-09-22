#define _CRT_SECURE_NO_WARNINGS
#include "TennisLog.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
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
    return rec - 1;  // exclude heading line
}
TennisLog::TennisLog() {
    setEmpty();
}
TennisLog::TennisLog(const char* filename) {
    setEmpty();
    m_cnt = recsCount(filename);

    delete[] m_match;
    m_match = new TennisMatch[m_cnt + 1];

    ifstream inf(filename);
    while (!inf.eof()) {
        for (int i{0}; i < m_cnt; i++) {  // exclude heading line
                                          // 必须先input一个string 才能打印出来

            getline(inf, m_match[i].m_tid, ',');
            getline(inf, m_match[i].m_name, ',');

            cin >> m_match[i].m_mid;  // 读不进去
            cin.ignore(1000, ',');

            getline(inf, m_match[i].m_winner, ',');  // 读了mid的值
            getline(inf, m_match[i].m_loser, '\n');
            cin.ignore(1000, '\n');
        }
    }
    inf.close();
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