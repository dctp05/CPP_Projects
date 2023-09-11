#include <iostream>
#include <string>
using namespace std;
int main()
 {
    int CashInput = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    cout << "Input Cash \n";
    cin >> CashInput;
    CashInput = CashInput * 100.00;
    cout << CashInput<<"\n";
    int CashInputQuarter = CashInput / quarter;cout << CashInput%quarter<<'\n';
    return CashInput;
    int CashInputDime = CashInput / dime;cout << CashInput % dime<<'\n';
    return CashInput;
    int CashInputNickel = CashInput / nickel; cout << CashInput % nickel<<'\n';
    return CashInput;
    int CashInputPenny = CashInput / penny;cout << CashInput % penny<<'\n';
    //Penny Mod division is redundant to ensure functionality.
    to_string(CashInput); to_string(CashInputQuarter); to_string(CashInputDime); to_string(CashInputNickel); to_string(CashInputPenny);
    cout << "Final Output: \n";
    cout << CashInputQuarter << "Quarters \n";
    cout << CashInputDime << "Dimes \n";
    cout << CashInputNickel << "Nickels \n";
    cout << CashInputPenny << "Pennies \n";
}