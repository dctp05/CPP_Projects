#include <iostream>
#include <string>     
#include <math.h>     
using namespace std;
int main() {
    const int Q = 25;
    const int D = 10;
    const int N = 5;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    double dollar_amount;
    cout << "Input dollars and cents (ex. 3.45): $";
    cin >> dollar_amount;
    int cents = round(dollar_amount*100);
    cout << "Cents: " << cents;
    int quarters, dimes, nickels, pennies;
    quarters = cents/Q;
    cents %= Q;
    dimes = cents/D;
    cents %= D;
    nickels = cents/N;
    cents %= N;
    pennies = cents;
    cout << "\n\nQuarters: " << quarters << "\tDimes: " << dimes << "\tNickels: " << nickels << "\tPennies: " << pennies;
    cout << "\nInput amount of quarters, dimes, nickels, and pennies separated by spaces: ";
    cin >> quarters >> dimes >> nickels >> pennies;
    cents = quarters * Q + dimes * D + nickels * N + pennies;
    cout << "\nYou're rich! you have $" << cents/100 << "." << cents%100 << " in coins.";
    return 0;
}