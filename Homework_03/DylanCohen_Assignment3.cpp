/*Author: Dylan Cohen
 *Date: 09/30/2022
 *Assignment 3 -  
 */

#include <iostream>
#include <math.h>     //needed for sqrt function
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    //Set numbers to show with two decimals
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    /* Define input and output streams for reading and writing data into 
     * a txt file
     */
    ifstream in_stream;
    ofstream out_stream;

    
    //Seed for psuedo-random num generation
    srand(time(0));

    //Generate a random number from 101 to 999 and assign to declared varible
    int N = (rand() % 899) + 101;

    //Print to screen how many numbers generated
    cout << "-- " << N << " random numbers generated --" << endl;

    //Open outstream and save N generated random numbers from 1 to 1000 inclusive to .txt
    out_stream.open("DylanCohen_Rand.txt");
    int i, rand_num;
    for (i=1; i<=N; i++) {
        rand_num = (rand() % 1000) + 1;
        out_stream << rand_num << " ";
    }

    //close the output stream
    out_stream.close();

    //open the input stream to read the numbers output before
    in_stream.open("DylanCohen_Rand.txt");

    int rand_number;
    double average = 0;

    //For each int saved in txt file, add that to the average variable
    while (in_stream >> rand_number) {
        average += rand_number;
    }

    //Compute average dividing the sum stored in average by N, the number of random ints
    average /= N;
    //Output the average to the screen
    cout << "Average of " << N << " randomly generated numbers: "
        << average << endl;

    //Close input stream
    in_stream.close();
    
    //open input stream for calculating standard deviation
    in_stream.open("DylanCohen_Rand.txt");
    
    //Go through txt numbers and calculate a standard deviation formula and add it to 'std'
    int n;
    double std = 0;
    while (in_stream >> n) {
        std += (n - average) * (n - average);
    }

    //square root std/N for standard deviation file
    std = sqrt(std/N);
    cout << "Standard deviation of " << N 
        << " randomly generated numbers: " << std << "\n\n";

    in_stream.close();

    //append avg and std info to end of file
    out_stream.open("DylanCohen_Rand.txt", ios_base::app);
    out_stream << "\nAverage: " << average;
    out_stream << "\nStandard Deviation: " << std;

    out_stream.close();
    return 0;
}