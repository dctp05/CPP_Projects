#include <iostream>
#include <string>     //needed for type string
#include <math.h>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double dollar_amount;
    cout << "Hello. Input dollars and cents: $";
    cin >> dollar_amount;
    // cout << dollar_amount;
    // int cents = (int)(dollar_amount*100 + 0.5);
    int cents = round(dollar_amount*100);
    cout << "Cents: " << cents;
    int quarters, dimes, nickels, pennies;
    quarters = cents/25;
    cents %= 25;
    dimes = cents/10;
    cents %= 10;
    nickels = cents/5;
    cents %= 5;
    pennies = cents;

    cout << "\n\nQuarters: " << quarters << "\tDimes: " << dimes << "\tNickels: " << nickels << "\tPennies: " << pennies;

    cout << "\nInput amount of quarters, dimes, nickels, and pennies separated by spaces: ";
    cin >> quarters >> dimes >> nickels >> pennies;
    cents = quarters * 25 + dimes * 10 + nickels * 5 + pennies;
    dollar_amount = cents/100.0;
    cout << "\nYou're rich! you have $" << dollar_amount << " in coins.";
    // cout << "\nQuarters: " << quarters << "\tDimes: " << dimes << "\tNickels: " << nickels << "\tPennies: " << pennies;
    cout << "\nPress enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}