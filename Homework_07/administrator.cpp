#include "administrator.h"
#include <iostream>
#include <string>
namespace employeescohen
{
    Administrator::Administrator()
        : SalariedEmployee(), title("Title Undeclared"),
          division("Division Undeclared")
    {
    }
    Administrator::Administrator(string the_title, string the_division,
                                 double the_salary, string the_name, string new_ssn)
        : SalariedEmployee(the_name, new_ssn, the_salary), title(the_title),
          division(the_division) 
    {
    }
    string Administrator::get_title() const {
        return title;
    }
    string Administrator::get_division() const {
        return division;
    }
    void Administrator::set_title(string the_title) {
        title = the_title;
    }
    void Administrator::set_division(string the_division) {
        division = the_division;
    }
    void Administrator::input_data() {
        string name, ssn, title, division, salary_str;
        double salary;
        cout << "Input name: ";
        getline(cin, name);
        cout << "Input title: ";
        getline(cin, title);
        cout << "Input division: ";
        getline(cin, division);
        cout << "Input SSN: ";
        getline(cin, ssn);
        cout << "Input Salary: ";
        cin >> salary;
        cin.ignore(100, '\n');
        (*this).set_name(name);
        (*this).set_title(title);
        (*this).set_division(division);
        (*this).set_ssn(ssn);
        (*this).set_salary(salary);
    }
    void Administrator::print() const{
        cout << (*this).get_name()
             << " | " << (*this).get_title()
             << " of " << (*this).get_division()
             << " | Salary: $" << (*this).get_salary()
             << " | SSN:  " << (*this).get_ssn() << endl;
    }
    void Administrator::print_check()
    {
        set_net_pay(salary);
        cout << "---------------------------------------------\n";
        cout << "Pay to the order of " << get_name() << " | " << get_title() << " of " << get_division() << endl;
        cout << "The sum of $" << get_net_pay() << endl;
        cout << "---------------------------------------------\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << get_ssn() << endl;
        cout << "Salaried Administrator. Salary Pay: $" << salary << endl;
        cout << "---------------------------------------------\n\n";
    }
} 