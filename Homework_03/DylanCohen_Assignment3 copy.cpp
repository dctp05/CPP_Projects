#include <iostream>
#include <math.h>     
#include <ctime>
#include <fstream>
using namespace std;
int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    ifstream in_stream;
    ofstream out_stream;
    srand(time(0));
    int N = (rand() % 899) + 101;
    cout << "-- " << N << " random numbers generated --" << endl;
    out_stream.open("DylanCohen_Rand.txt");
    int i, rand_num;
    for (i=1; i<=N; i++) {
        rand_num = (rand() % 1000) + 1;
        out_stream << rand_num << " ";
    }
    out_stream.close();
    in_stream.open("DylanCohen_Rand.txt");
    int rand_number;
    double average = 0;
    while (in_stream >> rand_number) {
        average += rand_number;
    }
    average /= N;
    cout << "Average of " << N << " randomly generated numbers: " << average << endl;
    in_stream.close();
    in_stream.open("DylanCohen_Rand.txt");
    int n;
    double std = 0;
    while (in_stream >> n) {
        std += (n - average) * (n - average);
    }
    std = sqrt(std/N);
    cout << "Standard deviation of " << N 
        << " randomly generated numbers: " << std << "\n\n";
    in_stream.close();
    out_stream.open("DylanCohen_Rand.txt", ios_base::app);
    out_stream << "\nAverage: " << average;
    out_stream << "\nStandard Deviation: " << std;
    out_stream.close();
    return 0;
}