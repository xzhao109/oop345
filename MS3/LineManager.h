///////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Dec 3
///////////////////////////////////////////////////
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>

#include "Workstation.h"

namespace sdds {
class LineManager {
    std::vector<Workstation*> m_activeLine;
    size_t m_cntCustomerOrder{};
    Workstation* m_firstStation{};

   public:
    LineManager(const std::string& file, const std::vector<Workstation*>& stations);
    void reorderStations();
    bool run(std::ostream& os);
    void display(std::ostream& os) const;
};
}  // namespace sdds

#endif