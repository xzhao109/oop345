///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "LineManager.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Utilities.h"

namespace sdds {
LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
    Utilities ul;
    size_t next{0u};
    bool more{};
    std::string record{}, cur_ws_name{}, nxt_ws_name{};

    std::ifstream inf(file);
    if (!inf)
        throw std::string("Failed to open ") + file;

    while (std::getline(inf, record)) {
        cur_ws_name = ul.extractToken(record, next, more);
        Workstation* cur_ws = *std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
            return (station->getItemName() == cur_ws_name);
        });
        m_activeLine.push_back(cur_ws);

        if (more) {
            nxt_ws_name = ul.extractToken(record, next, more);
            Workstation* nxt_ws = *std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
                return (station->getItemName() == nxt_ws_name);
            });
            cur_ws->setNextStation(nxt_ws);
        }
    }
    inf.close();

    std::for_each(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* fir_ws) {
        auto result{std::any_of(stations.begin(), stations.end(), [=](Workstation* ws) {
            return (ws->getNextStation() == fir_ws);
        })};
        if (!result) m_firstStation = fir_ws;
    });
    m_cntCustomerOrder = g_pending.size();
}
void LineManager::reorderStations() {
    Workstation* nxt_ws = m_firstStation;
    std::vector<Workstation*> ws;
    while (nxt_ws) {
        ws.push_back(nxt_ws);
        nxt_ws = nxt_ws->getNextStation();
    }
    m_activeLine = ws;
}
bool LineManager::run(std::ostream& os) {
    static size_t counter{0u};
    os << "Line Manager Iteration: " << ++counter << '\n';
    if (!g_pending.empty()) {
        *m_firstStation += std::move(g_pending.front());
        g_pending.pop_front();
    }
    std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
        station->fill(os);
    });
    std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
        station->attemptToMoveOrder();
    });
    return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
}
void LineManager::display(std::ostream& os) const {
    std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
        station->display(os);
    });
}
}  // namespace sdds