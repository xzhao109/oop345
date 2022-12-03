#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include "EmpProfile.h"
#include "GeneratingList.h"

namespace sdds {
GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}  // namespace sdds

#endif  // SDDS_WRITINGRECORD_H
