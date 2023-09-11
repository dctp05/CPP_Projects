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
istream& operator >>(istream& ins, Rational& rat_num) {
    int n, d;
    char slash;
    string typed_rational;
    stringstream temp;
    getline(ins, typed_rational);
    temp << typed_rational;
    if (typed_rational.find("/") != string::npos) {
        temp >> n >> slash >> d;
        rat_num.num = n;
        rat_num.den = d;
    }
    else {
        temp >> n;
        rat_num.num = n;
        rat_num.den = 1;
    }
    check_negatives(rat_num);
    return ins;
}
ostream& operator <<(ostream& outs, const Rational& rat_num) {
    if (rat_num.den == 0) {
        outs << "Cannot divide by zero!";
        return outs;
    }
    outs << rat_num.num << "/" << rat_num.den;
    return outs;
}