#include <iostream>
#include <math.h>     //needed for rounding
#include <iomanip>    //needed for table formatting
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void calculateCost(int count, float& subTotal, float& taxCost);

int main() {

    float tax = 0.0, subTotal = 0.0;

    calculateCost(15, subTotal, tax);

    cout << "The cost for 15 items is " << subTotal

        << ", and the tax for " << subTotal << " is " << tax << endl;

}

void calculateCost(int count, float& subTotal, float& taxCost)

{

      if ( count < 10)

      {

                  subTotal = count * 0.50;

      }

      else

      {

                  subTotal = count * 0.20;

      }

      taxCost = 0.1 * subTotal;

}