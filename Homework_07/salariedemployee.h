// This is the header file salariedemployee.h.
// This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include "employee.h"
#include <string>

namespace employeescohen
{
    class SalariedEmployee : public Employee
    {
    public:
        SalariedEmployee();
        SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary);
        double get_salary() const;
        void set_salary(double new_salary);
        void print_check();

    protected:
        double salary; // weekly
    };
} // namespace employeescohen
#endif // SALARIEDEMPLOYEE_H