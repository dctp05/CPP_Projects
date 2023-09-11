#include <iostream>
#include "rational.h"

using namespace std;

int main() {
    //make use of constructors in different ways to show how fraction format is handled
    Rational a, b(3), c(3, -5), d(0, 2), e(-2, -9);
    cout << "Welcome to the rational number calculator. The first numbers demonstrate how" << endl;
    cout << "constructors make instances of the rational number class. The constructors are: " << endl;
    cout << "Rational a, b(3), c(3, -5), d(0, 2), e(-2, -9);" << endl;
    cout << "a: " << a << "\tb: " << b << "\tc: " << c << "\td: " << d << "\te: " << e << endl;

    //show that object and int can be added without issue due to constructor
    cout << "\nBecause of the single int param constructor, rational number + int converts int to " << endl;
    cout << "the rational number class. If we add 3 to rational number c we get:" << endl;
    cout << "c + 3 = " << c + 3 << endl;

    //set up loop to allow user to test different rational numbers
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y') {
        //prompt and save user input for first and second rational
        Rational x, y;
        cout << "\nEnter the first rational number. (ex. 2/4, 0/4, -3/-2, or just an int, 3, -5, 0): ";
        cin >> x;
        cout << "Enter the second rational number: ";
        cin >> y;

        //all of the possible calculations and boolean evaluations
        cout << "\nThese are your calculations:" << endl;
        cout << "-(" << x << ")" << " = " << -x << endl;
        cout << "-(" << y << ")" << " = " << -y << endl;
        cout << x << " + " << y << " = " << x + y << endl;
        cout << x << " - " << y << " = " << x - y << endl;
        cout << x << " * " << y << " = " << y * x << endl;
        cout << x << " / " << y << " = " << x / y << endl;
        cout << x << " == " << y << " is " << ((x == y) ? "True" : "False") << endl;
        cout << x << " != " << y << " is " << ((x != y) ? "True" : "False") << endl;
        cout << x << " < " << y << " is " << ((x < y) ? "True" : "False") << endl;
        cout << x << " > " << y << " is " << ((x > y) ? "True" : "False") << endl;
        cout << x << " <= " << y << " is " << ((x <= y) ? "True" : "False") << endl;
        cout << x << " >= " << y << " is " << ((x >= y) ? "True" : "False") << endl;

        //prompt user to rerun and clear whitespace
        cout << "\nRun calculation on new rational numbers? (y/n): ";
        cin >> repeat;
        cin.ignore();
    }

    //goodbye
    cout << "\n\nThanks for using the rational number calculator!";

    return 0;
}