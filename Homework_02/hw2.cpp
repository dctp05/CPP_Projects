/*Author: Dylan Cohen
 *Date: 09/21/2022
 *Assignment 2 - This program takes input from the user in the form of a principal loan
 * amount, interest rate, and loan repayment length, and returns the monthly payment,
 * and a table with the decreasing principle amount, monthly interest, and accrued interest.
 */

#include <iostream>
#include <math.h>     //needed for rounding
#include <iomanip>    //needed for table formatting

using namespace std;

/* This function is the equation that takes the principal, loan length, and interest rate
 * and returns a monthly payment that will pay off the loan in the alotted time.
 */
double amortization(double principal, int num_months, double interest) {
    return principal * (interest * pow((1 + interest), num_months))/(pow((1 + interest), num_months)-1);
}

int main() {
    //Set numbers to show with two decimals
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Hello! Welcome to the mortgage calculator. Follow instructions to input\n";
    cout << "your principal, interest, and loan length. A table will be generated\n";
    cout << "that shows how your loan is paid off month to month.\n" << endl;
    
    //Set up loop so program can be rerun until the user quits
    while (true){

        // Declare/initialize variables for loan calculations
        double p, r, monthly_payment, monthly_interest, accrued_interest = 0;
        int n;

        //Prompt and assign user inputs for principal, interest, and loan time
        cout << "Input principal amount: ";
        cin >> p;
        cout << "Input interest: ";
        cin >> r;
        cout << "Input time of loan in months: ";
        cin >> n;

        //Get monthly payment for loan and display on screen
        monthly_payment = amortization(p, n, (r/100)/12);

        cout << "\nYou're monthly payment is $" << monthly_payment << "." << endl;

        //Make table headings using setw from iomanip header
        cout << setw(13) << "Payment #";
        cout << setw(15) << "Principal";
        cout << setw(11) << "Interest";
        cout << setw(16) << "Accrued Int." << endl;

        //i is the number of the payment in the table
        int i = 1;

        /* Each loop is a new row in the table. The monthly interest is the rate/12
         * times the principal, which is then added to the accrued interest variable.
         * The new principal is the previous principal minus the difference between the
         * monthly payment and the interest
         */
        while (round(p) > 0) {
            monthly_interest = (p*(r/100))/12;
            accrued_interest += monthly_interest;
            p = p - (monthly_payment - monthly_interest);
            cout << setw(13) << i;
            cout << setw(15) << p;
            cout << setw(11) << monthly_interest;
            cout << setw(16) << accrued_interest << endl;
            i++;
        }
        /* Prompt the user if they want to rerun the program. Make sure the user is
         * entering the correct characters, and if not, re-prompt the user. Break out
         * of the loop when a valid character is input
         */

        char rerun;
        while (true) {    
            cout << "Would you like to rerun the program? (y/n): ";
            cin >> rerun;
            if (!(rerun == 'y' || rerun == 'Y' || rerun == 'n' || rerun == 'N')){
                cout << "Please input y or n\n";
                continue;
            }
            break;
        }
        //If no is selected, display a goodbye message, otherwise restart the loop from the top
        if (rerun == 'n' || rerun == 'N'){
            cout << "Thanks for using the program, and make sure to pay your mortgage!";
            break;
        }
    }

    return 0;
}