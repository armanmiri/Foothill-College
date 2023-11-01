
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    double * myArray[3];
    int k;

    for (k = 0; k < 3; k++)
       myArray[k] = new double[5];
    
    cout << myArray;
}
