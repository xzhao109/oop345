///////////////////////////////////////////////////
// WorkShop#8 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Nov 20
///////////////////////////////////////////////////
#include "WritingRecord.h"

#include <memory>  // unique_ptr

#include "EmpProfile.h"
#include "GeneratingList.h"
using namespace std;

namespace sdds {
GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
    GeneratingList<EmployeeWage> activeEmp;
    // TODO: Add your code here to build a list of employees
    //         using raw pointers
    for (auto i{0u}; i < emp.size(); ++i) {
        for (auto j{0u}; j < sal.size(); ++j) {
            if (emp[i].id == sal[j].id) {
                EmployeeWage* Emp{new EmployeeWage(emp[i].name, sal[j].salary)};
                try {
                    Emp->rangeValidator();
                    if (activeEmp.sinValidator(emp[i].id))
                        activeEmp += Emp;
                } catch (...) {
                    delete Emp;
                    throw;  // continue throwing
                }
                delete Emp;
            }
        }
    }
    return activeEmp;
}

GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
    GeneratingList<EmployeeWage> activeEmp;
    // TODO: Add your code here to build a list of employees
    //         using smart pointers
    for (auto i{0u}; i < emp.size(); ++i) {
        for (auto j{0u}; j < sal.size(); ++j) {
            if (emp[i].id == sal[j].id) {
                unique_ptr<EmployeeWage> Emp{new EmployeeWage(emp[i].name, sal[j].salary)};
                try {
                    Emp->rangeValidator();
                    if (activeEmp.sinValidator(emp[i].id))
                        activeEmp += Emp;
                } catch (...) {
                    throw;  // continue throwing
                }
            }
        }
    }
    return activeEmp;
}
}  // namespace sdds