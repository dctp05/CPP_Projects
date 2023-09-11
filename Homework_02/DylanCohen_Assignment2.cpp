#include <iostream>
#include <math.h>     
#include <iomanip>    
using namespace std;
double amortization(double principal, int num_months, double interest) {
    return principal * (interest * pow((1 + interest), num_months))/(pow((1 + interest), num_months)-1);
}
int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Hello! Welcome to the mortgage calculator. Follow instructions to input\n";
    cout << "your principal, interest, and loan length. A table will be generated\n";
    cout << "that shows how your loan is paid off month to month.\n" << endl;
    while (true){
        double p, r, monthly_payment, monthly_interest, accrued_interest = 0;
        int n;
        cout << "Input principal amount: ";
        cin >> p;
        cout << "Input interest: ";
        cin >> r;
        cout << "Input time of loan in months: ";
        cin >> n;
        monthly_payment = amortization(p, n, (r/100)/12);
        cout << "\nYou're monthly payment is $" << monthly_payment << "." << endl;
        cout << setw(13) << "Payment #";
        cout << setw(15) << "Principal";
        cout << setw(11) << "Interest";
        cout << setw(16) << "Accrued Int." << endl;
        int i = 1;
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
        if (rerun == 'n' || rerun == 'N'){
            cout << "Thanks for using the program, and make sure to pay your mortgage!";
            break;
        }
    }
    return 0;
}