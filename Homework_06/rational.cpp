#include <sstream> //used for parsing user input
#include <tuple> //makes operator rules easier to write
#include "rational.h"
using namespace std;
//return a tuple of Rational class private variables
tuple<int, int, int, int> set_variables(const Rational& num1, const Rational& num2) {
    return {num1.num, num1.den, num2.num, num2.den};
}
//Basic constructors
Rational::Rational() {
    num = 0;
    den = 1;
}
Rational::Rational(int num1) {
    num = num1;
    den = 1;
}
Rational::Rational(int num1, int num2) {
    num = num1;
    den = num2;
    //make sure fraction is in correct format
    check_negatives(*this);
}
//alter signs to make num negative if appl.
void check_negatives(Rational& num1) {
    if (num1.den < 0) {
        num1.num = -num1.num;
        num1.den = -num1.den;
    }
    if (num1.num == 0 && num1.den != 1 && num1.den != 0) {
        num1.num = 0;
        num1.den = 1;
    }
    if (num1.num == num1.den && num1.num != 0) {
        num1.num = 1;
        num1.den = 1;
    }
    if (num1.num == -num1.den && num1.num != 0) {
        num1.num = -1;
        num1.den = 1;
    }
}
//get tuple and use to define operator rule
Rational operator +(const Rational& num1, const Rational& num2) {
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a*d + b*c;
    temp.den = b*d;
    check_negatives(temp);
    return temp;
}
Rational operator -(const Rational& num1, const Rational& num2) {
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a*d - b*c;
    temp.den = b*d;
    check_negatives(temp);
    return temp;
}
Rational operator *(const Rational& num1, const Rational& num2) {
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a*c;
    temp.den = b*d;
    check_negatives(temp);
    return temp;
}
Rational operator /(const Rational& num1, const Rational& num2) {
    Rational temp;
    auto [a, b, c, d] = set_variables(num1, num2);
    temp.num = a*d;
    temp.den = c*b;
    check_negatives(temp);
    return temp;
}
Rational operator -(const Rational& num1) {
    Rational temp;
    temp.num = -num1.num;
    temp.den = num1.den;
    return temp;
}
//get tuple for first two, define rules, and use these to construct other operators
bool operator ==(const Rational& num1, const Rational& num2) {
    auto [a, b, c, d] = set_variables(num1, num2);
    if (a*d == c*b) return true;
    else return false;
}
bool operator <(const Rational& num1, const Rational& num2) {
    auto [a, b, c, d] = set_variables(num1, num2);
    if (a*d < c*b) return true;
    else return false;
}
bool operator !=(const Rational& num1, const Rational& num2) {
    if (num1 == num2) return false;
    else return true;
}
bool operator >(const Rational& num1, const Rational& num2) {
    if (num1 < num2 || num1 == num2) return false;
    else return true;
}
bool operator <=(const Rational& num1, const Rational& num2) {
    if (num1 < num2 || num1 == num2) return true;
    else return false;
}
bool operator >=(const Rational& num1, const Rational& num2) {
    if (num1 > num2 || num1 == num2) return true;
    else return false;
}
//handle instream operator
istream& operator >>(istream& ins, Rational& rat_num) {
    int n, d;
    char slash;
    string typed_rational;
    stringstream temp;
    getline(ins, typed_rational);
    temp << typed_rational;
    //if user inputs fraction do this
    if (typed_rational.find("/") != string::npos) {
        temp >> n >> slash >> d;
        rat_num.num = n;
        rat_num.den = d;
    }
    //if int, do this
    else {
        temp >> n;
        rat_num.num = n;
        rat_num.den = 1;
    }
    //double check fraction format
    check_negatives(rat_num);
    return ins;
}
//format for outputting a rational number in cout
ostream& operator <<(ostream& outs, const Rational& rat_num) {
    if (rat_num.den == 0) {
        outs << "Cannot divide by zero!";
        return outs;
    }
    outs << rat_num.num << "/" << rat_num.den;
    return outs;
}