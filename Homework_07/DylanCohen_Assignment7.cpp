#include <iostream>
#include <string>
#include "employee.h"
#include "salariedemployee.h"
#include "administrator.h"
using namespace employeescohen;
int main () {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The first thing to do is initialize an array of objects of type" << endl
         << "Administrator. This uses the default constructor for each instance" << endl
         << "of the class, putting default values into the member variables. The" << endl
         << "first three instances in the array are printed to demonstrate this.\n\n";
    Administrator admins[10];
    int j=0;
    for(j=0; j<3; j++) admins[j].print();
    int admin_len=0;
    cout << "\n\n-----------------Administrator Data Input-----------------" << endl
         << "Input data as you are prompted on the screen. You can enter" << endl
         << "data for up to ten administrators and may stop at any point." << endl
         << "After you are done entering data, a list of these admins" << endl
         << "data will be printed to the screen. You may enter spaces" << endl
         << "where appropriate.\n\n";
    char cont='y';
    do {
        admins[admin_len].input_data();
        admins[admin_len].print_check();
        if (++admin_len == 10) break;
        cout << "\nContinue entering data? (y/n): ";
        cin >> cont;
        cin.ignore(100, '\n');
        cout << endl;
    } while (cont == 'y' || cont == 'Y');
    cout << "\n\nYou have input " << admin_len << "administrators:\n";
    int i;
    for (i=0; i<admin_len; i++) {
        admins[i].print();
    }
    cout << "-----------------Administration Division Change-----------------" << endl
         << "Unfortunately there has been some conflict amongst the administration" << endl
         << "and the employees in various departments. We are counting on you to" << endl
         << "change some of the divisions so that everyone gets along nicely. The" << endl
         << "following is a list of 5 administrators that need to be moved. They are" << endl
         << "initialized using the constructors.\n\n";
    Administrator admins2[] = {
        Administrator("Internal Manager", "Human Resources", 65000,
                      "Mark Johnson", "213-25-5478"),
        Administrator("Chief Op. Officer", "Social Media", 81600,
                      "Marsha Thomas", "123-45-1285"),
        Administrator("Central Mobility Representative", "Research",
                      110000, "Phillip Weston", "125-143-3698"),
        Administrator("Lead Quality Consultant", "Implementation Taskforce",
                      20000, "Tara Opal", "124-028-0014"),
        Administrator("Janitor", "Some Buildings", 1200000, "Kirk Heisen",
                      "999-99-9990")
    };
    cont = 'y';
    do
    {
        j = 1;
        for (j = 1; j <= 5; j++)
        {
            cout << j << ". ";
            admins2[j - 1].print();
        }
        int admin_num;
        do
        {
            cout << "\n\nInput the indicated number for the worker whose "
                    "division you want to change: ";
            cin >> admin_num;
            cin.ignore(100, '\n');
            if (!(admin_num < 6 && admin_num > 0))
            {
                cout << "Input a valid number!\n";
                continue;
            }
            break;
        } while (true);
        string new_division;
        Administrator temp = admins2[admin_num - 1];
        cout << "\n"
             << admin_num << ". " << temp.get_name() << " works in "
             << temp.get_division() << " as a/an " << temp.get_title() << "."
             << endl;
        cout << "Current: " << temp.get_division() << "     |     Input New: ";
        getline(cin, new_division);
        temp.set_division(new_division);
        cout << admin_num << ". " << temp.get_name() << " now works in "
             << temp.get_division() << " as a/an " << temp.get_title() << "!"
             << endl;
        admins2[admin_num - 1] = temp;
        cout << "\nWould you like to change another employee's division? "
                "(y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
}