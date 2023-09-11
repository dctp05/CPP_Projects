/*Author: Dylan Cohen
 *Date: 11/13/2022
 *Assignment 5 - This program outlines a class for rational numbers. The
 *behavior of this class is defined through overloading operators to handle
 *boolean comparison and basic math functions, and allows the user to enter
 *rational numbers to test these operations.
 */

#include <iostream>
#include <sstream> //used for parsing user input
#include <tuple>   //makes operator rules easier to write

using namespace std;

class Rational
{
public:
    // constructors
    Rational();
    Rational(int num1);
    Rational(int num1, int num2);

    // puts fractions into correct form
    friend void check_negatives(Rational &num1);

    // easier to write operator rules
    friend tuple<int, int, int, int> set_variables(const Rational &num1,
                                                   const Rational &num2);

    // basic math operations
    friend Rational operator+(const Rational &num1, const Rational &num2);
    friend Rational operator-(const Rational &num1, const Rational &num2);
    friend Rational operator*(const Rational &num1, const Rational &num2);
    friend Rational operator/(const Rational &num1, const Rational &num2);
    friend Rational operator-(const Rational &num1);

    // boolean operations
    friend bool operator==(const Rational &num1, const Rational &num2);
    friend bool operator!=(const Rational &num1, const Rational &num2);
    friend bool operator<(const Rational &num1, const Rational &num2);
    friend bool operator>(const Rational &num1, const Rational &num2);
    friend bool operator<=(const Rational &num1, const Rational &num2);
    friend bool operator>=(const Rational &num1, const Rational &num2);

    // handles instream and outstream
    friend istream &operator>>(istream &ins, Rational &rat_num);
    friend ostream &operator<<(ostream &outs, const Rational &rat_num);

private:
    // the important stuff
    int num;
    int den;
};

int main()
{
    // make use of constructors in different ways to show how fraction format is
    // handled
    Rational a, b(3), c(3, -5), d(0, 2), e(-2, -9);
    cout << "Welcome to the rational number calculator. The first numbers "
            "demonstrate how"
         << endl;
    cout << "constructors make instances of the rational number class. The "
            "consructors are: "
         << endl;
    cout << "Rational a, b(3), c(3, -5), d(0, 2), e(-2, -9);" << endl;
    cout << "a: " << a << "\tb: " << b << "\tc: " << c << "\td: " << d
         << "\te: " << e << endl;

    // show that object and int can be added without issue due to constructor
    cout << "\nBecause of the single int param constructor, rational number + "
            "int converts int to "
         << endl;
    cout << "the rational number class. If we add 3 to rational number c we get:"
         << endl;
    cout << "c + 3 = " << c + 3 << endl;

    // set up loop to allow user to test different rational numbers
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y')
    {
        // prompt and save user input for first and second rational
        Rational x, y;
        cout << "\nEnter the first rational number. (ex. 2/4, 0/4, -3/-2, or just "
                "an int, 3, -5, 0): ";
        cin >> x;
        cout << "Enter the second rational number: ";
        cin >> y;

        // all of the possible calculations and boolean evaluations
        cout << "\nThese are your calculations:" << endl;
        cout << "-(" << x << ")"
             << " = " << -x << endl;
        cout << "-(" << y << ")"
             << " = " << -y << endl;
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

        // prompt user to rerun and clear whitespace
        cout << "\nRun calculation on new rational numbers? (y/n): ";
        cin >> repeat;
        cin.ignore();
    }

    // goodbye
    cout << "\n\nThanks for using the rational number calculator!";

    return 0;
}

// return a tuple of Rational class private variables
tuple<int, int, int, int> set_variables(const Rational &num1,
                                        const Rational &num2)
{
    return {num1.num, num1.den, num2.num, num2.den};
}

// Basic constructors
Rational::Rational()
{
    num = 0;
    den = 1;
}

Rational::Rational(int num1)
{
    num = num1;
    den = 1;
}

Rational::Rational(int num1, int num2)
{
    num = num1;
    den = num2;
    // make sure fraction is in correct format
    check_negatives(*this);
}

// alter signs to make num negative if appl.
void check_negatives(Rational &num1)
{
    if (num1.den < 0)
    {
        num1.num = -num1.num;
        num1.den = -num1.den;
    }
    if (num1.num == 0 && num1.den != 1 && num1.den != 0)
    {
        num1.num = 0;
        num1.den = 1;
    }
    if (num1.num == num1.den && num1.num != 0)
    {
        num1.num = 1;
        num1.den = 1;
    }
    if (num1.num == -num1.den && num1.num != 0)
    {
        num1.num = -1;
        num1.den = 1;
    }
}

// get tuple and use to define operator rule
Rational operator+(const Rational &num1, const Rational &num2)
{
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a * d + b * c;
    temp.den = b * d;
    check_negatives(temp);
    return temp;
}

Rational operator-(const Rational &num1, const Rational &num2)
{
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a * d - b * c;
    temp.den = b * d;
    check_negatives(temp);
    return temp;
}

Rational operator*(const Rational &num1, const Rational &num2)
{
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a * c;
    temp.den = b * d;
    check_negatives(temp);
    return temp;
}

Rational operator/(const Rational &num1, const Rational &num2)
{
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a * d;
    temp.den = c * b;
    check_negatives(temp);
    return temp;
}

Rational operator-(const Rational &num1)
{
    Rational temp;
    temp.num = -num1.num;
    temp.den = num1.den;
    return temp;
}

// get tuple for first two, define rules, and use these to construct other
// operators
bool operator==(const Rational &num1, const Rational &num2)
{
    auto [a, b, c, d] = set_variables(num1, num2);
    if (a * d == c * b)
        return true;
    else
        return false;
}

bool operator<(const Rational &num1, const Rational &num2)
{
    auto [a, b, c, d] = set_variables(num1, num2);
    if (a * d < c * b)
        return true;
    else
        return false;
}

bool operator!=(const Rational &num1, const Rational &num2)
{
    if (num1 == num2)
        return false;
    else
        return true;
}

bool operator>(const Rational &num1, const Rational &num2)
{
    if (num1 < num2 || num1 == num2)
        return false;
    else
        return true;
}

bool operator<=(const Rational &num1, const Rational &num2)
{
    if (num1 < num2 || num1 == num2)
        return true;
    else
        return false;
}

bool operator>=(const Rational &num1, const Rational &num2)
{
    if (num1 > num2 || num1 == num2)
        return true;
    else
        return false;
}

// handle instream operator
istream &operator>>(istream &ins, Rational &rat_num)
{
    int n, d;
    char slash;
    string typed_rational;
    stringstream temp;

    getline(ins, typed_rational);

    temp << typed_rational;

    // if user inputs fraction do this
    if (typed_rational.find("/") != string::npos)
    {
        temp >> n >> slash >> d;
        rat_num.num = n;
        rat_num.den = d;
    }
    // if int, do this
    else
    {
        temp >> n;
        rat_num.num = n;
        rat_num.den = 1;
    }

    // double check fraction format
    check_negatives(rat_num);
    return ins;
}

// format for outputting a rational number in cout
ostream &operator<<(ostream &outs, const Rational &rat_num)
{
    if (rat_num.den == 0)
    {
        outs << "Cannot divide by zero!";
        return outs;
    }
    outs << rat_num.num << "/" << rat_num.den;
    return outs;
}
