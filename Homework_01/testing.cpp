#include <iostream>
#include <fstream>
#include <string>     //needed for type string
#include <math.h>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    ifstream myfile ("list.txt");
    string mystring;

    // change stof to stod to test doubles

    if (myfile.is_open()) {
        while (myfile.good()){
            myfile >> mystring;
            if ((int)(stof(mystring)*100) == (int)round(stof(mystring)*100)) {
                continue;
            }
            cout << stof(mystring) << endl;
    }}
    return 0;
}