using namespace std;
class Rational {
    public:
        Rational();
        Rational(int num1);
        Rational(int num1, int num2);
        friend void check_negatives(Rational& num1);
        friend tuple<int, int, int, int> set_variables(const Rational& num1, const Rational& num2);
        friend Rational operator +(const Rational& num1, const Rational& num2);
        friend Rational operator -(const Rational& num1, const Rational& num2);
        friend Rational operator *(const Rational& num1, const Rational& num2);
        friend Rational operator /(const Rational& num1, const Rational& num2);
        friend Rational operator -(const Rational& num1);
        friend bool operator ==(const Rational& num1, const Rational& num2);
        friend bool operator !=(const Rational& num1, const Rational& num2);
        friend bool operator <(const Rational& num1, const Rational& num2);
        friend bool operator >(const Rational& num1, const Rational& num2);
        friend bool operator <=(const Rational& num1, const Rational& num2);
        friend bool operator >=(const Rational& num1, const Rational& num2);
        friend istream& operator >>(istream& ins, Rational& rat_num);
        friend ostream& operator <<(ostream& outs, const Rational& rat_num);
    private:
        int num;
        int den;
};