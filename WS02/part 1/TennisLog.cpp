///////////////////////////////////////////////////
// WorkShop#2 :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 25
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "TennisLog.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
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
    return (rec - 1);  // exclude heading line
}
TennisLog::TennisLog() {
    setEmpty();
}
TennisLog::TennisLog(const char* filename) {
    string str{};
    setEmpty();

    m_cnt = recsCount(filename);
    delete[] m_match;
    m_match = new TennisMatch[m_cnt + 1];

    ifstream inf(filename);
    getline(inf, str, '\n');  // skip heading line
    while (!inf.eof()) {
        for (int i{0}; i <= m_cnt; i++) {
            getline(inf, m_match[i].m_tid, ',');
            getline(inf, m_match[i].m_name, ',');

            getline(inf, str, ',');
            m_match[i].m_mid = stoi(str);

            getline(inf, m_match[i].m_winner, ',');
            getline(inf, m_match[i].m_loser, '\n');
        }
    }
    inf.close();
}
TennisLog::~TennisLog() {
    delete[] m_match;
}
void TennisLog::addMatch(const TennisMatch& tm) {
    TennisMatch* tmp{};
    tmp = new TennisMatch[m_cnt + 1];
    for (int i{0}; m_cnt > 0 && i < m_cnt; i++) {
        tmp[i] = m_match[i];
    }
    tmp[m_cnt] = tm;
    delete[] m_match;
    m_match = tmp;
    m_cnt++;
}
TennisLog TennisLog::findMatches(const char* name) const {
    TennisLog tmp{};
    for (int i{0}; i < m_cnt; i++) {
        if ((!m_match[i].m_winner.compare(name)) ||
            (!m_match[i].m_loser.compare(name))) {
            tmp.addMatch(m_match[i]);
        }
    }
    return tmp;
}
TennisMatch TennisLog::operator[](size_t index) const {
    TennisMatch tmp{};
    if (m_match) {
        tmp = m_match[index];
    }
    return tmp;
}
TennisLog::operator size_t() const {
    return m_cnt;
}
// helper function
std::ostream& operator<<(std::ostream& os, const TennisMatch& tm) {
    if (tm.m_tid[0]) {
        os << setw(20) << right << setfill('.') << "Tourney ID";
        os << " : " << setw(30) << left << setfill('.') << tm.m_tid << "\n";
        os << setw(20) << right << setfill('.') << "Match ID";
        os << " : " << setw(30) << left << setfill('.') << tm.m_mid << "\n";
        os << setw(20) << right << setfill('.') << "Tourney";
        os << " : " << setw(30) << left << setfill('.') << tm.m_name << "\n";
        os << setw(20) << right << setfill('.') << "Winner";
        os << " : " << setw(30) << left << setfill('.') << tm.m_winner << "\n";
        os << setw(20) << right << setfill('.') << "Loser";
        os << " : " << setw(30) << left << setfill('.') << tm.m_loser << "\n";
    } else {
        os << "Empty Match";
    }
    return os;
}
}  // namespace sdds