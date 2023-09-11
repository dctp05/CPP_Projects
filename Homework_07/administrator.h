#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <string>
// #include "employee.h"
#include "salariedemployee.h"
namespace employeescohen
{
    class Administrator : public SalariedEmployee
    {
        public:
            Administrator();
            Administrator(string the_title, string the_division, double the_salary,
                          string the_name, string new_ssn);
            string get_title() const;
            string get_division() const;
            void set_title(string the_title);
            void set_division(string the_division);
            void input_data();
            void print() const;
            void print_check();
        private:
            string title;
            string division;
    };
} // employeescohen
#endif // ADMINISTRATOR_H