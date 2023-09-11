/*Author: Dylan Cohen
 *Date: 09/21/2022
 *Assignment 2 - This program takes input from the user in the form of a principal loan
 * amount, interest rate, and loan repayment length, and returns the monthly payment,
 * and a table with the decreasing principle amount, monthly interest, and accrued interest.
 */

#include <iostream>
#include <math.h>     //needed for rounding
#include <iomanip>    //needed for table formatting
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

int main() {
    //Set numbers to show with two decimals
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    ifstream in_stream;
    ofstream out_stream;

    
    // in_stream.open("DylanCohen_Rand.txt");
    
    // srand(time(0));

    unsigned long seed = mix(clock(), time(NULL), getpid());

    srand(seed);


    int N, x;

    for (x=1; x<100; x++){

        N = (rand() % 899) + 101;

        cout << "-- " << N << " random numbers generated --" << endl;

        out_stream.open("DylanCohen_Rand.txt");
        int i, rand_num;
        for (i=1; i<=N; i++) {
            rand_num = (rand() % 1000) + 1;
            out_stream << rand_num << " ";
        }

        out_stream.close();

        in_stream.open("DylanCohen_Rand.txt");

        int a, length = 0;
        double average = 0;
        while (in_stream >> a) {
            average += a;
            length++;
        }
        average /= length;
        cout << "Average of " << N << " randomly generated numbers: "
            << average << endl;

        in_stream.close();
        
        in_stream.open("DylanCohen_Rand.txt");
        int n;
        double std = 0;
        while (in_stream >> n) {
            std += (n - average) * (n - average);
        }
        std = sqrt(std/length);
        cout << "Standard deviation of " << N 
            << " randomly generated numbers: " << std << "\n\n";

        in_stream.close();

        out_stream.open("DylanCohen_Rand.txt", ios_base::app);
        out_stream << "\nAverage: " << average;
        out_stream << "\nStandard Deviation: " << std;

        out_stream.close();
    }
    return 0;
}