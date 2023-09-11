#include <iostream>

using namespace std;

struct test {
    double age;
    double income;
    bool happy;
};

struct b {
    int c;
    int d;
    int e;
};

struct a {
    int age;
    b bills;
};

void print_data(test& thing);


int main() {
    // test abc;
    // abc.age = 25;
    // abc.income = 25000;
    // abc.happy = true;

    // // cout << abc.age;
    // print_data(abc);
    b test2 = {1, 2, 3};

    a test1 = {12, test2};
    cout << test1.age << endl;
    cout << test1.bills.c << endl;
    cout << test1.bills.d << endl;
    cout << test1.bills.e << endl;

    return 0;
}

void print_data(test& thing) {
    cout << thing.age << thing.income << thing.happy;
}
